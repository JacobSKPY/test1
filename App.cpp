#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* mainFrame = new MainFrame("Blackjack");
	mainFrame->SetSize(900, 600);
	mainFrame->Center();
	mainFrame->Show(true);
	return true;
}
