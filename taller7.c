#include <stdio.h>
#include <stdlib.h>



#define TAMANO 7
#define edadMin 10 
#define edadMax 65

#define pesoMin 50.0f
#define pesoMax 100.0f

char *nombres[TAMANO] = {"Jose Perez","Maria Garcia","Ana Andrade", "Julio Como", "Julia Rodriguez", "Antonio Aguilar", "Diana Marcel" };


typedef struct personaTDA{
	int edad;
	int peso;
	char *nombre;
	struct listaHijosTDA *hijos;
}Persona;

typedef struct listaHijosTDA{
	Persona *per;
	struct listaHijosTDA *siguiente;
}ListaHijos;




Persona *crearPersona(char *nombre, int edad, float peso){

	//solucion problema 1:inicializar puntero
	Persona *nuevo=(Persona *)malloc(sizeof(Persona));
	if(nuevo == NULL){
			return NULL;		
		}

	//fin solucion
	nuevo->nombre = nombre;
	nuevo->edad = edad;
	nuevo->peso = peso;

	

	nuevo->hijos = NULL;
	//solucion problema 2 : no retornando direccion de memoria de variable local
	return nuevo;		
	//fin solucion			
}


int anadirHijo(Persona *padre, Persona *hijo){
	
	ListaHijos *lista_hijos = padre->hijos;

	if(lista_hijos == NULL){
		ListaHijos *lista = (ListaHijos *)malloc(sizeof(ListaHijos));
		if(lista == NULL){
			return -1;		
		}
		lista->per = hijo;
		lista->siguiente = NULL;
		padre->hijos = lista;
		return 0;
	}

	else{
		while(lista_hijos != NULL){
		
			if(lista_hijos->siguiente == NULL){
				break;
			}
			lista_hijos = lista_hijos->siguiente;
		}

					
		ListaHijos *nuevo = (ListaHijos *)malloc(sizeof(ListaHijos));
		if(nuevo == NULL){
			return -1;		
		}
		nuevo->per = hijo;
		//solucion problema 4: el puntero siguiente del puntero nuevo debe apuntar a nulo no a si mismo
		nuevo->siguiente =NULL;
		//fin solucion
		lista_hijos->siguiente = nuevo;
		return 0;	
		
	}
	return -1;
}

void mostrarInfoPersona(Persona *persona){
	if(persona != NULL){
		printf("Nombre: %s\nPeso: %d kg\nEdad: %d\n",persona->nombre, persona->peso, persona->edad);
		if(persona->hijos == NULL){
			printf("Hijos: esta persona no tiene hijos\n");
			return;
		}
		else{
			ListaHijos *lista_hijos = persona->hijos;
			printf("Los hijos de %s son:\n", persona->nombre);

			while(lista_hijos != NULL){
				printf("- %s\n", lista_hijos->per->nombre);	
				lista_hijos = lista_hijos->siguiente;		
			}
		}
	}
}


int main(void){

	Persona *listaPersona[TAMANO];

	int i = 0;
	//solucion problema 5 : quitar el = en la condicion del for del forma que solo acceda a los 7 elementos del arreglo y no a los 7 e intente acceder a
	//otra direccion fuera del array.
	for(i = 0; i < TAMANO; i++){			
		//fin solucion
		int edad = edadMin + rand() / (RAND_MAX / (edadMax - edadMin + 1) + 1);
		int peso = pesoMin + rand() / (RAND_MAX / (pesoMax - pesoMin + 1) + 1);

		//solucion 3: asignando lo que retorna la funcion crear persona en el array listaPersona
		listaPersona[i]=crearPersona(nombres[i],  edad, peso);
		//fin solucion

	}


	anadirHijo(listaPersona[0], listaPersona[1]);
	anadirHijo(listaPersona[3], listaPersona[2]);
	anadirHijo(listaPersona[3], listaPersona[6]);
	anadirHijo(listaPersona[4], listaPersona[5]);

	

	
	for(i = 0; i < TAMANO; i++){			

		mostrarInfoPersona(listaPersona[i]);
		printf("\n");

	}

	

}


