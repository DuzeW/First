#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;
int** nowy_sklad(int w , int k) {
    int **tab;
    tab = new int *[w];
    for (int i = 0; i != w; i++) {
        tab[i] = new int[k];
    }
    for(int i=0 ; i<=k ; i++){
        for(int j=0 ; j<w ; j++) {
            tab[j][i] = 0;
        }
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
    if (tab[0][0] == 0 && tab[0][1] == 0 && tab[0][2] == 0 && tab[0][3] == 0 && tab[0][4] == 0) {
        cout
                << "Postacie mozesz ustawiac na pozycjach od 0 do 4"<< endl;
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
void zapis(int **tab) {
    cout <<"Trwa zapisywanie"<<endl;
    ofstream zapis;
    zapis.open("zapis.txt");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 5; j++) {
            zapis << tab[i][j] <<" ";
        }
        zapis << endl;
    }
    zapis.close();
    cout <<"Zapis udany"<<endl;
}
int** wczytanie(int **tab){
    cout << "Trwa wczytywanie zapisu..."<<endl;
    ifstream zapis("zapis.txt");
    if (!zapis.is_open()) {
        cout << "Nie mozna otworzyc zapisu!" << endl;
        exit(1);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            zapis >> tab[i][j];
        }
    }
    cout << "Wczytano zapis"<<endl;
    zapis.close();
    return tab;
}
void pokaz_sklad(int **tab){
    cout<<"Twoj zespol"<<endl;
    cout<<"|   0   |   1   |   2   |   3   |   4   |"<<endl;
    for (int i = 1; i < 10; i++) {
        if(i==2){
            i++;
        }
        if(i!=9) {
            cout << "|";
        }
        for (int j = 0; j < 5; j++) {
            if(tab[i][j]==0){
                cout << "       ";
            }
            if(i==1){
                if (tab[i][j]==1){
                    cout << "  MED  ";
                }
                if (tab[i][j]==2){
                    cout << " WSPAR ";
                }
                if (tab[i][j]==3){
                    cout << "  DOW  ";
                }
                if (tab[i][j]==4){
                    cout << " SNIPR ";
                }
                if (tab[i][j]==5){
                    cout << " TECHN ";
                }
            }
            if(tab[i][j]==-1){
                cout << "   O   ";
            }
            if(tab[i][j]==-2){
                cout << "  /|\\  ";
            }
            if(tab[i][j]==-3){
                cout << "  / \\  ";
            }
            if(i==6){
                if(tab[i][j]>0&&tab[i][j]<10){
                    cout << "ATK   ";
                }
                if(tab[i][j]>=10&&tab[i][j]<100){
                    cout << "ATK  ";
                }
                if(tab[i][j]>=100&&tab[i][j]<1000){
                    cout << "ATK ";
                }
                if(tab[i][j]>=1000){
                    cout << "ATK";
                }
                if(tab[i][j]!=0) {
                    cout << tab[i][j];
                }
            }
            if(i==7){
                if(tab[i][j]>0&&tab[i][j]<10){
                    cout << "DEF   ";
                }
                if(tab[i][j]>=10&&tab[i][j]<100){
                    cout << "DEF  ";
                }
                if(tab[i][j]>=100&&tab[i][j]<1000){
                    cout << "DEF ";
                }
                if(tab[i][j]>=1000){
                    cout << "DEF";
                }
                if(tab[i][j]!=0) {
                    cout << tab[i][j];
                }
            }
            if(i==8){
                if(tab[i][j]>0&&tab[i][j]<10){
                    cout << "HP    ";
                }
                if(tab[i][j]>=10&&tab[i][j]<100){
                    cout << "HP   ";
                }
                if(tab[i][j]>=100&&tab[i][j]<1000){
                    cout << "HP  ";
                }
                if(tab[i][j]>=1000){
                    cout << "HP ";
                }
                if(tab[i][j]!=0) {
                    cout << tab[i][j];
                }
            }
            cout << "|";
        }
        cout << endl;
        if (i==8) {
            break;
        }
    }
}
void zapis_imie() {
    cout <<"Podaj swoje imie"<<endl;
    string imie;
    cin >> imie;
    ofstream zapis("imie.txt");
    zapis << imie;
    zapis.close();
}
void imie(){
    string imie;
    ifstream zapis("imie.txt");
    zapis >> imie;
    cout << imie;
    zapis.close();
}
int** wybor_broni(int **tab){
    pokaz_sklad(tab);
    cout<<"1-Luneta ATK x3"<<endl;
    cout<<"2-Zbroja DEF x3"<<endl;
    cout<<"3-Apteczka HP x3"<<endl;
    cout<<"4-Helm z noktowizorem DEF x2 , HP x2"<<endl;
    cout<<"5-Kamizelka z pistoletem ATK x2 , DEF x2"<<endl;
    cout<<"6-strzykawka z morfina ATK x2 , HP x2"<<endl;
    int b=-1,p;
    while(b>6||b<1){
        cout << "Wybierz dodatkowe wyposarzenie od 1 do 6" << endl;
        cin >> b;
    }
    cout << "Postaci na ktorej pozycji chcesz dac bron?" << endl;
    cin >>p;
    while(tab[0][p]!=1){
        cout << "Postaci na ktorej pozycji chcesz dac bron?" << endl;
        cin >>p;
    }
    if(b==1){
        tab[6][p]=tab[6][p]*3;
    }
    if(b==2){
        tab[7][p]=tab[7][p]*3;
    }
    if(b==3){
        tab[8][p]=tab[8][p]*3;
    }
    if(b==4){
        tab[7][p]=tab[7][p]*2;
        tab[8][p]=tab[8][p]*2;
    }
    if(b==5){
        tab[6][p]=tab[6][p]*2;
        tab[7][p]=tab[7][p]*2;
    }
    if(b==6){
        tab[6][p]=tab[6][p]*2;
        tab[8][p]=tab[8][p]*2;
    }
    return tab;
}
void cls(){
    for(int i=0; i<40; i++){
        cout<<"\n";
    }
}
void wyswietl_zombie(int **tab){
    cout<<"Przeciwnicy"<<endl;
    cout<<"|   0   |   1   |   2   |   3   |   4   |"<<endl;
    int k=5 , w=8;

    for (int i = 1; i < w; i++) {
        cout<<"|";
        for (int j = 0; j < k; j++) {
            if(tab[i][j]==0){
                cout<<"       ";
            }
            else{
                if(i==1){
                    if(tab[i][j]==1){
                        cout<<" ZOMBI ";
                    }
                }
                if(i==2){
                    if(tab[i][j]==1){
                        cout<<"   U_  ";
                    }
                }
                if(i==3){
                    if(tab[i][j]==1){
                        cout<<"  /|   ";
                    }
                }
                if(i==4){
                    if(tab[i][j]==1){
                        cout<<"  / \\  ";
                    }
                }
                if(i==5){
                    if(tab[i][j]>0){
                        if(tab[i][j]>0&&tab[i][j]<10){
                            cout << "ATK   ";
                        }
                        if(tab[i][j]>=10&&tab[i][j]<100){
                            cout << "ATK  ";
                        }
                        if(tab[i][j]>=100&&tab[i][j]<1000){
                            cout << "ATK ";
                        }
                        if(tab[i][j]>=1000){
                            cout << "ATK";
                        }
                        if(tab[i][j]!=0) {
                            cout << tab[i][j];
                        }
                    }
                }
                if(i==6){
                    if(tab[i][j]>0&&tab[i][j]<10){
                        cout << "DEF   ";
                    }
                    if(tab[i][j]>=10&&tab[i][j]<100){
                        cout << "DEF  ";
                    }
                    if(tab[i][j]>=100&&tab[i][j]<1000){
                        cout << "DEF ";
                    }
                    if(tab[i][j]>=1000){
                        cout << "DEF";
                    }
                    if(tab[i][j]!=0) {
                        cout << tab[i][j];
                    }
                }
                if(i==7){
                    if(tab[i][j]>0&&tab[i][j]<10){
                        cout << "HP    ";
                    }
                    if(tab[i][j]>=10&&tab[i][j]<100){
                        cout << "HP   ";
                    }
                    if(tab[i][j]>=100&&tab[i][j]<1000){
                        cout << "HP  ";
                    }
                    if(tab[i][j]>=1000){
                        cout << "HP ";
                    }
                    if(tab[i][j]!=0) {
                        cout << tab[i][j];
                    }
                }

            }
            cout<<"|";
        }
        cout<<endl;
    }
}
int** tura_gracza(int **skl,int **zom){
    for(int i=0;i<5;i++) {
        while (skl[0][i]==0&&i<5) {
            i++;
        }
        if(i==5){
            break;
        }
        int zo=6;
        while (zom[0][zo] != 1 &&(zom[0][0]==1||zom[0][1]==1||zom[0][2]==1||zom[0][3]==1||zom[0][4]==1)) {
            cout << "Ktorego zombi ma zatakowac postac na pozycji " << i << " ?" << endl;
            cin >> zo;
        }
        if(zom[6][zo]>=skl[6][i]){
            zom[7][zo]--;
            cout << "-1 HP Zombie " << zo <<endl;
        }
        else {
            zom[7][zo] = zom[7][zo] - skl[6][i] + zom[6][zo];
            cout << (-skl[6][i] + zom[6][zo]) <<" HP Zombie " << zo <<endl;
        }
            if(zom[7][zo]<=0){
                for(int d=0; d<8;d++){
                    zom[d][zo]=0;
                }
                cout << "Udalo ci sie zabic zombie " << zo << endl;
            }
    }

    return zom;
}
int** tura_zombie(int **skl, int **zom){
    cout << "Tura zombi"<<endl;
    srand(time(NULL));
    int a=rand()%5;
    for(int i=0; i<=4;i++){
        if (zom[0][i]==1){
            while (skl[0][a]==0){
                a=rand()%5;
            }
            if((-zom[5][i]+skl[7][a])<=0) {
                skl[8][a] = (skl[8][a] - zom[5][i] + skl[7][a]);
                cout << "Zombie " << i << " zatakowal postac " << a << "   " << (-zom[5][i] + skl[7][a]) << " HP"
                     << endl;
            }
            else{
                cout << "Zombie " << i << " zatakowal postac " << a << "   " << "0" << " HP"<<endl;
            }
            if(skl[8][a]<=0){
                for (int j=0;j<=8;j++){
                    skl[j][a]=0;
                }
                cout << "O nie postac "<<a<<" umarla";
            }
        }
    }
    return skl;
}
int** bitwa(int **tab,int b){
    string plik = to_string(b) + "b.txt";
    ifstream sklad_zombie(plik);
    if(!sklad_zombie.is_open()){
        cout << "Blad wczytania bitwy"<<endl;
        return tab;
    }
    else{
        cout << "Bitwa sie rozpoczyna"<<endl;
    }
    int w=8, k=5;
    int **zom;
    zom = new int *[w];
    for (int i = 0; i != w; i++) {
        zom[i] = new int[k];
    }
    for(int i=0 ; i<=k ; i++){
        for(int j=0 ; j<w ; j++) {
            zom[j][i] = 0;
        }
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            sklad_zombie >> zom[i][j];
        }
    }
    sklad_zombie.close();
    wyswietl_zombie(zom);
    cout<<"\n\n\n\n";
    pokaz_sklad(tab);
    while (zom[0][0]==1||zom[0][1]==1||zom[0][2]==1||zom[0][3]==1||zom[0][4]==1){
        tura_gracza(tab,zom);
        wyswietl_zombie(zom);
        cout<<"\n\n\n\n";
        tura_zombie(tab,zom);
        pokaz_sklad(tab);



    }
    cout << "Brawo "; imie(); cout<<" udalo ci sie wygrac bitwe" << endl;
    return tab;
}
int main() {
    char nowa_gra;
    int **sklad;
    while(nowa_gra!='T'&&nowa_gra!='N') {
        cout << "Czy chcesz stworzyc nowa gre?" << endl << "T-Tak" << endl << "N-Nie" << endl;
        cin >> nowa_gra;
        if(nowa_gra=='T'||nowa_gra=='t'){
            zapis_imie();
            cls();
            sklad=nowy_sklad(9,5);
            sklad=wybor_postaci(sklad);
            sklad= wybor_broni(sklad);
            zapis(sklad);
            break;
        }
        else{
            cout<< "Witaj "; imie(); cout<< " milo ciebie widziec :-)"<<endl;
            sklad=nowy_sklad(9,5);
            wczytanie(sklad);
            pokaz_sklad(sklad);
            break;
        }
    }

    cls();
    pokaz_sklad(sklad);
    cls();
    bitwa(sklad,1);
    cls();
    bitwa(sklad,2);
    wybor_postaci(sklad);
    wybor_broni(sklad);
    wybor_broni(sklad);
    cls();
    bitwa(sklad,3);
    cout<<"Udalo ci sie dojsc do bezpiecznej osady wygrywasz!!!";
}
