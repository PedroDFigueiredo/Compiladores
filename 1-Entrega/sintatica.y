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

string to_string(int i);
string addNewVar();
void addNewVarToTable(string type, string name, string varTemp);

struct atributos
{
	string label;
	string traducao;
};
class VarNode{
	public: 
		string name;
		string type;
		VarNode(string , string);
};
VarNode::VarNode(string a, string b){
	name = a;
	type = b;
};

VarNode* getVar(string name);

map<string, VarNode*> varTable;

int yylex(void);
void yyerror(string);
%}

%token TK_NUM
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

				$$.traducao = $1.traducao + $3.traducao + "\t" + var + " = " + $1.label + " + " + $3.label  +";\n";

				$$.label = var;

			}
			| E '-' E
			{
				string var = addNewVar();

				$$.traducao = $1.traducao + $3.traducao + "\t" + var + " = " + $1.label + " - " + $3.label  +";\n";

				$$.label = var;

			}
			| E '*' E
			{
				string var = addNewVar();

				$$.traducao = $1.traducao + $3.traducao + "\t" + var + " = " + $1.label + " * " + $3.label  +";\n";

				$$.label = var;

			}
			| E '/' E
			{
				string var = addNewVar();

				$$.traducao = $1.traducao + $3.traducao + "\t" + var + " = " + $1.label + " / " + $3.label  +";\n";

				$$.label = var;

			}
			| E '=' E
			{	

				//string var = addNewVar();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $1.label + " = " + $3.label + ";\n";

			}
			| TK_NUM
			{
				string var = addNewVar();

				$$.traducao = "\t"+ var + " = "+ $1.label + ";\n";

				$$.label = var; //Armazena o var no label para no próximo passo da recursão saber qual variavel foi criada.
			}
			
			|DECLARACAO TK_ID
			{
				//Criar tabela para guardar variavel 
				string var = addNewVar();

				$$.traducao = "\t"+ $1.traducao + var + "  ;\n";

				//insere variavel na tabela
				addNewVarToTable( $2.label, var, $1.traducao);
				$$.label = var;
			}
			|TK_ID
			{	
				//busca na tabela de variáveis, o nome da váriavel 
				$$.label =  getVar($1.label)->name;
			}
			;
			

//Declaração de tipos
DECLARACAO	: TK_TIPO_INT{
				//Criar tabela para guardar tipo 
				$$.traducao = "int "; //retorna int na recursão
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
	cout<<"\nSTART\n";
	yyparse();
cout<<"\n\n::::\n";
	for (map<string,VarNode*>::iterator it=varTable.begin(); it!=varTable.end(); ++it)
    cout << it->first << " => " << it->second->name << '\n';

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
void addNewVarToTable(string name, string varTemp, string type){
	//verifica se a nova variavel está na tabela
	if(varTable.find(name)!=varTable.end()){
		cout<<"ERRO: "<<name<< " already exists!!\n";
	}else{
		varTable[name] = new VarNode(varTemp, type);
	}
}
VarNode* getVar(string name){
	//cout<<varTable[name]->name<<" getVar\n";
	return varTable[name]; 
}