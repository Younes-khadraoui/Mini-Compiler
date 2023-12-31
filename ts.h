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

tabIDF *tab = NULL;
tabSepMc *tabSeparateur = NULL;
tabSepMc *tabMotCle = NULL;


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


void rechercher(char entite[], char code[], char type[], float val, int y)
{
  int j, i;
  tabIDF *courant = tab;
  tabSepMc *courantM = tabMotCle;
  tabSepMc *courantS = tabSeparateur;

  switch (y)
  {

  case 0 : 
    if(strcmp("IDF", code) == 0){
        while (courant != NULL)
          {
            if((strcmp(entite, courant->elm.name) == 0)) break;
            courant = courant->suiv;
          }

          if (courant == NULL) inserer(entite, code, type, val, 0, y);
    }

    else{
      while (courant != NULL)
          {
            courant = courant->suiv;
          }

          if (courant == NULL) inserer(entite, code, type, val , 0, y);
    }

    break;

  case 1 : 

    while (courantM != NULL && (courantM->elm.state == 1) && (strcmp(entite, courantM->elm.name) != 0))
    {
      courantM = courantM->suiv;
    }
    if (courantM == NULL) inserer(entite, code, type, val, 0, y);
    break;

  case 2 : 

    while (courantS != NULL && (courantS->elm.state == 1) && (strcmp(entite, courantS->elm.name) != 0))
    {
      courantS = courantS->suiv;
    }

    if (courantS == NULL) inserer(entite, code, type, val, 0, y);
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

