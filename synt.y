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

%token  mc_program mc_routine  mc_entier err <str>string mc_true mc_false
        mc_real mc_logical mc_character mc_dimension 
        mc_read mc_write mc_if mc_then mc_else mc_endif 
        mc_dowhile mc_enddo mc_or mc_and mc_gt mc_ge mc_eq 
        mc_ne mc_le mc_lt mc_call mc_endr mc_end <str>IDF <entier>integr <reel>floatt
        add sub mul divv pvg  vrg aff po pf  mc_equivalence quote 


%start S
%left add sub
%left mul divv


%%

S: FUNCTION | PROGRAM {printf("prog syntaxiquement correct"); YYACCEPT;}
;

FUNCTION : HEADER BODY mc_endr S
;

HEADER : TYPE mc_routine IDF po PARAMETRE pf
;

TYPE:  mc_entier 
     | mc_real
     | mc_logical
     | mc_character
;

PARAMETRE :   IDF 
            | IDF vrg PARAMETRE
;



BODY : DEC INST 
;
	
DEC:  TYPE ListIDF pvg DEC
    | TYPE ListTAB pvg DEC
    | TYPE IDF mul integr pvg DEC
    |
;

ListIDF: IDF
       | IDF vrg ListIDF
       | IDF aff NUMBER 
       | IDF aff NUMBER vrg ListIDF
;

ListTAB : IDF mc_dimension po TAILLE pf 
        | IDF mc_dimension po TAILLE pf ListTAB
        |
;
	
TAILLE : integr
        | integr vrg integr
;



PROGRAM : mc_program IDF DEC INST mc_end
;


INST :    AFFECTATION
        | ES 
        | CONDITON
        | LOOP 
        | CALLING
        | EQUIV
	    | AFFECTATION pvg INST
        | ES pvg INST
	    | CONDITON pvg INST
	    | LOOP pvg INST
	    | CALLING pvg INST
	    | EQUIV pvg INST
        |
;



AFFECTATION : IDF aff EXPRESSION INST
            | IDF aff NUMBER pvg INST
            | IDF aff CHAINE pvg INST
            | IDF aff LOGICAL pvg INST

;

EXPRESSION : IDF pvg
            | NUMBER pvg
            | IDF OPERATION IDF
            | IDF OPERATION NUMBER
            | IDF OPERATION EXPRESSION 
            | po EXPRESSION pf
;

OPERATION : add | sub | mul | divv
;

NUMBER: integr | floatt
;

CHAINE :  string 
;

LOGICAL : mc_true|mc_false
;

ES :  mc_read po IDF pf 
    | mc_write po STRING pf 
;
STRING : CHAINE vrg IDF vrg CHAINE
        | CHAINE
;

CONDITON :  mc_if po EXPCDT pf mc_then INST mc_else INST mc_endif
;

EXPCDT :      IDF CDT EXPCDT
            | IDF CDT EXPRESSION
            | IDF CDT LOGICAL
            | IDF
;

CDT :         mc_eq
            | mc_ne
            | mc_ge
            | mc_gt
            | mc_le
            | mc_lt
            | mc_and
            | mc_or
;

LOOP: mc_dowhile po EXPCDT pf INST mc_enddo pvg
;

CALLING : IDF aff mc_call IDF po PARAMETRE pf pvg
;

EQUIV: mc_equivalence po PARAMETRE pf vrg po PARAMETRE pf pvg
;

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
    afficher();
    return 0;
}
yywrap ()
{}
int yyerror ( char*  msg )  
{
       printf ("Erreur Syntaxique : fichier %s , ligne %d , colonne %d \n", filename,nb_ligne,col);
}
