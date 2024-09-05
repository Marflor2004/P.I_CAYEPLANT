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

### 1. **Obtención de datos**

1. **Clonación del repositorio**: 
   Se clonó el repositorio de GitHub que contiene el conjunto de datos de imágenes de rosas y tulipanes usando el siguiente comando:
   ```python
   !git clone https://github.com/Marflor2004/Tulipan-RoseS.git
   ```
   Posteriormente, se cambió el directorio de trabajo a la carpeta que contiene las imágenes:
   ```python
   import os
   os.chdir('Tulipan-Roses/flowers')
   ```

2. **Exploración de datos**: 
   Se verificó la estructura del directorio para asegurar que las imágenes estaban correctamente organizadas:
   ```python
   print(os.listdir("../flowers"))
   ```

### 2. **Preprocesamiento de imágenes**

1. **Definición de parámetros**: 
   Se estableció el tamaño de las imágenes de entrada como 150x150 píxeles y se definieron las rutas a los directorios que contienen las imágenes de rosas y tulipanes:
   ```python
   IMG_SIZE = 150
   FLOWER_ROSE_DIR = "../flowers/rose"
   FLOWER_TULIP_DIR = "../flowers/tulip"
   ```

2. **Carga y etiquetado de imágenes**:
   Se implementaron funciones para cargar y etiquetar las imágenes. Las imágenes fueron redimensionadas a 150x150 píxeles y almacenadas en listas:
   ```python
   def assign_label(img, flower_type):
       return flower_type

   def make_train_data(flower_type, DIR):
       for img in tqdm(os.listdir(DIR)):
           label = assign_label(img, flower_type)
           path = os.path.join(DIR, img)
           img = cv2.imread(path, cv2.IMREAD_COLOR)
           img = cv2.resize(img, (IMG_SIZE, IMG_SIZE))
           X.append(np.array(img))
           Z.append(str(label))
   ```

   Se procesaron las imágenes de ambos tipos (rosas y tulipanes) y se visualizó una muestra para verificar la correcta carga de datos:
   ```python
   make_train_data('Tulip', FLOWER_TULIP_DIR)
   make_train_data('Rose', FLOWER_ROSE_DIR)

   # Visualización de imágenes
   fig, ax = plt.subplots(5, 2, figsize=(15, 15))
   for i in range(5):
       for j in range(2):
           l = np.random.randint(0, len(Z))
           ax[i, j].imshow(X[l])
           ax[i, j].set_title('Flower: ' + Z[l])
   plt.tight_layout()
   plt.show()
   ```

3. **Normalización y codificación**:
   Las imágenes fueron normalizadas para que los valores de los píxeles estén en el rango [0, 1]. Las etiquetas se codificaron numéricamente y se transformaron en una representación one-hot:
   ```python
   le = LabelEncoder()
   Y = le.fit_transform(Z)
   Y = to_categorical(Y, 2)
   X = np.array(X)
   X = X / 255.0
   ```

### 3. **División del conjunto de datos**

1. **Separación de datos**:
   Se dividieron los datos en conjuntos de entrenamiento y prueba utilizando una proporción del 75% para entrenamiento y 25% para prueba:
   ```python
   x_train, x_test, y_train, y_test = train_test_split(X, Y, test_size=0.25, random_state=42)
   ```

### 4. **Diseño del modelo de red neuronal convolucional (CNN)**

1. **Arquitectura del modelo**:
   Se construyó un modelo CNN con la siguiente arquitectura:
   - **Capas Convolucionales**: Cuatro capas convolucionales con filtros y tamaños de kernel definidos.
   - **Capas de Max-Pooling**: Reducción dimensional después de cada capa convolucional.
   - **Capas de Flatten y Densas**: Conversión de la salida a una forma unidimensional seguida de capas densas con activación ReLU y una capa final con activación softmax para clasificación:
   ```python
   model = Sequential()
   model.add(Conv2D(filters=32, kernel_size=(5, 5), padding='Same', activation='relu', input_shape=(IMG_SIZE, IMG_SIZE, 3)))
   model.add(MaxPooling2D(pool_size=(2, 2)))
   model.add(Conv2D(filters=64, kernel_size=(3, 3), padding='Same', activation='relu'))
   model.add(MaxPooling2D(pool_size=(2, 2)))
   model.add(Conv2D(filters=96, kernel_size=(3, 3), padding='Same', activation='relu'))
   model.add(MaxPooling2D(pool_size=(2, 2)))
   model.add(Conv2D(filters=96, kernel_size=(3, 3), padding='Same', activation='relu'))
   model.add(MaxPooling2D(pool_size=(2, 2)))
   model.add(Flatten())
   model.add(Dense(512, activation='relu'))
   model.add(Dense(2, activation='softmax'))
   ```

2. **Compilación del modelo**:
   Se utilizó el optimizador Adam y la función de pérdida categorical_crossentropy. También se configuró una reducción de tasa de aprendizaje:
   ```python
   model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])
   ```

3. **Prevención de overfitting**:
   Se empleó `ImageDataGenerator` para realizar aumentos de datos que ayudan a mejorar la generalización del modelo:
   ```python
   datagen = ImageDataGenerator(
       rotation_range=10,
       zoom_range=0.1,
       width_shift_range=0.2,
       height_shift_range=0.2,
       horizontal_flip=True,
       vertical_flip=False
   )
   datagen.fit(x_train)
   ```

### 5. **Entrenamiento del modelo**

1. **Configuración de entrenamiento**:
   Se entrenó el modelo durante 50 épocas utilizando el generador de datos y la validación de datos de prueba. Se utilizó el callback `ReduceLROnPlateau` para ajustar la tasa de aprendizaje durante el entrenamiento:
   ```python
   history = model.fit(
       datagen.flow(x_train, y_train, batch_size=128),
       epochs=50,
       validation_data=(x_test, y_test),
       verbose=1,
       steps_per_epoch=x_train.shape[0] // 128,
       callbacks=[red_lr]
   )
   ```

### 6. **Evaluación del modelo**

1. **Visualización del rendimiento**:
   Se generaron gráficos para evaluar la pérdida y precisión del modelo durante el entrenamiento y la validación:
   ```python
   plt.figure(figsize=(12, 6))
   plt.subplot(1, 2, 1)
   plt.plot(history.history['loss'])
   plt.plot(history.history['val_loss'])
   plt.title('Model Loss')
   plt.ylabel('Loss')
   plt.xlabel('Epochs')
   plt.legend(['train', 'test'])

   plt.subplot(1, 2, 2)
   plt.plot(history.history['accuracy'])
   plt.plot(history.history['val_accuracy'])
   plt.title('Accuracy Performance')
   plt.ylabel('Accuracy')
   plt.xlabel('Epochs')
   plt.legend(['train', 'test'])
   plt.show()
   ```

---



## **IV. Referencias:**

- [1] A. T. Martín, "Investigación de Detección de Bordes a Radiografías con Deep Learning," Trabajo Fin de Grado, Universidad Politécnica de Madrid, Escuela Técnica Superior de Ingenieros Informáticos, Madrid, mayo 2023. [Enlace: https://oa.upm.es/74981/1/TFG_ALBERTO_TOMAS_MARTIN.pdf]
