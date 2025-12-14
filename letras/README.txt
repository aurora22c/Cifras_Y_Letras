La parte que he hecho yo, Andrés, se corresponde solo a varios archivos de la
parte de letras, mas concretamente letras.cpp, letters_set y letters_bag.


Comencemos hablando de letters_set. En él encontramos un struct LetterInfo. 
Este contiene la informacion de cada letra, sus repeticiones en partida y la 
puntuación. También encontramos dos constructores, uno sin parámetros y otro 
con parametros. 

Ahora centrándonos en la clase LettersSet, encontramos que
tiene como atributo privado un map. Se ha elegido un map ya que es más cómodo
a la hora de almacenar la letra con su información, podemos tener la clave,
que es la letra y es única, y su valor que es el struct. También resulta más
fácil su busqueda con este TDA. 
Dentro de la clase LettersSet también tenemos definido el iterador normal y el 
constante, para tener las dos posibilades. Estos tienen definidos sus 
constructores y muchas operaciones. No todas de ellas son utilizadas, pero si
se intenta modificar o implementar cosas nuevas, pueden ser de ayuda.

Ahora como métodos de la propia clase, tenemos su destructor, constructor con 
y sin parámetros y el operador >>. Este operador servirá para crear el 
letters_set y para el constructor con parametros, ya que este recibe un 
arhivo.txt, que leerá los datos de ahí. Con la función insert, insertará 
los datos que se extraen en el operador >>. Por último, el método que se 
necesita para una modalidad del juego, el de los puntos, tenemos score, 
que recibe una palabra, en ella encuentra letra por letra en el map y calcula 
los puntos totales de la palabra.



Pasamos a letters_bag. Tenemos como atributo privado un vector. Hemos escogido 
este ya que, para trabajar con él y para almacenar letras, nos parece lo más 
simple y se acomoda a nuestras necesidades. 

En el tema de iteradores, tenemos los mismos que en letters_set. Se ha decidido
implementarlo por el mismo motivo. 

Pasamos a la propia clase LettersBag. Tenemos el destructor, los constructores 
con y sin parametros. En el constructor con parametros, tenemos que un
letters_bag se crea a partir de un letters_set. Es decir, que el vector 
contendrá todas las letras, tantas veces como se repita. Para el juego se 
usará el método de extractLetters. Este método se encarga de almacenar las
letras que se extraen. El que se encarga de extraerlas es extracLetter. 
Este extrae de manera aleatoria tantas letras como pida el jugador, utilizando
la funcion rand, que se inicilizará en letras.cpp.

Por último, encontramos métodos propios de un vector, pero que se han 
hecho para el propio LettersBag.



Terminando con mi parte, tenemos el propio juego de letras. En este encontramos 
una primera parte de comprobación de los datos que se pasan al juego.
Despues de que todo esté correcto, comenzamos con los preparativos del juego. 

Para ello, creamos un diccionario, un letters_set, un letters_bag y un solver y 
los inicializamos para el inicio del juego. También iniciamos el generador de 
números, que es el rand. 

Comenzando en el juego, tenemos al principio para el modo de puntuación,
la muestra por pantalla de todas las letras con su respectiva puntutación. 
Despues se creará un vector con las letras con la que se jugará en cada partida.

Se mostrarán y se le pedirá al jugador que ponga su solución.
Después, se verifica que su solución está dentro del diccionario, y si es así, 
también se comprueba si se puede construir con las letras que se dan.
Dependiendo del modo de juego, se le calcula su puntuación adquiria. 

Luego, se le muestra su puntaje obtenido y las posibles soluciones. 
Para conseguir todas las soluciones, se crea un nuevo vector que llamará al
método getSolutions, perteneciente a solver. Este nos dará las mejores 
soluciones según el modo de juego. Con estas soluciones, se calcula la 
puntuación. 

A continuación, se comparan las puntuaciones obtenidas. Si la del jugador es
la mejor posible, se mostrará como mejor solución la suya, sino la primera
que se muestre por parte del juego.

Al final se le preguntará si quiere volver a jugar con las mismas normas.

