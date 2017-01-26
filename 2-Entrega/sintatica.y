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
    //string tipoReal;
    
};

string tipoDeclaracao;

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
//Operacoes Aritimeticas
%token TK_MAIS TK_MENOS TK_MULT TK_RAZAO TK_POTENCIA TK_CONCAT
//Operacoes logica
%token TK_AND TK_OR
//Operacores relacionais
%token TK_MAIOR TK_MENOR TK_DIFERENTE TK_IGUAL
//ATRIBUICAO
%token TK_ATRIB TK_VAR TK_GLOBAL
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
                cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nusing namespace std;\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
            }
            ;

BLOCO		: TK_ABRE COMANDOS TK_FECHA
            {
                std::cout << "bloco" << std::endl;
                $$.traducao = $2.traducao;
            }
            ;

COMANDOS	: COMANDO COMANDOS
			{
			 $$.traducao = $1.traducao + $2.traducao;
			}
			|
			;

COMANDO 	:  E ';'
			;
            
E           : OPERACAO ';'
            | NUMEROS ';'
/*          | FUNCAO
            | BREAK ';'
            | CONTINUE ';'
            | SUPERBREAK ';'
            | SUPERCONTINUE ';'
            | DECLARA ';'
            | CMD_COUT ';'
            | CMD_CIN ';'
*/
            ;

OPERACAO    : ARITMETICO
//          | LOGICO
//          | RELACIONAL
//          | CONCATENACAO
            ;
            
ARITMETICO  : ARITMETICO OP_ARITMETICO ARITMETICO
            { 
                cout<<"ARITMETICO"<<$2.traducao<<" "<<$3.traducao<<"\n";
                
            }
            |ARITMETICO2
            //| '('ARITMETICO')' { $$.traducao = $2.traducao; $$.label = $2.label; $$.tipo = $2.tipo; $$.tipoReal = $2.tipoReal;}
            |NUMEROS 
            ;


ARITMETICO2 : ARITs OP_ARITMETICO2 ARITs
            {

            
                
            } 
            | '(' ARITMETICO2 ')' { $$.traducao = $2.traducao; $$.label = $2.label; $$.tipo = $2.tipo;}
            |NUMEROS 
            ;

ARITs       : ARITMETICO2
            | '(' ARITMETICO ')'  { $$.traducao = $2.traducao; $$.label = $2.label;}
            ;
            
            

/*OP_CONCAT         : TK_CONCAT;

OP_LOGICO       : TK_AND | TK_OR ;

OP_RELACIONAL   : TK_DIFERENTE | TK_IGUAL | TK_MENOR | TK_MAIOR ;
*/
OP_ARITMETICO   : TK_MAIS | TK_MENOS ;

OP_ARITMETICO2  : TK_DIVISAO | TK_MULT ;


NUMEROS     :  TK_INT
            {
                
                string var = addNewVar();

                //$$.traducao = "\t"+$1.tipo+" "+ var + " = "+ $1.label + ";\n";
                //$$.traducao = "\tint "+ var + " = "+ $1.label + ";\n";

                $$.label = var; //Armazena o var no label para no próximo passo da recursão saber qual variavel foi criada.
                cout << "ENtrou NUMEROS: " <<  $1.traducao << " " << var << endl;
                
                decl += "\tint "+ var + ";\n";
                $$.traducao = "\t" + var + " = "+ $1.label + ";\n";
                
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
