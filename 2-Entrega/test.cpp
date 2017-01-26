#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iostream>
#include <cassert>
#include <string>
#include <sstream>

using namespace std;
class VarNode{
	public: 
		string varName;
		string type;
		VarNode(string , string);
};
VarNode::VarNode(string a, string b){
	varName = a;
	type = b;
};
std::string to_string(int i){
    std::stringstream ss;
    ss << i;
    return ss.str();
}
VarNode* getVar(string str){
	return new VarNode(str,  str);
}
int main(int argc, char **argv)
{

	VarNode *j = getVar("teste");
	cout<<j->varName<<" caraleo\n";
/*
	map<string, VarNode*> m;

	for (int i = 0; i < 5; ++i){
		
		VarNode *j = new VarNode("temp"+to_string(i), "tempad"+to_string(i));
		
		m["varName"+to_string(i)] = j;
		cout<<(j->varName)<<"::\n";
	}
	string v = "varName4";

	//cout<<m.find("varName3") !=m.end()<<"\n";
	if (m.find(v)!=m.end()){
		cout<<m["varName4"]->varName<<"\n";
	}*/
	/*
	cout<< m["varName"]

	// check if key is present
	if (m.find("world") != m.end())
	cout << "map contains key world!\n";
	// retrieve
	cout << m["hello"] << '\n';
	map<string, int>::iterator i = m.find("hello");
	assert(i != m.end());
	cout << "Key: " << i->first << " Value: " << i->second << '\n';*/
	return 0;
}
/*int main(int argc, char **argv)
{
  map<string, int> m;
  m["hello"] = 23;
  // check if key is present
  if (m.find("world") != m.end())
    cout << "map contains key world!\n";
  // retrieve
  cout << m["hello"] << '\n';
  map<string, int>::iterator i = m.find("hello");
  assert(i != m.end());
  cout << "Key: " << i->first << " Value: " << i->second << '\n';
  return 0;
}*/