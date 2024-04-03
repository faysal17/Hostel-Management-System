#include "Receptionist.h"
#include "Employee.h"
#include "Guest.h"
#include "Room.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<stdlib.h>////////////////////////////////////////////////////////////////////ata
#include<windows.h>
#include<conio.h>

Receptionist::Receptionist()
{
    //ctor
    r_obj=new Room;
}

void Receptionist::disk_out()
{
    Employee* obj[100];
    int k=0;
    bool flag=true;

    std::ifstream infile("RECEPTIONIST.txt");
    if(!infile)
    {
        std::cout<<"\t\t\t\t\t\tthere is no file"<<"\n";
        flag=false;
    }
    if(flag==true)
    {
        obj[k]=new Receptionist;
        std::string s_id,s_pwd,s_name,s_desg;

        infile>>s_id>>s_pwd>>s_name>>s_desg;
        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);

        while(!infile.eof())
        {
            k++;
            obj[k]=new Receptionist;
            infile>>s_id>>s_pwd>>s_name>>s_desg;
            obj[k]->Setid(s_id);
            obj[k]->Setpwd(s_pwd);
            obj[k]->Setname(s_name);
            obj[k]->Setdesg(s_desg);

        }
        infile.close();
    }

    std::ofstream outfile("Receptionist.txt");
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
        std::cout << "\t\t\t\t\t\tFile written\n";
    }
    for(int i=0; i<k; i++)delete obj[i];

    Employee* obj1=new Receptionist;




    system("CLS");
    system("color 21");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To Appoint Receptionist\n";
    std::cout<<"\t\t\t\t====================================================\n";

    std::string s_id,s_pwd,s_name,s_desg;
    std::cout<<"\t\t\t\t\t\tEnter The Name : ";
    std::cin>>s_name;
    s_id=obj1->id_gnrt(s_name);
    s_pwd=obj1->pwd_gnrt();
    std::cout<<"\n\t\t\t\t\t\tNew Receptionist  ID is : "<<s_id<<std::endl;
    std::cout<<"\t\t\t\t\t\tNew Receptionist Password is : "<<s_pwd<<std::endl;
    std::cout<<"\t\t\t\t\t\tEnter The Designation : ";
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
    std::cout << "\t\t\t\t\t\tFile written\n";


    delete obj1;
    outfile.close();
    Sleep(250);
    system("CLS");

}


void Receptionist::disk_in()
{
    Employee* obj[100];
    int k=0;
    std::ifstream infile("RECEPTIONIST.TXT");
    if(!infile)
    {
        std::cout<<"\t\t\t\t\t\tthere are no file for receptionist"<<std::endl;
        return ;
    }
    obj[k]=new Receptionist;
    std::string s_id,s_name,s_pwd,s_desg;
    infile>>s_id>>s_pwd>>s_name>>s_desg;
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setname(s_name);
    obj[k]->Setdesg(s_desg);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Receptionist;
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

std::string Receptionist::id_gnrt(std::string s_name)
{
    std::string s_res="";
    s_res+=("010");
    s_res+=s_name;
    int n=3;//Receptionist::disk_count();
    s_res+=(std::to_string(n+1));
    return s_res;
}

std::string Receptionist::pwd_gnrt()
{
    //std::cout<<"pwd gnrt"<<std::endl;//debugger
    std::srand(time(NULL));
    std::string p="";
    int co[4]= {3,3,3,3};
    int k=0;
    while(co[0]--)
    {
        p+=33+(std::rand()%15);
        k++;
    }
    while(co[1]--)
    {
        p+=65+(std::rand()%26);
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

const void Receptionist::show_info()
{
    system("color 60");
    std::cout<< "\t\t\t\*******************************************************************************\n ";
    std::cout<< "\t\t\t\t\t\tId : " <<Getid()<<std::endl;
    std::cout<< "\t\t\t\t\t\tPassword : "<<Getpwd()<<std::endl;
    std::cout<< "\t\t\t\t\t\tName : "<<Getname()<<std::endl;
    std::cout<< "\t\t\t\t\t\tDesignation : "<<Getdesg()<<std::endl;
    std::cout<< "\t\t\t\*******************************************************************************\n ";
}

void Receptionist::del_own_rec()
{
    system("CLS");
    system("color 40");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To Fire Receptionist\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::string d_id,d_name;
    std::cout<<"\n\t\t\t\t\t\tEnter the id you want to delete : ";
    std::cin>>d_id;
    std::cout<<"\n\t\t\t\t\t\tEnter the name you want to delete : ";
    std::cin>>d_name;
    Employee* obj[100];
    int k=0;
    std::ifstream infile("RECEPTIONIST.TXT");
    bool flag1=true;
    if(!infile)
    {
        std::cout<<"\t\t\t\t\t\tThere is no Rceptionist to fire"<<std::endl;
        flag1=false;
    }
    if(flag1==true)
    {
        obj[k]=new Receptionist;

        std::string s_id,s_pwd,s_name,s_desg;

        infile>>s_id>>s_pwd>>s_name>>s_desg;

        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);

        while(!infile.eof())
        {
            k++;
            obj[k]=new Receptionist;
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
            std::ofstream outfile("RECEPTIONIST.TXT");
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
    Sleep(250);
    system("CLS");
}

bool Receptionist::login_op()
{
    system("CLS");
    system("color 0D");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To  Receptionist Login\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::ifstream infile("RECEPTIONIST.txt");
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
    obj[k]=new Receptionist;
    infile>>s_id>>s_pwd>>s_name>>s_desg;
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setname(s_name);
    obj[k]->Setdesg(s_desg);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Receptionist;
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
void Receptionist::main_func_recep()
{
    system("CLS");
    system("color B0");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome Receptionist \n";
    std::cout<<"\t\t\t\t====================================================\n";
    Sleep(500);
    while(1)
    {
        system("CLS");
        system("color B0");
        std::cout<<"\n\n\n\n\n\n";
        std::cout<<"\n\t\t\t\t\t\tPress The Appropiate Button\n"<<std::endl;
        std::cout<<"\t\t\t\t->Press 1 to for Check_in a guest"<<std::endl;
        std::cout<<"\t\t\t\t->Press 2 to Check_out a guest"<<std::endl;
        std::cout<<"\t\t\t\t->Press 3 to see information of guests"<<std::endl;
        std::cout<<"\t\t\t\t->Press 4 to order Porter"<<std::endl;
        std::cout<<"\t\t\t\t->Press 5 to Ensure Covid Safety"<<std::endl;
        std::cout<<"\t\t\t\t->Press 6 to to Exit Receptionist menu "<<std::endl;
        int x;
        std::cout<<"\t\t\t\tPress The Button :";
        std::cin>>x;
        if(x==1)
        {
            ck_in_gst();
            int c=0;
            bool flag=true;
            std::ifstream infile("count_gst.txt");
            if(!infile)
            {
                flag=false;
            }
            if(flag==true)
            {
                infile>>c;
                infile.close();
            }
            c++;
            std::ofstream outfile("count_gst.txt");
            outfile<<c
                   <<' ';
            outfile.close();
        }
        else if(x==2)
        {


            ck_out_gst();
        }
        else if(x==3)
            ck_info_gst();
        else if(x==4)
            prt_ord_lst();
        else if(x==5)
            infect_room();
        else if(x==6)
        {
            system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tClosing Receptionist Menu"<<std::endl;
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
    Sleep(250);
    system("CLS");
}

void Receptionist::ck_in_gst()
{
    bool flag=true;
    Guest* obj[100];
    int k=0;
    std::string s_name,s_id,s_pwd,s_room_no,s_date;

    std::ifstream infile("guest_list.txt");
    if(!infile)
    {
        std::cout<<"\t\t\t\tThere are no guest right now"<<std::endl;
        flag=false;
    }
    if(flag==true)
    {
        obj[k]=new Guest;
        infile>>s_name>>s_id>>s_pwd>>s_room_no>>s_date;
        obj[k]->Setname(s_name);
        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setroom_no(s_room_no);
        obj[k]->Setdate(s_date);
        while(!infile.eof())
        {
            k++;
            obj[k]=new Guest;
            infile>>s_name>>s_id>>s_pwd>>s_room_no>>s_date;
            obj[k]->Setname(s_name);
            obj[k]->Setid(s_id);
            obj[k]->Setpwd(s_pwd);
            obj[k]->Setroom_no(s_room_no);
            obj[k]->Setdate(s_date);
        }
        infile.close();
    }

    std::ofstream outfile("guest_list.txt");

    for(int i=0; i<k; i++)
    {
        outfile<<obj[i]->Getname()
               <<' '
               <<obj[i]->Getid()
               <<' '
               <<obj[i]->Getpwd()
               <<' '
               <<obj[i]->Getroom_no()
               <<' '
               <<obj[i]->Getdate()
               <<' ';
    }
    for(int i=0; i<k; i++)delete obj[i];

    Guest* obj1;
    obj1=new Guest;
    system("CLS");
    system("color B1");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To check in Guest\n";
    std::cout<<"\t\t\t\t====================================================\n";
    Sleep(500);
    std::cout<<"\t\t\t\t\tEnter the name of the guest : ";
    std::cin>>s_name;
    s_id=obj1->id_gnrt(s_name);
    s_pwd=obj1->pwd_gnrt();
    std::cout<<"\t\t\t\t\tGuest's ID is : "<<s_id<<std::endl;
    std::cout<<"\t\t\t\t\tGuest's Password is : "<<s_pwd<<std::endl;
    Sleep(500);
    system("CLS");
    std::cout<<"\n\n\n\n";
    //after adding room
    while(1)
    {
        std::cout<<"\n\n\t\t\t\t\tThe Empty Rooms are  : "<<std::endl;
        show_empty_room();
        std::cout<<"\n\n\t\t\t\t\tEnter the Room number to Allocate : ";
        std::cin>>s_room_no;
        int r=stoi(s_room_no);

        if(r_obj->occupied(r))
        {
            std::cout<<"\t\t\t\t\tRoom is not empty or it can be infected"<<std::endl;
            std::cout<<"\t\t\t\t\tGive another room number"<<std::endl;
        }
        else
        {
            int floor=r/100;
            r%=100;
            r=(r-1)+(30*(floor-1));

            r_obj->rooms[r]=full;
            std::cout<<"\n\t\t\t\t\tRoom is allocated"<<std::endl;
            break;
        }
    }
    std::cout<<"\n\t\t\t\t\tGive Today's Date and it's format should be dd-mm-yy : ";
    std::cin>>s_date;

    outfile<<s_name
           <<' '
           <<s_id
           <<' '
           <<s_pwd
           <<' '
           <<s_room_no
           <<' '
           <<s_date
           <<' ';
    outfile.close();

}

void Receptionist::ck_out_gst(std::string q_id,std::string q_pwd)
{
    system("CLS");
    system("color E4");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";/////////////////////////ai pura block ta add korbi
    std::cout<<"\t\t\t\t\t\tWelcome To check out Guest\n";
    std::cout<<"\t\t\t\t====================================================\n";
    Sleep(500);
    Guest* obj[100];
    int k=0;
    std::ifstream infile("guest_list.txt");
    if(!infile)
    {
        std::cout<<"\t\t\t\t\tthere is no guest to check out."<<std::endl;
        return ;
    }
    obj[k]=new Guest;
    std::string s_name,s_id,s_pwd,s_room_no,s_date;
    infile>>s_name>>s_id>>s_pwd>>s_room_no>>s_date;
    obj[k]->Setname(s_name);
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setroom_no(s_room_no);
    obj[k]->Setdate(s_date);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Guest;
        infile>>s_name>>s_id>>s_pwd>>s_room_no>>s_date;
        obj[k]->Setname(s_name);
        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setroom_no(s_room_no);
        obj[k]->Setdate(s_date);
    }
    infile.close();
    std::ofstream outfile("guest_list.txt");
    for(int i=0; i<k; i++)
    {
        if((obj[i]->Getid()!=q_id)&&(obj[i]->Getpwd()!=q_pwd))
        {
            outfile<<obj[i]->Getname()
                   <<' '
                   <<obj[i]->Getid()
                   <<' '
                   <<obj[i]->Getpwd()
                   <<' '
                   <<obj[i]->Getroom_no()
                   <<' '
                   <<obj[i]->Getdate()
                   <<' ';
        }
        else
        {
            int r=stoi(obj[i]->Getroom_no());
            int floor=r/100;
            r%=100;
            r=(r-1)+(30*(floor-1));

            r_obj->rooms[r]=emptyy;
            std::cout<<"\t\t\t\t\tRoom is deallocated"<<std::endl;
        }
    }
    outfile.close();
    for(int i=0; i<k; i++)delete obj[i];
}

void Receptionist::ck_info_gst()
{
    system("CLS");
    system("color E4");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To Guest Info\n";
    std::cout<<"\t\t\t\t====================================================\n";
    Sleep(500);
    std::string t_date;
    std::cout<<"\t\t\t\tPlease insert today's date dd-mm-yy : ";
    std::cin>>t_date;
    std::ifstream infile("guest_list.txt");
    if(!infile)
    {
        std::cout<<"\t\t\t\t\tThere are no guest to check their information"<<std::endl;
        return ;
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
    while(1)
    {
        Sleep(250);
        system("CLS");
        system("color C0");
        std::cout<<"\n\n\n\n\n\n";
        std::cout<<"\n\t\t\t\t\t\tThe Guest Info Menu\n"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 1 for only to See The information of Guests"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 2 for Check_Out List of Today"<<std::endl;
        std::cout<<"\t\t\t\t\t\t->Press 3 for Exit the menu"<<std::endl;
        int x;
        std::cout<<"\n\t\t\t\tEnter Your Choice :";
        std::cin>>x;
        if(x==1)
        {
            Sleep(250);
            system("CLS");
            system("color C0");
            std::cout<<"\n\n\n\n\n\n";
            std::cout<<"\n\t\t\t\t---------------The List Of The Guests-------------------\n";
            for(int i=0; i<k; i++)
            {    std::cout<<"\n\t\t\t\******************************************************** \n";
                std::cout<<"\n\t\t\t\tName : "<<obj[i]->Getname()<<std::endl;
                std::cout<<"\n\t\t\t\tID : "<<obj[i]->Getid()<<std::endl;
                std::cout<<"\n\t\t\t\tPassword : "<<obj[i]->Getpwd()<<std::endl;
                std::cout<<"\n\t\t\t\tRoom_no : "<<obj[i]->Getroom_no()<<std::endl;
                std::cout<<"\n\t\t\t\tDate : "<<obj[i]->Getdate()<<std::endl;
                std::cout<<"\n\t\t\t\******************************************************** \n";
                Sleep(250);
            }
            std::cout<<"\t\t\t\t\t\t->Press a key to exit ";
            getch();
            Sleep(250);
            system("CLS");
        }
        else if(x==2)
        {
            Sleep(250);
            system("CLS");
            system("color C0");
            std::cout<<"\n\n\n\n\n\n";
            std::cout<<"\n\t\t\t\t---------------Today's Check-out List Of The Guests-------------------\n";
            for(int i=0; i<k; i++)
            {
                int diff_d=0,diff_m=0;
                std::string g_date=obj[i]->Getdate();

                diff_d=(((t_date[0]-'0')*10)+(t_date[1]-'0'))-(((g_date[0]-'0')*10)+(g_date[1]-'0'));
                diff_m=(((t_date[3]-'0')*10)+(t_date[4]-'0'))-(((g_date[3]-'0')*10)+(g_date[4]-'0'));
                bool flag=false;


                if(diff_m==0&&diff_d==2)
                    flag=true;
                else if(diff_m==1)
                {
                    if(h_m_d(((g_date[3]-'0')*10)+(g_date[4]-'0'))+diff_d==2)
                        flag=true;
                }

                if(flag==true)
                {
                    std::cout<<"\n\t\t\t\tName : "<<obj[i]->Getname()<<std::endl;
                    std::cout<<"\n\t\t\t\tID : "<<obj[i]->Getid()<<std::endl;
                    std::cout<<"\n\t\t\t\tDo you want to check out above guest?"<<std::endl;
                    std::cout<<"\t\t\t\t\t\t->Press 1 for Yes"<<std::endl;
                    std::cout<<"\t\t\t\t\t\t->Press 2 for No"<<std::endl;
                    int y;
                    std::cout<<"\n\t\t\t\tPress the Button:";
                    std::cin>>y;
                    if(y==1)
                    {
                        ck_out_gst(obj[i]->Getid(),obj[i]->Getpwd());
                        std::cout<<"\t\t\t\t\t\tGuest has checked out"<<std::endl;
                    }
                }
            }
            Sleep(250);
            system("CLS");
        }
        else if(x==3)
        {
            system("CLS");
            system("color 40");
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tClosing Guest Check-out  Menu"<<std::endl;
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
    for(int i=0; i<k; i++)delete obj[i];
    Sleep(250);
    system("CLS");
}

void Receptionist::ck_out_gst()
{
    ck_info_gst();
}

int Receptionist::h_m_d(int m)
{
    int ar[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    return ar[m-1];
}

void Receptionist::prt_ord_lst()
{
    system("CLS");
    system("color E1");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";/////////////////////////ai pura block ta add korbi
    std::cout<<"\t\t\t\t\t\tWelcome To Order Porter\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::string s_desg,s_room_no;
    bool flag=true;
    std::ifstream infile("Porter_ord_lst.txt");
    if(!infile)
    {
        std::cout<<"\t\t\t\t\t\tThere is no order yet"<<std::endl;
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

    std::cout<<"\t\t\t\t\t\tEnter your designation : ";
    std::cin>>s_desg;
    std::cout<<"\t\t\t\t\t\tEnter your room_no : ";
    std::cin>>s_room_no;

    outfile<<s_desg
           <<' '
           <<s_room_no
           <<' ';

    outfile.close();
    std::cout<<"\t\t\t\t\t\tOrder Given ";
    Sleep(250);
    system("CLS");
}

void Receptionist::show_empty_room()
{
    std::cout<<"\n\n\t\t\t\t\t\t1st floor : "<<std::endl;///////////////////////////////////////////////////////

    for(int i=101; i<=130; i++)
    {
        if(r_obj->occupied(i));
        else
            std::cout<<i<<' ';
    }
    std::cout<<std::endl;
    std::cout<<"\n\t\t\t\t\t\t2nd floor : "<<std::endl;

    for(int i=201; i<=230; i++)
    {
        if(r_obj->occupied(i));
        else
            std::cout<<i<<' ';
    }
    std::cout<<std::endl;
    std::cout<<"\n\t\t\t\t\t\t3rd floor : "<<std::endl;

    for(int i=301; i<=330; i++)
    {
        if(r_obj->occupied(i));
        else
            std::cout<<i<<' ';
    }
    std::cout<<std::endl<<std::endl;
}

void Receptionist::infect_room()
{
     system("CLS");
    system("color 61");
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tWelcome To Covid Safety\n";
    std::cout<<"\t\t\t\t====================================================\n";
    std::cout<<"\t\t\t\t\t\tEnter the room number you want to mark as infected : ";
    int r;
    std::cin>>r;
    int floor=r/100;
    r%=100;
    r=(r-1)+(30*(floor-1));

    r_obj->rooms[r]=infected;
}
