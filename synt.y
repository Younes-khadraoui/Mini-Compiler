%{
       #include <stdio.h>
       #include<stdlib.h>
       #include<string.h>
       int nb_ligne=1, col=1,ts=0;
       extern FILE *yyin;
       char* saveType;
       char *filename;
%}

%union {
         int     entier;
         char*   str;
         float reel;

}

%token  <str>mc_program <str>mc_routine  <str>mc_entier  <str>string mc_true mc_false
        <str>mc_real <str>mc_logical <str>mc_character <str>mc_dimension 
        <str>mc_read <str>mc_write <str>mc_if <str>mc_then <str>mc_else <str>mc_endif 
        <str>mc_dowhile <str>mc_enddo <str>mc_or <str>mc_and <str>mc_gt <str>mc_ge <str>mc_eq 
        <str>mc_ne <str>mc_le <str>mc_lt <str>mc_call <str>mc_endr <str>mc_end <str>IDF <entier>integr <reel>floatt
        <str>add <str>sub <str>mul <str>divv <str>pvg  <str>vrg <str>aff <str>po <str>pf  <str>mc_equivalence  <str>point

%type <str> TYPE 


%start S
%left add sub
%left mul divv


%%

S: FUNCTION | PROGRAM {printf("prog syntaxiquement correct"); YYACCEPT;}
;

FUNCTION : HEADER BODY mc_endr S {rechercher ($3,"Mot cle ","",0, 1); ts = ts + 1} 
;

HEADER : TYPE mc_routine IDF po PARAMETRE pf {modifyType($3,$1,ts); rechercher ($2,"Mot cle ","",0, 1); rechercher ($4,"Separateur",0,0, 2); rechercher ($6,"Separateur",0,0, 2);}  
;

TYPE:  mc_entier {saveType=$1;rechercher ($1,"Mot cle ","",0, 1);}
     | mc_real {saveType=$1;rechercher ($1,"Mot cle ","",0, 1);}
     | mc_logical {saveType=$1;rechercher ($1,"Mot cle ","",0, 1);}
     | mc_character {saveType=$1;rechercher ($1,"Mot cle ","",0, 1);}
;

PARAMETRE :   IDF 
            | IDF vrg  PARAMETRE {rechercher ($2,"Separateur",0,0, 2);}
            | IDF po TAILLE pf {rechercher ($2,"Separateur",0,0, 2);rechercher ($4,"Separateur",0,0, 2);}
            | IDF po TAILLE pf PARAMETRE {rechercher ($2,"Separateur",0,0, 2);rechercher ($4,"Separateur",0,0, 2);}
            
;



BODY : DEC INST 
;
	
DEC:     TYPE  IDF ListIDF pvg DEC  {modifyType($2,saveType,ts); rechercher ($4,"Separateur",0,0, 2);}
        |

;

ListIDF: vrg IDF  ListIDF {modifyType($2,saveType,ts); rechercher ($1,"Separateur",0,0, 2);}
        | mc_dimension po TAILLE pf {rechercher ($1,"Mot cle ","",0, 1);rechercher ($2,"Separateur",0,0, 2); rechercher ($4,"Separateur",0,0, 2);}
        | mc_dimension po TAILLE pf  vrg ListIDF {rechercher ($1,"Mot cle ","",0, 1);rechercher ($2,"Separateur",0,0, 2); rechercher ($4,"Separateur",0,0, 2); rechercher ($5,"Separateur",0,0, 2);}
        | mul integr {rechercher ($1,"Separateur",0,0, 2);}
        |
;

	
TAILLE : integr
        | integr vrg integr{rechercher ($2,"Separateur",0,0, 2);}
;



PROGRAM : mc_program IDF BODY mc_end {rechercher ($1,"Mot cle ","",0, 1);rechercher ($4,"Mot cle ","",0, 1); ts = 0;}
;


INST :    AFFECTATION pvg INST {rechercher ($2,"Separateur",0,0, 2);}
        | ES pvg INST{rechercher ($2,"Separateur",0,0, 2);}
	    | CONDITON INST 
	    | LOOP pvg INST {rechercher ($2,"Separateur",0,0, 2);}
	    | CALLING pvg INST {rechercher ($2,"Separateur",0,0, 2);}
	    | EQUIV pvg INST {rechercher ($2,"Separateur",0,0, 2);}
        |
;



AFFECTATION : IDF aff EXPRESSION INST{printTypeOfIDF($1); rechercher ($2,"Separateur",0,0, 2);}
            | IDF aff CHAINE INST{printTypeOfIDF($1);rechercher ($2,"Separateur",0,0, 2);}
            | IDF aff LOGICAL INST{printTypeOfIDF($1);rechercher ($2,"Separateur",0,0, 2);}
;

EXPRESSION :  VALEUR
            | VALEUR OPERATION EXPRESSION 
            | po EXPRESSION pf OPERATION EXPRESSION {rechercher ($1,"Separateur",0,0, 2); rechercher ($3,"Separateur",0,0, 2);}
            | po EXPRESSION pf{rechercher ($1,"Separateur",0,0, 2);rechercher ($3,"Separateur",0,0, 2);}
;

VALEUR :      IDF TAB {printTypeOfIDF($1);}
            | NUMBER 
            | IDF {printTypeOfIDF($1);}
;

TAB :       po TAILLE pf {rechercher ($1,"Separateur",0,0, 2); rechercher ($3,"Separateur",0,0, 2);}
;

NUMBER:     integr | floatt
;

OPERATION : add {rechercher ($1,"Separateur",0,0, 2);}| sub{rechercher ($1,"Separateur",0,0, 2);} | mul{rechercher ($1,"Separateur",0,0, 2);} | divv{rechercher ($1,"Separateur",0,0, 2);}
;

CHAINE :    string 
;

LOGICAL :   mc_true {rechercher ($1,"Mot cle ","",0, 1);} | mc_false {rechercher ($1,"Mot cle ","",0, 1);}
;

ES :        mc_read po IDF pf {rechercher ($1,"Mot cle ","",0, 1); rechercher ($2,"Separateur",0,0, 2); rechercher ($4,"Separateur",0,0, 2);}
          | mc_write po STRING pf {rechercher ($1,"Mot cle ","",0, 1); rechercher ($2,"Separateur",0,0, 2); rechercher ($4,"Separateur",0,0, 2);}
;

STRING :    CHAINE vrg IDF vrg CHAINE {rechercher ($2,"Separateur",0,0, 2); rechercher ($4,"Separateur",0,0, 2);}
          | CHAINE
;

CONDITON :  mc_if po EXPCDTT pf mc_then INST mc_else INST mc_endif {rechercher ($1,"Mot cle ","",0, 1); rechercher ($2,"Separateur",0,0, 2); rechercher ($4,"Separateur",0,0, 2);rechercher ($5,"Mot cle ","",0, 1);rechercher ($7,"Mot cle ","",0, 1);rechercher ($9,"Mot cle ","",0, 1);}
;

EXPCDTT :     EXPRESSION
            | EXPRESSION  CDTT EXPCDTT  
            | LOGICAL
            | po EXPCDTT pf CDTT po EXPCDTT pf {rechercher ($1,"Separateur",0,0, 2); rechercher ($3,"Separateur",0,0, 2);rechercher ($5,"Separateur",0,0, 2);rechercher ($7,"Separateur",0,0, 2);}
;

CDTT :      point CDT point {rechercher ($1,"Separateur",0,0, 2); rechercher ($3,"Separateur",0,0, 2);}
;
CDT :         mc_eq {rechercher ($1,"Mot cle ","",0, 1);}
            | mc_ne {rechercher ($1,"Mot cle ","",0, 1);}
            | mc_ge {rechercher ($1,"Mot cle ","",0, 1);}
            | mc_gt {rechercher ($1,"Mot cle ","",0, 1);}
            | mc_le {rechercher ($1,"Mot cle ","",0, 1);}
            | mc_lt {rechercher ($1,"Mot cle ","",0, 1);}
            | mc_and {rechercher ($1,"Mot cle ","",0, 1);}
            | mc_or {rechercher ($1,"Mot cle ","",0, 1);}
;

LOOP:       mc_dowhile po EXPCDTT pf INST mc_enddo {rechercher ($1,"Mot cle ","",0, 1); rechercher ($2,"Separateur",0,0, 2);rechercher ($4,"Separateur",0,0, 2);rechercher ($6,"Mot cle ","",0, 1);}
;

CALLING :   IDF aff mc_call IDF po PARAMETRE pf { rechercher ($2,"Separateur",0,0, 2);rechercher ($3,"Mot cle ","",0, 1);rechercher ($5,"Separateur",0,0, 2);rechercher ($7,"Separateur",0,0, 2);}
;

EQUIV:      mc_equivalence po PARAMETRE pf vrg po PARAMETRE pf {rechercher ($1,"Mot cle ","",0, 1);rechercher ($4,"Separateur",0,0, 2);rechercher ($5,"Separateur",0,0, 2);rechercher ($6,"Separateur",0,0, 2);rechercher ($8,"Separateur",0,0, 2);}
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

