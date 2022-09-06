#include <cstdlib>
#include <iostream>
#include <clocale>
#include <math.h>
#include <windows.h>
#include <stdio.h>
#include <iomanip>
#include <time.h>
#include <sstream>
using namespace std;
void gotoxy(short x, short y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int main()
{
	//variables y arreglos
	float deducciones, tm,cantidad,horastrabajadas,horasextrasempleado[50], salariobruto,horasdeempleado[50],salarionetoempleado[50], horasextras,bono, salario, salarioneto, promediodehoras, segurosocial=0.0975, seguroeducativo=0.0125;
	int  opc1, i=0, s=0, salto, venaca;
	string nombredeempleado[50], nombre, t;
	//barra de carga
for (int cont2 = 1; cont2 <= 5; cont2++)
    {
        for (int cont = 0;cont<4;cont++)
        {
            gotoxy(0, 0);
            if (cont == 0)
                std::cout << "\304";
            if (cont == 1)
                std::cout << "\134";
            if (cont == 2)
                std::cout << "\174";
            if (cont == 3)
                std::cout << "\57";
            Sleep(200);
        }
    }
    std::cout<<std::endl;
    //color de la consola
    	system ("color 20");
    //llamar el goto
    	venaca:
    	//fecha y hora funcion
    char fecha[25];
    time_t current_time;
    current_time=time(NULL);
    ctime(&current_time);
    strcpy(fecha, ctime(&current_time));
    printf("%s", fecha);
    //presentacion del programa
    cout<<"Universidad de panama"<<endl;
cout<<"Facultad de Ingenieria informatica, electronica y communicacion"<<endl;
cout<<"Escuela de Licenciatura en informatica."<<endl;
cout<<"Nombre: Jose Dasilva"<<endl;
cout<<"Cedula: EC-46-14698"<<endl;
	//inicio del programa
	cout<<"---------------------------------"<<endl;
	cout<<"Ingrese la cantidad de empleados a evaluar: "<<endl;
	cin>>cantidad;
	//inicio del ciclo 
	do
	{
		cout<<"---------------------------------"<<endl;
		cout<<"En que turno trabaja el empleado: \n"<<"1. Diurno\n"<<"2. Vespertino\n"<<"3. Nocturno"<<endl;
		cin>>opc1;
		
		  switch (opc1)
		  { //opcion numero 1
		  	case 1:
		  		cout<<"---------------------------------"<<endl;
		  		cout<<"Ingrese el nombre del empleado: "<<endl;
		  		cin>>nombre;
		  		nombredeempleado[i]=nombre;
		  		cout<<"Ingrese las horas trabajadas del empleado: \n"<<endl;
		  		cin>>horastrabajadas;
		  		horasdeempleado[i]=horastrabajadas;
		  		cout<<"Cuantas horas extras trabajo el empleado: "<<endl;
		  		cin>>horasextras;
		  		horasextrasempleado[i]=horasextras;
		  		if (horasextras<=2)
		  		{
		  			horasextras*=1.75;
		  		}else
		  			{
		  				if(horasextras>=5)
		  				{
		  					horasextras*=2.25;
		  				}else
		  					{
		  						if(horasextras<5)
		  						{
		  							horasextras*=0.3;
		  						}
		  					}
		  				
		  			}
		  		salariobruto=horastrabajadas*horasextras;
		  		segurosocial=salariobruto*0.0975;
		  		seguroeducativo=salariobruto*0.0125;
		  		salarioneto=salariobruto-segurosocial-seguroeducativo;
		  		salarionetoempleado[i]=salarioneto;
		  		break;
		  		//opcion numero 2
		  	case 2:
		  		cout<<"---------------------------------"<<endl;
		  		cout<<"ingrese el nombre del empleado: "<<endl;
		  		cin>>nombre;
		  		nombredeempleado[i]=nombre;
		  		cout<<"cuantas horas trabajo el empleado: "<<endl;
		  		cin>>horastrabajadas;
		  		horasdeempleado[i]=horastrabajadas;
		  		cout<<"Ingrese las horas extras trabajadas: \n"<<endl;
		  		cin>>horasextras;
		  		horasextrasempleado[i]=horasextras;
		  			if (horasextras<=2)
		  		{
		  			horasextras*=1.75;
		  		}else
		  			{
		  				if(horasextras>=5)
		  				{
		  					horasextras*=2.25;
		  				}else
		  					{
		  						if(horasextras<5)
		  						{
		  							horasextras*=0.3;
		  						}
		  					}
		  				
		  			}
		  		bono=horastrabajadas+100;
		  		salariobruto=horastrabajadas*horasextras;
		  		segurosocial=salariobruto*0.0975;
		  		seguroeducativo=salariobruto*0.0125;
		  		salarioneto=salariobruto-segurosocial-seguroeducativo+bono;
		  		salarionetoempleado[i]=salarioneto;
		  		break;
		  		//opcion numero 3
		  	case 3:
		  		cout<<"---------------------------------"<<endl;
		  		cout<<"ingrese el nombre del empleado: "<<endl;
		  		cin>>nombre;
		  		nombredeempleado[i]=nombre;
		  		cout<<"cuantas horas trabajo el empleado: "<<endl;
		  		cin>>horastrabajadas;
		  		horasdeempleado[i]=horastrabajadas;
		  		cout<<"Ingrese las horas extras trabajadas: \n"<<endl;
		  		cin>>horasextras;
		  		horasextrasempleado[i]=horasextras;
		  			if (horasextras<=2)
		  		{
		  			horasextras*=1.75;
		  		}else
		  			{
		  				if(horasextras>=5)
		  				{
		  					horasextras*=2.25;
		  				}else
		  					{
		  						if(horasextras<5)
		  						{
		  							horasextras*=0.3;
		  						}
		  					}
		  				
		  			}
		  		bono=horastrabajadas*0.03;
		  		salariobruto=horastrabajadas*horasextras;
		  		segurosocial=salariobruto*0.0975;
		  		seguroeducativo=salariobruto*0.0125;
		  		salarioneto=salariobruto-segurosocial-seguroeducativo;
		  		salarionetoempleado[i]=salarioneto;
		  		break;
		  		}
		     	i++;
	}while(i<cantidad);
	//impresion de la proforma
	for(int i=0; i<cantidad; i++)
		  		{
		  			cout<<"---------------------------------"<<endl;
		  			cout<<"                   GRUPO  REY                   "<<endl;
					cout<<"Nombre del empleado: "<<nombredeempleado[i]<<endl;;
		  			cout<<"Horas trabajadas: "<<horasdeempleado[i]<<endl;
		  			cout<<"Horas extras trabajadas: "<<horasextrasempleado[i]<<endl;;
		  			cout<<"Salario neto del empleado: "<<salarionetoempleado[i]<<endl;;
		  			cout<<"---------------------------------"<<endl;
		  			
		  		}
		  		system("pause");
		  		system("cls");
		  		goto venaca;
	}
