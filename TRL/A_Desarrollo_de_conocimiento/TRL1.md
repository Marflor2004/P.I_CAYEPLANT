
### **Características clave de Twilio API:**
- **Mensajería Programable**: Permite enviar y recibir mensajes de forma automatizada.
- **Compatibilidad con WhatsApp**: A través de la API, se pueden enviar mensajes de WhatsApp a los usuarios.
- **Escalabilidad**: Soporta desde pequeñas aplicaciones hasta grandes volúmenes de mensajes.
- **Fácil integración**: Puedes integrarlo en aplicaciones usando varios lenguajes de programación (Python, Java, Node.js, etc.).

### **Flujo de funcionamiento en tu proyecto:**
1. **Twilio API recibe la información** del microcontrolador (ESP32/ATOM MATRIX M5) cuando se detecta un evento (como baja humedad en la planta).
2. **Twilio envía el mensaje** al número de WhatsApp registrado.
3. **El usuario recibe la notificación** en su WhatsApp en tiempo real.

