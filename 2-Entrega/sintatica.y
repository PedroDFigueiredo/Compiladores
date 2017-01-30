%{
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include "TabelaTipos.h"

#define YYSTYPE atributos

using namespace std;



struct atributos
{
    string label;
    string operador;
    string traducao;
    string tipo;
    string nomeTemp;
    //string tipoReal;
    
};
/*struct variavel{
    string label;
    string tipo;
};
variavel *addNewVar(string tipo);*/

class VarNode{
    public: 
        string nomeTemp; //Var0, Var2;
        string tipo;
        VarNode(string , string);
};
VarNode::VarNode(string a, string b){
    nomeTemp = a;
    tipo = b;
};

VarNode* getVar(string nomeTemp);

map<string, VarNode*> varTable;

//Contagem para tabela de variaveis
//criar por escopo
int varCount=0;


void criaTabelaTipos();
void addNewVarToTable(string tipo, string nomeTemp, string varTemp);

//string verificaTipo(string tipoA, string operador, string tipoB);
string verificaTipo(atributos *a, atributos *b,string operador, atributos *c);
string buscaTipoTabela(string tipoA, string operador, string tipoB);

string to_string(int i);
string addNewVar();
string geraVar(string tipo);
string decl = "";


int yylex(void);
void yyerror(string);

%}
//Operacoes Aritimeticas
%token TK_MAIS TK_MENOS TK_MULT TK_RAZAO TK_POTENCIA TK_CONCAT
//Operacoes logica
%token TK_AND TK_OR
//Operacores relacionais
%token TK_MAIOR TK_MENOR TK_DIFERENTE TK_IGUAL
//ATRIBUICAO
%token TK_ATRIBUICAO TK_VAR TK_GLOBAL
//TIPOS
%token TK_TIPO_STRING TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL TK_TIPO_INT
//VALORES
%token TK_INT TK_FLOAT TK_CHAR TK_BOOL TK_STR
//Condicionais e loops
%token TK_WHILE TK_FOR TK_SWITCH TK_CASE TK_IF TK_ELSE TK_ELIF
%token TK_BREAK TK_CONTINUE TK_DO TK_DEFAUT
//Bloco
%token TK_ABRE TK_FECHA
//func + do
%token TK_FUNC TK_RETORNA TK_RETURN
//read write
%token TK_READ TK_WRITE 

%token TK_SUPER
%token TK_MAIN TK_ID 
%token TK_FIM TK_ERROR TK_END_E TK_FIMLINHA
%start S

%nonassoc TK_AND TK_OR 
%left TK_MAIS TK_MENOS
%left TK_MULT TK_DIVISAO

%%

S           : TK_TIPO_INT TK_MAIN '(' ')' BLOCO
            {
                 cout<< "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nusing namespace std;\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
            }
            ;

BLOCO		: TK_ABRE COMANDOS TK_FECHA
            {
                $$.traducao = $2.traducao;
            }
            ;

COMANDOS	: COMANDO COMANDOS
            { 
                $$.traducao = $1.traducao + $2.traducao;        
            }
            | COMANDO 
            {
                $$.traducao = $1.traducao;
            }
            ;


            
COMANDO     : OPERACAO ';'
            | NUMEROS ';'
            | DECLARA ';'
            | ATRIBUICAO ';'
/*          | FUNCAO
            | BREAK ';'
            | CONTINUE ';'
            | SUPERBREAK ';'
            | SUPERCONTINUE ';'
            | CMD_COUT ';'
            | CMD_CIN ';'
*/
            ;

OPERACAO    : ARITMETICO
//            | LOGICO
            | RELACIONAL
//          | CONCATENACAO
            ;
            
ARITMETICO  : ARITMETICO OP_ARITMETICO ARITMETICO
            { 
                $$.traducao = $1.traducao + $3.traducao + verificaTipo(&$$, &$1, $2.traducao, &$3);
                
            }
            |ARITMETICO2
            | '('ARITMETICO')' {; 

                $$.traducao = $2.traducao; $$.label = $2.label; $$.tipo = $2.tipo;}
            |NUMEROS 
            ;


ARITMETICO2 : ARITs OP_ARITMETICO2 ARITs
            {
                $$.traducao = $1.traducao + $3.traducao + verificaTipo(&$$, &$1, $2.traducao, &$3);
                
            } 
            | '(' ARITMETICO2 ')' { 
                $$.traducao = $2.traducao; $$.label = $2.label; $$.tipo = $2.tipo;}
            |NUMEROS 
            ;

ARITs       : ARITMETICO2
            | '(' ARITMETICO ')'  { 
                $$.traducao = $2.traducao; $$.label = $2.label;}
            ;
            
RELACIONAL	: RELs OP_RELACIONAL RELs	
			{
				$$.traducao = $1.traducao + $3.traducao + verificaTipo(&$$, &$1, $2.traducao, &$3);
			
			}
			| '(' RELACIONAL ')' { $$.traducao = $2.traducao; $$.label = $2.label; $$.tipo = $2.tipo; }
			| ARITMETICO;
			;

RELs 		: RELACIONAL;
            
            

//OP_CONCAT         : TK_CONCAT;

//OP_LOGICO       : TK_AND | TK_OR ;

OP_RELACIONAL   : TK_DIFERENTE | TK_IGUAL | TK_MENOR | TK_MAIOR ;

OP_ARITMETICO   : TK_MAIS 
                | TK_MENOS 
                | TK_DIVISAO 
                | TK_MULT ;

OP_ARITMETICO2  : TK_DIVISAO 
                | TK_MULT ;

/**
    DECLARAÇÃO SEM ATRIBUIÇÃO
**/
DECLARA     : TIPO TK_ID // int a
            {
                addNewVarToTable($2.traducao, geraVar($2.tipo), $2.tipo);

                //não será necessário assim que a partede scopo for criada, 'geraVar' irá inseri a declaração para ser impressa
                $$.traducao = "\t"+varTable[$2.traducao]->tipo+" "+varTable[$2.traducao]->nomeTemp +";\n";
                
            }
            | DECLARA_E_ATRIBUI
            ;
            
DECLARA_E_ATRIBUI : TIPO TK_ID TK_ATRIBUICAO NUMEROS// int a
            {
                addNewVarToTable($2.traducao, geraVar($2.tipo), $2.tipo);

                //não será necessário assim que a partede scopo for criada, 'geraVar' irá inseri a declaração para ser impressa
                $$.traducao = "\t"+varTable[$2.traducao]->tipo+" "+varTable[$2.traducao]->nomeTemp +";\n" + // DECLARA
                $4.traducao + "\t" +getVar($2.traducao)->tipo+" "+getVar($2.traducao)->nomeTemp +" "+$3.traducao+" "+$4.label+";\n"; //ATRIBUI
                
            }
            ;
/**
    ATRIBUIÇÕES
**/     

ATRIBUICAO  :  TK_ID TK_ATRIBUICAO NUMEROS{
                //$$.traducao = $3.traducao + "\t"+ $1.label + " "+ $2.label + " " +$3.label + "\n";
                $$.traducao = $3.traducao + "\t" +getVar($1.traducao)->tipo+" "+getVar($1.traducao)->nomeTemp +" "+$2.traducao+" "+$3.label+";\n";

            };

TIPO        : TK_TIPO_STRING 
            | TK_TIPO_FLOAT 
            | TK_TIPO_CHAR 
            | TK_TIPO_BOOL 
            | TK_TIPO_INT;

NUMEROS     :  TK_INT
            {
                $$.label = geraVar($1.tipo);
                $$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    

            }
            | TK_CHAR
            {
                $$.label = geraVar($1.tipo);
                $$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    
            }
            | TK_FLOAT
            {
                $$.label = geraVar($1.tipo);
                $$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    
            }
            | TK_ID
            {
                $$.label = getVar($1.traducao)->nomeTemp;
                $$.tipo = getVar($1.traducao)->tipo;
            }
            | TK_BOOL
			{
				$$.label = geraVar($1.tipo);
                $$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    
						
			}
            ;

%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{   
    yyparse();
    //for (map<string,VarNode*>::iterator it=varTable.begin(); it!=varTable.end(); ++it)

    return 0;
}

void yyerror( string MSG )
{
    cout << MSG << endl;
    exit (1);
}   

std::string to_string(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

string geraVar(string tipo){
    //INCLUIR EM BLOCO PARA ESCOPO
    string var =("var" + to_string(varCount++));
    return var; 
}
/*variavel *addNewVar(string tipo){
    variavel var;
    var.tipo = tipo;
    var.label = geraVar("");

    return &var;
}*/
void addNewVarToTable(string nomeTemp, string varTemp, string tipo){
    //verifica se a nova variavel está na tabela
    if(varTable.find(nomeTemp)!=varTable.end()){
        yyerror("error: redeclaration of '"+tipo+" "+nomeTemp+ "'\n");
    }else{
        varTable[nomeTemp] = new VarNode(varTemp, tipo);
    }
}
VarNode* getVar(string nomeTemp){
    if(varTable.find(nomeTemp)==varTable.end()){
        yyerror("error: variavel não foi declarada '"+nomeTemp+ "'\n");
    }
    return varTable[nomeTemp]; 
}

string verificaTipo(atributos *a, atributos *b,string operador, atributos *c){
    string tipo = buscaTipoTabela(b->tipo, operador, c->tipo);
    string var = "", rtn = "";

    if(b->tipo != tipo) {
        var = geraVar(tipo);
        rtn += "\t" + tipo + " " + var +" = ";
        rtn += "("+ tipo +") "+ b->label +";\n";
        b->label = var;
    }

    if(c->tipo != tipo) {
        var = geraVar(tipo);
        rtn += "\t" + tipo + " " + var +" = ";
        rtn += "("+ tipo +") "+ c->label +"\n";
        c->label = var;
    }
    var = geraVar(tipo);

    a->label = var;
    rtn += "\t" + tipo + " " + var +" = "+ b->label+" "+operador + " "+c->label+"\n";
    
    return rtn ;
}


string buscaTipoTabela(string tipoA, string operador, string tipoB){
    if(TabelaTipos.empty()){
        criaTabelaTipos();
    }
    string busca = tipoA+operador+tipoB;
    string retorno  = TabelaTipos.find(busca)->second;
    if(retorno == "ERRO")
        yyerror("ERRO");
    
    //TabelaTipos[busca]
    return retorno;
}
