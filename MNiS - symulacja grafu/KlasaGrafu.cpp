#include "KlasaGrafu.h"
#include <iostream> 

using namespace std;

/* Konstruktory */
// Konstruktor tworz¹cy pusty graf 
Graph::Graph()
{
	V = 0;
	E = 0;
}
Graph::~Graph()
{
	adj.clear();
}
/* Rozmiar */

//Zwraca true jeœli graf jest pusty 
bool Graph::empty()
{
	if (adj.empty()) return true;
	return false;
}

//Zwraca rozmiar grafu 
int Graph::size()
{
	return V;
}
/* Modyfikacje */

//Dodaje pojedynczy wierzcholek do grafu 
void Graph::add_vertex()
{
	vector<int> vertex;
	adj.push_back(vertex);
	V++;
}

//Dodaje krawedz pomiedzy wierzcholkami 
void Graph::add_edge(int v, int w)
{
	//Sprawdzamy czy oba wierzcholki istnieja 
	if ((v >= 0 && v < V) && (w >= 0 && w < V))
	{
		//Sprawdzamy czy taka krawedz nie zostala juz utworzona 
		if (!connection(v, w))
		{
			adj[v].push_back(w);
			adj[w].push_back(v);
			E++;
		}
		else cout << "Taka krawedz juz istnieje." << endl;
	}
}

/* Wyswietlanie */

// Wypisuje wszystkie wierzcholki wraz z ich polaczeniami 
void Graph::write_out()
{
	connections::iterator vert;
	for (int i = 0; i<(int)adj.size(); i++)
	{
		cout << i << ": ";
		for (vert = adj[i].begin(); vert != adj[i].end(); vert++)
		{
			cout << *vert << " ";
		}
		cout << endl;
	}
}

/* Dodatkowe */
//Zwraca true jezeli istnieje bezposrednie polaczenie miedzy wierzcholkami 
bool Graph::connection(int v, int w)
{
	for (int i = 0; i<(int)adj[v].size(); i++)
	{
		if (adj[v][i] == w) return true;
	}
	return false;
}