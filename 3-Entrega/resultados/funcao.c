//iniEscopo:1 1



//iniEscopo:2 2
//DECLARA_PARAM:a:
//DECLARA::var2_0
//DECLARA_PARAM:b:
//DECLARA_PARAM:c:
//PARANs:var2_0:
//PARANs:var2_1:
//PARANs:var2_2:

//NUMEROS TK_ID:a
//NUMEROS TK_ID:b
//ARITMETICO::2 2 FIM_2
//:var2_0::var2_1:
//RETORNOs OPERACAO:var2_3:	var2_3 = var2_0 * var2_1;

//NUMEROS TK_ID:b
//RETORNO_OPER:var2_3:var2_1:
//RETORNO_OPER::var2_3
//NUMEROS TK_ID:c
//RETORNO_OPER:var2_3:var2_2:
//RETORNO_OPER::var2_3
//RETORNO_OPER::var2_1
//RETORNO:	var2_3 = var2_0 * var2_1;


//FUNCAO1::2 2 FIM_2
//FUNCAO1::c::
//FUNCAO1:var2_3:
//FUNCAO1:var2_1:
//FUNCAO1:var2_2:
//fimEscopo:2 2


//DECLARA_PARAM:b:

//ARITMETICO::1 1 FIM_1
//:var1_6::var1_7:
//ARITMETICO::1 1 FIM_1
//:var1_9::var1_10:
//ARITMETICO::1 1 FIM_1
//:var1_12::var1_13:
//EXECUTA_FUNCAO OPs:: 1 1
//3:3:func2_0:
//EXECUTA_FUNCAO:var1_8:var2_0:
//EXECUTA_FUNCAO:var1_11:var2_1:
//EXECUTA_FUNCAO:var1_14:var2_2:
//arit:EXECUTA_FUNCAO:meda:
//ARITMETICO::1 1 FIM_1
//:var1_5::var2_3:
//DECLARA_E_ATRIBUI::1 1 FIM_1
//DeA:a:var1_15::


//NUMEROS TK_ID:a

//BLOCO
/*Compilador FOCA*/
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

	void func2_0(); //função: meda
	int var1_10; 
	int var1_11; 
	int var1_12; 
	int var1_13; 
	int var1_14; 
	int var1_15; 
	int var1_16;  //variavel: a
	int var1_4;  //variavel: b
	int var1_5; 
	int var1_6; 
	int var1_7; 
	int var1_8; 
	int var1_9; 
	int var2_0;  //variavel: a
	int var2_1;  //variavel: b
	int var2_2;  //variavel: c
	int var2_3; 

int main(void)
{


	var1_5 = 1;

	func2_0();
	var1_15 = var1_5 + var2_3;
	var1_16 = var1_15;
	cout << var1_16 <<"\n";
	return 0;
}
void func2_0()
{
	var2_3 = var2_0 * var2_1;

}
