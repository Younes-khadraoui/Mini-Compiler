#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int ts;
  tabIDF *tab1;
  tabSepMc *tab2;
  tabSepMc *tab3;
  struct listePointure * suiv;
} listePointure;

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


listePointure *tabLP = NULL;
tabIDF *tab = NULL;
tabSepMc *tabSeparateur = NULL;
tabSepMc *tabMotCle = NULL;

listePointure * FinListePointure()
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
 tabSepMc *newSEP = (tabSepMC *)malloc(sizeof(tabSepMc));

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
    listePointure *newLP = (listePointure *)malloc(sizeof(listePointure));
    tabLP = newLP;
    newLP->suiv = NULL;
    newLP->tab1 = tab;
    newLP->tab2 = tabMotCle;
    newLP->tab3 = tabSeparateur;
    newLP->ts = 0;
  }
  else
  {
    courantLP = FinListePointure;
    if(courantLP->ts < ts)
    {
      
      listePointure *newLP = (listePointure *)malloc(sizeof(listePointure));
      /*
      newLP->tab1 = tab;
      newLP->tab2 = tabMotCle;
      newLP->tab3 = tabSeparateur;
      */
      creep (newLP);
      newLP->ts = ts;
    }
    else {
      
      while (chik->ts  < ts)
      {

        chik =  chik->suiv ;

      }
      courantLP = chik ;

    }
  }

 

  switch (y)
  {

  case 0 : 
    if(strcmp("IDF", code) == 0){
        while (newLP->tab1 != NULL)
          {
            if((strcmp(entite, newLP->tab1->elm.name) == 0)) break;
            newLP->tab1 = newLP->tab1->suiv;
          }

          if (newLP->tab1 == NULL) inserer(entite, code, type, val, 0, y);
    }

    else{
      while (newLP->tab1 != NULL)
          {
            newLP->tab1 = newLP->tab1->suiv;
          }

          if (newLP->tab1 == NULL) inserer(entite, code, type, val , 0, y);
    }

    break;

  case 1 : 

    while (newLP->tab2 != NULL && (newLP->tab2->elm.state == 1) && (strcmp(entite, newLP->tab2->elm.name) != 0))
    {
      newLP->tab2 = newLP->tab2->suiv;
    }
    if (newLP->tab2 == NULL) inserer(entite, code, type, val, 0, y);
    break;

  case 2 : 

    while (newLP->tab3 != NULL && (newLP->tab3->elm.state == 1) && (strcmp(entite, newLP->tab3->elm.name) != 0))
    {
      newLP->tab3 = newLP->tab3->suiv;
    }

    if (newLP->tab3 == NULL) inserer(entite, code, type, val, 0, y);
    break;
  }
}


void afficher()
{
  printf("\n\t _______________________________________________________________\n");
  printf("\t|                         Table des IDF                         |\n");
  printf("\t|_______________________________________________________________|\n");
  printf("\t|  Nom_Entite  |   Code_Entite  |  Type_Entite |   Val_Entite   |\n");
  printf("\t|______________|________________|______________|________________|\n");

  tabIDF *currentIDF = tab;
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

  tabSepMc *courantM = tabMotCle;
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

  tabSepMc *courantS = tabSeparateur;
  while (courantS != NULL)
  {
    printf("\t|%10s   |%12s | \n", courantS->elm.name, courantS->elm.type);
    courantS = courantS->suiv;
  }
  printf("\t|_____________|_____________|\n");
}


void modifyType(char entite[], char newType[]) {
    tabIDF *courant = tab;

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

