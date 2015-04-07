#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	int mat;
	char nome[100];
	printf ("informe matricula:\n");
	scanf ("%d",&mat);
	printf ("informe nome:\n");
	scanf ("%s",nome);
	FILE *fp;
	fp = fopen ("Saida.txt","w");
	fprintf (fp, "%d %s", mat,nome);
	fclose(fp);	

}
