#pragma once

namespace MNiSsymulacjagrafu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for OknoGlowne
	/// </summary>
	public ref class OknoGlowne : public System::Windows::Forms::Form
	{
	public:
		
		OknoGlowne(void)
		{
			InitializeComponent();
		}

		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OknoGlowne()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  AddV;
	private: System::Windows::Forms::TextBox^  vTransBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  Nazwa;
	private: System::Windows::Forms::ColumnHeader^  TransmitancjaV;
	private: System::Windows::Forms::ListView^  listView2;
	private: System::Windows::Forms::ColumnHeader^  TransE;
	private: System::Windows::Forms::ColumnHeader^  wOut;
	private: System::Windows::Forms::ColumnHeader^  wIn;






	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;







	
			 
	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(OknoGlowne::typeid));
			this->AddV = (gcnew System::Windows::Forms::Button());
			this->vTransBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->Nazwa = (gcnew System::Windows::Forms::ColumnHeader());
			this->TransmitancjaV = (gcnew System::Windows::Forms::ColumnHeader());
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->wOut = (gcnew System::Windows::Forms::ColumnHeader());
			this->wIn = (gcnew System::Windows::Forms::ColumnHeader());
			this->TransE = (gcnew System::Windows::Forms::ColumnHeader());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// AddV
			// 
			this->AddV->Location = System::Drawing::Point(89, 133);
			this->AddV->Name = L"AddV";
			this->AddV->Size = System::Drawing::Size(110, 52);
			this->AddV->TabIndex = 0;
			this->AddV->Text = L"Dodaj wierzcho³ek";
			this->AddV->UseVisualStyleBackColor = true;
			this->AddV->Click += gcnew System::EventHandler(this, &OknoGlowne::AddV_Click);
			// 
			// vTransBox
			// 
			this->vTransBox->Location = System::Drawing::Point(12, 68);
			this->vTransBox->Name = L"vTransBox";
			this->vTransBox->Size = System::Drawing::Size(252, 20);
			this->vTransBox->TabIndex = 1;
			this->vTransBox->Text = L"1 2.2 3.33 0 ;4.4 0 5.55 ;";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(268, 52);
			this->label1->TabIndex = 2;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 107);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(252, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"Nazwa np. G1, Y2, X itp.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(184, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Wpisz poni¿ej nazwê dla wierzcho³ka";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(324, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(277, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Wpisz poni¿ej transmitancje krawedzi w postaci jak obok:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(327, 25);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(274, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"1 2.2 3.33 0 ;4.4 0 5.55 ;";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(324, 53);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(208, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Wierzcho³ek z którego wychodzi krawêdŸ:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(324, 92);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(214, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Wierzcho³ek do którego dochodzi krawêdŸ:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(327, 69);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(274, 20);
			this->textBox3->TabIndex = 9;
			this->textBox3->Text = L"Np. G1";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(327, 108);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(274, 20);
			this->textBox4->TabIndex = 10;
			this->textBox4->Text = L"Np. Y2";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(415, 133);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 52);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Dodaj krawedz";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &OknoGlowne::button1_Click);
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->Nazwa, this->TransmitancjaV });
			this->listView1->FullRowSelect = true;
			this->listView1->GridLines = true;
			this->listView1->LabelEdit = true;
			this->listView1->Location = System::Drawing::Point(22, 191);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(579, 123);
			this->listView1->TabIndex = 12;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// Nazwa
			// 
			this->Nazwa->Text = L"Nazwa";
			this->Nazwa->Width = 130;
			// 
			// TransmitancjaV
			// 
			this->TransmitancjaV->Text = L"Transmitancja";
			this->TransmitancjaV->Width = 444;
			// 
			// listView2
			// 
			this->listView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->wOut, this->wIn,
					this->TransE
			});
			this->listView2->FullRowSelect = true;
			this->listView2->GridLines = true;
			this->listView2->Location = System::Drawing::Point(22, 333);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size(579, 111);
			this->listView2->TabIndex = 13;
			this->listView2->UseCompatibleStateImageBehavior = false;
			this->listView2->View = System::Windows::Forms::View::Details;
			// 
			// wOut
			// 
			this->wOut->Text = L"Opuszczany wierzcho³ek";
			this->wOut->Width = 133;
			// 
			// wIn
			// 
			this->wIn->Text = L"Nastêpny wierzcho³ek";
			this->wIn->Width = 177;
			// 
			// TransE
			// 
			this->TransE->Text = L"Transmitancja";
			this->TransE->Width = 263;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(624, 191);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(181, 44);
			this->button2->TabIndex = 20;
			this->button2->Text = L"Usun Zaznaczony Wierzcholek";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &OknoGlowne::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(624, 333);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(181, 39);
			this->button3->TabIndex = 21;
			this->button3->Text = L"Usun Zaznaczona Krawedz";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &OknoGlowne::button3_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(624, 242);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(183, 13);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Usunie takze krawedzie wychodzace";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(639, 102);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(160, 31);
			this->button4->TabIndex = 23;
			this->button4->Text = L"Znajdz droge";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &OknoGlowne::button4_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(639, 25);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(160, 20);
			this->textBox5->TabIndex = 24;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(639, 69);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(160, 20);
			this->textBox6->TabIndex = 25;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(639, 145);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 13);
			this->label7->TabIndex = 26;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(642, 9);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(126, 13);
			this->label8->TabIndex = 27;
			this->label8->Text = L"Wierzcholek poczatkowy";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(639, 53);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(112, 13);
			this->label9->TabIndex = 28;
			this->label9->Text = L"Wierzcholek koncowy";
			// 
			// OknoGlowne
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(815, 456);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->listView2);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->vTransBox);
			this->Controls->Add(this->AddV);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"OknoGlowne";
			this->Text = L"Graf Przep³ywu Sygna³u";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddV_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
