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


[(){}[\];,]	{ return *yytext; }

[+\-*/]		{ yylval.operador = yytext;   return OPERADOR; }
[=]         { return *yytext; }



{INT}		{ yylval.label = yytext;  yylval.tipo = "int"; return TK_INT; }
{FLOAT}		{ yylval.label = yytext;  yylval.tipo = "float"; return TK_REAL; }
{CHAR}		{ yylval.label = yytext;  yylval.tipo = "char"; return TK_CHAR; }
{ID}		{ yylval.label = yytext;  return TK_ID; }

.			{ *yytext; }

%%
