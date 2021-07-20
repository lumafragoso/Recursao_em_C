#include <stdio.h>

int mdc(int n1, int n2){
    //CASO BASE
    if(n2==0){
        return n1;
    }
    //OUTROS CASOS COM RECURSÃO
    else{
        return mdc(n2, n1%n2);
    }
}

int main(){
    int A, B, C, D;

    scanf(" %d %d %d", &A, &B, &C);

    //PRIMEIRO MDC ENTRE DOIS NÚMEROS
    D= mdc(A, B);

    //CHAMA A FUNÇÃO COM O RESULTADO DO PRIMEIRO MDC E O NÚMERO Q FALTOU
    printf("MDC de %d, %d e %d: %d", A, B, C, mdc(D, C));
    
}