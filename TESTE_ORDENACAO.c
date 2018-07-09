#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *arquivo;

int comp_insert = 0, troca_insert = 0, ac_insert_troc = 0, ac_insert_comp = 0, md_insert_comp = 0, md_insert_troc = 0;
int comp_bubble = 0, troca_bubble = 0, ac_bubble_troc = 0, ac_bubble_comp = 0, md_bubble_comp = 0, md_bubble_troc = 0;
int comp_select = 0, troca_select = 0, ac_select_troc = 0, ac_select_comp = 0, md_select_comp = 0, md_select_troc = 0;
int comp_shell  = 0, troca_shell  = 0, ac_shell_troc  = 0, ac_shell_comp  = 0, md_shell_comp =  0, md_shell_troc  = 0;
int comp_heap   = 0, troca_heap   = 0, ac_heap_troc   = 0, ac_heap_comp   = 0, md_heap_comp   = 0, md_heap_troc   = 0;
int comp_quick  = 0, troca_quick  = 0, ac_quick_troc  = 0, ac_quick_comp  = 0, md_quick_comp  = 0, md_quick_troc  = 0;
int comp_merge  = 0, troca_merge  = 0, ac_merge_troc  = 0, ac_merge_comp  = 0, md_merge_comp  = 0, md_merge_troc  = 0;

void bubble_sort(int *nrs, int tam);
void selection_sort(int *nrs, int tam);
void insertion_sort(int *original, int n);
void heap_sort(int *a, int n);
void shell_sort(int *vet, int size);
void quick_sort(int *nrs, int esquerda, int direita);
void merge_sort(int *vetor, int comeco, int fim);
void merge(int *vetor, int comeco, int meio, int fim);

int main(void) {
	int *vet, *cop, range, i, j, k, x, z;
	int num = 10, rodada = 0, qtd = 10; 	//(qtd) - Quantidade de vetores por rodada | (num) - qtd de rodadas
	int tam = 10;							//(tam) - vetor inicial tamanho 10 posições
	range=(1000-0)+1;						//(range) - valores aleatórios entre 0 a 1000 para preencher vetor	
	srand((unsigned)time(NULL));
	vet = (int*)calloc(tam,sizeof(int));
	cop = (int*)calloc(tam,sizeof(int));
	arquivo = fopen("resultados.txt", "w");

	while(rodada < num)
	{
		rodada++;
		printf("\n\n\n\n - - Iniciando %da. Rodada - - \n",rodada);
		
		for(k = 0; k < qtd; k++)
		{
			printf("\n\n\n Vetor %d de [%d] posicoes:",k+1,tam);
			for (j = 0; j < tam ; j++)
			{
				vet[j] = (0+(rand()%range));
				//printf("  %d",vet[j]);	//Printa cada vetor
			}

			for(z=0; z<tam; z++) cop[z]=vet[z];
			selection_sort(cop,tam);
			printf("\n - SELECTION:\tTroca: %d\tComparacao: %d",troca_select,comp_select);
			ac_select_troc += troca_select;
			ac_select_comp += comp_select;
			troca_select = 0;
			comp_select = 0;
	
			for(z=0; z<tam; z++) cop[z]=vet[z];
			insertion_sort(cop,tam);
			printf("\n - INSERTION:\tTroca: %d\tComparacao: %d",troca_insert,comp_insert);
			ac_insert_troc += troca_insert;
			ac_insert_comp += comp_insert;
			troca_insert = 0;
			comp_insert = 0;

			for(z=0; z<tam; z++) cop[z]=vet[z];
			bubble_sort(cop,tam);
			printf("\n - BUBBLE:\tTroca: %d\tComparacao: %d",troca_bubble,comp_bubble);
			ac_bubble_troc += troca_bubble;
			ac_bubble_comp += comp_bubble;
			troca_bubble = 0;
			comp_bubble = 0;
			
			for(z=0; z<tam; z++) cop[z]=vet[z];
			shell_sort(cop,tam);
			printf("\n - SHELL:\tTroca: %d\tComparacao: %d",troca_shell,comp_shell);
			ac_shell_troc += troca_shell;
			ac_shell_comp += comp_shell;
			troca_shell = 0;
			comp_shell = 0;

			for(z=0; z<tam; z++) cop[z]=vet[z];
			heap_sort(cop,tam);
			printf("\n - HEAP:\tTroca: %d\tComparacao: %d",troca_heap,comp_heap);
			ac_heap_troc += troca_heap;
			ac_heap_comp += comp_heap;
			troca_heap = 0;
			comp_heap = 0;
			
			for(z=0; z<tam; z++) cop[z]=vet[z];
			quick_sort(cop,0,tam-1);
			printf("\n - QUICK:\tTroca: %d\tComparacao: %d",troca_quick,comp_quick);
			ac_quick_troc += troca_quick;
			ac_quick_comp += comp_quick;
			troca_quick = 0;
			comp_quick = 0;
			
			for(z=0; z<tam; z++) cop[z]=vet[z];
			merge_sort(cop,0,tam-1);
			printf("\n - MERGE:\tTroca: %d\tComparacao: %d",troca_merge,comp_merge);
			ac_merge_troc += troca_merge;
			ac_merge_comp += comp_merge;
			troca_merge = 0;
			comp_merge = 0;
			
		}

		fprintf(arquivo,"\n\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
		printf("\n\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
		fprintf(arquivo," - Resultado das Medias da %da Rodada com %d Vetores de [%d] posicoes:\n",rodada,qtd,tam);
		printf(" - Resultado das Medias da %da Rodada com Vetores de [%d] posicoes:\n",rodada,tam);
		
		md_select_troc = ac_select_troc/qtd;
		md_select_comp = ac_select_comp/qtd;
		printf("\n - MEDIA SELECTION:\tTroca: %d\tComparacao: %d",md_select_troc,md_select_comp);
		fprintf(arquivo,"\n - MEDIA SELECTION:\tTroca: %d\tComparacao: %d",md_select_troc,md_select_comp);

		md_insert_troc = ac_insert_troc/qtd;
		md_insert_comp = ac_insert_comp/qtd;
		printf("\n - MEDIA INSERTION:\tTroca: %d\tComparacao: %d",md_insert_troc,md_insert_comp);
		fprintf(arquivo,"\n - MEDIA INSERTION:\tTroca: %d\tComparacao: %d",md_insert_troc,md_insert_comp);
		
		md_bubble_troc = ac_bubble_troc/qtd;
		md_bubble_comp = ac_bubble_comp/qtd;		
		printf("\n - MEDIA BUBBLE:\tTroca: %d\tComparacao: %d",md_bubble_troc,md_bubble_comp);
		fprintf(arquivo,"\n - MEDIA BUBBLE:\tTroca: %d\tComparacao: %d",md_bubble_troc,md_bubble_comp);
		
		md_shell_troc = ac_shell_troc/qtd;
		md_shell_comp = ac_shell_comp/qtd;
		printf("\n - MEDIA SHELL:\t\tTroca: %d\tComparacao: %d",md_shell_troc,md_shell_comp);
		fprintf(arquivo,"\n - MEDIA SHELL:\t\tTroca: %d\tComparacao: %d",md_shell_troc,md_shell_comp);		

		md_heap_troc = ac_heap_troc/qtd;
		md_heap_comp = ac_heap_comp/qtd;
		printf("\n - MEDIA HEAP:\t\tTroca: %d\tComparacao: %d",md_heap_troc,md_heap_comp);
		fprintf(arquivo,"\n - MEDIA HEAP:\t\tTroca: %d\tComparacao: %d",md_heap_troc,md_heap_comp);
		
		md_quick_troc = ac_quick_troc/qtd;
		md_quick_comp = ac_quick_comp/qtd;
		printf("\n - MEDIA QUICK:\t\tTroca: %d\tComparacao: %d",md_quick_troc,md_quick_comp);
		fprintf(arquivo,"\n - MEDIA QUICK:\t\tTroca: %d\tComparacao: %d",md_quick_troc,md_quick_comp);

		md_merge_troc = ac_merge_troc/qtd;
		md_merge_comp = ac_merge_comp/qtd;
		printf("\n - MEDIA MERGE:\t\tTroca: %d\tComparacao: %d\n\n",md_merge_troc,md_merge_comp);
		fprintf(arquivo,"\n - MEDIA MERGE:\t\tTroca: %d\tComparacao: %d\n\n",md_merge_troc,md_merge_comp);
		
		tam += 50;
		vet = (int*)realloc(vet,tam*sizeof(int));
		cop = (int*)realloc(cop,tam*sizeof(int));

		ac_select_troc = 0; ac_select_comp = 0;
		ac_insert_troc = 0; ac_insert_comp = 0;
		ac_bubble_troc = 0; ac_bubble_comp = 0;
		ac_shell_troc  = 0; ac_shell_comp  = 0;
		ac_heap_troc   = 0; ac_heap_comp   = 0;
		ac_quick_troc  = 0; ac_quick_comp  = 0;
		ac_merge_troc  = 0; ac_merge_comp  = 0;
	}
	fclose(arquivo);
	free(vet);
	free(cop);
	system("start resultados.txt");
}


void insertion_sort(int *original, int n) {
	int i, j, atual;
	for (i = 1; i < n; i++)
	{
		atual = original[i];	
		j = i - 1;
		comp_insert++;
		while ((j >= 0) && (atual < original[j])) {
			original[j + 1] = original[j];
			j--;
			comp_insert++;
			troca_insert++;
        }
		original[j+1] = atual;
	}
}

void selection_sort(int *nrs, int tam) {
 int i, j, min, aux;
 
 for(i = 0; i < tam - 1; i++)
 {
	min = i;
	for(j= i + 1; j < tam ; j++) 
	{
		comp_select++;
    	if ( nrs[j] < nrs[min] ) {
        	min = j;
        	troca_select++;
        }
    }
	aux = nrs[i];
	nrs[i] = nrs[min];
	nrs[min] = aux;
   }
} 
    
void bubble_sort(int *nrs, int tam) {
	int i, j, aux;
	for(i = 0; i < tam - 1 ; i++)
		for(j= 0; j < tam - 1 ; j++) {
			comp_bubble++;
	        if ( nrs[j] > nrs[j+1] ) {
	        	troca_bubble++;
	            aux = nrs[j];
	            nrs[j] = nrs[j+1];
	            nrs[j+1] = aux;
	        }
		}
}

void heap_sort(int *a, int n) { 
   int i = n / 2, pai, filho, t;
   while(1) 
   {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0)
		  {
          	return;
		  }
          t = a[n];
          a[n] = a[0];
          troca_heap++;
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) 
	  {
		  if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho])) 
		  {
		  	filho++;
		  	comp_heap++;
		  }
		  comp_heap++;	 	  
          if (a[filho] > t) {
			 a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
             troca_heap++;
          } else {
              break;
          }
      }
	  a[pai] = t;
   }
}

void shell_sort(int *vvet, int size) {
    int i , j , value;
    int gap = 1;
	while(gap < size)
	{
        gap = 3*gap+1;
    }
	while ( gap > 1) 
	{
        gap /= 3;        
        for(i = gap; i < size; i++) 
		{
			comp_shell++;
            value = vvet[i];
            j = i;
            
            while (j >= gap && value < vvet[j - gap]) 
			{
                vvet[j] = vvet[j - gap];
                j = j - gap;
                troca_shell++;
                comp_shell++;
            }
            vvet[j] = value;
        }
    }
}

void quick_sort(int *nrs, int esquerda, int direita) {
    int i, j, meio, aux;
    i = esquerda;
    j = direita;
    meio = nrs[(esquerda + direita) / 2];

    while(i <= j) 
	{	
        while(nrs[i] < meio && i < direita)  {         
            i++;
            comp_quick++;
        }
        while(nrs[j] > meio && j > esquerda) {
            j--;
        	comp_quick++;
        }
        if(i <= j)  
		{
            aux = nrs[i];
            nrs[i] = nrs[j];
            nrs[j] = aux;
            i++;
            j--;
            troca_quick++;
        }
    }
    
    if(j > esquerda)
    {
        quick_sort(nrs, esquerda, j);
        comp_quick++;
    }
    if(i < direita)
    {
        quick_sort(nrs,  i, direita);
        comp_quick++;
    }
}

void merge(int *vetor, int comeco, int meio, int fim) { 
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim)
	{	
		comp_merge++;
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }
    
    while(com1 <= meio) {
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
        troca_merge++;
    }
    while(com2 <= fim) {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
        troca_merge++;
    }
    for(comAux = comeco; comAux <= fim; comAux++){
        vetor[comAux] = vetAux[comAux-comeco];
    }
    free(vetAux);
}

void merge_sort(int *vetor, int comeco, int fim) {
    if (comeco < fim) {
        int meio = (fim+comeco)/2;
        merge_sort(vetor, comeco, meio);
        merge_sort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

		
