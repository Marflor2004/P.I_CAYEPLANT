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
<div align="center">

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
<div align="center">

# *Realización y Producción*


| Característica principal  | Característica secundaria                                           | Estudio del caso industrial                                                                                   |
|---------------------------|--------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Fabricación               | Impresión 3D para estuche del componente | Se realizará la impresión con material PETG, debido a su resistencia a la humedad, otra opción a considerar, sería el Nylon, pero es más difícil de imprimir debido a su tendencia a deformarse, y también requiere un ambiente controlado durante la impresión. |                                                                     

---
<div align="center">

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
<div align="center">

# *Organización*


| Característica principal | Característica secundaria                           | Estudio del caso industrial                                                                                   |
|--------------------------|----------------------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Planificación            | Costo| Un aproximado de 90 soles |                                                                                                               |
|                          | Leyes| Ley de Promoción de las Inversiones para el Crecimiento Económico y el Desarrollo Sostenible LEY Nº 30327. Asegurarse de que el dispositivo cumpla con las normativas locales y los estándares pertinentes para su fabricación y funcionamiento. |                                                                                                               |
| Sostenibilidad           | Equilibrio ecológico| El equipo total del macetero inteligente,integra tácticas de producción sostenible, además, incluyen materiales reciclados como por ejemplo el macetero per se, de la planta |                                                                                           
## 3) DIAGRAMA DE CIRCUITOS ELÉCTRICOS:

A continuación, presentamos el diagrama eléctrico de la planta interactiva. El diseño incluye los siguientes elementos:

- Controlador central (Arduino Nano o similar): Conectado a los sensores de luz, humedad y temperatura, será el encargado de procesar los datos y activar las emociones en función de los estímulos externos.

- Conexiones a LEDs y pantalla: El controlador también estará conectado a los LEDs, que representarán las emociones de la planta. Si usamos una pantalla LED opcional, también se conectará a este controlador para mostrar información relevante al usuario.

- Alimentación eléctrica: Usaremos una batería recargable, que alimentará tanto los sensores como los LEDs y la unidad de control.

- Comunicación Bluetooth o WiFi: Este componente permitirá la interacción entre la planta y una aplicación móvil, donde el usuario podrá visualizar el estado de la planta y recibir recomendaciones sobre su cuidado.

## 4) MODELADO 3D:

Para el diseño estructural de la planta interactiva, hemos desarrollado un modelo en 3D que incluye lo siguiente:

Carcasa de nuestro macetero: La estructura de la planta será impresa en 3D. Hemos diseñado la carcasa de manera que los sensores y luces estén integrados de forma discreta y estética.

<div align="center"; style="display: flex; justify-content: space-between;">
  <img src=https://github.com/user-attachments/assets/8daa80e4-0d0e-47fd-b62b-8136dee99bd6 width="600px"/>
</div>

<p align="center">Imagen 01: Diseño de la carcasa del macetero, realizado en Onshape.


---

# Referencias:
[1]L. No, "Ley de Promoción de las Inversiones para el Crecimiento Económico y el Desarrollo Sostenible," Gob.pe. [En línea]. Disponible en: https://www.minam.gob.pe/wp-content/uploads/2017/04/Ley-N%C2%B0-30327.pdf.





