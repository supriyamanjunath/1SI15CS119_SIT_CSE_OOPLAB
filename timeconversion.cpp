#include<iostream>
#include<string>
using namespace std;

class time12
{
	private:
	bool pm;
	int hrs;
	int mins;
	
	public:
	time12():pm(true),hrs(0),mins(0)
	{}
	time12(bool ap,int h,int m):pm(ap),hrs(h),mins(m)
	{}
	void display ()const
	{
		cout<<hrs<<":";
		if(mins<10)
			cout<<0;
		cout<<mins<<":";
		
		string am_pm=pm?"p.m.":"a.m.";
		
		cout<<am_pm;	
	}
	
};

class time24
{
	private:
	int hours;
	int minutes;
	int seconds;
	
	public:
	time24():hours(0),minutes(0),seconds(0)
	{}
	time24(int h,int m,int s):hours(h),minutes(m),seconds(s)
	{}
	void display() const
	{
		if(hours<10)
			cout<<'0';
		cout<<hours<<":";
		
		if(minutes<10)
			cout<<'0';
		cout<<minutes<<":";
		
		if(seconds<10)
			cout<<'0';
		cout<<seconds;
		
	}
	operator time12() const;
};


time24::operator time12() const
{
	int hrs24=hours;
	
	bool pm=hours<12?false:true;
	
	int roundmins =seconds<30?minutes:minutes+1;
	
	if(roundmins==60)
	{
		roundmins=0;
		++hrs24;
		
		if(hrs24==12||hrs24==24)
			pm=(pm==true)?false:true;
	}
	
	int hrs12=(hrs24<13)?hrs24:hrs24-12;
	
	if(hrs12==0)
	{
		hrs12=12;
		pm=false;
	}
	return time12(pm,hrs12,roundmins);
	
}


int main(void)
{
	int h,m,s;
	
	while(true)
	{
		cout<<"enter the 24_hr format time\n";
		cout<<"hours(0 to 23):";
		cin>>h;
		
		if(h>23)
			return 1;
		
		cout<<"minutes(0 to 59):";
		cin>>m;
		
		if(m>59)
			return 1;
		
		time24 t24(h,m,s);
		cout<<"you entered:";
		t24.display();
		time12 t12=t24;
		
		cout<<"\n 12_hour time:";
		
		t12.display();
		
		cout<<"\n\n";
		
		
		
	}
	return 0;
}
