#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <string>
#include <clocale>
#include <windows.h>
#include <ctype.h>
using namespace std;


void gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}
void barra_cargando(int x, int y){
	gotoxy (40,28), printf("Cargando...");
	for (x=50; x<100 ; x++){
		gotoxy (x,28), printf("%c",219);
		Sleep(15);
	}
}
class cuadro{
	int x, y;
	public:
	cuadro(int _x, int _y):x(_x), y(_y){}
	int X(){return x;}
	int Y(){return y;}
	void cuadrop();
	void encabezado();
	void borrarpantalla();
	};	
void cuadro::cuadrop(){
	for(x=39;x<=102;x++){
	gotoxy(x,1);	printf("%c",205);
	gotoxy(x,29);	printf("%c",205);
	gotoxy(38,1); printf("%c",201);
	gotoxy(103,1); printf("%c",187);
	}
	for(y=2;y<=28;y++){
	gotoxy(38,y); printf("%c",186);
	gotoxy(103,y); printf("%c",186);
	gotoxy(38,29); printf("%c",200);
	gotoxy(103,29); printf("%c",188);
	}
}
void cuadro::borrarpantalla(){
		for(y=2; y<29; y++){
			gotoxy(39,y);printf("                                                               ");
			}
		fflush(stdin);
}

struct datos{
	char *nombre[30];
	char *apellido[30];
	char *telefono[8];
	struct datos *ligaizq;
	struct datos *ligader;
};

typedef struct datos nodo;
void *crearmemoria(int n);
nodo *crearnodo();
void *crearcontacto();
nodo *liberarmemoria(nodo *p);
int longitud_cadena(char cadena[]);
void conversion_mayuscula(char cadena1[], char cadena2[]);
void conversion(char cadena1[]);
nodo* crearfiltro(nodo *p, nodo *q);
void mostrarcontactos();
void mostrarcontactos_filtro(nodo *filtro);
void guardarcontactos(nodo *p, char archivo[]);
nodo *cargarcontactos(nodo *p, char archivo[]);
nodo *busqueda_nombre(nodo *p, char dato[]);
nodo *busqueda_apellido(nodo *p, char dato[]);
nodo *busqueda_telefono(nodo *p, char dato[]);
nodo *eliminarcontacto(nodo *p, nodo *e);
bool buscarcontacto(nodo *p, char n[], char a[]);
int menuprincipal();
int menubuscar();
void acercade();

nodo *primero=NULL;
nodo *ultimo=NULL;
nodo *filtro=NULL;
nodo *eliminar=NULL;

int main(){
	char archivo[10]={'c', 'o', 'n', 't', 'a', 'c', 't', 'o', 's'};
	char dato[30], n[30], a[30];
	FILE *fp;
	int opc, opc1, x, y;
	nodo *q;
	cuadro cuadrop(x, y);
	cuadrop.cuadrop();
	barra_cargando(x,y);
	system("cls");
	do{
	opc=menuprincipal();
	cuadrop.borrarpantalla();
	switch (opc){
		case 1:
			crearcontacto();
			gotoxy(42, 28); system("pause");
		break;
		case 2:
			mostrarcontactos();
			gotoxy(42, 28); system("pause");
		break;
		case 3:
			opc1=menubuscar();
			switch(opc1){
				case 1:
					cuadrop.borrarpantalla();
					cuadrop.cuadrop();
					gotoxy(10, 2); printf("\t\t\t\t---------------------BUSQUEDA DE CONTACTOS---------------------");
					gotoxy(40, 4); printf("| Ingrese el nombre del contacto: ");
					scanf("%s", &dato);
					fflush(stdin);
					conversion(dato);
					busqueda_nombre(primero, dato);
					mostrarcontactos_filtro(filtro);
					filtro=liberarmemoria(filtro);
					gotoxy(42, 28); system("pause");
				break;
				case 2:
					cuadrop.borrarpantalla();
					cuadrop.cuadrop();
					gotoxy(10, 2); printf("\t\t\t\t---------------------BUSQUEDA DE CONTACTOS---------------------");
					gotoxy(40, 4); printf("| Ingrese el apellido del contacto: ");
					scanf("%s", &dato);
					fflush(stdin);
					conversion(dato);
					busqueda_apellido(primero, dato);
					mostrarcontactos_filtro(filtro);
					filtro=liberarmemoria(filtro);
					gotoxy(42, 28); system("pause");
				break;
				case 3:
					cuadrop.borrarpantalla();
					cuadrop.cuadrop();
					gotoxy(10, 2); printf("\t\t\t\t---------------------BUSQUEDA DE CONTACTOS---------------------");
					gotoxy(40, 4); printf("| Ingrese el telefono del contacto: ");
					scanf("%s", &dato);
					fflush(stdin);
					conversion(dato);
					busqueda_telefono(primero, dato);
					mostrarcontactos_filtro(filtro);
					filtro=liberarmemoria(filtro);
					gotoxy(42, 28); system("pause");
				break;
				case 0:
				break;
				default:
				break;
			}
		break;
		case 4:
			gotoxy(10, 2); printf("\t\t\t\t---------------------ELIMINAR CONTACTO---------------------");
			if(primero!=NULL){
			gotoxy(40, 4); printf("| Ingrese el nombre del contacto: ");
			scanf("%s", &n);
			conversion(n);
			fflush(stdin);
			gotoxy(40, 5); printf("| Ingrese el apellido del contacto: ");
			scanf("%s", &a);
			conversion(a);
			fflush(stdin);
				if (buscarcontacto(primero, n, a)){
					primero=eliminarcontacto(primero, eliminar);
					gotoxy(40, 27); printf("| Contacto eliminado correctamente.");
					gotoxy(42, 28); system("pause");
					eliminar=NULL;
				}
				else{
					gotoxy(40, 6); printf("| El contacto ingresado no existe.");
					gotoxy(42, 28); system("pause");
				}
			}
			else{
					gotoxy(40, 4); printf("| La lista de contactos esta vacia.");
					gotoxy(42, 28); system("pause");
			}
		break;
		case 5:
			guardarcontactos(primero, archivo);
		break;
		case 6:
			primero=cargarcontactos(primero, archivo);
			q=primero;
			do{
				q=q->ligader;
			}while(q->ligader!=NULL);
			ultimo=q;
		break;
		case 7:
			acercade();
			gotoxy(40, 28); system("pause");
		break;
		case 8:
		gotoxy(8, 2); printf("\t\t\t\t-----------------------LIBERAR MEMORIA-----------------------");
		primero=liberarmemoria(primero);
		gotoxy(40, 4); printf("| La memoria ha sido liberada con exito. \n");	
		gotoxy(42, 28); system("pause");
		break;
		default:
		break;
	}
	system("cls");
	}while(opc!=0);
}

int menuprincipal(){
	int opc, x, y;
	cuadro cuadrop(x, y);
	cuadrop.cuadrop();
	gotoxy(10, 2); printf("\t\t\t\t---------------------AGENDA DE CONTACTOS----------------------");
	gotoxy(40, 4); printf("| 1. Agregar contacto.");
	gotoxy(40, 5); printf("| 2. Mostrar contactos.");
	gotoxy(40, 6); printf("| 3. Buscar contacto.");
	gotoxy(40, 7); printf("| 4. Eliminar contacto.");
	gotoxy(40, 8); printf("| 5. Guardar contactos.");
	gotoxy(40, 9); printf("| 6. Cargar contactos.");
	gotoxy(40, 10); printf("| 7. Acerca de.");
	gotoxy(40, 11); printf("| 8. Liberar memoria.");
	gotoxy(40, 12); printf("| 0. Salir.");
	gotoxy(40, 13); printf("| Seleccion una opcion: ");
	scanf("%d", &opc);
	fflush(stdin);
	return opc;
}

int menubuscar(){
	int opc, x, y;
	cuadro cuadrop(x, y);
	cuadrop.cuadrop();
	gotoxy(10, 2); printf("\t\t\t\t---------------------BUSQUEDA DE CONTACTOS----------------------");
	if(primero!=NULL){
	gotoxy(40, 4); printf("| 1. Buscar por nombre.");
	gotoxy(40, 5); printf("| 2. Buscar por apellido.");
	gotoxy(40, 6); printf("| 3. Buscar por telefono.");
	gotoxy(40, 7); printf("| 0. Atras.");
	gotoxy(40, 8); printf("| Seleccion una opcion: ");
	scanf("%d", &opc);
	fflush(stdin);
	return opc;
	}
	else{
		gotoxy(40, 4); printf("| La lista de contactos esta vacia.");
		gotoxy(42, 28); system("pause");
	}
}

nodo *liberarmemoria(nodo *p){
	nodo *q=NULL;
	while( p!=NULL){
		q=p;
		p=p->ligader;
		free(q);
	}
	return(p);
}

void *crearmemoria(int n){
	void *p=(int *)malloc(n);
	if (p==NULL){
		printf("ERROR! No hay memoria disponible.\n");
		getchar();
		exit(1);
	}
	return(p);
}

nodo *crearnodo(){
	return (nodo*)crearmemoria(sizeof(nodo));
}

int longitud_cadena(char cadena[]){
	int i;
	for(i=0; cadena[i]!=0; ++i);
	return i;
}

void conversion_mayuscula(char cadena1[], char cadena2[]){
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

void *crearcontacto(){	 
	nodo *aux, *aux1, *aux2, *temp, *q;
	int banda=1;
	gotoxy(10, 2); printf("\t\t\t\t----------------------CREAR CONTACTOS-----------------------");
	aux=crearnodo();
	gotoxy(40, 4); printf("| Ingrese el nombre del contacto: ");
	scanf("%s",&aux->nombre);
	fflush(stdin);
	gotoxy(40, 6); printf("| Ingrese el apellido del contacto: ");
	scanf("%s",&aux->apellido);
	fflush(stdin);
	gotoxy(40, 8); printf("| Ingrese el telefono del contacto: ");
 	scanf("%s",&aux->telefono);
	fflush(stdin);
	aux->ligader=NULL;
	aux->ligaizq=NULL;
	conversion_mayuscula((char*)aux->nombre, (char*)aux->apellido);
	if (primero==NULL){ //primero
		primero=aux;
		ultimo=aux;
		temp=aux;
	}
	else if((strncmp((const char*)aux->nombre, (const char*)primero->nombre, longitud_cadena((char*)aux->nombre))) < 0){ //primero
		aux->ligader=primero;
		primero->ligaizq=aux;
		if(primero->ligader==NULL){
		   ultimo=primero;
		}
		primero=aux;
	}
	else if (primero->ligader==NULL){ //ultimo
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
	gotoxy(40, 10); printf("| Contacto agregado exitosamente.\n\n");
}  

void mostrarcontactos(){
	nodo *p=primero;
	int x, y=6;	
	gotoxy(8, 2); printf("\t\t\t\t-----------------------MOSTRAR CONTACTOS----------------------");
	gotoxy(40, 4); printf("NOMBRE");
	gotoxy(67, 4); printf("APELLIDO");
	gotoxy(94, 4); printf("TELEFONO");
	if (p!=NULL){
	do{
		gotoxy(40, y); printf("%s", p->nombre);
		gotoxy(67, y); printf("%s", p->apellido);
		gotoxy(94, y); printf("%s", p->telefono);
		p=p->ligader;
		y=y+2;
	}while(p!=NULL);
	}
	else{
	gotoxy(40, 6); printf("| La lista de contactos esta vacia.");
	}
}

void guardarcontactos(nodo *p, char archivo[]){
	nodo *q=p;
	int y=15, x;
	FILE *fp;
	gotoxy(10, 2); printf("\t\t\t\t----------------------GUARDAR CONTACTOS-----------------------");
	if(primero==NULL){
		gotoxy(40, 10); printf("| ERROR! La lista que intenta guardar esta vacia. ");
		gotoxy(42, 28); system("pause");
	}
	else{
	if ((fp=fopen(archivo,"wb"))==NULL)
	 {
	 	gotoxy(40, 10); printf("| No se puede abrir el archivo: %s",archivo);
	 	exit(1);
	}
	 while (q!=NULL)
	 {
	 //gotoxy(40, 10); printf("| Guardando contactos... \n");
	 fwrite(q, sizeof(nodo),1,fp);
	 q=q->ligader;
	 y=y+1;
	 }
	 //x=0, y=0;
	 barra_cargando(x,y);
	 fclose(fp);
	}	
}

nodo *cargarcontactos(nodo *p, char archivo[]){
	nodo *q, *t, *aux1;
	int i, op, e, x, y;
	FILE *fp;
	gotoxy(10, 2); printf("\t\t\t\t----------------------CARGAR CONTACTOS-----------------------");
	if ((fp=fopen(archivo,"rb"))==NULL){
	 	gotoxy(40, 4); printf("| No existe el archivo: %s",archivo);
	 //	exit(1);
	     e=1;
	 }
	 if (e!=1){
	 	gotoxy(40, 4); printf("| Se cargaran los contactos del archivo.");
	 	gotoxy(40, 5); printf("| Desea continuar presione el numero uno 1: ");
	 	scanf("%d",&op);
	 	fflush(stdin);
	 	if (op==1){
	 		while(p!=NULL){
	 			q=p;
	 			p=p->ligader;
	 			free(q);
			 }
		barra_cargando(x,y);
		//gotoxy(40, 6); printf("| Cargando la lista . . . ");
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

nodo *busqueda_nombre(nodo *p, char dato[]){
	nodo *q;
	q=p;
	do{
		if(strncmp((const char*)q->nombre, dato, longitud_cadena((char*)q->nombre)) ==0){
			crearfiltro(q, filtro);
		}
		q=q->ligader;
	}while(q!=NULL);
	if(filtro==NULL){
	gotoxy(40, 4); printf("| El contacto (%s) NO se encuentra en la lista.", dato);
	}
	else{
	gotoxy(40, 4); printf("| El contacto (%s) SI se encuentra en la lista.", dato);
	}
}

nodo *busqueda_apellido(nodo *p, char dato[]){
	nodo *q;
	q=p;
	do{
		if(strncmp((const char*)q->apellido, dato, longitud_cadena((char*)q->apellido)) ==0){
			crearfiltro(q, filtro);
		}
		q=q->ligader;
	}while(q!=NULL);
	if (filtro==NULL){
	gotoxy(40, 4); printf("| El contacto (%s) NO se encuentra en la lista.", dato);
	}
	else{
	gotoxy(40, 4); printf("| El contacto (%s) SI se encuentra en la lista.", dato);
	}
}

nodo *busqueda_telefono(nodo *p, char dato[]){
	nodo *q;
	q=p;
	do{
		if(strncmp((const char*)q->telefono, dato, longitud_cadena((char*)q->telefono)) ==0){
			crearfiltro(q, filtro);
		}
		q=q->ligader;
	}while(q!=NULL);
	if (filtro==NULL){
	gotoxy(40, 4); printf("| El contacto (%s) NO se encuentra en la lista.", dato);
	}
	else{
	gotoxy(40, 4); printf("| El contacto (%s) SI se encuentra en la lista.", dato);
	}
}

void mostrarcontactos_filtro(nodo *filtro){
	nodo *p=filtro;
	int x, y=7;
	gotoxy(8, 2); printf("\t\t\t\t-----------------------MOSTRAR CONTACTOS----------------------");
	gotoxy(40, 6); printf("NOMBRE");
	gotoxy(67, 6); printf("APELLIDO");
	gotoxy(94, 6); printf("TELEFONO");
	if (p!=NULL){
	do{
		gotoxy(40, y); printf("%s", p->nombre);
		gotoxy(67, y); printf("%s", p->apellido);
		gotoxy(94, y); printf("%s", p->telefono);
		p=p->ligader;
		y=y+2;
	}while(p!=NULL);
	}
	else{
	gotoxy(40, 10); printf("| La lista de contactos esta vacia.");
	}
}

nodo *crearfiltro(nodo *p, nodo *q){
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

nodo *eliminarcontacto(nodo *p, nodo *e){
	nodo *aux1, *aux2, *temp;
	aux1=p;
	if(e==primero){
		aux1=aux1->ligader;
		free(e);
		aux1->ligaizq=NULL;
		primero=aux1;
	}
	else if(e==ultimo){ //ultimo
		temp=p;
		while(temp->ligader!=ultimo){
			temp=temp->ligader;
		}
		free (e);
		ultimo=temp;
		ultimo->ligader=NULL;
	}
	else{
	while(temp!=e){ //cualquiera
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

bool buscarcontacto(nodo *p, char n[], char a[]){
	nodo *q=p;
	if (strncmp((const char*)q->nombre, n, longitud_cadena((char*)q->nombre))==0 && strncmp((const char*)q->apellido, a, longitud_cadena((char*)q->apellido)) ==0){ //primero
		eliminar=q;
		return true;
	}
	else{
	do{ //cualquiera y ultimo
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

void acercade(){
	gotoxy(10, 2); printf("\t\t\t\t-----------------------LIBERAR MEMORIA-----------------------");
	gotoxy(40, 4); printf("| Autor: Kristtian Colina");
	gotoxy(40, 5); printf("| Proyecto: Agenda Telefonica con listas doblemente enlazadas.");
	gotoxy(40, 6); printf("| Universidad de Panama.");
	gotoxy(40, 7); printf("| Facultad de Electronica, Informatica y Comunicacion.");
	gotoxy(40, 8); printf("| Escuela de Ingenieria Informatica.");
	gotoxy(40, 9); printf("| Programacion II.");
	gotoxy(40, 10); printf("| Profesor: Alvaro Pino.");
	gotoxy(40, 11); printf("| Fecha: Julio 2020.");
}

