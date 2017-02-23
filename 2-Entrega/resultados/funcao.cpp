//iniEscopo:1 1


//iniEscopo:2 2
//DECLARA_PARAM:a:
//DECLARA::var2_0
//PARANs:var2_0:

//OPs OPERACAO:2 2 FIM_2
//OPs OPERACAO:var2_1::size:0:
//DECLARA_E_ATRIBUI::2 2 FIM_2
//DeA:b:var2_1::


//iniEscopo:3 3
//DECLARA_PARAM:d:
//DECLARA::var3_3
//PARANs:var3_3:

//NUMEROS TK_ID:b
//NUMEROS TK_ID:d
//ARITMETICO::3 3 FIM_3
//:var2_2::var3_3:
//RETORNOs OPERACAO:var3_4:

//FUNCAO1::3 3 FIM_3
//FUNCAO1::d::
//FUNCAO1:var3_4:
//fimEscopo:3 3

//NUMEROS TK_ID:a
//OPs OPERACAO:2 2 FIM_2
//OPs OPERACAO:var2_0::size:0:
//EXECUTA_FUNCAO OPs:: 2 2
//1:1:func3_1:
//EXECUTA_FUNCAO:var2_0:var3_3:
//RETORNOs OPERACAO:meda2:

//FUNCAO2::2 2 FIM_2
//FUNCAO2::meda1:a::
//FUNCAO2:var3_4:
//void func3_1()
//fimEscopo:2 2

//iniEscopo:2 4
//DECLARA_PARAM:a:
//DECLARA::var2_5
//DECLARA_PARAM:b:
//DECLARA_PARAM:c:
//PARANs:var2_5:
//PARANs:var2_6:
//PARANs:var2_7:

//NUMEROS TK_ID:a
//NUMEROS TK_ID:b
//ARITMETICO::2 4 FIM_4
//:var2_5::var2_6:
//RETORNOs OPERACAO:var2_8:
//NUMEROS TK_ID:b
//RETORNO_OPER:var2_8:var2_6:
//RETORNO_OPER::var2_8
//NUMEROS TK_ID:c
//RETORNO_OPER:var2_8:var2_7:
//RETORNO_OPER::var2_8
//RETORNO_OPER::var2_6

//FUNCAO1::2 4 FIM_4
//FUNCAO1::c::
//FUNCAO1:var2_8:
//FUNCAO1:var2_6:
//FUNCAO1:var2_7:
//fimEscopo:2 4


//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:var1_9::size:0:
//EXECUTA_FUNCAO OPs:: 1 1
//3:3:func2_2:
//EXECUTA_FUNCAO:var1_9:var2_5:
//EXECUTA_FUNCAO:var1_10:var2_6:
//EXECUTA_FUNCAO:var1_11:var2_7:
//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:meda3::size:3:
	//::var2_8
	//::var2_6
	//::var2_7
//DECLARA_E_ATRIBUI::1 1 FIM_1
//DeA:d:var2_8::
//void func2_0()
//void func2_2()

//DeA:e:var2_6::
//void func2_0()
//void func2_2()

//DeA:f:var2_7::
//void func2_0()
//void func2_2()

//NUMEROS TK_ID:d



//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:var1_15::size:0:
//EXECUTA_FUNCAO OPs:: 1 1
//1:1:func2_0:
//EXECUTA_FUNCAO:var1_15:var2_0:
//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:meda1::size:1:
	//::var3_4
//DECLARA_E_ATRIBUI::1 1 FIM_1
//DeA:g:var3_4::
//void func2_0()

//NUMEROS TK_ID:g


//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:var1_18::size:0:
//EXECUTA_FUNCAO OPs:: 1 1
//3:3:func2_2:
//EXECUTA_FUNCAO:var1_18:var2_5:
//EXECUTA_FUNCAO:var1_19:var2_6:
//EXECUTA_FUNCAO:var1_20:var2_7:
//arit:EXECUTA_FUNCAO:meda3:
//void func2_0()
//void func2_2()
//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:var1_22::size:0:
//EXECUTA_FUNCAO OPs:: 1 1
//1:1:func2_0:
//EXECUTA_FUNCAO:var1_22:var2_0:
//arit:EXECUTA_FUNCAO:meda1:
//void func2_0()
//OPs OPERACAO:1 1 FIM_1
//OPs OPERACAO:var1_24::size:0:
//EXECUTA_FUNCAO OPs:: 1 1
//1:1:func2_0:
//EXECUTA_FUNCAO:var1_24:var2_0:
//arit:EXECUTA_FUNCAO:meda1:
//void func2_0()
//ARITMETICO::1 1 FIM_1
//:var1_23::var1_25:
//ARITMETICO::1 1 FIM_1
//:var1_21::var1_26:
//ARITMETICO::1 1 FIM_1
//:var1_17::var1_27:
//ATRIBUICAO::1 1 FIM_1//ATRIBUICAO:::var1_28:
//if else:var1_16:var1_28::


//NUMEROS TK_ID:g


//BLOCO
/*Compilador FOCA*/
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

	void func2_0(); //função: meda1
	void func2_2(); //função: meda3
	void func3_1(); //função: meda2
	int var1_10; 
	int var1_11; 
	int var1_12;  //variavel: d
	int var1_13;  //variavel: e
	int var1_14;  //variavel: f
	int var1_15; 
	int var1_16;  //variavel: g
	int var1_17; 
	int var1_18; 
	int var1_19; 
	int var1_20; 
	int var1_21; 
	int var1_22; 
	int var1_23; 
	int var1_24; 
	int var1_25; 
	int var1_26; 
	int var1_27; 
	int var1_28; 
	int var1_9; 
	int var2_0;  //variavel: a
	int var2_1; 
	int var2_2;  //variavel: b
	int var3_3;  //variavel: d
	int var3_4; 
	int var2_5;  //variavel: a
	int var2_6;  //variavel: b
	int var2_7;  //variavel: c
	int var2_8; 

int main(void)
{


	var1_9 = 1;
	var1_10 = 2;
	var1_11 = 3;
	var2_5 = var1_9;
	var2_6 = var1_10;
	var2_7 = var1_11;
	func2_2();  //meda3

	var1_12 = var2_8;
	var1_13 = var2_6;
	var1_14 = var2_7;
	cout << var1_12 <<"\n";
	var1_15 = 1;
	var2_0 = var1_15;
	func2_0();  //meda1

	var1_16 = var3_4;
	cout << var1_16 <<"\n";
	var1_17 = 2;
	var1_18 = 1;
	var1_19 = 2;
	var1_20 = 3;
	var2_5 = var1_18;
	var2_6 = var1_19;
	var2_7 = var1_20;
	func2_2();  //meda3


	var1_21 = var2_8;
	var1_22 = 5;
	var2_0 = var1_22;
	func2_0();  //meda1


	var1_23 = var3_4;
	var1_24 = 4;
	var2_0 = var1_24;
	func2_0();  //meda1


	var1_25 = var3_4;
	var1_26 = var1_23 + var1_25;
	var1_27 = var1_21 + var1_26;
	var1_28 = var1_17 + var1_27;
	var1_16 = var1_28;
	cout << var1_16 <<"\n";
	return 0;
}
void func2_0(){  //meda1

	var2_1 = 2;
	var2_2 = var2_1;
	var3_3 = var2_0;
	func3_1();  //meda2


}
void func2_2(){  //meda3

	var2_8 = var2_5 * var2_6;

}
void func3_1(){  //meda2

	var3_4 = var2_2 * var3_3;

}
