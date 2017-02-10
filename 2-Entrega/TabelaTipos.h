
#include <string>
#include <map>
#include <iostream>

using namespace std;

map<string, string> TabelaTipos;
void criaTabelaTipos(){ 
    
    //Tabela de Operação para soma
    TabelaTipos["int+bool"] = "ERRO";
    TabelaTipos["int+int"] = "int";
    TabelaTipos["int+float"] = "float";
    TabelaTipos["int+string"] = "string";
    TabelaTipos["int+char"] = "char"; //Verificar se será esse tipo mesmo para essa operação
    TabelaTipos["int+hex"] = "hex";
    
    TabelaTipos["float+bool"] = "ERRO";
    TabelaTipos["float+int"] = "float";
    TabelaTipos["float+float"] = "float";
    TabelaTipos["float+string"] = "string";
    TabelaTipos["float+char"] = "ERRO";
    TabelaTipos["float+hex"] = "ERRO";
    
    TabelaTipos["string+bool"] = "ERRO";
    TabelaTipos["string+int"] = "ERRO";
    TabelaTipos["string+float"] = "string";
    TabelaTipos["string+string"] = "string";
    TabelaTipos["string+char"] = "string";
    TabelaTipos["string+hex"] = "string";
    
    TabelaTipos["char+bool"] = "ERRO";
    TabelaTipos["char+int"] = "char";
    TabelaTipos["char+float"] = "ERRO";
    TabelaTipos["char+string"] = "string";
    TabelaTipos["char+char"] = "string";
    TabelaTipos["char+hex"] = "hex";
    
    TabelaTipos["bool+bool"] = "ERRO";
    TabelaTipos["bool+int"] = "ERRO";
    TabelaTipos["bool+float"] = "ERRO";
    TabelaTipos["bool+string"] = "ERRO";
    TabelaTipos["bool+char"] = "ERRO";
    TabelaTipos["bool+hex"] = "ERRO";
    
    TabelaTipos["hex+int"] = "hex";
    TabelaTipos["hex+float"] = "ERRO";
    TabelaTipos["hex+string"] = "string";
    TabelaTipos["hex+char"] = "hex";
    TabelaTipos["hex+hex"] = "hex";
    //---------------------------------------------------
    
    //Tabela de Operação para subtração   
    TabelaTipos["int-bool"] = "int";
    TabelaTipos["int-int"] = "int";
    TabelaTipos["int-float"] = "float";
    TabelaTipos["int-string"] = "string";
    TabelaTipos["int-char"] = "char";
    TabelaTipos["int-hex"] = "hex";
    
    TabelaTipos["float-bool"] = "int";
    TabelaTipos["float-int"] = "float";
    TabelaTipos["float-float"] = "float";
    TabelaTipos["float-string"] = "string";
    TabelaTipos["float-char"] = "ERRO";
    TabelaTipos["float-hex"] = "ERRO";
    
    TabelaTipos["float-bool"] = "int";
    TabelaTipos["string-int"] = "ERRO";
    TabelaTipos["string-float"] = "string";
    TabelaTipos["string-string"] = "string";
    TabelaTipos["string-char"] = "string";
    TabelaTipos["string-hex"] = "string";
    
    TabelaTipos["float-bool"] = "int";
    TabelaTipos["char-int"] = "char";
    TabelaTipos["char-float"] = "ERRO";
    TabelaTipos["char-string"] = "string";
    TabelaTipos["char-char"] = "string";
    TabelaTipos["char-hex"] = "hex";
    
    TabelaTipos["bool-bool"] = "ERRO";
    TabelaTipos["bool-int"] = "ERRO";
    TabelaTipos["bool-float"] = "ERRO";
    TabelaTipos["bool-string"] = "ERRO";
    TabelaTipos["bool-char"] = "ERRO";
    TabelaTipos["bool-hex"] = "ERRO";
    
    TabelaTipos["hex-int"] = "hex";
    TabelaTipos["hex-float"] = "ERRO";
    TabelaTipos["hex-string"] = "string";
    TabelaTipos["hex-char"] = "hex";
    TabelaTipos["hex-hex"] = "hex";
    
    
    //Tabela de Operação para multiplicação
    TabelaTipos["int*bool"] = "ERRO";
    TabelaTipos["int*int"] = "int";
    TabelaTipos["int*float"] = "float";
    TabelaTipos["int*string"] = "ERRO";
    TabelaTipos["int*char"] = "string"; //Verificar se será esse tipo mesmo para essa operação
    TabelaTipos["int*hex"] = "ERRO";
    
    TabelaTipos["float*bool"] = "ERRO";
    TabelaTipos["float*int"] = "float";
    TabelaTipos["float*float"] = "float";
    TabelaTipos["float*string"] = "ERRO";
    TabelaTipos["float*char"] = "ERRO";
    TabelaTipos["float*hex"] = "ERRO";
    
    TabelaTipos["string*bool"] = "ERRO";
    TabelaTipos["string*int"] = "string"; //Alterar isso depois para poder repetir a string n vezes
    TabelaTipos["string*float"] = "ERRO";
    TabelaTipos["string*string"] = "ERRO";
    TabelaTipos["string*char"] = "ERRO";
    TabelaTipos["string*hex"] = "ERRO";
    
    TabelaTipos["char*bool"] = "ERRO";
    TabelaTipos["char*int"] = "string"; 
    TabelaTipos["char*float"] = "ERRO";
    TabelaTipos["char*string"] = "ERRO";
    TabelaTipos["char*char"] = "ERRO";
    TabelaTipos["char*hex"] = "ERRO";
    
    TabelaTipos["bool*bool"] = "ERRO";
    TabelaTipos["bool*int"] = "ERRO";
    TabelaTipos["bool*float"] = "ERRO";
    TabelaTipos["bool*string"] = "ERRO";
    TabelaTipos["bool*char"] = "ERRO";
    TabelaTipos["bool*hex"] = "ERRO";
    
    TabelaTipos["hex*int"] = "ERRO";
    TabelaTipos["hex*float"] = "ERRO";
    TabelaTipos["hex*string"] = "ERRO";
    TabelaTipos["hex*char"] = "ERRO";
    TabelaTipos["hex*hex"] = "hex";
    
    
    //Tabela de Operação para divisão
    TabelaTipos["int/bool"] = "int";
    TabelaTipos["int/int"] = "int";
    TabelaTipos["int/float"] = "float";
    TabelaTipos["int/string"] = "ERRO";
    TabelaTipos["int/char"] = "ERRO"; //Verificar se será esse tipo mesmo para essa operação
    TabelaTipos["int/hex"] = "ERRO";
    
    TabelaTipos["float/bool"] = "int";
    TabelaTipos["float/int"] = "float";
    TabelaTipos["float/float"] = "float";
    TabelaTipos["float/string"] = "ERRO";
    TabelaTipos["float/char"] = "ERRO";
    TabelaTipos["float/hex"] = "ERRO";
    
    TabelaTipos["string/bool"] = "int";
    TabelaTipos["string/int"] = "ERRO";
    TabelaTipos["string/float"] = "ERRO";
    TabelaTipos["string/string"] = "ERRO";
    TabelaTipos["string/char"] = "ERRO";
    TabelaTipos["string/hex"] = "ERRO";
    
    TabelaTipos["char/bool"] = "int";
    TabelaTipos["char/int"] = "ERRO";
    TabelaTipos["char/float"] = "ERRO";
    TabelaTipos["char/string"] = "ERRO";
    TabelaTipos["char/char"] = "ERRO";
    TabelaTipos["char/hex"] = "ERRO";
    
    TabelaTipos["bool/bool"] = "ERRO";
    TabelaTipos["bool/int"] = "ERRO";
    TabelaTipos["bool/float"] = "ERRO";
    TabelaTipos["bool/string"] = "ERRO";
    TabelaTipos["bool/char"] = "ERRO"; //Verificar se será esse tipo mesmo para essa operação
    TabelaTipos["bool/hex"] = "ERRO";
    
    TabelaTipos["hex/int"] = "ERRO";
    TabelaTipos["hex/float"] = "ERRO";
    TabelaTipos["hex/string"] = "ERRO";
    TabelaTipos["hex/char"] = "ERRO";
    TabelaTipos["hex/hex"] = "ERRO";
    
    
    //Atribuição
    TabelaTipos["int=bool"] = "ERRO";
    TabelaTipos["int=int"] = "int";
    TabelaTipos["int=float"] = "int";
    TabelaTipos["int=string"] = "ERRO";
    TabelaTipos["int=char"] = "ERRO";
    TabelaTipos["int=hex"] = "int";
    
    TabelaTipos["float=bool"] = "ERRO";
    TabelaTipos["float=int"] = "float";
    TabelaTipos["float=float"] = "float";
    TabelaTipos["float=string"] = "ERRO";
    TabelaTipos["float=char"] = "ERRO";
    TabelaTipos["float=hex"] = "ERRO";
    
    TabelaTipos["string=bool"] = "ERRO";
    TabelaTipos["string=int"] = "ERRO";
    TabelaTipos["string=float"] = "string";
    TabelaTipos["string=string"] = "string";
    TabelaTipos["string=char"] = "string";
    TabelaTipos["string=hex"] = "string";
    
    TabelaTipos["char=bool"] = "ERRO";
    TabelaTipos["char=int"] = "char";
    TabelaTipos["char=float"] = "ERRO";
    TabelaTipos["char=string"] = "ERRO";
    TabelaTipos["char=char"] = "char";
    TabelaTipos["char=hex"] = "char";
    
    TabelaTipos["bool=bool"] = "bool";
    TabelaTipos["bool=int"] = "ERRO";
    TabelaTipos["bool=float"] = "ERRO";
    TabelaTipos["bool=string"] = "ERRO";
    TabelaTipos["bool=char"] = "ERRO";
    TabelaTipos["bool=hex"] = "ERRO";
    
    TabelaTipos["hex=int"] = "hex";
    TabelaTipos["hex=float"] = "hex";
    TabelaTipos["hex=string"] = "ERRO";
    TabelaTipos["hex=char"] = "ERRO";
    TabelaTipos["hex=hex"] = "hex";
    
    
    
    //Relacionais
    
    //Maior
    TabelaTipos["int>bool"] = "bool";
    TabelaTipos["int>int"] = "bool";
    TabelaTipos["int>float"] = "bool";
    TabelaTipos["int>string"] = "ERRO";
    TabelaTipos["int>char"] = "ERRO"; 
    
    TabelaTipos["float>bool"] = "bool";
    TabelaTipos["float>int"] = "bool";
    TabelaTipos["float>float"] = "bool";
    TabelaTipos["float>string"] = "ERRO";
    TabelaTipos["float>char"] = "ERRO";
    
    TabelaTipos["string>bool"] = "ERRO";
    TabelaTipos["string>int"] = "ERRO";
    TabelaTipos["string>float"] = "ERRO";
    TabelaTipos["string>string"] = "ERRO";
    TabelaTipos["string>char"] = "ERRO";
    
    TabelaTipos["char>bool"] = "ERRO";
    TabelaTipos["char>int"] = "ERRO";
    TabelaTipos["char>float"] = "ERRO";
    TabelaTipos["char>string"] = "ERRO";
    TabelaTipos["char>char"] = "ERRO";
    
    TabelaTipos["bool>bool"] = "ERRO";
    TabelaTipos["bool>int"] = "ERRO";
    TabelaTipos["bool>float"] = "ERRO";
    TabelaTipos["bool>string"] = "ERRO";
    TabelaTipos["bool>char"] = "ERRO";
    
    
    //Maior igual
    TabelaTipos["int>=bool"] = "bool";
    TabelaTipos["int>=int"] = "bool";
    TabelaTipos["int>=float"] = "bool";
    TabelaTipos["int>=string"] = "ERRO";
    TabelaTipos["int>=char"] = "ERRO"; 
    
    TabelaTipos["float>=bool"] = "bool";
    TabelaTipos["float>=int"] = "bool";
    TabelaTipos["float>=float"] = "bool";
    TabelaTipos["float>=string"] = "ERRO";
    TabelaTipos["float>=char"] = "ERRO";
    
    TabelaTipos["string>=bool"] = "bool";
    TabelaTipos["string>=int"] = "ERRO";
    TabelaTipos["string>=float"] = "ERRO";
    TabelaTipos["string>=string"] = "ERRO";
    TabelaTipos["string>=char"] = "ERRO";
    
    TabelaTipos["char>=bool"] = "ERRO";
    TabelaTipos["char>=int"] = "ERRO";
    TabelaTipos["char>=float"] = "ERRO";
    TabelaTipos["char>=string"] = "ERRO";
    TabelaTipos["char>=char"] = "ERRO";
    
    TabelaTipos["bool>=bool"] = "bool";
    TabelaTipos["bool>=int"] = "bool";
    TabelaTipos["bool>=float"] = "bool ";
    TabelaTipos["bool>=string"] = "ERRO";
    TabelaTipos["bool>=char"] = "ERRO";
    
    
    //menor
    TabelaTipos["int<bool"] = "bool";
    TabelaTipos["int<int"] = "bool";
    TabelaTipos["int<float"] = "bool";
    TabelaTipos["int<string"] = "ERRO";
    TabelaTipos["int<char"] = "ERRO"; 
    
    TabelaTipos["float<bool"] = "bool";
    TabelaTipos["float<int"] = "bool";
    TabelaTipos["float<float"] = "bool";
    TabelaTipos["float<string"] = "ERRO";
    TabelaTipos["float<char"] = "ERRO";
    
    TabelaTipos["string<bool"] = "ERRO";
    TabelaTipos["string<int"] = "ERRO";
    TabelaTipos["string<float"] = "ERRO";
    TabelaTipos["string<string"] = "ERRO";
    TabelaTipos["string<char"] = "ERRO";
    
    TabelaTipos["char<bool"] = "ERRO";
    TabelaTipos["char<int"] = "ERRO";
    TabelaTipos["char<float"] = "ERRO";
    TabelaTipos["char<string"] = "ERRO";
    TabelaTipos["char<char"] = "ERRO";
    
    TabelaTipos["bool<bool"] = "bool";
    TabelaTipos["bool<int"] = "bool";
    TabelaTipos["bool<float"] = "bool";
    TabelaTipos["bool<string"] = "ERRO";
    TabelaTipos["bool<char"] = "ERRO";
    
    //Menor Igual
    TabelaTipos["int=<bool"] = "bool";
    TabelaTipos["int=<int"] = "bool";
    TabelaTipos["int=<float"] = "bool";
    TabelaTipos["int=<string"] = "ERRO";
    TabelaTipos["int=<char"] = "ERRO"; 
    
    TabelaTipos["float=<bool"] = "bool";
    TabelaTipos["float=<int"] = "bool";
    TabelaTipos["float=<float"] = "bool";
    TabelaTipos["float=<string"] = "ERRO";
    TabelaTipos["float=<char"] = "ERRO";
    
    TabelaTipos["string=<bool"] = "ERRO";
    TabelaTipos["string=<int"] = "ERRO";
    TabelaTipos["string=<float"] = "ERRO";
    TabelaTipos["string=<string"] = "ERRO";
    TabelaTipos["string=<char"] = "ERRO";
    
    TabelaTipos["char=<bool"] = "ERRO";
    TabelaTipos["char=<int"] = "ERRO";
    TabelaTipos["char=<float"] = "ERRO";
    TabelaTipos["char=<string"] = "ERRO";
    TabelaTipos["char=<char"] = "ERRO";
    
    TabelaTipos["bool=<bool"] = "bool";
    TabelaTipos["bool=<int"] = "bool";
    TabelaTipos["bool=<float"] = "bool";
    TabelaTipos["bool=<string"] = "ERRO";
    TabelaTipos["bool=<char"] = "ERRO";
    
    
    //igual
    TabelaTipos["int==bool"] = "bool";
    TabelaTipos["int==int"] = "bool";
    TabelaTipos["int==float"] = "bool";
    TabelaTipos["int==string"] = "ERRO";
    TabelaTipos["int==char"] = "ERRO"; 
    
    TabelaTipos["float==bool"] = "bool";
    TabelaTipos["float==int"] = "bool";
    TabelaTipos["float==float"] = "bool";
    TabelaTipos["float==string"] = "ERRO";
    TabelaTipos["float==char"] = "ERRO";
    
    TabelaTipos["string==bool"] = "ERRO";
    TabelaTipos["string==int"] = "ERRO";
    TabelaTipos["string==float"] = "ERRO";
    TabelaTipos["string==string"] = "ERRO";
    TabelaTipos["string==char"] = "ERRO";
    
    TabelaTipos["char==bool"] = "ERRO";
    TabelaTipos["char==int"] = "ERRO";
    TabelaTipos["char==float"] = "ERRO";
    TabelaTipos["char==string"] = "ERRO";
    TabelaTipos["char==char"] = "ERRO";
    
    TabelaTipos["bool==bool"] = "bool";
    TabelaTipos["bool==int"] = "ERRO";
    TabelaTipos["bool==float"] = "ERRO";
    TabelaTipos["bool==string"] = "ERRO";
    TabelaTipos["bool==char"] = "ERRO";
    
    //diferente
    TabelaTipos["int!=bool"] = "bool";
    TabelaTipos["int!=int"] = "bool";
    TabelaTipos["int!=float"] = "bool";
    TabelaTipos["int!=string"] = "ERRO";
    TabelaTipos["int!=char"] = "ERRO"; 
    
    TabelaTipos["float!=bool"] = "bool";
    TabelaTipos["float!=int"] = "bool";
    TabelaTipos["float!=float"] = "bool";
    TabelaTipos["float!=string"] = "ERRO";
    TabelaTipos["float!=char"] = "ERRO";
    
    TabelaTipos["string!=bool"] = "ERRO";
    TabelaTipos["string!=int"] = "ERRO";
    TabelaTipos["string!=float"] = "ERRO";
    TabelaTipos["string!=string"] = "ERRO";
    TabelaTipos["string!=char"] = "ERRO";
    
    TabelaTipos["char!=bool"] = "ERRO";
    TabelaTipos["char!=int"] = "ERRO";
    TabelaTipos["char!=float"] = "ERRO";
    TabelaTipos["char!=string"] = "ERRO";
    TabelaTipos["char!=char"] = "ERRO";
    
    TabelaTipos["bool!=bool"] = "bool";
    TabelaTipos["bool!=int"] = "bool";
    TabelaTipos["bool!=float"] = "bool";
    TabelaTipos["bool!=string"] = "ERRO";
    TabelaTipos["bool!=char"] = "ERRO";
    
    
    //Logicos
    TabelaTipos["intorbool"] = "bool";
    TabelaTipos["intorint"] = "bool";
    TabelaTipos["intorfloat"] = "bool";
    TabelaTipos["intorstring"] = "ERRO";
    TabelaTipos["intorchar"] = "ERRO"; 
    
    TabelaTipos["floatorbool"] = "bool";
    TabelaTipos["floatorint"] = "bool";
    TabelaTipos["floatorfloat"] = "bool";
    TabelaTipos["floatorstring"] = "ERRO";
    TabelaTipos["floatorchar"] = "ERRO";
    
    TabelaTipos["stringorbool"] = "ERRO";
    TabelaTipos["stringorint"] = "ERRO";
    TabelaTipos["stringorfloat"] = "ERRO";
    TabelaTipos["stringorstring"] = "ERRO";
    TabelaTipos["stringorchar"] = "ERRO";
    
    TabelaTipos["charorbool"] = "ERRO";
    TabelaTipos["charorint"] = "ERRO";
    TabelaTipos["charorfloat"] = "ERRO";
    TabelaTipos["charorstring"] = "ERRO";
    TabelaTipos["charorchar"] = "ERRO";
    
    TabelaTipos["boolorbool"] = "bool";
    TabelaTipos["boolorint"] = "ERRO";
    TabelaTipos["boolorfloat"] = "ERRO";
    TabelaTipos["boolorstring"] = "ERRO";
    TabelaTipos["boolorchar"] = "ERRO";
    
    //diferente
    TabelaTipos["int!=bool"] = "bool";
    TabelaTipos["int!=int"] = "bool";
    TabelaTipos["int!=float"] = "bool";
    TabelaTipos["int!=string"] = "ERRO";
    TabelaTipos["int!=char"] = "ERRO"; 
    
    TabelaTipos["float!=bool"] = "bool";
    TabelaTipos["float!=int"] = "bool";
    TabelaTipos["float!=float"] = "bool";
    TabelaTipos["float!=string"] = "ERRO";
    TabelaTipos["float!=char"] = "ERRO";
    
    TabelaTipos["string!=bool"] = "ERRO";
    TabelaTipos["string!=int"] = "ERRO";
    TabelaTipos["string!=float"] = "ERRO";
    TabelaTipos["string!=string"] = "ERRO";
    TabelaTipos["string!=char"] = "ERRO";
    
    TabelaTipos["char!=bool"] = "ERRO";
    TabelaTipos["char!=int"] = "ERRO";
    TabelaTipos["char!=float"] = "ERRO";
    TabelaTipos["char!=string"] = "ERRO";
    TabelaTipos["char!=char"] = "ERRO";
    
    TabelaTipos["bool!=bool"] = "bool";
    TabelaTipos["bool!=int"] = "bool";
    TabelaTipos["bool!=float"] = "bool";
    TabelaTipos["bool!=string"] = "ERRO";
    TabelaTipos["bool!=char"] = "ERRO";
    


}
void criaTabelaTipos();