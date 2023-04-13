#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<cstring>
#ifndef computer_entery
#define computer_entery
using namespace std;
class computer
{
    public:
    string sno;
    string model_name,processor;
    string purchase_date,ram,price;
    void add_new_comp()
    {   fstream file;
        file.open("comp.txt",ios::out|ios::in|ios::app);        
        cout<<"Enter the sno of computer:";
        cin>>sno;
        cout<<"Enter the model name:";
        cin>>model_name;
        cout<<"Enter the processor:";
        cin>>processor;
        cout<<"Enter the purchase date:";
        cin>>purchase_date;
        cout<<"Enter the RAM:";
        cin>>ram;
        cout<<"Enter the price of the computer:";
        cin>>price;
        string k=sno+","+model_name+","+processor+","+purchase_date+","+ram+","+price;
        file<<k<<endl;
    }
    void display()
    { 
         
        
        cout<<"\ncomputer details:\n"<<endl;
        fstream file;
        file.open("comp.txt",ios::out|ios::in);
        cout<<"sno"<<"modelname"<<" processor"<<" purchasedate"<<" ram"<<" price";
        while(!file.eof())
        {
            string line;
            file>>line;
            cout<<line<<"\n";
        }
    }
    void update()
    {
        
        string s;
        cout<<"Welcome to OUR CAFE:"<<endl;
       
        fstream file;
        bool flag=false;
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
            cout<<"Enter serial no to search:";
            cin>>s;
         flag=false;
         o=0;
         file.open("comp.txt",ios::out|ios::in|ios::app);
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
          if(k[0]==s)
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
        cout<<"you entered wrong serial number";
    c++;
    k.clear();
        } 
        file.close();
        if(flag)
        {
        cout<<"Choose the option you want to update:"<<endl;
        cout<<"1. Model name"<<endl<<"2. Processor"<<endl<<"3. Purchase date"<<endl<<"4. RAM"<<endl<<"5. Price"<<endl;
        cout<<"Your choice is:\t";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter the new Model name:";
                cin>>k[1];
                break;
            }
            case 2:
            {
                cout<<"Enter the new processor:";
                cin>>k[2];
                break;
            }
            case 3:
            {
                cout<<"Enter the new purchase date:";
                cin>>k[3];
                break;
            }
            case 4:
            {
                cout<<"Enter the RAM:";
                cin>>k[4];
                break;
            }
            case 5:
            {
                cout<<"Enter the new price:";
                cin>>k[5];
                break;
            }
        }
        }       
        ifstream ifile("comp.txt");
         string lz=k[0]+","+k[1]+","+k[2]+","+k[3]+","+k[4]+","+k[5];
         int e=0;
         stringstream data;
         string line;
         while (getline(ifile,line))
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
         
        ifile.close();
        ofstream ofile("comp.txt");
        ofile<<data.str();
        ofile.close();
    }
    void search()
    {    fstream file;
        file.open("comp.txt",ios::out|ios::in|ios::app);
        string s;
        bool flag=false;
        cout<<"Enter serial no to search:";
        cin>>s;
        vector<string>k(6);
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
          if(k[0]==s)
          {
            flag=true;
            cout<<"your computer serial no is:"<<k[0]<<endl;
        cout<<"Your computer's model name is:"<<k[1]<<endl;
        cout<<"Your computer's processor is:"<<k[2]<<endl;
        cout<<"Your computer's purchase date is:"<<k[3]<<endl;
        cout<<"Your computer's RAM is:"<<k[4]<<endl;
        cout<<"Your computer's price is:"<<k[5]<<endl;
        break;
          }
          k.clear();
          file.close();
        }
        if(!flag)
        {
            cout<<"\nthe computer for what you are searching is not there!";
        }
          
    }
    void deletee()
    {
        string s;
        cout<<"Welcome to OUR CAFE:"<<endl;
        cout<<"Enter serial no to search:";
        cin>>s;
        fstream file;
        bool flag=false;
        file.open("comp.txt",ios::out|ios::in|ios::app);
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
          if(k[0]==s)
          {
             flag=true;
             break;
          }
           o++;
           k.clear();
        }
        if(flag)
        {
            ifstream ifile("comp.txt");
        
         int e=0;
         stringstream data;
         string line;
         while (getline(ifile,line))
         {
            if(e==o)
            {
                continue;
            }
            else{
                data<<line<<endl;
            }
            e++;
         }
         
        ifile.close();
        ofstream ofile("comp.txt");
        ofile<<data.str();
        ofile.close();
        }
        else{
            cout<<"not found data which you want to delete";
        }
    }
};
#endif