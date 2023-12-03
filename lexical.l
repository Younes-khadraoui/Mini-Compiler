%{
//	#include "synt.tab.h"
	#include "ts.h"

//	extern nb_ligne;
//	extern col;
//	extern YYSTYPE yylval;
int nb_ligne;
int col;


%}
lettreM [A-Z]
lettre [a-z]
chiffre [0-9]
IDF ({lettreM}|{lettre})({lettre}|{chiffre}|{lettreM})*
flot -{chiffre}+.{chiffre}+|{chiffre}+.{chiffre}+
integr {chiffre}+|-{chiffre}+

%%

PROGRAM   { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); }
ROUTINE   { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); }
EQUIVALENCE   { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); }
INTEGER   { 
 rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);	}
REAL      { 	
 rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); }
LOGICAL   { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
CHARACTER { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
DIMENSION { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
READ      { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
WRITE     { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
IF        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
THEN      { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
ELSE      { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
ENDIF     { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
DOWHILE   { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
ENDDO     { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
OR        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
AND       { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
GT        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
GE        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
EQ        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
NE        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
LE        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
LT        { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
CALL      { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
END       { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
ENDR      { rechercher(yytext,"Mot cle",0,0, 1); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }

{IDF}     { 
			  rechercher(yytext,"IDF"," ",0,0);  
              col = col + strlen(yytext);
			  if (yyleng>10) printf ("Erreur Lexical: IDF trop long a la ligne %d a la colonne %d \n ",nb_ligne, col);
              printf (" L entite lexicale reconnue est %s \n", yytext); 
			  
		  }
{integr}   { 
	int val = atoi(yytext);
	if(val<= 32767 && val >= -32768){
		printf("L'entite reconnue est %s \n", yytext);
		col = col + strlen(yytext);
	}
	else {
		printf("L'entite %s  hors interval \n",yytext);
	}
	}
{flot}   { 
	float val = atof(yytext);
	if(val<= 32767.32767 && val >= -32767.32767){
		printf("L'entite reconnue est %s \n", yytext);
		col = col + strlen(yytext);
	}
	else {
		printf("L'entite %s  hors interval \n",yytext);
	}
	}

"+"       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); }
"-"       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); }
"*"       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); }
"/"       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); }
";"       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); }
","       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); }
"="       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); }
"("       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }
")"       { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  }

[ \t]     { rechercher(yytext,"Mot cle",0,0, 2); col = col + strlen(yytext); }
\n        { rechercher(yytext,"Mot cle",0,0, 2); col = 1; nb_ligne++; }
. { printf("Erreur lexical a la ligne %d, colonne %d, entite %s \n", nb_ligne, col, yytext);  }
