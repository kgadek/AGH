#include <iostream>
#include <ctime>

using namespace std;

const int MAX_HEIGHT=16; // z gory zadana maksymalna wysokosc skiplisty (potrzebna do wartownika na poczatku)

struct node {
       int val; // w skipliscie inty
       int height; //na ilu poziomach znajduje sie element (zawsze MAX_HEIGHT >= height >= 1)
       node **nexts; // wskaznik na tablice nextow
};

struct skiplist {
       int height; //do przechowania obecnej wysokosci calej skiplisty, zawsze height <= MAX_HEIGHT
       node *head; // tu bedzie siedzial wartownik
};     

//***************************************************************************

int random_height(int max) { //losuje wysokosc, poziom 0 (zwykla lista) ma p-stwo 1, kazdy kolejny poziom ma p-stwo o polowe mniejsze
    const static int rand_size=sizeof(rand())*8; //ile bitow bedzie mial rand()
    int height, bits=rand(), found=0, reset=rand_size;
    for (height=0;!found && height<max;++height) { //jesli found==0 albo wysokosc >= obecnej wysokosci skiplisty koniec
        if (!reset) { // jesli braklo bitow, to nowy rand()
                    bits=rand();
                    reset=rand_size;
        }
        found=bits&1;
        bits=bits>>1;
        --reset;
    }
    if (height > MAX_HEIGHT ) height=MAX_HEIGHT; // kontrola z gory zadanej max wysokosci (zeby sie wartownik nie wykrzaczyl)
    return height;
}

int insert (skiplist *plist, int val) {
     node *item=new node; // dodawany element
     int height=random_height((plist->height)+1);
     item->nexts=new node* [height];
     item->height=height;
     item->val=val;
     node *it=plist->head; // iterator do przechodzenia tablicy
     node *tab_temp[MAX_HEIGHT]; // tu beda zapisywane wskazniki do poprzednikow dodawanego elementu (potrzebne, jesli skiplista ma odrzucac duplikaty)
     for (int i=(plist->height)-1;i>=0;--i) {
         while (it->nexts[i] != NULL && val < it->nexts[i]->val ) it=it->nexts[i];
         tab_temp[i]=it; //zapisuje poprzednik na i-tym poziomie skiplisty
     }
     if ( it->nexts[0] != NULL && it->nexts[0]->val == val ) return -1; else { // jesli duplikat, to do widzenia
          
          if (item->height > plist->height) { // jesli wylosowana wysokosc elementu jest o 1 wieksza od wysokosci skiplisty
              ++(plist->height); //zwiekszenie wysokosci listy o 1
              tab_temp[(item->height)-1]=plist->head; // do wstawienia elementu na nowej maksymalnej wysokosci 
          }
          int h=item->height; //pomocnicza zmienna do while'a nizej 
          while ( --h >= 0 ) { // wstawianie do listy na h-tym poziomie
                item->nexts[h]=tab_temp[h]->nexts[h]; 
                tab_temp[h]->nexts[h]=item;
          }
     }
     return 0;
} 

int erase (skiplist *plist, int key) {
    node *it=plist->head; //iterator
    int i=plist->height;
    while ( --i > 0 ) { // usuwanie z listy na i-tym poziomie
          while ( it->nexts[i] != NULL && key < it->nexts[i]->val ) it=it->nexts[i];
          if ( it->nexts[i] != NULL && key == it->nexts[i]->val ) it->nexts[i]=it->nexts[i]->nexts[i];
    }
    while ( it->nexts[0] != NULL && key < it->nexts[0]->val ) it=it->nexts[0]; //poziom 0 traktowany osobno, zeby w petli wyzej nie powtarzac niepotrzebnie operacji
    if ( it->nexts[0] != NULL && key == it->nexts[0]->val ) { //jesli istnieje element o poszukiwanym kluczu
         node *save=it->nexts[0]; 
         it->nexts[i]=it->nexts[i]->nexts[i]; //usuniecie z listy na poziomie 0
         int temp=(plist->height)-1;
         while ( temp>=0 && plist->head->nexts[temp] == NULL ) {
               --(plist->height); // jesli element byl jedyny na maksymalnej wysokosci, zmniejsza sie wysokosc listy
               --temp;
         }
         delete save;
         return 0;
    }
    return -1;
}
          
void print (skiplist *plist, int level) { //wypisuje liste na poziomie level
     node *it=plist->head;
     while (it->nexts[level] != NULL ) {
           it=it->nexts[level];
           cout<<it->val<<" ";
     }
     cout<<endl;
}

void remove_skiplist(skiplist *plist) { // usuwa cala skipliste (razem z wartownikiem)
     node *it=plist->head;
     while (it->nexts[0] != NULL ) erase(plist,it->nexts[0]->val);
     delete plist->head;
}

int main() {
    srand(time(NULL));  
    skiplist list;
    list.head=new node; 
    list.head->nexts=new node* [MAX_HEIGHT];
    list.height=0;
    for (int i=0;i<MAX_HEIGHT;++i) list.head->nexts[i]=NULL; //wartownik
    
    char c='a';
    int liczba;
    while (c!='q') {
         switch (c) {
                case 'i': cout<<"Podaj liczbe do wstawienia: ";
                          cin>>liczba;
                          if ( insert(&list,liczba) ) cout<<"Istnieje juz taka liczba w liscie!";
                          cout<<endl;
                          for (int i=list.height-1;i>=0;--i) print(&list,i);
                          cout<<endl;
                          break;
                case 'e': cout<<"Podaj liczbe do usuniecia: ";
                          cin>>liczba;
                          if ( erase(&list,liczba) ) cout<<"Nie istnieje taka liczba w liscie!";
                          cout<<endl;
                          for (int i=list.height-1;i>=0;--i) print(&list,i);
                          cout<<endl;
                          break;
                case 'q': cout<<"Koniec"<<endl;
                          break;
         }
         c='a';
         while ( c!='i' && c!='e' && c!='q') {
            cout<<"Co chcesz zrobic: i (insert), e (erase) lub q (quit) ? ";
            cin>>c;
         }
    }
    remove_skiplist(&list);
    system("pause");
    return 0;
}  
    
