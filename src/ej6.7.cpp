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

