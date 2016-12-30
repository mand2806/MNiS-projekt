#include "OknoGlowne.h"

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