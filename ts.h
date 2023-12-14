/****************CREATION DE LA TABLE DES SYMBOLES ******************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
typedef struct element
{
    char name[20];
    char type[20];
    float val;
    struct element* suiv;
} element;

typedef struct elt
{
    char name[20];
    char type[20];
    struct elt *suiv;
} elt;
element* tab[1017];
elt *tabs[47],*tabm[47];
extern char sav[20];

int hach(char entite[],int table_length)
{
    int taille,i;
    long long value = 0;
    taille = strlen(entite);
    for(i=0; i<taille; i++)
    {
        value+=entite[i]*pow(3,i+1);
    }
    return value%table_length;
}

void inserer (char entite[],char type[],float val, int y)
{

    int value;
    element* new_element=NULL;
    elt* new_elt=NULL;
    switch (y)
    {
    case 0://IDF et CONST
        new_element=(element*)malloc(sizeof(element));
        strcpy(new_element->name,entite);
        strcpy(new_element->type,type);
        new_element->val=val;
        new_element->suiv=NULL;
        value =  hach(entite,1017);
        if(tab[value]==NULL)
        {
            tab[value]=new_element;
        }
        else
        {
            element* p=tab[value];
            while(p->suiv!=NULL)
            {
                p=p->suiv;
            }
            p->suiv=new_element;
        }
        break;

    case 1://mots cles
        new_elt=(elt*)malloc(sizeof(elt));
        strcpy(new_elt->name,entite);
        strcpy(new_elt->type,type);
        new_elt->suiv=NULL;
        value =  hach(entite,47);
        if(tabm[value]==NULL)
        {
            tabm[value]=new_elt;
        }
        else
        {
            elt* p=tabm[value];
            while(p->suiv!=NULL)
            {
                p=p->suiv;
            }
            p->suiv=new_elt;
        }
        break;

    case 2:// separateurs
        new_elt=(elt*)malloc(sizeof(elt));
        strcpy(new_elt->name,entite);
        strcpy(new_elt->type,type);
        new_elt->suiv=NULL;
        value =  hach(entite,47);
        if(tabs[value]==NULL)
        {
            tabs[value]=new_elt;
        }
        else
        {
            elt* p=tabs[value];
            while(p->suiv!=NULL)
            {
                p=p->suiv;
            }
            p->suiv=new_elt;
        }
        break;
    }

}

void rechercher (char entite[],char type[],float val,int y)
{
    bool check=false;
    int value;
    element *p;
    elt *b;
    switch(y)
    {
    case 0://IDF et CONST 
        value=hach(entite,1017);
        p=tab[value];
        while(p!=NULL&&check==false)
        {
            if(strcmp(entite,p->name)==0) check=true;
            p=p->suiv;
        }
        if(check==false) inserer(entite,type,val,y);
    break;

    case 1://mots cles

        value=hach(entite,47);
        b=tabm[value];
        while(b!=NULL&&check==false)
        {
            if(strcmp(entite,b->name)==0) check=true;
            b=b->suiv;
        }
        if(check==false) inserer(entite,type,val,y);
        break;

    case 2://separateurs
        value=hach(entite,47);
        b=tabs[value];
        while(b!=NULL&&check==false)
        {
            if(strcmp(entite,b->name)==0) check=true;
            b=b->suiv;
        }
        if(check==false) inserer(entite,type,val,y);
        break;
    }

}

void afficher()
{int i;
    element *p;
    elt *b;

printf("/***************Table des symboles IDF*************/\n");
printf("____________________________________________________________________\n");
printf("\t| Nom_Entite | Type_Entite | Val_Entite\n");
printf("____________________________________________________________________\n");

for(i=0;i<1017;i++)
{
    p=tab[i];
    while(p!=NULL)
    {
        printf("\t|%10s     | %12s      | %12f\n",p->name,p->type,p->val);
        p=p->suiv;
    }

}


printf("\n/***************Table des symboles mots cles*************/\n");

printf("_____________________________________\n");
printf("\t| NomEntite |  Type_Entite | \n");
printf("_____________________________________\n");

for(i=0;i<47;i++)
      {
          b=tabm[i];
          while(b!=NULL)
          {
               printf("\t|%10s      |%12s       | \n",b->name, b->type);
               b=b->suiv;

          }

      }

printf("\n/***************Table des symboles separateurs*************/\n");

printf("_____________________________________\n");
printf("\t| NomEntite |  Type_Entite | \n");
printf("_____________________________________\n");

for(i=0;i<47;i++)
      {
         b=tabs[i];
          while(b!=NULL)
          {
               printf("\t|%10s       |%12s       | \n",b->name, b->type);
               b=b->suiv;

          }
      }

}





