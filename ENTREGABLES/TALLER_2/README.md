<p align="center">
  <img src="https://semanadelcannabis.cayetano.edu.pe/assets/img/logo-upch.png" width="250">
 
</p>

# "Entregable 02: Redes Neuronales Convolucionales en Python: Clasificación de imágenes con perros vs. gatos y tulipanes vs. rosas"

**Integrantes:**

- Flores Mescco Fiorella Ingrid
- Guitierrez Huaman Mar Flor
- Quispe Mamani Lizzeth Rossmery 
- Yalli Espinoza Milena Nicol

> **Objetivo General**
El objetivo principal de esta actividad es desarrollar y optimizar una red neuronal convolucional (CNN) para la clasificación de imágenes de rosas y tulipanes, utilizando herramientas modernas de Python y librerías como TensorFlow y Keras. Este proceso es crucial para mejorar las tecnologías de visión por computadora aplicadas al reconocimiento de objetos específicos. El enfoque incluye comprender el funcionamiento de las CNNs para analizar cómo estas redes pueden clasificar imágenes de flores, prestando especial atención a los detalles visuales que diferencian cada categoría, y optimizar los métodos, mejorando las capas convolucionales y densas para alcanzar una mayor precisión en la clasificación de imágenes.

## **I. Introducción:**

En la actualidad, las redes neuronales convolucionales (CNN) se han convertido en una herramienta fundamental en el campo de la visión por computadora, siendo utilizadas ampliamente para la clasificación y reconocimiento de objetos en imágenes. Este entregable tiene como objetivo aplicar y optimizar una CNN para la clasificación de imágenes, específicamente para diferenciar entre dos tipos de flores: tulipanes y rosas, además de explorar la distinción entre perros y gatos. Utilizando bibliotecas modernas como TensorFlow y Keras en Python, este trabajo busca comprender cómo las CNNs son capaces de identificar características visuales clave que permiten distinguir entre diferentes categorías, optimizando la arquitectura de las redes para mejorar la precisión en la clasificación de estos objetos.

## **II. Metodología del codigo de perros y gatos:**

## **III. Metodología del codigo de rosas vs tulipanes:**

#### 1. **Importación de Bibliotecas y Configuración del Entorno**

En esta sección, importamos todas las bibliotecas necesarias para la manipulación de datos, visualización y construcción de nuestro modelo CNN:

- **`warnings`**: Suprimimos advertencias innecesarias para que el código sea más limpio.
- **`numpy` y `pandas`**: Manipulamos y organizamos los datos con estas bibliotecas.
- **`matplotlib` y `seaborn`**: Las usamos para visualizar gráficos de manera clara y ordenada.
- **`sklearn`**: Incluimos herramientas para dividir los datos y medir el rendimiento del modelo.
- **`tensorflow` y `keras`**: Son esenciales para construir y entrenar el modelo de red neuronal convolucional.

#### 2. **Preparación de Datos**

Aquí preparamos y etiquetamos las imágenes que usaremos para entrenar el modelo:

- **Función `make_train_data`**: Cargamos las imágenes desde el directorio, redimensionándolas a 150x150 píxeles y asignando etiquetas (por ejemplo, "Tulip" o "Rose").
  
- **Visualización de imágenes**: Mostramos algunas imágenes aleatorias con sus etiquetas para asegurarnos de que la asignación es correcta.

- **Codificación de etiquetas**: Convertimos las etiquetas de texto en valores numéricos y las transformamos en una representación binaria para el modelo.

#### 3. **División del Conjunto de Datos**

Usamos `train_test_split` para dividir los datos en entrenamiento (75%) y prueba (25%). Esto nos permite evaluar el rendimiento del modelo con datos no vistos durante el entrenamiento.

#### 4. **Construcción del Modelo CNN**

Creamos nuestra red neuronal convolucional con las siguientes capas:

- **Capas convolucionales (`Conv2D`)**: Detectan características importantes de las imágenes, como bordes y texturas.
- **Capas de pooling (`MaxPooling2D`)**: Reducen el tamaño de los datos manteniendo la información más relevante, lo que ayuda a disminuir la complejidad.
- **Capa densa**: Después de "aplanar" los datos, utilizamos una capa completamente conectada que realiza la clasificación final.

#### 5. **Prevención del Sobreajuste**

Para evitar que el modelo se "memorice" el conjunto de entrenamiento y no generalice bien:

- Usamos **aumento de datos** con `ImageDataGenerator`, que aplica transformaciones aleatorias a las imágenes (rotaciones, desplazamientos, zooms) para crear variaciones que el modelo no ha visto.
- Implementamos **ReduceLROnPlateau**, que ajusta la tasa de aprendizaje si el modelo deja de mejorar, lo que permite un ajuste más preciso.

#### 6. **Entrenamiento del Modelo**

Compilamos el modelo con el optimizador `adam` y la función de pérdida `categorical_crossentropy`, que es ideal para la clasificación de múltiples categorías. Entrenamos el modelo durante 50 épocas con los datos de entrenamiento.

#### 7. **Evaluación del Modelo**

Finalmente, evaluamos el rendimiento del modelo mediante gráficos:

- **Gráfico de pérdida**: Nos muestra cómo evoluciona la pérdida del modelo tanto en los datos de entrenamiento como en los de validación a lo largo del tiempo.
- **Gráfico de precisión**: Compara la precisión en los conjuntos de entrenamiento y validación, ayudándonos a visualizar si el modelo está mejorando.


Este enfoque estructurado permite que cada sección sea comprensible y didáctica, facilitando la interpretación de los resultados y su ajuste.
## *La actividad consistió en dos tareas principales:*

### Modificación y Corrección del Código de Imágenes de Perros y Gatos:

### *Introducción y Revisión del Código Inicial:*

Se revisó y analizó el código base de un modelo de CNN preexistente para entender su estructura y funcionalidad.
### *Ejecución del Código Base:*
Se ejecutó el código para identificar problemas y entender las áreas de mejora.
### *Implementación de Mejoras:*
Se realizaron correcciones y mejoras en el código para actualizarlo con nuevas herramientas y optimizar su rendimiento.
## Aplicación del Modelo a la Clasificación de Rosas y Tulipanes:
### *Visualización de Imágenes:*
Se ajustó el código para permitir la visualización de todas las imágenes generadas por los filtros convolucionales, ahora aplicadas a las imágenes de rosas y tulipanes.
