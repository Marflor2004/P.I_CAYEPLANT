#include <Wire.h>
#include <SparkFunLSM9DS1.h>
#include <a33_inferencing.h>

// Inicializa el sensor LSM9DS1
LSM9DS1 imu;

// Definir pines para LEDs
const int RED_LED_PIN = 2;
const int BLUE_LED_PIN = 3;
const int GREEN_LED_PIN = 4;

static float features[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE];

/**
 * @brief      Copy raw feature data in out_ptr
 *             Function called by inference library
 *
 * @param[in]  offset   The offset
 * @param[in]  length   The length
 * @param      out_ptr  The out pointer
 *
 * @return     0
 */
int raw_feature_get_data(size_t offset, size_t length, float *out_ptr) {
    memcpy(out_ptr, features + offset, length * sizeof(float));
    return 0;
}

/**
 * @brief      Print inference result and control LEDs
 *
 * @param[in]  result   The inference result
 */
void print_inference_result(ei_impulse_result_t result) {
    // Print how long it took to perform inference
    ei_printf("Timing: DSP %d ms, inference %d ms, anomaly %d ms\r\n",
            result.timing.dsp,
            result.timing.classification,
            result.timing.anomaly);

    // Print the prediction results (classification)
    ei_printf("Predictions:\r\n");
    for (uint16_t i = 0; i < EI_CLASSIFIER_LABEL_COUNT; i++) {
        ei_printf("  %s: ", ei_classifier_inferencing_categories[i]);
        ei_printf("%.5f\r\n", result.classification[i].value);
    }

    // Control LEDs based on classification
    if (result.classification[0].value > 0.5) { // Ejemplo para clase "círculo"
        digitalWrite(RED_LED_PIN, HIGH);
        digitalWrite(BLUE_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, LOW);
    } else if (result.classification[1].value > 0.5) { // Ejemplo para clase "3"
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, HIGH);
        digitalWrite(GREEN_LED_PIN, LOW);
    } else if (result.classification[2].value > 0.5) { // Ejemplo para clase "1"
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, HIGH);
    } else {
        // Apagar todos los LEDs si no se detecta ninguna de las clases
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, LOW);
    }
}

/**
 * @brief      Arduino setup function
 */
void setup() {
    Serial.begin(115200);
    Wire.begin();

    if (imu.begin() != 0) {
        Serial.println("Error al inicializar el LSM9DS1.");
        while (1);
    }

    // Configura los pines de los LEDs
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);

    Serial.println("LSM9DS1 inicializado correctamente.");
}

/**
 * @brief      Arduino main function
 */
void loop() {
    ei_printf("Edge Impulse standalone inferencing (Arduino)\n");

    // Lee los valores del acelerómetro
    imu.readAccel(); // Lee los datos del acelerómetro

    features[0] = imu.calcAccel(imu.ax); // Aceleración en X
    features[1] = imu.calcAccel(imu.ay); // Aceleración en Y
    features[2] = imu.calcAccel(imu.az); // Aceleración en Z

    if (sizeof(features) / sizeof(float) != EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
        ei_printf("The size of your 'features' array is not correct. Expected %lu items, but had %lu\n",
            EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, sizeof(features) / sizeof(float));
        delay(1000);
        return;
    }

    ei_impulse_result_t result = { 0 };

    // Prepare signal for inference
    signal_t features_signal;
    features_signal.total_length = sizeof(features) / sizeof(features[0]);
    features_signal.get_data = &raw_feature_get_data;

    // Invoke the impulse
    EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, false /* debug */);
    if (res != EI_IMPULSE_OK) {
        ei_printf("ERR: Failed to run classifier (%d)\n", res);
        return;
    }

    // Print inference result and control LEDs
    print_inference_result(result);

    delay(1000);
}

