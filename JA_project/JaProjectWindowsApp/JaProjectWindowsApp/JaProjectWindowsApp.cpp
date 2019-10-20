#include "stdafx.h"



using namespace System;
using namespace System::Windows::Forms;


int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	JaProjectWindowsApp::MainWidnow ^ mainWindow = gcnew JaProjectWindowsApp::MainWidnow();
	Application::Run(mainWindow);


    return 0;
}
