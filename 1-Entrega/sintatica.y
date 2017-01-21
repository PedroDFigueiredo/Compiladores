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
string verificaTipo(string tipoA, string operador, string tipoB);

struct atributos
{
	string label;
	string operador;
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

string decl = "";


int yylex(void);
void yyerror(string);
%}

%token TK_INT TK_CHAR TK_FLOAT
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL
%token TK_FIM TK_ERROR
%token OPERADOR 
%token TK_OPER_OR TK_OPER_AND TK_OPER_NOT
%token TK_TRUE TK_FALSE
%token TK_OPER_MAIOR TK_OPER_MAIOR_IGUAL TK_OPER_MENOR TK_OPER_MENOR_IGUAL TK_OPER_IGUAL TK_OPER_DIFERENTE

%start S

%right '='
%left '+'


%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nusing namespace std;\nint main(void)\n{\n" <<decl<< $5.traducao << "\treturn 0;\n}" << endl; 
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

E 			: E OPERADOR E
			{
				string var = addNewVar(), cast1 = "", cast3 = "";
				string tipo = verificaTipo($1.tipo, $2.operador, $3.tipo);
				if($2.operador == "+" || $2.operador == "-" || $2.operador == "*" || $2.operador == "/")
				if($1.tipo != $3.tipo){
					if(tipo != $1.tipo)
						cast1 = "("+tipo+") ";
					if(tipo != $3.tipo)
						cast3 = "("+tipo+") ";
				}
				
				$1.tipo = tipo;
				$$.traducao = $1.traducao + $3.traducao + "\t" +$1.tipo+" "+ var + " = " + cast1 + $1.label + " " + $2.operador + " " + cast3 + $3.label  +";\n";

				$$.label = var;
				$$.tipo = tipo;
			}
		
		
			| E '=' E
			{	
				$1.tipo = verificaTipo($1.tipo, "=", $3.tipo);
				string cast = $3.tipo != $1.tipo ? "("+ $1.tipo +")" : "";
				$$.traducao = $1.traducao + $3.traducao + "\t" +$1.tipo+" "+ $1.label + " = " + cast+" "+ $3.label + ";\n";

			}
			| TK_INT
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
			| TK_FLOAT
			{
				string var = addNewVar();
				//cout<<"EAL "<<$1.tipo<<" "<<$1.label<<";\n";

				$$.traducao = "\t"+$1.tipo+ " " + var + " = "+ $1.label + ";\n";

				$$.label = var; //Armazena o var no label para no próximo passo da recursão saber qual variavel foi criada.
			}
			
			|DECLARACAO TK_ID
			{
				//Criar tabela para guardar variavel 
				string var = addNewVar();

				decl += "\t"+ $1.tipo+" " + var + ";\n";
				//insere variavel na tabela
				addNewVarToTable( $2.label, var, $1.tipo);
				$$.label = var;
				$$.tipo = $1.tipo;
			}
			|TK_ID
			{	

				$$.label = getVar($1.label)->nomeTemp;
				$$.tipo = getVar($1.label)->tipo;
				$$.nomeTemp =  $1.label;
			}
			;
			

//Declaração de tipos
DECLARACAO	: TK_TIPO_INT{
				//Criar tabela para guardar tipo 
				$$.tipo = "int"; //retorna int na recursão
			}
			| TK_TIPO_BOOL{
				//Criar tabela para guardar tipo 
				$$.tipo = "bool"; //retorna bool na recursão
			}
			| TK_TIPO_FLOAT{
				//Criar tabela para guardar tipo 
				$$.tipo = "float"; //retorna float na recursão
			}
			| TK_TIPO_CHAR{
				//Criar tabela para guardar tipo 
				$$.tipo = "char"; //retorna char na recursão
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
		yyerror("error: redeclaration of '"+tipo+" "+nomeTemp+ "'\n");
	}else{
		varTable[nomeTemp] = new VarNode(varTemp, tipo);
	}
}
VarNode* getVar(string nomeTemp){
	//cout<<varTable[nomeTemp]->nomeTemp<<" getVar\n";
	return varTable[nomeTemp]; 
}

string verificaTipo(string tipoA, string operador, string tipoB){
	if(TabelaTipos.empty()){
		criaTabelaTipos();
	}
	string busca = tipoA+operador+tipoB;
	string retorno  = TabelaTipos.find(busca)->second;
	if(retorno == "ERRO")
		yyerror("ERRO");
	//cout <<tipoA<<" "<<operador<<" "<<tipoB<<" :: "<< retorno<<"\n ";
	
	//TabelaTipos[busca]
	return retorno;
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
    //Atribuição
    TabelaTipos["int=int"] = "int";
    TabelaTipos["int=float"] = "int";
    TabelaTipos["int=string"] = "ERRO";
    TabelaTipos["int=char"] = "ERRO"; //Verificar se será esse tipo mesmo para essa operação
    TabelaTipos["int=hex"] = "int";
    TabelaTipos["float=int"] = "float";
    TabelaTipos["float=float"] = "float";
    TabelaTipos["float=string"] = "ERRO";
    TabelaTipos["float=char"] = "ERRO";
    TabelaTipos["float=hex"] = "ERRO";
    TabelaTipos["string=int"] = "ERRO";
    TabelaTipos["string=float"] = "string";
    TabelaTipos["string=string"] = "string";
    TabelaTipos["string=char"] = "string";
    TabelaTipos["string=hex"] = "string";
    TabelaTipos["char=int"] = "char";
    TabelaTipos["char=float"] = "ERRO";
    TabelaTipos["char=string"] = "ERRO";
    TabelaTipos["char=char"] = "char";
    TabelaTipos["char=hex"] = "char";
    TabelaTipos["hex=int"] = "hex";
    TabelaTipos["hex=float"] = "hex";
    TabelaTipos["hex=string"] = "ERRO";
    TabelaTipos["hex=char"] = "ERRO";
    TabelaTipos["hex=hex"] = "hex";
    
    //Relacionais
    TabelaTipos["int>int"] = "bool";
    TabelaTipos["int>float"] = "bool";
    TabelaTipos["int>string"] = "ERRO";
    TabelaTipos["int>char"] = "ERRO"; 
    TabelaTipos["float>int"] = "bool";
    TabelaTipos["float>float"] = "bool";
    TabelaTipos["float>string"] = "ERRO";
	TabelaTipos["float>char"] = "ERRO";
    TabelaTipos["string>int"] = "ERRO";
    TabelaTipos["string>float"] = "ERRO";
    TabelaTipos["string>string"] = "ERRO";
    TabelaTipos["string>char"] = "ERRO";
    TabelaTipos["char>int"] = "ERRO";
    TabelaTipos["char>float"] = "ERRO";
    TabelaTipos["char>string"] = "ERRO";
    TabelaTipos["char>char"] = "ERRO";
    
    TabelaTipos["int>=int"] = "bool";
    TabelaTipos["int>=float"] = "bool";
    TabelaTipos["int>=string"] = "ERRO";
    TabelaTipos["int>=char"] = "ERRO"; 
    TabelaTipos["float>=int"] = "bool";
    TabelaTipos["float>=float"] = "bool";
    TabelaTipos["float>=string"] = "ERRO";
	TabelaTipos["float>=char"] = "ERRO";
    TabelaTipos["string>=int"] = "ERRO";
    TabelaTipos["string>=float"] = "ERRO";
    TabelaTipos["string>=string"] = "ERRO";
    TabelaTipos["string>=char"] = "ERRO";
    TabelaTipos["char>=int"] = "ERRO";
    TabelaTipos["char>=float"] = "ERRO";
    TabelaTipos["char>=string"] = "ERRO";
    TabelaTipos["char>=char"] = "ERRO";
    
    TabelaTipos["int<int"] = "bool";
    TabelaTipos["int<float"] = "bool";
    TabelaTipos["int<string"] = "ERRO";
    TabelaTipos["int<char"] = "ERRO"; 
    TabelaTipos["float<int"] = "bool";
    TabelaTipos["float<float"] = "bool";
    TabelaTipos["float<string"] = "ERRO";
	TabelaTipos["float<char"] = "ERRO";
    TabelaTipos["string<int"] = "ERRO";
    TabelaTipos["string<float"] = "ERRO";
    TabelaTipos["string<string"] = "ERRO";
    TabelaTipos["string<char"] = "ERRO";
    TabelaTipos["char<int"] = "ERRO";
    TabelaTipos["char<float"] = "ERRO";
    TabelaTipos["char<string"] = "ERRO";
    TabelaTipos["char<char"] = "ERRO";
    
    TabelaTipos["int=<int"] = "bool";
    TabelaTipos["int=<float"] = "bool";
    TabelaTipos["int=<string"] = "ERRO";
    TabelaTipos["int=<char"] = "ERRO"; 
    TabelaTipos["float=<int"] = "bool";
    TabelaTipos["float=<float"] = "bool";
    TabelaTipos["float=<string"] = "ERRO";
	TabelaTipos["float=<char"] = "ERRO";
    TabelaTipos["string=<int"] = "ERRO";
    TabelaTipos["string=<float"] = "ERRO";
    TabelaTipos["string=<string"] = "ERRO";
    TabelaTipos["string=<char"] = "ERRO";
    TabelaTipos["char=<int"] = "ERRO";
    TabelaTipos["char=<float"] = "ERRO";
    TabelaTipos["char=<string"] = "ERRO";
    TabelaTipos["char=<char"] = "ERRO";
    
    TabelaTipos["int==int"] = "bool";
    TabelaTipos["int==float"] = "bool";
    TabelaTipos["int==string"] = "ERRO";
    TabelaTipos["int==char"] = "ERRO"; 
    TabelaTipos["float==int"] = "bool";
    TabelaTipos["float==float"] = "bool";
    TabelaTipos["float==string"] = "ERRO";
	TabelaTipos["float==char"] = "ERRO";
    TabelaTipos["string==int"] = "ERRO";
    TabelaTipos["string==float"] = "ERRO";
    TabelaTipos["string==string"] = "ERRO";
    TabelaTipos["string==char"] = "ERRO";
    TabelaTipos["char==int"] = "ERRO";
    TabelaTipos["char==float"] = "ERRO";
    TabelaTipos["char==string"] = "ERRO";
    TabelaTipos["char==char"] = "ERRO";
    
    TabelaTipos["int!=int"] = "bool";
    TabelaTipos["int!=float"] = "bool";
    TabelaTipos["int!=string"] = "ERRO";
    TabelaTipos["int!=char"] = "ERRO"; 
    TabelaTipos["float!=int"] = "bool";
    TabelaTipos["float!=float"] = "bool";
    TabelaTipos["float!=string"] = "ERRO";
	TabelaTipos["float!=char"] = "ERRO";
    TabelaTipos["string!=int"] = "ERRO";
    TabelaTipos["string!=float"] = "ERRO";
    TabelaTipos["string!=string"] = "ERRO";
    TabelaTipos["string!=char"] = "ERRO";
    TabelaTipos["char!=int"] = "ERRO";
    TabelaTipos["char!=float"] = "ERRO";
    TabelaTipos["char!=string"] = "ERRO";
    TabelaTipos["char!=char"] = "ERRO";
}
