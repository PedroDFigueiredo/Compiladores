%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*

SINAL ("+"|"-")?

INT {SINAL}{NUM}
FLOAT {SINAL}{REAL}



%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}


"int"		{return TK_TIPO_INT;}
"float"     {return TK_TIPO_FLOAT;}
"char"      {return TK_TIPO_CHAR;}
"bool"      {return TK_TIPO_BOOL;}

-------PalavrasReservadas
"true" 					{yylval.label = yytext; return TK_TRUE;}
"false" 				{yylval.label = yytext; return TK_FALSE;}


--------------------OPERADORES
--------Logicos
"||"					{yylval.label = yytext; return TK_OPER_OR;}
"&&"					{yylval.label = yytext; return TK_OPER_AND;}
"!"					{yylval.label = yytext; return TK_OPER_NOT;}

--------Relacionais
">"     {yylval.label = yytext; return TK_OPER_MAIOR;}
">="    {yylval.label = yytext; return TK_OPER_MAIOR_IGUAL;}
"<"     {yylval.label = yytext; return TK_OPER_MENOR;}
"<="    {yylval.label = yytext; return TK_OPER_MENOR_IGUAL;}
"=="    {yylval.label = yytext; return TK_OPER_IGUAL;}
"!="    {yylval.label = yytext; return TK_OPER_DIFERENTE;}
--------------------FIMOPEADORES----------


[(){}[\];,]	{ return *yytext; }

[>]

[+\-*/]		{ yylval.operador = yytext;   return OPERADOR; }
[=]         { return *yytext; }



{INT}		{ yylval.label = yytext;  yylval.tipo = "int"; return TK_INT; }
{FLOAT}		{ yylval.label = yytext;  yylval.tipo = "float"; return TK_REAL; }
{CHAR}		{ yylval.label = yytext;  yylval.tipo = "char"; return TK_CHAR; }
{ID}		{ yylval.label = yytext;  return TK_ID; }

.			{ *yytext; }

%%
