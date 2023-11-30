# Proyecto: Catalogo de peliculas
Este es un proyecto de un catalogo de peliculas donde el usuario puede ver un catalogo de peliculas (ya predeterminadas), puede decidir ordenar este catalogo y si lo desea podra agregar nuevas peliculas y estas se agregaran de manera ordenada. Podra buscar (consultar) si existe o no una pelicula en particular. Como funcion final el usuario podra eliminar todas pelicula del catalogo, y por ende tambien se eliminan del archivo de texto.

## Descripción del avance 1
En este avance el objetivo es que dentro de un programa funcional se puedan organizar los datos almacenados. 
Se debe usar un algoritmo de ordenamiento adecuado al problema (de los vistos en clase) y argumentar porqué es que se eligio ese algoritmo.

Dentro del proyecto se puede observar un algoritmo de ordenamiento usado para ordenar los datos.

## Descripción del avance 2
En este avance de proyecto se va a almacenar los datos, a ordenar los datos y posteriormente a acceder a ellos de manera eficiente.

Esta parte se ve al momento de almacenar los datos en una lista simplemente ligada. En el menu se podra ver que se puede utilizar la opcion ordenar los datos, tambien existe la forma de acceder a ellos (cargar los datos a mi estructura de datos lineal) 

### Cambios sobre el primer avance
1. Cambio de parametros de ordenamiento (genero, director, año) por el usuario: Al momento de leer los datos del archivo de texto, agregar los demas parametros, fue complejo y lo quise mantener simple para poder demostrar la competencia.

## Descripción del avance 3
En este proyecto vas a almacenar los datos, a ordenar los datos y posteriormente a acceder a ellos de manera eficiiente.

### Cambios sobre el segundo avance
1. La implementacion de un algoritmo de ordenamiento. Un merge sort.
2. Una estructura de datos donde se almacenaran los datos, en este caso use una lista simplemente ligada.
3. Un archivo de texto donde hay peliculas, las culaes se pueden cargar a la estructura de datos.
4. La opcion de poder buscar (consultar) si existe un elemento o no en la lista.
5. Una opcion para eliminar todos los elementos de la lista y tambien del archivo de texto.
6. Un mecanismo de escritura del archivo de texto de las peliculas ya que al momento de que el usuario realice la opcion "insertarLista este elemento se agregara al archivo.

## Entrega final
Correcciones sobre la escritura de archivos y mejoras en las funcionalidades

### Cambios sobre el tercer avance avance
1. Mejoramiento en las funciones para arreglar el problema del duplicado de datos

## Instrucciones para compilar el proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance` 

## Instrucciones para ejecutar el proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
El programa requiere un archivo de tipo .txt donde estan almacenados los nombres de las peliculas, el archivo se llama "peliculas.txt". Existe tambien un llamado "datos.txt" que es donde trabajaremos la escritura de los datos, ya que "peliculas.txt" solo nos sirve para cargar los datos y "datos.txt" para visualizarlos

## Descripción de las salidas del avance de proyecto
1. Cuando cargamos las peliculas del archivo a la lista ligada y seleccionamos "mostrar catalogo", obtendremos la lista de peliculas.
2. Cuando seleccionamos ordenar, estas se ordenaran y si seleccionamos "mostrar catalogo", veremos las peliculas ordenadas alfabeticamente de la A-Z.
3. Cuando seleccionemos ingresar pelicula, esta se insertara a la lista y se escribira en el archivo
4. Si deseamos consultar si existe alguna pelicula, solo obtendremos un mensaje de si esta o no, despues de haber tecleado el nombre de la pelicula
5. Si seleccionamos eliminar peliculas, estas se eliminaran de la lista y tambien se borraran del archivo de texto.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Aprendi que aunque la recursividad es una característica fundamental del merge sort, y puede hacer que el código del algoritmo sea más claro y fácil de entender, esta no hace que el algoritmo sea más rápido en términos de tiempo de ejecución. La eficiencia de merge sort se debe principalmente a su estrategia de "dividir y conquistar" y al hecho de que divide la lista en sublistas más pequeñas, las ordena de manera independiente y luego las combina.

Mis argumentos sobre por qué ya considero que ahora ya he desarrollado el criterio son principalmente porque despues de haber investigado bien, entendi que la complejidad del merge sort es O(n log(n)), por lo que es eficiente al momento de ordenar listas de peliculas de cualquier tamaño, incluso cuando se tratan de listas muy grandes, ya que divide la lista en dos mitades casi iguales en cada paso. Esto asegura que, incluso en listas grandes, el trabajo se distribuye de manera uniforme a lo largo de las divisiones, lo que evita el peor caso de desequilibrio en la división. 

En cuanto a donde se puede observar el desarrollo, pues creo que la confusion estaba en la idea de pensar en que la recursividad por si sola hacia eficiente al algoritmo. Asi que, aqui mismo  en el readme se puede apreciar el desarrollo. 

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Me di cuenta que no todas las operaciones de una lista ligada son de complejidad 0(1) ya que eso depende que quieras hacer (insertar, mostrar, buscar, eliminar) y en que posicion de la lista estes trabajando. Mis argumentos para reconsiderar que ahora ya he desarrolado este criterio son que, no es lo mismo insertar un elememnto al principio que al final de la lista, ya que por un lado, al principio de la lista no tendremos que recorrer la lista con los punteros para lograr insertarlo, por lo que la complejidad sera simplemente O(1), pero si queremos insertar un elemento en medio o al final, la complejidad cambia a O(n) porque se requiere recorrer la lista para encontrar la posicion correcta. Esto puede verse en la ejecucion al momento de insertar una pelicula a la lista.


#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
En el programa utilizo una lista enlazada para gestionar operaciones como insercion, busqueda, ordenamiento y eliminacion de peliculas. La funcion mergeSort es la más exigente, con una complejidad de O(n log n) debido a su estrategia de dividir y conquistar. En el peor caso, las operaciones de insercion y busqueda tienen una complejidad O(n) al recorrer la lista enlazada. La carga y escritura desde y hacia el archivo de peliculas tienen una complejidad lineal en relación con el numero de lineas en el archivo.

Al final, la complejidad final del programa está principalmente influenciada por la operación de ordenamiento. La implementacion demuestra una gestion efectiva de la informacion de peliculas, con una complejidad global de O(n log n), siendo n el numero de peliculas en el catalogo


### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Dado que quiero usar una considerable cantidad de elementos para el programa, estuve investigando por cual algoritmo podia ayudarme mas con conjuntos de datos mas largos, y yo pense que el quick sort me iba a ayudar mas con eso, sin embargo, investigando un poco, vi que el merge sort es mucho mas eficiente en ese aspecto y que esta mas balanceado que el quick sort porque en el peor de los casos el quick sort tiene una complejidad computacional de O(n^2), mientras que el merge sort en el peor de los casos tiene una complejidad de O(n log(n)) lo que al final lo hace mucho mejor para mi proyecto

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Me he dado cuenta que el uso de una lista ligada en mi proyecto proporciona eficiencia en diversas operaciones. La inserción de películas la realizo de manera eficiente en orden alfabético, aprovechando la capacidad de la lista ligada para agregar elementos al principio en tiempo constante y en el medio en tiempo lineal. La estructura ordenada facilita mis búsquedas eficientes, aunque mi implementación actual utiliza una búsqueda lineal. Además, el algoritmo de ordenamiento Merge Sort aprovecha la flexibilidad de la lista ligada para dividirla en mitades, ordenarlas por separado y luego fusionarlas. La eliminación de películas la realizo eficientemente, liberando memoria y actualizando el archivo de almacenamiento. En conjunto, la lista ligada se adapta bien a mis necesidades específicas del catálogo de películas, ofreciendo una gestión eficiente de datos y una implementación ordenada y fácil de mantener.

Esto se puede observar al momento de la implementacion de las funciones del programa, contribuyendo a la organizacion con las operaciones relacionadas con el catalogo de peliculas.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Me di cuenta que no tenia clara la idea la funcion de buscar (consultar) algun dato o elemento en la lista y eso aprendi, en cuanto a mis argumentos puedo decir que ahora pude lograr buscar un elemento por medio del uso de banderas booleanas que me indican si existe o no, apoyandome de un nodo auxiliar (por asi decirlo) y recorrer toda la lista hasta que este apuntara a nulo, de esta forma con un condicional confirmaba si el elemento existia o no en la lista. Esto se puede observar claramente en la funcion "4. Consultar (buscar) una pelicula en la lista".


#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Yo creo que porque la estructura general del programa es coherente y sigue un buen enfoque al momento de abrir el archivo, leer los datos que hay en el, construir la lista ligada, ordenarla y luego imprimir los resultados.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

Me di cuenta que si usaba un solo archivo de texto ("peliculas.txt") y trabajaba sobre si mismo, moviendo los datos, y demas, tendia a fallar en algunos casos debido al merge, sin embargo, la solucion que encontre fue usar "peliculas.txt" unicamente para importar los datos a un nuevo archivo de texto llamo "datos.txt" y poder manejarlos ahi. SIn embargo, seguia teniendo error de datos duplicados asi que me di cuenta que habia un problema en la funcion mergeSort, donde la lista original no estaba siendo limpiada antes de realizar la fusión de las mitades ordenadas. Esto resultaba en duplicados porque los elementos se insertaban tanto en la lista original como en la nueva lista fusionada.

La solución que encontre fue agregar la función eliminarTodasPeliculas antes de la fusión en mergeSort, para asegurar que la lista original esté vacía antes de insertar los elementos de las mitades ordenadas, evitando así duplicados en el archivo "datos.txt".

Esto finalmente se puede ver reflejado al momento de usar el programa, si cargamos los datos y depues agregar datos manualmente, para despues ordenarlos. Si se hace eso en el programa, ahi se vera que ya no existen duplicados.
