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
	bool var1_10; 
	int var1_12; 
	bool var1_13; 
	int var1_15; 
	bool var1_16; 
	int var1_18; 
	bool var1_19; 
	int var1_2; 
	int var1_3;  //variavel: b
	int var1_4; 
	int var1_5;  //variavel: c
	int var1_6; 
	bool var1_7; 
	int var1_9; 
	int var2_8; 
	int var2_11; 
	int var2_14; 
	int var2_17; 
	int var2_20; 
	int var2_21; 


	var1_0 = 111;
	var1_1 = var1_0;
	var1_2 = 110;
	var1_3 = var1_2;
	var1_4 = 0;
	var1_5 = var1_4;
	var1_6 = 1;
	var1_7 = var1_1 == var1_6;

	if (!(var1_7)) goto FIM_11;
	var2_8 = 1;
	var1_5 = var2_8;

 goto FIM_0_1;


	FIM_11:
	var1_9 = 2;
	var1_10 = var1_3 == var1_9;

	if (!(var1_10)) goto FIM_10;
	var2_11 = 2;
	var1_5 = var2_11;

 goto FIM_0_1;


	FIM_10:
	var1_12 = 3;
	var1_13 = var1_1 == var1_12;

	if (!(var1_13)) goto FIM_9;
	var2_14 = 3;
	var1_5 = var2_14;

 goto FIM_0_1;


	FIM_9:
	var1_15 = 4;
	var1_16 = var1_3 == var1_15;

	if (!(var1_16)) goto FIM_8;
	var2_17 = 4;
	var1_5 = var2_17;

 goto FIM_0_1;


	FIM_8:
	var1_18 = 5;
	var1_19 = var1_1 == var1_18;

	if (!(var1_19)) goto FIM_7;
	var2_20 = 5;
	var1_5 = var2_20;

 goto FIM_0_1;


	FIM_7:
	var2_21 = 6;
	var1_5 = var2_21;






 FIM_0_1:

	return 0;
}

