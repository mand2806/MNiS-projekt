# MNiS-projekt
                                                ******* SYMULACJA GRAFU *******
Opis: Program w założeniu ma umożliwić redukcje grafu przepływu sygnału oraz wyznaczenie odpowiedzi skokowej, impulsowej i sinus.
Autorzy: Mateusz Andrzejewski, Marek Radkowski, Mateusz Zalas.

Użyte biblioteki: 
<vector> <map> <string> <algorithm> <msclr\marshal_cppstd.h> <cmath> <fstream>

const int MAX_S = 10 // stała przechowująca maksymalny rozmiar tablic licznika i mianownika w klasie PostacOperatorowa 

Klasa PostacOperatorowa:
Cechy:
reprezentacja poprzez 2 tablice typu zmiennoprzecinkowego. Tablica licznik zawiera współczynniki kolejnych potęg s np.
licznik[0]=1 oznacza 1*s^0, licznik[2] = 2,43 oznacza 2,43*s^2 itd. Tablica mianownik analogicznie.
Metody:
Konstruktory - domyślny (transmitancja zerowa, czyli przerwa), z argumentem double k (wzmocnienie parametrem k), oraz
PostacOperatorowa(double * wsk_licz, double * wsk_mian, int poml, int pomm) - przyjmuje 2 wskazniki odpowiednio na tablice licznika
i mianownika oraz 2 zmienne pomocnicze typu int okreslajace rozmiar tablicy licznika i mianownika (odpowiednio poml i pomm)
Przeciążenie operatorów: + i - (polaczenie rownolegle gałęzi), * (połączenie szeregowe lub mnożenie przez skalar), operator przypisania.
PostacOperatorowa inverse(void);	- odwraca transmitancje (G^-1).

Klasa Vertex:
każdy węzeł posiada nazwę, transmitancję, zmienną typu bool (pomocnicza) oraz vector wychodzących krawędzi.
Metody:
addEdge - dodaje krawędź do vectora
removeEdge - usuwa krawędź z vectora
getEdgeTo - usuwa krawędź z vectora i dodaje do vectora wierzchołka o nazwie przekazanej jako argument

Klasa Edge:
Cechy: transmitancja, węzeł z którego wychodzi krawędź, węzeł na który wskazuje krawędź (wskaźniki do obiektu typu Vertex).

Klasa DirectedGraph:
Cechy: vector wskaźników do Edge, mapa wierzchołków (dostęp poprzez nazwę typu std::string).
Metody:
addVertex - dodaje wierzchołek o nazwie i transmitancji podanej w argumentach.
addEdge - dodaje krawędź o transmitancji i wierzchołkach podanych w argumentach.
getEdge - zwraca krawędź pomiędzy podanymi węzłami.
removeEdge - usuwa krawędź pomiędzy podanymi wierzchołkami.
getVertexWithLabel - zwraca węzeł o podanej nazwie.
removeVertex - usuwa węzeł o podanej nazwie.
whereCanIGo - zwraca vector węzłów do których można przejść w następnym kroku (od podanego wierzchołka).
isPath - sprawdza czy istnieje droga pomiędzy wierzchołkami o nazwach podanych w argumentach (obsługuje pętle własne).

Funkcja solver: 

Dane wejściowe:
*licznik - wektor zawierający współczynniki rzeczywiste licznika transmitancji, współczynniki w kolejności od stojącego przy najwyższej potędze do wyrazu wolnego przykład: [2 3 4]  odpowiada licznikowi 2s^2+3s+4 
*mianownik - wektor zawierający współczynniki rzeczywiste mianiwnika transmitancji, współczynniki w kolejności od stojącego przy najwyższej potędze do wyrazu wolnego przykład: [5 6]  odpowiada 5s+6 
*typ_wymuszenia - liczba całkowita określająca badany typ odpowiedzi:
1 - odpowiedź skokowa
2 - odpowiedź impulsowa
3 - odpowiedź na fukncję sinus postacji Asin(wt+fi), wymaga podania amplitudy, pulsacji, fazy początkowej wymuszenia domyśnie wszystkie wartości są równe 0
*czas_symulacji - liczba całkowita określająca długość symulacji w [s]
 skok - liczba rzeczywista - różnica między kolejnymi wartościami czasu, w większości przypadków wartość 0.001(wyznaczona doświadczalnie) daje wystarczająco dobrą dokłądność  
*liczby rzeczywiste:(tylko w przypadku wymuszenia sinusoidalnego)
amplituda - A
pulsacja - w
faza_poczatkowa - fi

Wyjście:
Program tworzy plik wyniki.txt w którym znajdują się dwie kolumny:
w pierwszej jest czas w [s] od 0 zwiększający się o skok do czas_symulacji
w drugiej znajduję się obliczona odpowiedź na zadane wymuszenie

Opis algorytmu:
Do obliczeń została użyta metoda eulera wstecz.

Uwagi:
Transmitancja definiowana jest przy założeniu zerowych warunków początkowych.
