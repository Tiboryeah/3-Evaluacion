#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <string>

struct atleta{
	int id;
	char nombre[15];
	char nacionalidad[15];
	int medalla;
};

struct Nodo{
	char nombre[15];
	int dato;
	char nacionalidad[15];
	Nodo *der;
	Nodo *izq;
}; 

//Prototipos
Nodo *crearNodo();
void insertarNodo(Nodo *&,Nodo *&,Nodo *&, int, char[],char[],int);
void menu();
bool buscarNodoOro(Nodo *,int,char[],char[]);
bool buscarNodoPlata(Nodo *,int,char[],char[]);
bool buscarNodoBronce(Nodo *,int,char[],char[]);
void mostrarOro(Nodo *,int);
void mostrarPlata(Nodo *,int);
void mostrarBronce(Nodo *,int);
void leerP();

struct atleta agenda,*m1;

Nodo *oro = NULL;
Nodo *plata = NULL;
Nodo *bronce = NULL;

int main(){
	menu();
	free( m1 );
	return 0;
}

//Funcion para mostrar el menu
void menu(){
	int dato,op,cont=0,i=0,medalla=0;
	char nombre[15],nacionalidad[15];
	
	do{
		printf("\t.:MENU:.\n");
		printf("1. Insertar atletas desde un .txt\n");
		printf("2. Buscar un atleta\n");
		printf("3. Recorrer arbol Preorden\n");
		printf("4. Mostrar arbol de Oros\n");
		printf("5. Mostrar arbol de Platas\n");
		printf("6. Mostrar arbol de Bronces\n");
		printf("7. Salir\n");
		printf("Ingresa la opcion deseada\n");
		scanf("%d",&op);
		
		switch(op){
			case 1: leerP();
					
					//Insertar dato al arbol
					for(i=0;i<50;i++){
						dato = int(m1[i].nombre[0]);
						printf("%d\n",dato);
						strcpy(nombre,m1[i].nombre);
						strcpy(nacionalidad,m1[i].nacionalidad);
						medalla = m1[i].medalla;
						insertarNodo(oro,plata,bronce,dato,nombre,nacionalidad,medalla);
					}
					printf("Los elementos se han añadido correctamente\n");
					//system("cls");
					break;
			case 2: printf("Escribe el nombre del atleta que deseas buscar: \n");
					scanf("%s",nombre);
					fflush(stdin);
					dato = int(nombre[0]);
					printf("Escribe el pais de origen del atleta que deseas buscar: \n");
					scanf("%s",nacionalidad);
					fflush(stdin);
					printf("%d\n",dato);
					//printf("%s\n",nombre);
					//printf("%s\n",nacionalidad);
					//Buscar dato en el arbol de oro
					if(buscarNodoOro(oro,dato,nombre,nacionalidad) == true){
						printf("El atleta %s de %s se encuentra y ha ganado una medalla de oro\n",nombre,nacionalidad);
						system("pause");
						system("cls");
						break;
					}else{
						printf("El elemento no esta en el arbol\n");
					}
					if
						(buscarNodoPlata(plata,dato,nombre,nacionalidad) == true){
						printf("El atleta %s de %s se encuentra y ha ganado una medalla de plata\n",nombre,nacionalidad);
						system("pause");
						system("cls");
						break;
						}
					else{
						printf("El elemento no esta en el arbol\n");
					}
					if
							//Buscar dato en el arbol de bronce
						(buscarNodoBronce(bronce,dato,nombre,nacionalidad) == true){
						printf("El atleta %s de %s se encuentra y ha ganado una medalla de bronce\n",nombre,nacionalidad);
						system("pause");
						system("cls");	
						}
					else {
							printf("El elemento no esta en el arbol\n");
							system("pause");
							system("cls");	
							break;
							}
							
						
			case 3:	printf("\n");
					system("pause");
					break;
			case 6: printf("\nArbol de Bronces: \n\n");
					mostrarBronce(bronce,cont);
					printf("\n");
					system("pause");
					break;
			case 5: printf("\nArbol de Platas: \n\n");
					mostrarPlata(plata,cont);
					printf("\n");
					system("pause");
					break;
			case 4: printf("\nArbol de Oros: \n\n");
					mostrarOro(oro,cont);
					printf("\n");
					system("pause");
					break;
			case 7: 
					printf("\n");
					system("pause");
					break;			
		}
		
	}while(op != 8);
	
}
//Funcion crear nodo
Nodo *crearNodo(int n, char nombre[], char nacionalidad[]){
	Nodo *n_nodo = new Nodo();
	
	n_nodo->dato = n;
	strcpy(n_nodo->nombre,nombre);
	strcpy(n_nodo->nacionalidad,nacionalidad);
	n_nodo->der = NULL;
	n_nodo->izq = NULL;
	
	return n_nodo;
}
//Leer datos
void leerP(){
	FILE *archivo;
	//Definir variables, arreglos y punteros a usar
	int cont=0,i=0,c=0,medalla;
	char nom[15],na[15];
	char dir[100]="e.txt",temp[15],caracter,car;
	//Preguntarle al usuario la ruta del archivo y asignarla a un arreglo de caracteres
	printf("Escribe la ruta del archivo que deseas leer o el nombre del archivo (si el ejecutable esta en la misma carpeta)\n");
	scanf("%[^\n]",dir);
	//Abrir el archivo en modo lectura
	archivo = fopen(dir,"rb");
	//Uso de condicional doble para evaluar si el puntero apunta a una direccion de memoria
	if (archivo == NULL){
		system("cls");
		printf("\nError de apertura del archivo. \n\n");
		return ;
	}
	else{
		//Leer el archivo
		printf("Las edades que contiene el archivo son: \n\n");
		//Uso de la funcion rewind para llevar el puntero al inicio del archivo
		rewind(archivo);
		
		while(!feof(archivo)){
			fgets(temp,30,archivo);
			cont++;
		}
		cont=cont-2;
		//Uso de la funcion malloc para determinar el tamaño del arreglo estructurado
		m1=(struct atleta*) malloc(cont*sizeof(agenda));
		if( m1 == NULL ){
		
      		printf( "No hay memoria suficiente\n" );
      		fclose(archivo);
      		return;
      	}
  	 	else
  		{
      		rewind(archivo);
	
			//Leer los datos del archivo y asignarlos a el arerglo estructurado
			printf("%c",'\n');
			while(fscanf(archivo,"%s\t%s\t%d\t",nom,na,&medalla)==3){
			m1[c].id=c+1;	
			strcpy(m1[c].nombre,nom);
			strcpy(m1[c].nacionalidad,na);
			m1[c].medalla=medalla;
			c++	;
			}
			//Cerrar archivo	
			fclose(archivo);	
				
			//Mostrar los puntos añadidos en la terminal
			printf("\nLos productos añadidos son:\n\n");
			for(int x=0; x<cont; x++){
			printf("ID: %d\n",m1[x].id);
			printf("Nombre: %s\n",m1[x].nombre);
			printf("Nacionalidad: %s\n",m1[x].nacionalidad);
			printf("Medalla: %d\n",m1[x].medalla);

			}
			return;
			
  		}			
	}
}
//Funcion para insertar elementos al arbol
void insertarNodo(Nodo *&oro,Nodo *&plata,Nodo *&bronce, int n, char nombre[],char nacionalidad[], int medalla){
	//Si el arbol esta vacio
	if(oro == NULL && medalla ==10){
		//Crear nodo
		Nodo *n_nodo = crearNodo(n,nombre,nacionalidad);
		oro = n_nodo;
	}
	else if(plata == NULL && medalla ==5){
		Nodo *n_nodo = crearNodo(n,nombre,nacionalidad);
		plata = n_nodo;
		
	}else if(bronce == NULL && medalla ==1){
		Nodo *n_nodo = crearNodo(n,nombre,nacionalidad);
		bronce = n_nodo;
		}
	
	//Si no esta vacio el arbol
	else{
		if(medalla ==10){
			int valorR = oro->dato;
			//Si el elemento es menor a la raiz
			if(n < valorR){
			insertarNodo(oro->izq,plata,bronce,n,nombre,nacionalidad,medalla);
			}
			//Si el elemento es mayor a la raiz
			else{
				insertarNodo(oro->der,plata,bronce,n,nombre,nacionalidad,medalla);
			}
		}
		
	else if(medalla == 5){
			int valorR = plata->dato;
			//Si el elemento es menor a la raiz
			if(n < valorR){
			insertarNodo(oro,plata->izq,bronce,n,nombre,nacionalidad,medalla);
			}
			//Si el elemento es mayor a la raiz
			else{
				insertarNodo(oro,plata->der,bronce,n,nombre,nacionalidad,medalla);
			}
		}
		
		else {
			int valorR = bronce->dato;
			//Si el elemento es menor a la raiz
			if(n < valorR){
			insertarNodo(oro,plata,bronce->izq,n,nombre,nacionalidad,medalla);
			}
			//Si el elemento es mayor a la raiz
			else{
				insertarNodo(oro,plata,bronce->der,n,nombre,nacionalidad,medalla);
			}
		}
			
	}
}

//Fundion para buscar un elemento en el arbol
bool buscarNodoOro(Nodo *oro,int n,char nombre[],char nacimiento[]){
	int x1= int(nombre[2]);
	int y1= int(nacimiento[2]); 
	int suma1 = x1+y1;
	int x= int(oro->nacionalidad[2]);
	int y= int(oro->nombre[2]);
	int suma = x+y;
	printf("%d , %d\n",suma1,suma);
	printf("%s\n",oro);
		
	if(oro == NULL){
		printf("%s\n",oro);
		return false;
	}

	else if(suma == suma1){
		return true;
	}
	else if(n < oro->dato){
		return buscarNodoOro(oro->izq,n,nombre,nacimiento);
	}
	else{
		return buscarNodoOro(oro->der,n,nombre,nacimiento);
	}
}
//Fundion para buscar un elemento en el arbol
bool buscarNodoPlata(Nodo *plata,int n,char nombre[],char nacimiento[]){
	int x1= int(nombre[2]);
	int y1= int(nacimiento[2]); 
	int suma1 = x1+y1;
	int x= int(plata->nacionalidad[2]);
	int y= int(plata->nombre[2]);
	int suma = x+y;

	if(plata == NULL){
		return false;
	}

	else if(suma == suma1){
		return true;
	}
	else if(n < plata->dato){
		return buscarNodoPlata(plata->izq,n,nombre,nacimiento);
	}
	else{
		return buscarNodoPlata(plata->der,n,nombre,nacimiento);
	}
}
//Fundion para buscar un elemento en el arbol
bool buscarNodoBronce(Nodo *bronce,int n,char nombre[],char nacimiento[]){
	int x1= int(nombre[2]);
	int y1= int(nacimiento[2]); 
	int suma1 = x1+y1;
	int x= int(bronce->nacionalidad[2]);
	int y= int(bronce->nombre[2]);
	int suma = x+y;

	if(bronce == NULL){
		return false;
	}

	else if(suma == suma1){
		return true;
	}
	else if(n < bronce->dato){
		return buscarNodoBronce(bronce->izq,n,nombre,nacimiento);
		
	}
	else{
		return buscarNodoBronce(bronce->der,n,nombre,nacimiento);
	}

}



//Funcion para mostrar arbol
void mostrarOro(Nodo *oro, int cont){
	int i;
	char a;
	if(oro == NULL){
		return;
	}
	else{
		mostrarOro(oro->der,cont+1);
		for(i=0;i<cont;i++){
			printf("   ");
		}
		a = char(oro->dato);
		printf("%c\n",oro->dato);
		mostrarOro(oro->izq,cont+1);
	}
}
void mostrarPlata(Nodo *plata, int cont){
	int i;
	char a;
	if(plata == NULL){
		return;
	}
	else{
		mostrarPlata(plata->der,cont+1);
		for(i=0;i<cont;i++){
			printf("   ");
		}
		a = char(plata->dato);
		printf("%c\n",plata->dato);
		mostrarPlata(plata->izq,cont+1);
	}
}
void mostrarBronce(Nodo *bronce, int cont){
	int i;
	char a;
	if(bronce == NULL){
		return;
	}
	else{
		mostrarBronce(bronce->der,cont+1);
		for(i=0;i<cont;i++){
			printf("   ");
		}
		a = char(bronce->dato);
		printf("%c\n",bronce->dato);
		mostrarBronce(bronce->izq,cont+1);
	}
}
