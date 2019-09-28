// Main.cpp
// Author: Mark Bashqawi
// Handles the initiation of the program and starts the GUI

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/graphics.h>
#include <wx/sizer.h>

class FoilApp : public wxApp {
public:
	virtual bool OnInit();
};

class TopFrame : public wxFrame {
public:
	TopFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
};

wxIMPLEMENT_APP(FoilApp);
bool FoilApp::OnInit() {

	TopFrame* topFrame = new TopFrame("FoilAnalyzer", wxPoint(0,0), wxSize(800,600));


	topFrame->Show(true);
	return true;
}

TopFrame::TopFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
	: wxFrame(NULL, wxID_ANY, title, pos, size) {

	wxMenu *menuFile = new wxMenu;
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
}