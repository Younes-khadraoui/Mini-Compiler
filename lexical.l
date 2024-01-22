%{
	#include "synt.tab.h"
	#include "ts.h"
	extern nb_ligne;
	extern col;
	extern YYSTYPE yylval;
	char *filename;
%}
lettreM [A-Z]
lettre [a-z]
chiffre [0-9]
BOOLEEN TRUE|FALSE
IDF ({lettreM}|{lettre})({lettre}|{chiffre}|{lettreM})*
floatt "-"{chiffre}+"."{chiffre}+|{chiffre}+"."{chiffre}+
integr {chiffre}+|"-"{chiffre}+
string \"[^\"]*\"

%%
"%"[^\n]* 
PROGRAM   		{yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_program;}
ROUTINE   		{yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_routine;}
EQUIVALENCE   	{yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_equivalence;}
INTEGER   		{yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);	return mc_entier;}
REAL      		{yylval.str = strdup(yytext); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mc_real;}
LOGICAL   		{yylval.str = strdup(yytext); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_logical;}
CHARACTER 		{yylval.str = strdup(yytext); col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_character;}
DIMENSION  		{yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_dimension;}
READ      {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);   return mc_read;}
WRITE     {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_write;}
IF        {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_if;}
THEN      {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_then;}
ELSE      {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_else;}
ENDIF     {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_endif;}
DOWHILE   {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_dowhile;}
ENDDO     {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_enddo;}
OR        {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_or;}
AND       {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_and;}
GT        {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_gt;}
GE        {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_ge;}
EQ        {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_eq;}
NE        {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_ne;}
LE        {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_le;}
LT        {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_lt;}
CALL      {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_call;}
END       {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_end;}
ENDR      {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return mc_endr;}

{BOOLEEN} {yylval.str = strdup(yytext);
              col = col + strlen(yytext);
			  if (yyleng>10) printf ("Erreur Lexical: IDF trop long a la ligne %d a la colonne %d \n ",nb_ligne, col);
              printf ("L'entite reconnue est %s \n", yytext); 
			  return booleen;
}

{IDF}     { 
	 yylval.str = strdup(yytext);
              col = col + strlen(yytext);
			  if (yyleng>10) printf ("Erreur Lexical: IDF trop long a la ligne %d a la colonne %d \n ",nb_ligne, col);
              printf ("L'entite reconnue est %s \n", yytext); 
			  return IDF;
}
{integr}   { 
	yylval.entier = atoi(yytext);
	int val = atoi(yytext); 
	if(val<= 32767 && val >= -32768){
		printf("L'entite reconnue est %s \n", yytext);
		col = col + strlen(yytext);
		return integr;
	}
	else {
		printf("L'entite %s  hors interval \n",yytext);
	}
}
{floatt}   {   
	yylval.reel = atof(yytext);
	float val = atof(yytext); 
	if(val<= 32767.32767 && val >= -32767.32767){
		printf("L'entite reconnue est %s \n", yytext);
		col = col + strlen(yytext);
		return floatt;
	}
	else {
		printf("L'entite %s  hors interval \n",yytext);
	}
}
{string}      {  yylval.str = strdup(yytext);
                               col= col + strlen(yytext);
								printf("L'entite reconnue est %s \n", yytext);
			                 return string;

}

"+"       { yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return add; }
"-"       {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return sub; }
"*"       {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return mul; }
"/"       {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return divv; }
";"       {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return pvg;}
","       {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return vrg;}
"="       {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext); return aff;}
"("       {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return po;}
")"       {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return pf;}
"."       {yylval.str = strdup(yytext);  col = col + strlen(yytext); printf("L'entite reconnue est %s \n", yytext);  return point;}


[ \t]     {yylval.str = strdup(yytext);  col = col + strlen(yytext); }
\n        {col = 1; nb_ligne++; }

. { printf("Erreur lexical : fichier %s ligne %d colonne %d  entite %s \n",filename, nb_ligne, col, yytext); }

