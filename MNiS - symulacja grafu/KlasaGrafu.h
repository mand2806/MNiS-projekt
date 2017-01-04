#pragma once

#include <vector>
#include <map>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
#include <memory>

const int MAX_S = 10; // maksymalna potêga s

class PostacOperatorowa {
	double licznik[MAX_S]; // licznik[0]: s^0, licznik[1]: s^1 itd...
	double mianownik[MAX_S]; // j.w.
public:
	PostacOperatorowa();
	PostacOperatorowa(double k);
	PostacOperatorowa(double * wsk_licz, double * wsk_mian);
	PostacOperatorowa(const PostacOperatorowa & copy);
	~PostacOperatorowa() { }
	
	PostacOperatorowa operator*(const PostacOperatorowa & H); // polaczenie szeregowe transmitancji
	PostacOperatorowa operator*(double k);					  // wzmocnienie
	PostacOperatorowa operator+(const PostacOperatorowa & H); // polaczenie rownolegle
	PostacOperatorowa operator-(const PostacOperatorowa & H);
	PostacOperatorowa & operator=(const PostacOperatorowa & H);
	PostacOperatorowa inverse(void);							// czyli G^-1
};

class Edge 
{
	std::string name;
	Node* out; // wierzcholek z ktorego wychodzi krawedz
	Node* in; // do ktorego dochodzi
	PostacOperatorowa transmittance; // waga krawedzi czyli transmitancja
public:
	Edge() : out(nullptr), in(nullptr), transmittance(PostacOperatorowa()) { }			// domyslny konstruktor - wskazniki zerowe, transmitancja zerowa
	Edge(Node * w, Node * d, PostacOperatorowa H) : out(w), in(d), transmittance(H) { }
	~Edge() { } 
	
	PostacOperatorowa getTrans() const { return transmittance; }
	Node* getOut() const { return out; }
	Node* getIn() const { return in; }
	void setTrans(PostacOperatorowa H) { transmittance = H; }
	void setOut(Node * w) { out = w; }
	void setIn(Node * d) { in = d; }

};

class Node
{
	std::string name;			// etykieta
	std::list<Edge*> edgesLeaving; // lista krawedzi
	PostacOperatorowa value; // wartosc wezla, czyli X(s), Y(s), E(s)...
	bool visited;			// ulatwia przeszukiwanie
public:
	Node();
	Node(std::string n) : name(n), visited(false) { }
	~Node();

	std::string getName() const { return name; }
	std::list<Edge*> getEdges() const { return edgesLeaving; }
	void setVisited(bool v) { visited = v; }
	bool getVisited() { return visited; }
	
	void addEdge(Edge * e) { edgesLeaving.push_back(e); } // dodaje kraw
	void removeEdge(Edge * e);
	Edge * getEdgeTo(std::string d);
	void removeEdgeTo(std::string l);

};

class Graph
{
	std::vector<Edge *> edges; // wektor krawedzi
	std::map<std::string, Node *> nodes; // wektor wezlow
public:
	Graph() { }        //tworzenie pustego grafu
	~Graph() { }


};



