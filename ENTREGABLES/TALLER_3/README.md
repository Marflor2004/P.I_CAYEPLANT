# TEMA: Modelo TinyML en Arduino Nano 33 BLE SENSE para el reconocimiento de formas y números 

## INTEGRANTES: 
* Milena Yally
* Fiorella Flores
* Mar Gutierrez
* Lizeth Mamani
  
## 1). INTRODUCCIÓN

TinyML es una tecnología que permite la implementación de modelos de Machine Learning en dispositivos de bajo consumo, como microcontroladores, posibilitando análisis en tiempo real de datos sensoriales, como visión y audio, directamente en el dispositivo, lo que reduce la dependencia de la nube y mejora la privacidad y seguridad de los datos (Lane et al., 2024; Warden et al., 2023). Su crecimiento ha impulsado el desarrollo de herramientas, como frameworks y bibliotecas, facilitando su uso en diversas industrias, desde la salud hasta la agricultura (Banbury et al., 2023).
La placa Nano 33 BLE Sense incorpora sensores y capacidades de conectividad mediante Bluetooth de baja energía, lo cual la hace ideal para aplicaciones que necesitan interactuar con el entorno y establecer comunicación inalámbrica eficiente (Mitchell, 2023).



<p align="left">
  <img src="https://semanadelcannabis.cayetano.edu.pe/assets/img/logo-upch.png" width="250">
 
</p>




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

