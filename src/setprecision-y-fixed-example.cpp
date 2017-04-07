// setprecision example
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
using namespace std;
// el setprecision formatea la cantidad de decimales a usar en la salida x pantalla. 
int main () {
	double f = 3.14159;
	cout <<"setprecision(5) f:    "<< setprecision(5) << f << '\n';
	cout <<"setprecision(5) 10*f: "<< setprecision(5) << 10*f << '\n';
	
	cout << setprecision(9) << f << '\n';
	cout << fixed;
	cout << setprecision(8) << f << '\n';
	cout << setprecision(9) << f << '\n';
	
	cout << setprecision(9) << f << '\n';
	return 0;
}
