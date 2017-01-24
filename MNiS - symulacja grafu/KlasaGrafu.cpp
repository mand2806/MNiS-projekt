#include "KlasaGrafu.h"

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

PostacOperatorowa::PostacOperatorowa(double * wsk_licz, double * wsk_mian, int poml, int pomm)
{
	for (int i = 0; i < MAX_S; ++i)				// przypisanie odpowiednich wspolczynnikow
	{
		// do licznika postaci operatorowej
		if (i >= poml)
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
		if (i >= pomm)
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
			temp.licznik[i + j] += this->licznik[i] * H.licznik[j];						//tabL[i + j] += this->licznik[i] * H.licznik[j];
			temp.mianownik[i + j] += this->mianownik[i] * H.mianownik[j];					//tabM[i + j] += this->mianownik[i] * H.mianownik[j];
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

double PostacOperatorowa::Show(int s)                // funkcja do debuggowania
{
		return mianownik[s];
}

Edge * Vertex::getEdgeTo(string d)
{
	for (vector<Edge *>::iterator it = edgesLeavingMe.begin(); it != edgesLeavingMe.end(); ++it)
	{
		if ((*it)->getV2()->getLabel() == d)
		{
			return (*it);
		}
	}
	return 0;
}

Vertex *  DirectedGraph::addVertex(string label, PostacOperatorowa w)
{
	Vertex * v = new Vertex(label, w);
	vertices[label] = v;
	return v;
}

Edge * DirectedGraph::addEdge(PostacOperatorowa w, string from, string to)
{

	if (vertices.find(from) != vertices.end() && vertices.find(to) != vertices.end())
	{
		Vertex * vfrom = vertices.find(from)->second;
		Vertex * vto = vertices.find(to)->second;
		Edge * e = new Edge(w, vfrom, vto);
		(*vfrom).addEdge(e);
		edges.push_back(e);
		return e;
	}
	else
	{
		//przypadek gdy wierzcholki nie istnieja
		return 0;
	}
}

Edge * DirectedGraph::getEdge(string from, string to)
{
	if (vertices.find(from) != vertices.end() && vertices.find(to) != vertices.end())
	{
		Vertex * v1 = vertices.find(from)->second;
		Vertex* v2 = vertices.find(to)->second;
		Edge * e = (*v1).getEdgeTo(to);
		return e;
	}
	else
	{
		return 0;		// co gdy nie istnieje?
	}
}

bool DirectedGraph::removeEdge(string from, string to)
{
	Edge * e = getEdge(from, to);
	if (e != 0)
	{
		edges.erase(remove(edges.begin(), edges.end(), e), edges.end());
		(*e).getV1()->removeEdge(e);
		return true;
	}
	else
		return false;
		// co gdy nie istnieje?
}

Vertex * DirectedGraph::getVertexWithLabel(string l)
{
	if (vertices.find(l) != vertices.end())
		return vertices.find(l)->second;
	else
		return 0;		// nie istnieje?
}

bool DirectedGraph::removeVertex(string l)
{
	Vertex * v = getVertexWithLabel(l);
	if (v != 0)
	{
		vector<Edge *> edges = getVertexWithLabel(l)->getEdges();

		for (vector<Edge *>::iterator it = edges.begin(); it != edges.end(); ++it)
		{
			string from = (*it)->getV1()->getLabel();
			string to = (*it)->getV2()->getLabel();
			removeEdge(from, to);
		}
		vertices.erase(l);
		return true;
	}
	else
	{
		return false;
		//wierzcholek nie istnieje
	}
}

vector<Vertex *> DirectedGraph::whereCanIGo(Vertex * v)
{
	vector<Vertex *> destinations;
	vector<Edge *> edges = v->getEdges();
	for (vector<Edge *>::const_iterator it = edges.begin(); it != edges.end(); ++it)
	{
		if ((*it)->getV2() != v)
		{
			destinations.push_back((*it)->getV2());
		}
	}
	destinations.push_back(v);
	return destinations;
}

bool DirectedGraph::isPath(string from, string to)
{
	Vertex * vfrom = getVertexWithLabel(from);
	Vertex * vto = getVertexWithLabel(to);

	if (vfrom == 0 || vto == 0)
	{
		return false;
	}

	for (vector<Edge *>::const_iterator it = edges.begin(); it != edges.end(); ++it)
	{
		if (vfrom == (*it)->getV1() && vto == (*it)->getV2())
			return true;
	}

	map<string, Vertex*> vertices = getVertices();
	vector<Edge *> edges = getEdges();

	vector<Vertex *> verticesToCheck;
	verticesToCheck.push_back(vfrom);
	vertices.erase(from);

	while (verticesToCheck.size() != 0)
	{
		vector<Vertex *> destinations = whereCanIGo(verticesToCheck[0]);
		verticesToCheck.erase(verticesToCheck.begin());


		for (vector<Vertex *>::const_iterator it = destinations.begin(); it != destinations.end(); ++it)
		{
			if (vertices.find((*it)->getLabel()) != vertices.end())
			{
				if ((*it)->getLabel() == to)
				{
					return true;
				}
				verticesToCheck.push_back((*it));
				vertices.erase((*it)->getLabel());
			}
		}
	}
	return false;
}
