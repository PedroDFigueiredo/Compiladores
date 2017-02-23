//iniEscopo:1 1

//DECLARA_PARAM:a:

//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:var1_1::size:0:
//DECLARA_E_ATRIBUI::1 1 FIM_1
//DeA:b:var1_1::

//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:var1_3::size:0:
//DECLARA_E_ATRIBUI::1 1 FIM_1
//DeA:c:var1_3::

//NUMEROS TK_ID:b
//NUMEROS TK_ID:c
//ARITMETICO::1 1 FIM_1
//:var1_4::var1_5:
//ATRIBUICAO::1 1 FIM_1//ATRIBUICAO:::var1_7:
//if else:var1_0:var1_7::

//BLOCO
/*Compilador FOCA*/
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

	bool var1_0;  //variavel: a
	int var1_1; 
	int var1_2;  //variavel: b
	int var1_3; 
	int var1_4;  //variavel: c
	int var1_5; 
	int var1_6; 
	bool var1_7; 

int main(void)
{


	var1_1 = 20;
	var1_2 = var1_1;
	var1_3 = 15;
	var1_4 = var1_3;
	var1_5 = 10;
	var1_6 = var1_4 + var1_5;
	var1_7 = var1_2 < var1_6;
	var1_0 = var1_7;
	return 0;
}

