#include "Authentication.h"
#include <Windows.h>

using namespace HealthRecommendations;

[STAThreadAttribute]

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Authentication());
	return 0;
}



