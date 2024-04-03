#include "Interface.h"
#include "Employee.h"
#include "Receptionist.h"
#include "Manager.h"
#include "Porter.h"
#include "Guest.h"
#include "Waiter.h"
#include "Cook.h"
#include "Cleaner.h"
#include "Guard.h"
#include"Room.h"
#include<iostream>
#include<fstream>
#include"Font.h"

Interface::Interface()
{

    r_obj=new Room;
    load_stat_room();
    main_func();
}
void Interface::main_func()
{


    while(1)
    {
        Font::fontsize(20,25);
        system("CLS");
        system ("color 04");
        Font::PlaceCursor(1920,1080);
        std::cout<<"\n\n\n\n\n\n";
        std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
        std::cout<<"\t\t\t\t\t\tWelcome To  Main Menu\n";
        std::cout<<"\t\t\t\t====================================================\n";
        std::cout<<"\t\t\t\t\t\tThe Login Options Are :"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 1  Login AS Manager"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 2  Login AS Guest"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 3  Login AS Receptionist"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 4  Login AS Porter"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 5  Login AS Waiter"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 6  Login AS Cook"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 7  Login AS Cleaner"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 8  Login AS Guard"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 9  Close The Program"<<std::endl;
        int x;
        std::cout<<"\t\t\t\t\t\tPress The Button :";
        std::cin>>x;
        if(x==1)
        {
            Manager* obj;
            obj=new Manager;
            if(obj->login_op())
            {
                obj->main_func_mng();
            }
            else
            {  system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n"<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tIncorrect ID & Password . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tEnter it again correctly . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tGoing To Main Menu . "<<std::endl;
                Sleep(1000);
            }
            delete obj;
        }
        else if(x==2)
        {
            Guest* obj;
            obj=new Guest;
            if(obj->login_op())
            {
                obj->main_func_gst();
            }
            else
            {   system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n"<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tIncorrect ID & Password . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tEnter it again correctly . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tGoing To Main Menu . "<<std::endl;
                Sleep(1000);
            }
            delete obj;
        }
        else if(x==3)
        {
            Receptionist* obj;
            obj=new Receptionist;
            if(obj->login_op())
            {
                obj->main_func_recep();
            }
            else
            {   system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n"<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tIncorrect ID & Password . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tEnter it again correctly . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tGoing To Main Menu . "<<std::endl;
                Sleep(1000);
            }
            delete obj;
        }
        else if(x==4)
        {
            Porter* obj;
            obj=new Porter;
            if(obj->login_op())
            {
                obj->main_func_prt();
            }
            else
            {   system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n"<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tIncorrect ID & Password . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tEnter it again correctly . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tGoing To Main Menu . "<<std::endl;
                Sleep(1000);
            }
            delete obj;
        }
        else if(x==5)
        {
            Waiter* obj;
            obj=new Waiter;
            if(obj->login_op())
            {
                obj->main_func_wtr();
            }
            else
            {   system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n"<<std::endl;
               std::cout<<"\n\t\t\t\t\t\tIncorrect ID & Password . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tEnter it again correctly . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tGoing To Main Menu . "<<std::endl;
                Sleep(1000);
            }
            delete obj;
        }
        else if(x==6)
        {
            Cook* obj;
            obj=new Cook;
            if(obj->login_op())
            {
                obj->main_func_cok();
            }
            else
            {   system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n"<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tIncorrect ID & Password . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tEnter it again correctly . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tGoing To Main Menu . "<<std::endl;
                Sleep(1000);
            }
            delete obj;
        }
        else if(x==7)
        {
            Cleaner* obj=new Cleaner;
            if(obj->login_op())
            {
                obj->main_func_cln();
            }
            else
            {
                system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n"<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tIncorrect ID & Password . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tEnter it again correctly . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tGoing To Main Menu . "<<std::endl;
                Sleep(1000);
            }
            delete obj;
        }
        else if(x==8)
        {
            Guard* obj=new Guard;
            if(obj->login_op())
            {
                obj->disk_in();
            }
            else
            {
                system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n"<<std::endl;
            std::cout<<"\n\t\t\t\t\t\tIncorrect ID & Password . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tEnter it again correctly . "<<std::endl;
                std::cout<<"\n\t\t\t\t\t\tGoing To Main Menu . "<<std::endl;
                Sleep(1000);
            }
            delete obj;
        }
        else if(x==9)
        {
              system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tProgram is Closed . "<<std::endl;
            Sleep(1000);

            break;
        }
        else
        {

            system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tInvalid Input .Press The correct Button . "<<std::endl;
            Sleep(1000);


        }
        Sleep(250);
    }
}

void Interface::load_stat_room()
{
    std::ifstream infile("stat_room.txt");
    if(!infile)
    {
        std::cout<<"\n\t\t\t\t\t\tThere is no file to load"<<std::endl;
        return ;
    }
    int r;
    infile>>r;
    int floor=r/100;
    r%=100;
    r=(r-1)+(30*(floor-1));
    r_obj->rooms[r]=full;
    while(!infile.eof())
    {
        infile>>r;
        int floor=r/100;
        r%=100;
        r=(r-1)+(30*(floor-1));
        r_obj->rooms[r]=full;
    }
    infile.close();
}

void Interface::save_stat_room()
{
    std::ofstream outfile("stat_room.txt");
    for(int i=101; i<=130; i++)
    {
        if(r_obj->occupied(i))
        {
            outfile<<i
                   <<' ';
        }
    }
    for(int i=201; i<=230; i++)
    {
        if(r_obj->occupied(i))
        {
            outfile<<i
                   <<' ';
        }
    }
    for(int i=301; i<=330; i++)
    {
        if(r_obj->occupied(i))
        {
            outfile<<i
                   <<' ';
        }
    }
    outfile.close();
}
