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

void rechercher1(char entite[], char code[], char type[], float val, int y , int ts )
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
    courantLP->tab1=tabLP->tab1;    
    courantLP->tab2=tabLP->tab2;   
    courantLP->tab3=tabLP->tab3;
    courantLP->ts=ts;    
  }
  else
  {
    

    courantLP = FinListePointure();
    if(courantLP->ts != ts)
    {
      
      listePointure *newLP5 = (listePointure *)malloc(sizeof(listePointure)); 
      newLP5->tab1=tab;
      newLP5->tab2=tabMotCle;
      newLP5->tab3=tabSeparateur;
      newLP5->ts = ts;
      newLP5->suiv=NULL;
      courantLP->ts=newLP5->ts;
      courantLP->suiv = newLP5; 
      courantLP->tab2=newLP5->tab2;
      courantLP->tab3=newLP5->tab3;
      courantLP = newLP5 ;
      tab=NULL;
      tabMotCle=NULL;
      tabSeparateur=NULL;

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
        while ((courantLP->tab1 != NULL) && ((strcmp(entite, courantLP->tab1->elm.name) != 0)))
          {
            courantLP->tab1 = courantLP->tab1->suiv;
          }

          if (courantLP->tab1 == NULL) {                        printf(" Element NON  Declarerrrrrrrrrrrrrrrrrrrrrrrrrrrr %s\n",entite);
          }
          courantLP->tab1=tab;
          
    }

    else{
      while (courantLP->tab1 != NULL)
          {
            courantLP->tab1 = courantLP->tab1->suiv;
          }

          if (courantLP->tab1 == NULL) inserer(entite, code, type, val , 0, y);
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

    if (courantLP->tab3 == NULL)inserer(entite, code, type, val, 0, y);
         courantLP->tab3=tabSeparateur;
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

char* printTypeOfIDF(const char* entite) {
    tabIDF *courant = tab;

    while (courant != NULL) {
        // Check if Nom_Entite matches the specified condition
        if (strcmp(entite, courant->elm.name) == 0) {
            // Print the Type_Entite if the condition is met
            return courant->elm.type;  // Exit the function after printing
        }
        courant = courant->suiv;
    }

    // If the identifier is not found, print "Unknown" (or an appropriate value)
    return"Type : Unknown\n";
}

int verifyTypeEntite(const char* entite) {
    listePointure *tabl=tabLP;
    tabIDF *courant = tabl->tab1;

    while (courant != NULL) {
        if (strcmp(entite, courant->elm.name) == 0) {
                return 1;  // Type matches, return 0
            } else {
                return 0;  // Type doesn't match, return 1
            }
        courant = courant->suiv;
    }

    return -1;  // Identifier not found, return -1
}

void modifyValueOfIDF(const char* entite, void* nouvelleValeur, int type, int ts) {
    listePointure *courantLP = tabLP;
    tabIDF *courant;

    // Recherche de la listePointure appropriée
    while (courantLP != NULL && courantLP->ts != ts) {
        courantLP = courantLP->suiv;
    }

    // Si la listePointure n'existe pas encore, vous pouvez choisir de créer une nouvelle listePointure ici.

    // Recherche de l'IDF dans la listePointure
    if (courantLP != NULL) {
        courant = courantLP->tab1;

        while (courant != NULL) {
            if (strcmp(entite, courant->elm.name) == 0) {
                // Modification de la valeur de l'entité en fonction du type
                        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2%s",nouvelleValeur);
                switch (type) {
                    case 0: // int
                        courant->elm.val = *(int*)nouvelleValeur;
                        break;
                    case 1: // float
                        courant->elm.val = *(float*)nouvelleValeur;
                        break;
                    case 2: // string
                        strcpy(courant->elm.type, (char*)nouvelleValeur);
                        break;
                    case 3: // boolean
                        courant->elm.val = *(int*)nouvelleValeur; // Assuming boolean is represented as an integer (0 or 1)
                        break;
                    default:
                        // Handle unsupported type
                        printf("Type non pris en charge : %d\n", type);
                        return;
                }
                return;  // Sortie de la fonction après la modification
            }
            courant = courant->suiv;
        }
    }

    // Si l'entité n'est pas trouvée, vous pouvez choisir de gérer cela d'une manière spécifique.
    printf("Entité non trouvée : %s\n", entite);
}

int incompatibiliteDeType(char var[], char typeval[]) {
    tabIDF* courant = tab;
    while (courant != NULL) {
        if ((strcmp(var, courant->elm.name) == 0) && (strcmp(typeval, courant->elm.type) == 0)) return 0 ; // aucune erreur
        courant = courant->suiv;
    }
    return 1 ; // il existe une incompatibilité de type
}


