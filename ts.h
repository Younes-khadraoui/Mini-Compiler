#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int state;
  char name[20];
  char code[20];
  char type[20];
  float val;
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


listePointure *tabLP = NULL;
tabIDF *tab = NULL;
tabSepMc *tabSeparateur = NULL;
tabSepMc *tabMotCle = NULL;

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


void inserer(char entite[], char code[], char type[], float val, int i, int y)
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
    newIDF->elm.val = val;
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


void rechercher(char entite[], char code[], char type[], float val, int y , int ts )
{
  int j, i;
  listePointure *courantLP = tabLP;
  tabIDF *courant = tab;
  tabSepMc *courantM = tabMotCle;
  tabSepMc *courantS = tabSeparateur;
  listePointure *chik = tabLP;

  if(tabLP == NULL)
  {
    printf("0\n");
    listePointure *newLP = (listePointure *)malloc(sizeof(listePointure));
    tabLP = newLP;
    newLP->suiv = NULL;
    newLP->tab1 = tab;
    newLP->tab2 = tabMotCle;
    newLP->tab3 = tabSeparateur;
    newLP->ts = 0;
    courantLP=tabLP;
  }
  else
  {
    printf("2\n");
    courantLP = FinListePointure();
    if(courantLP->ts < ts)
    {
      
      listePointure *newLP5 = (listePointure *)malloc(sizeof(listePointure)); 
      creep (newLP5);
      newLP5->ts = ts;
      courantLP->suiv = newLP5; 
      courantLP = newLP5 ;
    }
    else { 
      while (chik->ts != ts)
      {
      
        chik = chik->suiv ;

      }
      courantLP = chik ;

    }
    
  }

 
    

  switch (y)
  {
  case 0 : 
    if(strcmp("IDF", code) == 0){
        while (courantLP->tab1 != NULL)
          {
            if((strcmp(entite, courantLP->tab1->elm.name) == 0)) break;
            courantLP->tab1 = courantLP->tab1->suiv;
          }

          if (courantLP->tab1 == NULL) {inserer(entite, code, type, val, 0, y);
          courantLP->tab1=tab;
          }
    }

    else{
      while (courantLP->tab1 != NULL)
          {
            courantLP->tab1 = courantLP->tab1->suiv;
          }

          if (courantLP->tab1 == NULL) {inserer(entite, code, type, val , 0, y);
            courantLP->tab1=tab;
          }
    }

    break;

  case 1 : 

    while (courantLP->tab2 != NULL && (courantLP->tab2->elm.state == 1) && (strcmp(entite, courantLP->tab2->elm.name) != 0))
    {
      courantLP->tab2 = courantLP->tab2->suiv;
    }
    printf("%dttttttttttt\n",ts);
    if (courantLP->tab2 == NULL) {inserer(entite, code, type, val, 0, y);
    courantLP->tab2=tabMotCle;}
    break;

  case 2 : 

    while (courantLP->tab3 != NULL && (courantLP->tab3->elm.state == 1) && (strcmp(entite, courantLP->tab3->elm.name) != 0))
    {
      courantLP->tab3 = courantLP->tab3->suiv;
    }

    if (courantLP->tab3 == NULL) {inserer(entite, code, type, val, 0, y);
    courantLP->tab3=tabSeparateur;}
    break;
  }
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
    printf("\t|                         Table des IDF  %d                       |\n",courantLP->ts);
    printf("\t|_______________________________________________________________|\n");
    printf("\t|  Nom_Entite  |   Code_Entite  |  Type_Entite |   Val_Entite   |\n");
    printf("\t|______________|________________|______________|________________|\n");

    
    

    while (currentIDF != NULL)
    {
      printf("\t|%13s | %14s | %12s | %14f |\n", currentIDF->elm.name, currentIDF->elm.code, currentIDF->elm.type, currentIDF->elm.val);
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
        // Check if Nom_Entite matches the specified condition
        if (strcmp(entite, courant->elm.name) == 0) {
            // Modify the Type_Entite if the condition is met
            strcpy(courant->elm.type, newType);
            break;  // Assuming only one match is needed
        }
        courant = courant->suiv;
    }
}

void printTypeOfIDF(const char* entite) {
    tabIDF *courant = tab;

    while (courant != NULL) {
        // Check if Nom_Entite matches the specified condition
        if (strcmp(entite, courant->elm.name) == 0) {
            // Print the Type_Entite if the condition is met
            printf("Type of %s: %s\n", entite, courant->elm.type);
            return;  // Exit the function after printing
        }
        courant = courant->suiv;
    }

    // If the identifier is not found, print "Unknown" (or an appropriate value)
    printf("Type of %s: Unknown\n", entite);
}
int verifyTypeEntite(const char* entite) {
    tabIDF *courant = tab;

    while (courant != NULL) {
        if (strcmp(entite, courant->elm.name) == 0) {
            if (strcmp(courant->elm.type, "Identifier") == 0) {
                return 0;  // Type matches, return 0
            } else {
                return 1;  // Type doesn't match, return 1
            }
        }
        courant = courant->suiv;
    }

    return -1;  // Identifier not found, return -1
}


