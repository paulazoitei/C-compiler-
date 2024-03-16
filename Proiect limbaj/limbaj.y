%{
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <unistd.h>
#include "UserDefinedClasses.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
using namespace std;
ofstream fout("symboltable");
void yyerror(const char * s);
int ind=0;
int isClass=0;
char buffer[5000];
char domain[50]="global";
char aux[50]="global";
class IdList ids;
class UserDefinedClasses cls;
class UserFunctions fnc;
%}
%union {
     char* string;
     int integerValue;
     float floatValue; 
     bool boolValue;
}
%token  BGIN END ASSIGN FLOAT_NR NR BOOL_TRUE BOOL_FALSE CHARACTER ID TYPE
%token<string>  STRING_TYPE STRING_TEXT CLASS BOOL_TYPE ENTRY_POINT LOGIC_OR LOGIC_AND CHAR_TYPE
IF_START WHILE_START FOR_START DEC INC DO ELSE CONST EVAL BOOL_LT BOOL_LTE BOOL_GT BOOL_GTE BOOL_E BOOL_NE TYPEOF
%start progr
%left DEC INC
%left '+' '-' 
%left '*' '/'
%type <string> call_list
%type <string> param
%type <string> ID
%type <string> TYPE
%type <string> list_param_inner
%type <string> idVar 
%type <floatValue> onlyExp
%type <string> CHARACTER
%type <floatValue> NR 
%type <floatValue> FLOAT_NR
%type <floatValue> e
%type <floatValue> evalAritFunc
%type <boolValue> bExpForm
%type <boolValue> bExp
%type <boolValue> BOOL_FALSE
%type <boolValue> BOOL_TRUE
%type <floatValue> evalAritFuncFT
%type <floatValue> evalForType
%%

progr: userDefinedDeclarations declarations functions TYPE ENTRY_POINT '(' ')' {strcpy(domain,"main");}block {printf("End\n"); }
     | userDefinedDeclarations functions TYPE ENTRY_POINT '(' ')'  {strcpy(domain,"main");} block {printf("End\n");}
     | userDefinedDeclarations declarations TYPE ENTRY_POINT '(' ')' {strcpy(domain,"main");} block {printf("End\n");}
     | userDefinedDeclarations TYPE ENTRY_POINT '(' ')'{strcpy(domain,"main");} block {printf("End\n");}
     | declarations TYPE ENTRY_POINT '(' ')' {strcpy(domain,"main");}  block {printf("End\n");}
     | declarations functions TYPE ENTRY_POINT '(' ')' {strcpy(domain,"main");} block {printf("End\n");}
     | functions TYPE ENTRY_POINT '(' ')'{strcpy(domain,"main");}   block {printf("End\n");}
     | TYPE ENTRY_POINT '(' ')'{strcpy(domain,"main");}  block {printf("End\n");}
      ; 

typeoffunc : TYPEOF evalAritFuncFT {cout <<"Arithmetic expression"; if($2==(int)$2)cout<<" of type int"<<endl; else cout<<" of type float"<<endl;}
           | TYPEOF '(' bExp ')' {cout <<"boolean"<<endl;}
           | TYPEOF '(' CHARACTER ')' {cout <<"char"<<endl;}
           | TYPEOF '(' STRING_TEXT ')' {cout <<"string"<<endl;}
           | TYPEOF '(' ID ')' {if(!ids.existsVar($3))yyerror("variable does not exist");
                                   cout<<ids.getType($3)<<endl;
                                   }
          | TYPEOF '(' ID '['e']' ')' {if(!ids.existsVar($3))yyerror("variable does not exist");
                                   cout<<ids.getType($3)<<endl;
                                   }
          | TYPEOF '(' ID '.' ID ')' {if(!ids.existsVar($5))yyerror("variable does not exist");
                                   cout<<ids.getType($5)<<endl;
                                   }
evalFunc : EVAL evalForType 
         | EVAL '(' bExp ')' {cout <<"Valoarea expresiei:" <<boolalpha<< $3 << endl;}
evalForType : evalAritFunc {$$=$1;  cout <<"Valoarea expresiei:" << $$ << endl;}
evalAritFuncFT :'(' onlyExp ')' {$$=$2;}
evalAritFunc :'(' onlyExp ')' {$$=$2;}
             | '(' ID ')'{$$=ids.getValueFloat($2); }
             | '(' ID '[' e ']' ')' {     string val=ids.getValueIndex($2,$4); 
                          $$=stof(val);
                         if(!ids.existsVar($2))
                         {yyerror("variable is not declared in this scope");}
                         
                    }
e : e '+' e   {$$=$1+$3;}
  | e '*' e   {$$=$1*$3;}
  | e '-' e   {$$=$1-$3;}
  | e '/' e   {$$=$1/$3;}
  |'(' e ')' {$$= $2;}
  |'(' '-' e ')' {$$= -$3;}
  | FLOAT_NR {$$=$1;}
  | NR {$$=$1;}
  | ID {$$=ids.getValueFloat($1); }
  | ID '[' e ']' {     string val=ids.getValueIndex($1,$3); 
                         if(val == "")yyerror("No value on that position");
                          $$=stof(val);
                         if(!ids.existsVar($1))
                         {yyerror("variable is not declared in this scope");}
                         
                    }
  |ID '(' call_list ')' { 
                                   $$=0;
                                   if(!fnc.existFunction($1)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam($1,string($3)))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                   }
                                   
                               }
     | ID '(' ')'  { 
                                   $$=0;
                                   if(!fnc.existFunction($1)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!(fnc.numParam($1)==0))
                                        {
                                             yyerror("incorrect or insufficient parameters passed to function");
                                        }
                                   }
                                   
                               }
     |ID '.' ID {
          
          int i=ids.getIndex($3);
          string v=ids.getValueIndex($1,i);
          if(stoi(v) || stof(v))
          {
               $$=stof(v);
          }
     }
     |ID '.' ID '(' call_list ')'  {
                                  
                                   if(!fnc.existFunction($3)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam($3,string($5)))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                        string funcDomain= fnc.getDomain($3);
                                        if(!(ids.getType($1) == funcDomain))
                                        {
                                             yyerror("syntax error");
                                        }
                                   }
                                   if(!cls.existsClass(ids.getType($1).c_str()))
                                   {
                                        yyerror("class does not exist");
                                   }
                                    $$=0;
                               }
  ;


list_param_inner : param {$$=$1;}
            | list_param_inner ','  param {strcat($$,$3);}
            ;
          
param : TYPE ID {sprintf($$,"%s %s ", $1, $2);}
      | TYPE ID '[' ']' {sprintf($$,"%s %s ", $1, $2);}
      | STRING_TYPE ID {sprintf($$,"%s %s ", $1, $2);}
      | CHAR_TYPE ID {sprintf($$,"%s %s ", $1, $2);}
      | BOOL_TYPE ID {sprintf($$,"%s %s ", $1, $2);}
      | ID ID {sprintf($$,"%s %s ", $1, $2); if(!cls.existsClass($1))yyerror("unknown variable type");}
functions: function 
          |functions function  

function: TYPE ID'(' list_param_inner  ')' {
                                       
                                   if(!fnc.existFunction($2))
                                    {
                                        fnc.addFunction($1, $2, $4);
                                      
                                        fnc.addDomain($2, string(domain));
                                        
                                    }else yyerror("function with this name already exists");
                                   
                                   } {strcpy(domain,$2);} block {strcpy(domain,"global");}
          |BOOL_TYPE ID '(' list_param_inner ')'{
                                 
                                   if(!fnc.existFunction($2))
                                    {
                                        fnc.addFunction($1, $2, $4);
                                         fnc.addDomain($2, string(domain));
                                        
                                    }else yyerror("function with this name already exists");
                                    
                                   } {strcpy(domain,$2);} block  {strcpy(domain,"global");}
           |STRING_TYPE ID '(' list_param_inner ')' {
                                 
                                   if(!fnc.existFunction($2))
                                    {
                                        fnc.addFunction($1, $2, $4);
                                        fnc.addDomain($2, string(domain));
                                    }else yyerror("function with this name already exists");
                                   }{strcpy(domain,$2);} block  {strcpy(domain,"global");}
         |CHAR_TYPE ID '(' list_param_inner ')'     { 
                                                   if(!fnc.existFunction($2))
                                                   {
                                                      fnc.addFunction($1, $2, $4);
                                                       fnc.addDomain($2, string(domain));
                                        
                                                    }else yyerror("function with this name already exists");
                                   
                                             }{strcpy(domain,$2);} block   {strcpy(domain,"global");}
         | ID ID '(' list_param_inner ')'{if(!cls.existsClass($2))yyerror("unknown variable type");
                                                        if(!fnc.existFunction($2))
                                                   {
                                                      fnc.addFunction($1, $2, $4);
                                                      fnc.addDomain($2, string(domain));
                                                    }else yyerror("function with this name already exists");
                                                  } {strcpy(domain,$2);}  block   {strcpy(domain,"global");}
          | TYPE ID '(' ')' {
                                   char sp[2]=" ";
                                   if(!fnc.existFunction($2))
                                    {
                                        fnc.addFunction($1, $2, sp);
                                         fnc.addDomain($2, string(domain));
                                        
                                    }else yyerror("function with this name already exists");
                                   }{strcpy(domain,$2);}  block  {strcpy(domain,"global");}
          |BOOL_TYPE ID '(' ')'{
                                   char sp[2]=" ";
                                   if(!fnc.existFunction($2))
                                    {
                                        fnc.addFunction($1, $2, sp);
                                         fnc.addDomain($2, string(domain));
                                        
                                    }else yyerror("function with this name already exists");
                                   }{strcpy(domain,$2);}  block   {strcpy(domain,"global");}
           |STRING_TYPE ID '(' ')'{
                                   char sp[2]=" ";
                                   if(!fnc.existFunction($2))
                                    {
                                        fnc.addFunction($1, $2, sp);
                                        fnc.addDomain($2, string(domain));
                                        
                                    }else yyerror("function with this name already exists");
                                   }{strcpy(domain,$2);}  block   {strcpy(domain,"global");}
         |CHAR_TYPE ID '(' ')' { 
                                        char sp[2]=" ";
                                                   if(!fnc.existFunction($2))
                                                   {
                                                      fnc.addFunction($1, $2, sp);
                                                      fnc.addDomain($2, string(domain));
                                        
                                                    }else yyerror("function with this name already exists");
                                   
                                             }{strcpy(domain,$2);}  block      {strcpy(domain,"global");}
         | ID ID '(' ')' {if(!cls.existsClass($2))yyerror("unknown variable type");
                                             char sp[2]=" ";
                                                        if(!fnc.existFunction($2))
                                                   {
                                                      fnc.addFunction($1, $2, sp);
                                                       fnc.addDomain($2, string(domain));
                                                    }else yyerror("function with this name already exists");
                                                  }{strcpy(domain,$2);} block  {strcpy(domain,"global");}

        ;
conditionalBlock : IF_START '(' bExp ')' block
                 | IF_START '(' bExp ')' block ELSE conditionalBlock
                 | IF_START '(' bExp ')' block ELSE block
                 | WHILE_START '(' bExp ')' block
                 | DO block WHILE_START '(' bExp ')' ';'
                 | FOR_START '(' forFirst forSecond statement')' block
                 | FOR_START '(' forFirst forSecond ')' block
                 ;
forFirst : decl ';'
        // | idVar ASSIGN idVar ';'
         | idVar ASSIGN e ';'
         
         ;
forSecond : bExp ';'
          |';'

bExp : '(' bExp ')' {$$=$2;}
     | bExpForm {if($1==0)$$=false; else $$=true;}
     | bExpForm LOGIC_OR bExpForm {if($1 || $3)$$=true; else $$=false;}
     | bExpForm LOGIC_AND bExpForm{if($1 && $3)$$=true; else $$=false;}
     | '!''(' bExpForm LOGIC_OR bExpForm ')'{if($3||$5)$$=false; else $$=true;}
     | '!''(' bExpForm LOGIC_AND bExpForm ')'{if($3&&$5)$$=false; else $$=true;}
     | '(' bExp ')' LOGIC_AND bExpForm {if($2 && $5)$$=true; else $$=false;}
     | '(' bExp ')' LOGIC_OR bExpForm {if($2 || $5)$$=true; else $$=false;}
     |  bExpForm LOGIC_AND '(' bExp ')'{if($1 && $4)$$=true; else $$=false;}
     |  bExpForm LOGIC_OR  '(' bExp ')'{if($1 || $4)$$=true; else $$=false;}
     | '(' bExp ')' LOGIC_OR '(' bExp ')' {if($2 || $6)$$=true; else $$=false;}
     | '(' bExp ')' LOGIC_AND '(' bExp ')' {if($2 && $6)$$=true; else $$=false;}
     ;
bExpForm          :
                  '!''(' bExpForm ')'{if($3==0)$$=true; else $$=false;}
                  | e BOOL_E e {if($1==$3)$$=true; else $$=false;}
                  | e BOOL_LTE e {if($1<=$3)$$=true; else $$=false;}
                  | e BOOL_GTE e {if($1>=$3)$$=true; else $$=false;}
                  | e BOOL_NE e {if($1!=$3)$$=true; else $$=false;}
                  | e BOOL_LT e {if($1<$3)$$=true; else $$=false;}
                  | e BOOL_GT e {if($1>$3)$$=true; else $$=false;}
                  | BOOL_TRUE {$$=true;}
                  | '!' BOOL_FALSE {$$=true;}
                  | BOOL_FALSE {$$=false;}
                  | '!' BOOL_TRUE {$$=false;}
               ;
                  
declarations :  decl ';'          
	      |  declarations decl ';'  
	      ;
classLineGroup : classLine
               | classLineGroup classLine
classLine : decl ';' {ind=ind+1;}
          | function 
declarationBlockForClass : BGIN classLineGroup END
                         | BGIN END
                         ;
classDeclaration : CLASS ID {strcpy(domain,$2); isClass=1; ind=0;} declarationBlockForClass {
                         cls.addNewClass($2);
                         cls.setSize($2, ind);
                         ind=0;
                         isClass=0;
                         strcpy(domain,"global");
                    }
                  ;
userDefinedDeclarations : classDeclaration ';' 
                        | userDefinedDeclarations classDeclaration ';'
                        ;

decl       :  TYPE ID'['e']''['e']' { string s1=$2; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}

                     
                    }
          | STRING_TYPE ID'['e']''['e']' { string s1=$2; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}

                     
                    }
          | CHAR_TYPE ID'['e']''['e']' { string s1=$2; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}

                     
                    }
          | BOOL_TYPE ID'['e']''['e']' { string s1=$2; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}

                     
                    }
          |TYPE ID { string s1=$2; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}

                     
                    }
           | TYPE ID ASSIGN e { string s1=$2; 
                        string s2="declared existing variable ";
                 
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false, to_string($4).c_str());
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}

                    }
           |CONST TYPE ID ASSIGN e { string s1=$3; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($3)) {
                          ids.addVar($2,$3,true, to_string($5).c_str());
                          ids.addDomain($3, domain);
                          if(isClass)ids.setIndex($3, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
           | CHAR_TYPE ID ASSIGN CHARACTER { string s1=$2; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false, $4);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
           | CHAR_TYPE ID ASSIGN idVar { string s1=$2; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($2)) {
                         if(ids.haveSameTypeWithVar($1,$4))
                          ids.addVar($1,$2,false, $4);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
             |CONST CHAR_TYPE ID ASSIGN ID '[' e ']' { string s1=$2; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($3)) {
                         if(ids.haveSameTypeWithVar($2,$5))
                          ids.addVar($2,$3,true, ids.getValueIndex($5,$7).c_str());
                          ids.addDomain($3, domain);
                          if(isClass)ids.setIndex($3, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
            | CHAR_TYPE ID { string s1=$2; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
           |CONST CHAR_TYPE ID ASSIGN CHARACTER { string s1=$3; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($3)) {
                          ids.addVar($2,$3,true, $5);
                          ids.addDomain($3, domain);
                          if(isClass)ids.setIndex($3, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
           
           |CONST TYPE ID '[' e ']' { string s1=$3; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($3)) {
                          ids.addVar($2,$3,false);
                          ids.addDomain($3, domain);
                          if(isClass)ids.setIndex($3, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
           | STRING_TYPE ID '[' e ']'
           { string s1=$2; 
                      float size=$4;
                     
                        string s2="declared existing variable ";
                         string s3="no such variable as ";
                        
                          if((int)$4 != $4)
                         {
                              yyerror("not of int type");
                         }
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false,(int)$4);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                         }else {yyerror((s2+"'"+s1+"'").c_str());}
     
                    }
           | BOOL_TYPE ID '[' e ']'{ string s1=$2; 
                      float size=$4;
                     
                        string s2="declared existing variable ";
                         string s3="no such variable as ";
                        
                          if((int)$4 != $4)
                         {
                              yyerror("not of int type");
                         }
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false,(int)$4);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                         }else {yyerror((s2+"'"+s1+"'").c_str());}
     
                    }
           | CHAR_TYPE ID '[' e ']'{ string s1=$2; 
                      float size=$4;
                     
                        string s2="declared existing variable ";
                         string s3="no such variable as ";
                        
                          if((int)$4 != $4)
                         {
                              yyerror("not of int type");
                         }
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false,(int)$4);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                         }else {yyerror((s2+"'"+s1+"'").c_str());}
     
                    }
           | TYPE ID '[' e ']'
                    { string s1=$2; 
                      float size=$4;
                     
                        string s2="declared existing variable ";
                         string s3="no such variable as ";
                        
                          if((int)$4 != $4)
                         {
                              yyerror("not of int type");
                         }
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false,(int)$4);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                         }else {yyerror((s2+"'"+s1+"'").c_str());}
     
                    }
           |STRING_TYPE ID { string s1=$2; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
           |STRING_TYPE ID ASSIGN STRING_TEXT
                    { string s1=$2; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false, $4);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
            |BOOL_TYPE ID
                    { string s1=$2; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false);
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
           |BOOL_TYPE ID ASSIGN BOOL_TRUE
                    { string s1=$2; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false,"true");
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
           |BOOL_TYPE ID ASSIGN BOOL_FALSE
                    { string s1=$2; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($2)) {
                          ids.addVar($1,$2,false,"false");
                          ids.addDomain($2, domain);
                          if(isClass)ids.setIndex($2, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
           |CONST BOOL_TYPE ID ASSIGN BOOL_TRUE
                    { string s1=$3; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($3)) {
                          ids.addVar($2,$3,true,"true");
                          ids.addDomain($3, domain);
                          if(isClass)ids.setIndex($3, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
           |CONST BOOL_TYPE ID ASSIGN BOOL_FALSE
                    { string s1=$3; 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar($3)) {
                          ids.addVar($2,$3,true,"false");
                          ids.addDomain($3, domain);
                           if(isClass)ids.setIndex($3, ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
           |ID ID 
               {
                    string s1=$2; 
                    string s2="declared existing variable";
                    string s3="declared variable of unexpected type";
                    if(cls.existsClass($1))
                    {
                         if(!ids.existsVar($2))
                         {
                              ids.addVar($1,$2,false);
                              ids.addDomain($2, domain);
                              ids.setSize($2, cls.getSize($1));
                               if(isClass)ids.setIndex($2, ind);
                         }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }else {yyerror("declared variable of unexpected type");}
               }
           
           ;


block : BGIN list END  
      |BGIN END
     ;
     

list : statement ';' 
     | conditionalBlock
     | list conditionalBlock
     | list statement ';'
    
     ;
idVar : ID '[' NR ']' {string val=ids.getValueIndex($1,$3); 
                         strcpy($$, val.c_str());
                         if(!ids.existsVar($1))
                         {yyerror("variable is not declared in this scope");}
                         
                         }
      | ID '[' idVar ']' { 
                    int v=stoi($3);
                    string val=ids.getValueIndex($1,v); 
                         strcpy($$, val.c_str());
                    if(!ids.existsVar($1)){yyerror("variable is not declared in this scope");}
                     if($1==$3)yyerror("you can't have an array as a size of the same array");
          }
     | ID {    
               $$=$1;
               if(!ids.existsVar($1)){yyerror("variable is not declared in this scope");}
           
           }
      ;
statement: decl
           |ID '[' e ']' ASSIGN onlyExp {if(!ids.existsVar($1)){yyerror("variable is not declared in this scope");}
                                              else if(ids.isConstant($1)){yyerror("attempted to modify constant variable");}
                                   if($3>=ids.getSize($1) || $3<0)
                                   {
                                        yyerror("index out of bounds");
                                   }
                                   else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain($1)!="main" && ids.getDomain($1)!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                   else
                                   {
                                        string x= to_string($6);
                                        int i= $3;
                                        if(strcmp(domain,"main")==0)
                                        ids.populate($1,i,x);
                                   }
                            }
           |ID '[' e ']' ASSIGN ID {if(!ids.existsVar($1)){yyerror("variable is not declared in this scope");}
                            else if(ids.isConstant($1)){yyerror("attempted to modify constant variable");}
                                   if($3>=ids.getSize($1) || $3<0)
                                   {
                                        yyerror("index out of bounds");
                                   }
                                   else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                        if(!(ids.getDomain($6)=="global" || ids.getDomain($6)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && ((ids.getDomain($1)!="main" && ids.getDomain($1)!="global")
                                        ||(ids.getDomain($6)!="main" && ids.getDomain($6)!="global")))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                   else
                                   {
                                        string x= ids.getValue($6);
                                        int i= $3;
                                        if(strcmp(domain,"main")==0)
                                        ids.populate($1,i,x);
                                   }
                                        
                                              
                                       
                                   
                            }
           |ID '[' e ']' ASSIGN ID '[' e ']' {if(!ids.existsVar($1)){yyerror("variable is not declared in this scope");}
                            else if(ids.isConstant($1)){yyerror("attempted to modify constant variable");}
                                   if($3>=ids.getSize($1) || $3<0)
                                   {
                                        yyerror("index out of bounds");
                                   }
                                    
                                   
                                        if(!ids.haveSameType($1,$6))
                                        {
                                             yyerror("variables do not have the same type");
                                        }
                                        else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                        if(!(ids.getDomain($6)=="global" || ids.getDomain($6)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && ((ids.getDomain($1)!="main" && ids.getDomain($1)!="global")
                                        ||(ids.getDomain($6)!="main" && ids.getDomain($6)!="global")))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                        else
                                        {

                                             string x= ids.getValueIndex($6,$8);
                                             int i= $3;
                                             if(strcmp(domain,"main")==0)
                                             ids.populate($1,i,x);
                                        }
                                   
                            }
         |ID ASSIGN CHARACTER {if(!ids.existsVar($1)){yyerror("variable is not declared in this scope");} 
                            else if(ids.isConstant($1)){yyerror("attempted to modify constant variable");}
                              else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain($1)!="main" && ids.getDomain($1)!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                              
                              else if(!ids.modifyValue($1,$3))
                              {
                                   yyerror("casting is not supported");
                              }
                            }
           | ID '[' e ']' ASSIGN BOOL_TRUE{
                                   if(!ids.existsVar($1)){yyerror("variable is not declared in this scope");}
                            else if(ids.isConstant($1)){yyerror("attempted to modify constant variable");}
                                   if(!ids.isBool($1)){yyerror("attempted to assign a bool to a non bool");}
                                   if($3>=ids.getSize($1) || $3<0)
                                   {
                                        yyerror("index out of bounds");
                                   }
                                   else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain($1)!="main" && ids.getDomain($1)!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                   else
                                   {
                                        string x= "true";
                                        int i= $3;
                                        if(strcmp(domain,"main")==0)
                                        ids.populate($1,i,x);
                                   }
                            }
         | ID '[' e ']' ASSIGN BOOL_FALSE{
                                   if(!ids.existsVar($1)){yyerror("variable is not declared in this scope");}
                            else if(ids.isConstant($1)){yyerror("attempted to modify constant variable");}
                                   if(!ids.isBool($1)){yyerror("attempted to assign a bool to a non bool");}
                                   if($3>=ids.getSize($1) || $3<0)
                                   {
                                        yyerror("index out of bounds");
                                   }
                                   else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain($1)!="main" && ids.getDomain($1)!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                   else
                                   {
                                        string x= "false";
                                        int i= $3;
                                        if(strcmp(domain,"main")==0)
                                        ids.populate($1,i,x);
                                   }
                            }
         | ID '[' e ']' ASSIGN STRING_TEXT{
                                   if(!ids.existsVar($1)){yyerror("variable is not declared in this scope");}
                            else if(ids.isConstant($1)){yyerror("attempted to modify constant variable");}
                                   if(!ids.isString($1)){yyerror("attempted to assign a string to a non string");}
                                   if($3>=ids.getSize($1) || $3<0)
                                   {
                                        yyerror("index out of bounds");
                                   }
                                   else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain($1)!="main" && ids.getDomain($1)!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                   else
                                   {
                                        string x= $6;
                                        int i= $3;
                                        if(strcmp(domain,"main")==0)
                                        ids.populate($1,i,x);
                                   }
                            }
         |  ID '[' e ']' ASSIGN CHARACTER{
                                   if(!ids.existsVar($1)){yyerror("variable is not declared in this scope");}
                              else if(ids.isConstant($1)){yyerror("attempted to modify constant variable");}
                                   if(!ids.isChar($1)){yyerror("attempted to assign a char to a non char");}
                                   if($3>=ids.getSize($1) || $3<0)
                                   {
                                        yyerror("index out of bounds");
                                   }
                                   else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain($1)!="main" && ids.getDomain($1)!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                   else
                                   {
                                        string x= $6;
                                        int i= $3;
                                        if(strcmp(domain,"main")==0)
                                        ids.populate($1,i,x);
                                   }
                            }
  
         | ID ASSIGN onlyExp {if(!ids.existsVar($1)){yyerror("variable is not declared in this scope");}
                            else if(ids.isConstant($1)){yyerror("attempted to modify constant variable");}
                            else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain($1)!="main" && ids.getDomain($1)!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                            else if(!ids.modifyValue($1,to_string($3)))
                              {
                                   yyerror("casting is not supported");
                              }
                             
                            }
          | ID ASSIGN ID {if(!ids.existsVar($1)){yyerror("variable is not declared in this scope");}
                            else if(ids.isConstant($1)){yyerror("attempted to modify constant variable");}
                           
                             else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                        if(!(ids.getDomain($3)=="global" || ids.getDomain($3)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && ((ids.getDomain($1)!="main" && ids.getDomain($1)!="global")
                                        ||(ids.getDomain($3)!="main" && ids.getDomain($3)!="global")))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                            else if(!ids.modifyValueByVar($1,$3))
                              {
                                   yyerror("casting is not supported");
                              }
                            }
          
         | ID ASSIGN BOOL_TRUE {
                                  if(!ids.existsVar($1)){yyerror("variable is not declared in this scope");}
                                  if(!ids.isBool($1)){yyerror("variable is not of type 'bool'");}
                                  else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain($1)!="main" && ids.getDomain($1)!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                  else if(!ids.modifyValue($1,to_string($3)))
                                   {
                                   yyerror("casting is not supported");
                                    }
                               }
         | ID ASSIGN BOOL_FALSE {
                                  if(!ids.existsVar($1)){yyerror("variable is not declared in this scope");}
                                  if(!ids.isBool($1)){yyerror("variable is not of type 'bool'");}
                                  else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain($1)!="main" && ids.getDomain($1)!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                  else if(!ids.modifyValue($1,to_string($3)))
                              {
                                   yyerror("casting is not supported");
                              }
                               }
         | ID ASSIGN STRING_TEXT {
                    string s1=$1;
               if(!ids.isString($1))
               {
                    yyerror("attept of assigning a string to a non-string type");
                        
               }
                else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain($1)!="main" && ids.getDomain($1)!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                      else if(!ids.modifyValue($1,$3))
                              {
                                   yyerror("casting is not supported");
                              }
         } 
         | ID ASSIGN ID '(' call_list ')' {
                    if(!ids.existsVar($1))yyerror("variable is not declared in this scope");
                         if(!fnc.existFunction($3)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam($3,string($5)))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                   }
                              if(fnc.getType($3) != ids.getType($1))
                         {
                              yyerror("variable does not have the same type as the function");
                         }
                          else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain($1)!="main" && ids.getDomain($1)!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                else  if(!ids.modifyValue($1,$3))
                              {
                                   yyerror("casting is not supported");
                              }
                        
                         
                     }
          | ID '[' e ']' ASSIGN ID '(' call_list ')' {
                    if(!ids.existsVar($1))yyerror("variable is not declared in this scope");
                         if(!fnc.existFunction($6)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam($6,string($8)))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                   }
                         
                         if(fnc.getType($6) != ids.getType($1))
                         {
                              yyerror("variable does not have the same type as the function");
                         }
                           else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain($1)!="main" && ids.getDomain($1)!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                         
                     }
         | ID '(' call_list ')' {
                                  
                                   if(!fnc.existFunction($1)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam($1,string($3)))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                   }
                               }
          | ID '(' ')' {if(!fnc.existFunction($1)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!(fnc.numParam($1)==0))
                                        {
                                             yyerror("incorrect or insufficient parameters passed to function");
                                        }
                                   }
                               }
         | ID ASSIGN ID '[' e ']' {if(!ids.haveSameType($1,$3))yyerror("variables have different types");
                                          else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                        if(!(ids.getDomain($3)=="global" || ids.getDomain($3)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && ((ids.getDomain($1)!="main" && ids.getDomain($1)!="global")
                                        ||(ids.getDomain($3)!="main" && ids.getDomain($3)!="global")))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                        string val= ids.getValueIndex($3, $5);
                                       
                                        
                                        ids.modifyValue($1, val);
                                   }
         | evalFunc
         | typeoffunc
         | ID '.' ID ASSIGN onlyExp {
                                        if(!cls.existsClass(ids.getType($1).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        if(string(domain)=="main")
                                        if(ids.getType($1)==ids.getDomain($3))
                                        {
                                            
                                             string v=to_string($5);
                                             ids.populate($1, ids.getIndex($3), v);
                                        }
                                        else  yyerror("hopa");
                                    }
           | ID '.' ID ASSIGN STRING_TEXT{
                                        if(!cls.existsClass(ids.getType($1).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        if(string(domain)=="main")
                                        if(ids.getType($1)==ids.getDomain($3))
                                        {
                                            if(ids.isString($3))
                                             {
                                             ids.populate($1, ids.getIndex($3), $5);}
                                                  }
                                        else  yyerror("hopa");
                                    }
          | ID '.' ID ASSIGN CHARACTER{
                                        if(!cls.existsClass(ids.getType($1).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        if(string(domain)=="main")
                                        if(ids.getType($1)==ids.getDomain($3))
                                        {
                                            if(ids.isChar($3))
                                             {
                                             ids.populate($1, ids.getIndex($3), $5);}
                                                  }
                                        else  yyerror("hopa");
                                    }
          | ID '.' ID ASSIGN BOOL_TRUE{
                                        if(!cls.existsClass(ids.getType($1).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        if(string(domain)=="main")
                                        if(ids.getType($1)==ids.getDomain($3))
                                        {
                                            if(ids.isBool($3))
                                             {
                                             ids.populate($1, ids.getIndex($3), "true");}
                                                  }
                                        else  yyerror("hopa");
                                    }
          | ID '.' ID ASSIGN BOOL_FALSE{
                                        if(!cls.existsClass(ids.getType($1).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        if(string(domain)=="main")
                                        if(ids.getType($1)==ids.getDomain($3))
                                        {
                                            if(ids.isBool($3))
                                             {
                                             ids.populate($1, ids.getIndex($3), "false");}
                                                  }
                                        else  yyerror("hopa");
                                    }
          | ID '.' ID ASSIGN ID {
                                        if(!cls.existsClass(ids.getType($1).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        if(!(ids.getDomain($5)=="main" || ids.getDomain($5)=="global"))
                                        {
                                             yyerror("variable was not declared in this scope");
                                        }
                                        else if(!ids.haveSameType($3,$5))
                                        {
                                              yyerror("casting is not supported");
                                        }
                                        else if(ids.getType($1)==ids.getDomain($3) && string(domain)=="main")
                                        {
                                            
                                             string v=ids.getValue($5);
                                             ids.populate($1, ids.getIndex($3), v);
                                        }
                                        else  yyerror("hopa");
                                    }
          | ID '.' ID ASSIGN ID '['e']'{
                                        if(!cls.existsClass(ids.getType($1).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        if(!(ids.getDomain($5)=="main" || ids.getDomain($5)=="global"))
                                        {
                                             yyerror("variable was not declared in this scope");
                                        }
                                        else if(!ids.haveSameType($3,$5))
                                        {
                                              yyerror("casting is not supported");
                                        }
                                        else if(ids.getType($1)==ids.getDomain($3) && string(domain)=="main")
                                        {
                                            
                                             string v=ids.getValueIndex($5,$7);
                                             ids.populate($1, ids.getIndex($3), v);
                                        }
                                        else  yyerror("hopa");
                                    }
             | ID '.' ID ASSIGN ID '.' ID{
                                        if(!cls.existsClass(ids.getType($1).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        else if(!cls.existsClass(ids.getType($5).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        else if(!ids.haveSameType($3,$7))
                                        {
                                              yyerror("casting is not supported");
                                        }
                                        else if(ids.getType($1)==ids.getDomain($3) && string(domain)=="main")
                                        {
                                             int i=ids.getIndex($7);
                                             string v=ids.getValueIndex($5,i);
                                             ids.populate($1, ids.getIndex($3), v);
                                        }
                                        else  yyerror("hopa");
                                    }
          | ID ASSIGN ID '.' ID{
                                   
                                        if(!cls.existsClass(ids.getType($3).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        else if(!ids.haveSameType($1,$5))
                                        {
                                              yyerror("casting is not supported");
                                        }
                                         else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain($1)!="main" && ids.getDomain($1)!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                        else 
                                        {
                                             int i=ids.getIndex($5);
                                             string v=ids.getValueIndex($3,i);
                                             ids.modifyValue($1, v);
                                        }
                                        
                                    }
          | ID '['e']' ASSIGN ID '.' ID{
                                        if(!cls.existsClass(ids.getType($6).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        else if(!ids.haveSameType($1,$8))
                                        {
                                              yyerror("casting is not supported");
                                        }
                                         else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain($1)=="global" || ids.getDomain($1)==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain($1)!="main" && ids.getDomain($1)!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                        else 
                                        {
                                             int i=ids.getIndex($8);
                                             string v=ids.getValueIndex($6,i);
                                             ids.populate($1, $3, v);
                                        }
                                     
                                    }
          | ID '.' ID '(' call_list ')' {
                                  
                                   if(!fnc.existFunction($3)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam($3,string($5)))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                        string funcDomain= fnc.getDomain($3);
                                        if(!(ids.getType($1) == funcDomain))
                                        {
                                             yyerror("syntax error");
                                        }
                                   }
                                   if(!cls.existsClass(ids.getType($1).c_str()))
                                   {
                                        yyerror("class does not exist");
                                   }
                               }
          | ID '.' ID '(' ')' {if(!fnc.existFunction($3)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!(fnc.numParam($3)==0))
                                        {
                                             yyerror("incorrect or insufficient parameters passed to function");
                                        }
                                        string funcDomain= fnc.getDomain($3);
                                        if(!(ids.getType($1) == funcDomain))
                                        {
                                             yyerror("syntax error");
                                        }
                                   }
                                   if(!cls.existsClass(ids.getType($1).c_str()))
                                   {
                                        yyerror("class does not exist");
                                   }
                                   
                               }
         ;



onlyExp  : e '+' e   {$$=$1+$3;}
  | e '*' e   {$$=$1*$3;}
  | e '-' e   {$$=$1-$3;}
  | e '/' e   {$$=$1/$3;}
  |'(' e ')' {$$= $2;}
  |'(' '-' e ')' {$$= -$3;}
  | FLOAT_NR {$$=$1;}
  | NR {$$=$1;}
  ;
call_list : 
           onlyExp {
                       
     
                      char in[20]="int ";
                      char fl[20]="float ";
                      if($1=(int)$1){$$=in;;}else $$=fl;
                      
               }
           |ID '(' call_list ')' { 
                                   
                                   if(!fnc.existFunction($1)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam($1,string($3)))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                        else{ string type=fnc.getType($1)+ " "; strcpy($$,type.c_str());}
                                   }
                                   
                               }
          | ID '(' ')'  { 
                                   
                                   if(!fnc.existFunction($1)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!(fnc.numParam($1)==0))
                                        {
                                             yyerror("incorrect or insufficient parameters passed to function");
                                        }
                                        else {string type=fnc.getType($1)+ " "; strcpy($$,type.c_str());}
                                   }
                                   
                               }
           |ID '.' ID '(' call_list ')' { 
                                   
                                   if(!fnc.existFunction($3)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam($3,string($5)))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                        else{ string type=fnc.getType($3)+ " "; strcpy($$,type.c_str());}
                                   }
                                   
                               }
          | ID '.'ID '(' ')'  { 
                                   
                                   if(!fnc.existFunction($3)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!(fnc.numParam($3)==0))
                                        {
                                             yyerror("incorrect or insufficient parameters passed to function");
                                        }
                                        else {string type=fnc.getType($3)+ " "; strcpy($$,type.c_str());}
                                   }
                                   
                               }
           | ID {string type=ids.getType($1)+ " "; strcpy($$,type.c_str()); }
           | ID '[' e ']'{string type=ids.getType($1)+ " "; strcpy($$,type.c_str()); }
           | STRING_TEXT {strcpy($$,"string ");}
           | bExp { strcpy($$,"bool ");}
           | CHARACTER {strcpy($$, "char ");}
           | call_list ',' ID '[' e ']' {string type=ids.getType($3); strcat($$,type.c_str()); strcat($$," "); }
           | call_list ',' ID {string type=ids.getType($3); strcat($$,type.c_str()); strcat($$," "); }
           | call_list ',' onlyExp {if($3=(int)$3){strcat($$,"int ");}else strcat($$,"float ");}
           | call_list ',' STRING_TEXT {strcat($$," "); strcat($$, "string ");}
           | call_list ',' bExp {strcat($$," "); strcat($$, "bool ");}
           | call_list ',' CHARACTER  {strcat($$," "); strcat($$, "char ");}
            |call_list ',' ID '(' call_list ')' { 
                                   
                                   if(!fnc.existFunction($3)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam($3,string($5)))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                        else{ string type=fnc.getType($3)+ " "; strcat($$,type.c_str());}
                                   }
                                   
                               }
            |call_list ',' ID '(' ')'  { 
                                   
                                   if(!fnc.existFunction($3)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!(fnc.numParam($3)==0))
                                        {
                                             yyerror("incorrect or insufficient parameters passed to function");
                                        }
                                        else {string type=fnc.getType($3)+ " "; strcat($$,type.c_str());}
                                   }
                                   
                               }
           |call_list ',' ID '.' ID '(' call_list ')' { 
                                   
                                   if(!fnc.existFunction($5)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam($5,string($7)))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                        else{ string type=fnc.getType($5)+ " "; strcat($$,type.c_str());}
                                   }
                                   
                               }
          |call_list ','  ID '.'ID '(' ')'  { 
                                   
                                   if(!fnc.existFunction($5)){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!(fnc.numParam($5)==0))
                                        {
                                             yyerror("incorrect or insufficient parameters passed to function");
                                        }
                                        else {string type=fnc.getType($5)+ " "; strcat($$,type.c_str());}
                                   }
                                   
                               }
           ;
%%
void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
     strcpy(buffer,"\n");
     ids.printVars(buffer);
     fnc.printFuncs(buffer);
     fout<<buffer;
     
     
} 
