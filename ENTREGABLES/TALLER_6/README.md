<p align="left">
  <img src="https://semanadelcannabis.cayetano.edu.pe/assets/img/logo-upch.png" width="250">
 
</p>


# ENTREGABLE 05: Mecánica
ACTIVIDAD A REALIZAR: Realizar una simulación de esfuerzos mecánicos (Estáticos) a al menos un componente de su estructura. Si no cuenta con
componentes mecánicos, realizar el ejemplo del video :
https://youtu.be/4bkl783NxEA?si=B67MQfUBpHeHVxBx

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
* Luis

### 1) INTRODUCCIÓN:
El presente informe detalla la simulación de esfuerzos mecánicos (estáticos) en un componente estructural utilizando el software SimScale. La simulación fue realizada para analizar el comportamiento mecánico del componente bajo una carga estática, aplicando el material PET (tereftalato de polietileno) en lugar de los materiales metálicos convencionales, como el acero. PET es un polímero ampliamente utilizado en la industria debido a su bajo peso, buena resistencia mecánica y propiedades químicas. Esta simulación tiene como objetivo evaluar la distribución de los esfuerzos y los desplazamientos generados en el componente, identificando áreas críticas donde se concentran mayores tensiones, lo cual es crucial para la mejora del diseño estructural. Se siguieron los pasos indicados en el video de referencia, adaptando el modelo al material PET, lo que permitirá comprender cómo los materiales plásticos se comportan bajo cargas estáticas en estructuras.

### 2) METODOLOGÍA:
La simulación de esfuerzos estáticos permite evaluar el comportamiento de los materiales y componentes cuando están sometidos a cargas que varían lentamente con el tiempo hasta alcanzar un estado de equilibrio. En este tipo de análisis, se asume que la estructura no experimenta aceleraciones ni fluctuaciones dinámicas, lo que permite estudiar los esfuerzos y deformaciones en un entorno controlado y estacionario.

Análisis de Esfuerzos: Se basa en los principios de la mecánica de sólidos, donde se estudia la relación entre las fuerzas aplicadas, las reacciones internas (esfuerzos) y las deformaciones resultantes. El criterio de Von Mises se emplea para determinar la distribución de esfuerzos y evaluar si un material dúctil, como el PET, alcanzará su límite de elasticidad o fallará bajo la carga aplicada. El PET es un material polimérico caracterizado por su capacidad de deformarse antes de romperse, lo que lo hace ideal para aplicaciones que requieren materiales resistentes y flexibles.

Simulación por Elementos Finitos (FEM): La técnica de elementos finitos descompone un modelo complejo en pequeñas subregiones llamadas elementos, permitiendo calcular los esfuerzos, deformaciones y desplazamientos en cada uno de ellos. El software SimScale permite realizar este análisis FEM de manera eficiente, proporcionando resultados visuales que muestran la concentración de esfuerzos y deformaciones dentro del modelo estructural.

## 3) METODOLIGÍA DE PASOS: 

Metodología (Pasos Seguidos)

3.1)Selección del Componente: Se utilizó el mismo modelo estructural propuesto en el video tutorial (soporte o bracket), que fue importado a SimScale para realizar la simulación de esfuerzos estáticos.

link del onshape realizado: https://cad.onshape.com/documents/b70fefb4e2a77fcdcdc02574/w/8184c593fc84d5693a1ad904/e/ce82a6d15d1231326a5cc8a7

[![Whats-App-Image-2024-10-05-at-2-22-01-PM.jpg](https://i.postimg.cc/XqpVSZD3/Whats-App-Image-2024-10-05-at-2-22-01-PM.jpg)](https://postimg.cc/N2vhR0cP)

3.2)Definición del Material: En lugar del material metálico sugerido en el video (acero), se seleccionó PET como material principal para la simulación. Las propiedades del PET, como el módulo de elasticidad, coeficiente de Poisson y límite de fluencia, fueron asignadas de acuerdo con valores estándares tomados de fuentes confiables.

[![Whats-App-Image-2024-10-05-at-2-27-38-PM.jpg](https://i.postimg.cc/XNHfwTfy/Whats-App-Image-2024-10-05-at-2-27-38-PM.jpg)](https://postimg.cc/yWR3KprV)

3.3)Condiciones de Contorno: Se definieron las restricciones y cargas en el componente. Uno de los extremos del soporte fue completamente restringido (fijación), mientras que en el otro extremo se aplicó una carga estática puntual de acuerdo con los parámetros establecidos en el video tutorial.

[![Whats-App-Image-2024-10-05-at-2-37-42-PM.jpg](https://i.postimg.cc/2y0gmmKD/Whats-App-Image-2024-10-05-at-2-37-42-PM.jpg)](https://postimg.cc/RJngLrms)

3.4)Generación de la Malla: Se realizó el mallado del modelo utilizando una malla de tipo tetraédrico, con un refinamiento en las zonas de interés, como los puntos de aplicación de la carga y las áreas cercanas a las restricciones. Se optó por una malla más densa para garantizar una mayor precisión en los resultados.
[![Whats-App-Image-2024-10-05-at-2-37-42-PM.jpg](https://i.postimg.cc/2y0gmmKD/Whats-App-Image-2024-10-05-at-2-37-42-PM.jpg)](https://postimg.cc/RJngLrms)

Ejecución de la Simulación: Se ejecutó la simulación estática en SimScale, lo que permitió observar la distribución de esfuerzos y desplazamientos a lo largo del componente, nuestro modelo es de 1.462MPa. Los resultados mostraron una concentración de esfuerzos en las zonas cercanas a la aplicación de la carga, con valores máximos de esfuerzo von Mises en áreas específicas que se identificaron para un análisis posterior.
[![Whats-App-Image-2024-10-05-at-2-53-18-PM-1.jpg](https://i.postimg.cc/66hh3M5y/Whats-App-Image-2024-10-05-at-2-53-18-PM-1.jpg)](https://postimg.cc/PNPDVzDj)

Post-procesamiento: Finalmente, se analizaron los resultados obtenidos. El mapa de esfuerzos von Mises mostró que, si bien hubo deformación en el material PET, este no superó el límite elástico, lo que indica que el componente bajo las condiciones simuladas no fallaría estructuralmente. Además, se generaron gráficos de desplazamiento total para visualizar cómo el componente se deformaba bajo la carga aplicada.
[![Whats-App-Image-2024-10-05-at-3-00-57-PM.jpg](https://i.postimg.cc/jS6q0nh0/Whats-App-Image-2024-10-05-at-3-00-57-PM.jpg)](https://postimg.cc/VJ6PX6TD)





