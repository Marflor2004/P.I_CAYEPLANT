<p align="left">
  <img src="https://semanadelcannabis.cayetano.edu.pe/assets/img/logo-upch.png" width="250">
 
</p>
<div align="center">
  
# ENTREGABLE 05: Familiarización con IoT en Arduino ESP32
</div>

         |  Objetivo: Obtener una comprensión práctica y teórica del Internet de las Cosas (IoT), enfocándonos en la configuración y programación de dispositivos IoT utilizando el ESP32. Esta experiencia permitió fortalecer nuestros conocimientos sobre conectividad y manejo de datos en entornos IoT.                                                              |

###### Docentes a cargo:
 - Mg. U. Lewis de la Cruz Rodríguez
 - > umbert.de.la.cruz@upch.pe
 - Ing. Renzo Chan Rios
 - > renzo.chan@upch.pe

#### INTEGRANTES: 
* Flores Mescco Fiorella Ingrid
* Gutierrez Huaman Mar Flor
* Quispe Mamani Lizzeth Rossmery
* Yalli Espinoza Milena Nicol

## 1). INTRODUCCIÓN:
El Internet de las cosas (IoT),  se ha consolidado como una de las tecnologías más relevantes de los últimos años. Su capacidad para conectar millones de dispositivos a nivel mundial plantea desafíos considerables en aspectos como el costo, la conectividad y el consumo energético (Zhang et al., 2023). Este avance tecnológico tiene como objetivo monitorear diversas facetas de la vida diaria (Sharma et al., 2023). Asimismo, se extiende a campos como la visión artificial, la conservación ambiental y el análisis meteorológico, entre otros.

El informe presente se focaliza en la configuración y programación de dispositivos IoT, utilizando plataformas como Arduino MKR y ESP32. Se explora la conexión de sensores que permiten la adquisición de datos de variables ambientales como temperatura, humedad, luminosidad y movimiento. Posteriormente, estos datos se envían a plataformas IoT mediante protocolos de comunicación, tales como Wi-Fi o MQTT, optimizando el proceso de monitoreo y respuesta en tiempo real.

El ecosistema IoT se compone de dispositivos que integran sistemas embebidos, como unidades centrales de procesamiento (CPU), sensores y módulos de conectividad (Li et al., 2020). Estos dispositivos recopilan, transmiten y responden a la información obtenida de su entorno, facilitando el intercambio de datos entre sensores y otros dispositivos mediante pasarelas IoT o dispositivos de frontera. La información recolectada puede ser transferida a la nube para un análisis más detallado o procesada localmente para una respuesta inmediata.

## 2). METODOLOGÍA

Hoy en día, existe una gran cantidad de microcontroladores y tarjetas de desarrollo orientadas al Internet de las Cosas (IoT). No obstante, en esta actividad nos enfocamos en el ESP32 Dev Kit 1. Este microcontrolador se destaca por su bajo costo y consumo energético, y cuenta con tecnología Wi-Fi y Bluetooth que permite el control de distintos sensores, lo que lo hace una opción económica y eficaz para proyectos de IoT.

## 2.1). ACTIVIDAD: Lectura de un Potenciómetro con ESP32 
### OBJETIVO: 
El objetivo fundamental del ejercicio es mejorar la precisión en la lectura de un potenciómetro con el ESP32 mediante el uso de un promediado de datos y la conversión de los valores del ADC a voltaje. Esto optimiza la estabilidad de las mediciones y permite interpretar correctamente los niveles de señal analógica. Adicionalmente, se exploran las funcionalidades de la biblioteca WiFi.h para conectar el dispositivo a redes Wi-Fi, lo que posibilita la integración en proyectos de monitoreo remoto, automatización del hogar e interacción con servidores web.

[![Whats-App-Image-2024-09-19-at-2-44-04-PM.jpg](https://i.postimg.cc/HsRR3rkT/Whats-App-Image-2024-09-19-at-2-44-04-PM.jpg)](https://postimg.cc/Lnkx86PW)
Figura 1: visualización del código 


[![Whats-App-Image-2024-09-25-at-9-53-38-PM.jpg](https://i.postimg.cc/MHX3mwkc/Whats-App-Image-2024-09-25-at-9-53-38-PM.jpg)](https://postimg.cc/Mf2Yzhpx)
Figura 2: montaje delm potenciometro 

## 2.2). ACTIVIDAD: Scanner WIFI con ESP32
### OBJETIVO: 
El objetivo de este ejercicio es configurar el ESP32 como un escáner de redes Wi-Fi para detectar y analizar las redes cercanas. Con esto, puedo identificar la cantidad de redes disponibles, sus nombres (SSID), la intensidad de la señal (RSSI) y el tipo de cifrado que utilizan. Los resultados se imprimirán en el monitor serie cada 5 segundos, lo que me permitirá evaluar el entorno de conectividad y analizar la calidad de las redes para proyectos de monitoreo o diagnóstico de señal.
[![Whats-App-Image-2024-09-19-at-2-50-26-PM.jpg](https://i.postimg.cc/Y2JTz49M/Whats-App-Image-2024-09-19-at-2-50-26-PM.jpg)](https://postimg.cc/hh1CStT5)
Figura: visualización de redes 

## código: 
```cpp
#include "WiFi.h"  // Incluye la biblioteca WiFi para manejar la conectividad Wi-Fi

const char* ssid = "Galaxy12345";  // Reemplaza con el nombre de tu hotspot
const char* password = "12345678";  // Reemplaza con la contraseña de tu hotspot

void setup() {
    Serial.begin(115200);  // Inicializa la comunicación serial a 115200 baudios

    // Configura el ESP32 en modo estación (cliente) y desconecta de una AP si estaba previamente conectado
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);  // Espera 100 ms para asegurar que la desconexión esté completa

    Serial.println("Conectando a la red...");
    WiFi.begin(ssid, password);  // Inicia la conexión al hotspot

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);  // Espera 1 segundo
        Serial.print(".");  // Muestra un punto para indicar que está intentando conectarse
    }

    Serial.println("");
    Serial.println("Conexión exitosa!");
    Serial.print("Dirección IP asignada: ");
    Serial.println(WiFi.localIP());  // Imprime la dirección IP asignada
}

void loop() {
    // Puedes añadir lógica aquí si necesitas hacer algo en el loop
} actividad
```
## *Materiales*
| Potenciómetro |  ESP32 | 
| :------------ |:---------------:| 
| [![Potenci-metro.jpg](https://i.postimg.cc/jjB43RDj/Potenci-metro.jpg)](https://postimg.cc/xkymcDyr)| [![sp32.jpg](https://i.postimg.cc/fRL7wVXL/sp32.jpg)](https://postimg.cc/WhBq8b5L)|


## ACTIVIDAD: Configuración del ESP32 para el envío de datos a un servidor 
#### *Envío a servidor en digital ocean*

    |  Se configuró el ESP32 para enviar datos a un servidor alojado en Digital Ocean. Este proceso incluyó varios pasos esenciales para asegurar la correcta comunicación entre el dispositivo y el servidor. Primero, se creó un servidor en Digital Ocean y se configuraron las credenciales necesarias para la conexión. Luego, se utilizó un código específico en Arduino IDE para programar el ESP32, que abarca la conexión a la red Wi-Fi y la definición de los parámetros del servidor. A continuación, se presenta el código utilizado para el ESP32                                                     |

  <p align="center">
  <img src="https://i.postimg.cc/852DCfjV/Evidencia-1.jpg)](https://postimg.cc/xJ3BxCvs)" width="1050">
 
</p>

#### *Código*

  ```cpp
era esto : #include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Redmi Note 11";  // Nombre de usuario (SSID de tu red)
const char* password = "hola1234";   // Contraseña de la red

const char* serverName = "https://sea-turtle-app-8b8vl.ondigitalocean.app/receive-data";  // URL donde se enviarán los datos

void setup() {
  Serial.begin(115200);

  // Conectar al WiFi
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Conectado a WiFi!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {  // Verifica que el ESP32 esté conectado
    HTTPClient http;

    // Inicia la conexión con el servidor
    http.begin(serverName);

    // Especifica el tipo de contenido (opcional)
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    // Dato a enviar, por ejemplo: "G2"
    String httpRequestData = "G2";  // Aquí puedes cambiar el valor que deseas enviar

    // Realiza la solicitud POST y captura la respuesta
    int httpResponseCode = http.POST(httpRequestData);

    // Verifica la respuesta
    if (httpResponseCode > 0) {
      String response = http.getString();  // Obtiene la respuesta del servidor
      Serial.println("Respuesta del servidor: " + response);
    } else {
      Serial.println("Error en la solicitud POST: " + String(httpResponseCode));
    }

    // Finaliza la conexión
    http.end();
  } else {
    Serial.println("Error: No se pudo conectar a WiFi");
  }

  delay(10000);  // Espera 10 segundos antes de enviar el próximo dato
}
```

#### *Envío MQTT Mostrando la Información del Monitor Serial*

    |  Se implementó un sistema de comunicación utilizando el protocolo MQTT, que es especialmente eficiente para aplicaciones IoT debido a su bajo consumo de ancho de banda y su arquitectura basada en publicador/suscriptor. Utilizando la biblioteca AsyncMqttClient, se configuró el ESP32 para conectarse a un broker MQTT, lo que permitió enviar datos en formato JSON.                                                             |
 <p align="center">
  <img src="https://i.postimg.cc/k5T7q7VF/Evidencia1.jpg)](https://postimg.cc/DW49ckP8)" width="1050">
 
</p>

 #### *Código*

```cpp
#include <WiFi.h>
#include <AsyncMqttClient.h>

#define WIFI_SSID "Mar240118"         // Nombre de tu red Wi-Fi
#define WIFI_PASSWORD "73212209@"        // Contraseña de tu red Wi-Fi

#define MQTT_HOST IPAddress(161, 132, 37, 210)  // Dirección del broker MQTT
#define MQTT_PORT 1883
#define MQTT_PUB_DATA "upch/equipo2"            // Tópico para el equipo

AsyncMqttClient mqttClient;
int QoS = 0;
TimerHandle_t mqttReconnectTimer;
TimerHandle_t wifiReconnectTimer;

/*****************
                    Variables
****************/
float tempVal = 30.5;
bool mqttConnected = false;  // Nueva variable para verificar si la conexión a MQTT está establecida

/*****************
                    Funciones
****************/
void connectToWifi() {
  Serial.println("Conectando a Wi-Fi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void connectToMqtt() {
  if (WiFi.isConnected()) {  // Verifica si Wi-Fi está conectado antes de intentar conectar a MQTT
    Serial.println("Conectando a MQTT...");
    mqttClient.connect();
  }
}

void WiFiEvent(WiFiEvent_t event) {
  Serial.printf("[Evento-WiFi] evento: %d\n", event);
  switch (event) {
    case IP_EVENT_STA_GOT_IP:  // Cuando el ESP32 obtiene una IP
      Serial.println("Wi-Fi conectado");
      Serial.println("Dirección IP: ");
      Serial.println(WiFi.localIP());
      connectToMqtt();  // Conecta a MQTT una vez que hay conexión Wi-Fi
      break;
    case WIFI_EVENT_STA_DISCONNECTED:  // Cuando el ESP32 se desconecta de Wi-Fi
      Serial.println("Wi-Fi desconectado");
      xTimerStop(mqttReconnectTimer, 0);  // Detiene el temporizador de reconexión a MQTT
      xTimerStart(wifiReconnectTimer, 0); // Inicia el temporizador de reconexión a Wi-Fi
      break;
  }
}

void onMqttConnect(bool sessionPresent) {
  Serial.println("Conectado a MQTT.");
  Serial.print("Sesión presente: ");
  Serial.println(sessionPresent);
  mqttConnected = true;  // Marca que la conexión a MQTT está activa
}

void onMqttDisconnect(AsyncMqttClientDisconnectReason reason) {
  Serial.println("Desconectado de MQTT.");
  mqttConnected = false;  // Marca que la conexión a MQTT está inactiva
  if (WiFi.isConnected()) {
    xTimerStart(mqttReconnectTimer, 0);  // Intenta reconectar a MQTT si Wi-Fi está conectado
  }
}

void onMqttPublish(uint16_t packetId) {
  Serial.println("Publicación confirmada.");
  Serial.print("  packetId: ");
  Serial.println(packetId);
}

void setup() {
  Serial.begin(115200);
  while (!Serial) { /* Espera hasta conectarse */ }

  mqttReconnectTimer = xTimerCreate("mqttTimer", pdMS_TO_TICKS(2000), pdFALSE, (void*)0, reinterpret_cast<TimerCallbackFunction_t>(connectToMqtt));
  wifiReconnectTimer = xTimerCreate("wifiTimer", pdMS_TO_TICKS(2000), pdFALSE, (void*)0, reinterpret_cast<TimerCallbackFunction_t>(connectToWifi));

  WiFi.onEvent(WiFiEvent);  // Asigna el evento de conexión Wi-Fi

  mqttClient.onConnect(onMqttConnect);  // Callback para conexión MQTT
  mqttClient.onDisconnect(onMqttDisconnect);  // Callback para desconexión MQTT
  mqttClient.onPublish(onMqttPublish);  // Callback para confirmación de publicación
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);  // Configura el broker MQTT
  mqttClient.setCredentials("devRCR", "D3s4rr0ll0"); // ESTO NO MODIFICAR

  connectToWifi();  // Inicia la conexión a Wi-Fi
}

void loop() {
  // Solo intenta publicar si la conexión a MQTT está activa
  if (mqttConnected) {  // Agrega verificación de conexión MQTT antes de publicar
    String jsonString = "{";
    jsonString += "\"temp\": ";
    jsonString += tempVal;
    jsonString += "}";

    uint16_t packetIdPub1 = mqttClient.publish(MQTT_PUB_DATA, QoS, true, jsonString.c_str()); // Publica el JSON
    Serial.println("Publicando datos: " + jsonString);
    Serial.printf("Publicando en el tópico %s con QoS %d, packetId: ", MQTT_PUB_DATA, QoS);
    Serial.println(packetIdPub1);
    Serial.print("\r\n");
  } else {
    Serial.println("Esperando conexión MQTT...");  // Mensaje de depuración si no hay conexión MQTT
  }

  delay(5000); // Espera de 5 segundos antes de intentar publicar nuevamente
}

```


## *CONCLUSIÓN*
La actividad nos brindó la oportunidad de experimentar de manera práctica con el ESP32, facilitando un aprendizaje significativo sobre la implementación del Internet de las Cosas. A través de este ejercicio, logramos no solo enviar datos, sino también entender mejor el potencial de los dispositivos conectados y su aplicación en diversas áreas.


## REFERENCIAS 
* Li, X., et al. (2020). Comprensión de los dispositivos y ecosistemas de IoT. Journal of Emerging Technologies , 32(5), 412-423.
* Sharma, P., et al. (2023). El papel de la IoT en los sistemas educativos modernos. Revista Internacional de Tecnología Educativa , 45(2), 58-67.
