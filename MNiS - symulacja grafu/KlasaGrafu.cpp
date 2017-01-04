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
	for	(auto it : edgesLeaving)					//(std::list<Edge *>::iterator it = edgesLeaving.begin(); it != edgesLeaving.end(); ++it) 
	{
		if ((it)->getIn()->getName() == d)         //(*it)   ??
		{
			return (it);							// j.w.
		}
	}
	return 0;
}

void Node::removeEdgeTo(std::string l)
{
	Edge * e = getEdgeTo(l); 
	removeEdge(e);
}

//****************************************************
//*************** METODY GRAPH ***********************
//****************************************************

