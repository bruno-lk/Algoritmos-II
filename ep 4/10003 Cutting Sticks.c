/*
    10003 Cutting Sticks
*/

#include <stdio.h>

int i, j, k, l, n, aux;
int vetorCorte[60], memo[60][60];

int minimun(int ini, int fim){
    int min;

    if( (fim - ini) == 1 )
        return 0;

    if(memo[ini][fim] != -1)
        return memo[ini][fim];

    min = minimun(ini,ini+1) + minimun(ini+1,fim) + (vetorCorte[fim] - vetorCorte[ini]);

    for(i=(ini+1);i<fim;i++){
        aux = ((vetorCorte[fim] - vetorCorte[ini]) + minimun(ini,i) + minimun(i,fim));
        if(min > aux)
            min = aux;
    }

    memo[ini][fim] = min;
    return min;
}

int main(){

    while(1){
        scanf("%d",&l);
        if(l == 0)
            break;

        vetorCorte[0] = 0;

        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&vetorCorte[i]);
        }

        vetorCorte[n+1] = l;

        for(i=0;i<60;i++){
            for(j=0;j<60;j++){
                memo[i][j] = -1;
            }
        }

        printf("The minimum cutting is %d.\n", minimun(0,n+1));

    }

    return 0;
}
