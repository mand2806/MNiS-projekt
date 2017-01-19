#include "OknoGlowne.h"
#include "KlasaGrafu.h"
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<System::String^> ^args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MNiSsymulacjagrafu::OknoGlowne forma_glowna;
	Application::Run(%forma_glowna);
	return 0;
}

DirectedGraph Graph;

System::Void MNiSsymulacjagrafu::OknoGlowne::AddV_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	int i, pl, pm;
	double licznik[MAX_S], mianownik[MAX_S];
	string tmp;

	for (i = 0, pl = 0; vTransBox->Text[i] != ';'; i++) {				// zamiana String^ z textboxa na tablice double licznika i mianownika
		if (vTransBox->Text[i] == ' ') {
			licznik[pl++] = stod(tmp);
			tmp.clear();
		}
		else
			tmp += vTransBox->Text[i];
	}
	tmp.clear();
	for (i++, pm = 0; vTransBox->Text[i] != ';'; i++) {
		if (vTransBox->Text[i] == ' ') {
			mianownik[pm++] = stod(tmp);
			tmp.clear();
		}
		else
			tmp += vTransBox->Text[i];
	}

	double * wm, *wl;
	wm = mianownik;
	wl = licznik;
	PostacOperatorowa X(wl, wm, pl, pm);
	tmp = msclr::interop::marshal_as<string>(textBox1->Text);
	Graph.addVertex(tmp, X);			// utworzenie wierzcholka i dodanie do grafu

	listView1->Items->Add(textBox1->Text)->SubItems->Add(vTransBox->Text);
	return System::Void();
}

System::Void MNiSsymulacjagrafu::OknoGlowne::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	int i, pl, pm;
	double licznik[MAX_S], mianownik[MAX_S];
	string tmp;

	for (i = 0, pl = 0; textBox2->Text[i] != ';'; i++) {				// zamiana String^ z textboxa na tablice double licznika i mianownika
		if (textBox2->Text[i] == ' ') {
			licznik[pl++] = stod(tmp);
			tmp.clear();
		}
		else
			tmp += textBox2->Text[i];
	}
	tmp.clear();
	for (i++, pm = 0; textBox2->Text[i] != ';'; i++) {
		if (textBox2->Text[i] == ' ') {
			mianownik[pm++] = stod(tmp);
			tmp.clear();
		}
		else
			tmp += textBox2->Text[i];
	}
	double * wm, *wl;
	wm = mianownik;
	wl = licznik;
	PostacOperatorowa X(wl, wm, pl, pm);
	tmp = msclr::interop::marshal_as<string>(textBox3->Text);
	string tmp2 = msclr::interop::marshal_as<string>(textBox4->Text);
	if (Graph.addEdge(X, tmp, tmp2) == 0)		// dodanie krawedzi po serii konwersji
		;      //cos;	
	else {
		ListViewItem ^L1 = gcnew ListViewItem(textBox3->Text);
		L1->SubItems->Add(textBox4->Text);
		L1->SubItems->Add(textBox2->Text);
		listView2->Items->Add(L1);
	}
	return System::Void();
}

System::Void MNiSsymulacjagrafu::OknoGlowne::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	String ^ tmp2 = listView1->SelectedItems[0]->Text;
	string tmp = msclr::interop::marshal_as<string>(listView1->SelectedItems[0]->Text);
	if (Graph.removeVertex(tmp) == false)
		;

	listView1->Items->Remove(listView1->SelectedItems[0]);
	array<System::Windows::Forms::ListViewItem^>^ tab = listView2->Items->Find(tmp2, false);
	listView2->Items->Remove(tab[0]);
	return System::Void();
}

System::Void MNiSsymulacjagrafu::OknoGlowne::button3_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	string tmp = msclr::interop::marshal_as<string>(listView2->SelectedItems[0]->Text);
	string tmp2 = msclr::interop::marshal_as<string>(listView2->SelectedItems[0]->SubItems[1]->Text);
	if (Graph.removeEdge(tmp, tmp2) == false)
		;
	else
		listView2->Items->Remove(listView2->SelectedItems[0]);
	return System::Void();
}

System::Void MNiSsymulacjagrafu::OknoGlowne::button4_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	string tmp = msclr::interop::marshal_as<string>(textBox5->Text);
	string tmp2 = msclr::interop::marshal_as<string>(textBox6->Text);
	if (Graph.isPath(tmp, tmp2))
		label7->Text = "Jest droga";
	else
		label7->Text = "Nie ma drogi";
	return System::Void();
}


