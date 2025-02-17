<p align="left">
  <img src="https://semanadelcannabis.cayetano.edu.pe/assets/img/logo-upch.png" width="250">
 
</p>
<div align="center">
  
# ENTREGABLE 04: Presentación de la lista de requerimiento, diagrama de circuitos eléctricos y modelado 3D
</div>

         |  Proyecto: Se busca facilitar el cuidado de plantas ornamentales, integrando tecnología de sensores y comunicación móvil para mantener al usuario informado de manera práctica y amigable.                                                                                     |

## INTEGRANTES: 
* Flores Mescco Fiorella Ingrid
* Gutiérrez Huamán Mar Flor
* Quispe Mamani Lizzeth Rossmery
* Yalli Espinoza Milena Nicol

  
## 1). INTRODUCCIÓN A NUESTRO PROYECTO:

<p align="justify">
En este proyecto, nuestro objetivo es desarrollar una planta interactiva inteligente que se comunique con el usuario, mostrando emociones y ayudando a personas que padecen ansiedad o depresión mediante una relación simbiótica y empática. A través de la interacción con el usuario, la planta no solo emitirá respuestas emocionales, sino que también alertará cuando necesite agua o luz. Además, este proyecto busca contribuir a la reducción de CO2, promoviendo el bienestar ambiental y el cambio climático positivo al incorporar una planta que absorbe este gas durante su ciclo de vida.
  
<p align="justify">
La idea principal es que nuestra planta se comporte como una compañera emocional que, al igual que una mascota, fomente una relación cercana con el usuario, ayudándolo a reducir su estrés. A largo plazo, esperamos que esta tecnología se convierta en un producto de consumo masivo que beneficie tanto a la salud emocional de las personas como al medio ambiente.

## 2) LISTA DE REQUERIMIENTOS:
   
> Objetivo Principal:
El objetivo principal de este proyecto es crear una planta interactiva con la capacidad de monitorear su entorno y responder de manera "emocional" al usuario, con un impacto positivo en la absorción de CO2.


# *Función*

| Característica principal | Característica secundaria                          | Estudio del caso industrial                                                                                   |
|--------------------------|---------------------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Material del macetero    | Plástico PETG (polietileno tereftalato glicol)| Ideal para aplicaciones que requieren resistencia al agua y durabilidad, flexibilidad y resistencia a impactos. |                                                                                                               |
| Material de la pantalla  | Pantalla LCD o LED resistente a condiciones ambientales  |   La pantalla debe ser resistente a la humedad y cambios de temperatura, ubicada en la parte frontal del macetero para mostrar las "emociones" de la planta según sus condiciones actuales.                                                                                                            |
|     Energía     | Batería recargable con carga mediante cable tipo celular |   El dispositivo se alimentará mediante una batería recargable similar a las utilizadas en celulares, con carga proporcionada a través de un cable estándar.                                                                                                           |
|      Señales          | Analógicas y digitales| Sensores: analógicos para medición de luz y humedad; comunicación: digitales para la transmisión de datos a través de WhatsApp. |                                                                                                               |
|     Definición de interfaces                  | Aplicativo para control y notificaciones        |       Interfaz para la visualización y ajustes del sistema, compatible con API de WhatsApp para el envío de notificaciones.                                                                                                        |
|         Costos                 | Moderado| Dentro del presupuesto para materiales y componentes necesarios, buscando equilibrio entre calidad y costo. |                                                                                                  |

---


# *Diseño/estructura*


| Característica principal | Característica secundaria                                    | Estudio del caso industrial                                                                                   |
|--------------------------|-------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Geometría                |    Tamaño compacto y discreto para integración en la maceta                  | El dispositivo de control debe tener un tamaño compacto para integrarse en la base o lateral de la maceta. Dimensiones recomendadas: Alto < 50 mm, Ancho < 100 mm. .|
|    Dimensiones de la pantalla                      | Acomodada en la parte frontal de la maceta| Tamaño suficiente para mostrar información de manera clara, sin obstruir el acceso a la planta. |
| Hardware              | Voltaje de operación nominal: 5V| Compatible con los estándares para garantizar una integración efectiva con el sistema de control. Alimentado por un microcontrolador ESP32.|                                                                                                               |
|                          | Accesibilidad e intercambiabilidad| Los sensores deben ser accesibles para mantenimiento y reemplazables sin necesidad de desarmar toda la maceta. El diseño debe permitir un fácil acceso.|                                                                                                   
| Software                 | Lenguaje de programación                                 | El software del sistema se desarrollará en Arduino, utilizando la placa ESP32 para gestionar los sensores y el envío de mensajes por WhatsApp mediante APIs.        |
|                          | Integración y conectividad|   La programación debe incluir la integración con sensores de luz y humedad, y la conectividad con Wi-Fi para enviar notificaciones de estado en tiempo real.|                                                                                                               |
| Ergonomía                | Interacción humano-dispositivo                              | Pantalla frontal que muestra las "emociones" de la planta basadas en las condiciones actuales. Uso intuitivo con indicadores claros para el estado de luz y humedad. |

---


# *Realización y Producción*


| Característica principal  | Característica secundaria                                           | Estudio del caso industrial                                                                                   |
|---------------------------|--------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Fabricación               | Impresión 3D para estuche del componente | Se realizará la impresión con material PETG, debido a su resistencia a la humedad, otra opción a considerar, sería el Nylon, pero es más difícil de imprimir debido a su tendencia a deformarse, y también requiere un ambiente controlado durante la impresión. |                                                                     

---


# *Uso/Reciclando*

| Característica principal | Característica secundaria                          | Estudio del caso industrial                                                                                   |
|--------------------------|---------------------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Uso                      | Área de aplicación y venta|  SECTOR COMERCIAL.- tiendas de jardinería y decoración. SECTOR EDUCATIVO.-Escuelas y universidades. SECTOR CORPORATIVO.- Oficinas y espacios comerciales. MERCADO DE TECNOLOGÍA Y ELECTRÓNICA.- Plataformas de E-commerce, tiendas de Electrónica y Gadget Stores. | Ubicación| Es de preferencia al usuario, pero como recomendacion, seria adecuado mantenerlo en un lugar fresco con buena iluminación| 
|                          | Puesta en servicio| Acondicionado,para verificar las necesidades de la planta|                                                                                                               |
|               | Ubicación  |Es de preferencia al usuario, pero como recomendacion, seria adecuado mantenerlo en un lugar fresco con buena iluminación.|
|                          | Comodidad| De fácil uso, interactivo con el usuario en todos los aspectos. |                                                                                                               |
|                          | Servicio|     Manual de guia para el usuario en la instalación del producto           |                                                                                                               |
|                          | Fiabilidad| Vida prolongada de uso , con garantia en su compra para mantenimiento del producto 
| Reciclaje                | Desecho| los componentes electrónicos del macetero inteligente, tendrían segundo uso de funcionamiento para su posible reciclaje-reuso.|                                                                                                   
---

# *Organización*


| Característica principal | Característica secundaria                           | Estudio del caso industrial                                                                                   |
|--------------------------|----------------------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Planificación            | Costo| Un aproximado de 90 soles |                                                                                                               |
|                          | Leyes| Ley de Promoción de las Inversiones para el Crecimiento Económico y el Desarrollo Sostenible LEY Nº 30327. Asegurarse de que el dispositivo cumpla con las normativas locales y los estándares pertinentes para su fabricación y funcionamiento. |                                                                                                               |
| Sostenibilidad           | Equilibrio ecológico| El equipo total del macetero inteligente,integra tácticas de producción sostenible, además, incluyen materiales reciclados como por ejemplo el macetero per se, de la planta |                                                                                           
## 3) DIAGRAMA DE CIRCUITOS ELECTRÓNICOS:
#### M5Stack Atom Matrix
*Es un microcontrolador basado en ESP32 con una matriz de LED 5x5, ideal para proyectos IoT, automatización y sensores. Incluye conectividad Wi-Fi y Bluetooth.*
- [Enlace al componente](https://easyeda.com/component/e0f2617baaf74262977347b0f7a93205)
- [Documentación oficial](https://docs.m5stack.com/en/core/ATOM%20Matrix)
  
#### Capacitive Soil Moisture Sensor v1.2
*Este sensor capacitivo mide la humedad del suelo sin oxidarse, ya que no tiene partes metálicas expuestas. Ideal para proyectos de monitoreo de plantas*
- [Enlace al componente](https://easyeda.com/components/Capacitive-Soil-Moisture-Sensor-v1-2_d5a816a6bab84d07a15c73d8d056d861)
- [Documentación oficial](https://media.digikey.com/pdf/data%20sheets/dfrobot%20pdfs/sen0193_web.pdf)

#### Sensor de luz BH1750 (GY-302)
*El sensor BH1750 es un medidor digital de luz ambiente que mide la intensidad de la luz en lux y puede utilizarse para ajustar automáticamente la iluminación o el crecimiento de las plantas.*
- [Enlace al componente](https://easyeda.com/component/BH1750-ea243013e9a94c9cbe7a12299ec2aeed)
- [Documentación oficial](https://www.mouser.com/datasheet/2/348/bh1750fvi-e-186247.pdf?srsltid=AfmBOooLdeD7OcCdxs-5Fv5oypMNYeaEw_alkJbjntrxK36hfGx-TguX)
  
#### Regulador de voltaje MT3608 Elevador de Voltaje Boost Step Up 6W 2A
*El MT3608 Elevador de Voltaje Boost Step-Up 6W 2A tiene como función entregar un voltaje de salida (5V a 28V) superior al voltaje de entrada( 2V a 24V) soportando corrientes de salida de hasta 2A.*
- [Enlace al componente](https://uelectronics.com/producto/modulo-regulador-mt3608-step-up-5-28v-2a/?srsltid=AfmBOop1EhvKYXsmaljdzFaOj48vN7w-0VVUk81rvgmMehwnLxWGHOa2).
- [Documentación oficial]( https://www.digikey.com/en/product-highlight/a/ams/oslon-pure-1414-leds?dclid=CMLa3M3z_YgDFTjhlAkd9sIK7Q)

#### Cargador de baterías de Litio 18650 con TP4056
El Módulo TP4056 Cargador De Batería Litio Lipo es un minúsculo módulo perfecto para la carga de baterías LiPo o Li-ion de una sola celda de 3.7V 1 Ah o superior como las 16550 o las 18650 y ahora incluye su circuito de protección, para que se tus baterías no reciban ningún daño.
- [Enlace al componente](https://www.teslaelectronic.com.pe/producto/cargador-de-baterias-de-litio-18650-con-tp4056-y-usb-c/)
  
#### Batería Lipo 450mAh / 3.7V - 601248
*Batería Lipo (Polymer Lithium) de alta calidad y capacidad de 450mAh, modelo 601248. Este tipo de baterías proporciona una fuente de alimentación muy eficiente, a la vez que son muy ligeras y soportan altos picos de corriente.*
- [Enlace al componente](https://tienda.bricogeek.com/baterias-lipo/1608-bateria-lipo-450mah.html).

![Diagrama esquemático](https://github.com/Marflor2004/CrackDetect/blob/main/ENTREGABLES/TALLER_4/Esquem%C3%A1tico.jpg)

</p>
<div align="center">
  Fuente: Elaborado por el grupo N°:7
</div>

         |  El circuito electrónico tiene como objetivo principal monitorear y controlar el ambiente de la planta inteligente. Los sensores recolectan datos que el microcontrolador procesa para tomar decisiones, como regar la planta o ajustar la iluminación, garantizando así condiciones óptimas para el crecimiento de las plantas. Este sistema permite la automatización y mejora la eficiencia en el cuidado de las plantas.                                                                                    |


## 4) MODELADO 3D:

Para el diseño estructural de la planta interactiva, hemos desarrollado un modelo en 3D que incluye lo siguiente:

Carcasa de nuestro macetero: La estructura de la planta será impresa en 3D. Hemos diseñado la carcasa de manera que los sensores y luces estén integrados de forma discreta y estética.

<div align="center"; style="display: flex; justify-content: space-between;">
  <img src=https://github.com/user-attachments/assets/8daa80e4-0d0e-47fd-b62b-8136dee99bd6 width="600px"/>
</div>

<p align="center"> Imagen 01: Diseño de la carcasa del macetero, realizado en Onshape.


---

# Referencias:
[1]L. No, "Ley de Promoción de las Inversiones para el Crecimiento Económico y el Desarrollo Sostenible," Gob.pe. [En línea]. Disponible en: https://www.minam.gob.pe/wp-content/uploads/2017/04/Ley-N%C2%B0-30327.pdf.





