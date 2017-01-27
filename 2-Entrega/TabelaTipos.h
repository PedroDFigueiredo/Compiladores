
#include <string>
#include <map>
#include <iostream>

using namespace std;

map<string, string> TabelaTipos;
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
void criaTabelaTipos();