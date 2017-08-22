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

    int a;
    int *pa = new int;
    int *pb = &a;
    
En la declaración vemos que el asterisco es quien nos indica que es un puntero, cuya referencia será
a un tipo de dato entero. ``a`` es una variable estática, cuya dirección de memoria se obtiene anteponiendo
el operador ``&``. De ahí que al declarar un puntero se le debe asignar algo que sea una dirección, en este caso
vemos 2 ejemplos, el ya mencionado que usa la dirección de la variable estática a, o bien creando un nuevo
espacio en memoria de forma dinámica, en este caso utilizando ``new int``.
