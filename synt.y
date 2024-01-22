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
       float idfValue;
       char idfNewValue[20];
       int qc=0;
       int resultI;
       float resultF;
       
       int jj=0;
       int kk=0;
       int c=0;
       int nb11=0,nb22=0,nb33=0,nb44=0;
       int i=0;
       float idfNewValue1;
       int idfNewValue2;
       int zz=0 ;
       int xx1=0;
       int bb = 0 ;
       int vv=0;
       int vv1=0;
       char xx[20] ;
       char chaine1[20];
       int intIdfNewValue;


	int err = 0;
	int h = 0;
	int Fin_if=0,Fin_while=0, Deb_while=0,OP = 0,and_b=0,and_f=0,or_b=0,or_f=0,debu=0,deb_for=0;
	char L[25],Q[25];
	char temp1[25] = "TEMP";
	char opera[5]; 
	char saveOP[25];
	char saveOpLo[25];
	char tmp[25];
	char med[25];
	char med2[25];
	char op1[25];
	char op2[25];
	char medOp[25];
	char tempMul[25];
	char resultL[25];
	char s[25];
	char medType[25];
    int fin_if[10];
	int i_if=0;
    int deb_else[10];
	int i_else=0;	
	int lol = 0;
	int Cond = 0;
	int medL=0;
	int indentation = 0;
	int mustBe = 0;
	int mull=0;
	int x=0;
	int AND_or_OR = 0;
	int only_one = 0;
	int first =0;
	int teemp = 0;
	int p = 0;
	int o = 0;
	int a = 0;
        int value2,value1;	
	char saveCst[25];
	char sauvIdf1[25];
	char sauvIdf[2][10] = {};	
        int nbLigne=1; 
        int nbCol=1; //declaraction du cpt de nombre de colonne
        int callIndex=-1;
        int nbParams=0;
%}

%union {
         int     entier;
         char*   str;
         float reel;

}

%token  <str>mc_program <str>mc_routine  <str>mc_entier  <str>string  <str>booleen
        <str>mc_real <str>mc_logical <str>mc_character <str>mc_dimension 
        <str>mc_read <str>mc_write <str>mc_if <str>mc_then <str>mc_else <str>mc_endif 
        <str>mc_dowhile <str>mc_enddo <str>mc_or <str>mc_and <str>mc_gt <str>mc_ge <str>mc_eq 
        <str>mc_ne <str>mc_le <str>mc_lt <str>mc_call <str>mc_endr <str>mc_end <str>IDF <entier>integr <reel>floatt
        <str>add <str>sub <str>mul <str>divv <str>pvg  <str>vrg <str>aff <str>po <str>pf  <str>mc_equivalence  <str>point

%type <str> TYPE OPERATION CHAINE LOGICAL 


%start S
%left add sub
%left mul divv
%left mc_or
%left mc_and
%left mc_gt mc_ge mc_lt mc_le mc_eq mc_ne

%%

S: FUNCTION | PROGRAM {printf("prog syntaxiquement correct"); YYACCEPT;}
;

FUNCTION : HEADER BODY mc_endr {rechercher ($3,"Mot cle ","","0", 1,tss);tss++; }S  
;

HEADER : TYPE mc_routine IDF po PARAMETRE pf { 
        callIndex++; 
        initializeCall(callIndex,$3,3);
        rechercher ($2,"Mot cle ","","0", 1,tss); 
        rechercher ($3,"IDF","Identifier","0", 0,tss);
        modifyType($3,saveType,tss); 
        rechercher ($4,"Separateur","0","0", 2,tss); 
        rechercher ($6,"Separateur","0","0", 2,tss);
}  
;

TYPE:  mc_entier {saveType=$1;rechercher ($1,"Mot cle ","","0", 1,tss);}
     | mc_real {saveType=$1;rechercher ($1,"Mot cle ","","0", 1,tss);}
     | mc_logical {saveType=$1;rechercher ($1,"Mot cle ","","0", 1,tss);}
     | mc_character {saveType=$1;rechercher ($1,"Mot cle ","","0", 1,tss);}
;

PARAMETRE :   IDF {rechercher ($1,"IDF","Identifier","0", 0,tss); nbParams++;}       
            | IDF vrg  PARAMETRE {rechercher ($1,"IDF","Identifier","0", 0,tss); rechercher ($2,"Separateur","0","0", 2,tss); }
            | IDF po TAILLE pf {rechercher ($1,"IDF","Identifier","0", 0,tss);rechercher ($2,"Separateur","0","0", 2,tss);rechercher ($4,"Separateur","0","0", 2,tss);}
            | IDF po TAILLE pf PARAMETRE {rechercher ($1,"IDF","Identifier","0", 0,tss);rechercher ($2,"Separateur","0","0", 2,tss);rechercher ($4,"Separateur","0","0", 2,tss);}            
;



BODY : DEC INST 
;
	
DEC:     TYPE  IDF{rechercher ($2,"IDF","Identifier","0", 0,tss); modifyType($2,saveType,tss);  } ListIDF pvg  {rechercher ($5,"Separateur","0","0", 2,tss);sprintf(chaine1, "%d",(int)idfNewValue1);if(zz == 1)Misajour($2,(int)tss,chaine1) ;if(kk == 1)modmat($2,nb11,nb22,i);kk=0;if(bb == 1)i++;} DEC 
        |

;

ListIDF: vrg IDF  ListIDF { rechercher ($1,"Separateur","0","0", 2,tss); rechercher ($2,"IDF","Identifier","0", 0,tss); modifyType($2,saveType,tss); }
        | mc_dimension po TAILLE pf {rechercher ($1,"Mot cle ","","0", 1,tss);rechercher ($2,"Separateur","0","0", 2,tss); rechercher ($4,"Separateur","0","0", 2,tss);zz=1;}
        | mc_dimension po TAILLE pf  vrg ListIDF {rechercher ($1,"Mot cle ","","0", 1,tss);rechercher ($2,"Separateur","0","0", 2,tss); rechercher ($4,"Separateur","0","0", 2,tss); rechercher ($5,"Separateur","0","0", 2,tss);}
        | mul integr {rechercher ($1,"Separateur","0","0", 2,tss);}
        |
;


	
TAILLE : integr {strcpy(typeval,"INTEGER");  if($1<0 ){printf("Erreur semantique : Indice Negatif %d,%d\n",nb_ligne,nbCol);exit(EXIT_FAILURE);}intIdfNewValue = $1 ;idfNewValue1 = (int)intIdfNewValue;;intIdfNewValue = $1 ;idfNewValue2 = (int)intIdfNewValue;vv1=1;bb=0;}
        | integr vrg integr{rechercher ($2,"Separateur","0","0", 2,tss);if($1<0 || $3<0) {printf("Erreur semantique : Indice Negatif %d,%d\n",nb_ligne,nbCol); exit(EXIT_FAILURE); }intIdfNewValue = $1 ;nb11 = (int)intIdfNewValue; intIdfNewValue = $3 ;nb22 = (int)intIdfNewValue;vv1=0;if(c==1)bb=1;c=1;kk=1}
;



PROGRAM : mc_program IDF BODY mc_end {rechercher ($1,"Mot cle ","","0", 1,tss); rechercher ($2,"IDF","Identifier","0", 0,tss); rechercher ($4,"Mot cle ","","0", 1,tss); }
;


INST :    AFFECTATION pvg INST {rechercher ($2,"Separateur","0","0", 2,tss);}
        | ES pvg INST{rechercher ($2,"Separateur","0","0", 2,tss);}
        | CONDITON INST 
        | LOOP pvg INST {rechercher ($2,"Separateur","0","0", 2,tss);}
        | CALLING pvg INST {rechercher ($2,"Separateur","0","0", 2,tss);}
        | EQUIV pvg INST {rechercher ($2,"Separateur","0","0", 2,tss);}
        |
;



AFFECTATION : IDF aff EXPRESSION INST{
                rechercher1 ($1,"IDF","Identifier","0", 0,tss); 
                if (incompatibiliteDeType($1,typeval,tss) == 1) {
                        printf("Erreur semantique: Incompatibilite de type a la ligne %d colonne %d\n", nb_ligne, col); 
                        exit(EXIT_FAILURE);
                }
                       
                rechercher ($2,"Separateur","0","0", 2,tss); 
                Misajour($1,(int)tss,idfNewValue); 
                quadr("=",saveCst,"",$1);
            }
            | IDF aff CHAINE INST{
                rechercher1 ($1,"IDF","Identifier","0", 0,tss); 
                printf("%s \t %s \n",$1,typeval);
                if (incompatibiliteDeType($1,typeval,tss) == 1) {
                        printf("Erreur semantique: Incompatibilite de type a la ligne %d colonne %d\n", nb_ligne, col); 
                        exit(EXIT_FAILURE);
                }
                rechercher ($2,"Separateur","0","0", 2,tss);
                Misajour($1,(int)tss,idfNewValue);
                strcpy(saveCst,idfNewValue);
                quadr("=",saveCst,"",$1);
                }
            | IDF aff LOGICAL INST{
                rechercher1 ($1,"IDF","Identifier","0", 0,tss);  
                printf("%s \t %s \n",$1,typeval);
                if (incompatibiliteDeType($1,typeval,tss) == 1) {
                        printf("Erreur semantique: Incompatibilite de type a la ligne %d colonne %d\n", nb_ligne, col); 
                        exit(EXIT_FAILURE);
                }
                        
                rechercher ($2,"Separateur","0","0", 2,tss);
                Misajour($1,(int)tss,idfNewValue); 
                strcpy(saveCst,idfNewValue);
                quadr("=",saveCst,"",$1);
                }
;

EXPRESSION :  VALEUR {
                        if(only_one == 0 ){
                                if(strcmp(op1,"")==0 && !h){
                                        strcpy(saveCst,op1);}else{if(h){h=0;}}
                        }else{
                                if(!mull){
                                        if(x==1){
                                                if(p){
                                                value2=atoi((char*)getValueOfIDF(op1,tss));
                                                        if (strcmp(saveOP, "+") == 0) {
                                                        resultI = value2 + value1;
                                                } else if (strcmp(saveOP, "-") == 0) {
                                                        resultI = value2 - value1;
                                                } else if (strcmp(saveOP, "*") == 0) {
                                                        resultI = value2 * value1;
                                                } else if (strcmp(saveOP, "/") == 0) {
                                                        if (value1 != 0) {
                                                        resultI = value2 / value1;
                                                        } else {
                                                        printf("Error: Division by zero.\n");
                                                        exit(EXIT_FAILURE);
                                                        err=1; // Exit with an error code
                                                        }}                                      

                                                quadr(medOp,op1,"TEMP",temp1);
                                                strcpy(saveCst,temp1);
                                                sprintf(idfNewValue,"%d",resultI);
                                                }else{
                                                        value2=resultI;
                                                        if (strcmp(saveOP, "+") == 0) {
                                                        resultI = value2 + value1;
                                                } else if (strcmp(saveOP, "-") == 0) {
                                                        resultI = value2 - value1;
                                                } else if (strcmp(saveOP, "*") == 0) {
                                                        resultI = value2 * value1;
                                                } else if (strcmp(saveOP, "/") == 0) {
                                                        if (value1 != 0) {
                                                        resultI = value2 / value1;
                                                        } else {
                                                        printf("Error: Division by zero.\n");
                                                        exit(EXIT_FAILURE);
                                                        err=1; // Exit with an error code
                                                        }}                                      
                                                        quadr(saveOP,temp1,op1,temp1);strcpy(saveCst,temp1);sprintf(idfNewValue,"%d",resultI);}
                                        }else{  
                                                value2=atoi((char*)getValueOfIDF(med,tss));
                                                        if (strcmp(saveOP, "+") == 0) {
                                                        resultI = value2 + value1;
                                                } else if (strcmp(saveOP, "-") == 0) {
                                                        resultI = value2 - value1;
                                                } else if (strcmp(saveOP, "*") == 0) {
                                                        resultI = value2 * value1;
                                                } else if (strcmp(saveOP, "/") == 0) {
                                                        if (value1 != 0) {
                                                        resultI = value2 / value1;
                                                        } else {
                                                        printf("Error: Division by zero.\n");
                                                        exit(EXIT_FAILURE);
                                                        err=1; // Exit with an error code
                                                        }}                                      
                                                quadr(saveOP,op1,med,temp1);
                                                strcpy(saveCst,temp1);sprintf(idfNewValue,"%d",resultI);
                                        }
                                }else{
                                        if (lol){
                                                value2=resultI;
                                                        if (strcmp(medOp, "+") == 0) {
                                                        resultI = value2 + value1;
                                                } else if (strcmp(medOp, "-") == 0) {
                                                        resultI = value2 - value1;
                                                } else if (strcmp(medOp, "*") == 0) {
                                                        resultI = value2 * value1;
                                                } else if (strcmp(medOp, "/") == 0) {
                                                        if (value1 != 0) {
                                                        resultI = value2 / value1;
                                                        } else {
                                                        printf("Error: Division by zero.\n");
                                                        exit(EXIT_FAILURE);
                                                        err=1; // Exit with an error code
                                                        }}                                      
                                                quadr(medOp,temp1,tempMul,temp1);lol=0;strcpy(saveCst,temp1);
                                                sprintf(idfNewValue,"%d",resultI);
                                        }
                                        if(strcmp(tempMul,"")!=0){
                                                if(strcmp(med2,"")!=0){if(a){
                                                        value2=resultI;
                                                        if(strcmp((char*)getCodeOfEntity(med2,tss),"IDF")==0)
                                                        value1=atoi((char*)getValueOfIDF(med2));
                                                        else value1=atoi(med2);
                                                                if (strcmp(medOp, "+") == 0) {
                                                                resultI = value2 + value1;
                                                        } else if (strcmp(medOp, "-") == 0) {
                                                                resultI = value2 - value1;
                                                        } else if (strcmp(medOp, "*") == 0) {
                                                                resultI = value2 * value1;
                                                        } else if (strcmp(medOp, "/") == 0) {
                                                                if (value1 != 0) {
                                                                resultI = value2 / value1;
                                                                } else {
                                                                printf("Error: Division by zero.\n");
                                                                exit(EXIT_FAILURE);
                                                                err=1; // Exit with an error code
                                                                }}                                      
                                                         quadr(medOp,med2,tempMul,temp1);
                                                         strcpy(saveCst,temp1);}}
                                                        sprintf(idfNewValue,"%d",resultI);
                                        }
                                }
                        }
	}
            | VALEUR {strcpy(medType,saveType);strcpy(med,op1);} {only_one = 1} OPERATION {if(strcmp(saveOP,"+")==0 ||strcmp(saveOP,"-")==0){
                                                                                                if(!mull){printf("");
                                                                                                if(strcmp(med2,"")!=0){
                                                                                                        if(x){
                                                                                                                value2=resultI;
                                                                                                                        if (strcmp(saveOP, "+") == 0) {
                                                                                                                        resultI = value2 + value1;
                                                                                                                } else if (strcmp(saveOP, "-") == 0) {
                                                                                                                        resultI = value2 - value1;
                                                                                                                } else if (strcmp(saveOP, "*") == 0) {
                                                                                                                        resultI = value2 * value1;
                                                                                                                } else if (strcmp(saveOP, "/") == 0) {
                                                                                                                        if (value1 != 0) {
                                                                                                                        resultI = value2 / value1;
                                                                                                                        } else {
                                                                                                                        printf("Error: Division by zero.\n");
                                                                                                                        exit(EXIT_FAILURE);
                                                                                                                        err=1; // Exit with an error code
                                                                                                                        }}                                      
                                                                                                                quadr(medOp,temp1,med,temp1);
                                                                                                        }else{
                                                                                                                value2=atoi((char*)getValueOfIDF(med2,tss));
                                                                                                                        if (strcmp(saveOP, "+") == 0) {
                                                                                                                        resultI = value2 + value1;
                                                                                                                } else if (strcmp(saveOP, "-") == 0) {
                                                                                                                        resultI = value2 - value1;
                                                                                                                } else if (strcmp(saveOP, "*") == 0) {
                                                                                                                        resultI = value2 * value1;
                                                                                                                } else if (strcmp(saveOP, "/") == 0) {
                                                                                                                        if (value1 != 0) {
                                                                                                                        resultI = value2 / value1;
                                                                                                                        } else {
                                                                                                                        printf("Error: Division by zero.\n");
                                                                                                                        exit(EXIT_FAILURE);
                                                                                                                        err=1; // Exit with an error code
                                                                                                                        }}                                      
                                                                                                                quadr(medOp,med2,med,temp1);x=1;
                                                                                                        }
                                                                                                        lol = 1;
                                                                                                }
                                                                                                else{
                                                                                                        strcpy(med2,med);
                                                                                                }}
                                                                                                else{ 
                                                                                                        if(strcmp(med2,"")!=0){
                                                                                                                        value2=atoi((char*)getValueOfIDF(med2,tss));
                                                                                                                                if (strcmp(saveOP, "+") == 0) {
                                                                                                                                resultI = value2 + value1;
                                                                                                                        } else if (strcmp(saveOP, "-") == 0) {
                                                                                                                                resultI = value2 - value1;
                                                                                                                        } else if (strcmp(saveOP, "*") == 0) {
                                                                                                                                resultI = value2 * value1;
                                                                                                                        } else if (strcmp(saveOP, "/") == 0) {
                                                                                                                                // Ensure value2 is not zero before performing division
                                                                                                                                if (value1 != 0) {
                                                                                                                                resultI = value2 / value1;
                                                                                                                                } else {
                                                                                                                                printf("Error: Division by zero.\n");
                                                                                                                                exit(EXIT_FAILURE);
                                                                                                                                err=1; // Exit with an error code
                                                                                                                                }}                                      
                                                                                                                        quadr(medOp,med2,"TEMP",temp1);
                                                                                                                        
                                                                                                                        strcpy(med2,"TEMP");
                                                                                                                }else{
                                                                                                                        strcpy(med2,"TEMP");p=1;
                                                                                                                        }mull=0;x=1;strcpy(tempMul,"");
                                                                                                }strcpy(medOp,saveOP);a=0;
                                                                                                }
                                                                                                if(strcmp(saveOP,"*")==0 || strcmp(saveOP,"/")==0){
                                                                                                                mull = 1;a=1;

                                                                                                        }
                                                                			} EXPRESSION {strcpy(saveOP,"");strcpy(medOp,"");strcpy(med2,"");strcpy(med,"");strcpy(tempMul,"");strcpy(op1,"");lol=0;mull=0;x=0;a=0;p=0;only_one = 0}
            | po EXPRESSION pf OPERATION EXPRESSION {rechercher ($1,"Separateur","0","0", 2,tss); rechercher ($3,"Separateur","0","0", 2,tss);}{strcpy(saveOP,"");strcpy(medOp,"");strcpy(med2,"");strcpy(med,"");strcpy(tempMul,"");strcpy(op1,"");lol=0;mull=0;x=0;a=0;p=0;only_one = 0}
            | po EXPRESSION pf{rechercher ($1,"Separateur","0","0", 2,tss);rechercher ($3,"Separateur","0","0", 2,tss);}
;

VALEUR :      IDF TABL {
                rechercher1 ($1,"IDF","Identifier","0", 0,tss);  
                strcpy(typeval,(char*)printTypeOfIDF($1)); 
                strcpy(idfNewValue, (char*)getValueOfIDF($1, tss));
                strcpy(saveCst,$1);
                strcpy(op1,saveCst);
                value1=atoi(idfNewValue);
                
                if(mull==1){printf("");
                if(strcmp((char*)getCodeOfEntity(med,tss),"IDF")==0)
                {value2=atoi((char*)getValueOfIDF(med,tss));}
                else {value2=atoi(med);}
                        if (strcmp(saveOP, "+") == 0) {
                        resultI = value2 + value1;
                } else if (strcmp(saveOP, "-") == 0) {
                        resultI = value2 - value1;
                } else if (strcmp(saveOP, "*") == 0) {
                        resultI = value2 * value1;
                } else if (strcmp(saveOP, "/") == 0) {
                        if (value1 != 0) {
                        resultI = value2 / value1;
                        } else {
                        printf("Error: Division by zero.\n");
                        exit(EXIT_FAILURE);
                        err=1; 
                        }}                                      
                quadr(saveOP,med,op1,"TEMP");
                strcpy(tempMul,"TEMP");strcpy(saveCst,op1);
                sprintf(idfNewValue,"%d",resultI);
             } ;strcpy(xx, (char*)getValueOfIDF($1, tss));xx1=atoi(xx) ;printf("");if( vv1 ==1 && idfNewValue2 > xx1) {printf("Erreur symantique : indice hors intervale\n");exit(EXIT_FAILURE);}   vv1=0;jj=nbb2($1);if (bb == 1  && (nb11 > nbb1($1) || nb22 > nbb2($1)))printf("\nerreur dans la matrice la taille non disponible\n");bb=0;
                }
            | NUMBER 
;

TABL : TAB |
;

TAB :       po TAILLE pf {rechercher ($1,"Separateur","0","0", 2,tss); rechercher ($3,"Separateur","0","0", 2,tss);}
;

NUMBER:     integr {    
                        strcpy(typeval, "INTEGER");
                        sprintf(idfNewValue, "%d", $1);
                        sprintf(saveCst,"%d",$1);
                        strcpy(op1,saveCst);
                        value1=$1;
                        if(strcmp(saveOP,"")!=0){
                                if(strcmp(saveType,medType)!=0){
                                printf("error at %d %d,types error\n",nbLigne-1,nbCol);err=1;
                                }
                        }
                        if(mull==1){
                                if(strcmp(tempMul,"")==0){ 
                                        value2=atoi((char*)getValueOfIDF(med,tss));
                                        if (strcmp(saveOP, "+") == 0) {
                                        resultI = value2 + value1;
                                        } else if (strcmp(saveOP, "-") == 0) {
                                        resultI = value2 - value1;
                                        } else if (strcmp(saveOP, "*") == 0) {
                                        resultI = value2 * value1;
                                        } else if (strcmp(saveOP, "/") == 0) {
                                        // Ensure value2 is not zero before performing division
                                                if (value1 != 0) {
                                                resultI = value2 / value1;
                                                } else {
                                                printf("Error: Division by zero.\n");
                                                exit(EXIT_FAILURE);
                                                err=1; 
                                                }}                                      
                                        quadr(saveOP,med,op1,"TEMP");
                                        strcpy(tempMul,"TEMP");strcpy(saveCst,op1);
                                        sprintf(idfNewValue,"%d",resultI);
                                }else{          
                                                value2=resultI;
                                                        if (strcmp(saveOP, "+") == 0) {
                                                        resultI = value2 + value1;
                                                } else if (strcmp(saveOP, "-") == 0) {
                                                        resultI = value2 - value1;
                                                } else if (strcmp(saveOP, "*") == 0) {
                                                        resultI = value2 * value1;
                                                } else if (strcmp(saveOP, "/") == 0) {
                                                   
                                                        if (value1 != 0) {
                                                        resultI = value2 / value1;
                                                        } else {
                                                        printf("Error: Division by zero.\n");
                                                        exit(EXIT_FAILURE);
                                                        err=1; 
                                                        }}                                      
                                                quadr(saveOP,tempMul,op1,"TEMP"); printf("%s\t %s \t %s\n",tempMul,saveOP,op1);strcpy(saveCst,op1);
                                        }
                        }
                } 
        | floatt {
                        strcpy(typeval, "REAL");
                        sprintf(idfNewValue, "%f", $1);
                        sprintf(saveCst,"%f",$1);
                        strcpy(op1,saveCst);
                        if(strcmp(saveOP,"")!=0){
                                if(strcmp(saveType,medType)!=0){
                                }
                        }
                        if(mull==1){
                                if(strcmp(tempMul,"")==0){
                                        quadr(saveOP,med,op1,"TEMP");
                                        strcpy(tempMul,"TEMP");
                        }else{
                                        quadr(saveOP,tempMul,op1,"TEMP");
                                }
                        }
                }
;

OPERATION : add {rechercher ($1,"Separateur","0","0", 2,tss); strcpy(saveOP,$1);}| sub{rechercher ($1,"Separateur","0","0", 2,tss); strcpy(saveOP,$1);} | mul{rechercher ($1,"Separateur","0","0", 2,tss); strcpy(saveOP,$1);}| divv {rechercher ($1,"Separateur","0","0", 2,tss); strcpy(saveOP,$1);}  
;

CHAINE :    string {
                        strcpy(typeval,"CHARACTER");
                        sprintf(idfNewValue, "%s", $1);
                }
;

LOGICAL :  	  booleen {strcpy(typeval,"LOGICAL");
        sprintf(idfNewValue, "%s", $1);
        
        if(strcmp(idfNewValue,"TRUE")==0)
                strcpy(saveCst,"1");
        else
                strcpy(saveCst,"0");
        h=1;}
;

ES :        mc_read po IDF pf {rechercher ($1,"Mot cle ","","0", 1,tss); rechercher ($2,"Separateur","0","0", 2,tss);rechercher1 ($3,"IDF","Identifier","0", 0,tss); rechercher ($4,"Separateur","0","0", 2,tss);}
          | mc_write po STRING pf {rechercher ($1,"Mot cle ","","0", 1,tss); rechercher ($2,"Separateur","0","0", 2,tss); rechercher ($4,"Separateur","0","0", 2,tss);}
;

STRING :    CHAINE vrg IDF vrg CHAINE {rechercher ($2,"Separateur","0","0", 2,tss);rechercher1 ($3,"IDF","Identifier","0", 0,tss); rechercher ($4,"Separateur","0","0", 2,tss);}
          | CHAINE
;

CONDITON :  mc_if po EXPCDTT            {deb_else[i_else]=qc;
                                        i_else++;
                                        quadr("BZ","",saveCst,"");
                                        sprintf(tmp,"%d",qc);
                                        ajour_quad(or_b,1,tmp);
                                        ajour_quad(or_b+1,1,tmp);
                                        }
            pf mc_then INST mc_else     {
                                        fin_if[i_if]=qc;
                                        i_if++;
                                        quadr("BR","","","");
                                        sprintf(tmp,"%d",qc);
                                        ajour_quad(deb_else[i_else-1],1,tmp);
                                        i_else--;
                                        AND_or_OR=0;
                                        }
            INST mc_endif               {
                                        rechercher ($1,"Mot cle ","","0", 1,tss); 
                                        rechercher ($2,"Separateur","0","0", 2,tss);
                                        rechercher ($5,"Separateur","0","0", 2,tss);
                                        rechercher ($6,"Mot cle ","","0", 1,tss);
                                        rechercher ($8,"Mot cle ","","0", 1,tss);
                                        rechercher ($11,"Mot cle ","","0", 1,tss);
                                        sprintf(tmp,"%d",qc);  
                                        ajour_quad(fin_if[i_if-1],1,tmp);
                                        i_if--;
                                        AND_or_OR=0;
                                        }
;

EXPCDTT :     EXPRESSION                {
                                        if(AND_or_OR!=0){
                                                if(AND_or_OR==1){
                                                        and_b=qc;
                                                        quadr("BZ","",saveCst);
                                                        quadr("=","1","","TEMP");
                                                        and_f=qc;
                                                        quadr("BR","","","");
                                                        sprintf(tmp,"%d",qc);
                                                        ajour_quad(and_b,1,tmp);
                                                        ajour_quad(and_b+1,1,tmp);
                                                        quadr("=","0","","TEMP");
                                                        sprintf(tmp,"%d",qc);
                                                        ajour_quad(and_f,1,tmp);
                                                }else{
                                                        or_b=qc;
 //                                                       quadr("BNZ","",s,"");
                                                        quadr("BNZ","",saveCst);
                                                        quadr("=","0","","TEMP");
                                                        or_f=qc;
                                                        quadr("BR","","","");
                                                        sprintf(tmp,"%d",qc);ajour_quad(or_b,1,tmp);ajour_quad(or_b+1,1,tmp);
                                                        quadr("=","1","","TEMP");sprintf(tmp,"%d",qc);
                                                        ajour_quad(or_f,1,tmp);
                                                }
                                        }
                                        }
             | EXPRESSION                {if(strcmp(saveCst,"TEMP")==0){
                                                ajour_quad(qc-1,3,"TEMP2");
                                                strcpy(s,"TEMP2");
                                        } else{
                                                strcpy(s,saveCst);
                                                }
                                                if(AND_or_OR!=0){
                                                        if(AND_or_OR==1){
                                                                and_b=qc;
//                                                                quadr("BZ","",s,"");
                                                                quadr("BZ","",saveCst,"");
                                                                quadr("=","1","","TEMP");
                                                                and_f=qc;
                                                                quadr("BR","","","");
                                                                sprintf(tmp,"%d",qc);
                                                                ajour_quad(and_b,1,tmp);
                                                                ajour_quad(and_b+1,1,tmp);
                                                                quadr("=","0","","TEMP");
                                                                sprintf(tmp,"%d",qc);
                                                                ajour_quad(and_f,1,tmp);
                                                        }else{
                                                                strcpy(saveCst,"TEMP");
                                                                or_b=qc;
                                                                printf("%s\n",s);
                                                                quadr("BNZ","",saveCst,"");
                                                                quadr("BNZ","",saveCst,"");
                                                        }
                                                }if(o){strcpy(saveCst,"TEMP");ajour_quad(qc-3,3,"TEMP2");printf("\n\n\n\nyaaaaaaaaaaaaaaa");}
                                                o = 1;
                                                }
                CDTT EXPCDTT                    {
                                                if(strcmp(saveOpLo,"GT")==0){quadr(">",s,saveCst,"TEMP");}
                                                if(strcmp(saveOpLo,"GE")==0){quadr(">=",s,saveCst,"TEMP");}
                                                if(strcmp(saveOpLo,"LT")==0){quadr("<",s,saveCst,"TEMP");}
                                                if(strcmp(saveOpLo,"LE")==0){quadr("<=",s,saveCst,"TEMP");}
                                                if(strcmp(saveOpLo,"EQ")==0){quadr("==",s,saveCst,"TEMP");}
                                                if(strcmp(saveOpLo,"NE")==0){quadr("!=",s,saveCst,"TEMP");}
                                                strcpy(saveCst,"TEMP");o=0;
                                                }  
            | LOGICAL   
            | po EXPCDTT pf CDTT po EXPCDTT pf {rechercher ($1,"Separateur","0","0", 2,tss); rechercher ($3,"Separateur","0","0", 2,tss);rechercher ($5,"Separateur","0","0", 2,tss);rechercher ($7,"Separateur","0","0", 2,tss);}
;

CDTT :      point CDT point {rechercher ($1,"Separateur","0","0", 2,tss); rechercher ($3,"Separateur","0","0", 2,tss);}
;

CDT :         mc_eq {rechercher ($1,"Mot cle ","","0", 1,tss);strcpy(saveOpLo,$1);}
            | mc_ne {rechercher ($1,"Mot cle ","","0", 1,tss);strcpy(saveOpLo,$1);}
            | mc_ge {rechercher ($1,"Mot cle ","","0", 1,tss);strcpy(saveOpLo,$1);}
            | mc_gt {rechercher ($1,"Mot cle ","","0", 1,tss);strcpy(saveOpLo,$1);}
            | mc_le {rechercher ($1,"Mot cle ","","0", 1,tss);strcpy(saveOpLo,$1);}
            | mc_lt {rechercher ($1,"Mot cle ","","0", 1,tss);strcpy(saveOpLo,$1);}
            | mc_and {rechercher ($1,"Mot cle ","","0", 1,tss);strcpy(saveOpLo,$1);AND_or_OR=1;}
            | mc_or {rechercher ($1,"Mot cle ","","0", 1,tss);strcpy(saveOpLo,$1);AND_or_OR=-1;}
;

LOOP:       mc_dowhile po {Deb_while=qc;} EXPCDTT {
                                        Fin_while=qc;
                                        quadr("BZ","",saveCst,"");
                                                }
                pf INST mc_enddo {
                                                                        rechercher ($1,"Mot cle ","","0", 1,tss);
                                                                        rechercher ($2,"Separateur","0","0", 2,tss);
                                                                        rechercher ($6,"Separateur","0","0", 2,tss);
                                                                        rechercher ($8,"Mot cle ","","0", 1,tss);
                                                                        sprintf(tmp,"%d",Deb_while);
                                                                        quadr("BR",tmp,"","");
                                                                        sprintf(tmp,"%d",qc);
                                                                        ajour_quad(Fin_while,1,tmp);

                                                                }
;

CALLING :   IDF aff mc_call IDF po PARAMETRE1 pf {
                if(functionExists($4,nbParams)==0) {printf("Erreur semantique : Fonction non declarer %d,%d\n",nb_ligne,nbCol); exit(EXIT_FAILURE);};
                if(functionExists($4,nbParams)==2) {printf("Erreur semantique : Nombre de parametre %d,%d\n",nb_ligne,nbCol); exit(EXIT_FAILURE);};
                rechercher1 ($1,"IDF","Identifier","0", 0,tss); 
                rechercher ($2,"Separateur","0","0", 2,tss);
                rechercher ($3,"Mot cle ","","0", 1,tss);
                rechercher ($5,"Separateur","0","0", 2,tss);
                rechercher ($7,"Separateur","0","0", 2,tss);
        }
;

EQUIV:      mc_equivalence po PARAMETRE1 pf vrg po PARAMETRE1 pf {rechercher ($1,"Mot cle ","","0", 1,tss);rechercher ($4,"Separateur","0","0", 2,tss);rechercher ($5,"Separateur","0","0", 2,tss);rechercher ($6,"Separateur","0","0", 2,tss);rechercher ($8,"Separateur","0","0", 2,tss);}
;

PARAMETRE1 :   IDF {rechercher1 ($1,"IDF","Identifier","0", 0,tss); nbParams=1}       
            | IDF vrg  PARAMETRE1 {rechercher1 ($1,"IDF","Identifier","0", 0,tss); rechercher ($2,"Separateur","0","0", 2,tss);  nbParams++;}
            | IDF po TAILLE pf {rechercher1 ($1,"IDF","Identifier","0", 0,tss);rechercher ($2,"Separateur","0","0", 2,tss);rechercher ($4,"Separateur","0","0", 2,tss); ;strcpy(xx, (char*)getValueOfIDF($1, tss));xx1=atoi(xx) ;printf("l");if( vv1 ==1 && idfNewValue2 > xx1) printf("erreur symantique car la taile non disponible\n");vv1=0;jj=nbb2($1);if(bb == 1  && (nb11 > nbb1($1) || nb22 > nbb2($1)))printf("erreur dans la matrice la taille non disponible");bb=0;}
            | IDF po TAILLE pf PARAMETRE1 {rechercher1 ($1,"IDF","Identifier","0", 0,tss);rechercher ($2,"Separateur","0","0", 2,tss);rechercher ($4,"Separateur","0","0", 2,tss);;strcpy(xx, (char*)getValueOfIDF($1, tss));xx1=atoi(xx) ;printf("l");if( vv1 ==1 && idfNewValue2 > xx1) printf("erreur symantique car la taile non disponible\n");vv1=0; }            
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
                afficher_qdr();
                executer(tss);
   

    
    return 0;
}
yywrap ()
{}
int yyerror ( char*  msg )  
{
       printf ("Erreur Syntaxique : fichier %s , ligne %d , colonne %d \n", filename,nb_ligne,col);
       exit(EXIT_FAILURE);
}

