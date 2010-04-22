Cel projektu/mysl przewodnia:
	Szesc ECTS-ow dla krola Piotra z jego
       				algorytmicznym problemem,
	Dwa dla Pawla - wladcy mocy tajemnej tylko
       				Kernighanowi znanej,
	Osiem - w sumie - dla nieugietych, w trakcie sesji
				panujacych,
	Pietnascie dla Kazdego Studenta
	Na inzynierskich studiach,
	W krainie AGH
	gdzie zalegna cienie [sesja].

	Jedno [miejsce], by wszystkie zaklepac,
	Jedno, by wszystkie odnalesc,
	Jedno, by wszystkie przetestowac i w porzadku zlaczyc,
	W krainie AGH
	gdzie zalegna cienie.


Krotko mowiac:
	Jest duzo (za duzo?) algorytmow do zaklepania...

System projektu:
    ---------------------------------/---------------> master
                                    /
                            /------/      devel_freeze_##
                           /
    -------\-------^---\--/----------/------/--------> devel
            \    /      \           /
             \--/        \........./   jakies galezie tymczasowe

	Ewolucja:
	 * wszystkie commity ida do devel, gdzie nastepuje rozwoj i
	   testowanie kodu
	 * gdy kolokwium sie bedzie zblizac, czesc kodu z devel
	   zostanie skopiowana do nowej galezi devel_freeze_## w ktorej
	   kod zostanie przetestowany na lewo i prawo oraz ostatecznie
	   poprawiony
	 * po nieznalezieniu bledow/mozliwych ulepszen, zawartosc
	   devel_freeze_## zostaje wrzucona do galezi master
	 * DO GALEZI MASTER NIGDY NIE WRZUCAMY BEZPOSREDNIO

	Po co tak?
	 1) bedzie sie mozna zakladac o pol oceny o kod z master
	 2) szybki rozwoj w devel
	 3) znajdowanie bledow w devel_freeze przed kolosem

	Super by bylo, jakby taki porzadek sie utrzymal...

TODO:______________________________________________________________________
 * skopiowac programy z innych zrodel (ideone etc)
 * uzupelnic ponizsza liste struktur drzewiastych, ktore trzeba napisac
 * struktury:
	- lista jedno/dwukierunkowa
	- stos
	- kolejka
	- kopiec
 	- drzewo BST
	- drzewo Splay
	- drzewo RB
	- drzewo AVL

