/*
  frame.cpp
*/

#include <frame.hpp>

namespace frame {

wxBitmap load_png(const char *png)
{
  FILE *fp = fopen(png, "rb");
  if(!fp){
    return wxBitmap(wxSize(32, 32), wxBITMAP_SCREEN_DEPTH);
  }else{
    char buf[32768];
    size_t sz = fread(buf, 1, sizeof(buf), fp);
    // fprintf(stdout, "%zd\n", sz);
    wxBitmap bmp = wxBitmap::NewFromPNGData(buf, sz);
    fclose(fp);
    return bmp;
  }
}

}
