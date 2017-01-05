#include "KlasaGrafu.h"



//********************************************************************
//*************** METODY POSTACI OPERATOROWEJ ************************
//********************************************************************

PostacOperatorowa::PostacOperatorowa()			// transmitancja zerowa (domyslna)
{
	for (int i = 0; i < MAX_S; i++)
	{
		licznik[i] = 0.0; 
		mianownik[i] = 0.0;
	}
}

PostacOperatorowa::PostacOperatorowa(double k)			// transmitancja jedynkowa 
{
	licznik[0] = k;
	mianownik[0] = 1.0;

	for (int i = 1; i < MAX_S; i++)
	{
		licznik[i] = 0.0;
		mianownik[i] = 0.0;
	}
}

PostacOperatorowa::PostacOperatorowa(double * wsk_licz, double * wsk_mian)
{
	for (int i = 0; i < MAX_S; ++i)				// przypisanie odpowiednich wspolczynnikow
	{											// do licznika postaci operatorowej
		if ((wsk_licz + i) == nullptr)
		{
			for (; i < MAX_S; ++i)
				licznik[i] = 0.0;
			break;
		}
		else 
		{
			licznik[i] = *(wsk_licz + i);
		}
	}

	for (int i = 0; i < MAX_S; ++i)				// i do mianownika
	{
		if ((wsk_mian + i) == nullptr)
		{
			for (; i < MAX_S; ++i)
				mianownik[i] = 0.0;
			break;
		}
		else
		{
			mianownik[i] = *(wsk_mian + i);
		}
	}

	delete[] wsk_licz; // usuniecie wskaznikow tymczasowych na wspolczynniki 
	delete[] wsk_mian;
}

PostacOperatorowa::PostacOperatorowa(const PostacOperatorowa & copy)
{
	for (int i = 0; i < MAX_S; i++)
	{
		licznik[i] = copy.licznik[i];
		mianownik[i] = copy.mianownik[i];
	}
}

PostacOperatorowa PostacOperatorowa::operator*(const PostacOperatorowa & H)
{
	PostacOperatorowa temp;
	//double tabL[MAX_S] = { 0.0 };          - potrzebne ???
	//double tabM[MAX_S] = { 0.0 };

	for (int i = 0; i < MAX_S; i++)
	{
		for (int j = 0; j < MAX_S; j++)
		{
			if (i + j > MAX_S)
			{
				// WSTAWIC BLAD O PRZEKROCZENIU ZAKRESU
				break;
			}
			temp.licznik[i+j] += this->licznik[i] * H.licznik[j];						//tabL[i + j] += this->licznik[i] * H.licznik[j];
			temp.mianownik[i+j] += this->mianownik[i] * H.mianownik[j];					//tabM[i + j] += this->mianownik[i] * H.mianownik[j];
		}
	}
	return temp;
}

PostacOperatorowa PostacOperatorowa::operator*(double k)
{
	PostacOperatorowa temp;
	for (int i = 0; i < MAX_S; ++i)
	{
		temp.licznik[i] = k * this->licznik[i];
		temp.mianownik[i] = this->mianownik[i];
	}
	return temp;
}

PostacOperatorowa PostacOperatorowa::operator+(const PostacOperatorowa & H)
{
	PostacOperatorowa temp;
	for (int i = 0; i < MAX_S; ++i)
	{
		temp.licznik[i] = this->licznik[i] + H.licznik[i];
		temp.mianownik[i] = this->mianownik[i] + H.mianownik[i];
	}
	return temp;
}

PostacOperatorowa PostacOperatorowa::operator-(const PostacOperatorowa & H)
{
	PostacOperatorowa temp;
	for (int i = 0; i < MAX_S; ++i)
	{
		temp.licznik[i] = this->licznik[i] - H.licznik[i];
		temp.mianownik[i] = this->mianownik[i] - H.mianownik[i];
	}
	return temp;
}

PostacOperatorowa & PostacOperatorowa::operator=(const PostacOperatorowa & H)
{
	if (this == &H)
		return *this;
	for (int i = 0; i < MAX_S; ++i)
	{
		this->licznik[i] = H.licznik[i];
		this->mianownik[i] = H.mianownik[i];
	}
	return *this;
}

PostacOperatorowa PostacOperatorowa::inverse(void)
{
	PostacOperatorowa temp;
	
	for (int i = 0; i < MAX_S; ++i)
	{
		temp.licznik[i] = this->mianownik[i];
		temp.mianownik[i] = this->licznik[i];
	}
	return temp;
}

//****************************************************
//*************** METODY EDGE ************************
//****************************************************

/*Edge::Edge()
{
	wychodzacy = nullptr;
	dochodzacy = nullptr;
	transmitancja = PostacOperatorowa();
}

Edge::Edge(Node * out, Node * in, PostacOperatorowa H)
{
	wychodzacy = out;
	dochodzacy = in;
	transmitancja = H;
} */

//****************************************************
//*************** METODY NODE ************************
//****************************************************

void Node::removeEdge(Edge * e)
{
	edgesLeaving.erase(std::remove(edgesLeaving.begin(), edgesLeaving.end(), e), edgesLeaving.end());
}

Edge * Node::getEdgeTo(std::string d)
{
	for (std::list<Edge *>::iterator it = edgesLeaving.begin(); it != edgesLeaving.end(); ++it)				//(std::list<Edge *>::iterator it = edgesLeaving.begin(); it != edgesLeaving.end(); ++it) 
	{
		if ((*it)->getIn()->getName() == d)         //(*it)   ??
		{
			return (*it);							// j.w.
		}
	}
	return nullptr;
}

void Node::removeEdgeTo(std::string l)
{
	Edge * e = getEdgeTo(l);
	removeEdge(e);
}

//****************************************************
//*************** METODY GRAPH ***********************
//****************************************************

Node * Graph::addNode(std::string label) 
{
	Node * v = new Node(label);
	nodes[label] = v;
	return v;
}

Edge * Graph::addEdge(std::string from, std::string to, PostacOperatorowa w) 
{
	if (nodes.find(from) != nodes.end() && nodes.find(to) != nodes.end())
	{
		Node * vfrom = nodes.find(from)->second;
		Node * vto = nodes.find(to)->second;
		Edge * e = new Edge(vfrom, vto, w);
		(*vfrom).addEdge(e);
		edges.push_back(e);
		return e;
	}
	else
	{
		// PRZYPADEK BRAKU WIERZCHOLKOW
		return nullptr;
	}
}

Edge * Graph::getEdge(std::string from, std::string to)
{
	if (nodes.find(from) != nodes.end() && nodes.find(to) != nodes.end())
	{
		Node * v1 = nodes.find(from)->second;
		Edge * e = (*v1).getEdgeTo(to);
		return e;
	}
	else
	{
		// PRZYPADEK O BLEDZIE
		return nullptr;
	}
}

void Graph::removeEdge(std::string from, std::string to)
{
	Edge * e = getEdge(from, to);
	if (e != nullptr) 
	{
		edges.erase(remove(edges.begin(), edges.end(), e), edges.end());
		(*e).getOut()->removeEdge(e);
	}
	else 
	{
		// wskaznik zerowy blad - messagebox??
	}
}

Node * Graph::getNodeWithName(std::string l)
{
	if (nodes.find(l) != nodes.end())
		return nodes.find(l)->second;
	else
		return nullptr;
}

void Graph::removeNode(std::string l)
{
	Node * v = getNodeWithName(l);
	if (v != nullptr) 
	{
		std::list<Edge *> edges = getNodeWithName(l)->getEdges();
		for (auto it : edges) //(std::list<Edge *>::iterator it = edges.begin(); it != edges.end(); ++it)
		{
			std::string from = it->getOut()->getName(); // (*it)
			std::string to = it->getIn()->getName();
			removeEdge(from, to);
		}
		nodes.erase(l);
	}
	else {
		// BLAD W PRZYPADKU WSKAZNIKA ZEROWEGO
	}
}

std::list<Node*> Graph::whereCanIGo(Node * v)
{
	std::list<Node *> destinations;
	std::list<Edge *> edges = v->getEdges();
	for (auto it : edges) 
	{
		if ((it)->getIn() != v) {
			destinations.push_back((it)->getOut());
		}
	}
	destinations.push_back(v);
	return destinations;
}

bool Graph::isPath(std::string from, std::string to)
{
	Node * vfrom = getNodeWithName(from);
	Node * vto = getNodeWithName(to);

	if (vfrom == nullptr || vto == nullptr) 
	{
		return false;
	}

	if (from == to) 
	{
		//Ten sam wierzcholek
		return true;
	}
	
	std::map<std::string, Node *> vertices = getNodes();
	std::vector<Edge *> krawedzie = getEdges();
	std::vector<Node *> verticesToCheck;
	verticesToCheck.push_back(vfrom);
	vertices.erase(from);

	while (verticesToCheck.size() != 0) 
	{
		std::list<Node *> destinations = whereCanIGo(verticesToCheck[0]);
		verticesToCheck.erase(verticesToCheck.begin());
		for (auto it : destinations) 
		{
			if (vertices.find((it)->getName()) != vertices.end()) 
			{
				if ((it)->getName() == to) 
				{
					return true;
				}
				verticesToCheck.push_back((it));
				vertices.erase((it)->getName());
			}
		}
	}
	return false;
}

//****************************************************
//************ FUNKCJE POMOCNICZE DO GRAFU ***********
//****************************************************








