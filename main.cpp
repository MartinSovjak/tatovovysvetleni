#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int zkontrolujPole(int*,int);
int zkontrolujZnaky(string);
int main()
{
    int pocetA,pocetB;
    string cislaA,cislaB;

    cout << "Zadejte pocet prvku mnoziny A:" << endl;
    cin >> pocetA;
    if (pocetA < 1 || cin.fail()){
        cout << "Nespravny vstup." << endl;
    }

    else {

            cin.ignore();
        cout << "Zadejte prvky mnoziny A:" << endl;

        getline(cin,cislaA);

        int znakyOkay = zkontrolujZnaky(cislaA);
        if (znakyOkay == 1)
            cout << "Nespravny vstup." << endl;
        else {
            int* pole = new int[pocetA];
            stringstream ss(cislaA);

            int mistoPole = 0;
            while (mistoPole < pocetA){
                ss >> pole[mistoPole];
                mistoPole++;
            }
            int okay = zkontrolujPole(pole,pocetA);

            if (okay == 1)
                cout << "Nespravny vstup." << endl;
            else {
                cout << "Zadejte pocet prvku mnoziny B:" << endl;
                cin >> pocetB;
                if (pocetB < 1 || cin.fail()){
                    cout << "Nespravny vstup." << endl;
                }
                else {
                    cin.ignore();
                    cout << "Zadejte prvky mnoziny B:" << endl;

                    getline(cin,cislaB);
                    znakyOkay = zkontrolujZnaky(cislaB);
                    if (znakyOkay == 1)
                        cout << "Nespravny vstup." << endl;
                    else {
                        int* pole2 = new int[pocetB];
                        stringstream ss(cislaB);

                        mistoPole = 0;
                        while (mistoPole < pocetB){
                            ss >> pole2[mistoPole];
                            mistoPole++;
                        }
                        okay = zkontrolujPole(pole2,pocetA);
                        if (okay == 1)
                            cout << "Nespravny vstup." << endl;
                        else {
                            cout << "Prunik mnozin:" << endl << "{";
                            int bruh = 0;
                            for (int i = 0; i < pocetA; i++){
                                for (int j = 0; j < pocetB; j++){
                                    if (pole[i] == pole2[j]){
                                        if (bruh < 1){
                                            cout << pole[i];
                                            bruh++;
                                        }
                                        else {
                                            cout << ", " << pole[i];
                                        }
                                    }


                                }
                            }
                            cout << "}" << endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int zkontrolujPole(int* pole, int pocet){
    for (int i = 0;i < pocet; i++){

        for (int j = i+1; j < pocet; j++){
            if (pole[i]==pole[j])
                return(1);
        }
    }
    return (0);
}
int zkontrolujZnaky(string cisla){
    int delka = cisla.length();

    for (int i = 0;i < delka; i++){
        if ((cisla.at(i) < '0' || cisla.at(i) > '9') && cisla.at(i) != 32)
            return (1);
    }

    return (0);
}
