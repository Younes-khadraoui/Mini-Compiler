%{
	#include "synt.tab.h"
	#include "ts.h"

	extern nb_ligne;
	extern col;
	extern YYSTYPE yylval;
%}
lettreM [A-Z]
lettre [a-z]
chiffre [0-9]
IDF ({lettreM}|{lettre})({lettre}|{chiffre}|{lettreM})*
%%

PROGRAM   { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_program; }
ROUTINE   { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_routine; }
EQUIVALENCE   { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_equivalence; }
INTEGER   { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_entier; }
REAL      { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_real; }
LOGICAL   { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_logical; }
CHARACTER { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_character; }
DIMENSION { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_dimension; }
READ      { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_read; }
WRITE     { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_write; }
IF        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_if; }
THEN      { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_then; }
ELSE      { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_else; }
ENDIF     { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_endif; }
DOWHILE   { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_dowhile; }
ENDDO     { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_enddo; }
OR        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_or; }
AND       { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_and; }
GT        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_gt; }
GE        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_ge; }
EQ        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_eq; }
NE        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_ne; }
LE        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_le; }
LT        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_lt; }
CALL      { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_call; }
END       { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_end; }
ENDR      { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_endr; }

{IDF}     { 
              yylval.str=strdup(yytext);
			  rechercher(yytext,"IDF"," ",0,0);  
              col= col + strlen(yytext);
			  if (yyleng>10) printf ("Erreur Lexical: IDF trop long a la ligne %d a la colonne %d \n ",nb_ligne, col);
              printf (" L entite lexicale reconnue est %s \n", yytext); 
			  return IDF;
		  }

"+"       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return add; }
"-"       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return sub; }
"*"       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mul; }
"/"       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return divv; }
";"       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return pvg; }
","       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return vrg; }
"="       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return aff; }

[ \t]     { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); }
\n        { rechercher(yytext,"Mot cle",0,0, 2); col = 1; nb_ligne++; }
. { printf("Erreur lexical à la ligne %d, colonne %d, entite %s \n", nb_ligne, col, yytext); return err; }
