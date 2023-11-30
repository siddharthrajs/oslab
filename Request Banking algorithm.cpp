#include<iostream>
using namespace std;

int main()
{
	int max[10][10],allo[10][10],need[10][10],ava[10],work[10],ss[10],req[10];
	int n,r,k=0,z;
	bool finish[10];
	
	cout<<"Enter number of process and resources :";
	cin>>n>>r;
	
	//input values
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the max values for resource "<<i<<":";
		for(int j=0;j<r;j++)
		{
			cin>>max[i][j];
		}
		cout<<"Enter the Allocation values for resource "<<i<<":";
		for(int j=0;j<r;j++)
		{
			cin>>allo[i][j];
		}
		for(int j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-allo[i][j];
		}
		finish[i]=false;
	}
	cout<<"Enter the Available "<<":";
	for(int j=0;j<r;j++)
	{
		cin>>ava[j];
		work[j]=ava[j];
	}
	
	
	cout<<"enter  prcoess number to request:";
	cin>>z;
	cout<<"Enter request of the process";
	for(int j=0;j<r;j++)
	{
		cin>>req[j];
	}
	
	bool flag1=true;
	for(int j=0;j<r;j++)
	{
		if(req[j]<=need[z][j] && req[j]<=ava[j])
		{
			continue;
		}
		else
		{
			flag1=false;
			break;
		}
	}
	
	if(flag1==false)
	{
		cout<<"request is not granted";
	}
	else
	{
	    for(int j=0;j<r;j++)
	    {
		allo[z][j]=allo[z][j]+req[j];
		ava[j]=ava[j]-req[j];
		need[z][j]=need[z][j]-req[j];
		work[j]=work[j]-req[j];
	    }
	//checking condition
	bool proceed=true;
	
	while(proceed)
	{
		proceed=false;
		
		for(int i=0;i<n;i++)
		{
		    bool flag=true;
			if(finish[i]==false)
			{
				for(int j=0;j<r;j++)
				{
					if(need[i][j]<=work[j])
					{
						continue;
					}
					else
					{
						flag=false;
						break;
					}
				}
				
				if(flag==false)
				{
					continue;
				}
				
				for(int j=0;j<r;j++)
				{
					work[j]=work[j]+allo[i][j];
				}
				finish[i]=true;
				ss[k++]=i;
				proceed=true;
				
			}
		}
	}
	
	
	int count=0;
	for(int i=0;i<n && finish[i]==true;i++)
	{
		count++;
		continue;
	}
	cout<<count<<endl;
	
	
	
	
	
	//output values
	cout<<"P"<<"\t\t"<<"Max"<<"\t\t"<<"Allocation"<<"\t"<<"Need"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"p"<<i<<"\t\t";
		for(int j=0;j<r;j++)
		{
			cout<<max[i][j]<<" ";
		}
		cout<<"\t\t";
		
		for(int j=0;j<r;j++)
		{
			cout<<allo[i][j]<<" ";
		}
		cout<<"\t\t";
		
		for(int j=0;j<r;j++)
		{
			cout<<need[i][j]<<" ";
		}
		cout<<endl;
	}
	
	if(count==n)
	{
		cout<<"safe squence exist : "<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<ss[i]<<" ";
		}
	}
	else
	{
		cout<<"safe sequence does not exist";
	}
}
}
