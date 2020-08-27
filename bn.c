#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define dimensao 8

void show_matrix(int matrix[dimensao][dimensao])
{
    int i,j;
    for(i=0; i<dimensao; i++)
    {    
        for(j=0; j<dimensao; j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }   
}       

int main()
{
    // INICIALIZA MATRIZ
    int matrix[dimensao][dimensao];
    int i,j;
    for(i=0; i<dimensao; i++)
        for(j=0; j<dimensao; j++)
            matrix[i][j] = 0;

//PREENCHE TABULEIRO COM NAVIOS
    int input,X,Y;
    char orientação[15];
    while(input != -1) 
    {
        printf("\nPara parar digite -1. Digite o próximo barco(0-5): ");
        scanf("%d",&input);
        fflush(stdin);
        if(input == -1)
        {
            break;
        }
        else
        {
            printf("Digite a orientação, (vertical ou horizontal): ");
            scanf("%s",orientação);
            fflush(stdin);
            printf("Digite as coordenadas do canto esquerdo superior (X,Y) do barco: ");
            scanf("%d",&X);
            fflush(stdin);
            scanf("%d",&Y);
            fflush(stdin);
            if(strcmp (orientação,"vertical") == 0)
            {
                int flag,cont=0;
                i=X;
                // PERCORRE AS CASAS QUE SERÃO PREENCHIDAS PELO BARCO E VERIFICA SE HÁ OUTRO BARCO
                while(cont<input && i<dimensao && flag != 1)
                {
                    if(matrix[i][Y] != 0)
                        flag = 1;
                    i++;
                    cont++;
                }
                // PREENCHE SE NÃO HOUVER CASA OCUPADA
                if(flag != 1)
                {
                    int cont=0;
                    i=X;
                    while(cont<input && i<dimensao)
                    {
                        matrix[i][Y] = input;
                        i++;
                        cont++;
                    }
                    printf("BARCO POSICIONADO!\n");
                    show_matrix(matrix);                    
                }
                // MENSAGEM DE ERRO CASO ALGUMA CASA JA ESTEJA OCUPADA
                else
                {
                    printf("As coordenadas %d,%d já estão ocupadas, confome abaixo:\n",X,Y);
                    show_matrix(matrix);
                }
            }
            else if(strcmp (orientação,"horizontal") == 0)
            {
                int flag,cont=0;
                i=Y;
                // PERCORRE AS CASAS QUE SERÃO PREENCHIDAS PELO BARCO E VERIFICA SE HÁ OUTRO BARCO
                while(cont<input && i<dimensao && flag != 1)
                {
                    if(matrix[X][i] != 0)
                        flag = 1;                    
                    i++;
                    cont++;
                }
                if(flag != 1)
                {
                    int cont=0;
                    i=Y;                 
                    while(cont<input && i<dimensao)
                    {
                        matrix[X][i] = input;
                        i++;
                        cont++;
                    }
                    printf("\nBARCO POSICIONADO!\n");
                    show_matrix(matrix);
                }
                // MENSAGEM DE ERRO CASO ALGUMA CASA JA ESTEJA OCUPADA
                else
                {
                    printf("As coordenadas %d,%d já estão ocupadas, confome abaixo:\n",X,Y);
                    show_matrix(matrix);
                }
            }
        }
    }
// AFUNDA NAVIOS
    int shots = 0,empty = 0,x,y;
    while(empty == 0)
    {
        x = rand()%8;
        y = rand()%8;
        if(matrix[x][y] != 0)
        {
            shots++;
            matrix[x][y] = 0;
            printf("As coordenadas %d,%d agoram são água!\n",x,y);
        }
        empty = 1;
        for(i=0; i<dimensao; i++)
        {
            if(empty == 0)
                break;
            for(j=0; j<dimensao; j++)
                if(matrix[i][j] > 0)
                {
                    empty = 0;
                    break;
                }
        }
    }

// IMPRIME RESULTADOS
    printf("\nNúmero de tiros dados: %d",shots);
    printf("\nTABULEIRO FINAL:\n");
    show_matrix(matrix);
    return 0;
}
