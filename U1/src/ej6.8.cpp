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

