/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LIMBAJ_TAB_H_INCLUDED
# define YY_YY_LIMBAJ_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BGIN = 258,                    /* BGIN  */
    END = 259,                     /* END  */
    ASSIGN = 260,                  /* ASSIGN  */
    FLOAT_NR = 261,                /* FLOAT_NR  */
    NR = 262,                      /* NR  */
    BOOL_TRUE = 263,               /* BOOL_TRUE  */
    BOOL_FALSE = 264,              /* BOOL_FALSE  */
    CHARACTER = 265,               /* CHARACTER  */
    ID = 266,                      /* ID  */
    TYPE = 267,                    /* TYPE  */
    STRING_TYPE = 268,             /* STRING_TYPE  */
    STRING_TEXT = 269,             /* STRING_TEXT  */
    CLASS = 270,                   /* CLASS  */
    BOOL_TYPE = 271,               /* BOOL_TYPE  */
    ENTRY_POINT = 272,             /* ENTRY_POINT  */
    LOGIC_OR = 273,                /* LOGIC_OR  */
    LOGIC_AND = 274,               /* LOGIC_AND  */
    CHAR_TYPE = 275,               /* CHAR_TYPE  */
    IF_START = 276,                /* IF_START  */
    WHILE_START = 277,             /* WHILE_START  */
    FOR_START = 278,               /* FOR_START  */
    DEC = 279,                     /* DEC  */
    INC = 280,                     /* INC  */
    DO = 281,                      /* DO  */
    ELSE = 282,                    /* ELSE  */
    CONST = 283,                   /* CONST  */
    EVAL = 284,                    /* EVAL  */
    BOOL_LT = 285,                 /* BOOL_LT  */
    BOOL_LTE = 286,                /* BOOL_LTE  */
    BOOL_GT = 287,                 /* BOOL_GT  */
    BOOL_GTE = 288,                /* BOOL_GTE  */
    BOOL_E = 289,                  /* BOOL_E  */
    BOOL_NE = 290,                 /* BOOL_NE  */
    TYPEOF = 291                   /* TYPEOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "limbaj.y"

     char* string;
     int integerValue;
     float floatValue; 
     bool boolValue;

#line 107 "limbaj.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LIMBAJ_TAB_H_INCLUDED  */
