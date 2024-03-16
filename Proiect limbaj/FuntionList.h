#include <string>
#include <vector>
using namespace std;

struct Parameter
{
    string type;
    string name;
};

struct Function
{
    string type;
    string name;
    vector<Parameter> params;
    string domain;
};

class UserFunctions
{
    vector<Function> funcs;
    public:
    void addFunction(const char*, const char*, char*);
    bool existFunction(const char* name);
    void printFuncs(char * buffer);
    void addDomain(const char*name, const char*dom);
    int numParam(const char *name);
    bool checkParam(const char* name, string param);
    void addDomain(const char*name, string domain);
    string getDomain(const char * name);
     string getType(const char*name);
};