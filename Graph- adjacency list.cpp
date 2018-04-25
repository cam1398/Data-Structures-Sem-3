//Program to insert and delete node in graph using adjacency matrix

#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

class graph
{
	public:
		int a[10][10];
		int n;
		void create();
		void display();
		void insert();
		void del();
};

void graph::create()
{
	cout<<"Enter the number of vertices";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(i!=j)
			{
				cout<<"Enter 1 if vertex"<<i+1<<"is adjacent to"<<j+1<<"else enter 0";
				cin>>a[i][j];
				a[j][i]=a[i][j];
			}
			else
				a[i][j]=0;
		}
	}
}

void graph::display()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n\n";
	}
}

void graph::insert()
{
	int v1,v2;
	cout<<"Enter 1st vertex to insert";
	cin>>v1;
	cout<<"Enter the 2nd vertex to insert";
	cin>>v2;
	
	a[v1][v2]=a[v2][v1]=1;
}

void graph::del()
{
	int v1,v2;
	cout<<"Enter first vertex to delete";
	cin>>v1;
	cout<<"Enter second vertex to delete";
	cin>>v2;
	
	a[v1][v2]=a[v2][v1]=0;
}

int main()
{
	graph g;
	int c1,c2;
	do
	{
		cout<<"Enter 1.Create/n2.Display/n3.Insert/n4.Delete/n";
		cin>>c1;
		
		switch(c1)
		{
			case 1:
				g.create();
				break;
				
			case 2:
				g.display();
				break;
			
			case 3:
				g.insert();
				break;
				
			case 4:
				g.del();
				break;
				
			default:
				cout<<"Invalid choice";
		}
		cout<<"Enter 1 to continue";
		cin>>c2;
	}while(c2==1);
	return 0;
}































