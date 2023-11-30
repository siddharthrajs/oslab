#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n,tq,completed=0,tot_idle_time=0,index,curr=0;
	int at[10],bt[10],rt[10],wt[10],tat[10],ct[10],st[10];
	float awt=0,atat=0;
	bool visited[30]={false};
	queue<int>q;
	
	cout<<"Enter number of process and time quantum : ";
	cin>>n>>tq;
	
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the Arrival time of Process "<<i+1<<":";
		cin>>at[i];
		cout<<"Enter the Brust  time of Process "<<i+1<<":";
		cin>>bt[i];
		rt[i]=bt[i];
		cout<<endl;
	}
	
	q.push(0);
	visited[0]=true;
	
	while(completed!=n)
	{
		index=q.front();
		q.pop();
		
		if(rt[index]==bt[index])
		{
			st[index]=max(curr,at[index]);
			curr=st[index];
			
		}
		
		if(rt[index]-tq>0)
		{
			rt[index]=rt[index]-tq;
			curr=curr+tq;
		}
		else
		{
			curr=curr+rt[index];
			rt[index]=0;
			completed++;
			
			ct[index]=curr;
			tat[index]=ct[index]-at[index];
			wt[index]=tat[index]-bt[index];
			
			atat=atat+tat[index];
			awt=awt+wt[index];
		}
		
		
		for(int i=1;i<n;i++)
		{
			if(rt[i]>0 && at[i]<=curr && visited[i]== false)
			{
				q.push(i);
				visited[i]=true;
			}
		}
		
		if(rt[index]>0)
		{
			q.push(index);
		}
		
		if(q.empty())
		{
			for(int i=1;i<n;i++)
			{
				if(rt[i]>0)
				{
					q.push(i);
					visited[i]=true;
					break;
				}
			}
		}
	}
	
	cout<<"p"<<"\t"<<"A"<<"\t"<<"B"<<"\t"<<"C"<<"\t"<<"W"<<"\t"<<"T"<<"\t"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<endl;
	}
	
	cout<<"Average Turn Around time :"<<(atat/n);
	cout<<"Average Waiting time :"<<(awt/n);
	
	
}
