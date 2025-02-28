#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
    wxArrayString update_accounts();

private:
    void OnButtonClicked(wxCommandEvent& event);
    void InputName(wxCommandEvent& event);
    void InputAmount(wxCommandEvent& event);
	void OnListBoxClicked(wxCommandEvent& event);

    // Data storage for account names and amounts
    wxArrayString choices;
    wxArrayString amounts;
    int current_id;             // Index of selected account

    // Temporary storage for user input
    wxString name;
    wxString amount;

    // UI elements
    wxListBox* L_Choice;       // ListBox for account selection
    wxTextCtrl* TC_Accountname; // Text field for account name input
    wxTextCtrl* TC_Amount;      // Text field for deposit amount input
	wxStaticText* T_Name;       // Display account name
	wxStaticText* T_Amount;     // Display account amount

    DECLARE_EVENT_TABLE()
};

