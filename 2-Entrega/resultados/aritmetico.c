

TK_MAIS TK_MAIS




TK_MAIS TK_MAIS

BLOCO1



TK_MAIS TK_MAIS


BLOCO3
BLOCO1
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

INI_2:
	var1_2 = 10;
	var1_3 = var1_1 < var1_2;

	if (!(var1_3)) goto FIM_2;
	var1_1 = var1_1 + 1;

 goto INI_2;

FIM_2:

INI_4:
	var1_4 = 0;
	var1_5 = var1_1 > var1_4;

	if (!(var1_5)) goto FIM_4;
	var1_1 = var1_1 - 1;

 goto INI_4;

FIM_4:
	return 0;
}

