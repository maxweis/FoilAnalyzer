#pragma once

#include <map>
#include <vector>

#include <wx/wxprec.h>
#include <wx/wx.h>

enum axisDirection {
	HORIZONTAL,
	VERTICAL
};

class Axis {
	double limits[2];
	double step;
	int boundary[2];
	axisDirection dir;
	std::string label;
	wxPoint origin;
	double vOrigin[2]{};

	std::map<double, int> valueLocs;

	void calculateVLocs();
public:
	Axis(axisDirection dir, int boundary[2], wxPoint& origin, double vOrigin[2]);
	Axis(axisDirection dir, int boundary[2], wxPoint& origin, double vOrigin[2], double limits[2], double step);
	double getLowerLimit();
	double getUpperLimit();
	std::map<double, int> getVLocs();
	void setBoundary(int boundary[2]);
	void setOrigin(wxPoint origin);
	void setVOrigin(double vOrigin[2]);
	void updateAxis(int boundary[2], wxPoint origin, double vOrigin[2]);
	void draw(wxDC& dc);
};
