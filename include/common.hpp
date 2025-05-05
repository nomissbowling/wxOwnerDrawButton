/*
  common.hpp
*/

#ifndef __COMMON_HPP__
#define __COMMON_HPP__

// UNICODE and _UNICODE are defined in test_wx_BMP.cbp
// #define UNICODE
// #define _UNICODE
#include <wchar.h>

#include <iostream>

#include <wx/cmdline.h>
#include <wx/wx.h>

using namespace std;

namespace common {

inline
void SetLayeredAndColours(wxWindow *w, DWORD cr, DWORD a, DWORD lwa,
  const wxColour &bgc, const wxColour &fgc)
{
#ifdef __WXMSW__ // BUILD_WINDOWS // user32.lib
  HWND hwnd = reinterpret_cast<HWND>(w->GetHandle());
  auto style = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
  SetWindowLong(hwnd, GWL_EXSTYLE, style | WS_EX_LAYERED);
  SetLayeredWindowAttributes(hwnd, cr, a, lwa); // use crKey with LWA_COLORKEY
#endif
  w->SetBackgroundColour(bgc); // StylesFactory::BackgroundColor
  w->SetForegroundColour(fgc); // StylesFactory::ForegroundColor
}

}

#endif // __COMMON_HPP__
