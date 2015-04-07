#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linhas (){
	FILE *f;
	int ch, count = 0;
	f = fopen("alunos.txt", "r");
	do {
		ch = fgetc(f);
		if (ch == '\n') count++;
	   }while (ch != EOF);
	fclose(f);
	return count;
}


void leAlunos(int* matriculas, char **nomes){
    int mat, i;
    int linha = 0;
    char c;

    char nome[50];
    FILE *f;
    f = fopen("alunos.txt","r");
    if(f == NULL){
        printf("Nao foi possivel abrir esse arquivo. \n");
        return;
    }

    while(feof(f) == 0){

        if(fscanf(f,"%d", &mat) < 0)
            break;
        c = fgetc(f);

        while(c == ' '){
            c = fgetc(f);
        }

        i = 0;

        while(c != '\n'){
            nome[i] = c;
            c = fgetc(f);
            i++;
        }
	//if (linha > 10)
		//matriculas = (int*)realloc(matriculas, linha * (sizeof(int)));
        nome[i] = '\0';
        matriculas[linha] = mat;
        strcpy(nomes[linha], nome);
        linha++;
    }
       fclose(f);
}

void leNotas(int *matricula, char **nomes, float *notas, int linha){
	FILE* f;
	int i = 0, j, mat;
	float nota[2];
        f = fopen("notas.txt","r"); 	
        if(f == NULL){
       		printf("Nao foi possivel abrir esse arquivo. \n");
        	return;
                     }
	while (feof(f) == 0){
	        if(fscanf(f,"%d", &mat) < 0)
            	        break;
		if (fscanf(f,"%f %f", &nota[0], &nota[1]) < 0)
			break;
		for (j=0; j<linha; j++)
			if (mat == matricula[j]){
				notas[j] = (nota[0]+nota[1])/2;
				break;}
		i++;		
		}
	fclose(f);
}

void busca (int *matricula, char **nomes, float *notas, char* busca, int n){
	int i=0;
	while (i < n){
		if(strstr (nomes[i],busca) != NULL){
			printf ("Nome completo: ");
			puts(nomes[i]);
			printf ("Media: %.2f\n", notas[i]);
						  }
		i++;}
}

void liberar (int *matricula, char **nomes, float *notas, char* busca, int j){
	int i;		
	free(matricula);
	free(notas);
	for (i=0; i < j; i++)
		free(nomes[i]);
	free(nomes);
	free(busca);





}

int main (int argc, char* argv[]){
	int *matricula, nlinhas=10, nletras=50, n;
	char **nomes, *nome;
	float *notas;
	matricula = (int*)malloc(nlinhas * sizeof(int));
	notas = (float*)malloc(nlinhas * sizeof(float)); 
	nomes = (char**)malloc(nlinhas * sizeof(char*));
	int j;
	int linha = linhas();
	if (linha > nlinhas){
		matricula = (int*)realloc(matricula, linha * sizeof(int));
		nomes = (char**)realloc(nomes, linha * sizeof(char*));
		notas = (float*)realloc(notas, linha * sizeof(float));}

	for (j=0; j < linha; j++)
		nomes[j] = (char*)malloc(nletras * sizeof(char));
		
	leAlunos(matricula, nomes);
	leNotas(matricula,nomes,notas, linha);
	if (argv[1] == NULL){
		printf ("Sem informacao\n");
		return 0;}


	nome = (char*)malloc(sizeof(char)*strlen(argv[1]));
	strcpy(nome,argv[1]);
	busca (matricula,nomes,notas,nome,nlinhas);
	liberar(matricula, nomes, notas, nome, linha);
	return 0;
}
	
