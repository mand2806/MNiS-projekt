#pragma once

#include <vector>
#include <map>
#include <string>
#include <algorithm>

using std::vector;
using std::map;
using std::string;

const int MAX_S = 10; // maksymalna potêga s

class PostacOperatorowa
{
	double licznik[MAX_S]; // licznik[0]: s^0, licznik[1]: s^1 itd...
	double mianownik[MAX_S]; // j.w.
public:
	PostacOperatorowa();
	PostacOperatorowa(double k);
	PostacOperatorowa(double * wsk_licz, double * wsk_mian, int poml, int pomm);
	PostacOperatorowa(const PostacOperatorowa & copy);
	~PostacOperatorowa() { }

	PostacOperatorowa operator*(const PostacOperatorowa & H); // polaczenie szeregowe transmitancji
	PostacOperatorowa operator*(double k);					  // wzmocnienie
	PostacOperatorowa operator+(const PostacOperatorowa & H); // polaczenie rownolegle
	PostacOperatorowa operator-(const PostacOperatorowa & H);
	PostacOperatorowa & operator=(const PostacOperatorowa & H);
	PostacOperatorowa inverse(void);							// czyli G^-1
	double Show(int s); // do debuggowania
};

class Edge;
class Vertex;

class Edge
{
	PostacOperatorowa weight;    //waga
	Vertex * vertex1;           // wezel z ktorego wychodzi krawedz
	Vertex * vertex2;           //wezel do ktorego dochodzi krawedz
public:
	PostacOperatorowa getWeight() const { return weight; }
	Vertex* getV1() const { return vertex1; }
	Vertex* getV2() const { return vertex2; }
	void setWeight(PostacOperatorowa w) { weight = w; }
	void setV1(Vertex * v) { vertex1 = v; }
	void setV2(Vertex * v) { vertex2 = v; }
	Edge(PostacOperatorowa w, Vertex* v1, Vertex* v2)
	{
		weight = w;
		vertex1 = v1;
		vertex2 = v2;
	}
};

class Vertex
{
	string label;                       // nazwa wierzcholka
	vector<Edge *> edgesLeavingMe;  // krawedzie wychodzace
	bool visited;                   // zmienna pomocnicza do znajdywania drogi
	PostacOperatorowa weight;       // waga
public:
	string getLabel() const { return label; }
	vector<Edge*> getEdges()const { return edgesLeavingMe; }
	Edge * getEdgeTo(string d);
	PostacOperatorowa getWeight() { return weight; }
	void setVisited(bool v) { visited = v; }
	bool getVisited() { return visited; }
	void addEdge(Edge * e) { edgesLeavingMe.push_back(e); }
	void removeEdge(Edge * e) { edgesLeavingMe.erase(remove(edgesLeavingMe.begin(), edgesLeavingMe.end(), e), edgesLeavingMe.end()); }
	void removeEdgeTo(string l)
	{
		Edge * e = getEdgeTo(l);
		removeEdge(e);
	}
	Vertex(string l, PostacOperatorowa w) : label(l), visited(false), weight(w) { }
};

class DirectedGraph
{
	vector<Edge*> edges;
	map<string, Vertex*> vertices;
public:
	Vertex *  addVertex(string label, PostacOperatorowa w);
	map<string, Vertex*> getVertices() { return vertices; }
	vector<Edge*> getEdges() { return edges; }
	Edge * addEdge(PostacOperatorowa w, string from, string to);
	Edge * getEdge(string from, string to);
	bool removeEdge(string from, string to);
	Vertex * getVertexWithLabel(string l);
	bool removeVertex(string l);
	vector<Vertex *> whereCanIGo(Vertex * v);
	bool isPath(string from, string to);
	void printGraph(void);
};
