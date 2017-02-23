









/*Compilador FOCA*/
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main(void)
{
	char var1_0[1024];  //variavel: y
	char var1_1[6]; 
	char var1_2[1041];  //variavel: x
	char var1_3[7]; 
	char var1_4[7];  //variavel: z
	char var1_5[1024]; 
	char var1_6[4]; 
	char var1_7[1028]; 
	char var1_8[1034]; 
	char var1_9[1041]; 


	strcpy (var1_1,"teste");
	strcpy (var1_2,var1_1);
	strcpy (var1_3,"blabla");
	strcpy (var1_4,var1_3);
	cin >> var1_5 ;
	strcpy (var1_0,var1_5);

	strcpy(var1_9,"");
	strcpy(var1_8,"");
	strcpy(var1_7,"");	strcpy (var1_6,"car");

	strcat(var1_7,var1_6);
	strcat(var1_7,var1_0);

	strcat(var1_8,var1_2);
	strcat(var1_8,var1_7);

	strcat(var1_9,var1_4);
	strcat(var1_9,var1_8);
	strcpy (var1_2,var1_9);
	cout << var1_2 <<"\n";
	return 0;
}
