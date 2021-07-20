#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char Principal;
	int jafoi;	
} CampoMinado;

void inicializar(int n, int m, CampoMinado** camp){
    int i, j;

    for (i = 0; i < n; i++){
        for (j= 0; j < m; j++){
            //DENTRO DA MATRIZ
            if(i!=0 && j!=0 && i!= n-1 && j!=m-1){
                camp[i][j].jafoi=0;
            }
            //BORDA
            else{
                camp[i][j].jafoi=1;
            }
            //printf("%d",camp[i][j].jafoi);
            camp[i][j].Principal = '0';
        }
        //printf("\n");
    }
}
void bomb_perto(CampoMinado** tab, int lin, int col){
    int B, xB, yB, quantidade_bomb=0;
    int i, j, k;
    //LER A QUANTIDADE DE BOMBAS
    scanf("%d", &B);

    //LER AS POSIÇÕES DAS BOMBAS E COLOCAR NO MAPA
    for (i = 0; i < B; i++){
        scanf("%d %d", &xB, &yB);
        tab[xB][yB].Principal = 'B';
    }

    //POSSÍVEIS CASOS SEM CONTAR AS BORDAS
    for (j = 1; j < lin; j++){
        for (k = 1; k < col; k++){
            if(tab[j][k].Principal != 'B'){
                //DIAGONAL INFERIOR DIREITA
                if(tab[j+1][k+1].Principal=='B'){
                    quantidade_bomb++;
                }
                //SUL
                if(tab[j+1][k].Principal=='B'){
                    quantidade_bomb++;
                }
                //DIAGONAL INFERIOR ESQUERDA
                if(tab[j+1][k-1].Principal=='B'){
                    quantidade_bomb++;
                }
                //DIAGONAL SUPERIOR DIREITA
                if(tab[j-1][k+1].Principal=='B'){
                    quantidade_bomb++;
                }
                //NORTE
                if(tab[j-1][k].Principal=='B'){
                    quantidade_bomb++;
                }
                //DIAGONAL SUPERIOR ESQUERDA
                if(tab[j-1][k-1].Principal=='B'){
                    quantidade_bomb++;
                }
                //DIREITA
                if(tab[j][k+1].Principal=='B'){
                    quantidade_bomb++;
                }
                //ESQUERDA
                if(tab[j][k-1].Principal=='B'){
                    quantidade_bomb++;
                }

                tab[j][k].Principal = quantidade_bomb + '0';
                //printf("%c",tab[j][k].Principal);
            }
            //ATUALIZAÇÃO
            quantidade_bomb=0;
        }
        //printf("\n");
    }
    
}

void abrir_recursividade(CampoMinado** c, int li, int co){
    if(c[li][co].jafoi==1){
        return;
    }

    c[li][co].jafoi=1;

    if(c[li][co].Principal=='B'){
        c[li][co].Principal='X';
        return;
    }
    else if(c[li][co].Principal=='0'){
        abrir_recursividade(c, li+1, co+1);
        abrir_recursividade(c, li+1, co);
        abrir_recursividade(c, li+1, co-1);
        abrir_recursividade(c, li-1, co+1);
        abrir_recursividade(c, li-1, co);
        abrir_recursividade(c, li-1, co-1);
        abrir_recursividade(c, li, co+1);
        abrir_recursividade(c, li, co-1);
    }
    return;
}
void imprime(CampoMinado** t, int l, int c){
    int i=0, j=0, k=0;

    for (i = 0; i < c+1; i++){
        printf("=");
    }
    printf("\n");

    for (j = 1; j < l; j++){
        for (k = 1; k < c; k++){
            if(t[j][k].jafoi ==0){
                printf("*");
            }
            else{
                printf("%c",t[j][k].Principal);
            }
        }
        printf("\n");
    }
    
    
}

void jogada(CampoMinado** tabuleiro, int J, int L, int C){
    int j, linha, coluna, a;
    //VARIÁVEL PARA RECEBER A JOGADA
    char jogada[11];

    //LER A QUANTIDADE DE JOGADAS J
    scanf("%d", &J);

    //LER AS JOGADAS
    for (j = 0; j < J; j++){
        scanf("%s %d %d\n", jogada, &linha, &coluna);

        if(jogada[0]== 'C'){
            abrir_recursividade(tabuleiro, linha, coluna);

            //printf("%c",tabuleiro[linha][coluna].Principal);
            if(tabuleiro[linha][coluna].Principal == 'X'){
                printf("CABUUUUM!\n");
		        printf("Game Over....\n");
			    break;
            }
        }
        else if(jogada[0]== 'M'){
            tabuleiro[linha][coluna].jafoi= 1;
        }
        a=0;
        imprime(tabuleiro, L-1, C-1);

        if(j==J-1){
            printf("Você sobreviveu!\n");
        }
    }
}


int main(){
    //VARIÁVEIS SOLICITADAS NO PROBLEMA
    int N, M, J, quantidade_bomb;
    //VARIÁVEIS DE LOOP
    int i, j, k, h;

    //VALORES DA ENTRADA LINHA E COLUNA
    scanf("%d %d", &N, &M);
    N += 2;
    M += 2;

    //ALOCAR DINAMICAMENTE A MATRIZ
    CampoMinado **campo = malloc(sizeof(CampoMinado*)*N);
    for (i = 0; i < N; i++){
        campo[i] = malloc(sizeof(CampoMinado)*M);
    }

    //COLOCAR AS DIMENSÇÕES DOS CAMPOS E AS VARIÁVEIS JAFOI E NFOI
    inicializar(N, M, campo);
    
    bomb_perto(campo, N-1, M-1);

    jogada(campo, J, N, M);

    for (j = 0; j < M; j++){
        printf("=");
    }
    printf("\n");
    for (k = 1; k < N-1; k++){
        for (h = 1; h < M-1; h++){
            printf("%c", campo[k][h].Principal);
        }
        printf("\n");
    }
    
    return 0;
}