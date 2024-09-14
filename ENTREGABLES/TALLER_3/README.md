# TEMA: Modelo TinyML en Arduino Nano 33 BLE SENSE para el reconocimiento de formas y números 

## INTEGRANTES: 
* Milena Yally
* Fiorella Flores
* Mar Gutierrez
* Lizeth Mamani
  
## 1). INTRODUCCIÓN

TinyML es una tecnología que permite la implementación de modelos de Machine Learning en dispositivos de bajo consumo, como microcontroladores, posibilitando análisis en tiempo real de datos sensoriales, como visión y audio, directamente en el dispositivo, lo que reduce la dependencia de la nube y mejora la privacidad y seguridad de los datos (Lane et al., 2024; Warden et al., 2023). Su crecimiento ha impulsado el desarrollo de herramientas, como frameworks y bibliotecas, facilitando su uso en diversas industrias, desde la salud hasta la agricultura (Banbury et al., 2023).
La placa Nano 33 BLE Sense incorpora sensores y capacidades de conectividad mediante Bluetooth de baja energía, lo cual la hace ideal para aplicaciones que necesitan interactuar con el entorno y establecer comunicación inalámbrica eficiente (Mitchell, 2023).

Este proyecto tiene como objetivo implementar un modelo TinyML en un Arduino Nano 33 BLE Sense para el reconocimiento de gestos, específicamente movimientos que forman un círculo o representan los números "3" y "1", activando diferentes LED en respuesta a cada gesto. A través de los sensores integrados del Arduino, se demostrará cómo la inteligencia artificial puede aplicarse en dispositivos con recursos limitados. Se detallarán los pasos necesarios para entrenar el modelo, implementarlo en el dispositivo y comprobar su correcto funcionamiento.

## 2).METODOLOGÍA 
Durante la realización del proyecto,se consultaron artículos especializados utilizando Google Scholar, para comprender la implementación de TinyML en el Arduino Nano 33 BLE Sense. Empleamos términos de búsqueda como “Machine Learning en dispositivos embebidos” y “redes neuronales en hardware limitado,”. El proyecto se dividió en fases que incluyeron desde la recolección de datos de movimiento con los sensores del Arduino hasta la carga e implementación del modelo TinyML en el dispositivo.

El modelo de reconocimiento de gestos fue entrenado con TensorFlow Lite, ajustando los parámetros necesarios para alcanzar la precisión requerida. Posteriormente, el modelo se cargó en el Arduino Nano 33 BLE Sense usando la plataforma Arduino IDE, asegurando su correcta integración con el hardware del dispositivo.

Finalmente, se realizaron pruebas para verificar la capacidad del sistema de reconocer los gestos específicos y activar los LED correspondientes. Cada etapa del proceso fue cuidadosamente documentada y ajustada para garantizar la eficacia del modelo y el funcionamiento adecuado del proyecto.


## 2.1). Configuración del Entorno:

Registrar una Cuenta en Edge Impulse: Crea una cuenta en Edge Impulse

## 2.2) Adquisición de Datos de Movimiento: 

Para entrenar el modelo de reconocimiento de gestos, se inició con la captura de datos utilizando los sensores del Arduino Nano 33 BLE Sense. Se recolectaron 100 muestras de cada gesto: el dibujo de un círculo, el número 3 y el número 1, en diferentes condiciones para garantizar que el modelo pudiera generalizar eficazmente.

[![Whats-App-Image-2024-09-10-at-6-58-09-PM.jpg](https://i.postimg.cc/qMc1W0z8/Whats-App-Image-2024-09-10-at-6-58-09-PM.jpg)](https://postimg.cc/TpwjWzjw)



## 2). REFERENCIAS

* Lane, N., & Warden, P. (2024). Efficient Machine Learning at the Edge: The Rise of TinyML. Journal of Embedded Systems.
* Warden, P., & Situnayake, D. (2023). TinyML: Machine Learning with TensorFlow Lite on Arduino and Ultra-Low-Power Microcontrollers. O'Reilly Media.
* Banbury, C., Reddi, V., & Cheng, Y. (2023). Benchmarking TinyML Systems: New Approaches and Open Challenges. IEEE Micro.
* Mitchell, S. (2023). Mastering Arduino Nano 33 BLE: Building Interactive Wireless Applications. Tech Press.



Para empezar con este taller empezaremos explicando el porque instalamos ciertos paquetes y donde pueden descargarlos.
Como primer paso debemos de tener instalado el Arduino IDE .
Dentro del cual descargaremos lo siguiente : 
1. Instalaremos el paquete de placas Arduino_Mbed_OS_Nano_Boards pues es esencial para el Arduino Nano 33 BLE Sense Lite y su integración con Mbed OS.
2. Instalaremos la biblioteca del sensor que es Arduino_LSM9DS1 si bien es opcional si haremos uso de este paquete pues es útil ya que deseamos trabajar directamente con el sensor para configuraciones avanzadas o pruebas (manipulación directa de los datos del código).
3. Instalaremos la biblioteca Harvard_TinyMLx en el Arduino IDE ya que trabajaremos en un proyecto de TinyML y necesitamos implementar modelos de machine learning en hardware embebido. La biblioteca facilita la integración y ejecución de modelos optimizados para microcontroladores, y proporciona ejemplos y funciones que ayudan en el desarrollo y despliegue de estos modelos en dispositivos de bajo consumo.
4. Descargamos e instalamos el firmware para el Arduino Nano 33 BLE Sense pues es parte crucial del mantenimiento y la actualización de nuestra placa. El firmware asegura que la placa tenga las últimas correcciones, mejoras y funcionalidades necesarias para el proyecto. Esto es especialmente importante ya que trabajaremos con aplicaciones avanzadas que dependen de la funcionalidad más reciente del hardware y del software. En el siguiente click podemos encontrar donde descargamos el firmware https://github.com/edgeimpulse/firmware-arduino-nano-33-ble-sense?tab=readme-ov-file
5. Y si el Arduino Cli no se encontrara en su carpeta lo pueden instalar aparte y luego añadirlo el cual lo pueden conseguir en el siguiente link donde tendra que descargar el que mas se adecue a su computadora: https://github.com/arduino/arduino-cli/releases/tag/0.33.1
   

Después de haber instalado todo ello en nuestro arduino IDE empezamos con la configuracion en Edge Impulse paso a paso :
1. Abrimos un nuevo proyecto, dando click en "New Proyect".
2. Dar click en "Add existing data".
3. Dar click en "Connect device" que esta dentro de la caja de texto de collect data. En este mismo paso debemos de darnos una pantalla de confirmación que el sensor se ha conectado correctamente.
4. 

