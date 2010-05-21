/* drzewo słownikowe by M.Nowak aka News */
#include <iostream>

using namespace std;

struct node {
    node *chars[256];		// indeksy to literki (znaki)
    bool end;			// czy dany wezel jest koncem stringa ?
    // konstruktor
     node() : end(0) {
	for (int i = 0; i < 256; i++)
	    chars[i] = NULL;
}};

node *p;

void trie_Add(const char *str)	// dodawanie stringa do drzewa
{
    node *s = p;		// do poruszania sie po drzewie
    int i = 0;			// numer litery
    while (str[i])		// petla chodzaca po literach
    {
	if (s->chars[(unsigned int)str[i]] == NULL)
	    s->chars[(unsigned int)str[i]] = new node;	// jezeli nie ma wezla to stworz
	if (!str[i + 1])
	    s->chars[(unsigned int)str[i]]->end = 1;	// jezeli to ostatnia litera to ustaw end

	s = s->chars[(unsigned int)str[i]];	// nastepny wezel
	i++;			// nastepna litera
    }
}

bool trie_Search(const char *str)	// szukanie czy string w drzewie
{
    node *s = p;		// do poruszania sie po drzewie
    int i = 0;			// licznik znakow
    while (str[i])		// petla chodzi po literach
	if (!(s = s->chars[(unsigned int)str[i++]]))
	    return false;	// przesuwa i sprawdza czy istnieje wezel
    // jak nie to nie ma slowa
    if (s->end)
	return true;
    else
	return false;		// jak jest to sprawdza czy jes ustawione end
}

void trie_Del(const char *str)	// usuwanie slow z drzewa
{
    if (trie_Search(str))	// jezeli wogole jest takie slowo w drzewie
    {
	node *s = p;
	node *sprev = NULL;
	int i = 0;
	while (str[i]) {
	    sprev = s;
	    s = s->chars[(unsigned int)str[i++]];
	}			// ustaw na koncowa litere
	if (s)
	    s->end = 0;
	else {
	    sprev = NULL;
	    delete s;
	    s = NULL;
	}
    }
}

int main()
{
    p = new node;
    cout << "Dodaje \"lol\"\n";
    trie_Add("lol");
    cout << "Dodaje \"lol2\"\n";
    trie_Add("lol2");
    		// dodawanie do drzewa
    cout << "Sprawdzam \"lol\" : " << trie_Search("lol") << endl;
    		// sprawdza czy jest
    cout << "Sprawdzam \"lol2\" : " << trie_Search("lol2") << endl;
    		// sprawdza czy jest dluzszy (nie)
    cout << "Sprawdzam \"lo\" : " << trie_Search("lo") << endl;
    		// sprawdza czy jest krotszy (nie)
    cout << "Usuwam \"lol\"\n";
    trie_Del("lol");
    cout << "Sprawdzam \"lol\" : " << trie_Search("lol") << endl;
    cout << "Sprawdzam \"lol2\" : " << trie_Search("lol2") << endl;
    cout << "Usuwam \"lo\" (nie ma takiego) : " << endl;
    trie_Del("lo");
}
