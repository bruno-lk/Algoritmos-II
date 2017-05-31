/* 1586 - Molar mass

        Pesos AtomicoS
Carbono:        12.01 g/mol
Hidrogenio:     1.008 g/mol
Oxigenio:       16 g/mol
Notrogeion:     14.01 g/mol

T = casos de teste
quando for 'n' == 1, 'n' será omitido

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    int t,tam;
    int i,j;
    float soma;
    float vetor[80];
    char formula[80];

    scanf("%d", &t);

    for(i=0;i<t;i++){
        scanf("%s", formula);
        tam = strlen(formula);
        soma = 0;

        for(j=0;j<tam;j++){
            switch (formula[j]){
            case 'C':
                if(!isdigit(formula[j+1])){
                    soma = soma + 12.01;
                }
                else{
                    if(isdigit(formula[j+1])){
                        if(isdigit(formula[j+2])){
                            soma = soma + (12.01 * ( ( ((int)( (formula[j+1]) - '0')) * 10) + ((int)((formula[j+2]) - '0') ) ) ) ;
                        }
                        else{
                            soma = soma + (12.01 * (int)((formula[j+1]) - '0'));
                        }
                    }
                }
                break;
            case 'H':
                if(!isdigit(formula[j+1])){
                    soma = soma + 1.008;
                }
                else{
                    if(isdigit(formula[j+1])){
                        if(isdigit(formula[j+2])){
                            soma = soma + (1.008 * ( ( ((int)( (formula[j+1]) - '0')) * 10) + ((int)((formula[j+2]) - '0') ) ) ) ;
                        }
                        else{
                            soma = soma + (1.008 * (int)((formula[j+1]) - '0'));
                        }
                    }
                }
                break;
            case 'O':
                if(!isdigit(formula[j+1])){
                    soma = soma + 16;
                }
                else{
                    if(isdigit(formula[j+1])){
                        if(isdigit(formula[j+2])){
                            soma = soma + (16 * ( ( ((int)( (formula[j+1]) - '0')) * 10) + ((int)((formula[j+2]) - '0') ) ) ) ;
                        }
                        else{
                            soma = soma + (16 * (int)((formula[j+1]) - '0'));
                        }
                    }
                }
                break;
            case 'N':
                if(!isdigit(formula[j+1])){
                    soma = soma + 14.01;
                }
                else{
                    if(isdigit(formula[j+1])){
                        if(isdigit(formula[j+2])){
                            soma = soma + (14.01 * ( ( ((int)( (formula[j+1]) - '0')) * 10) + ((int)((formula[j+2]) - '0') ) ) ) ;
                        }
                        else{
                            soma = soma + (14.01 * (int)((formula[j+1]) - '0'));
                        }
                    }
                }
                break;
            }
        }
        vetor[i] = soma;
    }

    for(i=0;i<t;i++){
        printf("%.3f\n",vetor[i]);
    }

    return 0;
}
