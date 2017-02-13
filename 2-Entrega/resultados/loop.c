














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
	int var1_3;  //variavel: i
	bool var1_4; 
	int var1_5; 
	bool var1_6; 
	int var2_7; 
	int var2_8;  //variavel: x
	bool var2_9; 


	var1_0 = 10;
	var1_1 = var1_0;
	var1_2 = 0;
	var1_3 = var1_2;

INI_2:
	var1_3 = var1_3 + 1;
	var1_4 = var1_3 < var1_1;

	if (var1_4) goto INI_2;

INI_6:
	var1_5 = 0;
	var1_6 = var1_3 > var1_5;

	if (!(var1_6)) goto FIM_6;
	var1_3 = var1_3 - 1;
	var2_7 = 0;
	var2_8 = var2_7;

INI_5:
	var2_9 = var2_8 < var1_3;

	if (!(var2_9)) goto FIM_5;
	var1_3 = var1_3 + 1;
	var2_8 = var2_8 + 1;

 goto INI_5;

FIM_5:

 goto INI_6;

FIM_6:
	return 0;
}




