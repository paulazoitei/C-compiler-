%{
#include <stdio.h>
#include <string.h>
#include "limbaj.tab.h"
%}
%option noyywrap
%%
"main" {yylval.string = strdup(yytext);return ENTRY_POINT;}
">" {yylval.string = strdup(yytext);return BOOL_GT;} 
"<" {yylval.string = strdup(yytext);return BOOL_LT;}
"<=" {yylval.string = strdup(yytext);return BOOL_LTE;}
">=" {yylval.string = strdup(yytext);return BOOL_GTE;}
"==" {yylval.string = strdup(yytext);return BOOL_E;}
"!=" {yylval.string = strdup(yytext);return BOOL_NE;}
"Eval" {yylval.string = strdup(yytext);return EVAL;}
"TypeOf"  {yylval.string = strdup(yytext);return TYPEOF;}
"const" {yylval.string = strdup(yytext);return CONST;}
"do" {yylval.string = strdup(yytext);return DO;}
"if" {yylval.string = strdup(yytext);return IF_START;}
"else" {yylval.string = strdup(yytext);return ELSE;}
"while" {yylval.string = strdup(yytext);return WHILE_START;}
"for" {yylval.string = strdup(yytext);return FOR_START;}
"||" {yylval.string = strdup(yytext);return LOGIC_OR;}
"&&" {yylval.string = strdup(yytext);return LOGIC_AND;}
"int"|"float" {yylval.string = strdup(yytext);return TYPE;}
"char" {yylval.string = strdup(yytext);return CHAR_TYPE;}
"bool" {yylval.string=strdup(yytext); return BOOL_TYPE;}
"class"|"struct" {yylval.string = strdup(yytext); return CLASS;}
"string" {yylval.string = strdup(yytext); return STRING_TYPE;}
"true" {yylval.string = strdup(yytext); return BOOL_TRUE;}
"false" {yylval.string = strdup(yytext); return BOOL_FALSE;}
"++" {yylval.string = strdup(yytext); return INC;}
"--" {yylval.string = strdup(yytext); return DEC;}
'.'{1,4}  {yylval.string = strdup(yytext);return CHARACTER;}
\"(([^\"]|\\\")*[^\\])?\" {yylval.string = strdup(yytext); return STRING_TEXT;}
"{" {return BGIN;}
"}" {return END;}

[a-zA-Z][a-zA-Z0-9]* {yylval.string = strdup(yytext); return ID;}
"=" {return ASSIGN;}
[0-9]*[.][0-9]+ {yylval.floatValue=atof(yytext); return FLOAT_NR;}
0|[1-9]+[0-9]* {yylval.floatValue=atof(yytext); return NR;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
