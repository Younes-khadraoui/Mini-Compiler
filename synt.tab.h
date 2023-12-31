
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     mc_program = 258,
     mc_routine = 259,
     mc_entier = 260,
     string = 261,
     mc_true = 262,
     mc_false = 263,
     mc_real = 264,
     mc_logical = 265,
     mc_character = 266,
     mc_dimension = 267,
     mc_read = 268,
     mc_write = 269,
     mc_if = 270,
     mc_then = 271,
     mc_else = 272,
     mc_endif = 273,
     mc_dowhile = 274,
     mc_enddo = 275,
     mc_or = 276,
     mc_and = 277,
     mc_gt = 278,
     mc_ge = 279,
     mc_eq = 280,
     mc_ne = 281,
     mc_le = 282,
     mc_lt = 283,
     mc_call = 284,
     mc_endr = 285,
     mc_end = 286,
     IDF = 287,
     integr = 288,
     floatt = 289,
     add = 290,
     sub = 291,
     mul = 292,
     divv = 293,
     pvg = 294,
     vrg = 295,
     aff = 296,
     po = 297,
     pf = 298,
     mc_equivalence = 299,
     point = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 13 "synt.y"

         int     entier;
         char*   str;
         float reel;




/* Line 1676 of yacc.c  */
#line 106 "synt.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


