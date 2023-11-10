%{
    #include "synt.tab.h"
    extern nb_ligne;
    extern col;
%}
lettreM [A-Z]
lettre [a-z]
chiffre [0-9]
IDF ({lettreM}|{lettre})({lettreM}|{lettre}|{chiffre})*

%%

PROGRAM   { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_code; }
ROUTINE   { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_routine; }
INTEGER   { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_entier; }
REAL      { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_real; }
LOGICAL   { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_logical; }
CHARACTER { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_character; }
DIMENSION { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_dimension; }
READ      { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_read; }
WRITE     { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_write; }
IF        { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_if; }
THEN      { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_then; }
ELSE      { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_else; }
ENDIF     { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_endif; }
DOWHILE   { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_dowhile; }
ENDDO     { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_enddo; }
OR        { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_or; }
AND       { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_and; }
GT        { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_gt; }
GE        { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_ge; }
EQ        { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_eq; }
NE        { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_ne; }
LE        { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_le; }
LT        { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_lt; }
CALL      { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_call; }
END       { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_end; }
ENDR      { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mc_endr; }

{IDF}     { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return IDF; }

"+"       { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return add; }
"-"       { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return sub; }
"*"       { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return mul; }
"/"       { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return div; }
";"       { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return pvg; }
","       { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return vrg; }
"="       { col = col + strlen(yytext); printf("L'entité reconnue est %s \n", yytext); return aff; }

[ \t]     { col = col + strlen(yytext); }
\n        { col = 1; nb_ligne++; }
.         { printf("Erreur lexical à la ligne %d, colonne %d, entité %s \n", nb_ligne, col, yytext); return err; }
