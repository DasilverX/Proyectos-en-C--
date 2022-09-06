/* Nombre: Jose Dasilva
Cedula: EC-46-14698
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;


struct Nodo{
	int dato;
	char dato1;
	Nodo *siguiente;
};


//prototipos
void menu();
void insertarCola(Nodo *&, Nodo *&, int);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&, Nodo*&, int);
void suma_polinomios();
void resta_polinomios();
void multiplicacion_polinomios();



int main(){
	
	
	menu();
	
	
	getch();
	return 0;
	
}


void menu(){
	int opc;
	char dato;
	
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	do{
		
	 printf("MENU:");
	    printf("1. Insertar primera cola");
		printf("2. Inserta segunda cola ");
	    printf("3. Mostrar elementos de las colas");
	    printf("4. Suma de polinomios");
	    printf("5. Resta de polinomios");
	    printf("6. Multiplicacion de polinomios");
        printf("7. Salir.");
	    printf("Opcion:");
		scanf("%d", &opc);
		
		
		switch(opc){
			
			        case 1: printf("Inserte para agregar la primera cola: ");
			                scanf("%d", &dato);
				            insertarCola(frente,fin,dato);
					        break;
					
					case 2: printf("Inserte para agregar la segunda cola: ");
			                scanf("%d", &dato);
			             	insertarCola(frente,fin,dato);
	                        break;


                    case 3: cout<<"\nMostrando los elementos de la cola: ";
			                 while(frente != NULL){
				                 suprimirCola(frente,fin,dato);
				                  if(frente != NULL){
				                    	cout<<dato<<" , ";
				                }
				                 else{
					                  cout<<dato<<" . "; 
				                 }
			                 }
			
			                  system("pause");
			                  break;
			
			        case 4: break;
				
				
				system("cls");}
	}while(opc != 7);
	}
	
	


//funcion insertar cola 1 
void insertarCola(Nodo *&frente, Nodo *&fin, int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		
		frente = nuevo_nodo;
		
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
	
	cout<<"Elemento "<<n<<" insertado en la cola";
	
}


//funcion insertar cola 2 
void insertarCola1(Nodo *&frente, Nodo *&fin, int n)
{
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		
		frente = nuevo_nodo;
		
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
	
	cout<<"Elemento "<<n<<" insertado en la cola";
	
}

//funcion cola vacia

bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true : false;
	
}


//funcion suprimir cola

void suprimirCola(Nodo *&frente, Nodo *&fin, char &n){
	n = frente->dato1;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente =NULL;
		fin= NULL;
	}
	else{
		frente = frente->siguiente;
	}
	
	delete aux;
	
	
}

