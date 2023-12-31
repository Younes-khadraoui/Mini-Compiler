%{
       #include <stdio.h>
       #include<stdlib.h>
       #include<string.h>
       int nb_ligne=1, col=1;
       extern FILE *yyin;
       char* saveType;
       char *filename;
%}

%union {
         int     entier;
         char*   str;
         float reel;

}

%token  mc_program mc_routine  <str>mc_entier  <str>string mc_true mc_false
        <str>mc_real <str>mc_logical <str>mc_character mc_dimension 
        mc_read mc_write mc_if mc_then mc_else mc_endif 
        mc_dowhile mc_enddo mc_or mc_and mc_gt mc_ge mc_eq 
        mc_ne mc_le mc_lt mc_call mc_endr mc_end <str>IDF <entier>integr <reel>floatt
        add sub mul divv pvg  vrg aff po pf  mc_equivalence  point

%type <str> TYPE 


%start S
%left add sub
%left mul divv


%%

S: FUNCTION | PROGRAM {printf("prog syntaxiquement correct"); YYACCEPT;}
;

FUNCTION : HEADER BODY mc_endr S
;

HEADER : TYPE mc_routine IDF {modifyType($3,$1)} po PARAMETRE pf
;

TYPE:  mc_entier {saveType=$1;}
     | mc_real {saveType=$1;}
     | mc_logical {saveType=$1;}
     | mc_character {saveType=$1;}
;

PARAMETRE :   IDF 
            | IDF vrg PARAMETRE
            | IDF po TAILLE pf 
            | IDF po TAILLE pf PARAMETRE 
            
;



BODY : DEC INST 
;
	
DEC:     TYPE  IDF {modifyType($2,saveType)} ListIDF pvg DEC
        |

;

ListIDF: vrg IDF {modifyType($2,saveType)} ListIDF
        | mc_dimension po TAILLE pf 
        | mc_dimension po TAILLE pf  vrg ListIDF
        | mul integr
        |
;

	
TAILLE : integr
        | integr vrg integr
;



PROGRAM : mc_program IDF BODY mc_end
;


INST :    AFFECTATION pvg INST
        | ES pvg INST
	    | CONDITON INST
	    | LOOP pvg INST
	    | CALLING pvg INST
	    | EQUIV pvg INST
        |
;



AFFECTATION : IDF aff EXPRESSION INST{printTypeOfIDF($1);}
            | IDF aff CHAINE INST{printTypeOfIDF($1);}
            | IDF aff LOGICAL INST{printTypeOfIDF($1);}
;

EXPRESSION :  VALEUR
            | VALEUR OPERATION EXPRESSION 
            | po EXPRESSION pf OPERATION EXPRESSION
            | po EXPRESSION pf
;

VALEUR :      IDF TAB {printTypeOfIDF($1);}
            | NUMBER 
            | IDF {printTypeOfIDF($1);}
;

TAB :       po TAILLE pf 
;

NUMBER:     integr | floatt
;

OPERATION : add | sub | mul | divv
;

CHAINE :    string 
;

LOGICAL :   mc_true | mc_false
;

ES :        mc_read po IDF pf 
          | mc_write po STRING pf 
;

STRING :    CHAINE vrg IDF vrg CHAINE
          | CHAINE
;

CONDITON :  mc_if po EXPCDTT pf mc_then INST mc_else INST mc_endif
;

EXPCDTT :     EXPRESSION
            | EXPRESSION  CDTT EXPCDTT  
            | LOGICAL
            | po EXPCDTT pf CDTT po EXPCDTT pf 
;

CDTT :      point CDT point
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

LOOP:       mc_dowhile po EXPCDTT pf INST mc_enddo 
;

CALLING :   IDF aff mc_call IDF po PARAMETRE pf 
;

EQUIV:      mc_equivalence po PARAMETRE pf vrg po PARAMETRE pf 
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
    afficher(0);
    
    return 0;
}
yywrap ()
{}
int yyerror ( char*  msg )  
{
       printf ("Erreur Syntaxique : fichier %s , ligne %d , colonne %d \n", filename,nb_ligne,col);
}

