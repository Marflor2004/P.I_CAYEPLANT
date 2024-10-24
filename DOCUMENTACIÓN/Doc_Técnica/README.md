# Informe técnico CayePlant: Análisis TRL y especificaciones del sistema

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

### 3.1 Sensor de Humedad Capacitivo v1.2

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
- Base de datos para histórico

#### 3.3.2 Diagrama 



#### 3.3.3 Flujo de comunicación
1. Recepción de mensajes
2. Procesamiento de datos
3. Generación de respuestas
4. Envío de respuestas
5. Almacenamiento de histórico

## 4. Integración y desarrollo

### 4.1 Hardware
- Diseño de PCB
- Integración de sensores
- Sistema de alimentación
- Carcasa protectora

### 4.2 Software
- Backend Flask
- API de comunicación
- Sistema de alertas
- Gestión de datos

### 4.3 Comunicación
- Protocolo WhatsApp
- Integración Twilio
- Procesamiento GPT-4
- Sistema de notificaciones
