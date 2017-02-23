//iniEscopo:1 1

//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:var1_0::size:0:
//DECLARA_E_ATRIBUI::1 1 FIM_1
//DeA:a:var1_0::

//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:var1_2::size:0:
//DECLARA_E_ATRIBUI::1 1 FIM_1
//DeA:c:var1_2::

//DECLARA_PARAM:b:

//NUMEROS TK_ID:a
//NUMEROS TK_ID:c
//ATRIBUICAO::1 1 FIM_1//ATRIBUICAO:::var1_5:
//if else:var1_4:var1_5::

//NUMEROS TK_ID:b


//BLOCO
/*Compilador FOCA*/
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

	int var1_0; 
	int var1_1;  //variavel: a
	int var1_2; 
	int var1_3;  //variavel: c
	bool var1_4;  //variavel: b
	bool var1_5; 

int main(void)
{


	var1_0 = 10;
	var1_1 = var1_0;
	var1_2 = 20;
	var1_3 = var1_2;
	var1_5 = var1_1 or var1_3;
	var1_4 = var1_5;
	cout << var1_4 <<"\n";
	return 0;
}

