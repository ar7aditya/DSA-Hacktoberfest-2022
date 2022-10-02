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
void reverseofll(node *head)
{	
	node *tail=NULL;
	while(head!=NULL)
	{
		node *ptr=head->next;
		head->next=tail;
		tail=head;
		head=ptr;
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
	cout<<endl;
	reverseofll(head);
	cout<<endl;
	printll(tail);
	return 0;
}
