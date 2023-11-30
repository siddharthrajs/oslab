#include<iostream>
using namespace std;

int main()
{
	int bt[10],at[10],tat[10],wt[10],ct[10],p[10];
	float totaltat=0,totalwt=0;
	
	int n;
	cout<<"Enter number of process : ";
	cin>>n;
	
	
	cout<<"enter arrival time and brust time for each process : "<<endl;
	for(int i=0;i<n;i++)
	{
		p[i]=i+1;
		cout<<"Arrival time of process"<<i+1<<":";
		cin>>at[i];
		
		cout<<"Brust time of process"<<i+1<<":";
		cin>>bt[i];
		
		cout<<endl;
	}
	
	for (int i = 0; i < n - 1; i++)
	{
       for (int j = 0; j < n - i - 1; j++) 
	   {
            if (at[j] > at[j + 1])
			{
                int temp = at[j];
                int temp1=bt[j];
                int temp3=p[j];
                at[j] = at[j + 1];
                bt[j]=bt[j+1];
                p[j]=p[j+1];
                at[j + 1] = temp;
                bt[j+1]=temp1;
                p[j+1]=temp3;
            }
       }
    }
    
    
    for (int i = 1; i < n - 1; i++)
	{
       for (int j = 1; j < n - i ; j++) 
	   {
            if (bt[j] > bt[j + 1])
			{
                int temp = at[j];
                int temp1=bt[j];
                int temp3=p[j];
                at[j] = at[j + 1];
                bt[j]=bt[j+1];
                p[j]=p[j+1];
                at[j + 1] = temp;
                bt[j+1]=temp1;
                p[j+1]=temp3;
            }
       }
    }
    
    //completion time
    int sum=at[0];
    for(int j=0;j<n;j++)
    {
    	if(at[j]<=sum)
    	{
    	    sum=sum+bt[j];
    	    ct[j]=sum;	
		}
		else
		{
			sum=at[j];
			sum=sum+bt[j];
    	    ct[j]=sum;
		}
    	
	}
	
	//turn around time
	
	for(int k=0;k<n;k++)
	{
		tat[k]=ct[k]-at[k];
		totaltat=totaltat+tat[k];
	}
	
	
	//waiting time
	
	for(int k=0;k<n;k++)
	{
		wt[k]=tat[k]-bt[k];
		totalwt=totalwt+wt[k];
	}
    
    
    cout<<"P"<<"\t";
    cout<<"A"<<"\t";
    cout<<"B"<<"\t";
    cout<<"C"<<"\t";
    cout<<"T"<<"\t";
    cout<<"W";
	cout<<endl;
    for(int i=0;i<n;i++)
	{
		cout<<p[i]<<"\t";
		cout<<at[i]<<"\t";
		cout<<bt[i]<<"\t";
		cout<<ct[i]<<"\t";
		cout<<tat[i]<<"\t";
		cout<<wt[i];
		cout<<endl;
	}
	
	cout<<"Average Tat is : "<<(totaltat/n)<<endl;
	cout<<"Average waiting time is : "<<(totalwt/n)<<endl;
  
}
