program rbtree;
{ autor: kgadek }

type
	colour = (re,bl);
	key = integer;
	pnode = ^node;
	node = record
			k:key;
			c:colour; {colour}
			l,r,p:pnode; {left, right, parent}
		end;
var
	W,R:pnode; {W - wartownik, R - root}

	{zmienne programu badajacego zachowanie drzewa}
	t1:char;
	t2:key;
	t3:pnode;



{ -------------------- LEFT-ROTATE(x) ----------------------------------- }
procedure lrot(x:pnode);
var
	y:pnode;
begin
	if x^.r <> W then begin
		y := x^.r;
		x^.r := y^.l;
		x^.r^.p := x;
		y^.p := x^.p;
		if y^.p = W then
			R := y
		else if x = x^.p^.r then	
			x^.p^.r := y
		else
			x^.p^.l := y;
		y^.l := x;
		x^.p := y;
	end;
end;

{ -------------------- RIGHT-ROTATE(x) ---------------------------------- }
procedure rrot(x:pnode);
var
	y:pnode;
begin
	if x^.l <> W then begin
		y := x^.l;
		x^.l := y^.r;
		x^.l^.p := x;
		y^.p := x^.p;
		if y^.p = W then
			R := y
		else if x = x^.p^.l then	
			x^.p^.l := y
		else
			x^.p^.r := y;
		y^.r := x;
		x^.p := y;
	end;
end;

{ -------------------- FIXUP(z) ----------------------------------------- }
procedure fixup(z:pnode);
var
	y:pnode;
begin
	{ Numery przypadkow zgodne z tymi w Cormenie }
	while z^.p^.c = re do begin
		if z^.p^.p^.l = z^.p then begin
			y := z^.p^.p^.r;
			if y^.c = re then begin { Przypadek 1}
				z^.p^.c := bl;
				z^.p^.p^.c := re;
				y^.c := bl;
				z := z^.p^.p;
			end else begin
				if z = z^.p^.r then { Przypadek 2 }
					lrot(z);
				z^.p^.c := bl; { Przypadek 3 }
				z^.p^.p^.c := re;
				rrot(z^.p^.p);
			end;
		end else begin {symetrycznie j.w.}
			y := z^.p^.p^.l;
			if y^.c = re then begin { Przypadek 4 }
				z^.p^.c := bl;
				z^.p^.p^.c := re;
				y^.c := bl;
				z := z^.p^.p;
			end else begin
				if z = z^.p^.l then { Przypadek 5 }
					rrot(z);
				z^.p^.c := bl; { Przypadek 6 }
				z^.p^.p^.c := re;
				lrot(z^.p^.p);
			end;
		end;
	end;
	R^.c := bl;
end;

{ -------------------- INSERT(z) ---------------------------------------- }
{ wstaw wezel do drzewa }
procedure ins(z:pnode);
var
	x,y:pnode;
begin
	y := W;
	x := R;
	while (x<>W) do begin
		y := x;
		if z^.k=x^.k then begin
			dispose(z);
			exit();
		end;
		if z^.k<x^.k then
			x := x^.l
		else
			x := x^.r;
	end;
	z^.p := y;
	if (y=W) then
		R := z
	else if z^.k<y^.k then
		y^.l := z
	else
		y^.r := z;
	z^.r := W;
	z^.l := W;
	z^.c := re;
	fixup(z);
end;

{ -------------------- QUERY(k) ----------------------------------------- }
{ szuka wartosci k w drzewie }
function query(k:key):pnode;
var
	x:pnode;
begin
	x := R;
	while (x<>W) and (k<>x^.k) do begin
		if k<x^.k then
			x := x^.l
		else
			x := x^.r;
	end;
	query := x;
end;

{ -------------------- CLEAR-MEMORY() ----------------------------------- }
{ czysci pamiec }
procedure clear_mem(x:pnode);
begin
	if x<> nil then begin
		clear_mem(x^.l);
		clear_mem(x^.r);
		dispose(x);
	end;
end;

{ -------------------- HELP() ------------------------------------------- }
{ wyswietl pomoc }
procedure help();
begin
	writeln();
    writeln('Komendy:');
    writeln('    h       - spis poleceń');
	writeln('    x       - zamknij program');
    writeln('    a N     - dodaj liczbę X do drzewa');
    writeln('    q N     - sprawdź, czy liczba X jest w drzewie');
    writeln('    s       - statystyka drzewa');
	writeln();
end;

{ -------------------- BLACK-HEIGHT(x) ---------------------------------- }
{ wyznacz ilosc czarnych wezlow na kazdej sciezce korzen-list (sprawdz tez
  czy ta wlasciwosc jest zachowana) }
function bh(x:pnode):integer;
var
	t:integer;
begin
	if x=W then
		bh := 0
	else begin
		t := bh(x^.r);
		if bh(x^.l)<>t then
			writeln('!! zaburzona właściwość 5 !!');
		bh := t;
		if x^.c=bl then
			Inc(bh);
	end;
end;

{ -------------------- HEIGHT(x) ---------------------------------------- }
{ wyznacz najdluzsza sciezke korzen-list w drzewie }
function h(x:pnode):integer;
var
	t:integer;
begin
	if x=W then
		h := 0
	else begin
		h := h(x^.l)+1;
		t := h(x^.r)+1;
		if t>h then
			h := t;
	end;
end;

{ -------------------- PRINT-INORDER(x) --------------------------------- }
{ wyswietl zawartosc drzewa w porzadku inorder }
procedure print_inorder(x:pnode);
begin
	if x<>W then begin
		print_inorder(x^.l);
		write(x^.k,' ');
		print_inorder(x^.r);
	end;
end;

{ -------------------- SHOW-STATISTICS() -------------------------------- }
{ wyswietl statystyki drzewa }
procedure stats();
begin
	writeln('Czarna wysokosc: ',bh(R));
	writeln('Maksymalna wysokosc: ',h(R));
	writeln('Zawartość drzewa (inorder):');
	print_inorder(R); writeln();
end;





{ ----------------------------------------------------------------------- }
{ program jest interaktywny }
begin
	writeln('testy drzewa czerwono-czarnego :D');
	help();
	new(W);
	W^.k := 0;
	W^.c := bl;
	W^.l := W;
	W^.l := W;
	W^.p := W;
	W^.r := W;
	R := W;
	t1 := '$';
	repeat
		if t1<>'s' then begin
			write(bh(R),':',h(R),' > ');
		end;
		read(t1);
		case t1 of
			'a': begin {add}
					readln(t2);
					new(t3);
					t3^.k := t2;
					ins(t3);
				end;
			'q': begin {query}
					readln(t2);
					t3 := query(t2);
					if t3<>W then
						writeln('Jest!')
					else
						writeln('Nie ma...');
				end;
			's': stats();
			'h': help();
		end;
	until t1='x';
	dispose(W);
end.

