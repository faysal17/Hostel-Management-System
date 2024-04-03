#include <iostream>
#include<Employee.h>
#include<Guest.h>
#include"Interface.h"
#include"Room.h"
#include"Font.h"
#include"welcome.h"
using namespace std;

Variety Room::rooms[] = {emptyy};

int main()
{  Font::fontsize(0,50);
    welcome();
    Interface* obj;
    obj=new Interface;
    delete obj;
    return 0;
}
