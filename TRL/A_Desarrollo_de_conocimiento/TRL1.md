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

#### Principio de funcionamiento
1. Placas capacitivas aisladas
2. Medición dieléctrica del suelo
3. Conversión capacitancia-señal
4. Procesamiento analógico

### 3.2 Sensor de luz BH1750

#### Especificaciones Técnicas
- Voltaje: 3V - 5V
- Interface: I2C
- Rango: 1-65535 lux
- Resolución: 1 lux
- Precisión: ±20%

#### Principio de funcionamiento
1. Fotodiodo de silicio
2. Conversión luz-corriente
3. Procesamiento digital
4. Compensación automática
5. Filtrado de interferencias
   
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

1. **Twilio API recibe la información** del microcontrolador (ESP32/ATOM MATRIX M5) cuando se detecta un evento (como baja humedad en la planta).
2. **Twilio envía el mensaje** al número de WhatsApp registrado.
3. **El usuario recibe la notificación** en su WhatsApp en tiempo real.

