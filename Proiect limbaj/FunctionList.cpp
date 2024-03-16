#include "FuntionList.h"
#include <cstring>


using namespace std;

void UserFunctions::printFuncs(char * buffer)
{
   
    strcat(buffer, "Functions:\n");
    for(const Function& f : funcs)
    {
        char line[100];
     
        sprintf(line, "domain: %s   name: %s   type: %s  params: ", f.domain.c_str() , f.name.c_str(), f.type.c_str());
        strcat(buffer,line);
        for(const Parameter& p : f.params)
        {
            char newline[100];
            sprintf(newline, "%s %s, ",p.type.c_str(), p.name.c_str());
            strcat(buffer,newline);
            
        }
        strcat(buffer, "\n");
    }
     strcat(buffer, "\n\n");
}
void UserFunctions::addDomain(const char*name, string domain)
{
    string strvar = string(name);
    for (Function& v : funcs) {
        if (strvar == v.name ) { 
            v.domain=domain;
        }
    }
    
}
string UserFunctions::getDomain(const char * name)
{
    string strvar = string(name);
    for (Function& v : funcs) {
        if (strvar == v.name ) { 
            return v.domain;
        }
    }
    return NULL;
}
void UserFunctions::addFunction(const char*type, const char*name , char*strToParse)
{
    Function newFunc;
    string strname=string(name);
    string strtype=string(type);
    char * p =strtok(strToParse, " ");
    newFunc.name=strname;
    newFunc.type=strtype;
    while(p)
    {
        Parameter par;
        string paramType=string(p);
        p=strtok(NULL, " ");
        string paramName=string(p);
        par.type=paramType;
        par.name=paramName;
        newFunc.params.push_back(par);
    
        p=strtok(NULL, " ");
    }
    funcs.push_back(newFunc);
}

bool UserFunctions::checkParam(const char* name, string param)
{
    vector<Parameter> par;
    string strname=string(name);
    for (const Function& v : funcs) {
        if (strname == v.name ) { 
            par=v.params;
        }
    }
    char parameters[100];
    int i=0;
    strcpy(parameters, param.c_str());
    char * p=strtok(parameters, " ");
    while(p)
    {
        if(strcmp(p,(par[i].type).c_str())!=0)
        {
            return false;
        }
        i++;
        p=strtok(NULL, " ");
    }
    if(i!=par.size())
    {
        return false;
    }
    return true;
}
void UserFunctions::addDomain(const char*name, const char*dom)
{
    string strvar = string(name);
    for (Function& v : funcs) {
        if (strvar == v.name ) { 
            v.domain=string(dom);
        }
    }
}
 string UserFunctions::getType(const char*name)
 {
    string strvar = string(name);
    for (const Function& v : funcs) {
        if (strvar == v.name ) { 
            return v.type;
        }
    }
   return NULL;
 }
int UserFunctions::numParam(const char* name)
{
   
    string strvar = string(name);
    for (const Function& v : funcs) {
        if (strvar == v.name ) { 
            return v.params.size();
        }
    }
   return 0;

}
bool UserFunctions::existFunction(const char* var) {
    string strvar = string(var);
  
     for (const Function& v : funcs) {
        if (strvar == v.name ) { 
            return true;
        }
    }
    return false;
}