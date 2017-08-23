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


