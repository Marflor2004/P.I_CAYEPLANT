# "Principios básicos observados y reportados"

### **Características clave de Twilio API:**
- **Mensajería Programable**: Permite enviar y recibir mensajes de forma automatizada.
- **Compatibilidad con WhatsApp**: A través de la API, se pueden enviar mensajes de WhatsApp a los usuarios.
- **Escalabilidad**: Soporta desde pequeñas aplicaciones hasta grandes volúmenes de mensajes.
- **Fácil integración**: Puedes integrarlo en aplicaciones usando varios lenguajes de programación (Python, Java, Node.js, etc.).

### **Flujo de funcionamiento en tu proyecto:**

<div align="center"; style="display: flex; justify-content: space-between;">
  <img src="https://github.com/user-attachments/assets/8a40b06b-98d2-49e6-9764-ecfed6d72423" width="600px"/>
</div>

<p align="center">Figura 01: Diagrama de flujo | Fuente: Creación propia</p>

1. **Twilio API recibe la información** del microcontrolador (ESP32/ATOM MATRIX M5) cuando se detecta un evento (como baja humedad en la planta).
2. **Twilio envía el mensaje** al número de WhatsApp registrado.
3. **El usuario recibe la notificación** en su WhatsApp en tiempo real.

