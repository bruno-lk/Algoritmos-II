# 10706 Number Sequence
# def tamanho(n):
#     res = 0
#
#     while(int(n)):
#         res +=1
#         n /= 10
#
#     return res

# def contaDigitos(n):
#     if(n < 10):
#         return n
#     else:
#         return contaDigitos(n - 1) + len( str(n) )

# def somaCumulativa(n):
#     if(n == 1):
#         return 1
#     else:
#         return somaCumulativa(n - 1) + contaDigitos(n)

def achaSequencia(p,vetor,vetor2):
    l = 0
    h = 40000

    while(l <= h):
        m = int( (l+h)/2 )

        if(vetor[m] < p):
            if(vetor[m+1] >= p):
                break
            else:
                l = m+1
        else:
            h = m - 1

    print(vetor2[p - vetor[m] -1 ])

def main():
    vetor = list(range(40000))
    vetor2 = "" # vetor com sequencia normal
    temp = 0

    for i in range(1,40000):    # cria vetor soma
        vetor2 += str(i)
        temp += len(str(i))
        vetor[i] = vetor[i - 1] + temp

    t = int(input())  # numero de testes

    while(t):
        t -= 1  # contador do while
        i = 0

        p = int(input())    # posição que que deseja encontrar

        achaSequencia(p,vetor,vetor2)

##############################################################

main()
