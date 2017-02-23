



























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




