#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <string>
#include <clocale>
#include <windows.h>
#include <ctype.h>
using namespace std;


//estructuras
struct postres{
	char postre[100];
	struct postres *ligaizq;
	struct postres *ligader;
	struct ingredientes *receta;
};

struct ingredientes{
	char ingrediente[100];
	char cantidad [100];
	struct ingredientes *ligader;
	struct ingredientes *ligaizq;
};



//prototipos
typedef struct postres nodo;
typedef struct ingredientes nodoi;
void *newMemoria(int n);
nodo *newNodo();
nodo *newPostre();
nodo *freeMemory(nodo *p);

//variables globales




void *crearmemoria(int n){
	void *p=(int *)malloc(n);
	if (p==NULL){
		printf("ERROR! No hay memoria disponible.\n");
		getchar();
		exit(1);
	}
	return p;
}

nodo *crearnodo(){
	return (nodo *)crearmemoria(sizeof(nodo));
}
