



/*BAGIAN I*/

/*Nomor 1*/
/*FAKTA*/
/*pria(X) benar, jika X adalah pria*/
pria(jito).
pria(abiyyu).
pria(omlutfi).
pria(mametrojab).
pria(bowo).
pria(ihsan).
pria(arden).
pria(liltude).
pria(ipul).

/*wanita(X) benar, jika X adalah wanita*/
wanita(jeremy).
wanita(jurisutantri).
wanita(emily).
wanita(riasgremory).
wanita(audy).

/*usia(X,Y) benar, jika X berusia Y*/
usia(jito, 71).
usia(jeremy, 69).
usia(abiyyu, 56).
usia(jurisutantri, 42).
usia(omlutfi, 58).
usia(emily, 40).
usia(mametrojab, 24).
usia(bowo, 30).
usia(ihsan, 32).
usia(riasgremory, 26).
usia(arden, 28).
usia(audy, 24).
usia(liltude, 14).
usia(ipul, 8).

/*menikah(X,Y) benar, jika X menikah dengan Y*/
menikah(jito, jeremy).
menikah(jeremy, jito).
menikah(abiyyu, jurisutantri).
menikah(jurisutantri, abiyyu).
menikah(omlutfi, emily).
menikah(emily, omlutfi).
menikah(ihsan, riasgremory).
menikah(riasgremory, ihsan).
menikah(arden, audy).
menikah(audy, arden).

/*anak(X,Y) benar, jika X adalah anak Y*/
anak(mametrojab, jito).
anak(mametrojab, jeremy).
anak(bowo, jito).
anak(bowo, jeremy).
anak(ihsan, jito).
anak(ihsan, jeremy).
anak(riasgremory, abiyyu).
anak(riasgremory, jurisutantri).
anak(arden, abiyyu).
anak(arden, jurisutantri).
anak(audy, omlutfi).
anak(audy, emily).
anak(liltude, ihsan).
anak(liltude, riasgremory).
anak(ipul, arden).
anak(ipul, audy).

/*saudara(X,Y) benar, jika X adalah saudara kandung Y*/
saudara(mametrojab, bowo).
saudara(bowo, mametrojab).
saudara(bowo, ihsan).
saudara(ihsan, bowo).
saudara(mametrojab, ihsan).
saudara(ihsan, mametrojab).
saudara(riasgremory, arden).
saudara(arden, riasgremory).

/*Nomor 2*/
/*kakak(X,Y) benar, jika X adalah kakak dari Y (baik perempuan maupun lelaki)*/
kakak(X, Y) :- saudara(X,Y), usia(X, Z), usia(Y, U), Z>U.
/*keponakan(X,Y) benar, jika X adalah keponakan dari Y*/
keponakan(X, Y) :- anak(X,Z), saudara(Z, Y).
suami(X,Y) :- pria(X), menikah(X, Y).
sepupu(X,Y) :- anak(X,Z), anak(Y,U), saudara(Z,U).
mertua(X, Y) :- menikah(Y, Z), anak(Z, X).
bibi(X, Y) :- wanita(X), anak(Y, Z), saudara(Z, X).
cucu(X, Y) :- anak(Z, Y), anak(X,Z).
anaksulung(X) :- anak(X,Y),pria(Y),\+kakak(_,X).
anakbungsu(X) :- anak(X,Y),pria(Y),\+kakak(X,_).


/*Nomor 3*/
/*Query dan hasilnya terdapat pada file txt*/

/*Bagian 2*/

/*RULES*/

/* Nomor a (fibbonaci)*/
fibbonaci(0,0):- !.
fibbonaci(1,1):- !.
fibbonaci(N,X):- N1 is N-1, N2 is N-2, fibbonaci(N1,X1),fibbonaci(N2,X2), X is X1 + X2.

/* Nomor b (gcd)*/
gcd(0,X,X):- X>0, !.
gcd(A,B,X):- A>=B, Y is A-B, gcd(Y,B,X).
gcd(A,B,X):- A<B,  Y is B-A, gcd(Y,A,X).

/* Nomor c (power)*/
power(_,0,1):- !. 
power(A,B,X):- A>0,B1 is B-1, power(A,B1,X1), X is X1*A.



/*Bagian 3*/

/*RULES*/

/* Nomor a (Inverse)*/
/*inverse(A,B):-!.*/
inverse([],Z).
inverse([H|T],Acc) :- inverse(T,[H|Acc]).

/* Nomor b (insert)*/
insert([],X, [X]). 
insert([Y | Rest],X, [X,Y | Rest]) :- X @< Y, !.
insert([Y | Rest1],X, [Y | Rest2]) :- insert(Rest1,X, Rest2).


/* Nomor c (dotProduct) */
dotProduct([],[],0) :-!.
dotProduct([X|Z], [Y|U], Hasil) :- dotProduct(Z, U, Hasil2), Hasil is Hasil2+X*Y.

/* Nomor d (countX) */
% countX([], Element, 0).
% countX([X|List], Element, OccurNum) :- X=Element, !, countX(List, Element, OccurNum1), OccurNum is OccurNum1 + 1.
% countX([X|List], Element, OccurNum) :- countX(List, Element, OccurNum).

% count(Element,[],0).

    % count(Element,[X|List],OccurNum) :-
    %     Element = X,!,
    %     count(Element,List,OccurNum1),
    %     OccurNum is OccurNum1 + 1.

    % count(Element,[X|List],OccurNum) :-
    %     count(Element,List,OccurNum).



countX([], Element, 0).
countX([X|List], Element, Sum) :- X=Element, !, countX(List, Element, Sum2), Sum is Sum2 + 1.
countX([X|List], Element, Sum2) :- countX(List, Element, Sum2).



/* Nomor e (palindrom) */

