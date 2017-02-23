











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
	bool var1_3; 
	int var1_4; 
	bool var1_5; 


	var1_0 = 0;
	var1_1 = var1_0;
	var1_1 = var1_1 - 1;
//ini_while
INI_2:
	var1_2 = 10;
	var1_3 = var1_1 < var1_2;

	if (!(var1_3)) goto FIM_2;
	var1_1 = var1_1 + 1;

	goto INI_2;

FIM_2:
//fim_while

//ini_while
INI_3:
	var1_4 = 0;
	var1_5 = var1_1 > var1_4;

	if (!(var1_5)) goto FIM_3;
	var1_1 = var1_1 - 1;

	goto INI_3;

FIM_3:
//fim_while

	return 0;
}

