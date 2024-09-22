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



### 2). MATERIALES UTILIZADOS: 



### 3). CONFIGURACIÓN DEL SISTEMA



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






