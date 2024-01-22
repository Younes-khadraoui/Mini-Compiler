#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mat{
    char nom[20]; 
    int nb1;   
    int nb2;    
 }mat ;
mat MATT[1000];

typedef struct qdr{
    char oper[100]; 
    char op1[100];   
    char op2[100];   
    char res[100];  
  }qdr;
qdr quad[1000];
extern int qc;

typedef struct call {
    char name[50];
    int nbParam;
} call;
call callTable[10];

typedef struct
{
  int state;
  char name[20];
  char code[20];
  char type[20];
  char val[20];
} element;

typedef struct tabIDF
{
  element elm;
  struct tabIDF *suiv;
} tabIDF;

typedef struct
{
  int state;
  char name[20];
  char type[20];
} elt;

typedef struct tabSepMc
{
  elt elm;
  struct tabSepMc *suiv;
} tabSepMc;

typedef struct listePointure
{
  int ts;
  tabIDF *tab1;
  tabSepMc *tab2;
  tabSepMc *tab3;
  struct listePointure *suiv;
} listePointure;

typedef struct
{
	char value[20];
} tabT;

tabT tabt[1000];
int l = 0;
int b = 0;
int cpt, cpts, cptm;
char TEMP[50], TEMP2[50];

listePointure *tabLP = NULL;
tabIDF *tab = NULL;
tabSepMc *tabSeparateur = NULL;
tabSepMc *tabMotCle = NULL;

void initializeCall(int index, const char* name, int nbParam) {
    strncpy(callTable[index].name, name, sizeof(callTable[index].name) - 1);
    callTable[index].name[sizeof(callTable[index].name) - 1] = '\0'; 
    callTable[index].nbParam = nbParam;
}



int functionExists(const char* functionName,  int nbParam) {
    int i;
    for (i = 0; i < 10; ++i) {
        if (strcmp(functionName, callTable[i].name) == 0) {
            if (nbParam == callTable[i].nbParam) {
                return 1; 
            }
            return 2;
        }
    }
    return 0; 
}

listePointure *FinListePointure()
{
  listePointure *courant = tabLP;
  while (courant != NULL && courant->suiv != NULL)
  {
    courant = courant->suiv;
  }
  return courant;
}

tabIDF *FinTabIDF()
{
  tabIDF *courant = tab;
  while (courant != NULL && courant->suiv != NULL)
  {
    courant = courant->suiv;
  }
  return courant;
}

tabSepMc *FinTabSepMc(int selectTAB)
{
  tabSepMc *courant = NULL;
  if (selectTAB == 0)
  {
    courant = tabSeparateur;
  }
  else if (selectTAB == 1)
  {
    courant = tabMotCle;
  }
  while (courant != NULL && courant->suiv != NULL)
  {
    courant = courant->suiv;
  }
  return courant;
}

void modmat(char nom[],int nb1,int nb2,int i)
{
  MATT[i].nb1 = nb1;
  MATT[i].nb2 = nb2;
  strcpy(MATT[i].nom ,nom);

  //    printf("nb2222222222222222222222222222 %s  %s  %d  %d",MATT[i].nom,nom,MATT[i].nb1,MATT[i].nb2);
  


}

int nbb1 (char nom [])
{
    int b=0;

    while (strcmp(nom, MATT[b].nom) != 0)
    {
      b++;
      if (b > 120)return 0;      
    }

    

    return MATT[b].nb1 ;
}
int nbb2 (char nom [])
{
    
    int b=0;

    while (strcmp(nom, MATT[b].nom) != 0)
    {

      b++;
      if (b > 120)return 0;
    }

   // printf("nb222333333332222222222222222222222222 %d ",MATT[b].nb2);

    return MATT[b].nb2 ;
}


void inserer(char entite[], char code[], char type[], char val[], int i, int y)
{
  switch (y)
  {

  case 0:
  {
    tabIDF *newIDF = (tabIDF *)malloc(sizeof(tabIDF));
    newIDF->elm.state = 1;
    strcpy(newIDF->elm.name, entite);
    strcpy(newIDF->elm.code, code);
    strcpy(newIDF->elm.type, type);
    strcpy(newIDF->elm.val,val);
    newIDF->suiv = NULL;
    tabIDF *lastElement = FinTabIDF();

    if (lastElement != NULL)
    {
      lastElement->suiv = newIDF;
    }
    else
    {
      tab = newIDF;
    }
  
    break;
  }

  case 1 :
  {
    tabSepMc *newSM = (tabSepMc *)malloc(sizeof(tabSepMc));
    newSM->elm.state = 1;
    strcpy(newSM->elm.name, entite);
    strcpy(newSM->elm.type, code);
    newSM->suiv = NULL;
    tabSepMc *lastElement = FinTabSepMc(1);
    if (lastElement != NULL) lastElement->suiv = newSM;
    else tabMotCle = newSM;
    break;
  }

  case 2 :
  {
    tabSepMc *newSM = (tabSepMc *)malloc(sizeof(tabSepMc));
    newSM->elm.state = 1;
    strcpy(newSM->elm.name, entite);
    strcpy(newSM->elm.type, code);
    newSM->suiv = NULL;
    tabSepMc *lastElement = FinTabSepMc(0);
    if (lastElement != NULL)
    {
      lastElement->suiv = newSM;
    }
    else
    {
      tabSeparateur = newSM;
    }
    break;
  }

  }
}

void creep (listePointure *newLP1)
{
 tabIDF *newIDF1 = (tabIDF *)malloc(sizeof(tabIDF));
 tabSepMc *newMC = (tabSepMc *)malloc(sizeof(tabSepMc));
 tabSepMc *newSEP = (tabSepMc *)malloc(sizeof(tabSepMc));

  newLP1->tab1 = newIDF1;
  newLP1->tab2 = newMC;
  newLP1->tab3 = newSEP;
}


void rechercher(char entite[], char code[], char type[], char val[], int y , int ts )
{

  int j, i;
  listePointure *courantLP = tabLP;
  tabIDF *courant = tab;
  tabSepMc *courantM = tabMotCle;
  tabSepMc *courantS = tabSeparateur;
  listePointure *chik = tabLP;

  if(tabLP == NULL)
  {
    listePointure *newLP = (listePointure *)malloc(sizeof(listePointure));
    newLP->suiv = NULL;
    newLP->tab1 = tab;
    newLP->tab2 = tabMotCle;
    newLP->tab3 = tabSeparateur;
    newLP->ts = ts;
    tabLP = newLP;
    courantLP=tabLP;
    courantLP->ts=ts;   
    courantLP->tab1=tab;
    courantLP->tab2=tabMotCle;
    courantLP->tab3=tabSeparateur;
  }
  else
  {
    courantLP = FinListePointure();

    if(courantLP->ts != ts)
    {
      while (tab!=NULL)
      {
      tab=tab->suiv;        
      }
      listePointure *newLP5 = (listePointure *)malloc(sizeof(listePointure)); 
      newLP5->tab1=tab;
      newLP5->tab2=tabMotCle;
      newLP5->tab3=tabSeparateur;
      newLP5->ts = ts;
      newLP5->suiv=NULL;
      courantLP->suiv = newLP5; 
      courantLP = newLP5 ;
      courantLP->tab1=tab;
      courantLP->tab2=tabMotCle;
      courantLP->tab3=tabSeparateur;
      courantLP->ts=newLP5->ts;
      tab=NULL;
      tabMotCle=NULL;
      tabSeparateur=NULL;
    }
    else { 
      while (chik->ts != ts)
      {
        chik = chik->suiv ;
      }

    }
    
  }

  switch (y)
  {
  case 0 : 
    if(strcmp("IDF", code) == 0){
        while ((courantLP->tab1 != NULL) && ((strcmp(entite, courantLP->tab1->elm.name) != 0)))
          {
              courantLP->tab1 = courantLP->tab1->suiv;
          }

          if (courantLP->tab1 == NULL) {    
            inserer(entite, code, type, val, 0, y);         
          }else {
            printf(" Element doubel Declarerrrrrrrrrrrrrrrrrrrrrrrrrrrr %s\n",entite);
          }
          courantLP->tab1=tab;
          
    }


    break;

  case 1 : 

    while (courantLP->tab2 != NULL && (courantLP->tab2->elm.state == 1) && (strcmp(entite, courantLP->tab2->elm.name) != 0))
    {
      courantLP->tab2 = courantLP->tab2->suiv;   
    }
    
    if (courantLP->tab2 == NULL) {inserer(entite, code, type, val, 0, y);
             courantLP->tab2=tabMotCle;
        }    
        break;

  case 2 : 

    while (courantLP->tab3 != NULL && (courantLP->tab3->elm.state == 1) && (strcmp(entite, courantLP->tab3->elm.name) != 0))
    {
      courantLP->tab3 = courantLP->tab3->suiv;
    }

    if (courantLP->tab3 == NULL) inserer(entite, code, type, val, 0, y);
         courantLP->tab3=tabSeparateur;
          break;
  }
}

void rechercher1(char entite[], char code[], char type[], char val[], int y , int ts )
{
 listePointure* courantLP = tabLP;
    tabIDF* courant = NULL;

    // Recherche de la listePointure appropriée
    while (courantLP != NULL && courantLP->ts != ts)
    {
        courantLP = courantLP->suiv;
    }

    // Si la listePointure n'existe pas ou la recherche est effectuée dans le futur, l'entité n'existe pas
    if (courantLP == NULL || ts > courantLP->ts)
    {
        printf("Entité non trouvée : %s\n", entite);
        return;
    }

    // Recherche dans la table des IDF
    courant = courantLP->tab1;
    while (courant != NULL)
    {
        if (strcmp(entite, courant->elm.name) == 0)
        {
            return;
        }
        courant = courant->suiv;
    }

    // Si l'entité n'est pas trouvée dans la table des IDF, afficher un message approprié
    printf("Entite non declarer dans la table des IDF : %s\n", entite);
}


void afficher()
{
  listePointure *courantLP = tabLP;
  tabIDF *currentIDF ;
  tabSepMc *courantM ;
  tabSepMc *courantS ;

  while (courantLP != NULL)
  {
    currentIDF = courantLP->tab1;

    courantM = courantLP->tab2; 
    courantS = courantLP->tab3;

    printf("\n\t _______________________________________________________________\n");
    printf("\t|                         Table des IDF  %d                      |\n",courantLP->ts);
    printf("\t|_______________________________________________________________|\n");
    printf("\t|  Nom_Entite  |   Code_Entite  |  Type_Entite |   Val_Entite   |\n");
    printf("\t|______________|________________|______________|________________|\n");

    
    

    while (currentIDF != NULL)
    {
      printf("\t|%13s | %14s | %12s | %14s |\n", currentIDF->elm.name, currentIDF->elm.code, currentIDF->elm.type, currentIDF->elm.val);
      currentIDF = currentIDF->suiv;
    }
    printf("\t|______________|________________|______________|________________|\n");

    printf("\n\t ___________________________\n");
    printf("\t|     Table des MOT-CLES    |\n");
    printf("\t|___________________________|\n");
    printf("\t|  NomEntite  | CodeEntite  |\n");
    printf("\t|_____________|_____________|\n");

    
    while (courantM != NULL)
    {
      printf("\t|%12s |%12s | \n", courantM->elm.name, courantM->elm.type);
      courantM = courantM->suiv;
    }
    printf("\t|_____________|_____________|\n");

    printf("\n\t ___________________________\n");
    printf("\t|   Table des SEPARATEURS   |\n");
    printf("\t|___________________________|\n");
    printf("\t|  NomEntite  |  CodeEntite | \n");
    printf("\t|_____________|_____________|\n");

    
    while (courantS != NULL)
    {
      printf("\t|%10s   |%12s | \n", courantS->elm.name, courantS->elm.type);
      courantS = courantS->suiv;
    }
    printf("\t|_____________|_____________|\n");

    courantLP = courantLP->suiv;
 
  }
}


void modifyType(char entite[], char newType[],int ts) {
    tabIDF *courant = tab;
    listePointure  *chikh = tabLP;

      while (chikh->ts != ts)
      {

        chikh = chikh->suiv ;

      }
      courant = chikh->tab1;    

    while (courant != NULL) {
        if (strcmp(entite, courant->elm.name) == 0) {
            strcpy(courant->elm.type, newType);
            break; 
        }
        courant = courant->suiv;
    }
}

char* printTypeOfIDF(const char* entite) {
    tabIDF *courant = tab;

    while (courant != NULL) {
        if (strcmp(entite, courant->elm.name) == 0) {
            return courant->elm.type;  
        }
        courant = courant->suiv;
    }

    return"Type : Unknown\n";
}

int verifyTypeEntite(const char* entite) {
    listePointure *tabl=tabLP;
    tabIDF *courant = tabl->tab1;

    while (courant != NULL) {
        if (strcmp(entite, courant->elm.name) == 0) {
                return 1;  
            } else {
                return 0;  
            }
        courant = courant->suiv;
    }

    return -1;  
}

int incompatibiliteDeType(char var[], char typeval[], int ts) {
    listePointure* courantLP = tabLP;

    while (courantLP != NULL && courantLP->ts != ts) {
        courantLP = courantLP->suiv;
    }

    if (courantLP == NULL || ts > courantLP->ts) {
        return 1;
    }

    tabIDF* courant = courantLP->tab1;
    while (courant != NULL) {
        if (strcmp(var, courant->elm.name) == 0 && strcmp(typeval, courant->elm.type) == 0) {
            return 0;
        }
        courant = courant->suiv;
    }

    return 1;
}

const char* getValueOfIDF(const char entite[], int ts) {
    listePointure *courantLP = tabLP;

    while (courantLP != NULL && courantLP->ts != ts) {
        courantLP = courantLP->suiv;
    }

    if (courantLP != NULL) {
        tabIDF *courant = courantLP->tab1;

        while (courant != NULL) {
            if (strcmp(entite, courant->elm.name) == 0) {
                return courant->elm.val;
            }
            courant = courant->suiv;
        }
    }

    return "0.0";
}

const char* getCodeOfEntity(const char* entite, int ts) {
    listePointure* courantLP = tabLP;

    // Trouver la listePointure appropriée en fonction du timestamp
    while (courantLP != NULL && courantLP->ts != ts) {
        courantLP = courantLP->suiv;
    }

    if (courantLP != NULL) {
        // Rechercher l'entité dans la table des IDF
        tabIDF* courant = courantLP->tab1;
        while (courant != NULL) {
            if (strcmp(entite, courant->elm.name) == 0) {
                // Retourner le code de l'entité si elle est trouvée
                return courant->elm.code;
            }
            courant = courant->suiv;
        }
    }
}

void Misajour(char entite[], int tss, const char* newValuess) {
    listePointure *courantLP = tabLP;

    while (courantLP != NULL && courantLP->ts != tss) {
        courantLP = courantLP->suiv;
    }

    if (courantLP != NULL) {
        tabIDF *courant = courantLP->tab1;
        while (courant != NULL) {
            if (strcmp(entite, courant->elm.name) == 0) {
                strcpy(courant->elm.val, newValuess);
                return;
            }
            courant = courant->suiv;
        }
    }

    printf("Entité non trouvée ##########: %s\n", entite);
}

void quadr(char opr[],char op1[],char op2[],char res[])
{

	strcpy(quad[qc].oper,opr);
	strcpy(quad[qc].op1,op1);
	strcpy(quad[qc].op2,op2);
	strcpy(quad[qc].res,res);
	
	
qc++;

}

void ajour_quad(int num_quad, int colon_quad, char val [])
{
if (colon_quad==0) strcpy(quad[num_quad].oper,val);
else if (colon_quad==1) strcpy(quad[num_quad].op1,val);
         else if (colon_quad==2) strcpy(quad[num_quad].op2,val);
                   else if (colon_quad==3) strcpy(quad[num_quad].res,val);

}

void afficher_qdr()
{
printf("\n\n\n\n*********************Les Quadruplets***********************\n");

int i;

for(i=0;i<qc;i++)
		{
  if(strcmp(quad[i].oper,"")==0){strcpy(quad[i].oper,"=");}
 printf("\n %d - ( %s  ,  %s  ,  %s  ,  %s )",i,quad[i].oper,quad[i].op1,quad[i].op2,quad[i].res); 
 printf("\n--------------------------------------------------------\n");

}
}

void GetValue(char entite[25], char value[25], int ts)
{
    listePointure* courantLP = tabLP;
    while (courantLP != NULL && courantLP->ts != ts)
    {
        courantLP = courantLP->suiv;
    }

    if (courantLP != NULL)
    {
        tabIDF* courant = courantLP->tab1;
        while (courant != NULL)
        {
            if (strcmp(entite, courant->elm.name) == 0)
            {
                sprintf(value, "%s", courant->elm.val);
                return;
            }
            courant = courant->suiv;
        }
    }

    // Entité non trouvée
    strcpy(value, "Entité non trouvée");
}

void SaveValue(char entite[25], char Value[25], int ts)
{
    listePointure* courantLP = tabLP;
    while (courantLP != NULL && courantLP->ts != ts)
    {
        courantLP = courantLP->suiv;
    }

    if (courantLP != NULL)
    {
        tabIDF* courant = courantLP->tab1;
        while (courant != NULL)
        {
            if (strcmp(entite, courant->elm.name) == 0)
            {
                if (strcmp(courant->elm.type, "char") != 0)
                {
                    strcpy(courant->elm.val, Value);
                }
                else
                {
                    // Assuming valChar is a field in the tabIDF structure
                    strcpy(courant->elm.val, Value);
                }

                if (strcmp(courant->elm.type, "LOGICAL") == 0)
                {
                    if (strcmp(courant->elm.val, "1") == 0)
                    {
                        strcpy(courant->elm.val, "TRUE");
                    }
                    else
                    {
                        strcpy(courant->elm.val, "FALSE");
                    }
                }
                return;
            }
            courant = courant->suiv;
        }
    }

    // Entité non trouvée
}

int findIndex(char entite[], int ts)
{
    listePointure* courantLP = tabLP;
    while (courantLP != NULL && courantLP->ts != ts)
    {
        courantLP = courantLP->suiv;
    }

    if (courantLP != NULL)
    {
        tabIDF* courant = courantLP->tab1;
        int i = 0;
        while (courant != NULL)
        {
            if (strcmp(entite, courant->elm.name) == 0)
            {
                return i;
            }
            i++;
            courant = courant->suiv;
        }
    }

    // Entité non trouvée
    return -1;
}

int search_temp(int l,int ts)
{
    int i = l;
    while (strcmp(quad[i].op1, "TEMP") == 0 || strcmp(quad[i].op2, "TEMP") == 0)
    {
        i--;
    }

    // Assuming TEMP is related to the symbol table, update the value
    if (strcmp(quad[i].op1, "TEMP") == 0)
    {
        GetValue(quad[i].op1, quad[i].op1, ts);
    }
    else if (strcmp(quad[i].op2, "TEMP") == 0)
    {
        GetValue(quad[i].op2, quad[i].op2, ts);
    }

    return i - 1;
}

void do_operation(char x[], char y[], char z[], char op[], int ts)
{
    b = 1;
    if (strcmp(x, "TEMP") == 0)
    {
        // Assuming 'value' is a field in the tabt structure
        strcpy(x, tabt[l - 1].value);

        if (strcmp(y, "TEMP") == 0)
        {
            strcpy(x, tabt[search_temp(l - 2,ts)].value);
            strcpy(y, tabt[search_temp(l - 1,ts)].value);
        }
    }

    if (strcmp(y, "TEMP") == 0)
    {
        strcpy(y, tabt[l - 1].value);
    }

    char te1[25], te2[25];
    strcpy(te1, x);
    strcpy(te2, y);

    // Assuming findIndex now takes the timestamp as an argument
    if (findIndex(x, ts) != -1)
    {
        GetValue(x, x, ts);
    }

    if (findIndex(y, ts) != -1)
    {
        GetValue(y, y, ts);
    }

    if (strcmp(op, "+") == 0)
    {
        sprintf(tabt[l].value, "%f", atof(y) + atof(x));
    }
    else if (strcmp(op, "-") == 0)
    {
        sprintf(tabt[l].value, "%f", atof(x) - atof(y));
    }
    else if (strcmp(op, "*") == 0)
    {
        sprintf(tabt[l].value, "%f", atof(y) * atof(x));
    }
    else if (strcmp(op, "/") == 0)
    {
        if (atof(y) == 0)
        {
            printf("error");
            return;
        }
        sprintf(tabt[l].value, "%f", atof(x) / atof(y));
    }

    strcpy(x, te1);
    strcpy(y, te2);
    l++;
}

void do_comparison(char x[], char y[], char z[], char op[], int ts)
{
    b = 1;

    if (strcmp(x, "TEMP") == 0 || strcmp(x, "TEMP!") == 0 || strcmp(x, "TEMP2") == 0)
    {
        strcpy(x, tabt[l - 1].value);
    }

    if (strcmp(y, "TEMP") == 0 || strcmp(y, "TEMP!") == 0 || strcmp(y, "TEMP2") == 0)
    {
        strcpy(y, tabt[l - 1].value);
    }

    char te1[25], te2[25];
    strcpy(te1, x);
    strcpy(te2, y);

    // Assuming findIndex now takes the timestamp as an argument
    if (findIndex(x, ts) != -1)
    {
        GetValue(x, x, ts);
    }

    if (findIndex(y, ts) != -1)
    {
        GetValue(y, y, ts);
    }

    if (strcmp(op, ">") == 0)
    {
        if (atof(x) > atof(y))
        {
            sprintf(tabt[l].value, "%f", 1.0);
        }
        else
        {
            sprintf(tabt[l].value, "%f", 0.0);
        }
    }
    else if (strcmp(op, ">=") == 0)
    {
        if (atof(x) >= atof(y))
        {
            sprintf(tabt[l].value, "%f", 1.0);
        }
        else
        {
            sprintf(tabt[l].value, "%f", 0.0);
        }
    }
    else if (strcmp(op, "<") == 0)
    {
        if (atof(x) < atof(y))
        {
            sprintf(tabt[l].value, "%f", 1.0);
        }
        else
        {
            sprintf(tabt[l].value, "%f", 0.0);
        }
    }
    else if (strcmp(op, "<=") == 0)
    {
        if (atof(x) <= atof(y))
        {
            sprintf(tabt[l].value, "%f", 1.0);
        }
        else
        {
            sprintf(tabt[l].value, "%f", 0.0);
        }
    }
    else if (strcmp(op, "==") == 0)
    {
        if (atof(x) == atof(y))
        {
            sprintf(tabt[l].value, "%f", 1.0);
        }
        else
        {
            sprintf(tabt[l].value, "%f", 0.0);
        }
    }
    else if (strcmp(op, "!=") == 0)
    {
        if (atof(x) != atof(y))
        {
            sprintf(tabt[l].value, "%f", 1.0);
        }
        else
        {
            sprintf(tabt[l].value, "%f", 0.0);
        }
    }

    strcpy(x, te1);
    strcpy(y, te2);
    l++;
}

void executer(int ts)
{
    printf("\n\nxxxxxxxxxxxxxxxxxx chaines de reference des Quadruplets xxxxxxxxxxxxxxxxxx\n");
    int i = 0;
    int v = 0;
    char A[25];
    int anda = 0, ora = 0;
    while (i < 1000)
    {
        printf(" => %d", i);
        if (strcmp(quad[i].oper, "=") == 0)
        {
            if (strcmp(quad[i].op1, "TEMP") != 0)
            {
                GetValue(quad[i].op1, A, ts);
                if (strcmp(quad[i].res, "TEMP") == 0)
                {
                    strcpy(tabt[l].value, A);
                    printf("%s", tabt[l].value);
                    l++;
                }
                SaveValue(quad[i].res, quad[i].op1, ts);
            }
            else
            {
                SaveValue(quad[i].res, tabt[l - 1].value, ts);
            }
            b = 0;
        }
        if (strcmp(quad[i].oper, "BZ") == 0)
        {
            if (strcmp(quad[i].op2, "TEMP") != 0)
            {
                if (atof(quad[i].op2) == 0)
                {
                    i = atoi(quad[i].op1);
                    v = 1;
                }
            }
            else
            {
                if (atof(tabt[l - 1].value) == 0)
                {
                    i = atoi(quad[i].op1);
                    v = 1;
                }
            }
            if (b)
                b = 0;
            strcpy(TEMP, "");
        }
        if (strcmp(quad[i].oper, "BR") == 0)
        {
            i = atoi(quad[i].op1);
            v = 1;
        }
        if (strcmp(quad[i].oper, "BNZ") == 0)
        {
            if (!b)
            {
                if (atof(quad[i].op2) == 1)
                {
                    i = atoi(quad[i].op1);
                    v = 1;
                }
            }
            else
            {
                if (atof(tabt[l - 1].value) == 1)
                {
                    i = atoi(quad[i].op1);
                    v = 1;
                }
            }
            b = 0;
            strcpy(TEMP, "");
            ora = 1;
        }
        if (strcmp(quad[i].oper, "==") == 0)
        {
            do_comparison(quad[i].op1, quad[i].op2, quad[i].res, "==", ts);
        }
        if (strcmp(quad[i].oper, ">") == 0)
        {
            do_comparison(quad[i].op1, quad[i].op2, quad[i].res, ">", ts);
        }
        if (strcmp(quad[i].oper, ">=") == 0)
        {
            do_comparison(quad[i].op1, quad[i].op2, quad[i].res, ">=", ts);
        }
        if (strcmp(quad[i].oper, "<") == 0)
        {
            do_comparison(quad[i].op1, quad[i].op2, quad[i].res, "<", ts);
        }
        if (strcmp(quad[i].oper, "<=") == 0)
        {
            do_comparison(quad[i].op1, quad[i].op2, quad[i].res, "<=", ts);
        }
        if (strcmp(quad[i].oper, "!=") == 0)
        {
            do_comparison(quad[i].op1, quad[i].op2, quad[i].res, "!=", ts);
        }
        if (strcmp(quad[i].oper, "+") == 0)
        {
            do_operation(quad[i].op1, quad[i].op2, quad[i].res, "+", ts);
        }
        if (strcmp(quad[i].oper, "-") == 0)
        {
            do_operation(quad[i].op1, quad[i].op2, quad[i].res, "-", ts);
        }
        if (strcmp(quad[i].oper, "*") == 0)
        {
            do_operation(quad[i].op1, quad[i].op2, quad[i].res, "*", ts);
        }
        if (strcmp(quad[i].oper, "/") == 0)
        {
            do_operation(quad[i].op1, quad[i].op2, quad[i].res, "/", ts);
        }
        if (strcmp(quad[i].oper, "") == 0)
        {
            return;
        }
        if (v)
        {
            v = 0;
        }
        else
        {
            i++;
        }
    }
}

