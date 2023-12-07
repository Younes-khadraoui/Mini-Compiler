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

%token  mc_program mc_routine  mc_entier 
        mc_real mc_logical mc_character mc_dimension 
        mc_read mc_write mc_if mc_then mc_else mc_endif 
        mc_dowhile mc_enddo mc_or mc_and mc_gt mc_ge mc_eq 
        mc_ne mc_le mc_lt mc_call mc_endr mc_end <str>IDF integr floatt
        add sub mul divv pvg  vrg aff po pf  mc_equivalence


%start S

%left add sub
%left mul divv

%%

S: FUNCTION | PROGRAM {printf("prog syntaxiquement correct"); YYACCEPT;}
;

FUNCTION : HEADER BODY mc_endr S
;

HEADER : TYPE mc_routine IDF PARAMETRE 
;

TYPE: mc_entier 
     | mc_real
     | mc_logical
     |mc_character
;

PARAMETRE : po LISTP pf 
;

LISTP : ListIDF pvg LISTP
        | 
;

ListIDF: IDF vrg ListIDF
       | IDF  
;

BODY : DEC INST RETURN
;
DEC: TYPE ListIDF pvg 
   | TYPE A
;

A : IDF X
;

X:    pvg
    | mc_dimension po Y pf pvg
;

Y :       integr vrg integr
        | integr
;

RETURN : IDF aff IDF pvg
;

PROGRAM : mc_program IDF DEC INST mc_end
;


INST :    AFFECTATION
        | ES 
        | CONDITON
        | LOOP 
        | CALLING
;

AFFECTATION : IDF aff EXPRESSION pvg
            | IDF aff integr pvg
            | IDF aff floatt pvg
;

EXPRESSION :  ADDITION EXPRESSION
            | DIVISION EXPRESSION
            | MULTIPLAY EXPRESSION
            | SUBSTRACT EXPRESSION
            | pvg
;

ADDITION :    IDF add IDF 
            | IDF add integr
            | IDF add floatt
;

SUBSTRACT :   IDF sub IDF 
            | IDF sub integr
            | IDF sub floatt
;
MULTIPLAY :   IDF mul IDF 
            | IDF mul integr
            | IDF mul floatt
;
DIVISION :    IDF divv IDF 
            | IDF divv integr
            | IDF divv floatt
;


ES :  READ 
    | WRITE
;

READ :        mc_read po IDF pf pvg
;

WRITE :       mc_write po 
;

CONDITON :    mc_if po EXPCDT pf mc_then INST mc_else INST mc_endif
;

EXPCDT :      IDF CDT EXPCDT
            | IDF CDT EXPRESSION
            | IDF CDT BOOLEEN
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

BOOLEEN : 
;

LOOP: mc_dowhile po EXPCDT pf INST mc_enddo pvg
;

CALLING : IDF aff mc_call IDF PARAMETRE pvg
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
    return 0;
}
yywrap ()
{}
int yyerror ( char*  msg )  
{
       printf ("Erreur Syntaxique : fichier %s , ligne %d , colonne %d \n", filename,nb_ligne,col);
}
