CIFRAS

La parte de Cifras, implementada por Aurora Casanova García, contiene los 
archivos cifras.cpp, cifras.h y operations.h.

operations.h contiene la definición de un struct con el mismo nombrem struct 
Operations, que contiene un dato tipo int y otro tipo string. El dato int hace 
referencia al valor calculado hasta el momento, y el string a las operaciones 
que hemos hecho para lograrlo. Es un TDA imprescindible para cifras ya que es 
la base para los siguientes algorítmos. También contamos con dos constructores, 
uno con y otro sin parámetros.

En cifras.h encontramos las defeniciones de las funciones utilizadas en 
cifras.cpp y algunas constantes, como son el vector con las cifras iniciales y 
el tamaño del multiset que usaremos para guardar las cifras disponibles.

Las funciones más destacadas dentro de cifras.cpp son Cifras y GeneraOperaciones. 
Cifras es la base, una función recursiva que recorre todas las posibilidades 
hasta encontrar un que de como resultado el número objetivo. GeneraOperaciones 
calcula las soluciones, si es posible, a las operaciones +, -, *, /. Se puede 
observar una comprobación al inicio que evita que se guarden o ejecuten 
operaciones con 0, lo cual es necesario ya que los objetos de Operations se 
inicializan a 0 en el atributo valor.

También tenemos digitsBag, que inicializa un multiset con 6 números aleatorios 
dentro de C para poder trabajar a continuación con ellos. Aunque en un inicio 
elegí un vector, me decante por un multiset debido a que tiene algunas 
propiedades, como el método find, que necesito y facilitan la escritura del 
código.

La función de analizaRespuesta es interpretar un texto, el cual es obtenido del 
jugador, que contiene las operaciones necesarias para lograr el número objetivo. 
Su sintaxsis debe ser igual a la del siguiente ejemplo: 

3+6 8*9

Los números utilizados deben estar en el conjunto proporcionado o haber sido 
creados con estos, no se usar ningúna cifra más de una vez. El programa tiene 
todo esto en cuenta y aborta en caso de detectar alguno de los casos mencionados.

Por último, el main. Este se encarga de llamar a las funciones y comprobar los 
resultados, además de crear al azar el número objetivo entre 100 y 999.
