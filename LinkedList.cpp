//Program to implement singly linked list operations 

#include <iostream>
using namespace std;
class node		//declaring node class
{
	public:
		int data;
		node *next;
		
		node(int n)
		{
			data=n;
			next=NULL;
		}
};

class list		//declaring list class
{
	node *listptr;
	public:
		list()
		{
			listptr=NULL;
		}
		void create();
		void display();
		void concat();
		void merge();
		void intersect();
		void union();
		
};

void list::create()
{
	int n,num;
	node *temp;
	cout<<"Enter the number of nodes";
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"Enter the data";
		cin>>n;
		node *newnode=new node(n);
		if(first==NULL)
		{
			listptr=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=temp->next;
		}
	}
	
}

void list::display()
{
	node *temp=listptr;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL";
}


































