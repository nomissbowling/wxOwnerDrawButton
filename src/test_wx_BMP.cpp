/*
  test_wx_BMP.cpp

  see also wxWidgetsTest.cpp

  Project - Build options
   Release (select)

  Compiler settings
   Compiler Flags
    Target x86_64 (64bit) [-m64] check

   #defines
    UNICODE
    _UNICODE
    __WXMSW__
    WXUSINGDLL
    NODEBUG

  Linker settings
   Link libraries:
    wxbase31u
    wxbase31u_net
    wxbase31u_xml
    wxmsw31u_core
    wxmsw31u_adv
    wxmsw31u_aui
    wxmsw31u_gl
    wxmsw31u_media
    wxmsw31u_propgrid
    wxmsw31u_ribbon
    wxmsw31u_richtext
    wxmsw31u_stc
    wxmsw31u_html
    wxmsw31u_webview
    wxmsw31u_xrc
    wxregexu
    wxexpat
    wxjpeg
    wxpng
    wxtiff
    wxzlib
    wxscintilla

  Search directories
   Compiler
    ..\wxWidgets-3.1.4\MinGW_GCC_810\include
    x ..\wxWidgets-3.1.4\MinGW_GCC_810\include\msvc
    ..\wxWidgets-3.1.4\MinGW_GCC_810\lib\gcc810_x64_dll\mswu
   Linker
    ..\wxWidgets-3.1.4\MinGW_GCC_810\lib\gcc810_x64_dll

  (Runtime)
   (Copy dlls to C:\prj\__CodeBlocks\test_wx_BMP\bin\Release)
    ..\wxWidgets-3.1.4\MinGW_GCC_810\dll\gcc810_x64_dll
     wxbase314u_gcc810_x64.dll
     wxbase314u_net_gcc810_x64.dll
     wxbase314u_xml_gcc810_x64.dll
     wxmsw314u_core_gcc810_x64.dll
     wxmsw314u_adv_gcc810_x64.dll
     wxmsw314u_aui_gcc810_x64.dll
     wxmsw314u_gl_gcc810_x64.dll
     wxmsw314u_media_gcc810_x64.dll
     wxmsw314u_propgrid_gcc810_x64.dll
     wxmsw314u_ribbon_gcc810_x64.dll
     wxmsw314u_richtext_gcc810_x64.dll
     wxmsw314u_stc_gcc810_x64.dll
     wxmsw314u_html_gcc810_x64.dll
     wxmsw314u_webview_gcc810_x64.dll
     wxmsw314u_xrc_gcc810_x64.dll
    C:\Program Files\CodeBlocks\MinGW\bin
     libgcc_s_seh-1.dll
     libstdc++-6.dll
     libwinpthread-1.dll
     libatomic-1.dll
     libgomp-1.dll
     libquadmath-0.dll
     libssp-0.dll

  (test)
  > test_wx_BMP\bin\Release\test_wx_BMP -o=123 -f=申能 漢字 能申 abc
  > test_wx_BMP\bin\Release\test_wx_BMP -s -t -o=123 -f=申能 漢字 能申
  > test_wx_BMP\bin\Release\test_wx_BMP -s -t -f=申能 漢字 能申
  > test_wx_BMP\bin\Release\test_wx_BMP -s -t -o=123 漢字 能申
  > test_wx_BMP\bin\Release\test_wx_BMP -s -t
  > test_wx_BMP\bin\Release\test_wx_BMP a -t

*/

#include <test_wx_BMP.hpp>

using namespace app;

#if 0
wxDECLARE_APP(MyApp); // to use wxGetApp()
wxIMPLEMENT_APP(MyApp);
#else
int main(int ac, char **av)
// int wmain(int ac, wchar_t **av)
{
  wcout << "sizeof(size_t): " << sizeof(size_t) << endl;
  cout << "Hello world! (A)" << endl;
  wcout << L"Hello world! (W)" << endl;
  int exitcode = 0;
  wxApp::SetInstance(new MyApp());
  bool r = wxEntryStart(ac, av);
  cout << "bool: " << r << endl;
  // wxTheApp->A(); or wxGetApp().A();
  if(wxTheApp->CallOnInit()){ // check OnInitCmdLine, OnCmdLineParsed, OnInit
    exitcode = wxTheApp->OnRun();
    wxTheApp->OnExit();
  }else{
    exitcode = -1; // OnInit, OnCmdLineParsed, OnInitCmdLine Parser fault etc
  }
  wxEntryCleanup();
  return exitcode;
}
#endif
