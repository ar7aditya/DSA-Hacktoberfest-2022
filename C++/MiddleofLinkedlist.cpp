#include<iostream>
using namespace std;
class node{
public: 
	int data;
	node *next;

	node(int d)
	{
		data=d;
		next=NULL;
	}
};

void insertatLast(node *&head, node *&tail, int d)
{	
	node *n =new node(d);
	if (head==NULL)
	{
		head=n;
		tail=n;
	}
	else
	{
		tail->next=n;
		tail=n;
	}
}
int middleofthell(node *head, int n)
{
	node *temp=head;
	node *temp1=head;
	if (n%2!=0)
	{
		while(temp1->next!=NULL)
		{
			temp=temp->next;
			temp1=temp1->next->next;
		}
		return temp->data;
	}
	else
	{
		while(temp1->next!=NULL and temp1->next->next!=NULL)
		{
			temp=temp->next;
			temp1=temp1->next->next;
		}
		return temp->data;
	}
	
}
void printll(node *head)
{
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{	
	node *head=NULL;
	node *tail=NULL;
	int n;
	cin>>n;
	int d;
	for (int i = 0; i < n; ++i)
	{
		cin>>d;
		insertatLast(head, tail, d);
	}
	
	printll(head);
	
	cout<<endl<<middleofthell(head,n);
	return 0;
}
