#! python3
# 10280 Old Wine Into New Bottles

# IMPORTS

# DEFINES
capacidadeMax = 4500+1
vetorMin = list(range(100))
vetorMax = list(range(100))
# maxLitros = 1000000


T = int(input())

while T > 0:
	# print()
	T -= 1
	cont = 0
	soma = 0
	limite = 1000000 # maxLitros

	memo = [0 for i in range(capacidadeMax)]
	garrafa = [0 for i in range(capacidadeMax)]

	l,s = input().split(' ')
	l = int(l) # amount of wine to be bottled (0 > l > 1,000,000) (em LITROS)
	l *= 1000 # conversao L -> mL
	s = int(s) # number of sizes of bottles (1 > s > 100)

	for i in range(s):
		MIN,MAX = input().split(' ') # minimum and maximum capacity of each bottle (em mililitros)
		vetorMax[i] = int(MAX)
		vetorMin[i] = int(MIN)

		for j in range(vetorMin[i],vetorMax[i]+1):
			if memo[j] == 0:
				garrafa[cont] = j
				cont += 1
				memo[j] = 1
				# soma += j
		# endfor

		limite = min(limite,(vetorMin[i] * vetorMin[i]) / (vetorMax[i] - vetorMin[i]))
	# endfor

	if l >= limite:
		print(0)
		if T > 0:
			print()
		# break
		continue # vai pra proxima interação

	aux = [0 for i in range(capacidadeMax*10)]
	for i in range(cont+1):
		for j in range(garrafa[i],l+1):
			aux[j] = max(aux[j], aux[j - garrafa[i]] + garrafa[i]);


	print(l-aux[l])

	if T > 0:
		print()
# endwhile