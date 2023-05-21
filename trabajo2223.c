#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>

#define ARCHIVO_USUARIOS "usuarios.dat"


/* Estructura de cuentas de usuario */
struct usuario {
	char nombre[80];
	char password[80];
};
typedef struct usuario Usuario;


/* Estructura para los datos de los ficheros*/

struct TAnalisis{
	char nombre[200];
	float ph;
	int conductividad;
	int turbidez;
	int coliformes;
};



/* Funciones que manipulan el archivo de usuarios */
char insertarUsuario(Usuario usuario);
char existeUsuario(char nombreUsuario[], Usuario *usuario);


int leerLinea(char *cad, int n);
void leerClave(char *password);

char linea[80];

//funciones
void leerficherodatos(char[]);//solo valen para leer los ficheros con estructura %s %f %f %f %f
void escribirficherodatos(char []);//solo valen para escribir los ficheros con estructura %s %f %f %f %f


int ficheroStruct(struct TAnalisis fuentes[]);//pasa los datos del fichero a un vector de estructuras

void abrirficherolista(char []);
float media(char nombrefichero[]);
void ordenarconductividad(char nombrefichero[]);
void ordenarph(char nombrefichero[]);
void maximaturbidez(struct TAnalisis fuentes[], struct TAnalisis maxturbidez, char nombrefichero[]);
struct TAnalisis fuentescoliformes(struct TAnalisis fuentes[], char nombrefichero[]);

int banner();

//INTRODUCIMOS LA FUNCIÃ“N DE UN BANNER FIJO 

int banner_fijo();

//Introducimos una funcion que ofrece informacion

void normativa();

//Introducimos otra funcion que ofrece informacion

void aguascaracteristicasdefiniciones();

//CREAMOS LA FUNCION QUE PERMITE AÃ‘ADIR UN NUEVO USUARIO


void menuRegistrarUsuario();

//CREAMOS LA FUNCION QUE DEJA VER LOS USUARIOS REGISTRADOS

void menuListarUsuarios();

//CREAMOS LA FUNCION QUE PERMITE AÃ‘ADIR UN NUEVO USUARIO


void menuRegistrarUsuario();

//CREAMOS LA FUNCION QUE DEJA VER LOS USUARIOS REGISTRADOS

void menuListarUsuarios();



//Introducimos la funcion que controla el menu

void menuIniciarSesion();


/* Retorna 1 si se registrÃ³ el usuario en el archivo correctamente */
char insertarUsuario(Usuario usuario);

/* Retorna 1 si existe el nombre de usuario. Retorna el usuario buscado si existe */
char existeUsuario(char nombreUsuario[], Usuario* usuario);





int banner(){
			printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	char banner[]={"*-*-*-*-*-*-*-*-*-*-*-{ KUNFONT }-*-*-*-*-*-{ KUNFONT }-*-*-*-*-{ KUNFONT }-*-*-*-*-*-*-*-*-*-*-*"};
	unsigned short longitud, indice, espacio, repite, resto;

	//A CONTINUACION SE PROGRAMA EL BANNER
 
	longitud=strlen(banner);
	for (repite=1; repite<=3; repite++) /* repite el proceso 3 veces */
	{
		// *** IMPRIME EN ORDEN DE IZQUIERDA A DERECHA Y LUEGO DESPLAZA *** 
		for(resto=0; resto<=longitud; resto++) // para caracteres restantes a imprimir 
		{	for (indice=0; indice<=longitud-1-resto; indice++) // seleccion de indices evitando restantes 
			{
				printf("%c", banner[indice]); // imprime indice 
				if (!resto) usleep(300); // demora el proceso 
			}
			for(espacio=1; espacio<=longitud-resto-1; espacio++)
				printf("\b"); // retrocede 
 
			if (resto) usleep(300); // demora el proceso 
			printf("\b "); // borra el caracter actual 
		}
 
		for(espacio=1; espacio<=longitud; espacio++) // borra todos los caracteres presentados 
			printf("\b\b ");
		printf("\b"); // se coloca al inicio del desplegado
	}
	printf("*-*-*-*-*-*-*-*-*-*-{ KUNFONT }-*-*-*-*-*-*-*-*-*-{ KUNFONT }-*-*-*-*-*-*-*-*-*{ KUNFONT }-*-*-*-*-*-*\n");
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	
}

//INTRODUCIMOS LA FUNCIÓN DE UN BANNER FIJO 

int banner_fijo(){
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("*-*-*-*-*-*-*-*-*-*-{ KUNFONT }-*-*-*-*-*-*-*-*-*-{ KUNFONT }-*-*-*-*-*-*-*-*-*{ KUNFONT }-*-*-*-*-*-*\n");
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	
}

//INTRODUCIMOS LA FUNCIÓN DE OTRO BANNER FIJO  DISTINTO

int banner2(){

	printf("\n\t     ========================================================================================\n");
	printf("\t\t\t     BIENVENIDO A KUNFONT, TU COMPARADOR DE AGUAS DE CONFIANZA\n");
	printf("\t\t\tPuede consultar y añadir: datos y fuentes del distrito de Lavapies\n");
	printf("\t\t\t                Elija que desea realizar\n");
	printf("\t     ========================================================================================\n");
	
		printf("\n\t\t[1].REGISTRAR NUEVO FICHERO CON DATOS DE FUENTES NUEVAS\n");
		printf("\t\t[2]. CONSULTAR LOS DATOS DE AGUAS DEL DISTRITO DE LAVAPIES U OTROS FICHEROS YA CREADOS\n");
		printf("\t\t[3]. ORDENAR FICHERO POR CONDUCTIVIDAD\n");	
		printf("\t\t[4]. ORDENAR FICHERO POR ACIDEZ\n");		
		printf("\t\t[5]. MEDIA DE LOS PARAMETROS DEL FICHERO\n");
		printf("\t\t[6]. VALOR DE FUENTE CON MAYOR NIVEL DE TURBIDEZ\n");
		printf("\t\t[7]. FUENTES CON COLIFORMES\n");
		printf("\t\t[8]. AYUDA E INTRUCCIONES\n");
		printf("\t\t[9]. SALIR AL MENU PRINCIPAL Y CERRAR SESION\n");
		printf("\n\t\tIngrese su opcion: [ ]\b\b");	
}

//Introducimos una funcion que ofrece informacion

void normativa(){
			printf("\n");
			printf("\n");
	    	printf("\tNORMATIVA LEGAL DE LA PAGINA:\n\n");
	        printf("\tPara consultar los datos de la red de aguas del distrito madrileño seleccionado, debes regristrarte o iniciar \n\tsesion si ya tienes una cuenta.\n\n");
			printf("\tLos datos recogidos en la pagina proceden de la red publica de aguas del canal de Isabel II de Madrid, ofrecida \n\tpor el ayuntamiento de la capital.\n\n");
		    printf("\tPara cualquier duda acerca del acceso a la web o del uso de los datos de la misma puede escribir al correo de \n\tnuestro equipo de marketing:\n \t\t jorge.escobar@alumnos.upm.es \n\n");
		    printf("\tRespetando la Ley mencionada anteriormente, los datos introducidos por los usuarios de la pagina seran tratados \n\tde manera interna y no se difundiran de ninguna manera, siendo utilizados tan solo para labores de control de la\n\tconsulta del sistema y sus datos.\n");
			printf("\n");
			printf("\tGracias por su atencion, si posee alguna duda puede llamar al telefono del equipo tecnico: 666 46 52 88\n ");
			printf("\n");
			printf("\n");
	
}

//Introducimos otra funcion que ofrece informacion

void aguascaracteristicasdefiniciones(){
			printf("\n");
			printf("\n");
	    	printf("\tCARACTERISTICAS ESTUDIADAS Y MOSTRADAS POR KUNFONT\n");
	        printf("\t\t[1].PH\n");
	        printf("\t\t\tEl pH es una medida de la acidez o basicidad de una solucion. El termino pH proviene 	\n");
			printf("\t\t\tdel potencial de hidrogeno y se refiere a la concentracion de iones de hidrogeno (H+) \n");
			printf("\t\t\tpresentes en una solucion. El pH se expresa en una escala numerica que va desde 0 a 	\n");
			printf("\t\t\t14, donde 0 indica una solucion altamente acida, 7 indica una solucion neutra y 14 	\n");
			printf("\t\t\tindica una solucion altamente basica o alcalina.	\n");
			printf("\t\t\t	\n");
			printf("\t\t[2].TURBIDEZ\n");
			printf("\t\t\tLa turbidez se refiere a la medida de la falta de transparencia o claridad de un liquido 	\n");
			printf("\t\t\tdebido a la presencia de particulas suspendidas en el. Es una propiedad optica que 	\n");
			printf("\t\t\tdescribe la dispersion y el bloqueo de la luz cuando pasa a traves de un medio turbio.	\n");
			printf("\t\t\t	\n");
			printf("\t\t\tCuando un liquido está turbio, significa que contiene particulas solidas o materia 	\n");
			printf("\t\t\tsuspendida que no se disuelven por completo en el medio. Estas particulas pueden 	\n");
			printf("\t\t\tincluir particulas de polvo, sedimentos, microorganismos, algas, materia organica en 	\n");
			printf("\t\t\tdescomposicion u otras sustancias suspendidas.	\n");
			printf("\t\t\t	\n");
		    printf("\t\t[3].COLIFORME\n");
		    printf("\t\t\tLos coloides son sistemas dispersos formados por particulas pequeñas, denominadas 	\n");
			printf("\t\t\tcoloides o particulas coloidales, dispersas en un medio continuo. Estas particulas 	\n");
			printf("\t\t\ttienen un tamaño mayor que las moleculas individuales pero son mucho mas pequeñas 	\n");
			printf("\t\t\tque las particulas visibles a simple vista. La dispersion coloidal se produce cuando estas 	\n");
			printf("\t\t\tpartículas se encuentran suspendidas o dispersas en un líquido, un gas o incluso en un 	\n");
			printf("\t\t\tsolido.	\n");
			printf("\t\t\t	\n");
		    printf("\t\t[4].CONDUCTIVIDAD\n");
		    printf("\t\t\tLa conductividad de una disolucion se refiere a su capacidad para conducir la corriente 	\n");
	        printf("\t\t\telectrica. Es una medida de la facilidad con la que los iones o las particulas cargadas 	\n");
	        printf("\t\t\tpresentes en la disolucion pueden moverse y transportar carga electrica. Cuando una	\n");
	        printf("\t\t\tsustancia se disuelve en agua u otro solvente, puede ionizarse, es decir, liberar iones 	\n");
	        printf("\t\t\tpositivos (cationes) y/o iones negativos (aniones) en la disolucion. Estos iones son 	\n");
	        printf("\t\t\tresponsables de la conductividad electrica de la disolucion.	\n");
	        printf("\t\t\t	\n");
			printf("\n");
			printf("Gracias por su atencion, si posee alguna duda puede llamar al telefono del equipo tecnico informativo: 644 24 06 08\n ");
			printf("\n");
			printf("\n");
	
}


int ficheroStruct(struct TAnalisis fuentes[]){
	
	int i ;
	char titulo1[20], titulo2[20], titulo3[20], titulo4[20], titulo5[20];
	FILE *fichero = fopen("fichero1.txt", "r");
	
	if (fichero == NULL){
		printf ("Error al abrir el fichero\n");
	}
	
	fscanf(fichero,"%s %s %s %s %s",titulo1, titulo2, titulo3, titulo4, titulo5);
	        printf(" %s %s %s %s %s\n",titulo1, titulo2, titulo3, titulo4, titulo5);
    while (fscanf(fichero, "%s %f %d %d %d", fuentes[i].nombre, &fuentes[i].ph, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes) !=EOF ) {
        i++;
    }
    
    fclose(fichero);
    
    return i;
}

void maximaturbidez(struct TAnalisis fuentes[], struct TAnalisis maxturbidez, char nombrefichero[]){
	
		  
	  int contador=0, i=0, j;
	  
	  char titulo[10], titulo2[10], titulo3[10], titulo4[10], titulo5[10];
	
	 FILE *fsalida1;
	        fsalida1 = fopen(nombrefichero,"r");
        	if (fsalida1 == NULL) {
	    	    printf("Error, no puede leer el fichero.\n");	
	        }
	        
	        fscanf(fsalida1,"%s %s %s %s %s",titulo, titulo2, titulo3, titulo4, titulo5);
	          
	        fflush(stdin);
            while(fscanf(fsalida1,"%s %f %f %f %f", fuentes[i].nombre, &fuentes[i].ph ,&fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes)!=EOF){
		      
		      
				contador++; 
				i++;
			
					}
					fclose(fsalida1);

	
	maxturbidez=fuentes[0];
	for (i=0; i<contador; i++){
	if (fuentes[i].turbidez > maxturbidez.turbidez){
		maxturbidez=fuentes[i];
		
	}
	}
	
	printf("Fuente con mayor nivel de turbidez: %s  ", maxturbidez.nombre);

}

struct TAnalisis fuentescoliformes(struct TAnalisis fuentes[], char nombrefichero[]){
	int contador=0, i=0, j;
	struct TAnalisis numcoliformes; 
	  
	  char titulo[10], titulo2[10], titulo3[10], titulo4[10], titulo5[10];
	
	 FILE *fsalida1;
	        fsalida1 = fopen(nombrefichero,"r");
        	if (fsalida1 == NULL) {
	    	    printf("Error, no puede leer el fichero.\n");	
	        }
	        
	        fscanf(fsalida1,"%s %s %s %s %s",titulo, titulo2, titulo3, titulo4, titulo5);
	          
	        fflush(stdin);
            while(fscanf(fsalida1,"%s %f %f %f %f", fuentes[i].nombre, &fuentes[i].ph ,&fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes)!=EOF){
		      
		      
				contador++; 
				i++;
			
					}
					fclose(fsalida1);

	
	numcoliformes=fuentes[0];
	for (i=0; i<contador; i++){
	if (fuentes[i].coliformes>0){
		printf("%s ", fuentes[i].nombre);
		
	}
	}
	
	return numcoliformes;
	
}
//CREAMOS LA FUNCION QUE PERMITE AÑADIR UN NUEVO USUARIO


void menuRegistrarUsuario() {
	
	int MAX=80;
	Usuario usuario;
	char nombreUsuario[80];
	char respuesta[80];
	char repite = 1;
	
	do {
		system("cls");
		printf("\n\t\t\tREGISTRAR USUARIO\n");
		printf("\t\t\t=================\n");
		printf("\n\tIngrese nombre de usuario: ");
		leerLinea(linea, MAX);
		sscanf(linea, "%s", nombreUsuario);

		/* Se verifica que el nombre de usuario no exista */
		if (!existeUsuario(nombreUsuario, &usuario)) {
			strcpy(usuario.nombre, nombreUsuario);

			printf("\tIngrese la clave: ");
			leerLinea(usuario.password, MAX);

			/* Se inserta el usuario en el archivo de usuarios */
			if (insertarUsuario(usuario)) {
				printf("\n\t Los datos fueron registrados satisfactoriamente!\n");

			} else {
				printf("\n\tOcurrio un error al registrar el usuario\n");
				printf("\nInténtelo mas tarde\n");
			}
		} else {
			printf("\n\tEl usuario \"%s\" ya ha sido registrado previamente\n", usuario.nombre);
			printf("\tNo puede registrar dos usuarios con el mismo nombre de usuario.\n");
		}

		printf("\n\tDesea seguir registrando usuarios? [S/N]: ");
		leerLinea(respuesta, MAX);
 
		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			repite = 0;
		}

	} while (repite == 1);
}

//CREAMOS LA FUNCION QUE DEJA VER LOS USUARIOS REGISTRADOS
void menuListarUsuarios() {
	int MAX_USUARIOS=200;
    int numeroUsuarios;
    Usuario usuarios[MAX_USUARIOS];
    int i;

    system("cls");
    obtenerUsuarios(usuarios, &numeroUsuarios); /* Obtiene los usuarios y actualiza el número de usuarios */

    if (numeroUsuarios == 0) {
        printf("\n\tNo existe ningun usuario registrado!\n");
    } else {
        printf("\n\t\t    ==> LISTADO DE PERSONAS REGISTRADAS <==\n");
        printf(" ------------------------------------------------------------------------------\n");
        printf("%10s%25s%25s\n", "#", "NOMBRE", "CONTRASEÑA");
        printf(" ------------------------------------------------------------------------------\n");

        /* Se recorre el arreglo de usuarios */
        for (i = 0; i < numeroUsuarios; i++) {
            printf("%10d%25s%25s\n", (i + 1), usuarios[i].nombre, usuarios[i].password);
        }
        printf(" ------------------------------------------------------------------------------\n");
    }

    getchar();
}




//Introducimos la funcion que controla el menu

void menuIniciarSesion() {
	
	int MAX=80;
	int MAX_INTENTOS=3;
	char nombreUsuario[MAX];
	char password[MAX];
	int intento = 0;
	int loginExitoso = 0;
	int intentosrestantes;
	

	do {
		intentosrestantes=MAX_INTENTOS-intento;
		banner_fijo();
		system("cls");
		printf("\n\t\t\t==========================================\n");	
		printf("\t\t\t============INGRESAR AL SISTEMA===========\n");
		printf("\t\t\t==========================================\n");
		printf("\t\t\tTienes %d intentos para acceder al sistema\n",intentosrestantes);

		printf("\n\t\tUSUARIO: ");
		leerLinea(linea, MAX);
		sscanf(linea, "%s", nombreUsuario);

		printf("\t\tCLAVE: ");
		leerClave(password);
		
		if (logear(nombreUsuario, password)) {
			loginExitoso = 1;
		} else {
			printf("\n\n\t\tUsuario y/o password incorrectos");
			intento++;
			getchar();
		}
	} while (intento < MAX_INTENTOS && loginExitoso == 0);

	if (loginExitoso == 1) {
		menuSistema();
		
	} else {
		printf("\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
		getchar();
	}
}


/* Retorna 1 si se registró el usuario en el archivo correctamente */
char insertarUsuario(Usuario usuario){
	FILE *archivo;
	char insercion = 0;

	/* Abre el archivo en modo de añadidura, para agregar datos al final. Si no existe es creado*/
	archivo = fopen(ARCHIVO_USUARIOS, "ab");

	if (archivo == NULL) {
		insercion = 0;

	} else {
		/* Registra el struct usuario en el archivo */
		fwrite(&usuario, sizeof(usuario), 1, archivo);
		insercion = 1;

		/* Cierra el archivo */
		fclose(archivo);
	}

	return insercion;
}

/* Retorna 1 si existe el nombre de usuario. Retorna el usuario buscado si existe */
char existeUsuario(char nombreUsuario[], Usuario* usuario){
	FILE *archivo;
	char existe;

	/* Abre el archivo en modo de lectura */
	archivo = fopen(ARCHIVO_USUARIOS, "rb");

	if (archivo == NULL) {
		existe = 0;

	} else {
		existe = 0;

		/* Lee secuencialmente del archivo de usuarios */
		fread(&(*usuario), sizeof(*usuario), 1, archivo);
		while (!feof(archivo)) {
			if (strcmp((*usuario).nombre, nombreUsuario) == 0) {
				/* Encuentra un usuario del archivo con el nombre de usuario buscado */
				existe = 1;
				break;
			}

			fread(&(*usuario), sizeof(*usuario), 1, archivo);
		}

		/* Cierra el archivo*/
		fclose(archivo);
	}

	return existe;
}


int obtenerUsuarios(Usuario usuarios[], int *n) {
	FILE *archivo;
	Usuario usuario;

	archivo = fopen(ARCHIVO_USUARIOS, "rb");
	
	if (archivo == NULL) {
		*n = 0;
	} else {
		*n = 0;
		while (fread(&usuario, sizeof(usuario), 1, archivo) != 0) {
			usuarios[(*n)++] = usuario;
		}
		fclose(archivo);
	}
}

int logear(char nombreUsuario[], char password[]) {
	FILE *archivo;
	char logeoExitoso;
	Usuario usuario;

	archivo = fopen(ARCHIVO_USUARIOS, "rb");

	if (archivo == NULL) {
		logeoExitoso = 0;
	} else {
		logeoExitoso = 0;

		while (fread(&usuario, sizeof(usuario), 1, archivo) != 0) {
			if (strcmp(usuario.nombre, nombreUsuario) == 0 && strcmp(usuario.password, password) == 0) {
				logeoExitoso = 1;
				break;
			}
		}
		fclose(archivo);
	}

	return logeoExitoso;
}

int leerLinea(char *cad, int n) {
    fgets(cad, n, stdin);
    cad[strcspn(cad, "\n")] = '\0';  // Eliminar el carácter de nueva línea
    return strlen(cad);
}

void leerClave(char *password) {
    char c;
    int i = 0;
    while ((c = getch()) != '\r') {  // Leer caracteres hasta que se presione Enter ('\r')
        if (c == 8 && i > 0) {  // Si se presiona Retroceso (8) y hay caracteres ingresados
            printf("\b \b");  // Borrar el carácter de la consola
            password[--i] = '\0';  // Eliminar el último carácter
        } else if (c != 8) {  // Si se ingresa un carácter válido
            putchar('*');  // Imprimir '*' en lugar del carácter ingresado
            password[i++] = c;  // Almacenar el carácter 
        }
    }
    printf("\n");
    password[i] = '\0';  // Agregar el carácter nulo al final 
}


//Introducimos las funciones que nos dejan leer y escribir sobre el fichero de los usuarios


void leerficherodatos(char nombrefichero[]){
	
	
	float ph, conductividad, turbidez, coliformes;
	  char nfuentes[10];
	
	 FILE *fsalida1;
	        fsalida1 = fopen(nombrefichero,"r");
        	if (fsalida1 == NULL) {
	    	    printf("Error, no puede leer el fichero.\n");
	        	
	        }
            while	(fscanf(fsalida1,"%s %f %f %f %f", nfuentes, &ph, &conductividad, &turbidez, &coliformes)!=EOF){
				
							printf("%s\t %2.f %2.f %2.f %2.f\n", nfuentes, ph, conductividad, turbidez, coliformes);
							fflush(stdin);
						}
						fclose(fsalida1);
            
            fflush(stdin);
	
}
void escribirficherodatos(char nombrefic[]){
	

	float ph, conductividad, turbidez, coliformes;
    char nfuentes[10]; 
	 FILE *fsalida;
	        fsalida = fopen(nombrefic,"a+");
        	if (fsalida == NULL) {
	    	    printf("Error, no puede crear el fichero.\n");
	        	
	        }
        	printf("que desea introducir (recuerde que es nombre de la fuente, pH, conductividad, turbidez y coliformes)\n");
        	fflush(stdin);
	        scanf("%s %f %f %f %f", nfuentes, &ph, &conductividad, &turbidez, &coliformes);
			fprintf(fsalida,"%s\t %2.f %2.f %2.f %2.f\n", nfuentes, ph, conductividad, turbidez, coliformes);
			fclose(fsalida);
}


void abrirficherolista(char lista[]){
	char nombrefic[20], nombrefichero[20],nficheros[20];
	char texto[100], salir; 
	float ph, conductividad, turbidez, coliformes;
		
		fflush(stdin);
	    	printf("Estos son los ficheros creados\n");
	    	
	    	FILE *flista;
	        flista = fopen("lista.txt","r");
        	    if (flista == NULL) {
	    	        printf("Error\n");
	        	    	
	            }
	            fflush(stdin);
            while(fscanf(flista,"%s",nficheros)!=EOF){
							printf("%s\n",nficheros);
							fflush(stdin);
			}
			fclose(flista);
            fflush(stdin);
}
float media(char nombrefichero[]){
	float ph, conductividad, turbidez, coliformes, media=0, media2=0, media3=0, media4=0, i;
	  char nfuentes[10];
	  int contador=0;
	  char titulo[10], titulo2[10], titulo3[10], titulo4[10], titulo5[10];
	
	FILE *fsalida1;
	        fsalida1 = fopen(nombrefichero,"r");
        	if (fsalida1 == NULL) {
	    	    printf("Error, no puede leer el fichero.\n");
	        	
	        }

	        fscanf(fsalida1,"%s %s %s %s %s",titulo, titulo2, titulo3, titulo4, titulo5);
	        printf("%s %s %s %s %s\n",titulo, titulo2, titulo3, titulo4, titulo5);  
            while	(fscanf(fsalida1,"%s %f %f %f %f", nfuentes, &ph, &conductividad, &turbidez, &coliformes)!=EOF){
				
							printf("%s %f %f %f %f\n", nfuentes, ph, conductividad, turbidez, coliformes);
							fflush(stdin);
						fflush(stdin);
                            contador++;
                            	media+=ph;
                            	media2+=conductividad;
                            	media3+=turbidez;
                            	media4+=coliformes;
						}
						fclose(fsalida1);
		
            
            media=media/contador;
            media2=media2/contador;
            media3=media3/contador;
            media4=media4/contador;
			printf("media pH= %2.f\nmedia conductividad= %2.f\nmedia turbidez= %2.f\nmedia coliformes= %2.f\n",media, media2, media3, media4);
            
            fflush(stdin);
	return media;
}

void ordenarconductividad(char nombrefichero[]){
		int i , contador, j, k, aux;
		struct TAnalisis fuentes[200];
		
	char titulo1[20], titulo2[20], titulo3[20], titulo4[20], titulo5[20], aux2[50];
		 
		 FILE *fichero;
	        fichero = fopen(nombrefichero,"r");
        	if (fichero == NULL) {
	    	    printf("Error, no puede leer el fichero.\n");	
        }
	
	fscanf(fichero,"%s %s %s %s %s",titulo1, titulo2, titulo3, titulo4, titulo5);
	    
    while (fscanf(fichero, "%s %f %d %d %d", fuentes[i].nombre, &fuentes[i].ph, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes) !=EOF ) {
        //printf("%s %f %d %d %d\n", fuentes[i].nombre, fuentes[i].ph, fuentes[i].conductividad, fuentes[i].turbidez, fuentes[i].coliformes);
							
		i++;
        
    }fflush(stdin);
    
    fclose(fichero);
    contador=i;
   
					
			for (i=0; i<contador-1;i++){
                for(j=i+1;j<contador;j++){

            if (fuentes[i].conductividad < fuentes[j].conductividad) {
                struct TAnalisis maximo = fuentes[i];
                fuentes[i] = fuentes[j ];
                fuentes[j] = maximo;
            }
        }
    }
        for(i=0;i<contador;i++){
        
                 printf("%d %s\n", fuentes[i].conductividad,fuentes[i].nombre);
        }

				}
	
void ordenarph(char nombrefichero[]){
	
	struct TAnalisis fuentes[200];
	  int contador=0, i=0, j;
	  float vector[50], aux;
	  int vector2[50];
	  char titulo[10], titulo2[10], titulo3[10], titulo4[10], titulo5[10];
	
	 FILE *fsalida1;
	        fsalida1 = fopen(nombrefichero,"r");
        	if (fsalida1 == NULL) {
	    	    printf("Error, no puede leer el fichero.\n");	
	        }
	        
	        fscanf(fsalida1,"%s %s %s %s %s",titulo, titulo2, titulo3, titulo4, titulo5);
	        printf("%s\n", titulo2);  
	        fflush(stdin);
            while(fscanf(fsalida1,"%s %f %f %f %f", fuentes[i].nombre, &fuentes[i].ph, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes )!=EOF){
		      
		      
				contador++; 
				i++;
			
					}
					fclose(fsalida1);
			
					
			for (i=0; i<contador-1;i++){
                for(j=i+1;j<contador;j++){
                      if (fuentes[i].ph < fuentes[j].ph) {
                struct TAnalisis maximo = fuentes[i];
                fuentes[i] = fuentes[j ];
                fuentes[j] = maximo;
                        }
                }
        }
        for(i=0;i<contador;i++){
                printf("%f %s \n", fuentes[i].ph, fuentes[i].nombre);
        }

				}
	
	
menuSistema(){
		
	int MAX=80;	
	int opcionMenu;
	char nombrefic[20], nombrefichero[20],nficheros[20];
	char texto[100], salir, lista[10]="lista.txt"; 
	float ph, conductividad, turbidez, coliformes;
	struct TAnalisis fuentes[200];
	struct TAnalisis maxturbidez;
	struct TAnalisis numcoliformes;
	int nelementos;
	int i;
	nelementos=ficheroStruct(fuentes);
		
		int farandule=1;
		int repite;
		repite=1;
		
		int opcion2;	
			do{
	
	system("cls");
	system("color E0");
	if(farandule==1){
			banner();
			banner2();
		}else{
		banner_fijo();
		banner2();
		}
	
		leerLinea(linea, MAX);
		sscanf(linea, "%d", &opcion2);
		
		switch (opcion2) {
			case 1:
				farandule++;
				system("cls");		
				banner_fijo();
				
					printf("\n\tintroduce como quieres llamar al archivo fichero (acuerdese de acabarlo con el formato .txt)\n");
		    scanf("%s", nombrefic);
		    escribirficherodatos(nombrefic);
	        printf("\tComprobacion del fichero\n");
		    leerficherodatos(nombrefic);
            
            //meter en un fichero llamado listadeficheros todos los ficheros introducidos;
            
            FILE *fsalida;
	            fsalida = fopen("lista.txt","a+");
        	        if (fsalida == NULL) {
	    	            printf("Error\n");
	        	        return 0;	
	                }
            	fflush(stdin);
	    		fprintf(fsalida,"%s\n",nombrefic);
		    	fclose(fsalida);
		    printf("\n\n\n");
    
            do{ //funcion de salir cuando quieras
		        printf("Utilice s y despues enter para volver al menu principal\n");
		        fflush(stdin);
		        scanf("%c",&salir);
		    	}while(salir=='s'&&salir=='S');
		    	if(salir=='s'&&salir=='S'){
		    			break;
				}break;
				
				
			case 2:
				farandule++;
				system("cls");		
				banner_fijo();
				
					//leer el fichero con los fichero que existen 
	    	printf("HAS ELEGIDO REVISAR LA INFORMACION DE AGUAS DE LAVAPIES\n");
	    	fflush(stdin);
	    	printf("Estos son los ficheros creados\n");
	    	
	    	FILE *flista;
	        flista = fopen("lista.txt","r");
        	    if (flista == NULL) {
	    	        printf("Error\n");
	        	    return 0;	
	            }
	            fflush(stdin);
            while(fscanf(flista,"%s",nficheros)!=EOF){
							printf("%s\n",nficheros);
							fflush(stdin);
			}
			fclose(flista);
            fflush(stdin);
            
	    	//leer el fichero que quieras
	    	
	    	printf("Introduzca el nombre del fichero que quiere mirar:\n");
	    	scanf("%s",nombrefichero);
	    	leerficherodatos(nombrefichero);
		    printf("\n\n\n");
		     do{
		        printf("Utilice s y despues enter para volver al menu principal:\n");
		        fflush(stdin);
		        scanf("%c",&salir);
		    	}while(salir=='s'&&salir=='S');
		    	if(salir=='s'&&salir=='S'){
		    			break;
				} break;		
				
			
			case 3:
				
				
		    	system("cls");
				system ("color 87");		
				banner_fijo();
				
	    		printf("\tHAS ELEGIDO ORDENAR POR CONDUCTIVIDAD\n");
		    	printf("\n\n");
		    	do{
				
					abrirficherolista(lista);
	    	        printf("introduce el nombre del fichero que quiere mirar\n");
	            	scanf("%s",nombrefichero);
	            	printf("se ordena la conductividad de mayor a menor\n");
	    	        ordenarconductividad(nombrefichero);
	    	        printf("\n\n\n\tUtilice s y despues enter para volver al menu principal\n");
		        	fflush(stdin);
		   	     scanf("%c",&salir);
		    		}while(salir=='s'&&salir=='S');
		    		if(salir=='s'&&salir=='S'){
		   		 			break;
					}break;
			
			case 4:
				
				
		   	system("cls");
			system ("color 87");		
			banner_fijo();
							
	    	printf("\tHAS ELEGIDO ORDENAR POR ACIDEZ\n");
	    	printf("\n\n");
	    	do{
									abrirficherolista(lista);
	    	        printf("introduce el nombre del fichero que quiere mirar\n");
	            	scanf("%s",nombrefichero);
	            	printf("se ordenaran las fuentes de menos acida a mas acida\n");
	    	        ordenarph(nombrefichero);
	    	        printf("\n\n\n\tUtilice s y despues enter para volver al menu principal\n");
		        	fflush(stdin);
		   	     scanf("%c",&salir);
		    		}while(salir=='s'&&salir=='S');
		    		if(salir=='s'&&salir=='S'){
		   		 			break;
					}break;
			
            case 5:
				
				system("cls");
				system ("color 87");		
				banner_fijo();
				
	    		printf("\tHAS ELEGIDO MEDIA DE LOS PARAMETROS\n");
		    	printf("\n\n");
		    	do{
				
					abrirficherolista(lista);
	    	        printf("introduce el nombre del fichero que quiere mirar\n");
	            	scanf("%s",nombrefichero);
	            	printf("La media de las muestras del ph de este distrito son\n");
	    	        media(nombrefichero);
	    	        printf("\n\n\n\tUtilice s y despues enter para volver al menu principal\n");
		        	fflush(stdin);
		   	     scanf("%c",&salir);
		    		}while(salir=='s'&&salir=='S');
		    		if(salir=='s'&&salir=='S'){
		   		 			break;
					}break;	
					
			case 6:
				
				
		   	system("cls");
			system ("color 87");		
			banner_fijo();
							
	    	printf("\tHAS ELEGIDO VER FUENTE CON MAYOR VALOR DE TURBIDEZ\n");
	    	printf("\n\n");
	    	do{
									abrirficherolista(lista);
	    	        printf("introduce el nombre del fichero que quiere mirar\n");
	            	scanf("%s",nombrefichero);
	            	maximaturbidez(fuentes, maxturbidez, nombrefichero);
	    	       
	    	        printf("\n\n\n\tUtilice s y despues enter para volver al menu principal\n");
		        	fflush(stdin);
		   	     scanf("%c",&salir);
		    		}while(salir=='s'&&salir=='S');
		    		if(salir=='s'&&salir=='S'){
		   		 			break;
					}break;
				
			case 7:
				
				
		   	system("cls");
			system ("color 87");		
			banner_fijo();
							
	    	printf("\tHAS ELEGIDO VER FUENTES CON COLIFORMES\n");
	    	printf("\n\n");
	    	do{
									abrirficherolista(lista);
	    	        printf("introduce el nombre del fichero que quiere mirar\n");
	            	scanf("%s",nombrefichero);
	            	numcoliformes=fuentescoliformes(fuentes, nombrefichero);
	    	       
	    	        printf("\n\n\n\tUtilice s y despues enter para volver al menu principal\n");
		        	fflush(stdin);
		   	     scanf("%c",&salir);
		    		}while(salir=='s'&&salir=='S');
		    		if(salir=='s'&&salir=='S'){
		   		 			break;
					}break;
				
			case 8 :
		    	
		    	farandule++;
		    	system("cls");
				system ("color 87");		
				banner_fijo();
				
	    		printf("\n\tHAS ELEGIDO INSTRUCCIONES Y AYUDA DENTRO\n");
		    	printf("\n\n");
		  	   do{
			        printf("\tBienvenido a Kunfont!! \n\tEste programa consiste en un algoritmo para guardar los ficheros de los datdos de diferentes analisis\n");
			        printf("\tde agua.\n\tLa opcion 1 en el menu de KUNFONT, sirve para registrar ficheros con datos de experimentos \n\tnuevos.\n\tAdemas, podemos consultar datos ya existentes en ficheros ya creados desde la opcion 2.\n\tAl introducir un fichero nuevo");
		    	    printf("este se regsitrara en un fichero que almacena todos los ficheros previamente\n\tregistrados.\n");
		    	    printf("\n\n\n\tUtilice s y despues enter para volver al menu principal\n");
		        	fflush(stdin);
		   	     scanf("%c",&salir);
		    		}while(salir=='s'&&salir=='S');
		    		if(salir=='s'&&salir=='S'){
		   		 			break;
					}break;
			
			case 9 :
				
				farandule++;
				system("cls");
				system("color 87");		
				banner_fijo();
				printf("\n");
				printf("\tGRACIAS POR UTILIZAR NUESTRA APLICACION!!!\n");
				printf("\tSu sesión en kunfont ha sido cerrada\n");
				printf("\tPulse enter para volver al menu principal\n");
				
				repite= 0;		
				break;
				
				}
		} while (repite == 1);
	getchar();
}	




//INTRODUCIMOS LA FUNCION QUE CODIFICA EL MENU PRINCIPAL





void menuInicial() {
	
	setlocale(LC_CTYPE,"Spanish");//CODIFICAMOS EL IDIOMA A ESPAÑOL PARA PODER UTILIZAR LETRAS COMO LA Ñ DE ESPAÑA
	

	
	Usuario usuario;
	char repite = 1;
	int MAX=80;
	int opcion = -1;
	int farandul;
	farandul=1;
	system ("color B0");//CODIFICAMOS EL COLOR: AGUAMARINA AZUL PARA EL FONDO Y EL NEGRO PARA LAS LETRAS

	
	do {
		system("cls");
		system ("color B0");//Creamos que al cambiar de nuevo a la pantalla del menu, vuelva el color original
		
		if(farandul==1){
			banner();
		}else{
		banner_fijo();
		}
				
		printf("\t\t\tMENU PRINCIPAL\n");
		printf("\n\t\t[1]. Ver usuarios registrados\n");
		printf("\t\t[2]. Registrar usuario nuevo\n");
		printf("\t\t[3]. Acceder al servico de KUNFONT\n");
		printf("\t\t[4]. Normativa Legal de la web\n");
		printf("\t\t[5]. A cerca de los datos recogidos\n");
		printf("\t\t[0]. Salir\n");
		printf("\n\t\tIngrese su opcion: [ ]\b\b");
		leerLinea(linea, MAX);
		sscanf(linea, "%d", &opcion);
		farandul++;

		switch (opcion) {
			case 1:
				system("cls");
				system ("color DF");		
				banner_fijo();
				menuListarUsuarios();
				farandul++;
				break;

			case 2:
				system("cls");
				system ("color DF");		
				banner_fijo();
				menuRegistrarUsuario();
				farandul++;
				break;

			case 3:
				system("cls");
				system ("color E0");		
				banner_fijo();
				menuIniciarSesion();
				farandul++;
				break;

			case 4:
				system("cls");
				system ("color 87");		
				banner_fijo();
				normativa();
				system("pause");
				break;
				
			case 5:
				system("cls");
				system ("color 87");		
				banner_fijo();
				aguascaracteristicasdefiniciones();
				system("pause");
				farandul++;
				break;
			
			case 0:
				system("cls");		
				banner_fijo();
				printf("\n\n\t\tHASTA PRONTO!!\n");
				repite = 0;
				break;
		}

	} while (repite == 1);
}

// CREAMOS EL PROGRAMA

int main() {
	menuInicial();
	return 0;
}
