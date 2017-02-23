//iniEscopo:1 1


1
//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:var1_0::size:0:
//DECLARA_E_ATRIBUI::1 1 FIM_1
//DeA:a:var1_0::


5
//ATRIBUICAO::1 1 FIM_1//ATRIBUICAO:::var1_3:
//if else:var1_1:var1_3::


//BLOCO
/*Compilador FOCA*/
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

	char var1_0[1]; 
	char var1_1[5];  //variavel: a
	char var1_3[5]; 

int main(void)
{


	strcpy (var1_0,"");
	strcpy (var1_1,var1_0);
	strcpy (var1_3,"adas");
	strcpy (var1_1,var1_3);
	return 0;
}
