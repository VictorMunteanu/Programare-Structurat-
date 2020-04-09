#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

int NrCifre(int n);
int Prim(int n);
int Briliant(int n);

int main()
{

    int key;
    int n, a, b, i, nr, A, k = 0;
    int cont = 0;
    do{
            system("cls");
        cout << "1. De verificat daca numarul satisface conditia" << endl;
        cout << "2. De afisat toate numerele din intervalul [a, b] care satisfac conditia" << endl;
        cout << "3. De afisat primele n numere care satisfac conditia" << endl;
        cout << "4. De afisat toate numerele din intervalul [a, b] care satisfac a 2 conditie" << endl;
        cout << "5. De afisat valoarea maxima care satisface conditia" << endl;
        cout << "0. Exit" << endl;
        cout << "\t\tSelecteaza o optiune ==> ";
        cin >> key;
    switch(key){
            case 1:
                system("cls");
                cout <<"Introduceti numarul ce trebuie verificat = ";
                cin >> n;
                if (Briliant(n)) cout <<"Numarul "<<n<<" este numar briliant";
                             else
                             cout <<"Numarul "<<n<<" nu este briliant";
            getch();
            break;

            case 2:
                system("cls");
                cout <<"Introduceti limita de stinga a intervalului ";
                cin >>a;
                cout <<"Introduceti limita de dreapta a intervalului ";
                cin >>b;
                cout <<"In intervalul dat sunt următoarele numere " <<endl;
                for (i = a; i<=b; i++){
                    if (Briliant(i)){
                        cout << i <<" ";
                        cont ++;
                    }
                }
                cout <<endl;
                if (cont == 0) cout <<"In intervalul dat nu sunt numere briliante";
                                else
                               cout <<"In intervalul ["<<a<<";"<<b<<"] sunt "<<cont<<" numere briliante";
            getch();
            break;

            case 3:
                system("cls");
                cout <<"Cite cifre doriti sa afisam = ";
                cin >>nr;
                i = 0;
                cont = 0;
                while((cont < nr) && (i<INT_MAX)){
                    if(Briliant(i)){
                        cout << i <<" ";
                        cont++;
                    }
                    i++;
                }
            getch();
            break;

            case 4:
                system("cls");
                cout << "Dati inceputul intervalului ";
                cin >> a;

                cout << "Dati sfirsitul intervalului ";
                cin >> A;

                cout << "Briliant!" << endl;
                cout << "\nNumere briliante de la " << a << " la " << A << endl;
                for(n = 0; n <= A; n++){
                if(Briliant(n)) {
                    cout << setw(8) << n;
                    k++;
                }
                }
                cout << "\n In total: " << k;
                return 0;
            getch();
            break;

            case 5:
                system("cls");

                if(Briliant(INT_MAX)){
                    cout << INT_MAX;
                }
                else {
                    cout << INT_MAX - 1;
                }
            getch();
            break;


    }
    }while(key != 0);

    return 0;
}

int NrCifre(int n) {
    int i;
    for(i = 0; n > 0; i++)
        n /= 10;
        return i;
}

int Prim(int n) {
    for(int i = 2; i <= n/2; i++)
        if(n%i == 0) return 0;
    return 1;
}

int Briliant(int n) {
    int i, j, s1;
    for(i = 2; i <= sqrt(n); i++) {
        s1 = NrCifre(i);
        for(j = 2;j <= n/2; j++)
            if(NrCifre(j) == s1)
                if(Prim(i) && Prim(j) && (i*j == n)) return 1;
    }
    return 0;
}
