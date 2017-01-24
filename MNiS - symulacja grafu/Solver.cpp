#include <cmath>
#include <vector>
#include <fstream>

using std::vector;
using std::ofstream;

const int czas_zero = 0;

void solver(vector<double> licznik, vector<double> mianownik, int typ_wymuszenia, int czas_symulacji, double skok, double amplituda = 0, double pulsacja = 0, double faza_poczatkowa = 0)
{
	vector<double> czas;
	vector<double> wymuszenie;
	vector<vector<double> > pochodne_wymuszen;

	int stopien_licznika = (int)licznik.size() - 1;
	int stopien_mianownika = (int)mianownik.size() - 1;
	double **trojkat_pascala = new double*[stopien_mianownika + 1];
	for (int i = 0; i < stopien_mianownika + 1; i++)
		trojkat_pascala[i] = new double[stopien_mianownika + 1];

	ofstream wynik;
	wynik.precision(10);
	wynik.open("wyniki.txt");


	for (double n = 0; n <= czas_symulacji; n += skok)
	{
		czas.push_back(n);
	}

	int ilosc_punktow = czas.size();

	vector<double> odpowiedz;
	switch (typ_wymuszenia)
	{
	case 1:
	{
		for (int i = 0; i<czas.size(); i++)
		{
			wymuszenie.push_back(1);
		};
		break;
	};
	case 2:
	{
		for (int i = 0; i<czas.size(); i++)
		{
			if (i != 0)
			{
				wymuszenie.push_back(0);
			}
			else wymuszenie.push_back(1);
		};
		break;
	};
	case 3:
	{
		for (int i = 0; i<czas.size(); i++)
		{
			wymuszenie.push_back(amplituda*sin(pulsacja*czas[i] + faza_poczatkowa));
		};
		break;
	};

	}

	int sumator_pomocniczy = 1;
	bool potega = 0;
	for (int i = 0; i<stopien_licznika; i++)
	{

		vector <double> kolumna;
		pochodne_wymuszen.push_back(kolumna);

		if (sumator_pomocniczy<2)
		{

		}
		else
		{
			sumator_pomocniczy = 0;
			potega = !potega;
		}
		sumator_pomocniczy++;

		for (int j = 0; j<ilosc_punktow; j++)
		{

			switch (typ_wymuszenia)
			{
			case 1:
			{
				if (i == 0 && j == 0)
				{
					pochodne_wymuszen.at(i).push_back(pow(skok, -1));
				}
				else if (i == 1 && j == 0)
				{
					pochodne_wymuszen.at(i).push_back(1 / skok);
				}
				else if (i == 1 && j == 1)
				{
					pochodne_wymuszen.at(i).push_back(-1 / skok);
				}
				else
				{
					pochodne_wymuszen.at(i).push_back(0);
				}
				break;
			};

			case 2:
			{
				if (i == 0 && j == 0 && j != 1)
				{
					pochodne_wymuszen.at(i).push_back(1 / skok);
				}
				else if (j == 1)
				{
					pochodne_wymuszen.at(i).push_back(-1 / skok);
				}
				else
				{
					pochodne_wymuszen.at(i).push_back(0);
				}
				break;
			}
			case 3:
			{
				if (i % 2 == 0)
				{
					pochodne_wymuszen.at(i).push_back(amplituda*cos(pulsacja*czas[i] + faza_poczatkowa)*pow(pulsacja, (i + 1))*pow(-1, potega));
				}
				else
				{
					pochodne_wymuszen.at(i).push_back(amplituda*sin(pulsacja*czas[i] + faza_poczatkowa)*pow(pulsacja, (i + 1))*pow(-1, potega));
				}
			}
			};
		}
	}


	for (int pom = 0; pom <= stopien_mianownika; pom++)
	{
		trojkat_pascala[pom][0] = 1;
		trojkat_pascala[pom][pom] = 1;
		for (int j = 0; j<pom - 1; j++)
		{
			trojkat_pascala[pom][j + 1] = trojkat_pascala[pom - 1][j] + trojkat_pascala[pom - 1][j + 1];
		}
	}


	for (int i = czas_zero; i<ilosc_punktow; i++)
	{

		double sumator_x = 0;
		for (int pom = 0; pom <= stopien_licznika; pom++)
		{

			if ((stopien_licznika - pom) != 0)
			{
				sumator_x += licznik[pom] * pochodne_wymuszen[stopien_licznika - pom - 1][i];

			}
			else
			{
				sumator_x += licznik[pom] * wymuszenie[i];

			}
		}

		double lewy_sumator = 0;
		for (int pom = 0; pom <= stopien_mianownika; pom++)
		{
			lewy_sumator += mianownik[stopien_mianownika - pom] / pow(skok, pom);

		}

		double prawy_pomocniczy_sumator = 0;
		for (int pom = 1; pom <= stopien_mianownika; pom++)
		{

			for (int czlon_pochodnej = 0; czlon_pochodnej<pom; czlon_pochodnej++)
			{

				if (czas[i] >= stopien_mianownika*skok)
				{
					prawy_pomocniczy_sumator = prawy_pomocniczy_sumator + mianownik[stopien_mianownika - pom] * trojkat_pascala[pom][czlon_pochodnej + 1] * pow(-1, czlon_pochodnej)*odpowiedz[i - czlon_pochodnej - 1] / pow(skok, pom);

				}
				else
				{
					int skoki_pomocnicze = czas[i] / skok;
					for (int wielokrotnosc_skoku = czlon_pochodnej; wielokrotnosc_skoku<skoki_pomocnicze; wielokrotnosc_skoku++)
					{

						prawy_pomocniczy_sumator = prawy_pomocniczy_sumator + mianownik[stopien_mianownika - pom] * trojkat_pascala[pom][czlon_pochodnej + 1] * pow(-1, czlon_pochodnej)*odpowiedz[i - czlon_pochodnej - 1] / pow(skok, pom);

					}
				}
			}
		}

		double l;
		l = (sumator_x + prawy_pomocniczy_sumator) / lewy_sumator;
		odpowiedz.push_back(l);

		if (typ_wymuszenia == 2)
		{

			wynik << czas[i] << " " << odpowiedz[i] * pow(skok, -1) << std::endl;
		}
		else
		{
			wynik << czas[i] << " " << odpowiedz[i] << std::endl;
		}
	}

	wynik.close();
	for (int i = 0; i < stopien_mianownika + 1; i++)
		delete[] trojkat_pascala[i];
	delete[] trojkat_pascala;
}
