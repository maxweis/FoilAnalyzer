#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "faProgram.h"

#define TITLE "Foil Analyzer"

/* Upper level panel that holds the layout for the main menu.*/
class StartPanel : public wxPanel{
public:
	StartPanel(wxWindow* parent);
private:
	void onExitButton(wxCommandEvent& event);
	void onViewerButton(wxCommandEvent& event); // Defined in Main.cpp
};

// Button IDs for event connection
enum {
	EXIT_ID = 3,
	VIEWER_BUTTON_ID = 4
};

/* Constructs the layout of the main menu panel upon app initialization.
It also stores a reference to the main menu panel.*/
class MainMenu : public faProgram {
	StartPanel* mainMenuPanel;
public:
	MainMenu(wxWindow* topFrame);
	wxPanel* getTopPanel();
	bool initializeProgram(wxWindow* topFrame);
	// Shows and enables the main menu top level panel
	void show(bool show = true);
};