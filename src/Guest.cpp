#include "Guest.h"
#include "Employee.h"
#include "Receptionist.h"
#include "Menu.h"
#include<string>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
Guest::Guest()
{
    //ctor
    name="";
    id="";
    pwd="";
    room_no="";
}

std::string Guest::id_gnrt(std::string g_name)
{
    std::string s_res="";
    s_res+=("1111");
    s_res+=g_name;
    int n=3;//Receptionist::disk_count();
    s_res+=(std::to_string(n+1));
    return s_res;
}

std::string Guest::pwd_gnrt()
{
    std::srand(time(NULL));
    std::string p="";
    int co[4]= {3,3,3,3};
    int k=0;
    while(co[0]--)
    {
        p+=48+(std::rand()%10);
        k++;
    }
    while(co[1]--)
    {
        p+=65+(std::rand()%26);
        k++;
    }
    while(co[2]--)
    {
        p+=33+(std::rand()%15);
        k++;
    }
    while(co[3]--)
    {
        p+=97+(std::rand()%26);
        k++;
    }
    //p[k]='\0';
    return p;
}

bool Guest::login_op()
{
    system("CLS");
    system("color 81");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";//ai block ta add korbi
    std::cout<<"\t\t\t\t\t\tWelcome To  Guest Login\n";
    std::cout<<"\t\t\t\t====================================================\n";////////////////////////////////////////
    std::string q_id,q_pwd;

    std::cout<<"\n\t\t\t\t\t\tEnter your ID : ";/////////////////////////////////////////////////
    std::cin>>q_id;
    std::cout<<"\n\t\t\t\t\t\tEnter your Password : ";/////////////////////////////////////////////
    std::cin>>q_pwd;
    std::ifstream infile("guest_list.txt");
    if(!infile)
    {
        std::cout<<"\n\t\t\t\t\t\tThere are no guest to log in"<<std::endl;
        return false;
    }
    Guest* obj[100];
    int k=0;
    std::string s_name,s_id,s_pwd,s_room_no,s_date;
    infile>>s_name>>s_id>>s_pwd>>s_room_no>>s_date;
    obj[k]=new Guest;
    obj[k]->Setname(s_name);
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setroom_no(s_room_no);
    obj[k]->Setdate(s_date);
    while(!infile.eof())
    {
        k++;
        infile>>s_name>>s_id>>s_pwd>>s_room_no>>s_date;
        obj[k]=new Guest;
        obj[k]->Setname(s_name);
        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setroom_no(s_room_no);
        obj[k]->Setdate(s_date);
    }
    infile.close();
    bool flag=false;
    for(int i=0; i<k; i++)
    {
        if(q_id==obj[i]->Getid()&&q_pwd==obj[i]->Getpwd())
        {
            flag=true;
            break;
        }
    }
    for(int i=0; i<k; i++)delete obj[i];
    return flag;
}

void Guest::main_func_gst()
{
    while(1)
    {
        system("CLS");
        system("color 0B");
        std::cout<<"\n\n\n\n\n\n";
        std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";//ai pura block ta add korbi
        std::cout<<"\t\t\t\t\t\tWelcome To Guest Menu\n";
        std::cout<<"\t\t\t\t====================================================\n";
        std::cout<<"\n\t\t\t\t\t\tPress The Appropiate Button"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 1 To Call for porter"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 2 To Call for waiter"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 3 To Call for cleaner"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 4 To Exit Guest Menu"<<std::endl;
        int x;
        std::cout<<"\n\t\t\t\tPress The Button ";
        std::cin>>x;
        if(x==1)
            prt_ord_lst();
        else if(x==2)
            wtr_ord_lst();
        else if(x==3)
            cln_ord_lst();
        else if(x==4)

            {
               system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tClosing The  Guest Menu"<<std::endl;
            Sleep(1000);
            break;
            }
            else{system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tInvalid Input .Press The correct Button . "<<std::endl;
            Sleep(1000);}
    }
}

void Guest::prt_ord_lst()
{
    std::string s_desg,s_room_no;
    bool flag=true;
    std::ifstream infile("Porter_ord_lst.txt");
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tThere is no order yet"<<std::endl;
        flag=false;
    }
    Employee* obj[100];
    Guest* obj1[100];
    int k=0;
    if(flag==true)
    {
        obj[k]=new Receptionist;
        obj1[k]=new Guest;
        infile>>s_desg>>s_room_no;
        obj[k]->Setdesg(s_desg);
        obj1[k]->Setroom_no(s_room_no);
        while(!infile.eof())
        {
            k++;
            obj[k]=new Receptionist;
            obj1[k]=new Guest;
            infile>>s_desg>>s_room_no;
            obj[k]->Setdesg(s_desg);
            obj1[k]->Setroom_no(s_room_no);
        }
        infile.close();
    }

    std::ofstream outfile("Porter_ord_lst.txt");

    for(int i=0; i<k; i++)
    {
        outfile<<obj[i]->Getdesg()
               <<' '
               <<obj1[i]->Getroom_no()
               <<' ';
    }
    for(int i=0; i<k; i++)delete obj[i];
    for(int i=0; i<k; i++)delete obj1[i];

    system("CLS");
    system("color 61");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";//ai pura block ta add korbi
    std::cout<<"\t\t\t\t\t\tWelcome To Porter Call\n";
    std::cout<<"\t\t\t\t====================================================\n";

    std::cout<<"\n\t\t\t\tEnter your designation : ";
    std::cin>>s_desg;
    std::cout<<"\n\t\t\t\tEnter Your Room no : ";
    std::cin>>s_room_no;


    outfile<<s_desg
           <<' '
           <<s_room_no
           <<' ';

    outfile.close();
}

void Guest::wtr_ord_lst()
{
    Menu* obj[100];
    std::string s_set,s_room_no;
    int k=0;
    std::ifstream infile("wtr_gst_lst.txt");
    bool flag=true;
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tThere is no order available"<<std::endl;
        flag=false;
    }
    if(flag==true)
    {
        obj[k]=new Menu;
        infile>>s_set>>s_room_no;
        obj[k]->Setset(s_set);
        obj[k]->Setroom_no(s_room_no);
        while(!infile.eof())
        {
            k++;
            obj[k]=new Menu;
            infile>>s_set>>s_room_no;
            obj[k]->Setset(s_set);
            obj[k]->Setroom_no(s_room_no);
        }
        infile.close();
    }
    std::ofstream outfile("wtr_gst_ord.txt");
    for(int i=0; i<k; i++)
    {
        outfile<<obj[i]->Getset()
               <<' '
               <<obj[i]->Getroom_no()
               <<' ';
    }
    system("CLS");
    system("color F0");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";//ai pura block ta add korbi
    std::cout<<"\t\t\t\t\t\tWelcome To Waiter Call\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::cout<<"\n\t\t\t\tWhich set you want to choose ?"<<std::endl;
    std::cout<<"\t\t\t\t\t\tType seta for setA\n";
    std::cout<<"\t\t\t\t\t\tType setb for setB\n";
    std::cout<<"\t\t\t\t\t\tType setc for setC\n";

    std::cout<<"\t\t\t\t\t\tType to ordr : ";std::cin>>s_set;
    std::cout<<"\n\t\t\t\tEnter your room_no : ";
    std::cin>>s_room_no;
    outfile<<s_set
           <<' '
           <<s_room_no
           <<' ';
    outfile.close();
    for(int i=0; i<k; i++)delete obj[i];

}

void Guest::cln_ord_lst()
{
    std::string s_room_no;
    Guest* obj[100];
    int k=0;
    std::ifstream infile("cln_gst.ord.txt");
    bool flag=true;
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tThere is no order yet"<<std::endl;
        flag=false;
    }
    if(flag==true)
    {
        infile>>s_room_no;
        obj[k]=new Guest;
        obj[k]->Setroom_no(s_room_no);
        while(!infile.eof())
        {
            k++;
            infile>>s_room_no;
            obj[k]=new Guest;
            obj[k]->Setroom_no(s_room_no);
        }
        infile.close();
    }
    std::ofstream outfile("cln_gst_ord.txt");
    for(int i=0; i<k; i++)
    {
        outfile<<obj[i]->Getroom_no()
               <<' ';
    }
    system("CLS");
    system("color A0");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To Cleaner call\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::cout<<"\n\t\t\t\tEnter YOur Room no : ";
    std::cin>>s_room_no;
    outfile<<s_room_no
           <<' ';
    outfile.close();
    for(int i=0; i<k; i++)delete obj[i];
}
