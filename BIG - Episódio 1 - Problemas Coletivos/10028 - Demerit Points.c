// Grupo: Bruno, Guilherme e Italo

#include <stdio.h>
#include <math.h>

void imprime (int ano, int mes, int dia, int merito, int demerito){
    printf("%d-", ano);
    if(mes < 10){
        printf("0%d-", mes);
    }
    else{
        printf("%d-",mes);
    }
    if(dia < 10){
        printf("0%d ", dia);
    }
    else{
        printf("%d ",dia);
    }

    if ((merito == 0) && (demerito == 0)){
        printf("No merit or demerit point(s).\n");
    }
    if (merito > 0){
        printf("%d merit point(s).\n", merito);
    }
    if (demerito > 0){
        printf("%d demerit point(s).\n", demerito);
    }
    return;
}

int main(){
    unsigned int merito=0, demerito=0;
    int data, proximo=0, total=0;
    int ano, mes, dia, resto, ultimo, ponto=0;

    scanf("%d", &total);

    while(total > 0){
        merito = demerito = 0;
        proximo = 0;

        if (ponto <= 15){
                scanf("%d", &data);
        }

        proximo = data + 20000;
        ultimo = data;

        ano = data/10000;
        resto = data%10000;
        mes = resto/100;
        dia = resto%100;

        imprime(ano, mes, dia, merito, demerito);
        //printf("%d-%d-%d No merit or demerit point(s).\n", ano, mes, dia);

        if(ponto > 15){
            data = ponto;
        }
        while(1){
            if (ponto <= 15){
                scanf("%d%d", &data, &ponto);
            }

            if ((merito == 5)&&(ponto>15)){
                    break;
            }

            if (data == ponto){
                scanf("%d", &ponto);
            }

            //redução demerito
            while((proximo <= data) || (ponto > 15)){
                ano = proximo/10000;
                if ((demerito == 0) && (merito < 5)){
                    merito++;
                    imprime(ano, mes, dia, merito, demerito);
                    //printf("%d-%d-%d %d merit point(s).\n", ano, mes, dia, merito);
                    if(merito == 5){
                        break;
                    }
                    proximo += 20000;
                }
                else{
                    if ((demerito/2) <= (demerito-2)){
                        demerito = demerito/2;
                        imprime(ano, mes, dia, merito, demerito);
                        //printf("%d-%d-%d %d demerit point(s).\n", ano, mes, dia, demerito);
                        proximo += 10000;
                    }
                    else{
                        demerito -= 2;
                        imprime(ano, mes, dia, merito, demerito);
                        //printf("%d-%d-%d No merit or demerit point(s).\n", ano, mes, dia);
                        proximo += 20000;
                    }
                }
            }

            //se ainda tem entrada
            if (ponto <= 15){
                ano = data/10000;
                resto = data%10000;
                mes = resto/100;
                dia = resto%100;

                //entrada de demerito
                if(merito > 0){
                    if (ponto > (2*merito)){
                        demerito = ponto-(2*merito);
                        merito = 0;
                        imprime(ano, mes, dia, merito, demerito);
                        //printf("%d-%d-%d %d demerit point(s).\n", ano, mes, dia, demerito);
                        proximo = data + 10000;
                    }
                    else{
                        demerito = 0;
                        merito -= (demerito/2);
                        if(merito == 0){
                            imprime(ano, mes, dia, merito, demerito);
                            //printf("%d-%d-%d No merit or demerit point(s).\n", ano, mes, dia);
                        }
                        else{
                            imprime(ano, mes, dia, merito, demerito);
                            //printf("%d-%d-%d %d merit point(s).\n", ano, mes, dia, merito);
                        }
                        proximo += 20000;
                    }
                }
                else{
                    demerito += ponto;
                    imprime(ano, mes, dia, merito, demerito);
                    //printf("%d-%d-%d %d demerit point(s).\n", ano, mes, dia, demerito);
                    proximo = data + 10000;
                }
            }
        }
        total--;
        printf("\n");
    }
}
