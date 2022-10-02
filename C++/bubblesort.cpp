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
int lengthofLL(node *head)
{
	 node *temp=head;
	 int count=0;

	 while(temp!=NULL)
	 {
	 	count++;
	 	temp=temp->next;
	 }
	 return count;
}
void bubblesort(node *head)
{
	for (int i = 0; i <= lengthofLL(head)-1; ++i)
	{	
		node *temp=head;
		for (int j = 0; j <= lengthofLL(head)-i-1; ++j)
		{
			if (temp->next->data<temp->data)
			{
				swap(temp->next->data,temp->data);
			}
			else
			{
				temp=temp->next;
			}
		}
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
	bubblesort(head);
	cout<<endl;
	printll(head);
	return 0;
}
