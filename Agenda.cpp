#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <string>
#include <clocale>
#include <windows.h>
#include <ctype.h>
using namespace std;


//structura
struct datos{
	char *nombre[30];
	char *apellido[30];
	char *telefono[8];
	struct datos *ligaizq;
	struct datos *ligader;
};

//prototipos
typedef struct datos nodo;
void *newMemory(int n);
nodo *newNodo();
void *newContacto();
nodo *freeMemory(nodo *p);
int longitudCadena(char cadena[]);
void mayuscula(char cadena1[], char cadena2[]);
void conversion(char cadena1[]);
nodo* organizar(nodo *p, nodo *q);
void mostrarContactos();
void mostrarContactosOrganizado(nodo *filtro);
void guardarContactos(nodo *p, char archivo[]);
nodo *cargarContactos(nodo *p, char archivo[]);
nodo *busquedaNombre(nodo *p, char dato[]);
nodo *busquedaApellido(nodo *p, char dato[]);
nodo *busquedaTelefono(nodo *p, char dato[]);
nodo *eliminarContacto(nodo *p, nodo *e);
bool buscarContacto(nodo *p, char n[], char a[]);
int menuInicial();
int buscarMenu();

//variables globales
nodo *primero=NULL;
nodo *ultimo=NULL;
nodo *filtro=NULL;
nodo *eliminar=NULL;

int main(){
	char archivo[10]={'a', 'g', 'e', 'n', 'd', 'a'};
	char dato[30], n[30], a[30];
	FILE *fp;
	int opc, opc1;
	nodo *q;
	system("cls");
	do{
	opc=menuInicial();
	switch (opc){
		case 1:
			newContacto();
			 system("pause");
		break;
		case 2:
			mostrarContactos();
			 system("pause");
		break;
		case 3:
			opc1=buscarMenu();
			switch(opc1){
				case 1:
					 printf("\nBuscar Contacto");
					 printf("\n Nombre: ");
					scanf("%s", &dato);
					fflush(stdin);
					conversion(dato);
					busquedaNombre(primero, dato);
					mostrarContactosOrganizado(filtro);
					filtro=freeMemory(filtro);
					system("pause");
				break;
				case 2:
					 printf("\nBuscar contacto");
					 printf("\n Apellido: ");
					scanf("%s", &dato);
					fflush(stdin);
					conversion(dato);
					busquedaApellido(primero, dato);
					mostrarContactosOrganizado(filtro);
					filtro=freeMemory(filtro);
					 system("pause");
				break;
				case 3:
					 printf("\nBuscar Contacto");
					 printf("\n Telefono/Celular: ");
					scanf("%s", &dato);
					fflush(stdin);
					conversion(dato);
					busquedaTelefono(primero, dato);
					mostrarContactosOrganizado(filtro);
					filtro=freeMemory(filtro);
					 system("pause");
				break;
				case 0:
				break;
				default:
				break;
			}
		break;
		case 4:
			 printf("\nBorrar Contacto");
			if(primero!=NULL){
			 printf("\n Nombre: ");
			scanf("%s", &n);
			conversion(n);
			fflush(stdin);
		printf("\n Apellido: ");
			scanf("%s", &a);
			conversion(a);
			fflush(stdin);
				if (buscarContacto(primero, n, a)){
					primero=eliminarContacto(primero, eliminar);
				 printf("\n Se ha borrado el contacto");
				 system("pause");
					eliminar=NULL;
				}
				else{
					 printf("\n Contacto no agendado, intenta de nuevo");
					 system("pause");
				}
			}
			else{
					 printf("\n No tienes contactos, intenta de nuevo");
					 system("pause");
			}
		break;
		case 5:
			guardarContactos(primero, archivo);
		break;
		case 6:
			primero=cargarContactos(primero, archivo);
			q=primero;
			do{
				q=q->ligader;
			}while(q->ligader!=NULL);
			ultimo=q;
		break;
		case 7:
		printf("\nLiberando memoria...");
		primero=freeMemory(primero);
		printf("\nSe ha liberado la memoria \n");	
		 system("pause");
		break;
		default:
		break;
	}
	system("cls");
	}while(opc!=0);
}

void *crearmemoria(int n){
	void *p=(int *)malloc(n);
	if (p==NULL){
		printf("No tienes memoria disponible, Intenta de nuevo\n");
		getchar();
		exit(1);
	}
	return(p);
}


void mostrarContactos(){
	nodo *p=primero;	
	printf("\nLista de Contactos");
	printf("\nNombre");
	printf("\nApellido");
	printf("\nTelefono/Celular");
	if (p!=NULL){
	do{
	printf("\n%s", p->nombre);
	printf("\n%s", p->apellido);
    printf("\n%s", p->telefono);
		p=p->ligader;
	}while(p!=NULL);
	}
	else{
	 printf("\n No tienes contactos, Intentalo de nuevo");
	}
}

int menuInicial(){
	int opc;
	printf("\n \t \t \t Agenda para el Profesor Pino");
	printf("\n1. Agregar contacto.");
	printf("\n2. Mostrar contactos.");
	printf("\n3. Buscar contacto.");
	printf("\n4. Eliminar contacto.");
	printf("\n5. Guardar contactos.");
	printf("\n6. Cargar contactos.");
	printf("\n7. Liberar memoria.");
	printf("\n0. Salir.");
	printf("\nOpcion a elegir: ");
	scanf("%d", &opc);
	fflush(stdin);
	return opc;
}

int buscarMenu(){
	int opc;
	 printf("BUSCAR");
	if(primero!=NULL){
     printf("\n1. Buscar nombre.");
	 printf("\n2. Buscar apellido.");
	 printf("\n3. Buscar telefono.");
	 printf("\n0. Volver");
	 printf("\nOpcion a elegir: ");
	scanf("%d", &opc);
	fflush(stdin);
	return opc;
	}
	else{
		printf("\nNo tienes contactos guardados.");
		system("pause");
	}
}


nodo *crearnodo(){
	return (nodo*)crearmemoria(sizeof(nodo));
}

int longitud_cadena(char cadena[]){
	int i;
	for(i=0; cadena[i]!=0; ++i);
	return i;
}

void mayuscula(char cadena1[], char cadena2[]){
	int i;
	for (i=0; cadena1[i]!=0; ++i){
		cadena1[i]=toupper(cadena1[i]);
	}
	for (i=0; cadena2[i]!=0; ++i){
		cadena2[i]=toupper(cadena2[i]);
	}
	return;
}

void conversion(char cadena1[]){
	int i;
	for (i=0; cadena1[i]!=0; ++i){
		cadena1[i]=toupper(cadena1[i]);
	}
	return;
}

void *newContacto(){	 
	nodo *aux, *aux1, *aux2, *temp, *q;
	int banda=1;
	printf("\nCREA UN CONTACTO");
	aux=crearnodo();
	printf("\n Nombre: ");
	scanf("%s",&aux->nombre);
	fflush(stdin);
	printf("\n Apellido: ");
	scanf("%s",&aux->apellido);
	fflush(stdin);
	printf("\n Telefono/Celular: ");
 	scanf("%s",&aux->telefono);
	fflush(stdin);
	aux->ligader=NULL;
	aux->ligaizq=NULL;
	mayuscula((char*)aux->nombre, (char*)aux->apellido);
	if (primero==NULL){ 
		primero=aux;
		ultimo=aux;
		temp=aux;
	}
	else if((strncmp((const char*)aux->nombre, (const char*)primero->nombre, longitud_cadena((char*)aux->nombre))) < 0){
		aux->ligader=primero;
		primero->ligaizq=aux;
		if(primero->ligader==NULL){
		   ultimo=primero;
		}
		primero=aux;
	}
	else if (primero->ligader==NULL){ 
		ultimo->ligader=aux;
		ultimo->ligaizq=temp;
		ultimo=aux;
		ultimo->ligader=NULL;
		temp=ultimo;
		}
	else{
		banda=1;
		for(aux1=primero; aux1->ligader!=NULL; aux1=aux1->ligader){
			aux2=aux1->ligader;
			if(((strncmp((const char*)aux1->nombre, (const char*)aux->nombre, longitud_cadena((char*)aux->nombre))) < 0) && ((strncmp((const char*)aux->nombre, (const char*)aux2->nombre, longitud_cadena((char*)aux->nombre))) < 0) ){ 
			aux1->ligader=aux;
			aux->ligader=aux2;
			aux->ligaizq=aux1;
			aux2->ligaizq=aux;
			banda=0;
			}
		}
		if(banda==1){
			aux1->ligader=aux;
			aux->ligaizq=aux1;
			aux->ligader=NULL;
		}
		q=primero;
		do{
			q=q->ligader;
		}while(q->ligader!=NULL);
		ultimo=q;
	}
	printf("\n Contacto agendado\n\n");
}  


void guardarContactos(nodo *p, char archivo[]){
	nodo *q=p;
	FILE *fp;
	printf("\n Guardar contactos");
	if(primero==NULL){
           printf("\n Tu lista esta vacia, no se puede guardar, intenta de nuevo. ");
		   system("pause");
	}
	else{
	if ((fp=fopen(archivo,"wb"))==NULL)
	 {
	 	printf("\n El siguiente archivo no se puede guardar: %s",archivo);
	 	exit(1);
	}
	 while (q!=NULL)
	 {
	 fwrite(q, sizeof(nodo),1,fp);
	 q=q->ligader;
	 }
	 fclose(fp);
	}	
}

nodo *busquedaNombre(nodo *p, char dato[]){
	nodo *q;
	q=p;
	do{
		if(strncmp((const char*)q->nombre, dato, longitud_cadena((char*)q->nombre)) ==0){
			organizar(q, filtro);
		}
		q=q->ligader;
	}while(q!=NULL);
	if(filtro==NULL){
	printf("\n (%s) no ha sido agendado", dato);
	}
	else{
	printf("\n (%s) esta agendado", dato);
	}
}

nodo *cargarContactos(nodo *p, char archivo[]){
	nodo *q, *t, *aux1;
	int i, op, e;
	FILE *fp;
	 printf("Cargar contactos");
	if ((fp=fopen(archivo,"rb"))==NULL){
	  printf("\nNo se encontro el siguiente archivo: %s",archivo);
	     e=0;
	 }
	 if (e!=0){
	 	printf("\n Se estan cargando los contactos del archivo.");
	 	printf("\nPara continuar escriba 0: ");
	 	scanf("%d",&op);
	 	fflush(stdin);
	 	if (op==1){
	 		while(p!=NULL){
	 			q=p;
	 			p=p->ligader;
	 			free(q);
			 }
		p=crearnodo();
		q=p;	 
		while (!feof(fp)){
		 if (1!=fread(q,sizeof(nodo),1,fp))	break;
		   q->ligader=crearnodo();
		   t=q;
		   q=q->ligader;
		}	 
		 t->ligader=NULL;
		 free(q);
		 fclose(fp);	 
		 }
	 }
	 return(p);
}

nodo *eliminarContacto(nodo *p, nodo *e){
	nodo *aux1, *aux2, *temp;
	aux1=p;
	if(e==primero){
		aux1=aux1->ligader;
		free(e);
		aux1->ligaizq=NULL;
		primero=aux1;
	}
	else if(e==ultimo){ 
		temp=p;
		while(temp->ligader!=ultimo){
			temp=temp->ligader;
		}
		free (e);
		ultimo=temp;
		ultimo->ligader=NULL;
	}
	else{
	while(temp!=e){ 
		temp=aux1->ligader;
		aux2=temp->ligader;
		if(temp!=e){
		aux1=aux1->ligader;
		}
	}
	aux1->ligader=aux2;
	aux2->ligaizq=aux1;
	free(e);
	}
	return(primero);
}

nodo *busquedaApellido(nodo *p, char dato[]){
	nodo *q;
	q=p;
	do{
		if(strncmp((const char*)q->apellido, dato, longitud_cadena((char*)q->apellido)) ==0){
			organizar(q, filtro);
		}
		q=q->ligader;
	}while(q!=NULL);
	if (filtro==NULL){
	    printf("\n (%s) no ha sido agendado", dato);
	}
	else{
		printf("\n (%s) esta agendado", dato);
	}
}

nodo *busquedaTelefono(nodo *p, char dato[]){
	nodo *q;
	q=p;
	do{
		if(strncmp((const char*)q->telefono, dato, longitud_cadena((char*)q->telefono)) ==0){
			organizar(q, filtro);
		}
		q=q->ligader;
	}while(q!=NULL);
	if (filtro==NULL){
	    printf("\n (%s) no ha sido agendado", dato);
	}
	else{
		printf("\n (%s) esta agendado", dato);
}
}
void mostrarContactosOrganizado(nodo *filtro){
	nodo *p=filtro;
	printf("\n Contactos");
	printf("Nombre");
	printf("Apellido");
	printf("Telefono/Celular");
	if (p!=NULL){
	do{
		printf("%s", p->nombre);
		printf("%s", p->apellido);
		printf("%s", p->telefono);
		p=p->ligader;
	}while(p!=NULL);
	}
	else{
	printf("\n No tienes contactos");
	}
}

nodo *organizar(nodo *p, nodo *q){
	nodo *aux=p, *aux1, *temp;
	if(filtro==NULL){
		filtro=crearnodo();
		strcpy((char*)filtro->nombre, (const char*)aux->nombre);
		strcpy((char*)filtro->apellido, (const char*)aux->apellido);
		strcpy((char*)filtro->telefono, (const char*)aux->telefono);
		filtro->ligader=NULL;
		filtro->ligaizq=NULL;
		aux1=filtro;
	}
	else{
		temp=crearnodo();
		strcpy((char*)temp->nombre, (const char*)aux->nombre);
		strcpy((char*)temp->apellido, (const char*)aux->apellido);
		strcpy((char*)temp->telefono, (const char*)aux->telefono);
		temp->ligaizq=aux1;
		temp->ligader=NULL;
		aux1->ligader=temp;
		aux1=temp;
	}
}



bool buscarContacto(nodo *p, char n[], char a[]){
	nodo *q=p;
	if (strncmp((const char*)q->nombre, n, longitud_cadena((char*)q->nombre))==0 && strncmp((const char*)q->apellido, a, longitud_cadena((char*)q->apellido)) ==0){ 
		eliminar=q;
		return true;
	}
	else{
	do{ 
		q=q->ligader;
	}while((q!=NULL) && (strncmp((const char*)q->nombre, n, longitud_cadena((char*)q->nombre)) !=0 || strncmp((const char*)q->apellido, a, longitud_cadena((char*)q->apellido)) !=0));
	if(q==NULL || (strncmp((const char*)q->nombre, n, longitud_cadena((char*)q->nombre))!=0 || strncmp((const char*)q->apellido, a, longitud_cadena((char*)q->apellido))!=0 )){
		return false;
	}
	else if((strncmp((const char*)q->nombre, n, longitud_cadena((char*)q->nombre)) == 0) && (strncmp((const char*)q->apellido, a, longitud_cadena((char*)q->apellido)) == 0)){
		eliminar=q;
		return true;
	}
	}
}


nodo *freeMemory(nodo *p){
	nodo *q=NULL;
	while( p!=NULL){
		q=p;
		p=p->ligader;
		free(q);
	}
	return(p);
}
