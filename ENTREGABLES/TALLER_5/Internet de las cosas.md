<p align="left">
  <img src="https://semanadelcannabis.cayetano.edu.pe/assets/img/logo-upch.png" width="250">
 
</p>
<div align="center">
  
# ENTREGABLE 05: Exploración y familiarización del Internet de las Cosas (IoT)
</div>

         |  Objetivo:  Convertir el MKR IoT Carrier en un dispositivo agrícola urbano, utilizando sensores y relés para monitorear y controlar el entorno de una planta. Se configuró un panel en Arduino Cloud para leer datos en tiempo real y activar dispositivos de alta potencia.                                                                                   |

###### Docentes a cargo:
 - Mg. U. Lewis de la Cruz Rodríguez
 - > umbert.de.la.cruz@upch.pe
 - Ing. Renzo Chan Rios
 - > renzo.chan@upch.pe

#### INTEGRANTES: 
* Flores Mescco Fiorella Ingrid
* Gutierrez Huaman Mar Flor
* Quispe Mamani Lizzeth Rossmery
* Yalli Espinoza Milena Nicol

  
### 1). INTRODUCCIÓN:

El IoT permite que los datos recolectados mediante sensores sean monitoreados de manera remota, lo que facilita la creación de bases de datos que permiten realizar análisis estadísticos, identificar tendencias y evaluar probabilidades. Esto resulta fundamental para comprender el comportamiento de personas y entornos, así como para optimizar procesos y detectar áreas de mejora en sistemas electrónicos integrales[1].


### 2). MATERIALES UTILIZADOS: 

- Arduino MKR WiFi 1010
- MKR IoT Carrier
- Sensor de humedad
- Cable micro USB
- Tierra de una planta 
- Maceta con la tierra de la tierra de la planta
- Computadora con acceso a internet
- Cuenta de Arduino Cloud

### 3) METODOLOGÍA:

**3.1 Preparación del hardware:**

<p align="justify">
Primero, montamos el Arduino MKR WiFi 1010 en el MKR IoT Carrier. Luego, conectamos el sensor de humedad al pin A5 del carrier. Finalmente, conectamos el cable micro USB a nuestro ordenador.
  
<div align="center"; style="display: flex; justify-content: space-between;">
  <img src=https://github.com/user-attachments/assets/01871b1d-8b03-4869-b8ab-5a8f56776a7f width="600px"/>
</div>

<p align="center">Imagen 01: Arduino MKR WiFi 1010 montado en el MKR IoT Carrier </p>

**3.2 Configuración del Arduino Cloud:**

<p align="justify">
Ahora, abrimos el Arduino Cloud y creamos una nueva "Thing" que llamamos "GRUPO 07". Configuramos las siguientes variables en la nube:
  
- Humedad (float)
- Temperatura (float)
- Luz (int)
- HumedadValor (int)
- Relé_1 (Boolean)
- Relé_2 (Boolean)
- rgbColor (Color)
- actualizaciónPantalla (Boolean)

> No olvidamos configurar las credenciales de nuestra red WiFi en el panel Network.

<div align="center"; style="display: flex; justify-content: space-between;">
  <img src=https://github.com/user-attachments/assets/8b733a87-e056-4a9f-a4d9-2fce9746c130 width="600px"/>
</div>
<p align="center">Imagen 02: Entrando a la ventana de Thing</p>

<div align="center"; style="display: flex; justify-content: space-between;">
  <img src=https://github.com/user-attachments/assets/787f7f7e-690c-4d50-9411-7537b5924ca9 width="600px"/>
</div>
<p align="center">Imagen 03: Creación de una nueva 'Thing' llamada 'GRUPO 07' en Arduino Cloud</p>

<div align="center"; style="display: flex; justify-content: space-between;">
  <img src=https://github.com/user-attachments/assets/bd607b88-23bb-4bf9-88bc-255f894e7be4 width="600px"/>
</div>
<p align="center">Imagen 04: Evidencia de la creación de la carpeta </p>

<div align="center"; style="display: flex; justify-content: space-between;">
  <img src=https://github.com/user-attachments/assets/1ce4f417-f2f8-4963-9d22-ac334ed083a2 width="600px"/>
</div>

<p align="center"> Imagen 05: Lista de variables configuradas en Arduino Cloud para nuestro proyecto</p>


**3.3 Creación del panel de control:**

En el Arduino Cloud, creamos un nuevo dashboard y lo llamamos "GRUPO 07". Añadimos los siguientes widgets y los vinculamos a nuestras variables:

- Un widget de porcentaje para humedad (rango 0-100)
- Un indicador para temperatura (rango -40 a 100)
- Un widget de valor para luz
- Un widget de porcentaje para humedadValor (rango 0-100)
- Un switch para relé_1
- Un switch para relé_2
- Un widget de luz coloreada para rgbColor
- Un switch para actualizaciónPantalla

<div align="center"; style="display: flex; justify-content: space-between;">
  <img src=https://github.com/user-attachments/assets/4dc069ad-645d-4e65-aa0d-fedd9d77dbc0 width="600px"/>
</div>

<p align="center"> Imagen 06: Entrando a la ventana de Dashboard</p>

<div align="center"; style="display: flex; justify-content: space-between;">
  <img src=https://github.com/user-attachments/assets/573878cf-aff1-4b28-b834-cd1ab22a1286 width="600px"/>
</div>


<p align="center"> Imagen 07: Dashboard completo en Arduino Cloud con todos los widgets configurados </p>

**3.4 Programación del sketch:**

<p align="justify">
Ahora, programamos nuestro sketch. Primero, incluimos las bibliotecas necesarias e inicializamos los objetos. En el setup(), inicializamos la comunicación serial, las propiedades y la conexión a la nube.
En el loop(), programamos el control de los relés basado en los switches del dashboard. También leemos los valores de los sensores (luz, temperatura, humedad, humedad del suelo) y mapeamos el valor de humedad del suelo a un rango de 0-100. Implementamos las funciones de callback para los cambios en los widgets del dashboard, como el control de los LEDs RGB.

<div align="center"; style="display: flex; justify-content: space-between;">
  <img src=https://github.com/user-attachments/assets/d1eb9afc-7125-4fe8-8a99-a1eb96043138 width="600px"/>
</div>

<p align="center"> Imagen 08: Ventana de nuestro sketch_GRUPO 07 y bibliotecas instaladas </p>

```cpp
void setup() {
  Serial.begin(9600);
  initProperties();  // Asegúrate de que thingProperties.h está bien incluido
  // Configurar la conexión a IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  CARRIER_CASE = true;  // Activa el uso del estuche del MKR IoT Carrier
  carrier.begin();      // Inicializa el carrier
  
  pinMode(externalLedPin, OUTPUT);  // Definir el pin del LED externo como salida
  
  setDebugMessageLevel(4);   // Obtener información y errores de la nube
  ArduinoCloud.printDebugInfo();
  
  while (!ArduinoCloud.connected()) {
    ArduinoCloud.update();
    carrier.display.setTextSize(3);
    carrier.display.setCursor(20, 70);
    carrier.display.println("Waiting For");
    carrier.display.setCursor(5, 110);
    carrier.display.println("Connection...");
    delay(500);
  }
}


```
<p align="center"> Codigo 01 : Código de inicialización en el setup() </p>

```cpp
void loop() {
  ArduinoCloud.update();
  if (carrier.Light.colorAvailable()) {
    int none; // Variable temporal
    carrier.Light.readColor(none, none, none, luz);
  }
  temperatura = carrier.Env.readTemperature();
  humedad = carrier.Env.readHumidity();
  int rawMoistValue = analogRead(moistPin);
  humedadValor = map(rawMoistValue, 0, 1023, 100, 0);
}


```

<p align="center"> Codigo 02 : Código principal en el loop() </p>

```cpp
void onHumedadChange() {
  Serial.print("Humedad changed to: ");
  Serial.println(humedad);
}

void onTemperaturaChange() {
  Serial.print("Temperatura changed to: ");
  Serial.println(temperatura);
}

void onRgbColorChange() {
  uint8_t r, g, b;
  rgbColor.getValue().getRGB(r, g, b);
  if (rgbColor.getSwitch()) {
    carrier.leds.fill(carrier.leds.Color(g, r, b), 0, 5);
    carrier.leds.show();
  } else {
    carrier.leds.fill(0, 0, 5);
    carrier.leds.show();
  }
}

void onUpdateDisplayChange() {
  // ... (código para actualizar la pantalla)
}

void onRele1Change() {
  if (rele_1) {
    carrier.Relay1.open();
    relayState1 = "ON";
    digitalWrite(externalLedPin, HIGH); 
  } else {
    carrier.Relay1.close();
    relayState1 = "OFF";
    digitalWrite(externalLedPin, LOW); 
  }
}


```

<p align="center"> Codigo 03 :Funciones de callback para los widgets del dashboard </p>

### **CODIGO COMPLETO**
```cpp
#include "thingProperties.h"
#include <Arduino_MKRIoTCarrier.h>
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

MKRIoTCarrier carrier;

int moistPin = A5;
const int externalLedPin = A6; // Pin para el LED externo

String relayState1 = "";
String relayState2 = "";

void setup() {
  Serial.begin(9600);
  initProperties();  // Asegúrate de que thingProperties.h está bien incluido

  // Configurar la conexión a IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  CARRIER_CASE = true;  // Activa el uso del estuche del MKR IoT Carrier
  carrier.begin();      // Inicializa el carrier
  
  pinMode(externalLedPin, OUTPUT);  // Definir el pin del LED externo como salida
  
  setDebugMessageLevel(4);   // Obtener información y errores de la nube
  ArduinoCloud.printDebugInfo();
  
  while (!ArduinoCloud.connected()) {
    ArduinoCloud.update();
    carrier.display.setTextSize(3);
    carrier.display.setCursor(20, 70);
    carrier.display.println("Waiting For");
    carrier.display.setCursor(5, 110);
    carrier.display.println("Connection...");
    delay(500);
  }
}

void loop() {
  ArduinoCloud.update();

  if (carrier.Light.colorAvailable()) {
    int none; // Variable temporal
    carrier.Light.readColor(none, none, none, luz);
  }

  temperatura = carrier.Env.readTemperature();
  humedad = carrier.Env.readHumidity();

  int rawMoistValue = analogRead(moistPin);
  humedadValor = map(rawMoistValue, 0, 1023, 100, 0);
}

void onHumedadChange() {
  Serial.print("Humedad changed to: ");
  Serial.println(humedad);
}

void onTemperaturaChange() {
  Serial.print("Temperatura changed to: ");
  Serial.println(temperatura);
}

void onHumedadValorChange() {
  Serial.print("HumedadValor changed to: ");
  Serial.println(humedadValor);
}

void onLuzChange() {
  Serial.print("Luz changed to: ");
  Serial.println(luz);
}

void onRgbColorChange() {
  uint8_t r, g, b;
  rgbColor.getValue().getRGB(r, g, b);
  if (rgbColor.getSwitch()) {
    carrier.leds.fill(carrier.leds.Color(g, r, b), 0, 5);
    carrier.leds.show();
  } else {
    carrier.leds.fill(0, 0, 5);
    carrier.leds.show();
  }
}

void onUpdateDisplayChange() {
  if (!updateDisplay) return;
  
  carrier.display.fillScreen(ST77XX_WHITE);
  carrier.display.setTextColor(ST77XX_RED);
  carrier.display.setTextSize(2);

  carrier.display.setCursor(20, 30);
  carrier.display.print("Temperatura: ");
  carrier.display.print(temperatura);
  carrier.display.print(" C");

  carrier.display.setCursor(20, 50);
  carrier.display.print("Humedad: ");
  carrier.display.print(humedad);
  carrier.display.print(" %");

  carrier.display.setTextColor(ST77XX_ORANGE);
  carrier.display.setCursor(20, 70);
  carrier.display.print("Luz: ");
  carrier.display.print(luz);

  carrier.display.setTextColor(ST77XX_BLUE);
  carrier.display.setCursor(20, 90);
  carrier.display.print("HumedadValor: ");
  carrier.display.print(humedadValor);
  carrier.display.print(" %");

  carrier.display.setTextColor(ST77XX_BLUE);
  carrier.display.setCursor(20, 120);
  carrier.display.print("R1: ");
  carrier.display.print(relayState1);

  carrier.display.print("R2: ");
  carrier.display.print(relayState2);

  updateDisplay = false;
}

void onRele1Change() {
  if (rele_1) {
    carrier.Relay1.open();
    relayState1 = "ON";
    digitalWrite(externalLedPin, HIGH); 
  } else {
    carrier.Relay1.close();
    relayState1 = "OFF";
    digitalWrite(externalLedPin, LOW); 
  }
}

void onRele2Change() {
  if (rele_2) {
    carrier.Relay2.open();
    relayState2 = "ON";
  } else {
    carrier.Relay2.close();
    relayState2 = "OFF";
  }
}


```


**3.5 Carga y prueba:**

<p align="justify">
Verificamos y cargamos el sketch en nuestra placa Arduino. Abrimos el Serial Monitor para verificar que la conexión con Arduino Cloud se ha establecido correctamente. Interactuamos con los widgets del dashboard y observamos los cambios en los sensores y actuadores para asegurarnos de que todo funciona como esperamos.

<div align="center"; style="display: flex; justify-content: space-between;">
  <img src=https://github.com/user-attachments/assets/978e7188-92ea-490d-bde2-2c0579e79664="600px"/>
</div>

<p align="center"> Imagen 09 : Serial Monitor mostrando conexión exitosa con Arduino Cloud </p>


<div align="center"; style="display: flex; justify-content: space-between;">
  <img src=https://github.com/user-attachments/assets/25c3a767-3c76-4301-9cee-30a1a00320f0 width="600px"/>
</div>

<p align="center"> Imagen 10 :MKR IoT Carrier en funcionamiento con LEDs encendidos y datos en pantalla </p>

  
### 4). CONFIGURACIÓN DEL SISTEMA
- Abrir Arduino Cloud y conectar el dispositivo:
  <div style="border: 2px solid black; padding: 10px; display: inline-block;">
    <img src="https://i.postimg.cc/650JzCDq/Dispositivo.jpg" alt="Resultado" style="max-width: 100%;">
</div>

- Crear un nuevo Sketch:
  
  Esto hará posible programar el dispositivo y visualizar los datos en tiempo real.
  <div style="border: 2px solid black; padding: 10px; display: inline-block;">
    <img src="https://i.postimg.cc/ydV0h49k/Sketch.jpg)" alt="Resultado" style="max-width: 100%;">
</div>

 <div style="border: 2px solid black; padding: 10px; display: inline-block;">
    <img src="https://i.postimg.cc/PqHDhsS2/Things.jpg" alt="Resultado" style="max-width: 100%;">
</div>

  


### 4). RESULTADOS 

###### Código
```cpp
#include "thingProperties.h"
#include <Arduino_MKRIoTCarrier.h>
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

MKRIoTCarrier carrier;

int moistPin = A5;
const int externalLedPin = A6; // Pin para el LED externo

String relayState1 = "";
String relayState2 = "";

void setup() {
  Serial.begin(9600);
  initProperties();  // Asegúrate de que thingProperties.h está bien incluido

  // Configurar la conexión a IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  CARRIER_CASE = true;  // Activa el uso del estuche del MKR IoT Carrier
  carrier.begin();      // Inicializa el carrier
  
  pinMode(externalLedPin, OUTPUT);  // Definir el pin del LED externo como salida
  
  setDebugMessageLevel(4);   // Obtener información y errores de la nube
  ArduinoCloud.printDebugInfo();
  
  while (!ArduinoCloud.connected()) {
    ArduinoCloud.update();
    carrier.display.setTextSize(3);
    carrier.display.setCursor(20, 70);
    carrier.display.println("Waiting For");
    carrier.display.setCursor(5, 110);
    carrier.display.println("Connection...");
    delay(500);
  }
}

void loop() {
  ArduinoCloud.update();

  if (carrier.Light.colorAvailable()) {
    int none; // Variable temporal
    carrier.Light.readColor(none, none, none, luz);
  }

  temperatura = carrier.Env.readTemperature();
  humedad = carrier.Env.readHumidity();

  int rawMoistValue = analogRead(moistPin);
  humedadValor = map(rawMoistValue, 0, 1023, 100, 0);
}

void onHumedadChange() {
  Serial.print("Humedad changed to: ");
  Serial.println(humedad);
}

void onTemperaturaChange() {
  Serial.print("Temperatura changed to: ");
  Serial.println(temperatura);
}

void onHumedadValorChange() {
  Serial.print("HumedadValor changed to: ");
  Serial.println(humedadValor);
}

void onLuzChange() {
  Serial.print("Luz changed to: ");
  Serial.println(luz);
}

void onRgbColorChange() {
  uint8_t r, g, b;
  rgbColor.getValue().getRGB(r, g, b);
  if (rgbColor.getSwitch()) {
    carrier.leds.fill(carrier.leds.Color(g, r, b), 0, 5);
    carrier.leds.show();
  } else {
    carrier.leds.fill(0, 0, 5);
    carrier.leds.show();
  }
}

void onUpdateDisplayChange() {
  if (!updateDisplay) return;
  
  carrier.display.fillScreen(ST77XX_WHITE);
  carrier.display.setTextColor(ST77XX_RED);
  carrier.display.setTextSize(2);

  carrier.display.setCursor(20, 30);
  carrier.display.print("Temperatura: ");
  carrier.display.print(temperatura);
  carrier.display.print(" C");

  carrier.display.setCursor(20, 50);
  carrier.display.print("Humedad: ");
  carrier.display.print(humedad);
  carrier.display.print(" %");

  carrier.display.setTextColor(ST77XX_ORANGE);
  carrier.display.setCursor(20, 70);
  carrier.display.print("Luz: ");
  carrier.display.print(luz);

  carrier.display.setTextColor(ST77XX_BLUE);
  carrier.display.setCursor(20, 90);
  carrier.display.print("HumedadValor: ");
  carrier.display.print(humedadValor);
  carrier.display.print(" %");

  carrier.display.setTextColor(ST77XX_BLUE);
  carrier.display.setCursor(20, 120);
  carrier.display.print("R1: ");
  carrier.display.print(relayState1);

  carrier.display.print("R2: ");
  carrier.display.print(relayState2);

  updateDisplay = false;
}

void onRele1Change() {
  if (rele_1) {
    carrier.Relay1.open();
    relayState1 = "ON";
    digitalWrite(externalLedPin, HIGH); 
  } else {
    carrier.Relay1.close();
    relayState1 = "OFF";
    digitalWrite(externalLedPin, LOW); 
  }
}

void onRele2Change() {
  if (rele_2) {
    carrier.Relay2.open();
    relayState2 = "ON";
  } else {
    carrier.Relay2.close();
    relayState2 = "OFF";
  }
}


```

<div style="border: 2px solid black; padding: 10px; display: inline-block;">
    <img src="https://i.postimg.cc/s2XLT7sP/Resultado.jpg" alt="Resultado" style="max-width: 100%;">
</div>


## 5). CONCLUSIONES

## 6). REFERENCIAS BIBLIOGRÁFICAS
[1] Alvear-Puertas, V., Rosero-Montalvo, P., Peluffo-Ordóñez, D., & Pijal-Rojas, J. (2017). Internet de las Cosas y Visión Artificial, Funcionamiento y Aplicaciones: Revisión de Literatura. Enfoque UTE, 8(Supl. 1), 244-256. https://doi.org/10.29019/enfoqueute.v8n1.121





