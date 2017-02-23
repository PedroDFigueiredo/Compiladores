//iniEscopo:1 1

//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:var1_0::size:0:
//DECLARA_E_ATRIBUI::1 1 FIM_1
//DeA:a:var1_0::




//NUMEROS TK_ID:a
//iniEscopo:2 2

//NUMEROS TK_ID:a


//BLOCO
//TK_WHILE::2 2 FIM_2_2
//fimEscopo:2 2


//NUMEROS TK_ID:a


//BLOCO
/*Compilador FOCA*/
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

	int var1_0; 
	int var1_1;  //variavel: a
	int var1_2; 
	bool var1_3; 

int main(void)
{


	var1_0 = 0;
	var1_1 = var1_0;
	var1_1 = var1_1 - 1;
//ini_while
INI_2:
	var1_2 = 10;
	var1_3 = var1_1 < var1_2;

	if (!(var1_3)) goto FIM_2;
	cout << var1_1 <<"\n";
	var1_1 = var1_1 + 1;

	goto INI_2;

FIM_2:
//fim_while

	cout << var1_1 <<"\n";
	return 0;
}

