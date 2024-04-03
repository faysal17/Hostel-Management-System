#include "Manager.h"
#include "Employee.h"
#include "Receptionist.h"
#include "Porter.h"
#include "Waiter.h"
#include "Cook.h"
#include "Cleaner.h"
#include "Guard.h"
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
Manager::Manager()
{
    //main_func_mng();
}

void Manager::main_func_mng()
{
    system("CLS");
    system("color 61");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome Manager\n";
    std::cout<<"\t\t\t\t====================================================\n";
    Sleep(500);

    while(1)
    {
        system("CLS");
        std::cout<<"\n\n\n\n\n\n";
        std::cout<<"\n\t\t\t\t\t\tThe Manager Menu\n"<<std::endl;
        std::cout<<"\t\t\t\t====================================================\n";
        std::cout<<"\t\t\t\t->Press 1 to Appoint Employee."<<std::endl;
        std::cout<<"\t\t\t\t->Press 2 to Fire Employee"<<std::endl;
        std::cout<<"\t\t\t\t->Press 3 to See Employee's Information"<<std::endl;
        std::cout<<"\t\t\t\t->Press 4 to See Current Month's Profit"<<std::endl;
        std::cout<<"\t\t\t\t->Press 5 to Exit Manager"<<std::endl;
        int x;
        std::cout<<"\n\t\t\t\tPress The Button :";
        std::cin>>x;
        if(x==1)
        {
            add_mng();
            int e=0;
            std::ifstream infile("count_emp.txt");
            if(infile)
            {
                infile>>e;
                infile.close();
            }
            e++;
            std::ofstream outfile("count_emp.txt");
            outfile<<e
                   <<' ';
            outfile.close();
        }
        else if(x==2)
            del_rec();
        else if(x==3)
            show_info_otr();
        else if(x==4)
        {
            int e=0;
            std::ifstream infile("count_emp.txt");
            if(infile)
            {
                infile>>e;
                infile.close();
            }
            show_this_month_profit(e);
        }
        else if(x==5)
        {
            system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tClosing Manager Menu"<<std::endl;
            Sleep(100);
            break;
        }
        else
            {
                system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tInvalid Input .Press The correct Button . "<<std::endl;
            Sleep(1000);
            }
    }
}

void Manager::add_mng()
{
    system("CLS");
    system("color 21");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To Appoint Employee Menu\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::cout<<"\n\t\t\t\t\t\tHow many employee you want to appoint?";
    int x;
    std::cin>>x;
    for(int i=0; i<x; i++)
    {
        Sleep(250);
        system("CLS");
        system("color 21");
        std::cout<<"\n\n\n\n\n\n";

        std::cout<<"\n\t\t\t\t\t\tPress The Appropiate Button To Appoint Employee"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 1 To Appoint Receptionist."<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 2 To Appoint Guard"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 3 To Appoint Cleaner"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 4 To Appoint Cook"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 5 To Appoint Waiter"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 6 To Appoint Porter"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 7 To Exit The Appoint Employee Menu"<<std::endl;
        int y;
        std::cout<<"\n\t\t\t\tPrees The Button : ";
        std::cin>>y;
        if(y==1)
        {
            Employee* obj=new Receptionist;
            obj->disk_out();
            delete obj;
        }
        else if(y==2)
        {
            Employee* obj=new Guard;
            obj->disk_out();
            delete obj;
        }
        else if(y==3)
        {
            Employee* obj=new Cleaner;
            obj->disk_out();
            delete obj;
        }
        else if(y==4)
        {
            Employee* obj=new Cook;
            obj->disk_out();
            delete obj;
        }
        else if(y==5)
        {
            Employee* obj=new Waiter;
            obj->disk_out();
            delete obj;
        }
        else if(y==6)
        {
            Employee* obj=new Porter;
            obj->disk_out();
            delete obj;
        }
        else if(y==7)
            {
                system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tClosing The Appoint Employee Menu"<<std::endl;
            Sleep(100);
            break;
            }
            else{

                system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tInvalid Input .Press The correct Button . "<<std::endl;
            Sleep(1000);
            }
    }
}

void Manager::del_rec()
{
    while(1)
    {
        system("CLS");
        system("color 40");
        std::cout<<"\n\n\n\n\n\n";
        std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
        std::cout<<"\t\t\t\t\t\tWelcome To Fire Employee Menu\n";
        std::cout<<"\t\t\t\t====================================================\n";
        std::cout<<"\n\t\t\t\t\t\tPress The Appropiate Button To Fire Employee"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 1 To Fire Receptionist."<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 2 To Fire Guard"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 3 To Fire Cleaner"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 4 To Fire Cook"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 5 To Fire Waiter"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 6 To Fire Porter"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 7 for Exit Fire Employee menu"<<std::endl;
        int x;
        std::cout<<"\n\t\t\t\tPress The Button : ";
        std::cin>>x;
        if(x==1)
        {
            Employee* obj=new Receptionist;
            obj->del_own_rec();
            delete obj;
        }
        else if(x==2)
        {
            Employee* obj=new Guard;
            obj->del_own_rec();
            delete obj;
        }
        else if(x==3)
        {
            Employee* obj=new Cleaner;
            obj->del_own_rec();
            delete obj;
        }
        else if(x==4)
        {
            Employee* obj=new Cook;
            obj->del_own_rec();
            delete obj;
        }
        else if(x==5)
        {
            Employee* obj=new Waiter;
            obj->del_own_rec();
            delete obj;
        }
        else if(x==6)
        {
            Employee* obj=new Porter;
            obj->del_own_rec();
            delete obj;
        }
        else if(x==7)
            {
                system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tClosing The Fire Employee Menu"<<std::endl;
            Sleep(100);
            break;
            }
            else{
                system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tInvalid Input .Press The correct Button . "<<std::endl;
            Sleep(1000);
            }
    }
}

void Manager::show_info_otr()
{
    while(1)
    {
        system("CLS");
        system("color 0B");
        std::cout<<"\n\n\n\n\n\n";
        std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
        std::cout<<"\t\t\t\t\t\tWelcome To  Employee's Information Menu\n";
        std::cout<<"\t\t\t\t====================================================\n";
        std::cout<<"\n\t\t\t\t\t\tPress The Appropiate Button "<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 1 To See Receptionist."<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 2 To See Guard"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 3 To See Cleaner"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 4 To See Cook"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 5 To See Waiter"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 6 To See Porter"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 7 for Exit Employee's Information Menu"<<std::endl;
        int x;
        std::cout<<"\n\t\t\t\tPress The Button : ";
        std::cin>>x;
        if(x==1)
        {
            Employee* obj=new Receptionist;

            system("CLS");
            system("color 0B");
            std::cout<<"\n\n\n\n\n\n";
            std::cout<<"\t\t\t\t\t\tShowing  Receptionist's Information"<<std::endl;
            std::cout<<"\t\t\t\t*********************************************************"<<std::endl;

            obj->disk_in();
            std::cout<<"\t\t\t\t\t\tPress any key";getch();
            delete obj;
        }
        else if(x==2)
        {
            Employee* obj=new Guard;
            system("CLS");
            system("color 0B");
            std::cout<<"\n\n\n\n\n\n";
            std::cout<<"\t\t\t\t\t\tShowing  Guard's Information"<<std::endl;
            std::cout<<"\t\t\t\t*********************************************************"<<std::endl;
            Sleep(1000);
            obj->disk_in();

            delete obj;
        }
        else if(x==3)
        {
            Employee* obj=new Cleaner;

            system("CLS");
            system("color 0B");
            std::cout<<"\n\n\n\n\n\n";
            std::cout<<"\t\t\t\t\t\tShowing Cleaner's Information"<<std::endl;
            std::cout<<"\t\t\t\t*********************************************************"<<std::endl;
            obj->disk_in();
            std::cout<<"\t\t\t\t\t\tPress any key";getch();
            delete obj;
        }
        else if(x==4)
        {
            Employee* obj=new Cook;

            system("CLS");
            system("color 0B");
            std::cout<<"\n\n\n\n\n\n";
            std::cout<<"\t\t\t\t\t\tShowing  Cook's Information"<<std::endl;
            std::cout<<"\t\t\t\t*********************************************************"<<std::endl;
            obj->disk_in();
            std::cout<<"\t\t\t\t\t\tPress any key";getch();
            delete obj;
        }
        else if(x==5)
        {
            Employee* obj=new Waiter;

            system("CLS");
            system("color 0B");
            std::cout<<"\n\n\n\n\n\n";
            std::cout<<"\t\t\t\t\t\tShowing Waiter's Information"<<std::endl;
            std::cout<<"\t\t\t\t*********************************************************"<<std::endl;
            obj->disk_in();
            std::cout<<"\t\t\t\t\t\tPress any key";getch();
            delete obj;
        }
        else if(x==6)
        {
            Employee* obj=new Porter;

            system("CLS");
            system("color 0B");
            std::cout<<"\n\n\n\n\n\n";
            std::cout<<"\t\t\t\t\t\tShowing  Porter's Information"<<std::endl;
            std::cout<<"\t\t\t\t*********************************************************"<<std::endl;
            obj->disk_in();
            std::cout<<"\t\t\t\t\t\tPress any key";getch();
            delete obj;
        }
        else if(x==7)

            {
               system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tClosing The  Employee's Information Menu"<<std::endl;
            Sleep(1000);
            break;
            }
            else{system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tInvalid Input .Press The correct Button . "<<std::endl;
            Sleep(1000);}
    }
}
void Manager::disk_out()
{
//boss implement
}

void Manager::disk_in()
{
//boss implement
}
std::string Manager::id_gnrt(std::string s_name)
{
    //boss implement
}
std::string Manager::pwd_gnrt()
{
    //boss implement
}
const void Manager::show_info()
{
    std::cout<<"\t\t\t\t\t\Manager ID : "<<Getid()<<std::endl;
    std::cout<<"\t\t\t\t\t\tManager Password : "<<Getpwd()<<std::endl;
    std::cout<<"\t\t\t\t\t\tManager Name : "<<Getname()<<std::endl;
    std::cout<<"\t\t\t\t\t\tManager Designation : "<<Getdesg()<<std::endl;
}

void Manager::del_own_rec()
{

}

bool Manager::login_op()
{
    system("CLS");
    system("color 21");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To  Manager Login\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::string s_id,s_pwd;
    std::cout<<"\n\t\t\t\t\t\tEnter your ID : ";
    std::cin>>s_id;
    std::cout<<"\n\t\t\t\t\t\tEnter your password : ";
    std::cin>>s_pwd;
    if(s_id=="admin"&&s_pwd=="admin")
        return true;
    return false;
}

void Manager::show_this_month_profit(int e)
{
    system("CLS");
    system("color F0");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To Profit Information\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::ifstream infile("count_gst.txt");
    if(!infile)
    {
        std::cout<<"\n\t\t\t\t\t\tthere is no data to calculate"<<std::endl;
        return ;
    }
    int c=0;
    infile>>c;
    infile.close();
    int total_sum=c*5000;
    std::cout<<"\n\t\t\t\t\t\tEnter a approximate  month's expanse : ";
    int bulk=0;
    std::cin>>bulk;
    std::cout<<"\n\t\t\t\t\t\tThe Profit is:";
    std::cout<<total_sum-(e*2000)-bulk<<std::endl;
    Sleep(2000);
}
