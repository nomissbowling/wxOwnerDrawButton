/*
  frame.hpp
*/

#ifndef __FRAME_HPP__
#define __FRAME_HPP__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESOURCES_DIR "./resources/"
#define RESOURCES_BMP RESOURCES_DIR"wx_64x64.png"
#define BTN RESOURCES_DIR"wx_64x64_btn.png"
#define HOVER RESOURCES_DIR"wx_64x64_hover.png"
#define PUSH RESOURCES_DIR"wx_64x64_push.png"
#define RELEASE RESOURCES_DIR"wx_64x64_release.png"

#include <common.hpp>
#include <odbtn.hpp>

using namespace common;
using namespace odbtn;

namespace frame {

wxBitmap load_png(const char *png);

class MyFrame : public wxFrame {
protected:
  wxBitmap bmp;
  wxBitmap bms;
  wxStaticBitmap *sb;
  wxWindowID ids;
/*
  wxButton *txbtn;
  wxBitmapButton *bmbtn;
  wxButton *dcbtn;
  ODBtn *btn;
*/
  wxAnyButton *txbtn, *bmbtn, *dcbtn, *btn;
public:
  MyFrame(wxWindow *parent, wxWindowID id, const wxString &title,
    const wxPoint &pt, const wxSize &sz) : wxFrame(parent, id, title, pt, sz),
    bmp(), bms(), sb(NULL), ids(0), txbtn(NULL), bmbtn(NULL), dcbtn(NULL) {
    wxSize wh = GetClientSize();
    wcout << wh.x << ", " << wh.y << endl;
    SetLayeredAndColours(this, 0, 192, LWA_ALPHA,
      wxColour(240, 192, 32), wxColour(96, 32, 32));
    ClearBackground();
    wxMenuBar *mb = new wxMenuBar();
    wxMenu *mf = new wxMenu();
    mf->Append(wxID_EXIT, L"&Quit");
    mb->Append(mf, L"&File");
    wxMenu *mh = new wxMenu();
    mh->Append(wxID_ABORT, L"&Test(close)");
    mb->Append(mh, L"&Help");
    SetMenuBar(mb);

    bmp = load_png(RESOURCES_BMP);
    wxIcon ico;
    ico.CopyFromBitmap(bmp);
    SetIcon(ico);

    wxPanel *pnl = new wxPanel(this, wxID_ANY);
    ids = wxWindow::NewControlId(4);

    wxImage bmi = bmp.ConvertToImage();
    bmi.Rescale(16, 16, wxIMAGE_QUALITY_HIGH); // select _BOX_AVERAGE _BICUBIC
    bms = wxBitmap(bmi);
    sb = new wxStaticBitmap(pnl, wxID_ANY, bms, wxPoint(0, 0));

    const char *res[] = {BTN, HOVER, PUSH, RELEASE};
    wxVector<wxBitmap> bmps;
    for(size_t i = 0; i < sizeof(res) / sizeof(res[0]); ++i)
      bmps.push_back(load_png(res[i]));
    btn = new ODBtn(pnl, ids + 3, wxPoint(20, 300), wxSize(96, 96), bmps);
    Bind(wxEVT_BUTTON, &MyFrame::OnExit, this, ids + 3);

    dcbtn = new wxButton(pnl, ids + 2, L"&Bmp", wxPoint(20, 200));
    Bind(wxEVT_BUTTON, &MyFrame::OnExit, this, ids + 2);
/*
    // bitmap with label on normal button for wxWidgets >= 3.1.6
    wxVector<wxBitmap> bmps;
    bmps.push_back(bmp);
    dcbtn->SetBitmap(wxBitmapBundle::FromBitmaps(bmps), wxLEFT);
    // SetBitmapFocus()
    // SetBitmapPressed()
    // SetBitmapCurrent()
    // SetBitmapDisabled()
*/
    // bitmap with label on normal button for wxWidgets < 3.1.6 (not effect)
    dcbtn->SetBitmap(bms, wxLEFT);
    dcbtn->SetBitmapFocus(bms);
    dcbtn->SetBitmapPressed(bms);
    dcbtn->SetBitmapCurrent(bms);
    dcbtn->SetBitmapDisabled(bms);
    // dcbtn->SetBitmapMargins(0, 0);
    // dcbtn->SetBitmapPosition(wxLEFT);
    // dcbtn->SetBitmapLabel(bms);

    // wxBitmap bm = wxBitmap(wxSize(64, 64), wxBITMAP_SCREEN_DEPTH);
    bmbtn = new wxBitmapButton(pnl, ids + 1, bmp,
      wxPoint(20, 80), wxSize(64, 64), 0);
    Bind(wxEVT_BUTTON, &MyFrame::OnExit, this, ids + 1);

    txbtn = new wxButton(pnl, ids + 0, L"&Normal", wxPoint(20, 40));
    Bind(wxEVT_BUTTON, &MyFrame::OnExit, this, ids + 0);

    CreateStatusBar();
    SetStatusText(L"test 日本語 漢字 表申能 森鷗外𠮟る");
    Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this); // no (, wxID_CLOSE)
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, [this](wxCommandEvent &ev){ Close(true); }, wxID_ABORT);
    SetClientSize(sz);
    wh = GetClientSize();
    wcout << wh.x << ", " << wh.y << endl;
  }
  virtual ~MyFrame(){}
public:
  virtual void OnClose(wxCloseEvent &ev){
    wcout << "closed" << endl;
    Destroy();
  }
  virtual void OnExit(wxCommandEvent &ev){
    wcout << "exit" << endl;
    Close(true);
  }
  virtual void OnPaint(wxPaintEvent &ev){
//    wxPaintDC dc(this);
/*
    // draw bitmap on normal button for wxWidgets < 3.1.6 (not effect)
    wxPaintDC *dc = new wxPaintDC(dcbtn);
    dc->DrawBitmap(bmp, wxPoint(0, 0));
*/
  }
};

}

#endif // __FRAME_HPP__
