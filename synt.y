%{
       #include <stdio.h>
       int nb_ligne=1, col=1;
       extern FILE *yyin;
       char *filename;
%}

%union {
         int     entier;
         char*   str;
         float reel;
}

%token mc_program mc_routine mc_equivalence mc_entier 
       mc_real mc_logical mc_character mc_dimension 
       mc_read mc_write mc_if mc_then mc_else mc_endif 
       mc_dowhile mc_enddo mc_or mc_and mc_gt mc_ge mc_eq 
       mc_ne mc_le mc_lt mc_call mc_endr mc_end <str>IDF 
       cst add sub mul divv pvg  vrg aff po pf err cstE 
       cstF

%start S

%%
S: TYPE mc_routine IDF po ListIDF pf DEC INST mc_endr mc_program IDF DEC  INST mc_end {printf("prog syntaxiquement correct"); YYACCEPT;}
;
DEC: TYPE ListIDF pvg DEC
   | TYPE ListIDF aff cstE
   | TYPE ListIDF aff sub cstE
   |
;
TYPE: mc_entier 
     | mc_real
     | mc_logical
     |mc_character
;
ListIDF: IDF vrg ListIDF
       | IDF  
;
INST : 
%%
int main(int argc, char **argv) {
    if (argc > 0) {
        yyin = fopen(argv[1], "r");
        filename = argv[1];
    } else {
        printf("Aucun fichier à compiler\n");
        return 1;
    }

    yyparse();
    fclose(yyin);
    return 0;
}
yywrap ()
{}
int yyerror ( char*  msg )  
{
       printf ("Erreur Syntaxique : fichier %s , ligne %d , colonne %d \n", filename,nb_ligne,col);
}
