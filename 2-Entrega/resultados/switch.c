//iniEscopo:1 1

//DECLARA_E_ATRIBUI::1 1 FIM_1 a

//DECLARA_E_ATRIBUI::1 1 FIM_1 b






//SWITCH::1 1 FIM_1_1 switch_varvar1_3
//iniEscopo:2 2


//iniEscopo:3 3
//BLOCO:: 3 3
//CASE::3 3 FIM_3
//fimEscopo:3 3


//iniEscopo:3 4


//BLOCO
//CASE::3 4 FIM_4
//fimEscopo:3 4


//iniEscopo:3 5


//TK_CONTINUE::3 5 FIM_5


//BLOCO
//CASE::3 5 FIM_5
//fimEscopo:3 5

//CASEs::2 2 FIM_2 -->
//CASEs::2 2 FIM_2 -->

//iniEscopo:3 6
//BLOCO:: 6 3
//DEFAULT::3 6 FIM_6
//fimEscopo:3 6

//SWITCHCASEDEFA::2 2 FIM_2_7 switch_varvar1_3
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
	int var2_4; 
	int var2_6; 
	int var2_8; 
	bool var3_5; 
	bool var3_7; 
	bool var3_9; 
	int var3_10; 


	var1_0 = 0;
	var1_1 = var1_0;
	var1_2 = 2;
	var1_3 = var1_2;

//ini_case
	var2_4 = 1;
	var3_5 = var1_3 == var2_4;

	if (var3_5) goto INI_3;

//ini_case
	var2_6 = 2;
	var3_7 = var1_3 == var2_6;

	if (var3_7) goto INI_4;

//ini_case
	var2_8 = 3;
	var3_9 = var1_3 == var2_8;

	if (var3_9) goto INI_5;

//ini_defalut
	goto INI_6;

goto FIM_2;

INI_3:
	var1_1 = var1_1 + 1;
//fim_case

INI_4:
	var1_1 = var1_1 + 1;
//fim_case

INI_5:
	var1_1 = var1_1 + 1;
	goto FIM_2;//break
//fim_case

INI_6:
	var3_10 = 10;
	var1_1 = var3_10;
//fim_default

//fim_switch_case
FIM_2:

	cout << var1_1 <<"\n";
	return 0;
}




