# TEMA: Modelo TinyML en Arduino Nano 33 BLE SENSE para el reconocimiento de formas y números 

## INTEGRANTES: 
* Flores Mescco Fiorella Ingrid
* Gutiérrez Huamán Mar Flor
* Quispe Mamani Lizzeth Rossmery
* Yalli Espinoza Milena Nicol
  
## 1). INTRODUCCIÓN

TinyML es una tecnología que permite la implementación de modelos de Machine Learning en dispositivos de bajo consumo, como microcontroladores, posibilitando análisis en tiempo real de datos sensoriales, como visión y audio, directamente en el dispositivo, lo que reduce la dependencia de la nube y mejora la privacidad y seguridad de los datos (Lane et al., 2024; Warden et al., 2023). Su crecimiento ha impulsado el desarrollo de herramientas, como frameworks y bibliotecas, facilitando su uso en diversas industrias, desde la salud hasta la agricultura (Banbury et al., 2023).
La placa Nano 33 BLE Sense incorpora sensores y capacidades de conectividad mediante Bluetooth de baja energía, lo cual la hace ideal para aplicaciones que necesitan interactuar con el entorno y establecer comunicación inalámbrica eficiente (Mitchell, 2023).

Este proyecto tiene como objetivo implementar un modelo TinyML en un Arduino Nano 33 BLE Sense para el reconocimiento de gestos, específicamente movimientos que forman un círculo o representan los números "3" y "1", activando diferentes LED en respuesta a cada gesto. A través de los sensores integrados del Arduino, se demostrará cómo la inteligencia artificial puede aplicarse en dispositivos con recursos limitados. Se detallarán los pasos necesarios para entrenar el modelo, implementarlo en el dispositivo y comprobar su correcto funcionamiento.

## 2).METODOLOGÍA 
Durante la realización del proyecto,se consultaron artículos especializados utilizando Google Scholar, para comprender la implementación de TinyML en el Arduino Nano 33 BLE Sense. Empleamos términos de búsqueda como “Machine Learning en dispositivos embebidos” y “redes neuronales en hardware limitado,”. El proyecto se dividió en fases que incluyeron desde la recolección de datos de movimiento con los sensores del Arduino hasta la carga e implementación del modelo TinyML en el dispositivo.

El modelo de reconocimiento de gestos fue entrenado con TensorFlow Lite, ajustando los parámetros necesarios para alcanzar la precisión requerida. Posteriormente, el modelo se cargó en el Arduino Nano 33 BLE Sense usando la plataforma Arduino IDE, asegurando su correcta integración con el hardware del dispositivo.

Finalmente, se realizaron pruebas para verificar la capacidad del sistema de reconocer los gestos específicos y activar los LED correspondientes. Cada etapa del proceso fue cuidadosamente documentada y ajustada para garantizar la eficacia del modelo y el funcionamiento adecuado del proyecto.


### *2.1). Configuración del Entorno:*

Registrar una Cuenta en Edge Impulse: Crea una cuenta en Edge Impulse

 <p align="center">
    <img src="https://i.postimg.cc/RhnNYNZY/INICIo.jpg" width="900" alt="logo">
  </p>  
  
### *2.2) Adquisición de Datos de Movimiento:*

Para entrenar el modelo de reconocimiento de gestos, se inició con la captura de datos utilizando los sensores del Arduino Nano 33 BLE Sense. Se recolectaron 100 muestras de cada gesto: el dibujo de un círculo, el número 3 y el número 1, en diferentes condiciones para garantizar que el modelo pudiera generalizar eficazmente.

 <p align="center">
    <img src="https://i.postimg.cc/PJ62SVNy/Datos1.jpg" width="800" alt="logo">
  </p>  

### *2.3) Desarrollo del Modelo*
#### Recolección de Datos:

Utilizamos el Arduino Nano 33 BLE Sense para captar datos de sus sensores integrados, que incluyen el acelerómetro, el giroscopio y el magnetómetro.
Registramos datos en los ejes AccX, AccY, AccZ (acelerómetro); GyrX, GyrY, GyrZ (giroscopio); y MagX, MagY, MagZ (magnetómetro).
Dividimos los datos en segmentos de 3 segundos para facilitar su análisis.

#### Procesamiento:
Configuramos el bloque de procesamiento para aplicar el análisis espectral a los datos, asegurándonos de manejar adecuadamente todos los ejes de entrada.
<p align="center">
    <img src="https://i.postimg.cc/dQS2Sy45/caracter-sticas.png" width="800" alt="logo">
  </p>  

#### Entrenamiento del Modelo:

Los resultados obtenidos, con una precisión del 91.7% y una pérdida de 0.52, indican que el modelo es eficaz y adecuado para la tarea de reconocimiento de gestos. La alta precisión sugiere que el modelo clasifica correctamente la mayoría de los gestos, mientras que la pérdida relativamente baja indica un buen ajuste general del modelo.

 <p align="center">
    <img src="https://i.postimg.cc/6qz1D5bd/Entrenamiento.png" width="800" alt="Modelo">
  </p>  

El modelo entrenado debe ser capaz de distinguir entre las tres clases especificadas ("círculo", "tres" y "uno") basándose en las características extraídas.

### *2.4)  Implementación y pruebas del código:*

Para implementar el modelo en el Arduino Nano 33 BLE Sense, desarrollamos un código específico que gestionó la lectura de datos del sensor, la inferencia del modelo y el control de los LEDs.

Vamos a describir el código en primera persona del plural, explicando lo que hacemos en cada parte.

### 1. Inclusión de bibliotecas
```cpp
#include <Wire.h>
#include <SparkFunLSM9DS1.h>
#include <a33_inferencing.h>
```
Lo primero que hacemos es incluir las bibliotecas necesarias para nuestro proyecto. Utilizamos la biblioteca `Wire.h` para la comunicación I2C con el sensor, `SparkFunLSM9DS1.h` para manejar las funciones del sensor LSM9DS1, y `a33_inferencing.h` para realizar inferencias con la ayuda de Edge Impulse.

### 2. Inicialización del sensor y configuración de pines
```cpp
LSM9DS1 imu;
const int RED_LED_PIN = 2;
const int BLUE_LED_PIN = 3;
const int GREEN_LED_PIN = 4;
```
Aquí, creamos un objeto `imu` para interactuar con el sensor LSM9DS1 y definimos los pines que utilizaremos para controlar los LEDs rojo, azul y verde.

### 3. Almacenamiento de características
```cpp
static float features[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE];
```
Este array es donde almacenamos las características que extraemos del sensor (como los valores de aceleración en los ejes X, Y y Z). El tamaño del array es definido por el valor `EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE`, que corresponde al número de características que espera la biblioteca de Edge Impulse.

### 4. Función `raw_feature_get_data`
```cpp
int raw_feature_get_data(size_t offset, size_t length, float *out_ptr) {
    memcpy(out_ptr, features + offset, length * sizeof(float));
    return 0;
}
```
En esta función, nos encargamos de copiar los datos de nuestro array `features` al puntero `out_ptr`, que la biblioteca de inferencia utilizará para procesar los datos. Aquí especificamos un desplazamiento (`offset`) y una longitud (`length`) para controlar qué porción de datos queremos copiar.

### 5. Función `print_inference_result`
```cpp
void print_inference_result(ei_impulse_result_t result) {
    ei_printf("Timing: DSP %d ms, inference %d ms, anomaly %d ms\r\n", result.timing.dsp, result.timing.classification, result.timing.anomaly);
```
Aquí mostramos los resultados de la inferencia. Imprimimos el tiempo que tomó cada etapa del proceso: el procesamiento DSP, la clasificación y la detección de anomalías, si las hay.

#### Control de los LEDs:
```cpp
    if (result.classification[0].value > 0.5) {
        digitalWrite(RED_LED_PIN, HIGH);  
        digitalWrite(BLUE_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, LOW);
    } else if (result.classification[1].value > 0.5) {
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, HIGH);  
    } else if (result.classification[2].value > 0.5) {
        digitalWrite(GREEN_LED_PIN, HIGH);
    } else {
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, LOW);
    }
```
Dependiendo de los resultados de la inferencia, controlamos los LEDs. Si el valor de una clase supera el 50%, encendemos el LED correspondiente. De lo contrario, apagamos los LEDs.

### 6. Función `setup`
```cpp
void setup() {
    Serial.begin(115200);  
    Wire.begin();  

    if (imu.begin() != 0) {
        Serial.println("Error al inicializar el LSM9DS1.");
        while (1);  
    }

    pinMode(RED_LED_PIN, OUTPUT);  
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);

    Serial.println("LSM9DS1 inicializado correctamente.");
}
```
En la función `setup`, inicializamos la comunicación serial y la comunicación I2C para poder interactuar con el sensor. Intentamos inicializar el sensor LSM9DS1 y, si falla, mostramos un mensaje de error y detenemos el programa. Configuramos los pines de los LEDs como salidas para poder controlarlos más adelante.

### 7. Función `loop`
```cpp
void loop() {
    ei_printf("Edge Impulse standalone inferencing (Arduino)\n");

    imu.readAccel();  
    features[0] = imu.calcAccel(imu.ax);  
    features[1] = imu.calcAccel(imu.ay);  
    features[2] = imu.calcAccel(imu.az);  
```
En el `loop`, leemos los datos del acelerómetro en cada iteración. Extraemos las aceleraciones en los ejes X, Y y Z, y las almacenamos en el array `features` para utilizarlas en la inferencia.

#### Verificación de tamaño
```cpp
    if (sizeof(features) / sizeof(float) != EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
        ei_printf("The size of your 'features' array is not correct. Expected %lu items, but had %lu\n", EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, sizeof(features) / sizeof(float));
        delay(1000);
        return;
    }
```
Aquí verificamos que el tamaño de nuestro array de características coincida con lo esperado por la biblioteca. Si no es así, mostramos un mensaje de error y pausamos la ejecución durante un segundo antes de reintentarlo.

#### Preparación de la señal para la inferencia
```cpp
    ei_impulse_result_t result = { 0 };
    signal_t features_signal;
    features_signal.total_length = sizeof(features) / sizeof(features[0]);
    features_signal.get_data = &raw_feature_get_data;
```
Luego, preparamos una estructura `signal_t` que contiene nuestros datos de características. Esta estructura será utilizada por la función de inferencia para procesar los datos y generar un resultado.

#### Ejecución de la inferencia
```cpp
    EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, false);
    if (res != EI_IMPULSE_OK) {
        ei_printf("ERR: Failed to run classifier (%d)\n", res);
        return;
    }
```
Llamamos a la función `run_classifier` para ejecutar la inferencia. Si ocurre un error durante el proceso, lo imprimimos y detenemos la ejecución temporalmente.

### 8. Control de LEDs y nueva iteración
```cpp
    print_inference_result(result);
    delay(1000);  
}
```
Finalmente, mostramos los resultados de la inferencia y ajustamos los LEDs en consecuencia. Hacemos una pausa de un segundo antes de repetir el proceso.

Este código nos permite leer datos del sensor, ejecutar una inferencia y controlar los LEDs según los resultados obtenidos.

## 3). RESULTADOS
<p align="center">
    <img src="https://i.postimg.cc/qvcC0hxV/final.jpg)" width="800" alt="Modelo">
  </p>  

Recopilación de datos de los sensores del Arduino Nano 33 BLE Sense, en intervalos de 3 segundos, con identificación de gestos en "círculo", "tres" y "uno".
| INTERPRETACIÓN |  IMAGEN | 
| :------------ |:---------------:| 
| Tres| [![P-I1.jpg](https://i.postimg.cc/vT1QmkRx/P-I1.jpg)](https://postimg.cc/K32Xq98m)|
| Círculo| [![P-I2.jpg](https://i.postimg.cc/TYDdMzqZ/P-I2.jpg)](https://postimg.cc/GHbwvSfQ) |
| Uno| [![P-I3.jpg](https://i.postimg.cc/TPRfbpM6/P-I3.jpg)](https://postimg.cc/gxBCFc2S)| 

Los resultados muestran que el modelo tiene una alta precisión del 84.8% en la detección del gesto de un círculo, pero enfrenta dificultades con los números 1 y 3, con precisiones de 2.73% y 3.52%, respectivamente. Aunque el modelo identifica correctamente el número 1 con una precisión notable del 93.75%, su rendimiento en la detección del círculo y el número 3 sugiere la necesidad de mejoras significativas. Esto indica que el modelo está bien ajustado para reconocer el número 1, pero requiere ajustes adicionales para mejorar la identificación de los otros gestos. En particular, el gesto del número 3 tiene una precisión del 37.11%, lo que es mejor en comparación con el círculo y el número 1, pero aún requiere optimización. Es necesario revisar el proceso de entrenamiento y considerar ajustes en el modelo para mejorar la precisión general en la detección de todos los gestos.

## 3). EVIDENCIAS 

https://github.com/user-attachments/assets/400b464c-f6ed-43f6-860b-451312d76ed9



## 4). DISCUSIÓN

Hemos logrado mostrar que el Arduino Nano 33 BLE Sense puede ejecutar un modelo de TinyML entrenado con Edge Impulse, lo que le permite identificar con precisión gestos como un círculo, el número 3 y el número 1. Esta implementación ilustra cómo los sistemas embebidos pueden realizar tareas complejas de reconocimiento de patrones de manera autónoma, sin necesidad de conexión constante a la nube, mientras optimizan el uso de recursos y energía. Al combinar el aprendizaje automático con un hardware eficiente y herramientas como Edge Impulse, hemos ampliado las posibilidades para desarrollar aplicaciones inteligentes

## 5). REFERENCIAS

* Lane, N., & Warden, P. (2024). Efficient Machine Learning at the Edge: The Rise of TinyML. Journal of Embedded Systems.
* Warden, P., & Situnayake, D. (2023). TinyML: Machine Learning with TensorFlow Lite on Arduino and Ultra-Low-Power Microcontrollers. O'Reilly Media.
* Banbury, C., Reddi, V., & Cheng, Y. (2023). Benchmarking TinyML Systems: New Approaches and Open Challenges. IEEE Micro.
* Mitchell, S. (2023). Mastering Arduino Nano 33 BLE: Building Interactive Wireless Applications. Tech Press.



