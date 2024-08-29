<p align="left">
  <img src="https://semanadelcannabis.cayetano.edu.pe/assets/img/logo-upch.png" width="250">
 
</p>

# **"Entregable 01: Predicción de NO₂ en el Condado de Alameda, California: Aplicación de regresión lineal con datos de 2022-2023"**

**Integrantes:**

- Flores Mescco Fiorella Ingrid
- Guitierrez Mamani Lizzeth Rossmery
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

_ **Columnas de los Datos:** Explica brevemente qué significa cada columna:
_ Date: Fecha en que se tomó la medición.

_ **Source:** Fuente de los datos.

_ **Site ID:** Identificador único del sitio de monitoreo.

_ **POC:** Código de Operación del Parámetro, un identificador único para el método de monitoreo utilizado en un sitio específico.

_ **Daily Max 1-hour NO2 Concentration:** Concentración máxima diaria de NO2 (dióxido de nitrógeno) en una hora.

_ **Units:** Unidades de medida de la concentración de NO2, generalmente partes por mil millones (ppb).

_ **Daily AQI Value**: Valor diario del Índice de Calidad del Aire (AQI).

_ **Local Site Name:** Nombre del sitio local donde se tomaron las mediciones.

_ **Daily Obs Count:** Número de observaciones diarias.

_ **Percent Complete:** Porcentaje de los datos completos para ese día.

_ **AQS Parameter Code:** Código del parámetro de calidad del aire en el sistema AQS.

_ **AQS Parameter Description** Descripción del parámetro de calidad del aire.

_ **Method Code**: Código del método utilizado para la medición.

_ **CBSA Code:** Código de la área estadística metropolitana/micropolitana.

_ **CBSA Name**: Nombre de la área estadística metropolitana/micropolitana.

_ *State FIPS Code:** Código FIPS del estado.

_ **State:** Nombre del estado.

_ **County FIPS Code:** Código FIPS del condado.

_ **County:** Nombre del condado.

_ **Site Latitude:** Latitud del sitio de monitoreo.

_ **Site Longitude:** Longitud del sitio de monitoreo.

## **Uniendo data:** ##
Acceder al sitio web de la EPA para descargar los datos de calidad del aire para el condado de Alameda, California, de los años 2022 y 2023. Una ves accedida a dicha informacion se compila la data

## **Exploración del conjunto de datos** ##
El rango de índices (RangeIndex: 683 entries, 0 to 682) proporciona información sobre la cantidad total de filas en tu DataFrame, que es 683.


## **3. Resultados:**

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
