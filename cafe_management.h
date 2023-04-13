#include <iostream>
#include <string>
#include "master_entery.h"
#include "normal_entery.h"
using namespace std;
#ifndef Cafe_management_H
#define Cafe_management_H
class cyberCafe
{
public:
	string name;
	long long int contact;
	bool premium, added;
	void book();
	void showCharges();
	void payCharges();
	void renewBooking();
	void timings();
	master_entry k;
	normal_entry o;
	
};
void cyberCafe::timings()
{
	cout << "----------- Cyber Cafe Timings -----------" << endl;
	cout << "8 AM - 8 PM (Mon - Sat)" << endl;
}

void cyberCafe::showCharges()
{
	cout << "Charges : \n 1 Hour : 10 INR \n 1 Day : 200 INR \n 1 Month : 3000 INR \n 3 Months : 5000 \n 1 Year : 10000 \n";
};
void cyberCafe::payCharges()
{
	int ans = 0;
	showCharges();
	cout << "Do u want to use computer?if yes press 1 (charges will apply).\n";
	cin >> ans;
	o.add_new_member();
	if (ans)
	{
		cout << "charges will be collected according to time of your usage.\n";
		cout << "use login credentials as username:guest,Password:guest\n";
	}
};
void cyberCafe::book()
{
	while (true)
	{
		cout << "Do you have any subscription ? (Press 1 for Yes and 0 for No) \n";
		cin >> premium;
		if (premium)
		{
			if(k.search())
			{
				cout<<"\nyou can use computer\n";
			}
			else{
				continue;
			}
		}
		else
		{
			payCharges();
		}
		break;
	}
}

void cyberCafe::renewBooking()
{
	
	int sp, cp, pm, i = 0, x = 0;
	char m_n[20];
	showCharges();
	cout << "Are u already a member:(if yes press 1) ";
	cin >> pm;
	if(pm)
	{
		k.update();
	}
	else{
		cout << "Are u want to take new subscribtion:(if yes press 1) ";
		int X;
		cin>>X;
		if(X)
		{
			k.add_new_member();

		}
		else{
		payCharges();
		}
	}	
}
#endif

