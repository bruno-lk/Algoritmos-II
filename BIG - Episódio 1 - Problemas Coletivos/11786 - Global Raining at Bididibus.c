/* 11786 - Global Raining at Bididibus */
// Grupo: Bruno, Guilherme e Italo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int x,unidade,largura;
    int i,j,k,tam;
    int altura[10000];
    char input[10000];

    scanf("%d",&x);

    for(i=0;i<x;i++){
        scanf("%s",input);
        tam = strlen(input);
        unidade = 0;
        k = 0;

        for(j=0;j<tam;j++){
            if(input[j] == '/'){
                altura[j] = ++k;
            }else{
                if(input[j] == '\\'){
                    altura[j] = --k;
                }else{
                    altura[j] = k;
                }
            }
        }

        for(j=0;j<tam;j++){
            largura = 0;
            if(input[j] == '\\'){
                k = j;
                while( (altura[j]+1 != altura[k]) && (k<tam) ){
                    k++;
                    largura++;
                }

                if(k <= tam){
                    if(input[k] == '/'){
                        unidade = unidade + largura;
                    }
                }
            }
        }

        printf("%d\n",unidade);
    }

    return 0;
}
