%{
#include <string>

%}


ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]



DELIM {ESPACO}+
INT {DIGITO}+
FLOAT {INT}+("."{INT}+)?
CHAR \'({LETRA}|{INT})\'
STRING \"(\\.|[^"])*\"

TK_ID {LETRA}({LETRA}|{INT})*
BOOL "true"|"false"



%%

"switch" 						{return TK_SWITCH; }
"case" 							{return TK_CASE; }
"default"						{return TK_DEFAULT; }

"main"							{return TK_MAIN;}

"int" 							{yylval.tipo = "int"; return TK_TIPO_INT; }
"float" 						{yylval.tipo = "float"; return TK_TIPO_FLOAT;}
"char"       					{yylval.tipo = "char"; return TK_TIPO_CHAR;}
"string"						{yylval.tipo = "string"; return TK_TIPO_STRING; }
"bool"       					{yylval.tipo = "bool"; return TK_TIPO_BOOL;}

"while" 						{yylval.traducao = yytext; return TK_WHILE; }
"for" 							{yylval.traducao = yytext; return TK_FOR; }
"do"							{yylval.traducao = yytext; return TK_DO; }
"continue"						{yylval.traducao = yytext; return TK_CONTINUE; }
"break"							{yylval.traducao = yytext; return TK_BREAK; }

"if"							{yylval.traducao = yytext; return TK_IF; }
"else" 							{yylval.traducao = yytext; return TK_ELSE; }
"elif"							{yylval.traducao = yytext; return TK_ELIF; }

"func"							{yylval.traducao = yytext; return TK_FUNC;}
"->"							{yylval.traducao = yytext; return TK_RETORNA;}
"return"						{yylval.traducao = yytext; return TK_RETURN;}

"var"							{yylval.traducao = yytext; return TK_VAR;}
"global"						{yylval.traducao = yytext; return TK_GLOBAL;}

"read"							{yylval.traducao = yytext; return TK_READ;}
"write"							{yylval.traducao = yytext; return TK_WRITE;}

"super"							{yylval.traducao = yytext; return TK_SUPER;}

[=] 							{yylval.traducao = yytext; return TK_ATRIBUICAO;}

[<] 							{yylval.traducao = yytext; return TK_MENOR;}
[>] 							{yylval.traducao = yytext; return TK_MAIOR;}
"!="							{yylval.traducao = yytext; return TK_DIFERENTE; }
"=="							{yylval.traducao = yytext; return TK_IGUAL; }

"and" 							{yylval.traducao = yytext; return TK_AND;}
"or" 							{yylval.traducao = yytext; return TK_OR;}


[+] 							{yylval.traducao = yytext; return TK_MAIS;}
[-] 							{yylval.traducao = yytext; return TK_MENOS;}
[*] 							{yylval.traducao = yytext; return TK_MULT;}
[/] 							{yylval.traducao = yytext; return TK_DIVISAO;}

"\.\."							{ yylval.traducao = yytext;return TK_CONCAT;}

[{]								{return TK_ABRE; }
[}]								{return TK_FECHA; }




{DELIM} 	{}


[(){}[\];,:]	{return *yytext; }
[+\-*/]		{return *yytext; }

{INT}		{yylval.traducao = yytext; yylval.tipo = "int"; return TK_INT; }
{FLOAT}		{yylval.traducao = yytext; yylval.tipo = "float"; return TK_FLOAT; }
{CHAR}		{yylval.traducao = yytext; yylval.tipo = "char"; return TK_CHAR; }
{BOOL}		{yylval.traducao = yytext; yylval.tipo = "bool"; return TK_BOOL; } 
{STRING} 	{yylval.traducao = yytext; yylval.tipo = "string";  return TK_STRING; }
{TK_ID}		{yylval.traducao = yytext; return TK_ID; }



.			{*yytext; }

%%
