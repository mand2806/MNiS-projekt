#pragma once
#ifndef GRAPH_H_ 
#define GRAPH_H_ 

#include <vector>

const int MAX_S = 10; // maxymalna potêga s

struct PostacOperatorowa {
private:
	int licznik[MAX_S]; 
	int mianownik[MAX_S];
public:
	PostacOperatorowa mnozenie(PostacOperatorowa H);
	PostacOperatorowa dodawanie(PostacOperatorowa H);
};

typedef std::vector < std::vector <int> > list;
typedef std::vector < int >  connections;

class Graph {
private:
	int V; // Liczba wierzcho³kow 
	int E; // Liczba krawêdzi 
	list adj; // Vector przechowuj¹cy pol¹cznia miedzy wierzcholkami (reprezentacja listowa) 
public:
	/*  Konstruktory */
	Graph(); // Konstruktor tworz¹cy pusty graf 
	~Graph(); // Destruktor 
			  /*  Rozmiar */
	bool empty(); // Zwraca true jesli graf jest pusty 
	int size(); // Zwraca rozmiar grafu; 
				/*  Modyfikacje */
	void add_vertex(); // Dodaje pojednyczy wierzcholek do grafu 
	void add_edge(int v, int w); // Dodaje krawedz pomiedzy wierzcholkami 
								 /*  Wyswietlanie */
	void write_out(); // Wypisuje wierzcholki wraz z ich polaczeniami 
					  /*  Dodatkowe */
	bool connection(int v, int w); // Zwraca true jesli istnieje bezposrednie polaczenie miedzy wierzcholkami 
};
#endif


