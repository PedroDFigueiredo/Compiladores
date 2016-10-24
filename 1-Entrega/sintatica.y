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
void addNewVarToTable(string tipo, string nomeTemp, string varTemp);

struct atributos
{
	string label;
	string traducao;
	string tipo;
	string nomeTemp;
};

class VarNode{
	public: 
		string nomeTemp; //Tipo de var Var0, Var2;
		string tipo;
		VarNode(string , string);
};

VarNode::VarNode(string a, string b){
	nomeTemp = a;
	tipo = b;
};

VarNode* getVar(string nomeTemp);

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
				
				$1.tipo = verificaTipo($1.tipo, "+", $3.tipo);
				cout<<$1.tipo<<"++\n";
				$$.traducao = $1.traducao + $3.traducao + "\t" +$1.tipo+" "+ var + " = " + $1.label + " + " + $3.label  +";\n";

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
				$1.tipo = verificaTipo($1.tipo, "+", $3.tipo);
				//string var = addNewVar();
				$$.traducao = $1.traducao + $3.traducao + "\t" +$1.tipo+" "+ $1.label + " = " + $3.label + ";\n";

			}
			| TK_NUM
			{
				string var = addNewVar();
				//cout<<"NUM "<<$1.tipo<<" "<<$1.label<<"\n;";

				$$.traducao = "\t"+$1.tipo+" "+ var + " = "+ $1.label + ";\n";

				$$.label = var; //Armazena o var no label para no próximo passo da recursão saber qual variavel foi criada.
			}
			| TK_CHAR
			{
				string var = addNewVar();
				//cout<<"HAR "<<$1.tipo<<" "<<$1.label<<"\n;";

				$$.traducao = "\t"+$1.tipo+" "+ var + " = "+ $1.label + ";\n";

				$$.label = var; //Armazena o var no label para no próximo passo da recursão saber qual variavel foi criada.
			}
			| TK_REAL
			{
				string var = addNewVar();
				//cout<<"EAL "<<$1.tipo<<" "<<$1.label<<"\n;";

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

				cout <<"$1.traducao"<<":"<<$1.label<<":"<<$1.tipo<<":"<<$1.nomeTemp<<":\n";
				//cout <<"$2.traducao"<<":"<<$2.label<<":"<<$2.tipo<<":"<<$2.nomeTemp<<":\n";
				//cout <<"$3.traducao"<<":"<<$3.label<<":"<<$3.tipo<<":"<<$3.nomeTemp<<":\n";
				
				//cout<<verificaTipo($1.tipo, "+", $3.tipo)<<"::";
				//busca na tabela de variáveis, o nome da váriavel 
				$$.label =  getVar($1.label)->nomeTemp;
				$$.tipo = getVar($1.label)->tipo;
				$$.nomeTemp =  $1.label;
			}
			;
			

//Declaração de tipos
DECLARACAO	: TK_TIPO_INT{
				//Criar tabela para guardar tipo 
				$$.traducao = "int"; //retorna int na recursão
			}
			| TK_TIPO_BOOL{
				//Criar tabela para guardar tipo 
				$$.traducao = "bool"; //retorna bool na recursão
			}
			| TK_TIPO_FLOAT{
				//Criar tabela para guardar tipo 
				$$.traducao = "float"; //retorna float na recursão
			}
			| TK_TIPO_CHAR{
				//Criar tabela para guardar tipo 
				$$.traducao = "char"; //retorna char na recursão
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
    //cout << it->first << " => " << it->second->nomeTemp << '\n';

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
void addNewVarToTable(string nomeTemp, string varTemp, string tipo){
	//verifica se a nova variavel está na tabela
	if(varTable.find(nomeTemp)!=varTable.end()){
		cout<<"error: redeclaration of '"<<tipo<<" "<<nomeTemp<< "'\n";
	}else{
		varTable[nomeTemp] = new VarNode(varTemp, tipo);
	}
}
VarNode* getVar(string nomeTemp){
	//cout<<varTable[nomeTemp]->nomeTemp<<" getVar\n";
	return varTable[nomeTemp]; 
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
