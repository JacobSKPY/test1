#include "MainFrame.h"
#include <wx/wx.h>

enum IDs
{
    CHOICE_ID = 1,
    PROFILE_ID = 2,
    CURRENT_ID = 3,
    BUTTON_ID = 4,
    LISTBOX_ID = 5,
    NEW_NAME_ID = 6,
    NEW_AMOUNT_ID = 7
};

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
    EVT_LISTBOX(LISTBOX_ID, MainFrame::OnListBoxClicked)
    EVT_TEXT(NEW_NAME_ID, MainFrame::InputName)
    EVT_TEXT(NEW_AMOUNT_ID, MainFrame::InputAmount)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    // Create the panels
    wxPanel* Choice_panel = new wxPanel(this, CHOICE_ID, wxPoint(0, 0), wxSize(300, 600), wxSIMPLE_BORDER);
    wxPanel* Profile_panel = new wxPanel(this, PROFILE_ID, wxPoint(300, 0), wxSize(300, 600), wxSIMPLE_BORDER);
    wxPanel* Currentgame_panel = new wxPanel(this, CURRENT_ID, wxPoint(600, 0), wxSize(300, 600), wxSIMPLE_BORDER);

    // ----- Choice Panel ----- //
    wxStaticText* T_Choice = new wxStaticText(Choice_panel, wxID_ANY, "Choose Profile", wxPoint(100, 25), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);

    // Initialize wxListBox with choices
    L_Choice = new wxListBox(Choice_panel, LISTBOX_ID, wxPoint(50, 50), wxSize(200, 300), choices, wxLB_SINGLE | wxALIGN_CENTRE_HORIZONTAL);

    // Create an account menu
    wxStaticText* T_Accountlabel = new wxStaticText(Choice_panel, wxID_ANY, "Account Name", wxPoint(25, 375), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
    TC_Accountname = new wxTextCtrl(Choice_panel, NEW_NAME_ID, "", wxPoint(25, 400), wxSize(100, 20));

    wxStaticText* T_Moneylabel = new wxStaticText(Choice_panel, wxID_ANY, "Deposit amount", wxPoint(175, 375), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
    TC_Amount = new wxTextCtrl(Choice_panel, NEW_AMOUNT_ID, "", wxPoint(175, 400), wxSize(100, 20));

    wxButton* B_Choice = new wxButton(Choice_panel, BUTTON_ID, "Create", wxPoint(100, 475), wxSize(100, 35));
    // ----- Choice Panel ----- //

    // ----- Profile Panel ----- //
    wxStaticText* T_Profile = new wxStaticText(Profile_panel, wxID_ANY, "Profile info", wxPoint(100, 25), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);

    // Name
    wxStaticText* T_Separator = new wxStaticText(Profile_panel, wxID_ANY, "----------------", wxPoint(100, 50), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
    wxStaticText* T_Namelabel = new wxStaticText(Profile_panel, wxID_ANY, "Name: ", wxPoint(100, 75), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
	if (!choices.IsEmpty())
    {
        T_Name = new wxStaticText(Profile_panel, wxID_ANY, choices[current_id], wxPoint(100, 100), wxDefaultSize);
    }
    else
    {
        T_Name = new wxStaticText(Profile_panel, wxID_ANY, "No profile selected", wxPoint(100, 100), wxDefaultSize);
    }
    
    
    // Saldo
    wxStaticText* T_Separator2 = new wxStaticText(Profile_panel, wxID_ANY, "----------------", wxPoint(100, 125), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
    wxStaticText* T_Saldolabel = new wxStaticText(Profile_panel, wxID_ANY, "Saldo: ", wxPoint(100, 150), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
    if (!choices.IsEmpty())
    {
        T_Amount = new wxStaticText(Profile_panel, wxID_ANY, amounts[current_id] + " DKK", wxPoint(100, 175), wxDefaultSize);
    }
    else
    {
        T_Amount = new wxStaticText(Profile_panel, wxID_ANY, "No profile selected", wxPoint(100, 175), wxDefaultSize);
    }

    // Stats
    wxStaticText* T_Separator3 = new wxStaticText(Profile_panel, wxID_ANY, "----------------", wxPoint(100, 200), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);


	// ----- Profile Panel ----- //

    // ----- Currentgame Panel ----- //
    wxStaticText* T_Current = new wxStaticText(Currentgame_panel, wxID_ANY, "Current Game", wxPoint(100, 25), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);

	// ----- Currentgame Panel ----- // 

	// Set font for headers
    wxFont headerFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    T_Choice->SetFont(headerFont);
    T_Profile->SetFont(headerFont);
    T_Current->SetFont(headerFont);


}

// Event handler for adding a new account
void MainFrame::OnButtonClicked(wxCommandEvent& event)
{
    if (!name.IsEmpty())  // Ensure name is not empty
    {
        choices.Add(name);  // Add name to choices
        L_Choice->Set(choices);  // Update the wxListBox with new choices
    }
	if (!amount.IsEmpty())  // Ensure amount is not empty
	{
		amounts.Add(amount);  // Add amount to amounts

	}
}

// Event handler for capturing name input
void MainFrame::InputName(wxCommandEvent& event)
{
    name = event.GetString();
}

// Event handler for capturing deposit amount input
void MainFrame::InputAmount(wxCommandEvent& event)
{
    amount = event.GetString();
}

// Event handler for selecting an account
void MainFrame::OnListBoxClicked(wxCommandEvent& event)
{
    current_id = L_Choice->GetSelection();

    // S�rg for at opdatere teksten p� T_Name
    if (current_id >= 0 && current_id < (int)choices.GetCount())
    {
        T_Name->SetLabel(choices[current_id]);
		T_Amount->SetLabel(amounts[current_id] + " DKK");
    }

}


// Method to return updated choices
wxArrayString MainFrame::update_accounts()
{
    return choices;
}
