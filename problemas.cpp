#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;


struct Nodo{
	int dato;
	char dato1;
	Nodo *siguiente;
	Nodo *atras;
} *primero, *ultimo;


//prototipos
void menu();
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo*);
void buscarLista(Nodo *, int);
void eliminarNodo(Nodo *&, int);
void eliminarLista(Nodo *&, int &);
void insertarNodo();
//void desplegarListaPU();
//void desplegarListaUP();
void insertarCola(Nodo *&, Nodo *&, int);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&, Nodo*&, char &);

//variable global 
	Nodo *lista = NULL;
    Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	 
int main(){

	
	menu();
	

	
	getch();
	return 0;
	
} 

void menu(){
	int opc, dato, dato1;
	char dato2;
	
	
	do{
		printf("\t \t \t Menu del Proyecto Final");
		printf("\n");
		printf("\n 1. Insertar elementos en la lista");
		printf("\n 2. Mostrar elementos de la lista");
		printf("\n 3. Buscar un elemento de la lista");
		printf("\n 4. Eliminar nodo de la lista");
		printf("\n 5. Vaciar lista");
		printf("\n 6. Desplegar lista");
		printf("\n 7. Insertar primera cola");
		printf("\n 8. Inserta segunda cola ");
	    printf("\n 9. Mostrar elementos de las colas");
		printf("\n 10. Salir");
		printf("\n");
		printf("\n Opcion: "); scanf("%d", &opc);
		
		switch(opc){
			case 1:
				cout<<"digite un numero: "<<endl;
				cin>>dato;
				insertarLista(lista,dato);
				cout<<"\n";
				system("pause");
				break;
			
			case 2:
			mostrarLista(lista);
			cout<<"\n";
			system("pause");
			break;
			
			case 3:
				cout<<"Digite el numero que desea buscar"<<endl;
				cin>>dato;
				buscarLista(lista,dato);
				cout<<"\n";
				system("pause");
				break;
				
			case 4:
				cout<<"Digite el elemento que desea eliminar"<<endl;
				cin>>dato;
				eliminarNodo(lista,dato);
				cout<<"\n";
				system("pause");
				break;
				
			case 5:
				while(lista != NULL){
					eliminarLista(lista,dato);
					cout<<dato<<" -> ";
				}
			cout<<"\n";	
			system("pause");
			break;	
			
			case 6:
				void insertarNodo();
				void insertarNodo();
				void insertarNodo();
				void insertarNodo();
				cout<<"\n lista primero al ultimo"<<endl;
				
				cout<<"\n lista ultimo al primero"<<endl;
				break;
				
			case 7:
				 printf("Inserte para agregar la primera cola: ");
			                scanf("%d", &dato);
				            insertarCola(frente,fin,dato);
					        break;
			
			case 8:
				printf("Inserte para agregar la segunda cola: ");
			                scanf("%d", &dato1);
			             	insertarCola(frente,fin,dato1);
	                        break;
	                        
	        case 9:
	        	printf("\nMostrar y Eliminar los elementos de la cola: ");
			                 while(frente != NULL){
				                 suprimirCola(frente,fin,dato2);
				                  if(frente != NULL){
				                    	cout<<dato<<" , ";
				                }
				                 else{
					                  cout<<dato1<<" . "; 
				                 }
			                 }
			
			                  system("pause");
			                  break;
		} 
		system("cls");
	}while(opc !=10);
}


void insertarLista(Nodo *&lista, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	
	while((aux1 != NULL ) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if (lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	
	nuevo_nodo->siguiente = aux1;
	
	cout<<"\tElemento "<<n<<" insertado en la lista correctamente\n"<<endl;
}


void mostrarLista(Nodo*){
	Nodo *actual = new Nodo();
	actual = lista;


while (actual != NULL){
	cout<<actual->dato<<" -> ";
	actual = actual->siguiente;
     }
}


void buscarLista(Nodo *lista, int n){
	bool band = false;
	
	Nodo *actual = new Nodo();
	actual = lista;
	
	while ((actual != NULL) && (actual->dato <= n)){
		if (actual->dato == n){
			band = true;
		}
		actual = actual->siguiente;
	}
	
	if(band == true){
		cout<<" Elemento "<<n<<" fue encontrado en la lista"<<endl;
	}
	else{
		cout<<"Elemento "<<n<<" no fue encontrado en lista"<<endl;
	}
}


void eliminarNodo(Nodo *&lista, int n){
	if (lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		
		aux_borrar = lista;
		
		while ((aux_borrar != NULL) && (aux_borrar->dato != n)){
			anterior = aux_borrar;
			aux_borrar->siguiente;
		}
		
		if(aux_borrar == NULL){
			cout<<"El elemento no ha sido encontrado"<<endl;
		}
		else if (anterior == NULL){
			lista = lista->siguiente;
			delete aux_borrar;
		}
		else{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
		
	}
}


void eliminarLista(Nodo *&lista, int &n){
	Nodo *aux = lista;
	n = aux->dato;
	lista = aux->siguiente;
	delete aux;
}

void insertarNodo(){
	Nodo* nuevo = new Nodo();
	cout<<"Ingrese el dato que tendra el nodo"<<endl;
	cin>> nuevo->dato;
	
	if (primero == NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		primero->atras = NULL;
		ultimo = primero;
	}
	else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->atras = ultimo;
		ultimo = nuevo;
	}
	cout<<" Nodo ingresado"<<endl;
}


void deplegarListaPU(){
	
	Nodo *actual = new Nodo();
		actual = primero;
		if (primero != NULL){
			
			while(actual != NULL){
				cout<<"\n"<< actual->dato;
				actual = actual->siguiente;
			}
		}
		else{
			cout<<"La lista esta vacia"<<endl;
		}
		
	}



void deplegarListaUP(){
	
	Nodo *actual = new Nodo();
		actual = ultimo;
		if (primero != NULL){
			
			while(actual != NULL){
				cout<<"\n"<< actual->dato;
				actual = actual->atras;
			}
		}
		else{
			cout<<"La lista esta vacia"<<endl;
		}
		
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
	n = frente->dato;
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
