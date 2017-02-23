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
    int valor;
    vector<string> colLabels;
    vector<int> dimensao;
    vector<string> dimensaoString;
    
};

class VarNode{
    public: 
        string nomeTKid; //a, b;
        string nomeTemp; //Var0, Var2;
        string tipo;
        int tamString;
        int tamVetor;
        vector<int> dimensoes;
        VarNode(string , string, string, int);
};
VarNode::VarNode(string a, string b, string c, int d = 0){
    nomeTemp = a;
    tipo = b;
    nomeTKid = c;
    tamString = d;
    tamVetor = 0;
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
string geraVarString(atributos *a, int flagCin);
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

//Matrizes
int auxVetor = 0;
vector<int> dimensaoMatrizOriginal;
vector<string> indexProcuradoMatriz;
void PegaDimensoesMatrizOriginal(string nomeTKid);
void PegaDimensaoIndexTemporario(atributos *a);
string CalculaIndexMatriz();
void ResetMatriz();
string retornoTraducao;

pair<string,string> geraLabelEscopo();
VarNode* getVar(string nomeTemp);
VarNode* getLabel(string label);

int yylex(void);
void yyerror(string);

%}
//Operacoes Aritimeticas
%token TK_MAIS TK_MENOS TK_MULT TK_RAZAO TK_POTENCIA TK_CONCAT
//Operacoes logica
%token TK_AND TK_OR
//Operacores relacionais
%token TK_MAIOR TK_MENOR TK_DIFERENTE TK_IGUAL TK_MAIOR_IGUAL TK_MENOR_IGUAL
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
                $$.traducao = $3.traducao;

            }
            | TK_ABRE INI_ESCOPO FIM_ESCOPO TK_FECHA //escopo vazio
            {
                $$.traducao = "";
            }
            | INI_ESCOPO COMANDO
            {

                $$.traducao = $2.traducao;
            }
            ;
BLOCO_IF     : TK_ABRE INI_ESCOPO_IF COMANDOS /*FIM_ESCOPO*/ TK_FECHA
            {
                $$.traducao = $3.traducao;

            }
            | TK_ABRE INI_ESCOPO_IF FIM_ESCOPO TK_FECHA //escopo vazio
            {
                $$.traducao = "";
            }
            | INI_ESCOPO_IF COMANDO
            {

                $$.traducao = $2.traducao;
            }
            ;

BLOCO_SE       : TK_ABRE COMANDOS /*FIM_ESCOPO*/ TK_FECHA
            {
                $$.traducao = $2.traducao;

            }
            | TK_ABRE FIM_ESCOPO TK_FECHA //escopo vazio
            {
                $$.traducao = "";
            }
            | COMANDO
            {

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
            | BLOCO_
            | CONDICIONAL
            | LOOP
            | CMD_COUT ';'
			| CMD_CIN ';'
            | CONTINUE ';'
            | BREAK ';'
            | SWITCHCASE


            ;
BLOCO_ : BLOCO {
                $$.traducao = $1.traducao;
                fimEscopo();
            };
OPERACAO    : ARITMETICO
            | LOGICO
            | RELACIONAL
            | CONCATENACAO
            ;
            
ARITMETICO  : ARITMETICO OP_ARITMETICO ARITMETICO
            { 

                $$.traducao = $1.traducao + $3.traducao + verificaTipo(&$$, &$1, $2.traducao, &$3);
                
            }
            |ARITMETICO2
            | '('ARITMETICO')' {

                $$.traducao = $2.traducao; $$.label = $2.label; $$.tipo = $2.tipo;
            }
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

            
            


OP_CONCAT         : TK_CONCAT;

OP_LOGICO       : TK_AND | TK_OR ;

OP_RELACIONAL   : TK_DIFERENTE | TK_IGUAL | TK_MENOR | TK_MAIOR | TK_MAIOR_IGUAL | TK_MENOR_IGUAL;

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
                addNewVarToTable($2.traducao, $2.tipo);

                VarNode *var = getVar($2.traducao);

                $$.traducao = "";
                
            }
            |DECLARA_VETOR
            ;

//DECLARACAO DE VETOR
DECLARA_VETOR
 			:TIPO TK_ID DIMENCAO 
 			{
 			    addNewVarToTable($2.traducao, $2.tipo);
 			    
 			    $$.traducao = "";//$3.traducao;
 			    
 			    VarNode *a = getVar($2.traducao);
 			    
 			    
 			    for (int i = 0 ; i < $3.dimensao.size(); i++)
				{
				   if(i == 0){
				        a->tamVetor = $3.dimensao[i];
				   }else{
				        a->tamVetor = a->tamVetor * $3.dimensao[i];
				   }
				  
				   //std::cout << $3.dimensao[i] << std::endl; 
				   a->dimensoes.push_back($3.dimensao[i]);
				}
 			    
 		
 			}
 			;
//Auxilia na declaração do vetor
DIMENCAO 	: '['NUMEROS']'
			{
			    if ($2.tipo	== "int")
 			 	{
 			 		$$.traducao = $2.traducao;
 			 		//std::cout << $2.valor << std::endl;
 			 	    
 			 		
 			 		$$.dimensao.push_back($2.valor);
 			 	
 			// 		$$.label = $2.label;
 			 	}
 			 	else
 			 	{
 			 		yyerror("Esse tipo não é aceito para um vetor");
 			 	}
 			
			}	
			| DIMENCAO DIMENCAO
			{
			    $$.traducao = $1.traducao + $2.traducao;
			    //$$.label = 
				// $$.label = nova_temp_var("int");
				// $$.traducao = $1.traducao; 
				// $$.traducao += $2.traducao + "\t"+ $$.label +" = "+ $1.label +" * " + $2.label+";\n" ;

			
				 for (int i = 0 ; i < $2.dimensao.size(); i++)
				 {
				 	$1.dimensao.push_back($2.dimensao[i]);
				 }
				 $$.dimensao = $1.dimensao;
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
                if($3.label != ""){ //Caso não tenha nenhuma operação antes
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
            |ATRIB_VETOR
            ;
            
ATRIB_VETOR : TK_ID INDEX TK_ATRIBUICAO OPERACAO
			{
			
                //$$.traducao = $3.traducao + "\t"+ $1.label + " "+ $2.label + " " +$3.label + "\n";
                // if($3.label != ""){ //Caso não tenha nenhuma operação antes
                //     aux = verificaTipoAtribuicao(getVar($1.traducao)->nomeTemp, $3.traducao, $4.label);
                    
                //     $$.traducao = $4.traducao + aux;
                // }
                // else{
                    string index = "";
				    
				    PegaDimensoesMatrizOriginal($1.traducao);
                    PegaDimensaoIndexTemporario(&$2);
                      
                    
				    index = CalculaIndexMatriz(); //Calcula o indice da matriz no codigo de 3 endereços
				    
				    
                   
                    $$.traducao = $2.traducao + $4.traducao  + retornoTraducao +
                    "\t"+getVar($1.traducao)->nomeTemp + "[" + index + "]" + " = " + $4.label + ";\n ";
                    ResetMatriz(); //Reseta os vectors das matrizes
                    
                // }
			}
			;
			
INDEX 	: '['NUMEROS']'
			{
			    
			    if ($2.tipo	== "int")
 			  	{
 			  	    std::cout << $2.nomeTemp << std::endl;
     			  	$$.dimensaoString.push_back($2.label);
    			    //auxVetor = auxVetor *  $2.valor;
    			    $$.traducao = $2.traducao;
 			   }
 			   else
 			   {
 			 		yyerror("Esse tipo não é aceito como index de um vetor");
 		       }
 			
			}	
			| INDEX INDEX
			{
			    $$.traducao = $1.traducao + $2.traducao;
			    //$$.label = 
				// $$.label = nova_temp_var("int");
				// $$.traducao = $1.traducao; 
				// $$.traducao += $2.traducao + "\t"+ $$.label +" = "+ $1.label +" * " + $2.label+";\n" ;

			
				  for (int i = 0 ; i < $2.dimensaoString.size(); i++)
				  {
				  	$1.dimensaoString.push_back($2.dimensaoString[i]);
				  }
				  $$.dimensaoString = $1.dimensaoString;
			}
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

                for (int i = 0; (i < $2.colLabels.size()) && (i < $4.colLabels.size()); i++){

                    addNewVarToTable($2.colLabels[i], $2.tipo);
                    //não será necessário essa parte assim que a partede scopo for criada, 'geraVar' irá inseri a declaração para ser impressa no escopo  qual pertence
                    //aux += "\t"+getVar($2.colLabels[i])->tipo+" "+getVar($2.colLabels[i])->nomeTemp +";\n"; // DECLARA 
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
                $$.valor = atoi($1.traducao.c_str()); //pega o valor para utilizar no vetor
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
			    $$.label = geraVarString(&$1, 0); // 0 pois não é do cin
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
            
CONCATENACAO: CONCATENACAO OP_CONCAT CONCATENACAO
			{
			    string aux = "";
			    VarNode *a = getLabel($1.label);
			    VarNode *b = getLabel($3.label);
			    
			    $$.label = geraVarString(&$1, 0); // 0 pois não é do cin
			    aux  = "\n\tstrcpy("+$$.label+",\"\");";
			    
			    VarNode *c = getLabel($$.label);
			    
			    if($1.tipo == "string" & $3.tipo == "string"){
			        
                    c->tamString = a->tamString + b->tamString;
                    
			        $$.traducao = aux + $1.traducao + $3.traducao +"\n\tstrcat("+$$.label+","+$1.label+");\n\tstrcat("+$$.label+","+$3.label+");\n"; 
			    }else{
			       	yyerror("Concatenação permitida apenas com strings");
			    }
			}
			|NUMEROS 
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
                $$.traducao = $2.traducao;
                $$.traducao += "\tgoto " + EscopoAtual->labelFim+";\n"; 
                $$.traducao += $2.label +":\n";
                $$.traducao += $3.traducao + "\n" + EscopoAtual->labelFim +":\n\n";
                fimEscopo();

            } 
            | INI_ESCOPO_IF IF {
                $$.traducao = $2.traducao + $2.label + ":\n//fim_if\n\n";
                fimEscopo();

            } 
            ;
IF          : TK_IF '(' RELACIONAL ')' BLOCO_IF {
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

            }
            | ELSE 
            ;

ELSE        : TK_ELIF '(' RELACIONAL ')' BLOCO_IF {

                
                $$.traducao = "\n//ini_elif\n" +$3.traducao;
                $$.traducao += "\n\tif (!("+ $3.label +")) goto " + EscopoAtual->labelFim +";"; 
                $$.traducao += "\n" + $5.traducao ;
                $$.traducao += "\ngoto " + EscopoAtual->escopoPai->labelFim +";\n"; 
                $$.traducao += "\n" + EscopoAtual->labelFim+":";
                fimEscopo();

            }
            | TK_ELSE BLOCO{

                $$.traducao = "\n//ini_else\n" +$2.traducao ;
                fimEscopo();
            } ;

SWITCHCASE  : SWITCH TK_ABRE INI_ESCOPO CASEs /*FIM_ESCOPO*/ TK_FECHA
            {

                $$.traducao = $1.traducao + $4.label;
                $$.traducao += "\ngoto "+EscopoAtual->labelFim +";\n\n";
                $$.traducao += $4.traducao;
                $$.traducao += "//fim_switch_case\n"+ EscopoAtual->labelFim +":\n\n";
                fimEscopo();


            }
            | SWITCH TK_ABRE INI_ESCOPO CASEs DEFAULT TK_FECHA
            {

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


            };

CASEs       : CASE CASEs 
            {

                $$.label = $1.label + $2.label;
                $$.traducao = $1.traducao + $2.traducao;

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

                fimEscopo();


            };

BREAK       : TK_BREAK  {

                Escopo *e = EscopoAtual->escopoPai;
                while(e->escopoPai != 0 && e->isCondicional){
                    e = e->escopoPai;
                }
                $$.traducao = "\tgoto "+e->labelFim + ";//break\n";

            };

CONTINUE    : TK_CONTINUE  {

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

        
CMD_CIN     : TK_READ '('TK_ID')'
            {
                 if($3.tipo == "string"){
                    $$.label = geraVarString(&$1, 1);
                    VarNode *a = getVar($3.traducao);
                    a->tamString = 1024;
                    
    			    $$.traducao = "\tcin >> " + $$.label  + " ;\n\tstrcpy (" + a->nomeTemp + "," + $$.label + ");\n";
                 }
                 else{
                     
                  $$.traducao = "\tcin >> " + getVar($3.traducao)->nomeTemp + " ;\n"; //getVar verifica se a variavel foi declarada
                 }
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

string geraVarString(atributos *a, int flagCin){
   // std::cout << a->tamString << std::endl;
    //strcpy(dest, src);
    int tamString;
    
    string var =("var" + to_string(nivel_escopo) +"_"+ to_string(varCount++) );
    if(flagCin == 1){ //Se a string veio de um cin 
        tamString = 1024;
    }
    else{
        tamString = a->traducao.length()-1; //Pega o tamanho da string menos 1;
    }
    
    //std::cout <<  tamString << std::endl;
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

// string AtribuicaoEntradaCin(string label1){
//     VarNode *a = getLabel(label1);
   
   
//     string var = "", rtn = "";
    
    
//     if(a->tipo == "string") //caso seja string é necessário utilizar o strcpy;
//     { 
//         geraVarSubrescritaString(a->nomeTemp, b->nomeTemp);
//         rtn += "\tstrcpy (" + a->nomeTemp + "," + b->nomeTemp  + ");\n";
//     }
//     else
//     {
//         rtn += "\t" + a->nomeTemp +" = " + b->nomeTemp  + ";\n";
//     }
         

//     }
//     return rtn;
// }

string geraVarSubrescritaString(string varA, string varB){
    VarNode *a = getLabel(varA);
    VarNode *b = getLabel(varB);
 
    int tamString = b->tamString; //Pega o tamanho da string menos 1;
     
    //std::cout << b->tamString << std::endl;
    //string var =("var" + to_string(nivel_escopo) +"_"+ to_string(varCount++) );
    //string varTamVetor = var + "[" + to_string(tamString) + "]";
    a->tamString = tamString;
    
    //a->nomeTemp = var;

    //VarNode *varnode = new VarNode(var, "string", "", tamString);

    //INCLUI EM BLOCO do ESCOPO atual
    //EscopoAtual->labelTable[var] = varnode;

    return "nada"; 
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
                    + (it->second->tamVetor > 0 ? "[" + to_string(it->second->tamVetor) + "]" : "") //verifica se é vetor, se for define o tamanho
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


void PegaDimensoesMatrizOriginal(string nomeTKid){ //pegar dimensões da matriz original e guarda no vector global dimensaoMatrizOriginal do ultimo elemento para o primeiro

    VarNode *a = getVar(nomeTKid);
    for (int i = a->dimensoes.size()-1 ; i >= 0; i--)
    {
        //index = $2.dimensao[i]-1 *  
        dimensaoMatrizOriginal.push_back(a->dimensoes[i]);
        //std::cout << "dimensoes " << a->dimensoes[i] << std::endl;
 	    //$1.dimensao.push_back($2.dimensao[i]);
    }
}


void PegaDimensaoIndexTemporario(atributos *a){
    //pegar dimensão do index da matriz que está sendo inserido
    for (int i = 0 ; i < a->dimensaoString.size(); i++)
    {
        string var = geraVar("int");
        
        //index = $2.dimensao[i]-1 *  
        //std::cout << "index " << a->dimensaoString[i] << std::endl;
        
        indexProcuradoMatriz.push_back(a->dimensaoString[i]);
        //$1.dimensao.push_back($2.dimensao[i]);
    }
}

// int CalculaIndexMatriz(){
//     int index = 0;
    
    
//     for (int i = 0 ; i < dimensaoMatrizOriginal.size()-1; i++){ //Faz o calculo da posição do index
//         std::cout << "index: " << indexProcuradoMatriz[i] << " coluna: " << dimensaoMatrizOriginal[i] << std::endl;
//         index += indexProcuradoMatriz[i]*dimensaoMatrizOriginal[i];
//         std::cout << "dim" << indexProcuradoMatriz[i]*dimensaoMatrizOriginal[i]  << std::endl;
//     }
//     index = index + indexProcuradoMatriz.back(); //Adiciona a coluna final ao calculo
//     std::cout <<  "indexProcuradoMatriz " << indexProcuradoMatriz.back() << std::endl;
    
    
//     std::cout << "Final " << index << std::endl;
    
//     return index;
// }

string CalculaIndexMatriz(){
    string var = geraVar("int");
    string index = "\t" + var + " = 0;\n";
    
    
    //std::cout << "var" << var << std::endl;
    
    for (int i = 0 ; i < dimensaoMatrizOriginal.size()-1; i++){ //Faz o calculo da posição do index
         //std::cout << "index: " << indexProcuradoMatriz[i] << " coluna: " << dimensaoMatrizOriginal[i] << std::endl;
         index += "\t" + var + " = "  + var +  " + " + indexProcuradoMatriz[i] + ";\n";
         index += "\t" + var + " = " + var + " * " + to_string(dimensaoMatrizOriginal[i]) + ";\n";
        
    //     std::cout << "dim" << indexProcuradoMatriz[i]*dimensaoMatrizOriginal[i]  << std::endl;
    }
     index +=  "\t" + var + " = " + var + " + " + indexProcuradoMatriz.back() + ";\n";; //Adiciona a coluna final ao calculo
     retornoTraducao = index;
     
    // std::cout << index << std::endl;
    // std::cout <<  "indexProcuradoMatriz " << indexProcuradoMatriz.back() << std::endl;
    // std::cout << "Final " << index << std::endl;
    
     return var;
}

void ResetMatriz(){
    dimensaoMatrizOriginal.clear();
    indexProcuradoMatriz.clear();
    retornoTraducao = "";
}