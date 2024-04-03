#include "Font.h"
#include<windows.h>
Font::Font()
{
    //ctor
}

Font::~Font()
{
    //dtor
}
void Font:: fontsize(int n,int m)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
  lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
  GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
  lpConsoleCurrentFontEx->dwFontSize.X = n;
  lpConsoleCurrentFontEx->dwFontSize.Y = m;
  SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}




void Font::PlaceCursor(const int x, const int y)
 {


HWND console = GetConsoleWindow();
        RECT ConsoleRect;
        GetWindowRect(console, &ConsoleRect);
        MoveWindow(console, ConsoleRect.left, ConsoleRect.top, x, y, TRUE);

    return;

}
