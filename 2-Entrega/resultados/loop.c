logico: teste









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
	int var2_4; 
	int var2_5; 


	var1_0 = 0;
	var1_1 = var1_0;

INI_0:
	var1_2 = 51;
	var1_3 = var1_1 < var1_2;

	if (!(var1_3)) goto FIM_2;
	var2_4 = 1;
	var2_5 = var1_1 + var2_4;
	var1_1 = var2_5;

 goto INI_0;

FIM_2:
	return 0;
}

