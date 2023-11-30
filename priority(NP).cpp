#include<iostream>
using namespace std;

int main()
{
	int at[10],bt[10],p[10],x[10],wt[10],tat[10],ct[10];
	int smallest,count=0;
	
	float avg=0,tt=0,end;
	
	int n;
	cout<<"enter number of process : ";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cout<<"enter the arrival time of process "<<i+1<<":";
		cin>>at[i];
		cout<<"enter the brust time of process "<<i+1<<":";
		cin>>bt[i];
		x[i]=bt[i];
		cout<<"enter the priority of process"<<i+1<<":";
		cin>>p[i];
		cout<<endl;
	}
	
	
	p[9]=-1;
	for(int time=0;count!=n;time++)
	{
		smallest=9;
		for(int i=0;i<n;i++)
		{
			if(at[i]<=time && p[i]>p[smallest] && bt[i]>0)
			{
				smallest=i;
			}
		}
		
		time=time+bt[smallest]-1;
		bt[smallest]=-1;
		count++;
		
		end=time+1;
		ct[smallest]=end;
		tat[smallest]=end-at[smallest];
		wt[smallest]=end-at[smallest]-x[smallest];
		
		avg=avg+wt[smallest];
		tt=tt+tat[smallest];
	}
	
	cout<<"p"<<"\t"<<"A"<<"\t"<<"B"<<"\t"<<"C"<<"\t"<<"T"<<"\t"<<"W"<<"\t"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"\t"<<at[i]<<"\t"<<x[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\t"<<endl;
	}
	
	cout<<"Total Average Waiting time is :"<<(avg/n)<<endl;
	cout<<"Total Average TurnAround time is :"<<(tt/n);
}

// if they given high priority for low number them change p[9]=9 and p[i]<p[smallest]
