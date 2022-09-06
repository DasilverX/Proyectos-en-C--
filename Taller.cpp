#include <iostream>
using namespace std;
int main ()
{
	int  cantie,i=0, j=0;
	string escuela,school[20] [20],estudi, dep,departamento[20][20],carrera[20] [20], nombreestudiante[20] [20];
	float indices[20][20], indice;
	//algoritmo
	cout<<"ingrese la cantidad de estudiantes que va a evaluar\n"<<endl;
	cin>>cantie;
	do
	{
	
	
	  for(i=0; i<20; i++)
	  { 
		for(j=0; j<20; j++)
		{
		
	    cout<<"ingrese el nombre del estudiante\n"<<endl;
	    cin>>nombreestudiante[i][j];
	    cout<<"ingrese la escuela en la que pertenecce\n"<<endl;
	    cin>>school[i][j];
	    cout<<"ingrese el departamento  en el que pertenece\n"<<endl;
	    cin>>departamento[i][j];
	    cout<<"ingrese su indice\n"<<endl;
	    cin>>indices[i] [j];
        }
      }
    } while (i<cantie);
    //impresion de lo cuadro de honor
    for(int i=0;i<cantie; i++)
		  		{
		  			cout<<"---------------------------------"<<endl;
		  			cout<<"                   ESTUDIANTE                 "<<endl;
					cout<<"Nombre del estudiante: "<<nombreestudiante[i][j]<<endl;;
		  			cout<<"Escuela: "<<school[i][j]<<endl;
		  			cout<<"Departamento: "<<departamento[i][j]<<endl;;
		  			cout<<"Carrera: "<<carrera[i][j]<<endl;
		  			cout<<"Indice: "<<indices[i][j]<<endl;
		  			cout<<"---------------------------------"<<endl;
		  		}
    system("pause");
    return 0;
}
