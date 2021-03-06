========
CStrings
========

:Autor: Emiliano López <emiliano [dot] lopez [at] gmail [dot] com>
:Fecha: 04/09/2014

.. contents:: Tabla de contenidos

Introducción
------------

Un cstring es *tal cual* un arreglo clásico pero de caracteres, con ciertas particularidades:

- Finalizan con un caracter ' \0' 
- Para mostrar en pantalla el arreglo entero se usa la salida estándar (cout<<)
- Existen ciertas funciones predefinidas para realizar operaciones sobre las mismas.

Declaración y definición
------------------------

Se pueden declarar como arreglos, dándole la dimensión o dejando que la calcule solito y solo. Acá, en los dos primeros ejemplos, los defino (inicializo) en la misma declaración, luego solo lo declaro:

.. code-block:: cpp
	
	//declaro y defino
	char cadena1[34]="Ojo, que puedo usar 33 caracteres";
	char cadena2[]="No tengas Ojo, va a tomar la cantidad total de caracteres";

	//declaro
	char cadena3[11];
 
Otra forma de declararlos es como punteros a char, algo así:

.. code-block:: cpp

	char *cadena="bla ble bli blo";

**Sin embargo, NO ES RECOMENDABLE hacerlo de este modo porque se encuentra obsoleto**. Los punteros a caracteres los vamos a usar cuando declaremos funciones que reciben cadenas de caracteres.


Asignación y lectura
--------------------

No es posible hacer una asignación como lo hacemos de una variable. Tengamos en cuenta que es un arreglo, y no podemos asignar un arreglo de enteros a otro simplemente con una operación a través del signo **=**. Es tal cuál un arreglo, por qué? porque es un arreglo.

Acá podemos hacerlo de dos maneras, usando las funciones predefinidas o bien programando una función nosotros donde se copie caracer por caracter. La función para asignar es **strcpy(dst,org)**, donde la cadena **org** se copia a **dst**.

.. code-block:: cpp
	
	//declaro y defino
	char cad1[12]="sin cadenas";
	char cad2[30];

	strcpy(cad2,cad1);
	cout<<cad2;
	//muestra: sin cadenas

La lectura puede hacerse utilizando el clásico **cin**, pero es preferible evitarlo porque si la cadena tiene espacios entonces solo lee hasta encontrar el primer espacio. La función utilizada entonces es **cin.getline(var, N)**, donde **var** es la variable que almacenará la lectura y N la cantidad de caracteres que debe leer. Por ejemplo:  

.. code-block:: cpp
	
	//cadenas de 20 caracteres
	char cad1[21];
	char cad2[21];
	
	//lee hasta 20 caracteres maximo
	cin.getline(cad1,21);

	//luego la copio a la cad2
	strcpy(cad2,cad1);

Funciones prefefinidas
----------------------

1). strlen
''''''''''

Para calcular la longitud de una cadena:

.. code-block:: cpp

	size_t strlen (const char *cadena); // averiguar longitud

Una función equivalente hecha a pata sería:

.. code-block:: cpp

		int len(char *cad){
			// retorna la cantidad de caracteres
			int cant = 0;
			while (cad[cant] != '\0')
				cant++;
			return cant;
		}

2). strcpy
'''''''''''

Para asignar una cadena a otra:

.. code-block:: cpp
	
	char *strcpy (char *dest, const char *orig); // copiar

**Ejemplo:** Se leen dos cadenas por teclado, se intercambia su contenido y se las muestra por pantalla.

.. code-block:: cpp
	:include: ej/tutorial/ej-strcpy.cpp

3). strncpy
''''''''''''

Para asignar una cantidad de caracteres de una cadena a otra:

.. code-block:: cpp
	
	char *strncpy (char *dest, const char *orig, size_t n); // copiar

**Ejemplo:** quiero copiar la mitad de caracteres de una cadena a otra:

.. code-block:: cpp
	:include: ej/tutorial/ej-strncpy.cpp

4). strcat
''''''''''

Para concatear una cadena a otra

.. code-block:: cpp
	
	char *strcat (char *dest, const char *orig); // concatenar

**Ejemplo:** quiero armar un email, donde las personas ingresan en variables separadas el nombre y apellido, y le tengo que agregar el dominio "@gnu.org"

.. code-block:: cpp
	:include: ej/tutorial/ej-strcat.cpp


5). strncat
'''''''''''

Para concatenar una cierta cantidad de caracteres a otra.

.. code-block:: cpp
	
	char *strncat (char *dest, const char *orig, size_t n); // concatenar

**Ejemplo:** leo dos cadenas, y concateno la mitad de caracteres de la segunda cadena en la primera.

.. code-block:: cpp
	:include: ej/tutorial/ej-strncat.cpp

6). strcmp
''''''''''

Compara dos cadenas, si son iguales o mayor o menor

.. code-block:: cpp
	
	int strcmp (const char *cad1, const char *cad2); // comparar

**Ejemplo:** Se compraran tres cadenas de caracteres y se imprime en pantalla la primera en orden alfabético.

.. code-block:: cpp
	:include: ej/tutorial/ej-strcmp.cpp

7). strncmp
'''''''''''

Compara los n primeros caracteres de dos cadenas, si son iguales o mayor o menor

.. code-block:: cpp
	
	int strncmp (const char *cad1, const char *cad2, size_t n); // comparar

**Ejemplo:** Se ingresan los **n** caracteres a comparar entre las cadenas "abz" y "aba" y se imprime en pantalla la primera en orden alfabético. En caso que sean iguales se muestra un mensaje alusivo.

.. code-block:: cpp
	:include: ej/tutorial/ej-strncmp.cpp

8). strchr
''''''''''

Busca un único caracter en una cadena comenzando desde la izquierda retornando la cadena desde la aparición del caracter (puntero a la primer ocurrencia) o NULL en caso que no se lo encuentre. 

.. code-block:: cpp
	
	const char *strchr (const char *cad, const char car); // buscar caracter

**Ejemplo:** Una cadena de caracteres representa la fecha y hora de tres medidas de temperaturas registradas en campo. La cadena posee el siguiente formato:

::

	28-03-2014 00:00:00; 28.30; 25.50; 12.10

Se observa que los valores se encuentran separados por el signo punto y coma (";"). Se desea obtener el solamente la fecha y hora de esta cadena. Realice el programa haciendo uso de la función **strchr**. 

.. code-block:: cpp
	:include: ej/tutorial/ej-strchr.cpp


9). strrchr
'''''''''''

Busca un único caracter en una cadena comenzando desde la derecha

.. code-block:: cpp
	
	const char *strrchr (const char *cad, const char car); // buscar caracter

**Ejemplo:** Utilizando el mismo caso que en el item previo, ahora se calcula el promedio de los tres valores numéricos.

.. code-block:: cpp
	:include: ej/tutorial/ej-strrchr.cpp

10). strstr
'''''''''''

Busca una cadena dentro de otra. Funciona similar a strchr con la diferencia que permite buscar una una cadena -una palabra o más de un caracter- dentro de otra. 

.. code-block:: cpp
	
	const char *strstr (const char *cad, const char *sub); // buscar subcadena

11). strspn
''''''''''''

Busca dentro de la cadena **cad** *alguno* de los caracteres que son parte de la cadena **cars** devolviendo la posición de la primer ocurrencia. Si no encuentra ninguna ocurrencia devuelve la longitud de la cadena **cad**.

.. code-block:: cpp
	
	size_t strspn (const char *cad, const char *cars); // buscar caracteres

**Ejemplo:** Se busca en una cadena la posición donde se encuentra algún valor numérico.

.. code-block:: cpp
	:include: ej/tutorial/ej-strspn.cpp

12). strtok
''''''''''''

Devuelve la cadena hasta donde se haya encontrado algunos de los carateres buscados. strtok modifica la cadena original, por lo tanto es necesario guardarla si no se desea perderla. La primer llamada (para conseguir el primer token) se hace con la cadena (cadena1), las llamadas sucesivas (para obtener los tokens restantes) se hacen con NULL.

.. code-block:: cpp
	
	char *strtok (char *ptr, const char *cars); // buscar caract. y cortar cadena

**Ejemplo:** se separan en tokens la cadena vista en el item 8, se utilizan como caracteres delimitadores el espacio, el punto y coma, los dos puntos y el guión (" ;:-").

.. code-block:: cpp
	:include: ej/tutorial/ej-strtok.cpp

Ejercicios
----------

Ejercicio 1
'''''''''''

Las fechas comúnmente se imprimen se imprimen en distintos formatos, dos de los ejemplos más comunes son:

- 28/03/1981
- 28 de Marzo, 1981

Escriba un programa que lea la fecha en el primer formato y lo imprima en el segundo. Para esto desarrolle el programa de dos maneras, utilizando sus propias funciones y haciendo uso de las funciones predefinidas en la biblioteca *cstring*.


Ejercicio 2
'''''''''''

Dado un cstring con una frase, por ejemplo: "Hola, todo bien?", se generan las
siguientes tres salidas (separadas por línea en blanco):

.. image:: img/ej1.png
	:width: 30%

Identifique el funcionamiento del programa que generó la salida previa y desarróllelo creando sus propias funciones. 

Soluciones
----------

Ej. 1
'''''

.. code-block:: cpp
	:include: ej/ej10.7.cpp

Ej. 2
'''''

.. code-block:: cpp
	:include: ej/ej10.3.cpp




