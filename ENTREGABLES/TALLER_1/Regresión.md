<p align="left">
  <img src="https://semanadelcannabis.cayetano.edu.pe/assets/img/logo-upch.png" width="250">
 
</p>

# **"Entregable 01: Predicción de NO₂ en el Condado de Alameda, California: Aplicación de regresión lineal con datos de 2022-2023"**

**Integrantes:**

- Flores Mescco Fiorella Ingrid
- Guitierrez Mamani Mar Flor
- Quispe Mamani Lizzeth Rossmery 
- Yalli Espinoza Milena Nicol

> **Objetivo:** Implementar y evaluar un modelo de regresión lineal para predecir la concentración diaria máxima de dióxido de nitrógeno (NO₂) en el Condado de Alameda, California, durante los años 2022 y 2023, utilizando como variables predictoras el índice de calidad del aire (AQI) y el tiempo transcurrido desde el inicio del período analizado.

## **1. Introducción:**

<p align="justify">
En la actualidad, la calidad de aire se ha convertido en una preocupación a nivel mundial debido a sus impactos profundos en la salud pública y el medio ambiente. Uno de los contaminantes clave en este contexto es el dióxido de nitrógeno (NO2). Este gas, producido principalmente por la quema de combustibles fósiles en vehículos y plantas industriales, es conocido por sus efectos adversos tanto en la salud humana como en el medio ambiente (1). El NO₂ no solo tiene impactos directos, como la exacerbación de enfermedades respiratorias como el asma, sino que también contribuye a la formación de otros contaminantes peligrosos, como el ozono troposférico y las partículas finas (PM2.5) (2).

<p align="justify">
El Condado de Alameda, en la región de la Bahía de San Francisco, incluye a la ciudad de Alameda, que, con una densidad de aproximadamente 2,600 personas por kilómetro cuadrado, presenta un entorno urbano significativo con una alta concentración de tráfico y actividad industrial (3). Aunque la densidad poblacional de Alameda no es la más alta en el área metropolitana, la combinación de su densidad moderada y las fuentes de emisión de NO₂ hace que sea un área relevante para el monitoreo de la calidad del aire.

<p align="justify">
En este contexto, el presente estudio se centra en el uso de técnicas de aprendizaje automático, específicamente la regresión lineal, para predecir las concentraciones diarias máximas de NO₂ en el Condado de Alameda durante los años 2022 y 2023. El objetivo es evaluar la precisión del modelo predictivo, utilizando como variables el índice de calidad del aire (AQI) y el tiempo. Este análisis no solo pretende contribuir a la comprensión de las tendencias de contaminación en la región, sino también a proporcionar una herramienta útil para la toma de decisiones en la gestión de la calidad del aire.

<div align="center"; style="display: flex; justify-content: space-between;">
  <img src=https://github.com/user-attachments/assets/58c4f557-9cae-4e6f-b0b5-3195177be86d width="600px"/>
</div>

<p align="center">Imagen 01: Una central de carbón en Utah, Estados Unidos, en una imagen de noviembre de 2019 © George Frey / AFP/Archivos</p>

## **2. Metodología:**

<p align="justify">
Los datos se obtuvieron de dos archivos CSV correspondientes a los años 2022 y 2023. Estos datos fueron combinados en un solo DataFrame para facilitar el análisis. Se realizó un preprocesamiento de los datos, que incluyó la conversión de las fechas a un formato numérico ('Time') que representa los días desde la fecha mínima.

<p align="justify">
Para la construcción del modelo, se utilizó regresión lineal, con la concentración máxima diaria de NO₂ como la variable dependiente y el valor del AQI diario y 'Time' como variables independientes. El conjunto de datos se dividió en 80% para entrenamiento y 20% para prueba. Posteriormente, se calcularon las métricas de rendimiento, como el error cuadrático medio (MSE), el error absoluto medio (MAE), el coeficiente de determinación (R²), y la raíz del error cuadrático medio (RMSE), tanto para el conjunto de entrenamiento como para el conjunto de prueba.

### **Descripción de los datos**

A continuación, se muestra una descripción detallanada de cada columna de las tablas.

**Columnas de los Datos:** Explica brevemente qué significa cada columna:
**Date:** Fecha en que se tomó la medición.

**Source:** Fuente de los datos.

**Site ID:** Identificador único del sitio de monitoreo.

**POC:** Código de Operación del Parámetro, un identificador único para el método de monitoreo utilizado en un sitio específico.

**Daily Max 1-hour NO2 Concentration:** Concentración máxima diaria de NO2 (dióxido de nitrógeno) en una hora.

**Units:** Unidades de medida de la concentración de NO2, generalmente partes por mil millones (ppb).

**Daily AQI Value**: Valor diario del Índice de Calidad del Aire (AQI).

**Local Site Name:** Nombre del sitio local donde se tomaron las mediciones.

**Daily Obs Count:** Número de observaciones diarias.

**Percent Complete:** Porcentaje de los datos completos para ese día.

**AQS Parameter Code:** Código del parámetro de calidad del aire en el sistema AQS.

**AQS Parameter Description** Descripción del parámetro de calidad del aire.

**Method Code**: Código del método utilizado para la medición.

**CBSA Code:** Código de la área estadística metropolitana/micropolitana.

**CBSA Name**: Nombre de la área estadística metropolitana/micropolitana.

**State FIPS Code:** Código FIPS del estado.

**State:** Nombre del estado.

**County FIPS Code:** Código FIPS del condado.

**County:** Nombre del condado.

**Site Latitude:** Latitud del sitio de monitoreo.

**Site Longitude:** Longitud del sitio de monitoreo.

---

#### 1. **Unión de Datos**

Se accedió al sitio web de la Agencia de Protección Ambiental de los Estados Unidos (EPA) para descargar los datos de calidad del aire correspondientes al condado de Alameda, California, para los años 2022 y 2023. Los datos fueron extraídos en formato CSV desde los enlaces proporcionados por la EPA. Una vez descargados, se unieron ambos conjuntos de datos en un único DataFrame utilizando la función `pd.concat()` de la biblioteca pandas en Python. Esta etapa consolidó la información para un análisis integral y continuo.

```python
import pandas as pd

# Cargar los datos de los años 2022 y 2023
data2022 = pd.read_csv("https://raw.githubusercontent.com/Marflor2004/CrackDetect/main/ENTREGABLES/TALLER_1/California_data2022.csv")
data2023 = pd.read_csv("https://raw.githubusercontent.com/Marflor2004/CrackDetect/main/ENTREGABLES/TALLER_1/California_data2023.csv")

# Unir ambos DataFrames
data_df = pd.concat([data2022, data2023], ignore_index=True)
```

#### 2. **Exploración del Conjunto de Datos**

Se realizó una inspección inicial del DataFrame combinado para comprender la estructura y el contenido de los datos. El DataFrame resultante incluye un rango de índices de 683 entradas, que representa el total de filas en el conjunto de datos. Se utilizó el método `info()` para obtener una visión general de las columnas disponibles y el número de entradas.

```python
data_df.info()
```

#### 3. **Visualización de Relaciones en los Datos**

Se creó un conjunto de aproximadamente 169 gráficos utilizando la función `sns.pairplot()` para explorar las relaciones entre las variables. Esta visualización ayudó a identificar correlaciones entre el Índice de Calidad del Aire (AQI VALUE) y la concentración de dióxido de nitrógeno (NO₂). Se observó una relación directa entre el AQI VALUE y la concentración de NO₂, lo que indica que el AQI VALUE es una variable relevante para la modelización. La variable "Date" también fue incluida para capturar las tendencias temporales.

```python
import seaborn as sns
import matplotlib.pyplot as plt

# Visualización de relaciones
sns.pairplot(data_df)
plt.show()
```

#### 4. **Separación entre Entrenamiento y Prueba**

Se procedió a dividir el conjunto de datos en conjuntos de entrenamiento y prueba. El DataFrame se particionó en un 80% para entrenamiento y un 20% para prueba utilizando la proporción calculada. Esta separación permite evaluar el desempeño del modelo en datos no vistos durante el entrenamiento.

```python
# Separar el DataFrame en conjuntos de entrenamiento y prueba
indice_particion = int(0.8 * len(data_df))
train_df = data_df[:indice_particion]
test_df = data_df[indice_particion:]
```

#### 5. **Extracción y Preparación de Características**

Se seleccionaron las columnas clave del DataFrame de entrenamiento, que incluyen 'Date', 'Daily AQI Value' y 'Daily Max 1-hour NO2 Concentration'. La columna 'Date' se convirtió al formato datetime utilizando `pd.to_datetime()` para facilitar el manejo de fechas. Se creó una nueva columna 'Time' que calcula el número de días desde la fecha mínima, transformando las fechas en una variable numérica útil para el análisis de regresión. Finalmente, se reorganizó el DataFrame para incluir las columnas necesarias en el orden adecuado.

```python
# Convertir 'Date' al formato datetime
train_df['Date'] = pd.to_datetime(train_df['Date'])

# Crear la columna 'Time'
train_df['Time'] = (train_df['Date'] - train_df['Date'].min()).dt.days

# Seleccionar las columnas necesarias
train_df = train_df[['Date', 'Daily AQI Value', 'Daily Max 1-hour NO2 Concentration', 'Time']]
```

---



## **3. Resultados:**

<div align="center"; style="display: flex; justify-content: space-between;">
  <img src=https://github.com/user-attachments/assets/71222cff-5b26-4a99-9f21-8c569ecafd70 width="600px"/>
</div>

<p align="center">Gráfico 01: Representación de la predicción NO2 2022-2023

<p align="justify">
El modelo de regresión lineal mostró los siguientes resultados en el conjunto de prueba:

Mean Squared Error (MSE): 0.1588

Mean Absolute Error (MAE): 0.3275

R-squared (R²): 0.9976

Root Mean Squared Error (RMSE): 0.3985

La gráfica generada comparó las concentraciones de NO₂ reales y predichas a lo largo del tiempo, mostrando una alta correspondencia entre los valores observados y predichos, lo que indica que el modelo pudo capturar de manera precisa la variación en las concentraciones de NO₂.

## **4. Discución:**

<p align="justify">
Los resultados indican que la regresión lineal es una herramienta efectiva para predecir las concentraciones de NO₂ a partir de los valores del AQI y del tiempo. El valor de R² cercano a 1 sugiere que el modelo explica casi toda la variabilidad en los datos. Sin embargo, el modelo podría beneficiarse de la inclusión de otras variables, como datos meteorológicos o el tráfico vehicular, para mejorar la precisión de las predicciones. Se recomienda también explorar modelos de aprendizaje automático más complejos, como Random Forest o Redes Neuronales, para una comparación más detallada.
