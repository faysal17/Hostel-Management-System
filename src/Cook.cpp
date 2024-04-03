#include "Cook.h"
#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<stdlib.h>

#include<windows.h>
#include<conio.h>
Cook::Cook()
{
    //ctor
}

const void Cook::show_info()
{
    system("color 20");
    std::cout<< "\t\t\t\*******************************************************************************\n ";
    std::cout<< "\t\t\t\t\t\tId : " <<Getid()<<std::endl;
    std::cout<< "\t\t\t\t\t\tPassword : "<<Getpwd()<<std::endl;
    std::cout<< "\t\t\t\t\t\tName : "<<Getname()<<std::endl;
    std::cout<< "\t\t\t\t\t\tDesignation : "<<Getdesg()<<std::endl;
    std::cout<< "\t\t\t\*******************************************************************************\n ";
}

void Cook::disk_out()
{
    Employee* obj[100];
    int k=0;
    bool flag=true;

    std::ifstream infile("Cook.txt");
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tthere is no file"<<"\n";
        flag=false;
    }
    if(flag==true)
    {
        obj[k]=new Cook;
        std::string s_id,s_pwd,s_name,s_desg;

        infile>>s_id>>s_pwd>>s_name>>s_desg;
        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);

        while(!infile.eof())
        {
            k++;
            obj[k]=new Cook;
            infile>>s_id>>s_pwd>>s_name>>s_desg;
            obj[k]->Setid(s_id);
            obj[k]->Setpwd(s_pwd);
            obj[k]->Setname(s_name);
            obj[k]->Setdesg(s_desg);

        }
        infile.close();
    }

    std::ofstream outfile("Cook.txt");
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

    Employee* obj1=new Cook;


    system("CLS");
    system("color 15");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To Appoint Cook\n";
    std::cout<<"\t\t\t\t====================================================\n";

    std::string s_id,s_pwd,s_name,s_desg;
    std::cout<<"\t\t\t\t\t\tEnter the name : ";
    std::cin>>s_name;
    s_id=obj1->id_gnrt(s_name);
    s_pwd=obj1->pwd_gnrt();
    std::cout<<"\n\t\t\t\t\t\tNew Cook's ID is : "<<s_id;
    std::cout<<"\n\t\t\t\t\t\tNew Cook's Password is : "<<s_pwd;
    std::cout<<"\n\t\t\t\t\t\tEnter The Designation : ";
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
void Cook::disk_in()
{
    Employee* obj[100];
    int k=0;
    std::ifstream infile("Cook.TXT");
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tthere are no file for cook"<<std::endl;
        return ;
    }
    obj[k]=new Cook;
    std::string s_id,s_name,s_pwd,s_desg;
    infile>>s_id>>s_pwd>>s_name>>s_desg;
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setname(s_name);
    obj[k]->Setdesg(s_desg);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Cook;
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
std::string Cook::id_gnrt(std::string s_name)
{
    std::string s_res="";
    s_res+=("101");
    s_res+=s_name;
    int n=3;//Receptionist::disk_count();
    s_res+=(std::to_string(n+1));
    return s_res;
}

std::string Cook::pwd_gnrt()
{
    std::srand(time(NULL));
    std::string p="";
    int co[4]= {3,3,3,3};
    int k=0;
    while(co[0]--)
    {
        p+=97+(std::rand()%26);
        k++;
    }
    while(co[1]--)
    {
        p+=48+(std::rand()%10);
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

void Cook::del_own_rec()
{
      system("CLS");
    system("color E0");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To Fire COOk\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::string d_id,d_name;
    std::cout<<"\n\t\t\t\t\t\tEnter the id you want to fire : ";
    std::cin>>d_id;
    std::cout<<"\n\t\t\t\t\t\tEnter the name you want to fire : ";
    std::cin>>d_name;
    Employee* obj[100];
    int k=0;
    std::ifstream infile("Cook.TXT");
    bool flag1=true;
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tThere is no cook to delete"<<std::endl;
        flag1=false;
    }
    if(flag1==true)
    {
        obj[k]=new Cook;

        std::string s_id,s_pwd,s_name,s_desg;

        infile>>s_id>>s_pwd>>s_name>>s_desg;

        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);

        while(!infile.eof())
        {
            k++;
            obj[k]=new Cook;
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
            std::ofstream outfile("Cook.TXT");
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

bool Cook::login_op()
{
   system("CLS");
    system("color B1");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To  Cook Login\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::ifstream infile("Cook.txt");
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tSorry, there is no cook right now"<<std::endl;
        return false;
    }
    std::string L_id,L_pwd;

    std::cout<<"\t\t\t\t\t\tGive your ID : ";
    std::cin>>L_id;
    std::cout<<"\t\t\t\t\t\tGive your Password : ";
    std::cin>>L_pwd;

    std::string s_id,s_pwd,s_name,s_desg;
    int k=0;
    Employee* obj[100];
    obj[k]=new Cook;
    infile>>s_id>>s_pwd>>s_name>>s_desg;
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setname(s_name);
    obj[k]->Setdesg(s_desg);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Cook;
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

void Cook::main_func_cok()
{ system("CLS");
    system("color B0");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome Cook \n";
    std::cout<<"\t\t\t\t====================================================\n";
    Sleep(500);
    int a=0,b=0,c=0;
    std::ifstream infile("Cook_lst.txt");
    bool flag=true;
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tThere is no food."<<std::endl;
        flag=false;
    }
    if(flag==true)
    {
        infile>>a>>b>>c;
    }
    infile.close();
    while(1)
    {


    system("CLS");
        system("color F2");
        std::cout<<"\n\n\n\n\n\n";
        std::cout<<"\n\t\t\t\t\t\tThe Cook Menu\n"<<std::endl;
        std::cout<<"\t\t\t\t->Press 1 To Add Set A"<<std::endl;
        std::cout<<"\t\t\t\t->Press 2 To Add Set B"<<std::endl;
        std::cout<<"\t\t\t\t->Press 3 To Add Set C"<<std::endl;
        std::cout<<"\t\t\t\t->Press 4 To Exit Cook Menu"<<std::endl;


        int x;
        std::cout<<"\n\t\t\t\tEPress The Button  :";
        std::cin>>x;

    if(x==1)
    {
       std::cout<<"\t\t\t\tSet A Added Successfully"<<std::endl;

        a++;}
    else if(x==2)
    {
        std::cout<<"\t\t\t\tSet B Added Successfully"<<std::endl;


        b++;}
    else if(x==3)
    {
        std::cout<<"\t\t\t\tSet C Added Successfully"<<std::endl;


        c++;}
       else if(x==4)
        {
            system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tClosing Cook Menu"<<std::endl;
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
        Sleep(500);
    std::ofstream outfile("Cook_lst.txt");
    outfile<<a
           <<' '
           <<b
           <<' '
           <<c
           <<' ';
    outfile.close();
}
}
