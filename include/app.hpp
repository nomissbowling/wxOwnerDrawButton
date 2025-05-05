/*
  app.hpp
*/

#ifndef __APP_HPP__
#define __APP_HPP__

#include <common.hpp>
#include <frame.hpp>

using namespace common;
using namespace frame;

namespace app {

extern const wxCmdLineEntryDesc cmdLineDesc[];

class MyApp : public wxApp {
protected:
  MyFrame *frm;
public:
  MyApp() : frm(NULL) {}
  virtual ~MyApp(){}
public:
  virtual bool OnInit(){
    wxInitAllImageHandlers();
    if(!wxApp::OnInit()) return false;
    frm = new MyFrame(NULL, wxID_ANY, L"wxWidgetsTest 日本語 申能 表示",
      wxPoint(120, 120), wxSize(640, 480));
    SetTopWindow(frm);
    frm->Show(true);
    return true;
  }
  virtual int OnExit(){
    return wxApp::OnExit();
  }
  virtual void OnInitCmdLine(wxCmdLineParser& parser){
    parser.SetDesc(cmdLineDesc);
    parser.SetSwitchChars(L"-");
  }
  virtual bool OnCmdLineParsed(wxCmdLineParser& parser){
    bool silent = parser.Found(L"s");
    wcout << "silent: " << silent << endl;
    long num = -1;
    bool numstat = parser.Found(L"o", &num);
    wcout << "number: (" << numstat << ") " << num << endl;
    wxString fn("not found");
    bool stat = parser.Found(L"f", &fn);
    cout << "output file: (" << stat << ") [" << fn << "]" << endl; // use cout
    // wcout << "output file: (" << stat << ") [" << fn << "]" << endl; // BAD
    wxArrayString a;
    for(size_t i = 0; i < parser.GetParamCount(); ++i)
      a.Add(parser.GetParam(i));
    wcout << "param count: " << a.Count() << endl;
    for(size_t i = 0; i < a.Count(); ++i)
      cout << " p[" << i << "]: " << a[i] << endl; // use cout
      // wcout << " p[" << i << "]: " << a[i] << endl; // BAD
    return true;
  }
};

}

#endif // __APP_HPP__
