#include <conio.h> // Just for WaitKey() routine
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()



void welcome()
{

   HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    int len = 0,x, y=245; // 240 = white background, black foreground

std::    string text = " Welcome To Hostel Management System ";
    len = text.length();
    std::cout  << std::endl <<std:: endl <<std:: endl<<std:: endl<<std:: endl<<std:: endl<<std:: endl << "\t\t";// start 3 down, 2 tabs, right
    for ( x=0;x<len;x++)
    {
        SetConsoleTextAttribute(console, y); // set color for the next print
std::        cout << text[x];
        y++; // add 1 to y, for a new color
        if(y==247 ||y==254 ||y==240)
{y=y+1;}
        if ( y >254) // There are 255 colors. 255 being white on white. Nothing to see. Bypass it
            y=245; // if y > 254, start colors back at white background, black chars
        Sleep(250); // Pause between letters
    }

    SetConsoleTextAttribute(console, 15); // set color to black background, white chars

    Sleep(1000);

    system("CLS"); // Program over, wait for a keypress to close program
}



