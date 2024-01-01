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

FUNCTION : HEADER BODY mc_endr S {rechercher ($3,"Mot cle ","",0, 1,ts); } 
;

HEADER : TYPE mc_routine IDF po PARAMETRE pf {modifyType($3,$1,ts); rechercher ($2,"Mot cle ","",0, 1,ts); rechercher ($4,"Separateur",0,0, 2,ts); rechercher ($6,"Separateur",0,0, 2,ts);}  
;

TYPE:  mc_entier {saveType=$1;rechercher ($1,"Mot cle ","",0, 1,ts);}
     | mc_real {saveType=$1;rechercher ($1,"Mot cle ","",0, 1,ts);}
     | mc_logical {saveType=$1;rechercher ($1,"Mot cle ","",0, 1,ts);}
     | mc_character {saveType=$1;rechercher ($1,"Mot cle ","",0, 1,ts);}
;

PARAMETRE :   IDF 
            | IDF vrg  PARAMETRE {rechercher ($2,"Separateur",0,0, 2,ts);}
            | IDF po TAILLE pf {rechercher ($2,"Separateur",0,0, 2,ts);rechercher ($4,"Separateur",0,0, 2,ts);}
            | IDF po TAILLE pf PARAMETRE {rechercher ($2,"Separateur",0,0, 2,ts);rechercher ($4,"Separateur",0,0, 2,ts);}
            
;



BODY : DEC INST 
;
	
DEC:     TYPE  IDF ListIDF pvg DEC  {modifyType($2,saveType,ts); rechercher ($4,"Separateur",0,0, 2,ts);}
        |

;

ListIDF: vrg IDF  ListIDF {modifyType($2,saveType,ts); rechercher ($1,"Separateur",0,0, 2,ts);}
        | mc_dimension po TAILLE pf {rechercher ($1,"Mot cle ","",0, 1,ts);rechercher ($2,"Separateur",0,0, 2,ts); rechercher ($4,"Separateur",0,0, 2,ts);}
        | mc_dimension po TAILLE pf  vrg ListIDF {rechercher ($1,"Mot cle ","",0, 1,ts);rechercher ($2,"Separateur",0,0, 2,ts); rechercher ($4,"Separateur",0,0, 2,ts); rechercher ($5,"Separateur",0,0, 2,ts);}
        | mul integr {rechercher ($1,"Separateur",0,0, 2,ts);}
        |
;

	
TAILLE : integr
        | integr vrg integr{rechercher ($2,"Separateur",0,0, 2,ts);}
;



PROGRAM : mc_program IDF BODY mc_end {rechercher ($1,"Mot cle ","",0, 1,ts);rechercher ($4,"Mot cle ","",0, 1,ts); }
;


INST :    AFFECTATION pvg INST {rechercher ($2,"Separateur",0,0, 2,ts);}
        | ES pvg INST{rechercher ($2,"Separateur",0,0, 2,ts);}
	    | CONDITON INST 
	    | LOOP pvg INST {rechercher ($2,"Separateur",0,0, 2,ts);}
	    | CALLING pvg INST {rechercher ($2,"Separateur",0,0, 2,ts);}
	    | EQUIV pvg INST {rechercher ($2,"Separateur",0,0, 2,ts);}
        |
;



AFFECTATION : IDF aff EXPRESSION INST{printTypeOfIDF($1); rechercher ($2,"Separateur",0,0, 2,ts);}
            | IDF aff CHAINE INST{printTypeOfIDF($1);rechercher ($2,"Separateur",0,0, 2,ts);}
            | IDF aff LOGICAL INST{printTypeOfIDF($1);rechercher ($2,"Separateur",0,0, 2,ts);}
;

EXPRESSION :  VALEUR
            | VALEUR OPERATION EXPRESSION 
            | po EXPRESSION pf OPERATION EXPRESSION {rechercher ($1,"Separateur",0,0, 2,ts); rechercher ($3,"Separateur",0,0, 2,ts);}
            | po EXPRESSION pf{rechercher ($1,"Separateur",0,0, 2,ts);rechercher ($3,"Separateur",0,0, 2,ts);}
;

VALEUR :      IDF TAB {printTypeOfIDF($1);}
            | NUMBER 
            | IDF {printTypeOfIDF($1);}
;

TAB :       po TAILLE pf {rechercher ($1,"Separateur",0,0, 2,ts); rechercher ($3,"Separateur",0,0, 2,ts);}
;

NUMBER:     integr | floatt
;

OPERATION : add {rechercher ($1,"Separateur",0,0, 2,ts);}| sub{rechercher ($1,"Separateur",0,0, 2,ts);} | mul{rechercher ($1,"Separateur",0,0, 2,ts);} | divv{rechercher ($1,"Separateur",0,0, 2,ts);}
;

CHAINE :    string 
;

LOGICAL :   mc_true {rechercher ($1,"Mot cle ","",0, 1,ts);} | mc_false {rechercher ($1,"Mot cle ","",0, 1,ts);}
;

ES :        mc_read po IDF pf {rechercher ($1,"Mot cle ","",0, 1,ts); rechercher ($2,"Separateur",0,0, 2,ts); rechercher ($4,"Separateur",0,0, 2,ts);}
          | mc_write po STRING pf {rechercher ($1,"Mot cle ","",0, 1,ts); rechercher ($2,"Separateur",0,0, 2,ts); rechercher ($4,"Separateur",0,0, 2,ts);}
;

STRING :    CHAINE vrg IDF vrg CHAINE {rechercher ($2,"Separateur",0,0, 2,ts); rechercher ($4,"Separateur",0,0, 2,ts);}
          | CHAINE
;

CONDITON :  mc_if po EXPCDTT pf mc_then INST mc_else INST mc_endif {rechercher ($1,"Mot cle ","",0, 1,ts); rechercher ($2,"Separateur",0,0, 2,ts); rechercher ($4,"Separateur",0,0, 2,ts);rechercher ($5,"Mot cle ","",0, 1,ts);rechercher ($7,"Mot cle ","",0, 1,ts);rechercher ($9,"Mot cle ","",0, 1,ts);}
;

EXPCDTT :     EXPRESSION
            | EXPRESSION  CDTT EXPCDTT  
            | LOGICAL
            | po EXPCDTT pf CDTT po EXPCDTT pf {rechercher ($1,"Separateur",0,0, 2,ts); rechercher ($3,"Separateur",0,0, 2,ts);rechercher ($5,"Separateur",0,0, 2,ts);rechercher ($7,"Separateur",0,0, 2,ts);}
;

CDTT :      point CDT point {rechercher ($1,"Separateur",0,0, 2,ts); rechercher ($3,"Separateur",0,0, 2,ts);}
;
CDT :         mc_eq {rechercher ($1,"Mot cle ","",0, 1,ts);}
            | mc_ne {rechercher ($1,"Mot cle ","",0, 1,ts);}
            | mc_ge {rechercher ($1,"Mot cle ","",0, 1,ts);}
            | mc_gt {rechercher ($1,"Mot cle ","",0, 1,ts);}
            | mc_le {rechercher ($1,"Mot cle ","",0, 1,ts);}
            | mc_lt {rechercher ($1,"Mot cle ","",0, 1,ts);}
            | mc_and {rechercher ($1,"Mot cle ","",0, 1,ts);}
            | mc_or {rechercher ($1,"Mot cle ","",0, 1,ts);}
;

LOOP:       mc_dowhile po EXPCDTT pf INST mc_enddo {rechercher ($1,"Mot cle ","",0, 1,ts); rechercher ($2,"Separateur",0,0, 2,ts);rechercher ($4,"Separateur",0,0, 2,ts);rechercher ($6,"Mot cle ","",0, 1,ts);}
;

CALLING :   IDF aff mc_call IDF po PARAMETRE pf { rechercher ($2,"Separateur",0,0, 2,ts);rechercher ($3,"Mot cle ","",0, 1,ts);rechercher ($5,"Separateur",0,0, 2,ts);rechercher ($7,"Separateur",0,0, 2,ts);}
;

EQUIV:      mc_equivalence po PARAMETRE pf vrg po PARAMETRE pf {rechercher ($1,"Mot cle ","",0, 1,ts);rechercher ($4,"Separateur",0,0, 2,ts);rechercher ($5,"Separateur",0,0, 2,ts);rechercher ($6,"Separateur",0,0, 2,ts);rechercher ($8,"Separateur",0,0, 2,ts);}
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