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

#### Especificaciones técnicas
- Voltaje: 3.3V - 5V DC
- Corriente: <5mA
- Salida: Analógica (0-1023)
- Profundidad: 38mm
- Dimensiones: 98mm x 23mm

#### Principio de funcionamiento:

<p align="justify">
El sensor de humedad capacitivo v1.2 opera mediante un sofisticado sistema de medición basado en la capacitancia. El dispositivo utiliza dos placas conductoras aisladas que, al entrar en contacto con el suelo, forman un condensador cuya capacitancia varía según el contenido de agua presente. El suelo actúa como material dieléctrico entre las placas, y sus propiedades dieléctricas cambian significativamente con el contenido de humedad. Cuando el suelo está más húmedo, su constante dieléctrica aumenta, resultando en una mayor capacitancia medida. Esta variación en la capacitancia es convertida en una señal analógica proporcional mediante un circuito integrado especializado, que posteriormente genera una lectura en el rango de 0 a 1023, donde valores más altos indican mayor contenido de humedad.

### 3.2 Sensor de luz BH1750

#### Especificaciones Técnicas
- Voltaje: 3V - 5V
- Interface: I2C
- Rango: 1-65535 lux
- Resolución: 1 lux
- Precisión: ±20%

#### Principio de funcionamiento:

<p align="justify">
El sensor de luz BH1750 emplea un sistema de detección fotométrica altamente preciso basado en un fotodiodo de silicio. Cuando la luz incide sobre el fotodiodo, se genera una corriente eléctrica proporcional a la intensidad luminosa. Esta corriente es procesada por un convertidor analógico-digital interno que transforma la señal en valores digitales de iluminancia expresados en lux. El sensor incorpora circuitos de compensación automática que ajustan la lectura según la temperatura y otros factores ambientales, asegurando mediciones consistentes en diversas condiciones. Además, cuenta con un sistema de filtrado que reduce las interferencias causadas por fuentes de luz artificial y variaciones rápidas de iluminación, proporcionando lecturas estables y confiables en un amplio rango de condiciones de iluminación.
   
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

