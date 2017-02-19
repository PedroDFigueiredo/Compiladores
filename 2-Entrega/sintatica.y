%{
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <vector>
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
    vector<string> colLabels;
    
};

class VarNode{
    public: 
        string nomeTKid; //a, b;
        string nomeTemp; //Var0, Var2;
        string tipo;
        int tamString;
        VarNode(string , string, string, int);
};
VarNode::VarNode(string a, string b, string c, int d = 0){
    nomeTemp = a;
    tipo = b;
    nomeTKid = c;
    tamString = d;
};
VarNode* getVar(string nomeTemp);
typedef map<string, VarNode*> MapVarNode;
pair<string,string> geraLabelEscopo();

class Escopo{
    public:
        int nivel;
        int profundidade;
        bool isCondicional;
        string labelInicio;
        string labelFim;
        MapVarNode tkIdTable;
        MapVarNode varTable;
        vector<Escopo*> list_escopo;
        Escopo *escopoPai;
        Escopo(int);
        Escopo(int, int);

};
Escopo::Escopo(int n){
    nivel = n;
};
Escopo::Escopo(int a, int b){
    nivel = a;
    profundidade = b;

    pair<string,string> p = geraLabelEscopo();
    labelInicio = p.first;
    labelFim = p.second;
};

//vector< Escopo*> list_escopo;
Escopo *EscopoGlobal = new Escopo(0, 0);
Escopo *EscopoAtual = EscopoGlobal;


//Contagem para tabela de variaveis
//criar por escopo
int varCount=0;
int nivel_escopo = 0;
int profu_escopo = 1;
int labelCount = 1;
string switch_var;
string condicional_label;

void iniEscopoIf();
void iniEscopo();
void fimEscopo();


void criaTabelaTipos();
void addNewVarToTable(string nomeTemp, string tipo);

//string verificaTipo(string tipoA, string operador, string tipoB);
string verificaTipo(atributos *a, atributos *b,string operador, atributos *c);
string verificaTipoRelacional(atributos *a, atributos *b,string operador, atributos *c);
pair<string, string> verificaTipoRelacional(string a, string operador, string b);
string verificaTipoAtribuicao(string label1, string operador, string label2);
string buscaTipoTabela(string tipoA, string operador, string tipoB);
string verificaTipoLogico(atributos *a, atributos *b,string operador, atributos *c);
string geraVarString(atributos *a);
string geraVarSubrescritaString(string a, string b);

string to_string(int i);
string addNewVar();
string geraVar(string tipo);
string geraVar(string tipo, string tkid);
string decl = "";

//busca variaveis dentro do escopo
pair<bool, VarNode*> varByTkid(string tkid);
pair<bool, VarNode*> varByNameTemp(string nomeTemp);


//prints declarações variáveis...
void printDeclarations();

pair<string,string> geraLabelEscopo();

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
%token TK_INT TK_FLOAT TK_CHAR TK_BOOL TK_STRING
//Condicionais e loops
%token TK_WHILE TK_FOR TK_SWITCH TK_CASE TK_IF TK_ELSE TK_ELIF
%token TK_BREAK TK_CONTINUE TK_DO TK_DEFAULT
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

                cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nusing namespace std;\nint main(void)\n{\n";
                printDeclarations();
                cout <<"\n\n"<< $5.traducao << "\treturn 0;\n}" << endl; 
            }
            ;

BLOCO		: TK_ABRE INI_ESCOPO COMANDOS /*FIM_ESCOPO*/ TK_FECHA
            {
            	cout<<"//BLOCO\n";
                $$.traducao = $3.traducao;

            }
            | TK_ABRE INI_ESCOPO FIM_ESCOPO TK_FECHA //escopo vazio
            {
                $$.traducao = "";
            }
            | INI_ESCOPO COMANDO
            {
    	cout<<"//BLOCO::"<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->nivel<<"\n";

                $$.traducao = $2.traducao;
            }
            ;
BLOCO_IF     : TK_ABRE INI_ESCOPO_IF COMANDOS /*FIM_ESCOPO*/ TK_FECHA
            {
                cout<<"//BLOCO\n";
                $$.traducao = $3.traducao;

            }
            | TK_ABRE INI_ESCOPO_IF FIM_ESCOPO TK_FECHA //escopo vazio
            {
                $$.traducao = "";
            }
            | INI_ESCOPO_IF COMANDO
            {
                cout<<"//BLOCO::"<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->nivel<<"\n";

                $$.traducao = $2.traducao;
            }
            ;

BLOCO_SE       : TK_ABRE COMANDOS /*FIM_ESCOPO*/ TK_FECHA
            {
                cout<<"//BLOCO_SE\n";
                $$.traducao = $2.traducao;

            }
            | TK_ABRE FIM_ESCOPO TK_FECHA //escopo vazio
            {
                $$.traducao = "";
            }
            | COMANDO
            {
        cout<<"//BLOCO_SE::"<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->nivel<<"\n";

                $$.traducao = $1.traducao;
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
INI_ESCOPO_IF: { 
                iniEscopoIf();
            };
INI_ESCOPO: { 
                iniEscopo();
            };
FIM_ESCOPO: { 
                fimEscopo();
            };

COMANDO     : OPERACAO ';'
            | NUMEROS ';'
            | DECLARA ';'
            | ATRIBUICAO ';'
            | BLOCO
            | CONDICIONAL
            | LOOP
            | CMD_COUT ';'
			| CMD_CIN ';'
            | CONTINUE ';'
            | BREAK ';'
            | SWITCHCASE
/*          

            | CONDICIONAL_ELSE
            | FUNCAO
            | SUPERBREAK ';'
            | SUPERCONTINUE ';'
*/

            ;

OPERACAO    : ARITMETICO
            | LOGICO
            | RELACIONAL
//          | CONCATENACAO
            ;
            
ARITMETICO  : ARITMETICO OP_ARITMETICO ARITMETICO
            { 

                $$.traducao = $1.traducao + $3.traducao + verificaTipo(&$$, &$1, $2.traducao, &$3);
                
            }
            |ARITMETICO2
            | '('ARITMETICO')' {

                $$.traducao = $2.traducao; $$.label = $2.label; $$.tipo = $2.tipo;}
            //|NUMEROS 
            //|TK_ID
            ;


ARITMETICO2 : ARITs OP_ARITMETICO2 ARITs
            {
                
                $$.traducao = $1.traducao + $3.traducao + verificaTipo(&$$, &$1, $2.traducao, &$3);
                
            } 
            | '(' ARITMETICO2 ')' { 
                
                $$.traducao = $2.traducao; $$.label = $2.label; $$.tipo = $2.tipo;}
            |NUMEROS 
 //           |TK_ID
            ;

ARITs       : ARITMETICO2
            | '(' ARITMETICO ')'  {
            
                $$.traducao = $2.traducao; $$.label = $2.label;}

            ;
            
RELACIONAL	: RELs OP_RELACIONAL RELs	
			{    
				$$.traducao = $1.traducao + $3.traducao + verificaTipoRelacional(&$$, &$1, $2.traducao, &$3);
			
			}
			| '(' RELACIONAL ')' { $$.traducao = $2.traducao; $$.label = $2.label; $$.tipo = $2.tipo; }
			| ARITMETICO;
			;

RELs 		: RELACIONAL;

LOGICO		: LOGs OP_LOGICO LOGs
			{ 
                $$.traducao = $1.traducao + $3.traducao + verificaTipoLogico(&$$, &$1, $2.traducao, &$3);
			}
			| '(' LOGICO ')' { $$.traducao = $2.traducao; $$.label = $2.label; $$.tipo = $2.tipo;  }
			;

LOGs 		: LOGICO | RELACIONAL ;

            
            


//OP_CONCAT         : TK_CONCAT;

OP_LOGICO       : TK_AND | TK_OR ;

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
                cout<<"DECLARA"<<$2.traducao<<"\n";
                addNewVarToTable($2.traducao, $2.tipo);

                VarNode *var = getVar($2.traducao);

                $$.traducao = "";
                
            }
            ;


/**
    ATRIBUIÇÕES
**/     

ATRIBUICAO  : TK_ID TK_ATRIBUICAO OPERACAO{
            //Para pegar a variável do tk_id TK_ID
            //std::cout << "$1 " << getVar($1.traducao)->nomeTemp << "  $Operacao " << $3.label << std::endl; //verfica se mome da variavel já foi declarado e retorna nome temporário
            
            string aux = "";
                //$$.traducao = $3.traducao + "\t"+ $1.label + " "+ $2.label + " " +$3.label + "\n";
                if($3.label != ""){
                    aux = verificaTipoAtribuicao(getVar($1.traducao)->nomeTemp, $2.traducao, $3.label);
                    
                    $$.traducao = $3.traducao + aux;
                }
                else{
                    aux = verificaTipoAtribuicao(getVar($1.traducao)->nomeTemp, $2.traducao, $3.traducao);
                    
                    $$.traducao = $3.traducao + aux;
                    $$.traducao = "\t"+getVar($1.traducao)->nomeTemp +" "+$2.traducao+" "+getVar($3.traducao)->nomeTemp+";\n";
                }

            }
            |DECLARA_E_ATRIBUI
            |INCREMENTAL
            ;

INCREMENTAL : TK_ID TK_MENOS TK_MENOS{
                VarNode *var = getVar($1.traducao); 

                $$.traducao = "\t" + var->nomeTemp + " = " + var->nomeTemp + " " + $2.traducao +" 1;\n";
            }
            | TK_ID TK_MAIS TK_MAIS{
                VarNode *var = getVar($1.traducao); 

                $$.traducao = "\t" + var->nomeTemp + " = " + var->nomeTemp + " " + $2.traducao +" 1;\n";
            };

/**
    DECLARAÇÃO com ATRIBUIÇÃO
**/           
DECLARA_E_ATRIBUI : TIPO IDs TK_ATRIBUICAO OPs// int a
            {
                string aux = "";
                cout<<"//DECLARA_E_ATRIBUI::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim;

                for (int i = 0; (i < $2.colLabels.size()) && (i < $4.colLabels.size()); i++){

                    addNewVarToTable($2.colLabels[i], $2.tipo);
                    //não será necessário essa parte assim que a partede scopo for criada, 'geraVar' irá inseri a declaração para ser impressa no escopo  qual pertence
                    //aux += "\t"+getVar($2.colLabels[i])->tipo+" "+getVar($2.colLabels[i])->nomeTemp +";\n"; // DECLARA 
cout<<" "<<$2.colLabels[i]<<"\n";
                    aux += verificaTipoAtribuicao(getVar($2.colLabels[i])->nomeTemp, $3.traducao, $4.colLabels[i]);
                }

                $$.traducao = $4.traducao  + aux;
            }
            ;


TIPO        : TK_TIPO_STRING 
            | TK_TIPO_FLOAT 
            | TK_TIPO_CHAR 
            | TK_TIPO_BOOL 
            | TK_TIPO_INT;

NUMEROS     :  TK_INT
            {
                $$.label = geraVar($1.tipo);
                //$$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    
                $$.traducao = "\t" + $$.label +" = " + $1.traducao + ";\n";    
            }
            | TK_CHAR
            {
                $$.label = geraVar($1.tipo);
                //$$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    
                $$.traducao = "\t" + $$.label +" = " + $1.traducao + ";\n";    
            }
            | TK_FLOAT
            {
                $$.label = geraVar($1.tipo);
                //$$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    
                $$.traducao = "\t" + $$.label +" = " + $1.traducao + ";\n";    
            }
            | TK_ID
            {
                $$.label = getVar($1.traducao)->nomeTemp; //verfica se mome da variavel já foi declarado e retorna nome temporário
                $$.tipo = getVar($1.traducao)->tipo; //verfica se mome da variavel já foi declarado e retorna tipo
                $$.traducao = "";

            }
            | TK_STRING
			{
			    //$1.tamString = $$.traducao.length()-1; //Pega o tamanho da string menos 1;
			    $$.label = geraVarString(&$1);
			    //std::cout << "Teste: " << $1.traducao << $$.label << std::endl;
			    $$.traducao = "\tstrcpy (" + $$.label + "," + $1.traducao + ");\n";
			    
			}
            | TK_BOOL
			{
				$$.label = geraVar($1.tipo);
                //$$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    
                $$.traducao = "\t" + $$.label +" = " + $1.traducao + ";\n";    
						
			}
            ;

/**
    ATRIBUIÇÃO MULTIPLA e PARAMETORS FUNÇÂO
**/ 
IDs         : IDs ',' TK_ID 
            {
                $$.colLabels = $1.colLabels;

                $$.colLabels.push_back($3.traducao);
            }
            | TK_ID 
            { 


                vector<string> e;
                $$.colLabels = e;
                $$.colLabels.push_back($1.traducao); 
            }

OPs         : OPs ',' OPERACAO  
            {   
                $$.traducao = $1.traducao + $3.traducao;
                $$.colLabels = $1.colLabels;
                $$.colLabels.push_back($3.label);
            }
            | OPERACAO
            {   

                vector<string> e;
                $$.colLabels = e;
                if ($1.label != "")
                    $$.colLabels.push_back($$.label);
                else{
                    if($1.colLabels.size() > 0){
                        for (int i = 0; i < $1.colLabels.size(); i++)
                        {
                            $$.colLabels.push_back($1.colLabels[i]);
                        }
                    }
                    else
                        yyerror("ERRO");
                }
            };

/**
    CONDICIONAIS
**/

CONDICIONAL : INI_ESCOPO_IF IF ELSEs{
                cout<<"//CONDICIONAL ELSEs::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<"\n";
                $$.traducao = $2.traducao;
                $$.traducao += "\tgoto " + EscopoAtual->labelFim+";\n"; 
                $$.traducao += $2.label +":\n";
                $$.traducao += $3.traducao + "\n" + EscopoAtual->labelFim +":\n\n";
                fimEscopo();

            } 
            | INI_ESCOPO_IF IF {
                cout<<"//CONDICIONAL IF::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<"\n";
                $$.traducao = $2.traducao + $2.label + ":\n//fim_if\n\n";
                fimEscopo();

            } 
            ;
IF          : TK_IF '(' RELACIONAL ')' BLOCO_IF {
                cout<<"//IF::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<"\n";
                $$.label  = EscopoAtual->labelFim;

                $$.traducao = "\n//ini_if\n" + $3.traducao;
                $$.traducao += "\n\tif (!("+ $3.label +")) goto " + EscopoAtual->labelFim +";"; 
                $$.traducao += "\n" + $5.traducao +"\n";
                /*$$.traducao += "\tgoto " + EscopoAtual->escopoPai->labelFim+":\n"; 
                $$.traducao += EscopoAtual->labelFim +":\n\n";*/

                fimEscopo();
            };


ELSEs       : ELSE ELSEs 
            {
                $$.label = $1.label + $2.label;
                $$.traducao = $1.traducao + $2.traducao;
                cout<<"//ELSEs::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<" -->"<<"\n";

            }
            | ELSE 
            ;

ELSE        : TK_ELIF '(' RELACIONAL ')' BLOCO_IF {
                cout<<"//TK_ELIF ELSE::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<"\n";

                
                $$.traducao = "\n//ini_elif\n" +$3.traducao;
                $$.traducao += "\n\tif (!("+ $3.label +")) goto " + EscopoAtual->labelFim +";"; 
                $$.traducao += "\n" + $5.traducao ;
                $$.traducao += "\ngoto " + EscopoAtual->escopoPai->labelFim +";\n"; 
                $$.traducao += "\n" + EscopoAtual->labelFim+":";
                fimEscopo();

            }
            | TK_ELSE BLOCO{
                cout<<"//TK_ELSE::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<"\n";

                $$.traducao = "\n//ini_else\n" +$2.traducao ;
                fimEscopo();
            } ;

SWITCHCASE  : SWITCH TK_ABRE INI_ESCOPO CASEs /*FIM_ESCOPO*/ TK_FECHA
            {
                cout<<"//SWITCHCASE::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<"_"<< to_string(profu_escopo)<<" switch_var"<<switch_var<<"\n";

                $$.traducao = $1.traducao + $4.label;
                $$.traducao += "\ngoto "+EscopoAtual->labelFim +";\n\n";
                $$.traducao += $4.traducao;
                $$.traducao += "//fim_switch_case\n"+ EscopoAtual->labelFim +":\n\n";
                fimEscopo();


            }
            | SWITCH TK_ABRE INI_ESCOPO CASEs DEFAULT TK_FECHA
            {
                cout<<"//SWITCHCASEDEFA::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<"_"<< to_string(profu_escopo)<<" switch_var"<<switch_var<<"\n";

                $$.traducao = $1.traducao + $4.label + $5.label;
                $$.traducao += "\ngoto "+EscopoAtual->labelFim +";\n\n";
                $$.traducao += $4.traducao + $5.traducao;
                $$.traducao += "//fim_switch_case\n"+ EscopoAtual->labelFim +":\n\n";
                fimEscopo();

            };

SWITCH      : TK_SWITCH '(' OPERACAO ')'  
            {
                switch_var = $3.label;
                $$.traducao = $3.traducao;
                cout<<"//SWITCH::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<"_"<< to_string(nivel_escopo)<<" switch_var"<<switch_var<<"\n";


            };

CASEs       : CASE CASEs 
            {

                $$.label = $1.label + $2.label;
                $$.traducao = $1.traducao + $2.traducao;
                cout<<"//CASEs::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<" -->"<<"\n";

            }
            | CASE 
            ;

CASE        : TK_CASE OPERACAO ':' BLOCO
            {
                pair<string, string> rtn = verificaTipoRelacional(switch_var, "==", $2.label);
                $$.label = "\n//ini_case\n";
                $$.label += $2.traducao;
                $$.label += rtn.second;
                $$.label += "\n\tif ("+ rtn.first +") goto " + EscopoAtual->labelInicio +";\n"; 
                $$.traducao = EscopoAtual->labelInicio+ ":\n";
                $$.traducao += $4.traducao ;
                $$.traducao += "//fim_case\n\n";
               // $$.traducao += EscopoAtual->labelFim+":\n\n";
                cout<<"//CASE::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<"\n";
                fimEscopo();


            };
DEFAULT     : TK_DEFAULT ':' BLOCO
            {
                pair<string, string> label = geraLabelEscopo();

                $$.label = "\n//ini_defalut";
                $$.label += "\n\tgoto " + EscopoAtual->labelInicio +";\n"; 
                $$.traducao = EscopoAtual->labelInicio + ":\n";
                $$.traducao += $3.traducao ;
                $$.traducao += "//fim_default\n\n";
                cout<<"//DEFAULT::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<"\n";

                fimEscopo();


            };

BREAK       : TK_BREAK  {
                cout<<"//TK_CONTINUE::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<"\n";

                Escopo *e = EscopoAtual->escopoPai;
                while(e->escopoPai != 0 && e->isCondicional){
                    e = e->escopoPai;
                }
                $$.traducao = "\tgoto "+e->labelFim + ";//break\n";

            };

CONTINUE    : TK_CONTINUE  {
                cout<<"//TK_CONTINUE::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<"\n";

                Escopo *e = EscopoAtual;
                while(e->escopoPai != 0 && e->isCondicional){
                    e = e->escopoPai;
                }
                $$.traducao = "\tgoto "+e->labelInicio + ";//continue\n";

            };

/**
    LOOPs
**/

LOOP :   TK_WHILE '(' RELACIONAL ')' BLOCO{
            cout<<"//TK_WHILE::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<"_"<< to_string(nivel_escopo)<<"\n";

            pair<string, string> label = geraLabelEscopo();

            $$.traducao = "//ini_while\n"+ EscopoAtual->labelInicio + ":\n";    
            $$.traducao += $3.traducao;
            $$.traducao += "\n\tif (!("+ $3.label +")) goto " + EscopoAtual->labelFim +";"; 
            $$.traducao += "\n" + $5.traducao ;
            $$.traducao += "\n\tgoto " + EscopoAtual->labelInicio +";\n";
            $$.traducao += "\n" + EscopoAtual->labelFim +":\n//fim_while\n\n";
            fimEscopo();

        }
        | INI_ESCOPO TK_FOR '(' ATRIBUICAO ';' RELACIONAL ';' ATRIBUICAO')' BLOCO_SE{
            cout<<"//TK_FOR::"<<EscopoAtual->nivel<<" "<<EscopoAtual->profundidade<<" "<<EscopoAtual->labelFim<<"_"<< to_string(nivel_escopo)<<"\n";
            
            $$.traducao = "//ini_for\n"+$4.traducao;
            $$.traducao += "\n"+ EscopoAtual->labelInicio + "_l:\n"; 
            $$.traducao += $6.traducao ;
            $$.traducao += "\n\tif (!("+ $6.label +")) goto " + EscopoAtual->labelFim +";"; 
            $$.traducao += "\n" + $10.traducao +"\n";
            $$.traducao +=  EscopoAtual->labelInicio +":\n"+ $8.traducao;
            $$.traducao += "\n\tgoto " + EscopoAtual->labelInicio +"_l;\n" + EscopoAtual->labelFim +":\n//fim_for\n\n";

            fimEscopo();
        }
        | TK_DO BLOCO TK_WHILE '(' RELACIONAL ')' ';' {

            $$.traducao = "\n//ini_do_while\n"+ EscopoAtual->labelInicio + ":\n"; 
            $$.traducao += $2.traducao;

            $$.traducao += $5.traducao ;
            $$.traducao += "\n\tif ("+ $5.label +") goto " + EscopoAtual->labelInicio +";\n";
            $$.traducao += EscopoAtual->labelFim+": //fim_do_while\n\n"; 

            fimEscopo();
            //$$.traducao += "\n goto " + label.first +";\n\n" + label.second +":\n";
        }
        ;

        
CMD_CIN     :  //TK_VAR TIPO TK_ID TK_ATRIBUICAO TK_READ 
            //{


                // if($2.tipoReal == "string"){
                //  nova_var_string($3.label, 0);
            //      resetaString($3.label, 1024);
            //      variavel var = use_var($3.label, $3.tipo);
                //  $$.traducao = "\t cin >> " + var.temp_name + " ;\n";
                // }
                // else
                // {
            //      $$.label = nova_var($3.label, $2.tipo);
                //  $$.traducao = "\t cin >> " + $$.label + " ;\n";
                // }
            //}
            //| TK_GLOBAL TK_VAR TIPO TK_ID TK_ATRIBUICAO TK_READ// global var int a;
            //{
                // if($3.tipoReal == "string"){
                //  nova_var_string($4.label, 0);
            //      resetaString($4.label, 1024);
            //      variavel var = use_var($4.label, $4.tipo);
                //  $$.traducao = "\tcin >> " + var.temp_name + " ;\n"; 
                // }else
                // {
            //      $$.label = nova_var($4.label, $3.tipo);
                //  $$.traducao = "\tcin >> " + $$.label + " ;\n";
                // }
            //}
            | TK_READ '('TK_ID')'
            {
                // if($3.tipoReal == "string"){
            //      resetaString($3.label, 1024);
            //      variavel var = use_var($3.label, $3.tipo);
                  //$$.traducao = "\t cin << " + var.temp_name + " ;\n";    
                // }
                // else{
                //  $$.traducao = "\t cin << " + $3.label + " ;\n"; 
                // }
            }
            ;


CMD_COUT 	: TK_WRITE '(' OPERACAO ')'
			{	
				$$.traducao = $3.traducao;
				$$.traducao += "\tcout << " + $3.label + " <<\"\\n\";\n";
			}
			;
%%


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{   
   
	 char var0_0[6]; 

	strcpy (var0_0,"teste");

    yyparse();
    //for (map<string,VarNode*>::iterator it=tkIdTable.begin(); it!=tkIdTable.end(); ++it)

    return 0;
}

void yyerror( string MSG )
{
    cout<<"ERROR:\n"<<MSG<<"\n";
    exit (1);
}   

std::string to_string(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

string geraVar(string tipo){
    string var =("var" + to_string(nivel_escopo) +"_"+ to_string(varCount++));

    VarNode *varnode = new VarNode(var, tipo, "");

    //INCLUI EM BLOCO do ESCOPO atual
    EscopoAtual->varTable[var] = varnode;

    return var; 
}

string geraVarString(atributos *a){
   // std::cout << a->tamString << std::endl;
    //strcpy(dest, src);
    int tamString;
    
    string var =("var" + to_string(nivel_escopo) +"_"+ to_string(varCount++) );
    tamString = a->traducao.length()-1; //Pega o tamanho da string menos 1;
    std::cout <<  tamString << std::endl;
    //string varTamVetor = var + "[" + to_string(a->tamString) + "]";

    VarNode *varnode = new VarNode(var, "string", "", tamString);

    //INCLUI EM BLOCO do ESCOPO atual
    EscopoAtual->varTable[var] = varnode;

    return var; 
}




string geraVar(string tipo, string tkid){
    string var =("var" + to_string(nivel_escopo) +"_"+ to_string(varCount++));

    VarNode *varnode = new VarNode(var, tipo, tkid);

    //INCLUI EM BLOCO do ESCOPO atual
    EscopoAtual->varTable[var] = varnode;
    EscopoAtual->tkIdTable[var] = varnode;

    return var; 
}
pair<bool, VarNode*> getVarByNameTemp(string nomeTemp){
    Escopo * e = EscopoAtual;
    
    pair<bool, VarNode*> rtn;
        
    while(e->escopoPai != 0){

        if(e->varTable.find(nomeTemp)!=e->varTable.end()){
            rtn.first = true;
            rtn.second = e->varTable[nomeTemp];
            return rtn;
        }
        e = e->escopoPai;
    }
    rtn.first = false;

    return rtn;
}
pair<bool, VarNode*> getVarByTkid(string tkid){
    Escopo * e = EscopoAtual;
    
    pair<bool, VarNode*> rtn;
    while(e->escopoPai != 0){

        if(e->tkIdTable.find(tkid)!=e->tkIdTable.end()){
            rtn.first = true;
            rtn.second = e->tkIdTable[tkid];
            return rtn;
        }
        e = e->escopoPai;
    }
    rtn.first = false;

    return rtn;
}
void addNewVarToTable(string nomeTemp, string tipo){
 
    if(EscopoAtual->tkIdTable.find(nomeTemp)==EscopoAtual->tkIdTable.end()){
        //verifica se variavel existe noescopo atual
        EscopoAtual->tkIdTable[nomeTemp] = EscopoAtual->varTable[geraVar(tipo, nomeTemp)];
    }else{
        //verifica se a nova variavel está na tabela
        pair<bool, VarNode*> p = getVarByTkid(nomeTemp);
        if(p.first){
            yyerror("error: redeclaração da variavel '"+tipo+" "+nomeTemp+ "'\n");
        }else{
            EscopoAtual->tkIdTable[nomeTemp] = EscopoAtual->varTable[geraVar(tipo, nomeTemp)];
        }
    }
}
//busca variavel por tkid
VarNode* getVar(string nomeTemp){
    pair<bool, VarNode*> p = getVarByTkid(nomeTemp);
    if(!p.first){
        yyerror("error: variavel não foi declarada '"+nomeTemp+ "'\n");
    }

    return p.second;
}
//busca variavel por label
VarNode* getLabel(string label){
    pair<bool, VarNode*> p = getVarByNameTemp(label);
    if(!p.first){
        yyerror("error: variavel temporária inexistente '"+label+ "'\n");
    }

    return p.second;
  
}

string verificaTipo(atributos *a, atributos *b,string operador, atributos *c){
    string tipo = buscaTipoTabela(b->tipo, operador, c->tipo);
    string var = "", rtn = "";

    if(b->tipo != tipo) {
        var = geraVar(tipo);
        rtn += "\t" +  var +" = ";
        rtn += "("+ tipo +") "+ b->label +";\n";
        b->label = var;
    }

    if(c->tipo != tipo) {
        var = geraVar(tipo);
        rtn += "\t" +  var +" = ";
        rtn += "("+ tipo +") "+ c->label +";\n";
        c->label = var;
    }
    var = geraVar(tipo);

    a->label = var;
    rtn += "\t" +  var +" = "+ b->label+" "+operador + " "+c->label+";\n";
    
    return rtn ;
}

string verificaTipoRelacional(atributos *a, atributos *b,string operador, atributos *c){
    string tipo = buscaTipoTabela(b->tipo, operador, c->tipo); 
    string var = "", rtn = "";
/*
    if(b->tipo != tipo) {
        var = geraVar(tipo);
        rtn += "\t" +  var +" = ";
        rtn += "("+ tipo +") "+ b->label +";\n";
        b->label = var;
    }

    if(c->tipo != tipo) {
        var = geraVar(tipo);
        rtn += "\t" +  var +" = ";
        rtn += "("+ tipo +") "+ c->label +";\n";
        c->label = var;
    }
*/
    var = geraVar(tipo);

    a->label = var;
    rtn += "\t" +  var +" = "+ b->label+" "+operador + " "+c->label+";\n";
    
    return rtn ;
}
pair<string, string> verificaTipoRelacional(string a, string operador, string b){
    string tipo = buscaTipoTabela(getLabel(a)->tipo, operador, getLabel(b)->tipo);

    string var = geraVar(tipo);
 
    pair<string, string> rtn;
    rtn.second = "\t" +  var +" = "+a+" "+operador + " "+b+";\n";
    rtn.first = var;
    return rtn ;

}


string verificaTipoLogico(atributos *a, atributos *b,string operador, atributos *c){
    string tipo = "bool"; //buscaTipoTabela(b->tipo, operador, c->tipo); 
  
    string var = "", rtn = "";
    
    var = geraVar(tipo);

    a->label = var;
    rtn += "\t" +  var +" = "+ b->label+" "+operador + " "+c->label+";\n";
    
    return rtn ;
}


string verificaTipoAtribuicao(string label1, string operador, string label2){
    VarNode *a = getLabel(label1);
    VarNode *b = getLabel(label2);
    string tipo = buscaTipoTabela(a->tipo, operador, b->tipo);
    //std::cout << "tipo: " <<tipo << std::endl;
    string var = "", rtn = "";

    if(b->tipo != tipo) {
        var = geraVar(tipo);
        //rtn += "\t" + tipo + " " + var +" = " + "("+ tipo +") "+ b->nomeTemp +";\n";
        rtn += "\t" + var +" = " + "("+ tipo +") "+ b->nomeTemp +";\n";
        rtn += "\t" + a->nomeTemp +" = " + var + ";\n";
    } 
    else{
         //rtn += "\t" + tipo + " " + a->nomeTemp +" = " + b->nomeTemp  + ";\n";
         if(a->tipo == "string") //caso seja string é necessário utilizar o strcpy;
         { 
             geraVarSubrescritaString(a->nomeTemp, b->nomeTemp);
             rtn += "\tstrcpy (" + a->nomeTemp + "," + b->nomeTemp  + ");\n";
         }
         else
         {
             rtn += "\t" + a->nomeTemp +" = " + b->nomeTemp  + ";\n";
         }
         

    }
    return rtn;
}

string geraVarSubrescritaString(string varA, string varB){
    VarNode *a = getLabel(varA);
    VarNode *b = getLabel(varB);
 
    int tamString = b->tamString; //Pega o tamanho da string menos 1;
     
    //std::cout << b->tamString << std::endl;
    string var =("var" + to_string(nivel_escopo) +"_"+ to_string(varCount++) );
    string varTamVetor = var + "[" + to_string(tamString) + "]";
    a->tamString = tamString;
    
    //a->nomeTemp = var;

    //VarNode *varnode = new VarNode(var, "string", "", tamString);

    //INCLUI EM BLOCO do ESCOPO atual
    //EscopoAtual->labelTable[var] = varnode;

    return "sas"; 
}

//busca na tabela tipo resultante de uma operação
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
void iniEscopoIf(){
    iniEscopo();
    EscopoAtual->isCondicional = true;   
}
void iniEscopo(){
        
    nivel_escopo++;
	cout<<"//iniEscopo:"<<to_string(nivel_escopo)<<" "<<to_string(profu_escopo)<<"\n";

    Escopo *e = new Escopo(nivel_escopo);

    pair<string,string> p = geraLabelEscopo();

    e->isCondicional = false;
    e->labelInicio = p.first;
    e->labelFim = p.second;

    e->profundidade = profu_escopo;
    profu_escopo++;
    
    EscopoAtual->list_escopo.push_back(e);
    e->escopoPai = EscopoAtual;
    EscopoAtual = e;

}
void fimEscopo(){
	cout<<"//fimEscopo:"<<to_string(nivel_escopo)<<" "<<to_string(EscopoAtual->profundidade)<<"\n";
    nivel_escopo--;
    EscopoAtual = EscopoAtual->escopoPai;
}
void printDeclarations(Escopo *esc){
    string temp = "";

    for (int i = 0; i< esc->list_escopo.size(); ++i){
        temp="";

        for( MapVarNode::const_iterator it = esc->list_escopo[i]->varTable.begin(); it != esc->list_escopo[i]->varTable.end(); ++it ){
            temp += "\t"
                    + (it->second->tipo != "string" ? it->second->tipo : "char") +" " //Se tipo for string é necessário transformar para char na declaração
                    + it->second->nomeTemp
                    + (it->second->tamString > 0 ? "[" + to_string(it->second->tamString) + "]" : "") //verifica se é string, se for define o tamanho
                    + "; "+(it->second->nomeTKid == "" ? "" : " //variavel: "+it->second->nomeTKid) +"\n";
        }
        cout<<temp;
        printDeclarations(esc->list_escopo[i]);
        
    }


}
void printDeclarations(){
    
    printDeclarations(EscopoGlobal);
   
}

pair<string,string> geraLabelEscopo(){
    pair<string, string> r;
    r.first = "INI_"+to_string(profu_escopo);
    r.second = "FIM_"+to_string(profu_escopo);

    return r;
}
string getLabelEscopoFim(){
    return EscopoAtual->labelFim;
}
