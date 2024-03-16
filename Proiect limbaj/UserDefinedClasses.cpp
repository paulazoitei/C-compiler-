#include "UserDefinedClasses.h"

void UserDefinedClasses::addNewClass(const char* name)
{
    UserDefinedClassInfo newClass;
    newClass.name=string(name);
    clsinfo.push_back(newClass);
}

bool UserDefinedClasses::existsClass(const char* name)
{
    string strvar = string(name);
  
     for (const UserDefinedClassInfo& v : clsinfo) {
        if (strvar == v.name ) { 
            return true;
        }
    }
    return false;
}


 void  UserDefinedClasses::setSize(const char* name, int sz)
 {
    string strvar = string(name);
    for (UserDefinedClassInfo &v : clsinfo)
    {
        if (strvar == v.name)
        {
            v.size=sz;
        }
    }
 }

  int UserDefinedClasses::getSize(const char* name)
 {
    string strvar = string(name);
    for (UserDefinedClassInfo &v : clsinfo)
    {
        if (strvar == v.name)
        {
            return v.size;
        }
    }
        return 0;
 }