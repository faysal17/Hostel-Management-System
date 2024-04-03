#include "Porter.h"
#include "Guest.h"
#include "Receptionist.h"
#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<stdlib.h>

#include<windows.h>
Porter::Porter()
{
    //ctor
}

const void Porter::show_info()
{
    system("color B1");
    std::cout<< "\t\t\t\*******************************************************************************\n ";
    std::cout<< "\t\t\t\t\t\tId : " <<Getid()<<std::endl;
    std::cout<< "\t\t\t\t\t\tPassword : "<<Getpwd()<<std::endl;
    std::cout<< "\t\t\t\t\t\tName : "<<Getname()<<std::endl;
    std::cout<< "\t\t\t\t\t\tDesignation : "<<Getdesg()<<std::endl;
    std::cout<< "\t\t\t\*******************************************************************************\n ";
}

void Porter::disk_out()
{
    Employee* obj[100];
    int k=0;
    bool flag=true;

    std::ifstream infile("Porter.txt");
    if(!infile)
    {
        std::cout<<"\n\t\t\t\tthere is no file"<<"\n";
        flag=false;
    }
    if(flag==true)
    {
        obj[k]=new Porter;
        std::string s_id,s_pwd,s_name,s_desg;

        infile>>s_id>>s_pwd>>s_name>>s_desg;
        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);

        while(!infile.eof())
        {
            k++;
            obj[k]=new Porter;
            infile>>s_id>>s_pwd>>s_name>>s_desg;
            obj[k]->Setid(s_id);
            obj[k]->Setpwd(s_pwd);
            obj[k]->Setname(s_name);
            obj[k]->Setdesg(s_desg);

        }
        infile.close();
    }

    std::ofstream outfile("Porter.txt");
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
    for(int i=0; i<k; i++)delete obj[i];

    Employee* obj1=new Porter;

    system("CLS");
    system("color 15");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To AppointPorter\n";
    std::cout<<"\t\t\t\t====================================================\n";

    std::string s_id,s_pwd,s_name,s_desg;
    std::cout<<"\t\t\t\t\t\tEnter The name : ";
    std::cin>>s_name;
    s_id=obj1->id_gnrt(s_name);
    s_pwd=obj1->pwd_gnrt();
    std::cout<<"\n\t\t\t\t\t\tNew Porter ID is : "<<s_id<<std::endl;
    std::cout<<"\t\t\t\t\t\tNew porter Password is : "<<s_pwd<<std::endl;
    std::cout<<"\t\t\t\t\t\tEnter the  Designation : ";
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

void Porter::disk_in()
{
    Employee* obj[100];
    int k=0;
    std::ifstream infile("Porter.TXT");
    if(!infile)
    {
        std::cout<<"there are no file for porter"<<std::endl;
        return ;
    }
    obj[k]=new Porter;
    std::string s_id,s_name,s_pwd,s_desg;
    infile>>s_id>>s_pwd>>s_name>>s_desg;
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setname(s_name);
    obj[k]->Setdesg(s_desg);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Porter;
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
    for(int i=0; i<k; i++)delete obj[i];
}

std::string Porter::id_gnrt(std::string s_name)
{
    std::string s_res="";
    s_res+=("111");
    s_res+=s_name;
    int n=3;//Receptionist::disk_count();
    s_res+=(std::to_string(n+1));
    return s_res;
}

std::string Porter::pwd_gnrt()
{
    std::srand(time(NULL));
    std::string p="";
    int co[4]= {3,3,3,3};
    int k=0;
    while(co[0]--)
    {
        p+=65+(std::rand()%26);
        k++;
    }
    while(co[1]--)
    {
        p+=33+(std::rand()%15);
        k++;
    }
    while(co[2]--)
    {
        p+=48+(std::rand()%10);
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

void Porter::del_own_rec()
{
    system("CLS");
    system("color E0");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To Fire Porter\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::string d_id,d_name;
    std::cout<<"\n\t\t\t\t\t\tEnter the id you want to delete : ";
    std::cin>>d_id;
    std::cout<<"\n\t\t\t\t\t\tEnter the name you want to delete : ";
    std::cin>>d_name;
    Employee* obj[100];
    int k=0;
    std::ifstream infile("Porter.TXT");
    bool flag1=true;
    if(!infile)
    {
        std::cout<<"\t\t\t\t\t\tThere is no Porter to delete"<<std::endl;
        flag1=false;
    }
    if(flag1==true)
    {
        obj[k]=new Porter;

        std::string s_id,s_pwd,s_name,s_desg;

        infile>>s_id>>s_pwd>>s_name>>s_desg;

        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);

        while(!infile.eof())
        {
            k++;
            obj[k]=new Porter;
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
                std::cout<<"\t\t\t\t\t\tRecord is found"<<std::endl;
                idx=i;
                break;
            }
        }
        if(flag==true)
        {
            std::cout<<"\t\t\t\t\t\tRecord is deleting"<<std::endl;
            std::ofstream outfile("Porter.TXT");
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
    for(int i=0; i<k; i++)delete obj[i];
}

bool Porter::login_op()
{
    system("CLS");
    system("color F1");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
      std::cout<<"\t\t\t\t\t\tWelcome To  Porter Login\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::ifstream infile("Porter.txt");
    if(!infile)
    {
        std::cout<<"\t\t\t\t\t\tSorry, there is no receptionist right now"<<std::endl;
        return false;
    }
    std::string L_id,L_pwd;

    std::cout<<"\t\t\t\t\t\tEnter your ID : ";
    std::cin>>L_id;
    std::cout<<"\t\t\t\t\t\tEnter your Password : ";
    std::cin>>L_pwd;

    std::string s_id,s_pwd,s_name,s_desg;
    int k=0;
    Employee* obj[100];
    obj[k]=new Porter;
    infile>>s_id>>s_pwd>>s_name>>s_desg;
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setname(s_name);
    obj[k]->Setdesg(s_desg);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Porter;
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
    for(int i=0; i<k; i++)delete obj[i];

    return flag;
}

void Porter::main_func_prt()
{
    system("CLS");
    system("color B0");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome Porter \n";
    std::cout<<"\t\t\t\t====================================================\n";
    Sleep(500);
    while(1)
    {
        system("CLS");
        system("color B0");
        std::cout<<"\n\n\n\n\n\n";
        std::cout<<"\n\t\t\t\t\t\tThe Porter Menu\n"<<std::endl;
        std::cout<<"\t\t\t\t->Press 1 To Check Order List"<<std::endl;
        std::cout<<"\t\t\t\t->Press 2 To Exit Menu"<<std::endl;
        int x;
        std::cout<<"\n\t\t\t\tPress The button :";
        std::cin>>x;
        if(x==1)
        {
            ck_prt_ord_lst();
        }
        else if(x==2)
        {
            system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tClosing Porter Menu"<<std::endl;
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

void Porter::ck_prt_ord_lst()
{
    system("CLS");
    system("color 07");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";/////////////////////////ai pura block ta add korbi
    std::cout<<"\t\t\t\t\t\tWelcome To Check Order List \n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::ifstream infile("Porter_ord_lst.txt");
    if(!infile)
    {
        std::cout<<"\t\t\t\t\t\tThere is no file to work on"<<std::endl;
        return ;
    }
    std::string s_desg,s_room_no;
    infile>>s_desg>>s_room_no;
    std::cout<<"\t\t\t\t\t\tDo you want to work on room_no "<<s_room_no<<" requested by "<<s_desg<<std::endl;
    std::cout<<"\t\t\t\t->Press 1 for YES and 2 for NO";
    int x;
    std::cout<<"\n\t\t\t\tEnter Your Choice :";
    std::cin>>x;
    if(x==1)
    {
        del_prt_ord_lst(s_room_no);
        std::cout<<"\t\t\t\t\t\trecord deleted"<<std::endl;
        return ;
    }
    while(!infile.eof())
    {
        infile>>s_desg>>s_room_no;
        std::cout<<"\t\t\t\t\t\tDo you want to work on room_no "<<s_room_no<<" Requested by "<<s_desg<<std::endl;
        std::cout<<"\t\t\t\t->Press 1 for Yes and 2 for No";
        int x;
        std::cout<<"\n\t\t\t\tEnter Your Choice :";
        std::cin>>x;
        if(x==1)
        {
            del_prt_ord_lst(s_room_no);
            std::cout<<"\t\t\t\t\t\trecord deleted"<<std::endl;
            break;
        }
    }
    infile.close();
}

void Porter::del_prt_ord_lst(std::string q_room_no)
{
    Employee* obj[100];
    Guest* obj1[100];
    int k=0;
    std::string s_desg,s_room_no;
    std::ifstream infile("Porter_ord_lst.txt");
    infile>>s_desg>>s_room_no;
    obj[k]=new Receptionist;
    obj1[k]=new Guest;
    obj[k]->Setdesg(s_desg);
    obj1[k]->Setroom_no(s_room_no);
    while(!infile.eof())
    {
        k++;
        infile>>s_desg>>s_room_no;
        obj[k]=new Receptionist;
        obj1[k]=new Guest;
        obj[k]->Setdesg(s_desg);
        obj1[k]->Setroom_no(s_room_no);
    }
    infile.close();
    std::ofstream outfile("Porter_ord_lst.txt");
    for(int i=0; i<k; i++)
    {
        if(obj1[i]->Getroom_no()!=q_room_no)
        {
            outfile<<obj[i]->Getdesg()
                   <<' '
                   <<obj1[i]->Getroom_no()
                   <<' ';
        }
    }
    outfile.close();
    for(int i=0; i<k; i++)delete obj[i];
    delete[] obj1;
}

