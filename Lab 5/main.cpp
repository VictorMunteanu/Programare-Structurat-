#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <string.h>

using namespace std;
int Nr_Cuvinte(char fraza[]);
int Fraza_Majuscule(char fraza[], int key);
void Sters_Cuvintele(char fraza[]);

void Citire();
void Fisier_Majuscule(char fraza[]);
int Sters_CuvinteFraza(char fraza[]);
int Lung_Cuvint(char fraza[]);

using namespace std;
   char fraza1[81];
int main()
{
    FILE *f;
    char c[81];
	int optiune, nru, op;
	int nr;
	int F1;
	char fraza[81] = "VISELE OAMENILOR sunt aripi cu care acestea zboara spre cer.";
    do
    {
        system("cls");
    	cout << "\t\t\tCuvintele cu litere majuscule\n\n";
        cout << "1. Intr-o fraza de determinat numarul de cuvinte.\n";
        cout << "2.	De determinat cuvintele dintr-o fraza, cu litere majuscule\n";
        cout << "3. De sters cuvintele dintr-o fraza, care contin litere majuscule\n";
        cout << "4.	Intr-un fisier text de determinat numărul de cuvinte\n";
        cout << "5. De inscris in alt fisier text cuvintele, care contin litera majuscula\n";
        cout << "6.	De sters cuvintele dintr-un fisier text, care contin litere majuscule.\n";
        cout << "7.	Cel mai lung cuvint scris cu litere majuscule.\n";
        cout << "0.Exit\n\n";
        cin >> optiune;
        switch(optiune)
        {
        	case 1:
  			system("cls");
  			puts("Fraza initiala");
            puts(fraza);
            cout << "In total sint " << Nr_Cuvinte(fraza) << " cuvinte. ";
            cout << "\n\nApasa Enter pentru a reveni la meniul initial";
        	_getch();
        break;

        case 2:
            puts("Fraza initiala");
            
            puts(fraza);
            cout<< "L ecran 0 fisier 1- ";
            cin >> op;
            nru = Fraza_Majuscule(fraza,op);
            if(nru >= 0)
                cout << "\n In total sint " << nru << " cuvinte cu litere majuscule ";
            else
                cout << "Nu sunt cuvintele" << endl;
                cout << "\n\nApasa Enter pentru a reveni la meniul initial";
            _getch();
        break;
        case 3:
            puts("Fraza initiala");
            puts(fraza);
            cout << "\n Fraza modificata la stergerea cuvintelor cu litere majuscule: \n ";
            Sters_Cuvintele(fraza);
            puts(fraza);
            cout << "\n\nApasa Enter pentru a reveni la meniul initial";
            _getch();
        break;
        case 4:
            cout << "Intr-un fisier text de determinat numarul de cuvinte.\n";
            Citire();
            nr = Nr_Cuvinte(fraza1);
            if(nr >=0)
                cout << "In fisier sunt " << nr <<" cuvinte.";
            else
                cout << "Nu-s cuvinte";
            cout << "\n\nApasa Enter pentru a reveni la meniul initial";
            getch();
            system("cls");
        break;
        case 5:
            cout << "Intr-un fisier text de determinat numarul de cuvinte.\n";
            Citire();
            Fisier_Majuscule(fraza1);
            cout << "\n\nApasa Enter pentru a reveni la meniul initial";
            getch();
            system("cls");
        break;
        case 6:
            cout << "De sters cuvintele dintr-un fisier text, care contin litere majuscule.\n";
            Citire();
            Sters_Cuvintele(fraza1);
            f = fopen("Fraza.txt", "w");
            fputs(fraza1, f);
            fclose(f);
            cout << "\n\nApasa Enter pentru a reveni la meniul initial";
            getch();
            system("cls");
        break;
         case 7:
            system("cls");
  			puts("Fraza initiala");
            puts(fraza);
            Lung_Cuvint(fraza);
            cout << "Cel mai lung cuvint cu litere majuscule este cuvint din: " << Lung_Cuvint(fraza) <<" litere" ;

            cout << "\n\nApasa Enter pentru a reveni la meniul initial";
        	_getch();
        break;
  		}

    }while(optiune);

    return 1;
}

int Nr_Cuvinte(char fraza[])
{
    int n = 0;
    char *cuvint, copia [81];
    strcpy(copia, fraza);
    if((cuvint = strtok(copia, " \n,.//?!-+:")) == NULL)
        return 0;
    n = 1;
    while((cuvint = strtok(NULL, " \n,.//?!-+")) != NULL)
            n++;
    return n;
}

bool LitereMari(char cuvint[])
{
    for(int i = 0; i < strlen(cuvint); i++)
    {
        if(!isalpha(cuvint[i])) return false;
        if(islower(cuvint[i])) return false;
    }
    return true;
}


int Fraza_Majuscule(char fraza[], int key)
{
    int nr = 0;
    char *cuvint, copia[81];
    strcpy(copia, fraza);
    if((cuvint = strtok(copia, " ,!?.:-_+/\n")) == NULL)
        return 0;
    if (LitereMari(cuvint))
    {
        if(key)
        {

        }
        else puts(cuvint);
        nr = 1;
    }
    while ((cuvint = strtok(NULL, " ,!?.:-_+/\n")) != NULL)
    {
        if (LitereMari(cuvint))
            {
                if(key)
                {
                   
                }
                else puts(cuvint);
                nr++;
            }
    }
return nr;
}

void Sters_Cuvintele(char fraza[])
{
    int k = 0;
    char *cuvant, copia[81];
    strcpy(copia, fraza);
    if((cuvant = strtok(copia,",.!?:; ")) == NULL)
        return;
    strcpy(fraza,"");
    for(int i = 0;i < strlen(cuvant);i++)
    {
        if((cuvant[i] >= 'a') && (cuvant[i] <= 'z'))
        {
            k++;
        }
    }
    if(k == strlen(cuvant))
    {
        strcat(fraza, cuvant);
        strcat(fraza, " ");
    }
    while((cuvant = strtok(NULL,",.!?:; ")) != NULL){
            k =0;
        for(int i=0;i<strlen(cuvant);i++)
        {
            if((cuvant[i] >= 'a') && (cuvant[i] <= 'z'))
            {
                k++;

            }
        }
        if(k == strlen(cuvant))
        {
            strcat(fraza, cuvant);
            strcat(fraza, " ");
        }
    }
}

void Citire()
{
   FILE *f = fopen("Fraza.txt" , "r");
   char  mystring [81];

   if (f == NULL) cout <<"Eroare";
   else
   {
     if ( fgets(fraza1,81, f) != NULL )
       puts(fraza1);
     fclose (f);
   }
}

void Fisier_Majuscule(char fraza[])
{
    int k = 0;
    char *cuvant, copia[81], fraza2[81];
    FILE *f;
    strcpy(copia, fraza);
    f = fopen("Fraza2.txt", "w");
    if((cuvant = strtok(copia,",.!?:; ")) == NULL)
        return;
    for(int i=0;i < strlen(cuvant);i++)
    {
        if((cuvant[i] >= 'A') && (cuvant[i] <= 'Z'))
        {
            k++;

        }
    }
    if(k == strlen(cuvant))
    {
        fputs(cuvant, f);
        fputs(" ", f);
    }
    while((cuvant = strtok(NULL,",.!?:; ")) != NULL){
            k =0;
        for(int i=0;i<strlen(cuvant);i++)
        {
            if((cuvant[i] >= 'A') && (cuvant[i] <= 'Z'))
            {
                k++;

            }
        }
        if(k == strlen(cuvant))
        {
            fputs(cuvant, f);
            fputs(" ", f);
        }
    }
    fclose(f);
    cout << "Datele au fost inscrise in fisier!";
}

int Lung_Cuvint(char fraza[])
{
    int k = 0;
    int maxim = 0;
    char *cuvant, copia[81];
    strcpy(copia, fraza);
    if((cuvant = strtok(copia,",.!?:; ")) == NULL)
        return 0;
    for(int i = 0;i < strlen(cuvant);i++)
    {
        if((cuvant[i] >= 'A') && (cuvant[i] <= 'Z'))
        {
            k++;
        }
    }
    if((k == strlen(cuvant)) && (maxim < strlen(cuvant)))
    {
       maxim = strlen(cuvant);
    }
    while((cuvant = strtok(NULL,",.!?:; ")) != NULL){
            k =0;
        for(int i=0;i  <strlen(cuvant);i++)
        {
            if((cuvant[i] >= 'A') && (cuvant[i] <= 'Z'))
            {
                k++;

            }
        }
        if((k == strlen(cuvant)) && (maxim < strlen(cuvant)))
    {
       maxim = strlen(cuvant);
    }
    }
    return maxim;
}
