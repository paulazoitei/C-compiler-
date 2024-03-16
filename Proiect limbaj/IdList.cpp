#include "IdList.h"
#include <cstring>

using namespace std;

void IdList::addVar(const char *type, const char *name, bool c)
{
    IdInfo var = {string(type), string(name), c};
    vars.push_back(var);
}
void IdList::addVar(const char *type, const char *name, bool c, const char *value)
{
    IdInfo var = {string(type), string(name), c, string(value)};
    vars.push_back(var);
}
int IdList::getSize(const char *name)
{
    string strvar = string(name);
    for (const IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            return v.arrsize;
        }
    }
    return 0;
}
void IdList::populate(const char *name, int index, string value)
{
    string strvar = string(name);
    for (IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            v.valori[index] = value;
        }
    }
}
void IdList::addVar(const char *type, const char *name, bool c, int val)
{
    IdInfo var;
    var.type = string(type);
    var.name = string(name);
    var.arrsize = val;
    var.constant = c;

    vars.push_back(var);
}
bool IdList::isInt(const char *name)
{
    string strvar = string(name);

    for (const IdInfo &v : vars)
    {
        if (strvar == v.name && v.type == "int")
        {
            return true;
        }
    }
    return false;
}
bool IdList::isFloat(const char *name)
{
    string strvar = string(name);

    for (const IdInfo &v : vars)
    {
        if (strvar == v.name && v.type == "float")
        {
            return true;
        }
    }
    return false;
}
bool IdList::isBool(const char *name)
{
    string strvar = string(name);

    for (const IdInfo &v : vars)
    {
        if (strvar == v.name && v.type == "bool")
        {
            return true;
        }
    }
    return false;
}

bool IdList::haveSameType(const char *name, const char *name2)
{
    string strvar = string(name);
    string strvar2 = string(name2);
    for (const IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            for (const IdInfo &v2 : vars)
            {
                if (strvar2 == v2.name)
                {
                    if (v.type == v2.type)
                        return true;
                    else
                        return false;
                    break;
                }
            }
        }
    }
    return false;
}
bool IdList::haveSameTypeWithVar(const char *type, const char *name)
{
    string strtype = string(type);
    string strvar = string(name);
    for (const IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            if (strtype == v.type)
                return true;
        }
    }
    return false;
}

bool IdList::modifyValue(const char *name, string val)
{

    string strvar = string(name);
    if (isChar(name))
    {
        if (val[0] == '\'' && val[2] == '\'')
        {
            for (IdInfo &v : vars)
            {
                if (v.name == strvar)
                {
                    v.valoare = val;
                    return true;
                }
            }
        }
        else
            return false;
    }
    if (isInt(name))
    {
        if (stoi(val) == stof(val))
        {
            for (IdInfo &v : vars)
            {
                if (v.name == strvar)
                {
                    v.valoare = val;
                    return true;
                }
            }
        }
        else
            return false;
    }
    if (isBool(name))
    {
        if (val == "true" || val == "false")
        {
            for (IdInfo &v : vars)
            {
                if (v.name == strvar)
                {
                    v.valoare = val;
                    return true;
                }
            }
        }
        else
            return false;
    }
    if (isFloat(name))
    {
        if (stoi(val) == stof(val) || stof(val))
        {
            for (IdInfo &v : vars)
            {
                if (v.name == strvar)
                {
                    v.valoare = val;
                    return true;
                }
            }
        }
        else
            return false;
    }
    if (isString(name))
    {

        for (IdInfo &v : vars)
        {
            if (v.name == strvar)
            {
                v.valoare = val;
                return true;
            }
        }
        return false;
    }
    return false;
}
bool IdList::isChar(const char *name)
{
    string strvar = string(name);

    for (const IdInfo &v : vars)
    {
        if (strvar == v.name && v.type == "char")
        {
            return true;
        }
    }
    return false;
}
bool IdList::isString(const char *name)
{
    string strvar = string(name);

    for (const IdInfo &v : vars)
    {
        if (strvar == v.name && v.type == "string")
        {
            return true;
        }
    }
    return false;
}
bool IdList ::modifyValueByVar(const char *name, const char *name2)
{
    string valToCopy;
    string strvar = string(name);
    string strvar2 = string(name2);
    if (haveSameType(name, name2))
    {

        for (const IdInfo &v : vars)
        {
            if (strvar2 == v.name)
            {
                valToCopy = v.valoare;
            }
        }
        for (IdInfo &v : vars)
        {
            if (strvar == v.name)
            {
                v.valoare = valToCopy;
            }
        }
        return true;
    }
    else
        return false;
}
bool IdList::isConstant(const char *name)
{
    string strvar = string(name);

    for (const IdInfo &v : vars)
    {
        if (strvar == v.name && v.constant == true)
        {
            return true;
        }
    }
    return false;
}
string IdList::getValueIndex(const char *name, int index)
{
    string strvar = string(name);

    for (const IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            return v.valori[index];
        }
    }
    return 0;
}
float IdList::getValueFloat(const char *name)
{
    string strvar = string(name);

    for (const IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            return atof(v.valoare.c_str());
        }
    }
    return 0;
}
bool IdList::existsVar(const char *var, const char *domain)
{
    string strvar = string(var);
    string strdom = string(domain);
    for (const IdInfo &v : vars)
    {
        if (strvar == v.name && strdom == v.domain)
        {
            return true;
        }
    }
    return false;
}
bool IdList::existsVar(const char *var)
{
    string strvar = string(var);

    for (const IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            return true;
        }
    }
    return false;
}
string IdList::getType(const char *var)
{
    string strvar = string(var);

    for (const IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            return v.type;
        }
    }
    return NULL;
}
void IdList::addDomain(const char *name, const char *dom)
{
    string strvar = string(name);
    for (IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            v.domain = string(dom);
        }
    }
}
void IdList::addNewClass(const char *name)
{
    userTypes.push_back(string(name));
}

void IdList::printVars(char *buffer)
{

    strcat(buffer, "Variables:\n");
    for (const IdInfo &v : vars)
    {
        char line[100];
        sprintf(line, "domain: %s    name: %s     type: %s     constant %s   ", v.domain.c_str(), v.name.c_str(), v.type.c_str(), v.constant ? "true" : "false");
        strcat(buffer, line);
        if(v.arrsize==0)
        {
            char newline[50];
            sprintf(newline, " value:%s ", v.valoare.c_str());
            strcat(buffer,newline);
        }
        if (v.arrsize != 0)
        {
            strcat(buffer, " values: ");
            for (int i = 0; i < v.arrsize; i++)
            {
                char newline[100];
                if (v.valori[i] != "")
                {
                    sprintf(newline, "%d : %s;  ", i, v.valori[i].c_str());
                    strcat(buffer, newline);
                }
            }
        }

        strcat(buffer, "\n");
    }
    strcat(buffer, "\n");
}
void IdList::setIndex(const char *name, int i)
{
    string strvar = string(name);
    for (IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            v.index = i;
        }
    }
}
void IdList::setSize(const char *name, int sz)
{
    string strvar = string(name);
    for (IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            v.arrsize = sz;
        }
    }
}
int IdList::getIndex(const char *name)
{
    string strvar = string(name);
    for (IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            return v.index;
        }
    }
    return 0;
}
string IdList::getDomain(const char *name)
{
    string strvar = string(name);
    for (IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            return v.domain;
        }
    }
    return NULL;
}
IdList::~IdList()
{
    vars.clear();
}

string IdList::getValue(const char *nume)
{
    string strvar = string(nume);
    for (const IdInfo &v : vars)
    {
        if (v.name == strvar)
        {
            return v.valoare;
        }
    }
    return "";
}