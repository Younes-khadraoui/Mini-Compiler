%{
       #include <stdio.h>
       #include<stdlib.h>
       #include<string.h>
       int nb_ligne=1, col=1,tss=0;
       extern FILE *yyin;
       char* saveType;
       char *returnedType;
       char typeval[25];
       char *filename;
%}

%union {
         int     entier;
         char*   str;
         float reel;

}

%token  <str>mc_program <str>mc_routine  <str>mc_entier  <str>string  booleen
        <str>mc_real <str>mc_logical <str>mc_character <str>mc_dimension 
        <str>mc_read <str>mc_write <str>mc_if <str>mc_then <str>mc_else <str>mc_endif 
        <str>mc_dowhile <str>mc_enddo <str>mc_or <str>mc_and <str>mc_gt <str>mc_ge <str>mc_eq 
        <str>mc_ne <str>mc_le <str>mc_lt <str>mc_call <str>mc_endr <str>mc_end <str>IDF <entier>integr <reel>floatt
        <str>add <str>sub <str>mul <str>divv <str>pvg  <str>vrg <str>aff <str>po <str>pf  <str>mc_equivalence  <str>point

%type <str> TYPE OPERATION CHAINE LOGICAL


%start S
%left add sub
%left mul divv


%%

S: FUNCTION | PROGRAM {printf("prog syntaxiquement correct"); YYACCEPT;}
;

FUNCTION : HEADER BODY mc_endr {rechercher ($3,"Mot cle ","",0, 1,tss);tss++; }S  
;

HEADER : TYPE mc_routine IDF po PARAMETRE pf { rechercher ($2,"Mot cle ","",0, 1,tss); rechercher ($3,"IDF","Identifier",0 , 0,tss);modifyType($3,saveType,tss); rechercher ($4,"Separateur",0,0, 2,tss); rechercher ($6,"Separateur",0,0, 2,tss);}  
;

TYPE:  mc_entier {saveType=$1;rechercher ($1,"Mot cle ","",0, 1,tss);}
     | mc_real {saveType=$1;rechercher ($1,"Mot cle ","",0, 1,tss);}
     | mc_logical {saveType=$1;rechercher ($1,"Mot cle ","",0, 1,tss);}
     | mc_character {saveType=$1;rechercher ($1,"Mot cle ","",0, 1,tss);}
;

PARAMETRE :   IDF {rechercher ($1,"IDF","Identifier",0 , 0,tss);}       
            | IDF vrg  PARAMETRE {rechercher ($1,"IDF","Identifier",0 , 0,tss); rechercher ($2,"Separateur",0,0, 2,tss); }
            | IDF po TAILLE pf {rechercher ($1,"IDF","Identifier",0 , 0,tss);rechercher ($2,"Separateur",0,0, 2,tss);rechercher ($4,"Separateur",0,0, 2,tss);}
            | IDF po TAILLE pf PARAMETRE {rechercher ($1,"IDF","Identifier",0 , 0,tss);rechercher ($2,"Separateur",0,0, 2,tss);rechercher ($4,"Separateur",0,0, 2,tss);}            
;



BODY : DEC INST 
;
	
DEC:     TYPE  IDF{rechercher ($2,"IDF","Identifier",0 , 0,tss); modifyType($2,saveType,tss);  } ListIDF pvg  {rechercher ($5,"Separateur",0,0, 2,tss);} DEC 
        |

;

ListIDF: vrg IDF  ListIDF { rechercher ($1,"Separateur",0,0, 2,tss); rechercher ($2,"IDF","Identifier",0 , 0,tss); modifyType($2,saveType,tss); }
        | mc_dimension po TAILLE pf {rechercher ($1,"Mot cle ","",0, 1,tss);rechercher ($2,"Separateur",0,0, 2,tss); rechercher ($4,"Separateur",0,0, 2,tss);}
        | mc_dimension po TAILLE pf  vrg ListIDF {rechercher ($1,"Mot cle ","",0, 1,tss);rechercher ($2,"Separateur",0,0, 2,tss); rechercher ($4,"Separateur",0,0, 2,tss); rechercher ($5,"Separateur",0,0, 2,tss);}
        | mul integr {rechercher ($1,"Separateur",0,0, 2,tss);}
        |
;

	
TAILLE : integr
        | integr vrg integr{rechercher ($2,"Separateur",0,0, 2,tss);}
;



PROGRAM : mc_program IDF BODY mc_end {rechercher ($1,"Mot cle ","",0, 1,tss); rechercher ($2,"IDF","Identifier",0 , 0,tss); rechercher ($4,"Mot cle ","",0, 1,tss); }
;


INST :    AFFECTATION pvg INST {rechercher ($2,"Separateur",0,0, 2,tss);}
        | ES pvg INST{rechercher ($2,"Separateur",0,0, 2,tss);}
	    | CONDITON INST 
	    | LOOP pvg INST {rechercher ($2,"Separateur",0,0, 2,tss);}
	    | CALLING pvg INST {rechercher ($2,"Separateur",0,0, 2,tss);}
	    | EQUIV pvg INST {rechercher ($2,"Separateur",0,0, 2,tss);}
        |
;



AFFECTATION : IDF aff EXPRESSION INST{rechercher1 ($1,"IDF","Identifier",0 , 0,tss);printf("%s \t",printTypeOfIDF($1)); printf("%s \t %s \n",$1,typeval); if (incompatibiliteDeType($1,typeval) == 1) printf("Erreur semantique: Incompatibilite de type a la ligne %d colonne %d\n", nb_ligne, col); rechercher ($2,"Separateur",0,0, 2,tss);}
            | IDF aff CHAINE INST{rechercher1 ($1,"IDF","Identifier",0 , 0,tss); printf("%s \t %s \n",$1,typeval);if (incompatibiliteDeType($1,typeval) == 1) printf("Erreur semantique: Incompatibilite de type a la ligne %d colonne %d\n", nb_ligne, col); rechercher ($2,"Separateur",0,0, 2,tss);}
            | IDF aff LOGICAL INST{rechercher1 ($1,"IDF","Identifier",0 , 0,tss);  printf("%s \t %s \n",$1,typeval);if (incompatibiliteDeType($1,typeval) == 1) printf("Erreur semantique: Incompatibilite de type a la ligne %d colonne %d\n", nb_ligne, col); rechercher ($2,"Separateur",0,0, 2,tss);}
;

EXPRESSION :  VALEUR
            | VALEUR OPERATION EXPRESSION 
            | po EXPRESSION pf OPERATION EXPRESSION {rechercher ($1,"Separateur",0,0, 2,tss); rechercher ($3,"Separateur",0,0, 2,tss);}
            | po EXPRESSION pf{rechercher ($1,"Separateur",0,0, 2,tss);rechercher ($3,"Separateur",0,0, 2,tss);}
;

VALEUR :      IDF TAB {returnedType =printTypeOfIDF($1); strcpy(typeval,returnedType); rechercher1 ($1,"IDF","Identifier",0 , 0,tss); }
            | NUMBER 
            | IDF {returnedType =printTypeOfIDF($1); strcpy(typeval,returnedType); rechercher1 ($1,"IDF","Identifier",0 , 0,tss); }
;

TAB :       po TAILLE pf {rechercher ($1,"Separateur",0,0, 2,tss); rechercher ($3,"Separateur",0,0, 2,tss);}
;

NUMBER:     integr {strcpy(typeval,"INTEGER");} | floatt {strcpy(typeval,"REAL");}
;

OPERATION : add {rechercher ($1,"Separateur",0,0, 2,tss);}| sub{rechercher ($1,"Separateur",0,0, 2,tss);} | mul{rechercher ($1,"Separateur",0,0, 2,tss);} | divv{rechercher ($1,"Separateur",0,0, 2,tss);}
;

CHAINE :    string {strcpy(typeval,"CHARACTER");}
;

LOGICAL :  booleen{strcpy(typeval,"LOGICAL");} 
;

ES :        mc_read po IDF pf {rechercher ($1,"Mot cle ","",0, 1,tss); rechercher ($2,"Separateur",0,0, 2,tss);rechercher1 ($3,"IDF","Identifier",0 , 0,tss); rechercher ($4,"Separateur",0,0, 2,tss);}
          | mc_write po STRING pf {rechercher ($1,"Mot cle ","",0, 1,tss); rechercher ($2,"Separateur",0,0, 2,tss); rechercher ($4,"Separateur",0,0, 2,tss);}
;

STRING :    CHAINE vrg IDF vrg CHAINE {rechercher ($2,"Separateur",0,0, 2,tss);rechercher1 ($3,"IDF","Identifier",0 , 0,tss); rechercher ($4,"Separateur",0,0, 2,tss);}
          | CHAINE
;

CONDITON :  mc_if po EXPCDTT pf mc_then INST mc_else INST mc_endif {rechercher ($1,"Mot cle ","",0, 1,tss); rechercher ($2,"Separateur",0,0, 2,tss); rechercher ($4,"Separateur",0,0, 2,tss);rechercher ($5,"Mot cle ","",0, 1,tss);rechercher ($7,"Mot cle ","",0, 1,tss);rechercher ($9,"Mot cle ","",0, 1,tss);}
;

EXPCDTT :     EXPRESSION
            | EXPRESSION  CDTT EXPCDTT  
            | LOGICAL
            | po EXPCDTT pf CDTT po EXPCDTT pf {rechercher ($1,"Separateur",0,0, 2,tss); rechercher ($3,"Separateur",0,0, 2,tss);rechercher ($5,"Separateur",0,0, 2,tss);rechercher ($7,"Separateur",0,0, 2,tss);}
;

CDTT :      point CDT point {rechercher ($1,"Separateur",0,0, 2,tss); rechercher ($3,"Separateur",0,0, 2,tss);}
;
CDT :         mc_eq {rechercher ($1,"Mot cle ","",0, 1,tss);}
            | mc_ne {rechercher ($1,"Mot cle ","",0, 1,tss);}
            | mc_ge {rechercher ($1,"Mot cle ","",0, 1,tss);}
            | mc_gt {rechercher ($1,"Mot cle ","",0, 1,tss);}
            | mc_le {rechercher ($1,"Mot cle ","",0, 1,tss);}
            | mc_lt {rechercher ($1,"Mot cle ","",0, 1,tss);}
            | mc_and {rechercher ($1,"Mot cle ","",0, 1,tss);}
            | mc_or {rechercher ($1,"Mot cle ","",0, 1,tss);}
;

LOOP:       mc_dowhile po EXPCDTT pf INST mc_enddo {rechercher ($1,"Mot cle ","",0, 1,tss); rechercher ($2,"Separateur",0,0, 2,tss);rechercher ($4,"Separateur",0,0, 2,tss);rechercher ($6,"Mot cle ","",0, 1,tss);}
;

CALLING :   IDF aff mc_call IDF po PARAMETRE1 pf {rechercher1 ($1,"IDF","Identifier",0 , 0,tss); rechercher ($2,"Separateur",0,0, 2,tss);rechercher ($3,"Mot cle ","",0, 1,tss);rechercher ($5,"Separateur",0,0, 2,tss);rechercher ($7,"Separateur",0,0, 2,tss);}
;

EQUIV:      mc_equivalence po PARAMETRE1 pf vrg po PARAMETRE1 pf {rechercher ($1,"Mot cle ","",0, 1,tss);rechercher ($4,"Separateur",0,0, 2,tss);rechercher ($5,"Separateur",0,0, 2,tss);rechercher ($6,"Separateur",0,0, 2,tss);rechercher ($8,"Separateur",0,0, 2,tss);}
;
PARAMETRE1 :   IDF {rechercher1 ($1,"IDF","Identifier",0 , 0,tss);}       
            | IDF vrg  PARAMETRE1 {rechercher1 ($1,"IDF","Identifier",0 , 0,tss); rechercher ($2,"Separateur",0,0, 2,tss); }
            | IDF po TAILLE pf {rechercher1 ($1,"IDF","Identifier",0 , 0,tss);rechercher ($2,"Separateur",0,0, 2,tss);rechercher ($4,"Separateur",0,0, 2,tss);}
            | IDF po TAILLE pf PARAMETRE1 {rechercher1 ($1,"IDF","Identifier",0 , 0,tss);rechercher ($2,"Separateur",0,0, 2,tss);rechercher ($4,"Separateur",0,0, 2,tss);}            
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

