//this file is part of notepad++
//Copyright (C)2010 Don HO <don.h@free.fr>
//
//This program is free software; you can redistribute it and/or
//modify it under the terms of the GNU General Public License
//as published by the Free Software Foundation; either
//version 2 of the License, or (at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program; if not, write to the Free Software
//Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#ifndef NOTEPAD_PLUS_WINDOW_H
#define NOTEPAD_PLUS_WINDOW_H

#ifndef WINCONTROLS_WINDOW_H
#include "WinControls/Window.h"
#endif

// Forward declarations
struct CmdLineParams;
class Notepad_plus;

class Notepad_plus_Window : public Window {
public:
	Notepad_plus_Window();
	~Notepad_plus_Window();
	void init(HINSTANCE, HWND, const TCHAR *cmdLine, CmdLineParams *cmdLineParams);

	bool isDlgsMsg(MSG *msg, bool unicodeSupported) const;

	HACCEL getAccTable() const;

	bool emergency(generic_string emergencySavedDir);

	bool isPrelaunch() const {
		return _isPrelaunch;
	}

	void setIsPrelaunch(bool val) {
		_isPrelaunch = val;
	}

	static const TCHAR * Notepad_plus_Window::getClassName() {
		return _className;
	}
	static HWND gNppHWND;	//static handle to Notepad++ window, NULL if non-existant

private:
	// JOCE: Circular references...
	// Notepad_plus_Window::_notepad_plus_plus_core => Notepad_plus
	// Notepad_plus::_pPublicInterface => Notepad_plus_Window
	// This is wrong on so many level, I do know where to start...
	Notepad_plus* _notepad_plus_plus_core;
	static LRESULT CALLBACK Notepad_plus_Proc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
	LRESULT runProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);

	static const TCHAR _className[32];
	bool _isPrelaunch;
	bool _disablePluginsManager;
};

#endif //NOTEPAD_PLUS_WINDOW_H
