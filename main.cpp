#include<iostream>
#include "master_entery.h"
#include "computer_entery.h"
#include "cafe_management.h"
#include "normal_entery.h"
#include<string.h>
using namespace std;

int main()
{
 master_entry me;	
 computer comp;
 cyberCafe caf;
 normal_entry nom;
 int o,a,i,j,k;
 int mn=2,cn=0,x=0;
 int m=1,m1=1,m2=1,cc=1,c1=1,c2=1;
 string password="1234";
 string p;
 cout<<"\nEnter the password: ";
 cin>>p;
 while(1)
 {
	if(p==password)
	{
	    break;
	}
	else
	{
	    cout<<"Invalid password!"<<endl;
		cout<<"please enter the correct password: ";
		cin>>p;
	}
 }
//----------------------------------------------------------------------------------------------------- 
 cout<<"Welcome to cyber cafe management"<<endl;
 while(1)
 {
  cout<<"1) Master Entry\n2)Cafe Management\n3)Exit";
  cout<<"\nPlease select any one of above options:\t";
  cin>>o;
  switch(o)
  {
	case 1:
	{
	 while(m!=3)
	 {
	  cout<<"1)Member entry option.\n2)Computer entry option.\n3)Return.\n";
	  cin>>m;
	  switch(m)
      {
       case 1:
	   {
	    while(m1!=4)
		{	
	     cout<<"1)Add new member.\n2)Show member.\n3)Update record.\n4)Return.\n";
	     cout<<"select any one of above options:\t";
	     cin>>m1;
	     switch(m1)
	     { case 1:
	 	   me.add_new_member();
			 	break;
			 	
			case 2:
            {
		    me.searchformem();
			break;
            }
		    case 3:
		  me.update();
			break;
		    case 4:break;
       }
	     }
         m1=0;	
	   break; 
     }
	   
	   
      //--------------------------------------------------------------------------------------------------
	   case 2:
	   {
	   	string p;
		int cp=0,z=2;
		while(1)
	   	{
	   	 cout<<"Enter the Admin password to access computer details.\n";
		 cin>>p;
		 if(p==password)
		 {
		  cp=1;
		  break;
		 }
		 else 
		 {
		  cout<<"Password Incorrect.\n";	
		  cout<<"If u forgot password press 1,if u want to go back press 0: ";
		  cin>>z;
		  if(z==0)
		  {
		  z=2;
		  break;	
		  }
		  else if(z==1)
		  {
		  z==2;
		  cout<<"enter new password\n";
          cin>>password;
		  }
		  continue;
		 }	
		}
		if(cp==1)
		{
	   	 while(m2!=5)
	   	 {
	      cout<<"1)Add new computer.\n2)Show computer.\n3)Update record.\n4)Delete record.\n5)Return.\n";
	      cout<<"select any one of above options:\t";
	      cin>>m2;
	      switch(m2)
	      {
 	 	    case 1:
 	 	    comp.add_new_comp();
	 	  	break;	
		    case 2:
		    comp.search();
			break;	
		    case 3:
		    comp.update();
			break;
		    case 4:
		   comp.deletee();
			break;	
		   
		    case 5:break;
	      }
		 }
	     m2=0;	 	
        break;  
	     }
	    
        }
	   case 3:break;
      
     }
    m=0;
	break; 
	}
  }
 
//------------------------------------------------------------------------------------------------------- 	
	case 2:
	{
	 while(cc!=4)
	 {
	  cout<<"1)Booking.\n2)Charges.\n3)Renewal(or Taking subscription).\n4)Return.\n";
	  cout<<"select any one of above options:";
	  cin>>cc;
	  switch(cc)
	  {
		case 1:
		{
		 while(c1!=3)
		 {
          cout<<"1)Login.\n2)Log-out.\n3)Return.\n";
	      cout<<"select any one of above options:\t";
		  cin>>c1;
		  switch(c1)
		  {
			case 1:
			caf.book();	
			break;
            case 2:
			cout<<"Logged-out successfully!\n"<<endl;
			cout<<" Visit Again!!!\n"<<endl;
			break;	
			case 3:break; 
		  }
	     } 
		c1=0;
		break;
	    }
		case 2 :
		caf.showCharges();
		break; 
		case 3:
		caf.renewBooking();
		break;
		case 4:break;
	  }
     } 
    cc=0; 
	break;  
	}
//------------------------------------------------------------------------------------------------------	
	case 3:exit(0);  
 }
}
 return 0;
}
