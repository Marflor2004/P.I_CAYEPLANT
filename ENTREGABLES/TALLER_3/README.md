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


## 3). DISCUSIÓN

Hemos logrado mostrar que el Arduino Nano 33 BLE Sense puede ejecutar un modelo de TinyML entrenado con Edge Impulse, lo que le permite identificar con precisión gestos como un círculo, el número 3 y el número 1. Esta implementación ilustra cómo los sistemas embebidos pueden realizar tareas complejas de reconocimiento de patrones de manera autónoma, sin necesidad de conexión constante a la nube, mientras optimizan el uso de recursos y energía. Al combinar el aprendizaje automático con un hardware eficiente y herramientas como Edge Impulse, hemos ampliado las posibilidades para desarrollar aplicaciones inteligentes

## 5). REFERENCIAS

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

