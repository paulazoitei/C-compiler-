#include "IdList.h"
#include "FuntionList.h"
using namespace std;

struct UserDefinedClassInfo
{
    string name;
    UserFunctions funcs;
    int size;
};
class UserDefinedClasses
{
    vector<UserDefinedClassInfo> clsinfo;
    
    public:
    void addNewClass(const char* name);
    string getClass(const char* var);
     void setSize(const char* name, int sz);
    bool existsClass(const char* name);
     int getSize(const char* name);
};