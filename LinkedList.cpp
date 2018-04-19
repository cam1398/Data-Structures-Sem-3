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
		void concat(list);
		void merge(list);
		void sort();
		
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
		if(listptr==NULL)
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
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL";
}

void list::concat(list l2)
{
	node *temp=listptr;
	while(temp->next!=NULL)
		temp=temp->next;
	
	temp->next=l2.listptr;
}

void list::merge(list l2)
{
	node *temp=listptr;
	while(temp->next!=NULL)
		temp=temp->next;
	
	temp->next=l2.listptr;
	
	sort();
}

void list::sort()
{
	node *temp;
	int swapped=0;
	
	do
	{
		swapped=0;
		temp=listptr;
		
		while(temp->next!=NULL)
		{
			if(temp->data>temp->next->data)
			{
				int t=temp->data;
				temp->data=temp->next->data;
				temp->next->data=t;
				swapped=1;
			}
			temp=temp->next;
		}
		
		
	}while(swapped);
	
}


int main()
{
	list l1,l2;
	
	int ch,c;
	
	do
	{
		cout<<"Choose the operation to be performed";
	cout<<"\n1. Create\n2. Display\n3. Concat\n4. Merge\n5. Sort\n";
	cin>>ch;
	
	switch(ch)
	{
		case 1:
			l1.create();
			break;
		case 2:
			l1.display();
			break;
		case 3:
			cout<<"Creating list to be concatenated";
			l2.create();
			l1.concat(l2);
			l1.display();
			break;
		case 4:
			cout<<"Creating list to be merged";
			l2.create();
			l1.merge(l2);
			l1.display();
			break;
		case 5:
			l1.sort();
			l1.display();
			break;
		default:
			cout<<"Please enter a correct choice";
			
	}
	cout<<"Enter 1 to perform more operations and 0 to stop";
	cin>>c;
	}while(c);
	
	return 0;
}





























