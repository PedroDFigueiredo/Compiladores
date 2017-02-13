

















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
	bool var2_11; 
	int var2_12; 
	bool var2_15; 
	int var2_16; 
	int var2_4; 
	bool var2_7; 
	int var2_8; 
	int var3_5; 
	int var3_6; 
	int var3_10; 
	int var3_9; 
	int var3_13; 
	int var3_14; 


	var1_0 = 0;
	var1_1 = var1_0;
	var1_2 = 1;
	var1_3 = var1_2;

//ini_case
	var2_4 = 1;
	var2_7 = var1_3 == var2_4;

	if (var2_7) goto FIM_3;

//ini_case
	var2_8 = 2;
	var2_11 = var1_3 == var2_8;

	if (var2_11) goto FIM_5;

//ini_case
	var2_12 = 3;
	var2_15 = var1_3 == var2_12;

	if (var2_15) goto FIM_7;

//ini_defalut
	goto FIM_8;

goto FIM_SWITCH;

FIM_3:
	var3_5 = 1;
	var3_6 = var1_1 + var3_5;
	var1_1 = var3_6;
//fim_case

FIM_5:
	var3_9 = 1;
	var3_10 = var1_1 + var3_9;
	var1_1 = var3_10;
//fim_case

FIM_7:
	var3_13 = 1;
	var3_14 = var1_1 + var3_13;
	var1_1 = var3_14;
//fim_case

FIM_8:
	var2_16 = 15;
	var1_1 = var2_16;
//fim_default


FIM_SWITCH:
	return 0;
}




