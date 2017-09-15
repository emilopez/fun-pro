==========
POO en C++
==========

:Autor: Emiliano López <emiliano [dot] lopez [at] gmail [dot] com>
:Fecha: 31/08/2017

.. contents:: Tabla de contenidos

**Aclaración:** Esto está escrito desestructuradamente, en criollo con fuertes 
influencias santafesinas. Pretendo ir a los bifes y mostrar las diferentes formas 
de hacer lo mismo, detalle que padezco y detesto de C++. 

Introducción
------------

La POO es un paradigma. ¿Qué significa esto? Que se siguen ciertas reglas y procedimientos.
Muy livianamente es un modo diferente de organizar el código.


Declaración
-----------

Para usar POO necesitamos declarar una clase, que es algo así como una plantilla
que define las propiedades y comportamiento de un objeto. On objeto es una instancia
 de una clase, una qué? se instancia algo cuando se lo declara. A continuación 
 creamos un objeto a del tipo Alumno, entonces decimos que a es una instancia de la
 clase Alumno.

.. code-block:: cpp

    Alumno a;

El tema es que debemos armar la clase, que es muy parecido a un struct, con la salvedad
que ahora agregamos funciones asociadas a la clase.  Supongamos que tenemos un 
``struct Persona{stirng nom; long fecha_nacimiento;};`` y que usamos una función
para calcular la edad a partir de su fecha de nacimiento y la fecha de hoy.

Sería algo así:

.. code-block:: cpp

    int calcular_edad(Persona p, long HOY){
        // formato fechas: YYYYMMDD
        return (p.fecha_nacimiento - HOY)/10000;
    }
    long HOY = 20170915;
    Persona a;
    a.nom = "Armando Esteban Quito";
    a.fecha_nacimiento = 19810328;
    cout << "La edad es: " << calcular_edad(a, HOY) 
     
Bueno, ahora vamos a hacer una clase Persona donde sería algo muy parecido al struct pero donde
 tengamos asociada la función ``calcular_edad()`` de modo que su uso sería del siguiente modo:

.. code-block:: cpp

    long HOY = 20170915;
    p.calcular_edad(HOY);

No me podés negar que queda mas elegante. Ahora bien, veamos cómo se define la clase ``Persona``:

.. code-block:: cpp

    class Persona{
        string nom;
        long fecha_nacimiento;
    public:
        int calcular_edad(long HOY){
            return (fecha_nacimiento - HOY)/10000;
        }
    };

De ese modo queda hermosamente declarada una clase. Ahora bien, desde adentro de 
la clase se ve que no hay drama en acceder a los atributos nom y fecha_nacimiento pero 
¿cómo los accedemos desde el programa principal?
