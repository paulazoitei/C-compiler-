#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct IdInfo {
    string type;
    string name;
    bool constant;
    string valoare;
    string valori[1000];
    int index;
    int arrsize;
    string domain;
};

class IdList {
    vector<IdInfo> vars;
    vector<string> userTypes;
    public:
    void addDomain(const char*name, const char*dom);
    void populate(const char*name, int index, string value);
    void addVar(const char* type, const char*name, bool c, const char*value);
    bool existsVar(const char* t, const char* dom);
    bool existsVar(const char* t);
    int getSize(const char*name);
    string getValueIndex(const char*nume, int index);
    void addNewClass(const char*name);
    void addVar(const char * type, const char* name , bool c);
    void addVar(const char * type, const char* name , bool c, int size);
    bool isConstant(const char* name);
    void addValue(const char* value, const char*name);
    string getType(const char*name);
    bool isInt(const char* name);
    bool isChar(const char* name);
    string getDomain(const char * name);
    bool isBool(const char* name);
    bool isFloat(const char* name);
    float getValueFloat(const char *name);
    string getValue(const char*nume);
    bool isString(const char* name);
    bool haveSameType(const char* name, const char* name2);
    bool haveSameTypeWithVar(const char* type, const char* name);
    bool modifyValue(const char*name, string val);
    bool modifyValueByVar(const char*name, const char*name2);
    void printVars(char * buffer);
    void setIndex(const char* name, int i);
    int getIndex(const char* name);
    void setSize(const char* name, int sz);
    ~IdList();
};






