%{
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iostream>
#include <cassert>
#include <string>
#include <sstream>

#define YYSTYPE atributos

using namespace std;

int varCount=0;

void criaTabelaTipos();
string to_string(int i);
string addNewVar();
void addNewVarToTable(string tipo, string name, string varTemp);

struct atributos
{
	string label;
	string traducao;
	string tipo;
	string teste;
};

class VarNode{
	public: 
		string name; //Tipo de var Var0, Var2;
		string tipo;
		VarNode(string , string);
};

VarNode::VarNode(string a, string b){
	name = a;
	tipo = b;
};

VarNode* getVar(string name);

map<string, VarNode*> varTable;

map<string, string> TabelaTipos;

string verificaTipo(string tipoA, string operador, string tipoB){
	if(TabelaTipos.empty()){
		criaTabelaTipos();
	}
	string busca = tipoA+operador+tipoB;
	string retorno  =TabelaTipos.find(busca)->second;
	//cout << busca<<"verficabusca\n";
	
	//TabelaTipos[busca]
	return retorno;
}


int yylex(void);
void yyerror(string);
%}

%token TK_NUM TK_CHAR TK_REAL
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL
%token TK_FIM TK_ERROR

%start S

%right '='
%left '+'


%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
			 $$.traducao = $1.traducao + $2.traducao;
			}
			|
			;

COMANDO 	: E ';'
			;

E 			: E '+' E
			{
				string var = addNewVar();
				
				if(getVar($3.teste)){ //Se o getVar não existe ele retorna 0 e não entra no IF!!!
					//cout <<getVar($1.teste)->tipo <<  ": " <<getVar($3.teste)->tipo;
					$1.tipo = verificaTipo(getVar($1.teste)->tipo , "+", getVar($3.teste)->tipo);
					cout << verificaTipo(getVar($1.teste)->tipo , "+", getVar($3.teste)->tipo); 
				}else{
					//$1.tipo = verificaTipo($1.teste , "+", getVar($3.teste)->tipo);
					cout <<"else "<< $1.traducao , "+", $3.traducao; 
				}
				
				$$.traducao = $1.traducao + $3.traducao + "\t" +$1.tipo+" "+ var + " = " + $1.label + " + " + $3.label  +";\n";
				//cout <<$2.traducao<<":"<<getVar($2.label)->tipo <<":"<< $3.traducao ;
				
				
				
				
				//cout << verificaTipo( getVar($1.label)->tipo, " + ", getVar($3.label)->tipo );
				//cout << ":teste\n";
				//criaTabelaTipos() $1.label + " + " + $3.label

				$$.label = var;

			}
			| E '-' E
			{
				string var = addNewVar();

				$$.traducao = $1.traducao + $3.traducao + "\t" +$1.tipo+" "+ var + " = " + $1.label + " - " + $3.label  +";\n";

				$$.label = var;

			}
			| E '*' E
			{
				string var = addNewVar();

				$$.traducao = $1.traducao + $3.traducao + "\t" +$1.tipo+" "+ var + " = " + $1.label + " * " + $3.label  +";\n";

				$$.label = var;

			}
			| E '/' E
			{
				string var = addNewVar();

				$$.traducao = $1.traducao + $3.traducao + "\t" +$1.tipo+" "+ var + " = " + $1.label + " / " + $3.label  +";\n";

				$$.label = var;

			}
			| E '=' E
			{	
				//string var = addNewVar();
				$$.traducao = $1.traducao + $3.traducao + "\t" +$1.tipo+" "+ $1.label + " = " + $3.label + ";\n";

			}
			| TK_NUM
			{
				string var = addNewVar();

				$$.traducao = "\t"+$1.tipo+" "+ var + " = "+ $1.label + ";\n";

				$$.label = var; //Armazena o var no label para no próximo passo da recursão saber qual variavel foi criada.
			}
			| TK_CHAR
			{
				string var = addNewVar();

				$$.traducao = "\t"+$1.tipo+" "+ var + " = "+ $1.label + ";\n";

				$$.label = var; //Armazena o var no label para no próximo passo da recursão saber qual variavel foi criada.
			}
			| TK_REAL
			{
				string var = addNewVar();

				$$.traducao = "\t"+$1.tipo+ " " + var + " = "+ $1.label + ";\n";

				$$.label = var; //Armazena o var no label para no próximo passo da recursão saber qual variavel foi criada.
			}
			
			|DECLARACAO TK_ID
			{
				//Criar tabela para guardar variavel 
				string var = addNewVar();

				$$.traducao = "\t"+ $1.traducao+" " + var + ";\n";

				//insere variavel na tabela
				addNewVarToTable( $2.label, var, $1.traducao);
				$$.label = var;
				$$.tipo = $1.traducao;
			}
			|TK_ID
			{	
				//busca na tabela de variáveis, o nome da váriavel 
				$$.label =  getVar($1.label)->name;
				$$.teste =  $1.label;
			}
			;
			

//Declaração de tipos
DECLARACAO	: TK_TIPO_INT{
				//Criar tabela para guardar tipo 
				$$.traducao = "int"; //retorna int na recursão
			}
			| TK_TIPO_BOOL{
				//Criar tabela para guardar tipo 
				$$.traducao = "bool "; //retorna bool na recursão
			}
			| TK_TIPO_FLOAT{
				//Criar tabela para guardar tipo 
				$$.traducao = "float "; //retorna float na recursão
			}
			| TK_TIPO_CHAR{
				//Criar tabela para guardar tipo 
				$$.traducao = "char "; //retorna char na recursão
			}
			;

%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{	
	yyparse();
	//cout<<"\n\n::::\n";
	//for (map<string,VarNode*>::iterator it=varTable.begin(); it!=varTable.end(); ++it)
    //cout << it->first << " => " << it->second->name << '\n';

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}	

std::string to_string(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

string addNewVar(){

	return ("var" + to_string(varCount++)); 
}
void addNewVarToTable(string name, string varTemp, string tipo){
	//verifica se a nova variavel está na tabela
	if(varTable.find(name)!=varTable.end()){
		cout<<"error: redeclaration of '"<<tipo<<" "<<name<< "'\n";
	}else{
		varTable[name] = new VarNode(varTemp, tipo);
	}
}
VarNode* getVar(string name){
	//cout<<varTable[name]->name<<" getVar\n";
	return varTable[name]; 
}
void criaTabelaTipos(){	
	 //Tabela de Operação para soma
    TabelaTipos["int+int"] = "int";
    TabelaTipos["int+float"] = "float";
    TabelaTipos["int+string"] = "string";
    TabelaTipos["int+char"] = "char"; //Verificar se será esse tipo mesmo para essa operação
    TabelaTipos["int+hex"] = "hex";
    TabelaTipos["float+int"] = "float";
    TabelaTipos["float+float"] = "float";
    TabelaTipos["float+string"] = "string";
    TabelaTipos["float+char"] = "ERRO";
    TabelaTipos["float+hex"] = "ERRO";
    TabelaTipos["string+int"] = "ERRO";
    TabelaTipos["string+float"] = "string";
    TabelaTipos["string+string"] = "string";
    TabelaTipos["string+char"] = "string";
    TabelaTipos["string+hex"] = "string";
    TabelaTipos["char+int"] = "char";
    TabelaTipos["char+float"] = "ERRO";
    TabelaTipos["char+string"] = "string";
    TabelaTipos["char+char"] = "string";
    TabelaTipos["char+hex"] = "hex";
    TabelaTipos["hex+int"] = "hex";
    TabelaTipos["hex+float"] = "ERRO";
    TabelaTipos["hex+string"] = "string";
    TabelaTipos["hex+char"] = "hex";
    TabelaTipos["hex+hex"] = "hex";
    //Tabela de Operação para subtração    
    TabelaTipos["int-int"] = "int";
    TabelaTipos["int-float"] = "float";
    TabelaTipos["int-string"] = "string";
    TabelaTipos["int-char"] = "char"; //Verificar se será esse tipo mesmo para essa operação
    TabelaTipos["int-hex"] = "hex";
    TabelaTipos["float-int"] = "float";
    TabelaTipos["float-float"] = "float";
    TabelaTipos["float-string"] = "string";
	TabelaTipos["float-char"] = "ERRO";
    TabelaTipos["float-hex"] = "ERRO";
    TabelaTipos["string-int"] = "ERRO";
    TabelaTipos["string-float"] = "string";
    TabelaTipos["string-string"] = "string";
    TabelaTipos["string-char"] = "string";
    TabelaTipos["string-hex"] = "string";
    TabelaTipos["char-int"] = "char";
    TabelaTipos["char-float"] = "ERRO";
    TabelaTipos["char-string"] = "string";
    TabelaTipos["char-char"] = "string";
    TabelaTipos["char-hex"] = "hex";
    TabelaTipos["hex-int"] = "hex";
    TabelaTipos["hex-float"] = "ERRO";
    TabelaTipos["hex-string"] = "string";
    TabelaTipos["hex-char"] = "hex";
    TabelaTipos["hex-hex"] = "hex";
    //Tabela de Operação para multiplicação
    TabelaTipos["int*int"] = "int";
    TabelaTipos["int*float"] = "float";
    TabelaTipos["int*string"] = "ERRO";
    TabelaTipos["int*char"] = "string"; //Verificar se será esse tipo mesmo para essa operação
	TabelaTipos["int*hex"] = "ERRO";
    TabelaTipos["float*int"] = "float";
    TabelaTipos["float*float"] = "float";
    TabelaTipos["float*string"] = "ERRO";
    TabelaTipos["float*char"] = "ERRO";
    TabelaTipos["float*hex"] = "ERRO";
    TabelaTipos["string*int"] = "string"; //Alterar isso depois para poder repetir a string n vezes
    TabelaTipos["string*float"] = "ERRO";
    TabelaTipos["string*string"] = "ERRO";
    TabelaTipos["string*char"] = "ERRO";
    TabelaTipos["string*hex"] = "ERRO";
    TabelaTipos["char*int"] = "string"; 
    TabelaTipos["char*float"] = "ERRO";
    TabelaTipos["char*string"] = "ERRO";
    TabelaTipos["char*char"] = "ERRO";
    TabelaTipos["char*hex"] = "ERRO";
    TabelaTipos["hex*int"] = "ERRO";
    TabelaTipos["hex*float"] = "ERRO";
    TabelaTipos["hex*string"] = "ERRO";
    TabelaTipos["hex*char"] = "ERRO";
    TabelaTipos["hex*hex"] = "hex";
    //Tabela de Operação para divisão
    TabelaTipos["int/int"] = "int";
    TabelaTipos["int/float"] = "float";
    TabelaTipos["int/string"] = "ERRO";
    TabelaTipos["int/char"] = "ERRO"; //Verificar se será esse tipo mesmo para essa operação
    TabelaTipos["int/hex"] = "ERRO";
    TabelaTipos["float/int"] = "float";
    TabelaTipos["float/float"] = "float";
    TabelaTipos["float/string"] = "ERRO";
    TabelaTipos["float/char"] = "ERRO";
    TabelaTipos["float/hex"] = "ERRO";
    TabelaTipos["string/int"] = "ERRO";
    TabelaTipos["string/float"] = "ERRO";
    TabelaTipos["string/string"] = "ERRO";
    TabelaTipos["string/char"] = "ERRO";
    TabelaTipos["string/hex"] = "ERRO";
    TabelaTipos["char/int"] = "ERRO";
    TabelaTipos["char/float"] = "ERRO";
    TabelaTipos["char/string"] = "ERRO";
    TabelaTipos["char/char"] = "ERRO";
    TabelaTipos["char/hex"] = "ERRO";
    TabelaTipos["hex/int"] = "ERRO";
    TabelaTipos["hex/float"] = "ERRO";
    TabelaTipos["hex/string"] = "ERRO";
    TabelaTipos["hex/char"] = "ERRO";
    TabelaTipos["hex/hex"] = "ERRO";
}
