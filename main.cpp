#include <iostream>
#include <fstream>
#include <cwchar>
using namespace std;
int** nowy_sklad(int w , int k) {
    int **tab;
    tab = new int *[w];
    for (int i = 0; i != w; i++) {
        tab[i] = new int[k];
    }
    for(int i=0 ; i<=k ; i++){
        tab[0][i]=0;
    }
    return tab;
}
int** wybor_postaci(int **tab) {
    int pozycja = -1, postac = -1;
    cout << "Wybierz pierwsza postac kazda postac posiada swoje atrybuty" << endl;
    cout << "| MED |WSPAR| DOW |SNIPR|TECHN|" << endl;
    cout << "|  O  |  O  |  O  |  O  |  O  |" << endl;
    cout << "| /|\\ | /|\\ | /|\\ | /|\\ | /|\\ |" << endl;
    cout << "| / \\ | / \\ | / \\ | / \\ | / \\ |" << endl;
    cout << " ATK 5 ATK 8 ATK 5 ATK 12 ATK 10" << endl;
    cout << " DEF 4 DEF 7 DEF 6 DEF 3  DEF 10" << endl;
    cout << " HP 16 HP 10 HP 14 HP 10  HP 6  " << endl;
    cout << "Gdzie chcesz ustawic swoja postac?" << endl;
    if (tab[0][0] == 0 && tab[0][1] == 0 && tab[0][2] == 0 && tab[0][3] == 0 && tab[0][4] == 0) {
        cout
                << "Postacie mozesz ustawiac na pozycjach od 0 do 4 im wieksa lczba tym postac bedzie stac blizej prawej oraz przeciwnikow przez co bedzie otrzymywac wieksze obrazenia"
                << endl;
        while (pozycja > 4 || pozycja < 0) {
            cout << "Gdzie ustawiamy pierwsza postac?" << endl;
            cin >> pozycja;
        }
    }
    else {
        cout << "Mozesz ustawic postac na pozycjach:";
        for (int i = 0; i <= 4; i++) {
            if (tab[0][i] == 0) {
                cout << " " << i;
            }
        }
        cout << endl;
        cin >> pozycja;
    }
    tab[0][pozycja]=1;
    cout << "1-Medyk" << endl;
    cout << "2-Wsparcie" << endl;
    cout << "3-Dowodca" << endl;
    cout << "4-Snajper" << endl;
    cout << "5-Technik" << endl;
    while (postac > 5 || postac < 0){
        cout << "Ktora postac wybierasz?" << endl;
        cin >> postac;
    }
    tab[1][pozycja]=postac;
    tab[2][pozycja]=-9-postac;
    tab[3][pozycja]=-1;
    tab[4][pozycja]=-2;
    tab[5][pozycja]=-3;
    if(postac==1){
        tab[6][pozycja]=5;
        tab[7][pozycja]=4;
        tab[8][pozycja]=16;
    }
    if(postac==2){
        tab[6][pozycja]=8;
        tab[7][pozycja]=7;
        tab[8][pozycja]=10;
    }
    if(postac==3){
        tab[6][pozycja]=5;
        tab[7][pozycja]=6;
        tab[8][pozycja]=14;
    }
    if(postac==4){
        tab[6][pozycja]=12;
        tab[7][pozycja]=3;
        tab[8][pozycja]=10;
    }
    if(postac==5){
        tab[6][pozycja]=10;
        tab[7][pozycja]=10;
        tab[8][pozycja]=6;
    }
    return tab;
}

int main() {
    char nowa_gra;
    int **sklad;
    while(nowa_gra!='T'||nowa_gra!='N') {
        cout << "Czy chcesz stworzyc nowa gre?" << endl << "T-Tak" << endl << "N-Nie" << endl;
        cin >> nowa_gra;
        if(nowa_gra=='T'){
            sklad=nowy_sklad(9,5);
            sklad=wybor_postaci(sklad);
            break;
        }
        else{

        }
    }
    for(int i=0;i<9;i++) {
        cout << sklad[i][0] << endl;
    }
}
