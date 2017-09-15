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
    cout << "La edad es: " << p.calcular_edad(HOY);

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

Bueno, resulta ser que a diferencia de los structs los atributos miembro de una clase son
privados a menos que se los ponga explícitamente bajo la cláusula ``public``.

¿Qué significa que sean privados? Significa que desde el programa principal donde 
se cree un objeto instanciando a esta clase, no se podrá acceder a ellos, por lo tanto
vamos a tener que crear funciones, de aquí en más les diremos ``métodos`` tanto
para modificarlos como para verlos. Esto se suele denominar en la jerga, setters y getters.

Setters y getters
'''''''''''''''''

Los setters y getters son los métodos usados para escribir y consultar los atributos privados, 
es decir, como ya no podemos acceder porque está oculto (principio de ocultación) tenemos
que usar los métodos que nos permiten hacerlo. 

Así que podríamo tener 4 métodos, 2 para consultar tanto el nombre como la fecha
de nacimiento y otros 2 para setearlos. La cosa quedaría:

.. code-block:: cpp

    class Persona{
        string nom;
        long fecha_nacimiento;
    public:
        void setNom(string n){
            nom = n;
        }
        void setFechaNac(long fn){
            fecha_nacimiento = fn;
        }
        string getNom(){
            return nom;
        }
        long getFechaNac(){
            return fecha_nacimiento;
        }
        int calcular_edad(long HOY){
            return (fecha_nacimiento - HOY)/10000;
        }
    };
    
También podríamos haber hecho un único método para setear ambos y lo mismo para consultarlos. 
Dependerá del diseño que te convenga, en general hay que ir uno por uno, para que luego tengas más
flexibilidad desde el programa cliente, si, ya se que es un embole.

Ahora sí entonces nos queda mostrar cómo sería su uso:

.. code-block:: cpp
    
    Persona p;
    p.setNom("Juan de los Palotes");
    p.setFechaNac(19810328);
    long HOY = 20170915;
    cout << "La edad es: " << p.calcular_edad(HOY);

