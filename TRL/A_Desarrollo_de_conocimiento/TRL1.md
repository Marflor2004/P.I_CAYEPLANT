<p align="center">
  <img src="https://github.com/JefHuiza/Fundamentos-de-Dise-o/assets/156036185/d3c66dfb-5faa-419b-bf1b-d897ea110ce7" width="70%">
</p>


# TRL 1:  Análisis TRL1 y especificaciones del sistema:

Docentes a cargo:
* Mg. U. Lewis de la Cruz Rodríguez
* umbert.de.la.cruz@upch.pe
* Ing. Renzo Chan Rios
* renzo.chan@upch.pe

Integrantes:
* Flores Mescco Fiorella Ingrid
* Gutierrez Huaman Mar Flor
* Quineche Casana Luiz Ignacio
* Quispe Mamani Lizzeth Rossmery
* Yalli Espinoza Milena Nicol

## 1. Descripción general:
CayePlant es un macetero inteligente que combina IoT, IA y comunicación interactiva para crear una experiencia única de cuidado de plantas. El sistema utiliza sensores avanzados, comunicación vía WhatsApp y procesamiento de lenguaje natural para establecer una conexión significativa entre usuarios y sus plantas.

## 2. Análisis de Technology Readiness Levels (TRL)

### 2.1 TRL Actual

#### TRL 1 - Principios básicos observados y reportados
- **Estado**: Completado
- **Evidencias**:
  - Investigación básica sobre interacción planta-usuario
  - Estudio de viabilidad de sensores IoT
  - Análisis de tecnologías de comunicación
  - Investigación sobre interfaces emocionales
  - Fundamentación teórica
    
## 3. Análisis técnico de componentes

### 3.1 Sensor de humedad capacitivo v1.2


| Función Fisica | Medio Fisico  | Función Quimica |Interacción|
|--------|----------------|------------------|---------------|
| Medición de la capacitancia del suelo| Suelo (tierra o sustrato) |Interacción de agua con el suelo |Cuando el sensor se inserta en el suelo, el agua actúa como un dieléctrico, cambiando la capacitancia medida. Este cambio se debe a que la capacitancia depende de la constante dieléctrica del medio, que aumenta con la cantidad de agua presente.|
|Detección de cambios en humedad | Agua presente en el suelo | Ionización y polaridad de moléculas de agua |La humedad altera la distribución de carga en el suelo, afectando su conductividad. A medida que aumenta la humedad, las moléculas de agua facilitan la movilidad de iones en el suelo, lo que cambia su conductividad eléctrica.|
| Transmisión de señal eléctrica| Circuito electrónico interno | Reacción de los electrodos con iones en el suelo|El sensor convierte la capacitancia medida en una señal eléctrica. Esta señal se amplifica y digitaliza en el circuito interno, lo que permite la transmisión de datos al microcontrolador para su procesamiento.|
| Uso de electrodos para captar humedad | Electrodos metálicos (cobre/acero inoxidable) | Corrosión potencial debido a la conductividad del suelo |La interacción entre los electrodos y los iones presentes en el suelo puede provocar reacciones de corrosión. La presencia de agua y sales en el suelo puede acelerar este proceso, afectando la durabilidad del sensor y la precisión de las mediciones.|



### 3.2 Sensor de luz BH1750
| **Función Química**                  | **Medio Físico**              | **Función Física**                     | **Interacción**                                                   |
|--------------------------------------|-------------------------------|----------------------------------------|------------------------------------------------------------------|
| Conversión de luz en señal eléctrica  | Luz (fotones)                 | Medición de intensidad de luz         | El sensor utiliza fotoceldas (fotodiodos) que convierten la energía de los fotones en corriente eléctrica. Cuanto más intensa sea la luz, mayor será la corriente generada. |
| Reacción fotoeléctrica                | Semiconductores (materiales como Si) | Producción de señal proporcional a la luz | La interacción de la luz con los electrones en el material semiconductor produce electrones libres, que crean una corriente eléctrica proporcional a la cantidad de luz recibida. |
| Interacción con la atmósfera         | Aire y condiciones ambientales | Influencia en la medición de luz      | Factores como la humedad y partículas en el aire pueden afectar la cantidad de luz que llega al sensor, alterando las mediciones. |
| Respuesta a diferentes longitudes de onda | Luz visible e infrarroja      | Detección de distintos tipos de luz   | El sensor es sensible a diferentes longitudes de onda, permitiendo medir la luz en el rango visible y parte del infrarrojo, afectando las lecturas según el tipo de luz ambiental. |


   
### 3.3 Sistema de comunicación e IA

#### 3.3.1 Arquitectura del sistema
- WhatsApp Business API
- Twilio para mensajería
- Flask como backend
- OpenAI GPT-4
 
### **Características de Twilio API:**

- **Mensajería programable**: Permite enviar y recibir mensajes de forma automatizada.
- **Compatibilidad con WhatsApp**: A través de la API, se pueden enviar mensajes de WhatsApp a los usuarios.
- **Escalabilidad**: Soporta desde pequeñas aplicaciones hasta grandes volúmenes de mensajes.
- **Fácil integración**: Puedes integrarlo en aplicaciones usando varios lenguajes de programación (Python, Java, Node.js, etc.).

### **Flujo de funcionamiento:**

<div align="center"; style="display: flex; justify-content: space-between;">
  <img src="https://github.com/user-attachments/assets/8a40b06b-98d2-49e6-9764-ecfed6d72423" width="600px"/>
</div>

<p align="center">Figura 01: Diagrama de flujo | Fuente: Creación propia</p>

1. **Twilio API recibe la información del microcontrolador** (ESP32/Atom Matrix M5) cuando uno de los sensores, como 
   el de humedad capacitivo, detecta niveles críticos de humedad en el sustrato de la planta, lo que desencadena el 
   envío de una notificación a través de WhatsApp.
2. **Twilio, al recibir los datos procesados del microcontrolador** , se encarga de enviar automáticamente un mensaje de alerta al número de WhatsApp previamente registrado, informando al usuario sobre las condiciones específicas de la planta, como la necesidad urgente de agua, asegurando así una interacción inmediata y efectiva.
3. **El usuario recibe la notificación** en su WhatsApp en tiempo real.

