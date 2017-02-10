






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
	int var1_3;  //variavel: c
	bool var1_4;  //variavel: b
	bool var1_5; 


	var1_0 = 10;
	var1_1 = var1_0;
	var1_2 = 20;
	var1_3 = var1_2;
	var1_5 = var1_1 or var1_3;
	var1_4 = var1_5;
	cout << var1_4 ;
	return 0;
}

