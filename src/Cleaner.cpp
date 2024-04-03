#include "Cleaner.h"
#include "Guest.h"
#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

Cleaner::Cleaner()
{
    //ctor
}

const void Cleaner::show_info()
{
   system("color B1");
    std::cout<< "\t\t\t\*******************************************************************************\n ";
    std::cout<< "\t\t\t\t\t\tId : " <<Getid()<<std::endl;
    std::cout<< "\t\t\t\t\t\tPassword : "<<Getpwd()<<std::endl;
    std::cout<< "\t\t\t\t\t\tName : "<<Getname()<<std::endl;
    std::cout<< "\t\t\t\t\t\tDesignation : "<<Getdesg()<<std::endl;
    std::cout<< "\t\t\t\*******************************************************************************\n ";
}

void Cleaner::disk_out()
{
    Employee* obj[100];
    int k=0;
    bool flag=true;

    std::ifstream infile("Cleaner.txt");
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tthere is no file"<<"\n";
        flag=false;
    }
    if(flag==true)
    {
        obj[k]=new Cleaner;
        std::string s_id,s_pwd,s_name,s_desg;

        infile>>s_id>>s_pwd>>s_name>>s_desg;
        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);

        while(!infile.eof())
        {
            k++;
            obj[k]=new Cleaner;
            infile>>s_id>>s_pwd>>s_name>>s_desg;
            obj[k]->Setid(s_id);
            obj[k]->Setpwd(s_pwd);
            obj[k]->Setname(s_name);
            obj[k]->Setdesg(s_desg);

        }
        infile.close();
    }

    std::ofstream outfile("Cleaner.txt");
    for(int i=0; i<k; i++)
    {
        outfile << obj[i]->Getid() //insert (write) data
                << ' ' //needs space between numbers
                << obj[i]->Getpwd()
                <<' '
                <<obj[i]->Getname()
                <<' '
                <<obj[i]->Getdesg()
                <<' ';
        std::cout << "\n\t\t\t\tFile written\n";
    }
    for(int i=0;i<k;i++)delete obj[i];

    Employee* obj1=new Cleaner;
   system("CLS");
    system("color F8");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To Appoint Cleaner\n";
    std::cout<<"\t\t\t\t====================================================\n";

    std::string s_id,s_pwd,s_name,s_desg;
    std::cout<<"\t\t\t\tEnter The name : ";
    std::cin>>s_name;
    s_id=obj1->id_gnrt(s_name);
    s_pwd=obj1->pwd_gnrt();
    std::cout<<"\n\t\t\t\tNew Cleaner's ID is : "<<s_id<<std::endl;
    std::cout<<"\t\t\t\tNew Cleaner's Password is : "<<s_pwd<<std::endl;
    std::cout<<"\t\t\t\tEnter the Designation : ";
    std::cin>>s_desg;
            obj1->Setid(s_id);
            obj1->Setpwd(s_pwd);
            obj1->Setname(s_name);
            obj1->Setdesg(s_desg);
            //create ofstream object
            outfile << obj1->Getid() //insert (write) data
                    <<' ' //needs space between numbers
                    << obj1->Getpwd()
                    <<' '
                    <<obj1->Getname()
                    <<' '
                    <<obj1->Getdesg()
                    <<' ';
            std::cout << "\n\t\t\t\tFile written\n";

    delete obj1;
    outfile.close();
}

void Cleaner::disk_in()
{
    Employee* obj[100];
    int k=0;
    std::ifstream infile("Cleaner.TXT");
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tthere are no file for cleaner"<<std::endl;
        return ;
    }
    obj[k]=new Cleaner;
    std::string s_id,s_name,s_pwd,s_desg;
    infile>>s_id>>s_pwd>>s_name>>s_desg;
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setname(s_name);
    obj[k]->Setdesg(s_desg);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Cleaner;
        infile>>s_id>>s_pwd>>s_name>>s_desg;
        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);
    }
    for(int i=0; i<k; i++)
    {
        obj[i]->show_info();
    }
    infile.close();
    for(int i=0;i<k;i++)delete obj[i];
}

std::string Cleaner::id_gnrt(std::string s_name)
{
    std::string s_res="";
    s_res+=("100");
    s_res+=s_name;
    int n=3;//Receptionist::disk_count();
    s_res+=(std::to_string(n+1));
    return s_res;
}

std::string Cleaner::pwd_gnrt()
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
        p+=97+(std::rand()%26);
        k++;
    }
    while(co[2]--)
    {
        p+=33+(std::rand()%15);
        k++;
    }
    while(co[3]--)
    {
        p+=65+(std::rand()%26);
        k++;
    }
    //p[k]='\0';
    return p;
}

void Cleaner::del_own_rec()
{
   system("CLS");
    system("color E0");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";//ai pura block ta add korbi
    std::cout<<"\t\t\t\t\t\tWelcome To Fire Cleaner\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::string d_id,d_name;
    std::cout<<"\n\t\t\t\tGive the id you want to Fire : ";
    std::cin>>d_id;
    std::cout<<"\n\t\t\t\tGive the name you want to Fire : ";
    std::cin>>d_name;
    Employee* obj[100];
    int k=0;
    std::ifstream infile("Cleaner.TXT");
    bool flag1=true;
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tThere is no cleaner to delete"<<std::endl;
        flag1=false;
    }
    if(flag1==true)
    {
        obj[k]=new Cleaner;

        std::string s_id,s_pwd,s_name,s_desg;

        infile>>s_id>>s_pwd>>s_name>>s_desg;

        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);

        while(!infile.eof())
        {
            k++;
            obj[k]=new Cleaner;
            infile>>s_id>>s_pwd>>s_name>>s_desg;
            obj[k]->Setid(s_id);
            obj[k]->Setpwd(s_pwd);
            obj[k]->Setname(s_name);
            obj[k]->Setdesg(s_desg);
        }
        infile.close();
        int idx;
        bool flag=false;
        for(int i=0; i<k; i++)
        {
            if((d_id==obj[i]->Getid())&&(d_name==obj[i]->Getname()))
            {
                flag=true;
                std::cout<<"\n\t\t\t\tRecord is found"<<std::endl;
                idx=i;
                break;
            }
        }
        if(flag==true)
        {
            std::cout<<"\n\t\t\t\tRecord is deleting"<<std::endl;
            std::ofstream outfile("Cleaner.TXT");
            for(int i=0; i<k; i++)
            {
                if(idx!=i)
                {
                    outfile<<obj[i]->Getid()
                           <<' '
                           <<obj[i]->Getpwd()
                           <<' '
                           <<obj[i]->Getname()
                           <<' '
                           <<obj[i]->Getdesg()
                           <<' ';
                }
            }
            outfile.close();
        }
    }
    for(int i=0;i<k;i++)delete obj[i];
}

bool Cleaner::login_op()
{   system("CLS");
    system("color 0D");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To  Cleaner Login\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::ifstream infile("Cleaner.txt");
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tSorry, there is no cleaner right now"<<std::endl;
        return false;
    }
    std::string L_id,L_pwd;

    std::cout<<"\n\t\t\t\tEnter your ID : ";
    std::cin>>L_id;
    std::cout<<"\n\t\t\t\tEnter your Password : ";
    std::cin>>L_pwd;

    std::string s_id,s_pwd,s_name,s_desg;
    int k=0;
    Employee* obj[100];
    obj[k]=new Cleaner;
    infile>>s_id>>s_pwd>>s_name>>s_desg;
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setname(s_name);
    obj[k]->Setdesg(s_desg);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Cleaner;
        infile>>s_id>>s_pwd>>s_name>>s_desg;
        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);
    }
    infile.close();

    bool flag=false;
    for(int i=0; i<k; i++)
    {
        if((obj[i]->Getid()==L_id)&&(obj[i]->Getpwd()==L_pwd))
        {
            flag=true;
            break;
        }
    }
    for(int i=0;i<k;i++)delete obj[i];

    return flag;
}

void Cleaner::main_func_cln()
{
    system("CLS");
    system("color B0");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t====================================================\n";
    Sleep(500);
    std::string s_room_no;
    std::ifstream infile("cln_gst_ord.txt");
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tThere is no order for cleaner"<<std::endl;
        Sleep(1000);
        return ;
    }
    infile>>s_room_no;
    std::cout<<"\n\t\t\t\tYour next room to clean is "<<s_room_no<<std::endl;
    del_gst_ord(s_room_no);
    std::cout<<"\n\t\t\t\tThe order to clean the room is deleted"<<std::endl;
    infile.close();
    std::cout<<"\n\t\t\t\tPress any Key To exit";getch();
    infile.close();
}

void Cleaner::del_gst_ord(std::string q_room_no)
{
    Guest* obj[100];
    std::string s_room_no;
    int k=0;
    std::ifstream infile("cln_gst_ord.txt");
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
    std::ofstream outfile("cln_gst_ord.txt");
    for(int i=0;i<k;i++)
    {
        if(obj[i]->Getroom_no()!=q_room_no)
        {
            outfile<<obj[i]->Getroom_no()
                   <<' ';
        }
    }
    outfile.close();
    for(int i=0;i<k;i++)delete obj[i];
}
