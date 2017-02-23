//iniEscopo:1 1


//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:var1_0::size:0:
//DECLARA_E_ATRIBUI::1 1 FIM_1
//DeA:b:var1_0::

//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:var1_2::size:0:
//DECLARA_E_ATRIBUI::1 1 FIM_1
//DeA:c:var1_2::

//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:var1_4::size:0:
//DECLARA_E_ATRIBUI::1 1 FIM_1
//DeA:a:var1_4::


//iniEscopo:2 2
//NUMEROS TK_ID:a

//iniEscopo:3 3
//ATRIBUICAO::3 3 FIM_3//ATRIBUICAO:::var3_8:
//if else:var1_3:var3_8::
//BLOCO:: 3 3
//IF::3 3 FIM_3
//fimEscopo:3 3

//NUMEROS TK_ID:a
//iniEscopo:3 4

//ATRIBUICAO::3 4 FIM_4//ATRIBUICAO:::var3_11:
//if else:var1_3:var3_11::

//BLOCO
//TK_ELIF ELSE::3 4 FIM_4
//fimEscopo:3 4


//NUMEROS TK_ID:a

//iniEscopo:3 5
//ATRIBUICAO::3 5 FIM_5//ATRIBUICAO:::var3_14:
//if else:var1_3:var3_14::
//BLOCO:: 5 3
//TK_ELIF ELSE::3 5 FIM_5
//fimEscopo:3 5


//iniEscopo:3 6

//ATRIBUICAO::3 6 FIM_6//ATRIBUICAO:::var3_15:
//if else:var1_3:var3_15::

//BLOCO
//TK_ELSE::3 6 FIM_6
//fimEscopo:3 6


//ELSEs::2 2 FIM_2 -->
//ELSEs::2 2 FIM_2 -->
//CONDICIONAL ELSEs::2 2 FIM_2
//fimEscopo:2 2
//NUMEROS TK_ID:c





//BLOCO
/*Compilador FOCA*/
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

	int var1_0; 
	int var1_1;  //variavel: b
	int var1_2; 
	int var1_3;  //variavel: c
	int var1_4; 
	int var1_5;  //variavel: a
	bool var2_10; 
	int var2_12; 
	bool var2_13; 
	int var2_6; 
	bool var2_7; 
	int var2_9; 
	int var3_8; 
	int var3_11; 
	int var3_14; 
	int var3_15; 

int main(void)
{


	var1_0 = 4;
	var1_1 = var1_0;
	var1_2 = 0;
	var1_3 = var1_2;
	var1_4 = 15;
	var1_5 = var1_4;

//ini_if
	var2_6 = 0;
	var2_7 = var1_5 == var2_6;

	if (!(var2_7)) goto FIM_3;
	var3_8 = 1;
	var1_3 = var3_8;

	goto FIM_2;
FIM_3:

//ini_elif
	var2_9 = 1;
	var2_10 = var1_5 == var2_9;

	if (!(var2_10)) goto FIM_4;
	var3_11 = 2;
	var1_3 = var3_11;

goto FIM_2;

FIM_4:
//ini_elif
	var2_12 = 3;
	var2_13 = var1_5 < var2_12;

	if (!(var2_13)) goto FIM_5;
	var3_14 = 3;
	var1_3 = var3_14;

goto FIM_2;

FIM_5:
//ini_else
	var3_15 = 145;
	var1_3 = var3_15;

FIM_2:

	cout << var1_3 <<"\n";
	return 0;
}

