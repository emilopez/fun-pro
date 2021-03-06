=========
Funciones
=========

:Autor: Emiliano López <emiliano [dot] lopez [at] gmail [dot] com>
:Fecha: 04/09/2014

.. contents:: Tabla de contenidos

Motivación
----------

¿Qué son?
	Conjunto de operaciones agrupadas que pueden ser **invocadas** desde diferentes partes de un
 	programa. Las funciones son subprogramas.

Ventajas
	- Subdividir un problema complejo en problemas mas simples: **divide y vencerás**
	- Mejoran la legibilidad del código, los programas modulares son más fáciles de **mantener y entender**
	- Posibilitan la reusabilidad del código, llamar funciones desde distintos programas.

Ejemplo 1: número par
---------------------

- Programa principal

	.. code-block:: cpp
	
		int n;
		cin>>n;
		if (es_par(n))
			cout<<n<<" es par";
		else
			cout<<n<<" es impar"

- Función **es_par**

	.. code-block:: cpp
	
		bool es_par(int n){
			if (n % 2 == 0)
				return true;
			else 
				return false;
		}

#. La función **es_par** es invocada desde el programa principal (cliente).
#. Se le envía **n** como dato de entrada.
#. La función recibe el parámetro, realiza una operación y **devuelve un resultado en su nombre**.

Ejercicio 1 (8.3.a)
-------------------

Escriba un programa que permita calcular el **área de un triángulo** a partir de conocer: a) la base y altura, b) las coordenadas de sus 3 vértices y, c) la longitud de sus lados. Resuelva el problema utilizando funciones, devolviendo además en el segundo caso la longitud de los lados. 

.. image:: img/triangulo.jpeg
	:width: 30%

Presente un menú que permita al usuario elegir una opción para calcular el área:

::

	CALCULO DE AREA DE UN TRIANGULO
	a- Ingresar base y altura: 
	b- Ingresar lados: 
	c- Ingresar coordenadas:
	Opcion: 

Ayuda 
''''''

Puede basarse en los siguientes prototipos:

.. code-block:: cpp

	float area_t(float base=1.0, float altura=1.0);

.. code-block:: cpp

	float area_t(float Lado1, float Lado2, float Lado3);

.. code-block:: cpp

	void area_t(float x1,float y1,float x2,float y2,float x3,float y3, 
		float &area, float &Lado1, float &Lado2, float &Lado3);


Las fórmulas para cada cálculo son las siguientes: 

* Conociendo la base y altura 
	.. math::
		AREA = base*altura/2

* Conociendo la longitud de sus lados
	.. math::
		s = 0.5*(L1+L2+L3)

	.. math::
		AREA = \sqrt{s*(s-L1)*(s-L2)*(s-L3)};

* Conociendo las coordenadas de sus vértices
	.. math::
		AREA = |0.5*(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2)|

	.. math::
		L1 = \sqrt{(x2-x1)^2 + (y2-y1)^2}

	.. math::
		L2 = \sqrt{(x3-x2)^2 + (y3-y2)^2}

	.. math::
		L3 = \sqrt{(x1-x3)^2 + (y1-y3)^2}

**OPCIONAL:** 

- Valide a través de una función que la opción ingresada sea correcta.
- Investigue el modo de modularizar en diferentes archivos y compilar las funciones en C++.

Ejercicio 2 (8.9)
-----------------

En un banco se ha depositado un capital inicial *m* por el cual se recibe anualmente un interés *x*. Se solicita que determine el capital que se tendrá al cabo de *n* años, teniendo en cuenta que el capital obtenido luego de un año es el capital inicial del año siguiente. Resuelva el problema utilizando función recursiva.

**Ayuda:** Para m = $5000 y x = 0.10, entonces el capital al cabo de tres años se obtendrá a partir del siguiente cálculo:

.. image:: img/ej2.png
	:width: 25%

de modo que el cálculo es una función que puede ser expresada en forma recursiva a partir de lo siguiente:

.. image:: img/ej2eq.png
	:width: 33%

El seguimiento de las sucesivas llamadas a si misma se observa a continuación, utilizando como datos de entrada m = 5000, x = 0.1 y n=3:

.. image:: img/recursividad_ej2.jpeg
	:width: 80%

Veamos las posibles soluciones


Solución al Ej. 1
-----------------

.. code-block:: cpp
	:include: ej/ej8.3.cpp

Modularizar el programa
''''''''''''''''''''''''

Del programa realizado vamos a crear tres archivos:

1. **area.h**
2. **area.cpp**
3. **ej8.3.cpp**

En cada uno vamos a tener lo siguiente:

- En (1) se encuentran UNICAMENTE los prototipos de las funciones.

- En (2) se encuentra la implementación de las funciones con los include a las bibliotecas que necesita, pero también se incluye *area.h*, es decir **#include "area.h"**. Ojo, van comillas porque es una biblioteca creada por el usuario y no parte del estándar de C++ donde se utiliza *<>*.

- En (3) se encuentra el programa principal con todos los include que necesita pero también con **#include "area.h"**.

El proceso de compilación es el siguiente:

a. Primero se compila *area.cpp* con la opción *-c*, esto es:

	::
	
		 g++ -c area.cpp

	Esto nos genera un archivo **area.o**

b. Ahora se compila el programa principal, es decir ej8.3.cpp, del siguiente modo:

	::
	
		g++ ej8.3.cpp area.o -o ej8.3.bin

Lo que finalmente nos va a generar el archivo **ej8.3.bin**

**Cada archivo quedaría del siguiente modo:**

- **area.h** (solo los prototipos)

.. code-block:: cpp
	:include: ej/modularizado/area.h

- **area.cpp** (implementación de los prototipos)

.. code-block:: cpp
	:include: ej/modularizado/area.cpp

- **ej8.3.cpp** (programa principal)

.. code-block:: cpp
	:include: ej/modularizado/ej8.3.cpp

Solución al Ej. 2
-----------------

.. code-block:: cpp
	:include: ej/ej8.9.cpp
