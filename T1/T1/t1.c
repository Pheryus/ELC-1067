#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void leAlunos(int* matriculas, char nomes[50][50], int* n){
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
        nome[i] = '\0';
        matriculas[linha] = mat;
        strcpy(nomes[linha], nome);
        linha++;
    }
    *n = linha;
    printf("\n\nNumero de linhas: %d\n\n", linha);

    fclose(f);
}

void leNotas(int *matricula, char nomes[50][50], float notas[50]){
	FILE* f;
	int i = 0, mat;
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
		notas[i] = (nota[0]+nota[1])/2;
		i++;		
		}
	fclose(f);
}

void busca (int *matricula, char nomes[50][50], float notas[50], char* busca, int n){
	int i=0;
	while (i < n){
		if(strstr (nomes[i],busca) != NULL){
			printf ("Nome completo: ");
			puts(nomes[i]);
			printf ("Media: %.2f\n", notas[i]);
						  }
		i++;}
}



int main (int argc, char* argv[]){
	int matricula[50][50], nlinhas=10;
	char nomes[50][50], nome[50]="";
	float notas[50];
	leAlunos(matricula, nomes, &nlinhas);
	leNotas(matricula,nomes,notas);
	int i=1;
	while (i < argc){
		strcpy(nome,argv[i]);
		busca (matricula,nomes,notas,nome,nlinhas);
		i++;
			}
	return 0;
}
	
