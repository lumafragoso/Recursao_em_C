#include <stdio.h>

void inverte(num){

    //CASO BASE
    if(num/2 ==0){
        printf("%d", num%2);
    }
    //CHAMAR A RECURSÃO
    else{
        inverte(num/2);
        printf("%d", num%2);
    }
}

int main(){
    int numero;

    //LER ENTRADA
    scanf("%d", &numero);

    //CHAMAR A FUNÇÃO PARA INVERTER
    inverte(numero);

    return 0;
}