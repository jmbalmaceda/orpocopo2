# orpocopo2

Necesidad de ordenar y documentar, aunque sea minimamente.

*** ./trackerdetect ***

Detector principal, el programa actual que utilizamos.

Actualmente, el detector usa un entrenamiento cascadeClassifier y la clase DetectionBasedTracker. Esto funciona aceptablemente.

Esta preparado para detectar cabezas, cuerpos y manos, pudiendo definir roi de gondola y un eje en donde se habilita la deteccion de mano.

Los perfiles que vayamos construyendo, pueden ser una combinacion de archivos de configuracion ".ini" y diferentes versiones del ejecutable. Por ejemplo, "trackerdetect", "trackerdetect_quilmes" donde ambos usan las mismas rutinas pero contienen modificaciones al codigo para adaptarlo a las necesidades concretas del caso.

Existen otras formas de hacer deteccion y trackeo que pueden ser mucho mejores, pero requieren mayor experimentacion y desarrollo. Los trackers "puros" son mas estables pero tienen el problema de que cuando la figura muta mucho se va perdiendo gradualmente el seguimiento. 

Una solucion podria ser la correccion adaptativa mediante deteccion para "centrar" gradualmente el trackeo hacia el area necesaria. Evaluar la diferencia con "DetectionBasedTracker".

Tambien estoy evaluando el deep learing con un conjunto de herramientas, que convergen en "goturn tracker".

*** ./countsamples ***

Programita para contar la cantidad de samples de un archivo de anotacion.

*** ./TrainingManager ***

Programa asistente que hice en Qt para hacer entrenamientos, version beta. ***

*** rois ***

Programas para hacer recorte de ROI y que genera entradas para los archivos .ini del trackerdetect.

