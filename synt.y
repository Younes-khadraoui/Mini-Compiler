%{
    int nb_ligne=1, col=1;
%}

%union {
         int     entier;
         char*   str;
         float reel;
}

%token mc_program mc_routine mc_equivalence mc_entier mc_real mc_logical mc_character mc_dimension mc_read mc_write mc_if mc_then mc_else mc_endif mc_dowhile mc_enddo mc_or mc_and mc_gt mc_ge mc_eq mc_ne mc_le mc_lt mc_call mc_endr mc_end <str>IDF cst add sub mul divv pvg  vrg aff     err 

%start S

%%
S: mc_program IDF DEC  INST mc_end {printf("prog syntaxiquement correct"); YYACCEPT;}
;
DEC: TYPE ListIDF pvg DEC
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
main()
{
yyparse();
}
yywrap ()   
{}
int yyerror ( char*  msg )  
 {
    printf ("Erreur Syntaxique a ligne %d a colonne %d \n", nb_ligne,col);
  }
