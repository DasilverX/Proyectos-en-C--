
#include <iostream>
#include <clocale>
#include <stdio.h>

using namespace std;
int main ()
{
	int  cantie,i=0, j=0;
	string escuela, estudi, dep,departamento[20],carrera[20], estudiante[20];
	float indices[20], indice;
	//algoritmo
	cout<<"ingrese la cantidad de estudiantes que va a evaluar\n"<<endl;
	cin>>cantie;
	for(i=0; i<cantie; i++)
	{
	cout<<"ingrese el nombre del estudiante\n"<<endl;
	cin>>estudi;
	estudiante[i]=estudi;
	cout<<"ingrese la escuela en la que pertenecce\n"<<endl;
	cin>>escuela;
	cout<<"ingrese el departamento  en el que pertenece\n"<<endl;
	cin>>dep;
	cout<<"ingrese su indice\n"<<endl;
	cin>>indice;
	indices[i]=indice;
    }
    //impresion
    for(j=0; j<cantie; j++)
    {
    	cout<<"prueba de impresion de la escuela\n"<<escuela<<endl;
    	cout<<"prueba de impresion del departamento\n"<<dep<<endl;
    	cout<<"prueba de impresion del indice\n"<<indices[i]<<endl;
    	
    }
    system("pause");
    return 0;
}
