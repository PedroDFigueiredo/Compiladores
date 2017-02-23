/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_MAIS = 258,
    TK_MENOS = 259,
    TK_MULT = 260,
    TK_RAZAO = 261,
    TK_POTENCIA = 262,
    TK_CONCAT = 263,
    TK_AND = 264,
    TK_OR = 265,
    TK_MAIOR = 266,
    TK_MENOR = 267,
    TK_DIFERENTE = 268,
    TK_IGUAL = 269,
    TK_MAIOR_IGUAL = 270,
    TK_MENOR_IGUAL = 271,
    TK_ATRIBUICAO = 272,
    TK_VAR = 273,
    TK_GLOBAL = 274,
    TK_TIPO_STRING = 275,
    TK_TIPO_FLOAT = 276,
    TK_TIPO_CHAR = 277,
    TK_TIPO_BOOL = 278,
    TK_TIPO_INT = 279,
    TK_INT = 280,
    TK_FLOAT = 281,
    TK_CHAR = 282,
    TK_BOOL = 283,
    TK_STRING = 284,
    TK_WHILE = 285,
    TK_FOR = 286,
    TK_SWITCH = 287,
    TK_CASE = 288,
    TK_IF = 289,
    TK_ELSE = 290,
    TK_ELIF = 291,
    TK_BREAK = 292,
    TK_CONTINUE = 293,
    TK_DO = 294,
    TK_DEFAULT = 295,
    TK_ABRE = 296,
    TK_FECHA = 297,
    TK_FUNC = 298,
    TK_RETORNA = 299,
    TK_RETURN = 300,
    TK_READ = 301,
    TK_WRITE = 302,
    TK_SUPER = 303,
    TK_MAIN = 304,
    TK_ID = 305,
    TK_FIM = 306,
    TK_ERROR = 307,
    TK_END_E = 308,
    TK_FIMLINHA = 309,
    TK_DIVISAO = 310
  };
#endif
/* Tokens.  */
#define TK_MAIS 258
#define TK_MENOS 259
#define TK_MULT 260
#define TK_RAZAO 261
#define TK_POTENCIA 262
#define TK_CONCAT 263
#define TK_AND 264
#define TK_OR 265
#define TK_MAIOR 266
#define TK_MENOR 267
#define TK_DIFERENTE 268
#define TK_IGUAL 269
#define TK_MAIOR_IGUAL 270
#define TK_MENOR_IGUAL 271
#define TK_ATRIBUICAO 272
#define TK_VAR 273
#define TK_GLOBAL 274
#define TK_TIPO_STRING 275
#define TK_TIPO_FLOAT 276
#define TK_TIPO_CHAR 277
#define TK_TIPO_BOOL 278
#define TK_TIPO_INT 279
#define TK_INT 280
#define TK_FLOAT 281
#define TK_CHAR 282
#define TK_BOOL 283
#define TK_STRING 284
#define TK_WHILE 285
#define TK_FOR 286
#define TK_SWITCH 287
#define TK_CASE 288
#define TK_IF 289
#define TK_ELSE 290
#define TK_ELIF 291
#define TK_BREAK 292
#define TK_CONTINUE 293
#define TK_DO 294
#define TK_DEFAULT 295
#define TK_ABRE 296
#define TK_FECHA 297
#define TK_FUNC 298
#define TK_RETORNA 299
#define TK_RETURN 300
#define TK_READ 301
#define TK_WRITE 302
#define TK_SUPER 303
#define TK_MAIN 304
#define TK_ID 305
#define TK_FIM 306
#define TK_ERROR 307
#define TK_END_E 308
#define TK_FIMLINHA 309
#define TK_DIVISAO 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
