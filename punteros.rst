========
Punteros
========

:Autor: Emiliano López <emiliano [dot] lopez [at] gmail [dot] com>
:Fecha: 16/08/2017

.. contents:: Tabla de contenidos

Introducción
------------

Los punteros son una variable cuyo contenido es una dirección de memoria, es decir, una referencia a otro sector de la memoria.

Declaración y definición
------------------------

Si se lo declara y define en una única sentencia entonces tiene la siguiente particularidad:

.. code-block:: cpp

    int a = 3;
    int *pa = new int;
    int *pb = &a;
    
En la declaración vemos que el asterisco es quien nos indica que es un puntero, cuya referencia será
a un tipo de dato entero. ``a`` es una variable estática, cuya dirección de memoria se obtiene anteponiendo
el operador ``&``. De ahí que al declarar un puntero se le debe asignar algo que sea una dirección, en este caso
vemos 2 ejemplos, el ya mencionado que usa la dirección de la variable estática ``a``, o bien creando un nuevo
espacio en memoria de forma dinámica, en este caso utilizando ``new int``.

Si se desdobla la operación de declaración y asignación entonces no se utiliza el asterisco en la asignación, 
para el caso del puntero ``pb`` sería de la siguiente manera:

.. code-block:: cpp

    int a = 3;
    int *pb;
    pb = &a;
    
Debe tenerse en cuenta esta particularidad para evitar la ambiguedad a la hora de acceder al conenido de lo que apunta un puntero.
Entonces, el asterisco se usa bajo dos circunstancias, para declarar el puntero y para acceder a lo que apunta, esto es, si quisiera
mostrar el contenido de lo que apunta ``pb`` debería hacer:

.. code-block:: cpp
    
    cout << *pb;

Eso nos mostraría lo que tiene almacenado la variabla estática ``a``. Al asterisco en este caso se lo denomina operador de desrreferencia, no hace falta explicar las razones de tan intrincado nombre.

Aritmética y arreglos
---------------------

Un arreglo estático se declara haciendo ``int v[10];`` y el acceso a los elementos se realiza a través de un índice, 
por ejemplo, el tercer elemento se encuentra bajo el índice 2: ``v[2] = 8;``.

Utilizando aritmética de punteros podemos referirnos a los elementos, por lo que para replicar la última asignación
deberíamos hacer: ``*(v + 2)= 8;``.

La equivalencia es ``v[i] <-> *(v + i)``.

Como bien sabemos, los arreglos estáticos deben dimensionarse utilizando una constante, esto es: ``int v[10];``, donde ese valor 10
no puede ser reemplazado por una variable ingresada por el usuario. Esta liminate puede ser salvada creando un arreglo en forma dinámica.

- Yo me pregunto, ¿cuál es la dirección de memoria del elemento de la posición 3?

La respuesta es: ``p+3``;

- ¿Por qué funciona esto?

Como sabe el tipo de dato que contiene, acá son enteros, se desplaza los bytes necesarios para llegar al cuarto lugar, índice 3. Cada entero ocupa 4 bytes, por lo que en realidad se está desplazando 3*4 bytes en la memoria, pero eso es transparente para el programador.

Arreglos dinámicos
''''''''''''''''''

Los arreglos estáticos ocupan la parte de la memoria denominada stack, es limitada y muy inferior a la porción de la memoria denominada heap. Al crear un arreglo en forma dinámica se almacena en el heap y la forma de hacerlo es la siguiente:

.. code-block:: cpp

    int N;
    cin >> N;
    
    int *p = new int[N];
    
De este modo se creó dinámicamente un arreglo en la memoria cuya dimensión fue ingresada por el usuario, funcionalidad no permitida
en arreglos estáticos. Ahora el puntero ``p`` apunta al primer elemento del arreglo y se pueden utilizar ambas notaciones para acceder, por ejemplo;

.. code-block:: cpp

    for (int i = 0; i< N; i++)
        cin >> *(p+i); // equivalente a p[i]
    
