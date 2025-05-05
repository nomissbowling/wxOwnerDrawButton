/*
  odbtn.hpp

  owner draw button
*/

#ifndef __ODBTN_HPP__
#define __ODBTN_HPP__

#include <common.hpp>

using namespace common;

namespace odbtn {

class ODBtn: public wxAnyButton {
protected:
  wxBitmap bbg;
  wxVector<wxBitmap> bis;
  wxPoint o;
  wxSize wh;
  size_t currentIdx;
public:
  ODBtn(wxWindow *parent, wxWindowID id, const wxPoint &pt, const wxSize &sz,
    wxVector<wxBitmap> &bmps): wxAnyButton(), bis(), o(), wh(), currentIdx(0) {
    Create(parent, id, pt, sz); // wxControl
    wh = wxSize(bmps[0].GetWidth(), bmps[0].GetHeight());
    o = wxPoint((sz.x - wh.x) / 2, (sz.y - wh.y) / 2);
    bbg = wxBitmap(sz, wxBITMAP_SCREEN_DEPTH);
    for(auto &e: bmps){ // for(auto it = bmps.begin(); it != bmps.end(); ++it){
      wxImage im = e.ConvertToImage();
      im.Rescale(wh.x, wh.y, wxIMAGE_QUALITY_HIGH); // _BOX_AVERAGE _BICUBIC
      bis.push_back(wxBitmap(im));
    }
    // SetBitmap(bis[0], wxLEFT);
    Bind(wxEVT_PAINT, &ODBtn::OnPaint, this, id);
    Bind(wxEVT_ERASE_BACKGROUND, &ODBtn::OnEraseBG, this, id);
    Bind(wxEVT_LEAVE_WINDOW, &ODBtn::OnMouseLeave, this, id);
    Bind(wxEVT_ENTER_WINDOW, &ODBtn::OnMouseOver, this, id);
    Bind(wxEVT_LEFT_DOWN, &ODBtn::OnMouseClick, this, id);
    Bind(wxEVT_LEFT_UP, &ODBtn::OnMouseRelease, this, id);
    Show(true);
    Refresh(true);
  }
  virtual ~ODBtn(){}
public:
  virtual void OnPaint(wxPaintEvent &ev){
    // cout << "OnPaint" << endl;
    wxPaintDC dc(this);
    wxSize sz = dc.GetSize();
    wxMemoryDC bdc;
    wxMemoryDC mdc;
    bdc.SelectObject(bbg);
    dc.Blit(0, 0, sz.x, sz.y, &bdc, 0, 0, wxCOPY, true);
    bdc.SelectObject(wxNullBitmap);
    mdc.SelectObject(bis[currentIdx]);
    dc.Blit(o.x, o.y, wh.x, wh.y, &mdc, 0, 0, wxCOPY, true);
    mdc.SelectObject(wxNullBitmap);
    ev.Skip();
    // wxAnyButton::OnPaint(ev);
  }
  virtual void OnEraseBG(wxEraseEvent &ev){
    // cout << "OnEraseBG" << endl;
    // wxAnyButton::OnEraseBG(ev);
  }
  virtual void OnMouseLeave(wxMouseEvent &ev){
    // cout << "OnMouseLeave" << endl;
    currentIdx = 0;
    Refresh(true);
    ev.Skip();
  }
  virtual void OnMouseOver(wxMouseEvent &ev){
    // cout << "OnMouseOver" << endl;
    currentIdx = ev.LeftIsDown() ? 2 : 1;
    Refresh(true);
    ev.Skip();
  }
  virtual void OnMouseClick(wxMouseEvent &ev){
    // cout << "OnMouseClick" << endl;
    currentIdx = 2;
    Refresh(true);
    ev.Skip();
  }
  virtual void OnMouseRelease(wxMouseEvent &ev){
    // cout << "OnMouseRelease" << endl;
    if(currentIdx == 2){
      wxCommandEvent cev(wxEVT_BUTTON, GetId());
      // GetParent()->AddPendingEvent(cev); // QueueEvent(&ev)
      cev.SetEventObject(this);
      ProcessWindowEvent(cev);
    }
    currentIdx = 3;
    Refresh(true);
    ev.Skip();
  }
};

}

#endif // __ODBTN_HPP__
