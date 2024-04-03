#include "Guard.h"
#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include "Employee.h"
#include<windows.h>
#include<conio.h>

Guard::Guard()
{
    //ctor
}

const void Guard::show_info()
{  system("CLS");
    system("color 0D");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To  Guard Info\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::cout<<"\n\t\t\t\tGuard Id"<<Getid()<<std::endl;
    std::cout<<"\n\t\t\t\tGuard Password"<<Getpwd()<<std::endl;
    std::cout<<"\n\t\t\t\tGuard Name"<<Getname()<<std::endl;
    std::cout<<"\n\t\t\t\tGuard Designation"<<Getdesg()<<std::endl;
    std::cout<<"\n\t\t\t\tPress any key to Exit ";
    getch();
}

void Guard::disk_out()
{
    Employee* obj[100];
    int k=0;
    bool flag=true;

    std::ifstream infile("Guard.txt");
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tthere is no file"<<"\n";
        flag=false;
    }
    if(flag==true)
    {
        obj[k]=new Guard;
        std::string s_id,s_pwd,s_name,s_desg;

        infile>>s_id>>s_pwd>>s_name>>s_desg;
        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);

        while(!infile.eof())
        {
            k++;
            obj[k]=new Guard;
            infile>>s_id>>s_pwd>>s_name>>s_desg;
            obj[k]->Setid(s_id);
            obj[k]->Setpwd(s_pwd);
            obj[k]->Setname(s_name);
            obj[k]->Setdesg(s_desg);

        }
        infile.close();
    }

    std::ofstream outfile("Guard.txt");
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

    Employee* obj1=new Guard;

   system("CLS");
    system("color 15");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";//ai pura block ta add korbi
    std::cout<<"\t\t\t\t\t\tWelcome To ADD Guard\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::string s_id,s_pwd,s_name,s_desg;
    std::cout<<"\n\t\t\t\tGive a name : ";
    std::cin>>s_name;
    s_id=obj1->id_gnrt(s_name);
    s_pwd=obj1->pwd_gnrt();
    std::cout<<"\n\t\t\t\tYour ID is : "<<s_id<<std::endl;
    std::cout<<"\t\t\t\tYour Password is : "<<s_pwd<<std::endl;
    std::cout<<"\n\t\t\t\tGive Designation : ";std::cin>>s_desg;
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
void Guard::disk_in()
{
    Employee* obj[100];
    int k=0;
    std::ifstream infile("Guard.TXT");
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tthere are no file for Guard"<<std::endl;
        return ;
    }
    obj[k]=new Guard;
    std::string s_id,s_name,s_pwd,s_desg;
    infile>>s_id>>s_pwd>>s_name>>s_desg;
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setname(s_name);
    obj[k]->Setdesg(s_desg);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Guard;
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

std::string Guard::id_gnrt(std::string s_name)
{
    std::string s_res="";
    s_res+=("011");
    s_res+=s_name;
    int n=3;//Receptionist::disk_count();
    s_res+=(std::to_string(n+1));
    return s_res;
}

std::string Guard::pwd_gnrt()
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
        p+=65+(std::rand()%26);
        k++;
    }
    while(co[3]--)
    {
        p+=33+(std::rand()%15);
        k++;
    }
    //p[k]='\0';
    return p;
}

void Guard::del_own_rec()
{
     system("CLS");
    system("color E0");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";//ai pura block ta add korbi
    std::cout<<"\t\t\t\t\t\tWelcome To Delete Guard\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::string d_id,d_name;
    std::cout<<"\n\t\t\t\tGive the id you want to delete : ";
    std::cin>>d_id;
    std::cout<<"\n\t\t\t\tGive the name you want to delete : ";
    std::cin>>d_name;
    Employee* obj[100];
    int k=0;
    std::ifstream infile("Guard.TXT");
    bool flag1=true;
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tThere is no Guard to delete"<<std::endl;
        flag1=false;
    }
    if(flag1==true)
    {
        obj[k]=new Guard;

        std::string s_id,s_pwd,s_name,s_desg;

        infile>>s_id>>s_pwd>>s_name>>s_desg;

        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);

        while(!infile.eof())
        {
            k++;
            obj[k]=new Guard;
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
            std::ofstream outfile("Guard.TXT");
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

bool Guard::login_op()
{  system("CLS");
    system("color 0D");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";//ai block ta add korbi
    std::cout<<"\t\t\t\t\t\tWelcome To  Guard Login\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::ifstream infile("Guard.txt");
    if(!infile)
    {
        std::cout<<"S\n\t\t\t\tSorry, there is no guard right now"<<std::endl;
        return false;
    }
    std::string L_id,L_pwd;


    std::cout<<"\n\t\t\t\tGive your ID : ";
    std::cin>>L_id;
    std::cout<<"\n\t\t\t\tGive your Password : ";
    std::cin>>L_pwd;

    std::string s_id,s_pwd,s_name,s_desg;
    int k=0;
    Employee* obj[100];
    obj[k]=new Guard;
    infile>>s_id>>s_pwd>>s_name>>s_desg;
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setname(s_name);
    obj[k]->Setdesg(s_desg);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Guard;
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

