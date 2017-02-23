all: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -lfl

		./glf < exemplos/aritmetico.ex > resultados/aritmetico.c
		./glf < exemplos/relacional.ex > resultados/relacional.c
		./glf < exemplos/logico.ex > resultados/logico.c
		./glf < exemplos/bloco.ex > resultados/bloco.c
		./glf < exemplos/cin.ex > resultados/cin.c
		./glf < exemplos/switch.ex > resultados/switch.c
		./glf < exemplos/loop.ex > resultados/loop.c
		./glf < exemplos/concatenacao.ex > resultados/concatenacao.cpp
		./glf < exemplos/vetor.ex > resultados/vetor.cpp