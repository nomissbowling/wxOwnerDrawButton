/*
  app.cpp
*/

#include <app.hpp>

namespace app {

/* static */ const wxCmdLineEntryDesc cmdLineDesc[] = {
  {wxCMD_LINE_SWITCH, "h", "help", "show this help message",
    wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP},
  {wxCMD_LINE_SWITCH, NULL, "verbose", "generate verbose log messages"},
  {wxCMD_LINE_SWITCH, "t", "test", "test switch",
    wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_MANDATORY},
  {wxCMD_LINE_SWITCH, "s", "silent", "disables the GUI"},
  {wxCMD_LINE_OPTION, "o", "option", "option number",
    wxCMD_LINE_VAL_NUMBER, wxCMD_LINE_PARAM_OPTIONAL},
  {wxCMD_LINE_OPTION, "f", "file", "output file",
    wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},
  {wxCMD_LINE_PARAM, NULL, NULL, "input file(s)",
    wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_MULTIPLE}, // requires at least one
  {wxCMD_LINE_NONE}};

}
