<p align="center">
  <img src="https://github.com/JefHuiza/Fundamentos-de-Dise-o/assets/156036185/d3c66dfb-5faa-419b-bf1b-d897ea110ce7" width="70%">
</p>


# ENTREGABLE 07: Diseño del PCB

Docentes a cargo:
* Mg. U. Lewis de la Cruz Rodríguez
* umbert.de.la.cruz@upch.pe
* Ing. Renzo Chan Rios
* renzo.chan@upch.pe

INTEGRANTES:
* Flores Mescco Fiorella Ingrid
* Gutierrez Huaman Mar Flor
* Quineche Casana Luiz Ignacio
* Quispe Mamani Lizzeth Rossmer 
* Yalli Espinoza Milena Nicol

# CayePlant PCB 🌱☺️

## 1. Introducción

Este informe tiene como objetivo explicar el diseño y funcionamiento del PCB (Printed Circuit Board) para nuestro  proyecto CayePlant. Nuestro sistema está diseñado para ser compacto y modular, utilizando conectores específicos y preparado para alojar un Atom Matrix M5. El PCB está diseñado para facilitar la conexión de varios sensores y una batería.

## 2. Componentes utilizados

### 2.1 Conectores

- **BX-PH2.0-2PLT** (2 pines): Utilizado para la conexión de la batería.
- **BX-PH2.0-3PLT** (3 pines): Empleado para conectar sensores como el de humedad o luz.
- **BX-PH2.0-5PLT** (5 pines): Usado para conexiones que requieren más pines, como interfaces I2C o SPI.

### 2.2 Pines para Atom Matrix M5

Se han diseñado pines específicos en el PCB para permitir la conexión directa del  Atom Matrix M5. Esto permite que el Atom actúe como el cerebro del sistema, procesando los datos de los sensores y controlando las funciones del dispositivo. Recorando que en  Atom Matrix M5 se encuentra el ESP PICO.

### 2.3 Área para sensores

El PCB incluye áreas designadas para la conexión de diversos sensores, incluyendo:

- Sensor de humedad
- Sensor de luz

### 2.4 Conexión para batería

Se ha incluido un conector específico para la batería, permitiendo que el sistema sea portátil y funcione de manera autónoma.

## 3. Diseño y Layout

El PCB ha sido diseñado con un enfoque en la compacidad y la modularidad. Los componentes están distribuidos de manera eficiente para minimizar el tamaño total de la placa mientras se mantiene una clara separación de funciones.

### 3.1 Características del diseño

- **Forma**: El PCB tiene una forma personalizada con esquinas redondeadas y orificios de montaje para facilitar su instalación en diversos entornos.
- **Disposición de componentes**: Los conectores y pines están distribuidos alrededor del área central, donde se alojará el Atom Matrix M5.
- **Rutas de señal**: Las pistas en el PCB están optimizadas para minimizar la interferencia y asegurar una transmisión de señal limpia entre los componentes.

## 4. Funcionamiento

1. **Alimentación**: La batería se conecta al PCB a través del conector BX-PH2.0-2PLT, proporcionando energía a todo el sistema.

2. **Procesamiento**: El Atom Matrix M5 se conecta a los pines dedicados en el centro del PCB, actuando como la unidad de procesamiento principal por su ESP PICO.

3. **Sensores**: Los sensores de humedad y luz se conectan a través de los conectores BX-PH2.0-3PLT, enviando datos al Atom Matrix para su procesamiento.

4. **Expansión**: El conector BX-PH2.0-5PLT permite la adición de sensores o módulos adicionales que requieran más pines de conexión.

<p align="center">
  <img src="https://github.com/user-attachments/assets/85d3e0c0-a0ad-47cc-9d0c-9a3102729d20" width="70%">
</p>
<p align="center">Figura 01: Representación en 3D de nuestro PCB para nuestro proyecto CayePlant | Fuente: Creación propia</p>


## 6. Conclusión

El PCB CayePlant representa una solución compacta y versátil para para nuestro proyecto. Su diseño cuidadosamente planeado, junto con la selección de conectores específicos y la integración del Atom Matrix M5, resulta en un sistema potente y flexible. Este PCB sienta las bases para una variedad de aplicaciones en agricultura de precisión, monitoreo de invernaderos, o cualquier proyecto que requiera un seguimiento detallado de las condiciones ambientales.
