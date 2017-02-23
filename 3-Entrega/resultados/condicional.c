//iniEscopo:1 1


//DECLARA_E_ATRIBUI::1 1 FIM_1 a

//DECLARA_E_ATRIBUI::1 1 FIM_1 b

//DECLARA_E_ATRIBUI::1 1 FIM_1 c


//iniEscopo:2 2

//iniEscopo:3 3
//BLOCO:: 3 3
//IF::3 3 FIM_3
//fimEscopo:3 3


//iniEscopo:3 4
//BLOCO:: 4 3
//TK_ELIF ELSE::3 4 FIM_4
//fimEscopo:3 4

//CONDICIONAL ELSEs::2 2 FIM_2
//fimEscopo:2 2








//BLOCO
/*Compilador FOCA*/
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main(void)
{
	int var1_0; 
	int var1_1;  //variavel: a
	int var1_2; 
	int var1_3;  //variavel: b
	int var1_4; 
	int var1_5;  //variavel: c
	bool var2_10; 
	int var2_6; 
	bool var2_7; 
	int var2_9; 
	int var3_8; 
	int var3_11; 


	var1_0 = 111;
	var1_1 = var1_0;
	var1_2 = 4;
	var1_3 = var1_2;
	var1_4 = 0;
	var1_5 = var1_4;

//ini_if
	var2_6 = 0;
	var2_7 = var1_1 == var2_6;

	if (!(var2_7)) goto FIM_3;
	var3_8 = 1;
	var1_5 = var3_8;

	goto FIM_2;
FIM_3:

//ini_elif
	var2_9 = 1;
	var2_10 = var1_1 == var2_9;

	if (!(var2_10)) goto FIM_4;
	var3_11 = 2;
	var1_5 = var3_11;

goto FIM_2;

FIM_4:
FIM_2:

	goto FIM_1;//break
	cout << var1_5 ;
	return 0;
}

