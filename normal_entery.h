#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<cstring>
#ifndef Noraml_entery_H
#define Noraml_entery_H
using namespace std;
fstream ofile;
class normal_entry
{
    public:
    string name;
    string age;
    string phno;
    string sno;
    void add_new_member()
    {
        ofile.open("n.txt",ios::out|ios::in|ios::app);
        cout<<"Enter your name:";
        cin>>name;
        cout<<"Enter your age:";
        cin>>age;
        cout<<"Enter your phone number:";
        cin>>phno;
        string k=name+","+age+","+phno;
        ofile<<endl<<k;
        ofile.close();
    }
    void total_entry()
    {
        ofile.open("n.txt",ios::out|ios::in|ios::app);
        string s;
        if ( ofile.is_open() ) 
        { 
            ofile>>s; 
            cout<<s; 
        }
        ofile.close();
    }
};
#endif