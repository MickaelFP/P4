#include <iostream>
#include <time.h>
//#include <vector>
//#include <Windows.h> FONCTIONNE QUE SUR VISUAL

using namespace std;

void verifvictory(int tab[6][7], int ligne, int colonne, int joueur) {
    //lignes
    //tab[ligne][colonne]
    int compteur = 0;
    for(int j = colonne-3; j <= colonne + 3; j++) {
        if(j < 0 || j > 6) {
            continue;
        }
        else {
            if (tab[ligne][j] == joueur) {
                compteur++;
                if (compteur >= 4) {
                    cout << "GAGNE";
                }
            }
            else {
                compteur = 0;
            }
        }
    }
    cout << compteur << endl;
    //colonnes
    //tab[ligne][colonne]
    for(int i = ligne-3; i <= ligne + 3; i++) { 
        if(i < 0 || i > 5) {
            continue;
        }
        else {
            if (tab[i][colonne] == joueur) {
                compteur++;
                if (compteur >= 4) {
                    cout << "GAGNE";
                }
            }
        }
    }
    
    //diagonales
    
}

void show(int a [6][7]) {
    for (int i = 0; i < 6; i++){
        
        std::cout << "| ";
        for (int j = 0; j < 7; j++){
        
            switch (a[i][j]) {
            case 0:
                cout << " ";
                break;
            case 1:
                cout << "X";
                break;
            case 2:
                cout << "O";
                break;
            default:
                break;
            }
            cout << " ";
        }
        cout << "|" << endl << "|---------------|" << endl;
    }
    cout << "  1 2 3 4 5 6 7  " << endl << endl;
}

int main() {
     
    srand(time(NULL));
    int tab[6][7] = { 0 };
    show(tab);
    
    /* test random
    for (int i = 0; i < 6; i++) {
        
        for (int j = 0; j < 7; j++) {
            tab[i][j] = (rand() % 2) + 1;
        }
        
    } */
    
    int colonne;
    bool j1 = true;
    while(1) {
        cout << (j1? "tour j1"  :"tour j2");
        cout << ", entrez un numéro de colonne : ";
        cin >> colonne;
        while(colonne < 1 || colonne > 7) {
            cout << "Mauvais numéro de colonne, réessayez : ";
            cin >> colonne;
        }
        colonne--;
        
        for (int i = 5; i >= 0; i--) {
            
            if (tab[i][colonne] == 0) {
                int joueur = 0;
                if(j1) {
                    tab[i][colonne] = 1;
                    joueur = 1;
                }
                else {
                    tab[i][colonne] = 2;
                    joueur = 2;
                }
                system("cls");
                cout << "Appel verifvictory : ";
                verifvictory(tab, i, colonne, joueur);
                j1 = !j1;
                break;
            }
            else if(i == 0) {
                cout<<"Colonne pleine!" << endl;
            }
    
        }
        show(tab);
        
    }

    return 0;
}
