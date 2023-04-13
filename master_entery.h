#include<iostream>
#ifndef Master_entry_H
#define Master_entry_H

#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<cstring>
using namespace std;
   fstream file; 
class master_entry
{
    public:
    char name[30];
    char email[30];
    string phno;
    string user;
    string pass;
    int plan;
    bool search()
    {
        string pa,us;
        bool flag;
        file.open("m.txt",ios::out|ios::in|ios::app);
        int choice,c=0;
        vector<string>n(6);
        while(!file.eof())
        {
            string c;
            file>>c;
            n.push_back(c);
        }
        vector<string>k;
        file.close();
        int o=0;
        
        while(c<3)
        {
       cout<<"Enter your username:";
        cin>>us;
        cout<<"Enter your password:";
        cin>>pa;
         flag=false;
         o=0;
         file.open("m.txt",ios::out|ios::in|ios::app);
        while(!file.eof())
        {
           
          char p[100];
          file>>p;
          char *l;
          l=strtok(p ,",");
          while(l!=NULL)
          {
            k.push_back(l);
            l=strtok(NULL,",");
          }
          if(k[0]==us&&k[1]==pa)
          {
             flag=true;
             break;
          }
           o++;
           
        }
        
        if(flag)
        {
            break;
        }
        cout<<"you entered wrong password or username";
    c++;
    k.clear();
        } 
        file.close();
        return flag;
    }
    bool searchusername(string user)
    {
        string pa,us;
        bool flag;
        file.open("m.txt",ios::out|ios::in|ios::app);
        int choice,c=0;
        vector<string>n(6);
        while(!file.eof())
        {
            string c;
            file>>c;
            n.push_back(c);
        }
        vector<string>k;
        file.close();
         flag=false;
         file.open("m.txt",ios::out|ios::in|ios::app);
        while(!file.eof())
        {
           
          char p[100];
          file>>p;
          char *l;
          l=strtok(p ,",");
          while(l!=NULL)
          {
            k.push_back(l);
            l=strtok(NULL,",");
          }
          if(k[0]==user)
          {
             flag=true;
             break;
          }
       
            k.clear();
        }
        file.close();
        return flag;
    }
    void add_new_member()
    {
        while(1)
        {
        file.open("m.txt",ios::out|ios::in|ios::app); 
        cout<<"Enter your name:";
        cin>>name;
        cout<<"Enter your email:";
        cin>>email;
        cout<<"Enter your phone number:";
        cin>>phno;
        cout<<"create new user name:";
        cin>>user;
        cout<<"Create your password:";
        cin>>pass;
        cout<<"Our plans details are:"<<endl;
        cout<<"1. Plan 500:"<<endl<<"Details are:"<<"Unlimited use of our computers for 6 months,free snacks and printing"<<endl;
        cout<<"2. Plan 399:"<<endl<<"Details are:"<<"3 hrs of use of our computers for 4 months and free printing"<<endl;
        cout<<"3. Plan 250:"<<endl<<"Details are:"<<"2 hrs of use of our computers for 3 months"<<endl;
        cout<<"Select your plan:";
        cin>>plan;
       // if(!searchusername(user))
        {
        string k=user+","+pass+","+name+","+email+","+phno+","+to_string(plan);
        file<<k;
          file.close();
        switch(plan)
        {
            case 1:
            {
                cout<<"Congrats you have selected our Plan 500, your plan will be activated soon"<<endl;
                break;
            }
            case 2:
            {
                cout<<"Congrats you have selected our Plan 399, your plan will be activated soon"<<endl;
                break;
            }
            case 3:
            {
                cout<<"Congrats you have selected our Plan 250, your plan will be activated soon"<<endl;
                break;
            }
        }
        }
        //else
        {
            cout<<"choose another username\n";
        }
        }
    }
    void update()
    {   
        string pa,us;
        bool flag;
        file.open("m.txt",ios::out|ios::in|ios::app);
        int choice,c=0;
        vector<string>n(6);
        while(!file.eof())
        {
            string c;
            file>>c;
            n.push_back(c);
        }
        vector<string>k;
        file.close();
        int o=0;
        
        while(c<3)
        {
       cout<<"Enter your username:";
        cin>>us;
        cout<<"Enter your password:";
        cin>>pa;
         flag=false;
         o=0;
         file.open("m.txt",ios::out|ios::in|ios::app);
        while(!file.eof())
        {
           
          char p[100];
          file>>p;
          char *l;
          l=strtok(p ,",");
          while(l!=NULL)
          {
            k.push_back(l);
            l=strtok(NULL,",");
          }
          if(k[0]==us&&k[1]==pa)
          {
             flag=true;
             break;
          }
           o++;
           
        }
        
        if(flag)
        {
            break;
        }
        cout<<"you entered wrong password or username";
    c++;
    k.clear();
        } 
        file.close();
        if(flag)
        {
            cout<<"Welcome to OUR CAFE:"<<endl;
            cout<<"Choose the option you wnt to update:"<<endl;
            cout<<"1. Name"<<endl<<"2. Email"<<endl<<"3. Phone number"<<endl<<"4. Password";
            cin>>choice;
            switch(choice)
            {
                case 1:
                {
                    cout<<"Enter your new username:";
                    cin>>k[0];
                    break;
                }
                case 2:
                {
                    cout<<"Enter your new name:";
                    cin>>k[2];
                    break;
                }
                case 3:
                {
                    cout<<"Enter your new email:";
                    cin>>k[3];
                    break;
                }
                case 4:
                {
                    cout<<"Enter your new phone number:";
                    cin>>k[4];
                    break;
                }   
                case 5:
                {
                    cout<<"Enter your new password:";
                    cin>>k[1];
                    break;
                }
            }
        }
        ifstream file("m.txt");
         string lz=k[0]+","+k[1]+","+k[2]+","+k[3]+","+k[4]+","+k[5];
         int e=0;
         stringstream data;
         string line;
         while (getline(file,line))
         {
            if(e==o)
            {
                data<<lz<<endl;
            }
            else{
                data<<line<<endl;
            }
            e++;
         }
         
        file.close();
        ofstream ofile("m.txt");
        ofile<<data.str();
        ofile.close();
    }
    void display()
    {
        vector<string>k(6);
        cout<<"VIP member details:"<<endl;
         file.open("m.txt",ios::in);
         cout<<"\n username :";
        cout<<"\t name :";
        cout<<"\t email is:";
        cout<<"\t Phone number :";
        cout<<"\t plan :";
         while(!file.eof())
        {
          char p[100];
          file>>p;
          char *l;
          l=strtok(p ,",");
          while(l!=NULL)
          {
            k.push_back(l);
            l=strtok(NULL,",");
          }
        cout<<"\n"<<k[0];
        cout<<"\t"<<k[2];
        cout<<"\t"<<k[3];
        cout<<"\t"<<k[4];
        cout<<"\t"<<k[5];
        k.clear();
        }
        file.close();
    }
    void searchformem()
    {

         string pa,us;
        bool flag;
        file.open("m.txt",ios::out|ios::in|ios::app);
        int choice,c=0;
        vector<string>n(6);
        while(!file.eof())
        {
            string c;
            file>>c;
            n.push_back(c);
        }
        vector<string>k;
        file.close();
        int o=0;
        
        while(c<3)
        {
       cout<<"Enter your username:";
        cin>>us;
        cout<<"Enter your password:";
        cin>>pa;
         flag=false;
         o=0;
         file.open("m.txt",ios::out|ios::in|ios::app);
        while(!file.eof())
        {
           
          char p[100];
          file>>p;
          char *l;
          l=strtok(p ,",");
          while(l!=NULL)
          {
            k.push_back(l);
            l=strtok(NULL,",");
          }
          if(k[0]==us&&k[1]==pa)
          {
             flag=true;
             break;
          }
           o++;
           
        }
        
        if(flag)
        {
            break;
        }
        cout<<"you entered wrong password or username";
    c++;
    k.clear();
        } 
        file.close();
        if(flag)
        {
            cout<<"\nmember details are:";
        cout<<"\n"<<k[0];
        cout<<"\t"<<k[2];
        cout<<"\t"<<k[3];
        cout<<"\t"<<k[4];
        cout<<"\t"<<k[5];
        }
        else{
            cout<<"member not found\n";
        }
    }
};
#endif