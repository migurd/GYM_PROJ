/* 
Hecho por:
Gonzalez Ramirez Jose Manuel
Qui Mora Angel Ernesto
Tirado Romero Juan Jose
*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x,int y);
void menu();
void menuEntrenador();
void menuServicios();
void menuRegistro();
void menuCliente();

void addEntrenador();
void addServicios(int idEntrenador);
void addCliente(int idEntrenador, int idServicio);

void consultarEntrenador();
void consultarEntrenadorGeneral();
void consultarEntrenadorEspecifico();

void modificarEntrenador();

int intcmp(int value, int i, int top, char arr[]);
char yesOrNo(int length);
long nument(int lon);
void valitext(int lon,char *pnom);
void valifec(char *pfecha);
void valiTelefono(char *pnom);

struct entrenador {
	int id;
	char especialidad[13];
	char primerNombre[11];
	char segundoNombre[11];
	char apellidoMaterno[11];
	char apellidoPaterno[11];
	char telefono[11];
//	char direccion[15];
	char turno[11];
} ent[10]; // Usaremos las 3 primeras letras para todas las estructuras

struct servicios {
	int id;
	char* idInstructor;
	char servicio[20];
	char rutina[20];
} ser[10];

struct registro {
	int id;
	char fechaRegistro[11];
	char vigenciaRegistro[11];
} reg[10];

struct cliente {
	int id;
	char primerNombre[10];
	char segundoNombre[10];
	char apellidoMaterno[10];
	char apellidoPaterno[10];
	char telefono[10];
	char direccion[15];
	char turno[11];
	int idRegistro;
	int idServicios;
} cli[10];

int main() {
//	system("COLOR C1");
	menuEntrenador();
	return 0;
}

void menu() {
	int option = 0;
	
	do {
		system("cls");
		gotoxy(40, 5);
		printf("======\tMen%c principal\t======\n\n", 163);
		gotoxy(40, 8);
		printf("1. Men%c entrenador\n", 163);
		gotoxy(40, 9);
		printf("2. Men%c servicios\n", 163);
		gotoxy(40, 10);
		printf("3. Men%c registro\n", 163);
		gotoxy(40, 11);
		printf("4. Men%c cliente\n", 163);
		gotoxy(40, 12);
		printf("5. Salir\n\n\n", 163);
		
		gotoxy(44, 15);
		printf("> > Elige una opci%cn: ", 162);
		option = nument(1);
		
		switch (option) {
			case 1:
				menuEntrenador();
				break;
			case 2:
				menuServicios();
				break;
			case 3:
				menuRegistro();
				break;
			case 4:
				menuCliente();
				break;
			case 5:
				system("cls");
				printf("\n\n\n\n\n\t\t\t\t\t\tCerrando...");
				Sleep(1000);
				break;
			default:
				system("cls");
				printf("\n\n\n\n\n\t\t\t\t\tOpci%cn inv%clida. Elige de nuevo.", 162, 160);
				Sleep(1000);
				break;
		}
	} while (option != 5);
}

void menuEntrenador() {
	int option = 0;
	
	do {
		system("cls");
		gotoxy(40, 5);
		printf("======\tMen%c entrenador\t======", 163);
		gotoxy(40, 8);
		printf("1. Agregar", 163);
		gotoxy(40, 9);
		printf("2. Consultar", 163);
		gotoxy(40, 10);
		printf("3. Modificar", 163);
		gotoxy(40, 11);
		printf("4. Eliminar", 163);
		gotoxy(40, 12);
		printf("5. Regresar", 163);
		
		gotoxy(44, 15);
		printf("> > Elige una opci%cn: ", 162);
		option = nument(1);
		
		switch (option) {
			case 1:
				addEntrenador();
				break;
			case 2:
				consultarEntrenador();
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				break;
			default:
				system("cls");
				printf("Opci%cn inv%clida. Elige de nuevo.", 162, 160);
				Sleep(300);
				break;
		}
	} while (option != 5);
}

void menuServicios() {
	int option = 0;
	
	do {
		
	} while (option != 5);
}

void menuRegistro() {
	
}

void menuCliente() {
	int option = 0;
	
	do {
		
	} while (option != 5);
}

void addEntrenador() {
	FILE *fp;
    char option = 'Y';
    int i;
    system("cls");
    fp = fopen("src/entrenadores.txt", "a");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error abriendo el archivo");
        exit(1);
    }
    fflush(stdin);
    
    while(option == 'Y')
    {
    	for (i = 0; i < 10; i++)
    		if (ent[i].id == NULL)
    			break;
    	if (i < 10)
    	{
	    	gotoxy(15,3);
	        printf("===\t A%cadir entrenador \t===", 164);
	        gotoxy(15,5);
	        printf("Inserta los detalles del entrenador");
	        gotoxy(15,7);
	        printf("ID: ");
	        scanf("%d", &ent[i].id);
	        fflush(stdin);
	        gotoxy(15,8);
	        printf("Especialidad: ");
	        valitext(12, ent[i].especialidad);
	        gotoxy(15,9);
	        printf("Primer nombre: ");
	        valitext(10, ent[i].primerNombre);
			gotoxy(15,10);
	        printf("Segundo nombre: ");
	        valitext(10, ent[i].segundoNombre);
	        gotoxy(15,11);
	        printf("Apellido Paterno: ");
	        valitext(10, ent[i].apellidoPaterno);
	        gotoxy(15,12);
	        printf("Apellido Materno: ");
	        valitext(10, ent[i].apellidoMaterno);
			gotoxy(15,13);
			printf("Tel%cfono: ", 130);
	        valiTelefono(ent[i].telefono);
	        fflush(stdin);
			gotoxy(15,14);
//			printf("Direcci%cn: ", 162);
//	        gets(ent[i].direccion);
//	        gotoxy(15,15);
			printf("Turno: ", 130);
	        valitext(10, ent[i].turno);
	        fwrite(&ent[i], sizeof(ent[i]), 1, fp);
	        gotoxy(15,16);
			printf("%cEntrenador a%cadido exitosamente!", 173, 164);
	        getch();
			gotoxy(15,18);
	        printf("%cDesea a%cadir otro entrenador? (Y / N): ", 168, 164);
	        fflush(stdin);
	        option = yesOrNo(1);
	        system("cls");
	        fflush(stdin);
		}
		else {
			printf("No hay espacio de almacentamiento para m%cs entrenadores. :(", 160);
			getch();
			break;
		}
        
    }
    fclose(fp);
    gotoxy(10,18);
}

void consultarEntrenador() {
	int option = 0;
	
	do {
		system("cls");
		gotoxy(40, 5);
		printf("======\tMen%c entrenador\t======", 163);
		gotoxy(40, 8);
		printf("1. General");
		gotoxy(40, 9);
		printf("2. Espec%cfico", 161);
		gotoxy(40, 10);
		printf("3. Regresar");
		
		gotoxy(44, 15);
		printf("> > Elige una opci%cn: ", 162);
		option = nument(1);
		
		switch (option) {
			case 1:
				consultarEntrenadorGeneral();
				break;
			case 2:
				consultarEntrenadorEspecifico();
				break;
			case 3:
				break;
			default:
				system("cls");
				gotoxy(40, 10);
				printf("Opci%cn inv%clida. Elige de nuevo.", 162, 160);
				Sleep(300);
				break;
		}
	} while (option != 3);
}

void consultarEntrenadorGeneral() {
	FILE *fp;
    int i = 0, j;
    system("cls");
    gotoxy(10,3);
    printf("===\t Consulta General Entrenador \t===");
    gotoxy(10,5);
    printf("ID  Especialidad    P. Nombre   S. Nombre   Apellido P.  Apellido M.  Tel%cfono     Turno", 130, 162);
    gotoxy(10,6);
    printf("____________________________________________________________________________________________");
    fp = fopen("src/entrenadores.txt","rb+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error abriendo el archivo");
        exit(1);
    }
    j=8;
    while(fread(&ent[i], sizeof(ent[i]), 1, fp) == 1){
        gotoxy(10, j);
        printf("%-4d%-16s%-12s%-12s%-13s%-13s%-13s%s", ent[i].id, ent[i].especialidad, ent[i].primerNombre, ent[i].segundoNombre, ent[i].apellidoPaterno, ent[i].apellidoMaterno, ent[i].telefono, ent[i].turno);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10, j+3);
    printf("Presiona cualquier tecla para salir");
    getch();
}

void consultarEntrenadorEspecifico() {
	
}

void modificarEntrenador() {
    system("cls");
    FILE *fp;
	char idEntrenador;
	int i;
    gotoxy(10,3);
    printf("===\t Modificar Entrenador \t===");
    gotoxy(10,5);
    printf("Inserta la ID de entrenador a modificar: ");
    scanf("%i", &idEntrenador);
    fp = fopen("src/entrenadores.txt","rb+");
    if(fp == NULL) {
        gotoxy(10,6);
        printf("Error abriendo el archivo");
        exit(1);
    }
    i = intcmp(idEntrenador, 0, 10, ent[]);
    while(fread(&ent[i], sizeof(ent[i]), 1, fp) == 1)
    {
        if() {
            gotoxy(15,8);
	        printf("Especialidad: ");
	        valitext(12, ent[i].especialidad);
	        gotoxy(15,9);
	        printf("Primer nombre: ");
	        valitext(10, ent[i].primerNombre);
			gotoxy(15,10);
	        printf("Segundo nombre: ");
	        valitext(10, ent[i].segundoNombre);
	        gotoxy(15,11);
	        printf("Apellido Paterno: ");
	        valitext(10, ent[i].apellidoPaterno);
	        gotoxy(15,12);
	        printf("Apellido Materno: ");
	        valitext(10, ent[i].apellidoMaterno);
			gotoxy(15,13);
			printf("Tel%cfono: ", 130);
	        valiTelefono(ent[i].telefono);
	        fflush(stdin);
			gotoxy(15,14);
			printf("Turno: ", 130);
	        valitext(10, ent[i].turno);
	        fwrite(&ent[i], sizeof(ent[i]), 1, fp);
	        gotoxy(15,16);
	        printf("%cDesea guardar los cambios? (Y / N): ", 168);
	        fflush(stdin);
	        option = yesOrNo(1);
			gotoxy(15,18);
			printf("%cEntrenador modificado exitosamente!", 173);
	        getch();
            fseek(fp , -sizeof(ent[i]), SEEK_CUR);
            fwrite(&ent[i], sizeof(ent[i]), 1, fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(15,20);
    printf("Presiona cualquier tecla para salir");
    getch();
}

void addCliente(int idEntrenador, int idServicio) {
	
}

void addservicios() {
	FILE *fp;
	char cd;
	int i;
	if (fp == NULL) {
		gotoxy(10, 5);
		printf("No se pudo abrir el archivo");
		exit(1);
	}
	for (i = 0; i < 10; i++)
		if (ser[i].id==NULL)
			break;
	if (i < 10) {
		do {
			system("cls");
			fp = fopen("./src/Servicios.txt", "a");
			printf("\t\t\t\t\t======\tA%cadir otro servicio\t======\n\n", 164);
			printf("\t\t\t\t\tID: %i", i);
			ser[i].id = i;
			getch();
			printf("\n\t\t\t\t\tServicios: ");
			valitext(15, ser[i].servicio);
			printf("\n\t\t\t\t\tId del Instructor: ");
			valitext(15, ser[i].idInstructor);
			printf("\n\t\t\t\t\tRutina: ");
			valitext(15, ser[i].rutina);
			
			fwrite(&ser, sizeof(struct servicios), 10, fp);
			fclose(fp);
			
			printf("\t\t\t\t\t%cA%cadir otro servicio? (y/n) ", 168, 164);
			scanf("%s", &cd);
		} while(cd == 'y' || cd == 'Y');
	}
}

long nument(int lon) {
	char car, cadena[lon+1]={' '};
	int x=0;
	do{
		car = getch();
		if(car >= 48 && car <= 57){
			printf("%c", car);
			cadena[x]=car;
			x++;
		}
		if(car==8 && x>0){
			printf("\b \b");
			x--;
			cadena[x]=' ';
		}
	}while(car != 13 && x < lon);
	cadena[x]='\n';
	return atoi(cadena);
}

void valitext(int lon,char *pnom){
	int c=0, x=0;
    do{
		c=getch();
        if(c>=65 && c<=90 || c>=97 && c<=122 || c==32 || c==164 || c==165){
			printf("%c",c);
            *(pnom+x)=c;
            x++;
        }
        if(c==8 && x>0){
			x--;
		    printf("\b \b");
	        *(pnom+x)=' ';
        }
    }while(c!=13 && x<lon);
    *(pnom+x)= NULL;
}

void valiTelefono(char *pnom){
	int c=0, x=0;
    do{
		c=getch();
        if(c>=48 && c<=57){
			printf("%c",c);
            *(pnom+x)=c;
            x++;
        }
        if(c==8 && x>0){
			x--;
		    printf("\b \b");
	        *(pnom+x)=' ';
        }
    }while(x<10);
    *(pnom+x)= NULL;
}

void valifec(char *pfecha){
	int dia=0, mes=0, anio=0, x=0, c=0, d=0, m=0, a=0, fec=0, bi=0;
	char diac[2], mesc[2], anioc[4];
	do{
		x=d=m=a=0;
		strcpy(diac,"  ");
		strcpy(mesc,"  ");
		strcpy(anioc,"    ");
		do{
			c=getch();
	    	if(c>=48 && c<=57){
				printf("%c",c);
    			if(x<2){
					diac[d]=c;
        			d++;
        		}
				else if (x<5){
					mesc[m]=c;
					m++;
				}
				else{
					anioc[a]=c;
					a++;
				}
				*(pfecha+x)=c;
    	    	x++;
	    	}
	    	if(x==2 || x==5){
				printf("/");
    	    	*(pfecha+x)='/';
        		x++;        
        	} 
			if(c==8 && x>0){
				x--;
	    		if(x==2){
					printf("\b\b  \b\b");
	    			*(pfecha+x)=' ';
	    			x--;
	    			*(pfecha+x)=' ';
	    			d--;
	    		}
	    		else if(x<2){
					printf("\b \b");
					*(pfecha+x)=' ';
					d--;
				}
	    		else if(x==5){
					printf("\b\b  \b\b");
	    			*(pfecha+x)=' ';
	    			x--;
					*(pfecha+x)=' ';
					m--;
	    		}
	    		else if(x<5){
					printf("\b \b");
					*(pfecha+x)=' ';
					m--;
				}
	    		else if(x>5){
					printf("\b \b");
	    			*(pfecha+x)=' ';
	    			a--;
	    		}
    		}
		}while(x<10);
		dia=atoi(diac);
		mes=atoi(mesc);
		anio=atoi(anioc);
		bi=0;
		if(anio%4==0 && (anio%100!=0 || anio%400==0))
			bi++;
		if(dia<=31 && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && anio>=1900 && anio<=2050)
			fec=1;
		else if(dia<=30 && (mes==4 || mes==6 || mes==9 || mes==11) && anio>=1900 && anio<=2050)
			fec=1;
		else if(dia<=28 && mes==2 && anio>=1900 && anio<=2050)
			fec=1;
		else if(dia==29 && mes==2 && anio>=1900 && anio<=2050 && bi==1)
			fec=1;
		else
			for(int y=1;y<=10;y++)
				printf("\b \b");
	}while(fec!=1);
}

char yesOrNo(int length) {
	char car, option;
	do {
		car = getch();
		option = toupper(car);
		switch (option) {
			case 89:
				printf("%c", option);
				return 'Y';
				break;
			case 78:
				printf("%c", option);
				return 'N';
				break;
			default:
				break;
		} 
	} while(option != 89 || option != 78);
}

int intcmp(int value, int i, int top, char arr[]) {
	// i = length
	for (i = 0; i < top; i++)
		if (value == arr[i])
			return value;
}

void gotoxy(int x,int y) {
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
