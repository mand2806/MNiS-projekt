#pragma once
#ifndef GRAPH_H_ 
#define GRAPH_H_ 

#include <vector>
#include <list>

const int MAX_S = 10; // maxymalna potêga s

class PostacOperatorowa {
	int licznik[MAX_S]; 
	int mianownik[MAX_S];
public:
	PostacOperatorowa();
	~PostacOperatorowa();
	PostacOperatorowa mnozenie(PostacOperatorowa H);
	PostacOperatorowa dodawanie(PostacOperatorowa H);
};

class Edge 
{
	Node* wychodzacy;
	Node* dochodzacy;
	PostacOperatorowa transmitancja;
public:
	Edge();
	~Edge();
};

class Node
{
	list<Edge*> edges;
	PostacOperatorowa value;
public:
	Node();
	~Node();
};

class Graph
{
	vector<Edge> edges; // graf jest w³aœcicielem krawedzi
	vector<Node> nodes; // i wierzcho³ków
public:
	Graph();
	~Graph();
};

#endif


