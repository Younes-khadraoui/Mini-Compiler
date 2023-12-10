
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
     err = 261,
     string = 262,
     mc_true = 263,
     mc_false = 264,
     mc_real = 265,
     mc_logical = 266,
     mc_character = 267,
     mc_dimension = 268,
     mc_read = 269,
     mc_write = 270,
     mc_if = 271,
     mc_then = 272,
     mc_else = 273,
     mc_endif = 274,
     mc_dowhile = 275,
     mc_enddo = 276,
     mc_or = 277,
     mc_and = 278,
     mc_gt = 279,
     mc_ge = 280,
     mc_eq = 281,
     mc_ne = 282,
     mc_le = 283,
     mc_lt = 284,
     mc_call = 285,
     mc_endr = 286,
     mc_end = 287,
     IDF = 288,
     integr = 289,
     floatt = 290,
     add = 291,
     sub = 292,
     mul = 293,
     divv = 294,
     pvg = 295,
     vrg = 296,
     aff = 297,
     po = 298,
     pf = 299,
     mc_equivalence = 300,
     quote = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 8 "synt.y"

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


