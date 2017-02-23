








































/*Compilador FOCA*/
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main(void)
{
	int var1_0; 
	int var1_1;  //variavel: i
	int var1_22; 
	bool var1_23; 
	int var2_4; 
	bool var2_5; 
	int var3_2; 
	bool var3_3; 
	int var2_6; 
	int var2_7;  //variavel: i
	int var2_8; 
	bool var2_9; 
	int var3_10; 
	bool var3_11; 
	int var2_12; 
	int var2_13;  //variavel: j
	int var2_14; 
	bool var2_15; 
	int var3_16; 
	int var3_17;  //variavel: k
	int var3_18; 
	bool var3_19; 
	int var4_20; 
	bool var4_21; 


	var1_0 = 0;
	var1_1 = var1_0;

//ini_do_while
INI_2:
	var1_1 = var1_1 + 1;

//ini_if
	var3_2 = 5;
	var3_3 = var1_1 == var3_2;

	if (!(var3_3)) goto FIM_4;
	goto FIM_2;//break

FIM_4:
//fim_if

	cout << var1_1 <<"\n";
	var2_4 = 10;
	var2_5 = var1_1 < var2_4;

	if (var2_5) goto INI_2;
FIM_2: //fim_do_while

//ini_for
	var2_6 = 0;
	var2_7 = var2_6;

INI_5_l:
	var2_8 = 10;
	var2_9 = var2_7 < var2_8;

	if (!(var2_9)) goto FIM_5;

//ini_if
	var3_10 = 5;
	var3_11 = var2_7 != var3_10;

	if (!(var3_11)) goto FIM_7;
	goto INI_5;//continue

FIM_7:
//fim_if

	cout << var2_7 <<"\n";

INI_5:
	var2_7 = var2_7 + 1;

	goto INI_5_l;
FIM_5:
//fim_for

//ini_for
	var2_12 = 0;
	var2_13 = var2_12;

INI_8_l:
	var2_14 = 2;
	var2_15 = var2_13 < var2_14;

	if (!(var2_15)) goto FIM_8;
//ini_for
	var3_16 = 0;
	var3_17 = var3_16;

INI_9_l:
	var3_18 = 5;
	var3_19 = var3_17 < var3_18;

	if (!(var3_19)) goto FIM_9;

//ini_if
	var4_20 = 3;
	var4_21 = var3_17 == var4_20;

	if (!(var4_21)) goto FIM_11;
	goto INI_9;//continue

FIM_11:
//fim_if

	cout << var2_13 <<"\n";
	cout << var3_17 <<"\n";

INI_9:
	var3_17 = var3_17 + 1;

	goto INI_9_l;
FIM_9:
//fim_for


INI_8:
	var2_13 = var2_13 + 1;

	goto INI_8_l;
FIM_8:
//fim_for

//ini_while
INI_12:
	var1_22 = 10;
	var1_23 = var1_1 < var1_22;

	if (!(var1_23)) goto FIM_12;
	var1_1 = var1_1 + 1;
	cout << var1_1 <<"\n";

	goto INI_12;

FIM_12:
//fim_while

	return 0;
}




