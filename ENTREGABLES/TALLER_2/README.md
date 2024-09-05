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

<p align="justify">
En la actualidad, las redes neuronales convolucionales (CNN) se han convertido en una herramienta fundamental en el campo de la visión por computadora, siendo utilizadas ampliamente para la clasificación y reconocimiento de objetos en imágenes. Este entregable tiene como objetivo aplicar y optimizar una CNN para la clasificación de imágenes, específicamente para diferenciar entre dos tipos de flores: tulipanes y rosas, además de explorar la distinción entre perros y gatos. Utilizando bibliotecas modernas como TensorFlow y Keras en Python, este trabajo busca comprender cómo las CNNs son capaces de identificar características visuales clave que permiten distinguir entre diferentes categorías, optimizando la arquitectura de las redes para mejorar la precisión en la clasificación de estos objetos [1].

## **II. Metodología del codigo de perros y gatos:**

#### **1. Descarga y preparación del conjunto de datos**

Para entrenar el modelo de clasificación de perros y gatos, se utilizó el conjunto de datos "Cat and Dog Small" disponible en **Kaggle**. Este contiene imágenes de gatos y perros distribuidas en carpetas de entrenamiento, validación y prueba. Los pasos detallados para la descarga y organización del conjunto de datos son:

```python
!pip install kaggle
from google.colab import files
files.upload()

# Configuración de Kaggle API para descargar los datos
!mkdir ~/.kaggle
!cp kaggle.json ~/.kaggle/
!chmod 600 ~/.kaggle/kaggle.json
!kaggle datasets download -d hongweicao/catanddogsmall
!unzip catanddogsmall.zip -d cats_and_dogs_small
```

En este paso, las imágenes fueron descargadas y organizadas en carpetas específicas, lo que permite que el modelo de red neuronal acceda fácilmente a los datos durante el proceso de entrenamiento y validación.

#### **2. Instalación de tensorFlow y verificación de entorno**

La biblioteca **TensorFlow**, junto con **Keras**, se utilizó para construir la CNN. Se verificó la presencia de una **GPU** para mejorar el rendimiento en el entrenamiento.

```python
!pip install --upgrade tensorflow

import tensorflow as tf
print("Num GPUs Available: ", len(tf.config.list_physical_devices('GPU')))
```

#### **3. Creación del modelo de red neuronal convolucional**

Se construyó una CNN con varias capas convolucionales y de agrupamiento, seguidas de capas densas totalmente conectadas para la clasificación binaria (perro vs. gato). El modelo utiliza la función de activación **ReLU** y el optimizador **Adam** para mejorar la precisión del modelo.

```python
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense, Dropout

model = Sequential([
    Conv2D(32, (3, 3), activation='relu', input_shape=(150, 150, 3)),
    MaxPooling2D(2, 2),
    Conv2D(64, (3, 3), activation='relu'),
    MaxPooling2D(2, 2),
    Conv2D(128, (3, 3), activation='relu'),
    MaxPooling2D(2, 2),
    Conv2D(128, (3, 3), activation='relu'),
    MaxPooling2D(2, 2),
    Flatten(),
    Dropout(0.5),
    Dense(512, activation='relu'),
    Dense(1, activation='sigmoid')
])

model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])
```

El modelo tiene cuatro capas convolucionales, seguidas de capas de agrupamiento para reducir la dimensionalidad. Se usa la función **sigmoide** en la capa de salida para clasificar las imágenes en una de dos categorías.

#### **4. Preparación de los datos y generación de imágenes**

Se utilizaron generadores de datos de **Keras** para preparar los conjuntos de entrenamiento y validación, aplicando **escalado de imágenes**.

```python
from tensorflow.keras.preprocessing.image import ImageDataGenerator

train_datagen = ImageDataGenerator(rescale=1./255)
validation_datagen = ImageDataGenerator(rescale=1./255)

train_generator = train_datagen.flow_from_directory(
    'cats_and_dogs_small/train',
    target_size=(150, 150),
    batch_size=20,
    class_mode='binary'
)

validation_generator = validation_datagen.flow_from_directory(
    'cats_and_dogs_small/validation',
    target_size=(150, 150),
    batch_size=20,
    class_mode='binary'
)
```

#### **5. Entrenamiento del modelo**

El modelo fue entrenado utilizando el conjunto de datos procesado, con un número fijo de épocas y pasos por época.

```python
history = model.fit(
    train_generator,
    steps_per_epoch=100,
    epochs=30,
    validation_data=validation_generator,
    validation_steps=50
)
```

#### **6. Evaluación del modelo**

Se utilizó un gráfico para visualizar el progreso del entrenamiento y la precisión del modelo a lo largo de las épocas.

```python
def plot_compare(history):
    acc = history.history['accuracy']
    val_acc = history.history['val_accuracy']
    loss = history.history['loss']
    val_loss = history.history['val_loss']

    plt.figure(figsize=(12, 6))
    plt.subplot(1, 2, 1)
    plt.plot(acc, label='Training Accuracy')
    plt.plot(val_acc, label='Validation Accuracy')
    plt.title('Training and Validation Accuracy')
    plt.legend()

    plt.subplot(1, 2, 2)
    plt.plot(loss, label='Training Loss')
    plt.plot(val_loss, label='Validation Loss')
    plt.title('Training and Validation Loss')
    plt.legend()
    plt.show()

plot_compare(history)
```

---

## **III. Metodología del codigo de rosas vs tulipanes:**

#### **1. Descarga y preparación del conjunto de datos**

Para la clasificación de imágenes de **rosas** y **tulipanes**, se utilizó un conjunto de datos específico, que fue previamente cargado y organizado en carpetas. El proceso de descarga y organización de los datos es similar al usado para los perros y gatos, pero enfocado en estas dos categorías de flores.

```python
!pip install kaggle
from google.colab import files
files.upload()

# Configuración de la API de Kaggle para descargar los datos de flores
!mkdir ~/.kaggle
!cp kaggle.json ~/.kaggle/
!chmod 600 ~/.kaggle/kaggle.json
!kaggle datasets download -d user/flowersdataset
!unzip flowersdataset.zip -d roses_and_tulips
```

Este conjunto de datos contiene imágenes organizadas en dos carpetas: una para las **rosas** y otra para los **tulipanes**, divididas en conjuntos de entrenamiento, validación y prueba.

#### **2. Instalación de TensorFlow y verificación de entorno**

Se utilizó **TensorFlow** y **Keras** para crear la arquitectura de la red neuronal convolucional (CNN), verificando la disponibilidad de **GPU** para optimizar el entrenamiento.

```python
!pip install --upgrade tensorflow

import tensorflow as tf
print("Num GPUs Available: ", len(tf.config.list_physical_devices('GPU')))
```

#### **3. Creación del modelo de red neuronal convolucional (CNN)**

El modelo de CNN para la clasificación de **rosas** y **tulipanes** se diseñó con varias capas convolucionales y de agrupamiento, seguidas de capas densas completamente conectadas. La arquitectura se diseñó específicamente para detectar características visuales importantes en las imágenes de flores.

```python
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense, Dropout

model = Sequential([
    Conv2D(32, (3, 3), activation='relu', input_shape=(150, 150, 3)),
    MaxPooling2D(2, 2),
    Conv2D(64, (3, 3), activation='relu'),
    MaxPooling2D(2, 2),
    Conv2D(128, (3, 3), activation='relu'),
    MaxPooling2D(2, 2),
    Conv2D(128, (3, 3), activation='relu'),
    MaxPooling2D(2, 2),
    Flatten(),
    Dropout(0.5),
    Dense(512, activation='relu'),
    Dense(1, activation='sigmoid')
])

model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])
```

La arquitectura incluye cuatro capas convolucionales que procesan las imágenes para identificar características clave de **rosas** y **tulipanes**, tales como patrones de pétalos, color y textura.

#### **4. Preparación de los datos y generación de imágenes**

Se utilizó el **ImageDataGenerator** de Keras para escalar las imágenes y generar lotes para el entrenamiento y la validación. La preparación incluyó una **normalización** de los valores de píxeles para mejorar el rendimiento del modelo.

```python
from tensorflow.keras.preprocessing.image import ImageDataGenerator

train_datagen = ImageDataGenerator(rescale=1./255)
validation_datagen = ImageDataGenerator(rescale=1./255)

train_generator = train_datagen.flow_from_directory(
    'roses_and_tulips/train',
    target_size=(150, 150),
    batch_size=20,
    class_mode='binary'
)

validation_generator = validation_datagen.flow_from_directory(
    'roses_and_tulips/validation',
    target_size=(150, 150),
    batch_size=20,
    class_mode='binary'
)
```

#### **5. Entrenamiento del modelo**

El modelo fue entrenado con un conjunto de datos de **rosas** y **tulipanes** utilizando un enfoque de clasificación binaria. Se ajustó el modelo durante varias épocas para maximizar su precisión.

```python
history = model.fit(
    train_generator,
    steps_per_epoch=100,
    epochs=30,
    validation_data=validation_generator,
    validation_steps=50
)
```

#### **6. Evaluación del modelo**

Se creó un gráfico para visualizar el rendimiento del modelo en términos de precisión y pérdida durante el entrenamiento y la validación.

```python
def plot_compare(history):
    acc = history.history['accuracy']
    val_acc = history.history['val_accuracy']
    loss = history.history['loss']
    val_loss = history.history['val_loss']

    plt.figure(figsize=(12, 6))
    plt.subplot(1, 2, 1)
    plt.plot(acc, label='Training Accuracy')
    plt.plot(val_acc, label='Validation Accuracy')
    plt.title('Training and Validation Accuracy')
    plt.legend()

    plt.subplot(1, 2, 2)
    plt.plot(loss, label='Training Loss')
    plt.plot(val_loss, label='Validation Loss')
    plt.title('Training and Validation Loss')
    plt.legend()
    plt.show()

plot_compare(history)
```

Este análisis permite observar si el modelo está **sobreajustándose** o si la precisión continúa mejorando con el tiempo.


## **IV. Referencias:**

- [1] A. T. Martín, "Investigación de Detección de Bordes a Radiografías con Deep Learning," Trabajo Fin de Grado, Universidad Politécnica de Madrid, Escuela Técnica Superior de Ingenieros Informáticos, Madrid, mayo 2023. [Enlace: https://oa.upm.es/74981/1/TFG_ALBERTO_TOMAS_MARTIN.pdf]
