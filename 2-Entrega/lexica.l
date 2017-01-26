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
"defaut"						{return TK_DEFAUT; }

"main"							{return TK_MAIN;}

"int" 							{yylval.tipo = "int"; return TK_TIPO_INT; }
"float" 						{yylval.tipo = "float"; return TK_TIPO_FLOAT;}
"char"       					{yylval.tipo = "char"; return TK_TIPO_CHAR;}
"string"						{yylval.tipo = "char"; return TK_TIPO_STRING; }
"bool"       					{yylval.tipo = "int"; return TK_TIPO_BOOL;}

"while" 						{return TK_WHILE; }
"for" 							{return TK_FOR; }
"do"							{return TK_DO; }
"continue"						{return TK_CONTINUE; }
"break"							{return TK_BREAK; }

"if"							{return TK_IF; }
"else" 							{return TK_ELSE; }
"elif"							{return TK_ELIF; }

"func"							{return TK_FUNC;}
"->"							{return TK_RETORNA;}
"return"						{return TK_RETURN;}

"var"							{return TK_VAR;}
"global"						{return TK_GLOBAL;}

"read"							{return TK_READ;}
"write"							{return TK_WRITE;}

"super"							{return TK_SUPER;}

[=] 							{return TK_ATRIB;}

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


[(){}[\];,]	{return *yytext; }
[+\-*/]		{return *yytext; }

{INT}		{yylval.traducao = yytext; yylval.tipo = "int"; return TK_INT; }
{FLOAT}		{yylval.traducao = yytext; yylval.tipo = "float"; return TK_FLOAT; }
{CHAR}		{yylval.traducao = yytext; yylval.tipo = "char"; return TK_CHAR; }
{BOOL}		{yylval.traducao = yytext; yylval.tipo = "int"; return TK_BOOL; } 
{STRING} 	{yylval.traducao = yytext; yylval.tipo = "char";  return TK_STR; }
{TK_ID}		{yylval.label = yytext; return TK_ID; }



.			{*yytext; }

%%
