==================
Introducción a C++
==================

:Autor: Emiliano López <emiliano [dot] lopez [at] gmail [dot] com>
:Fecha: 04/09/2014

.. contents:: Tabla de contenidos

Ejercicio 1
-----------

En el siguiente ejemplo se muestra un programa en C++:

.. code-block:: cpp
	
	#include <iostream>
	using namespace std;

	int main(int argc, char *argv[]) {
		float C, F;
		C = 21;
		F = (9/5)*C + 32;
		cout<<C<<" grados Celsius son "<<F<<" grados Fahrenheit";
		return 0;
	}

Analice el código del siguiente programa C++ utilizado para la conversión entre grados Celsius y Fahrenheit. ¿Los resultados son correctos? ¿Qué modificación haría?

Ejercicio 2
-----------

Realice un programa en C++ de conversión de unidades de distancia, donde se ingrese una longitud en metros y se obtenga la distancia en pulgadas, pies, yardas y millas.  Sabiendo que:

- 1 pulgada = 2.54 cm
- 1 pie = 12 pulgadas
- 1 yarda = 3 pies
- 1 milla = 1760 yardas. 

Como verificación: 640 metros = 25196,85 pulgadas = 2099,74 pies = 699,91 yardas = 0,3977 millas. La salida debe mostrarse de la siguiente manera:

.. image:: img/ej1.png
	:width: 40%

* Ayuda: haga uso de las funciones setw(), setfill(), left, right para formatear la salida y de  setprecision() y fixed() para establecer la cantidad de decimales a mostrar.


Ejercicio 3
-----------

La cocción de un huevo pasado por agua debe ser de tal modo que la clara se coagule sin que lo haga la yema. La clara se coagula para temperaturas superiores a 63 °C mientras que la yema lo hace para temperaturas superiores a 70 °C, por lo tanto para coagular la clara el huevo debe estar un tiempo suficiente a una temperatura superior a 63 °C pero la yema no debe superar los 70 °C. La siguiente fórmula expresa el tiempo “t” que demora en alcanzar la yema la temperatura “Ty”.

.. image:: img/ej2.png
	:width: 40%

donde M, ρ, c y K son propiedades del huevo y corresponden a la masa, densidad, calor específico y
conductividad térmica respectivamente. M = 47 gramos, ρ = 1,038, c = 3,7 y K= 5,4E-3.
Además, “Tw” es la temperatura del agua hirviendo, “T o” es la temperatura del huevo antes de ser
puesto en el agua.
Implemente la fórmula en un programa C++, y obtenga el tiempo para T w = 100 °C , Ty = 70 °C, y
usando Tw = 4 °C si el huevo estaba en la heladera, y T w =20 °C si se encontraba a temperatura
ambiente.

Veamos a continuación posibles soluciones y su explicación

Solución Ej. 1
--------------

En problema radica en las operaciones entre números enteros. Se debe tener en cuenta que operar entre números enteros da como resultado un valor del mismo tipo. Con lo cual la fracción 9/5 trunca los decimales y por ese motivo el resultado es incorrecto. La solución es que al menos una de las dos constantes sea flotante, por ejemplo: 9.0/5

Solución Ej. 2
--------------

.. code-block:: cpp
	
	#include <iostream>
	#include <iomanip>
	using namespace std;

	int main(int argc, char *argv[]) {
		
    	float metros, pulgadas, pies, yardas, millas, cms;
    	
    	cout<<"Ingrese la distancia en metros = ";
    	cin>>metros;
    
    	cms = metros*100;
    	pulgadas = cms/2.54;
    	pies = pulgadas/12;
    	yardas = pies/3;
    	millas = yardas/1760;
    
    	cout<<"\nUnidad \t\t Medida equivalente"<<endl;
    	cout<<setfill('.');
    	setprecision();
    
    	cout<<setw(10)<<left<<"Pulgadas";
    	cout<<setw(20)<<right<<fixed<<pulgadas<<endl;
    
    	cout<<setw(10)<<left<<"Pies";
    	cout<<setw(20)<<right<<pies<<endl;
    
    	cout<<setw(10)<<left<<"Yardas";
    	cout<<setw(20)<<right<<yardas<<endl;
    
    	cout<<setw(10)<<left<<"Millas";
    	cout<<setw(20)<<right<<millas<<endl;
    	return 0;
	}


Solución Ej. 3
--------------

.. code-block:: cpp
	
	#include <iostream>
	#include <cmath>
	using namespace std;

	int main(int argc, char *argv[]) {
		//+ Se declaran las variables
		//   M: masa, p: densidad, c: calor especifico, 
		//   K: conductividad termica 
		//   Tw: temp. del agua hirviendo
		//   To: temp. del huevo antes de ponerlo
		//   Ty: temp. de la yema
		float M,p,c,K,Tw,To,Ty;
		
		//+ Se definen las variables
		M = 47;     //gramos
		p = 1.038;
		c = 3.7;
		K = 5.4E-3;
		
		Tw = 100;
		Ty = 70;
		To = 4;
		
		//Se calcula la ecuacion
		float l = log(0.76*(To-Tw)/(Ty-Tw));
		float num = pow(M,2./3.)*c*pow(p,1./3.);
		float den = K*pow(M_PI,2)*pow(4.*M_PI/3.,2./3.);
		    
		float t = num*l/den;
		cout<<"Tiempo de coccion: "<<t/60.<<" minutos para To = "<<To<<endl;
		
		//Se calcula para el nuevo To
		To = 20;
		l = log(0.76*(To-Tw)/(Ty-Tw));
		t = num*l/den;
		cout<<"Tiempo de coccion: "<<t/60.<<" minutos para To = "<<To<<endl;
		
		return 0;
	}
