//this file is part of notepad++
//Copyright (C)2003 Don HO ( donho@altern.org )
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

#ifndef WINCONTROLS_TASKLIST_TASKLIST_H
#define WINCONTROLS_TASKLIST_TASKLIST_H

#ifndef WINCONTROLS_WINDOW_H
#include "WinControls/Window.h"
#endif

#ifndef WM_MOUSEWHEEL
#define WM_MOUSEWHEEL 0x020A
#endif //WM_MOUSEWHEEL

class TaskList : public Window
{
public:
	TaskList();
	virtual ~TaskList();

	virtual void destroy();

	//(Warning -- Member with different signature hides virtual member 'Window::init(struct HINSTANCE__ *, struct HWND__ *)'
	//lint -e1411
	void init(HINSTANCE hInst, HWND hwnd, HIMAGELIST hImaLst, int nbItem, int index2set);
	//lint +e1411

	void setFont(TCHAR *fontName, size_t fontSize);

	RECT adjustSize();
	int getCurrentIndex() const {return _currentIndex;}
	int updateCurrentIndex();

	HIMAGELIST getImgLst() const {
		return ListView_GetImageList(_hSelf, LVSIL_SMALL);
	};

	HFONT GetFontSelected() {return _hFontSelected;}

protected:

	WNDPROC _defaultProc;
	LRESULT runProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);

	static LRESULT CALLBACK staticProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
		return (((TaskList *)(::GetWindowLongPtr(hwnd, GWL_USERDATA)))->runProc(hwnd, Message, wParam, lParam));
	};

	HFONT _hFont;
	HFONT _hFontSelected;
	int _nbItem;
	int _currentIndex;
	RECT _rc;
};

#endif // WINCONTROLS_TASKLIST_TASKLIST_H
