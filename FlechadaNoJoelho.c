#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	char nome[21];
  int valor, peso;
}elementos;

typedef struct{
	char *pont_itens;
	int quant_itens;
	int valTotal_itens;
	int pesTotal_itens;
}cadaCombinacao;

typedef struct{
	int *pont_combi;
	int  combi_total;
}totalCombinacao;

int printSubset(elementos arr[], int n, int r, int index, cadaCombinacao data[], int i, int k){
  int count=0;
  if (index == r){
    for (int j = 0; j < r; j++){
      if(r > 1){
        data[k].valTotal_itens += data[j].valTotal_itens;
        count ++;
        if(count==r){
          printf("%d\n", data[k].valTotal_itens);
          k++;
          //count=0;
        }
      }else{
        data[k].valTotal_itens = data[j].valTotal_itens;
        printf("%d\n", data[k].valTotal_itens);
        k++;
      }
    }
    //k++;
    printf("\n");
    return -1;
  }
  if (i >= n) {
    return k;
  }
  data[index].valTotal_itens = arr[i].valor;
  printSubset(arr, n, r, index + 1, data, i + 1, k);
  printSubset(arr, n, r, index, data, i + 1, k);
}

int main()
{
	int q, p;
	scanf("%d %d", &q, &p);
	elementos itens[q];
	for (int i = 0; i < q; ++i){
		scanf("%s %d %d", itens[i].nome, &itens[i].valor, &itens[i].peso);
	}
  int n = sizeof(itens) / sizeof(itens[0]);
  int r=1;
  static int k=0;
  int aux=0;
  for(int j=0; j< pow(q,2); j++){
    cadaCombinacao data[r];
    aux = printSubset(itens, n, r, 0, data, 0, k);
    if(aux != -1){
      k = aux;
      aux=0;
    }
    //printSubset(itens, n, r, 0, data, 0, k);
    r++;
  }

	return 0;
}

/*void printSubset(int arr[], int n, int r, int index, int data[], int i);
int main(){
   int arr[] = {3 , 5, 6};
   int r = 2;
   //printf("The sets are : ");
   int n = sizeof(arr) / sizeof(arr[0]);
   int data[r];
   printSubset(arr, n, r, 0, data, 0);
   return 0;
}
void printSubset(int arr[], int n, int r, int index, int data[], int i){
  if (index == r) {
    for (int j = 0; j < r; j++) {
      printf("%d ", data[j]);
    }
    printf("\n");
    return;
  }
  if (i >= n) {
    return;
  }
  data[index] = arr[i];
  printSubset(arr, n, r, index + 1, data, i + 1);
  printSubset(arr, n, r, index, data, i + 1);
}*/