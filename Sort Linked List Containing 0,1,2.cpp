#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
class list
{
public:
	struct node* head;
	list()
	{
		head = NULL;
	}
	void insert(int);
	void join(struct node*,struct node*,struct node*,struct node**);
	void display(struct node *);
};
void list::insert(int x)
{
	if (head == NULL)
	{
		head = (struct node*)malloc(sizeof(struct node));
		head->data = x;
		head->next = NULL;
	}
	else
	{
		struct node* nnode = (struct node*)malloc(sizeof(struct node));
		nnode->data = x;
		nnode->next = NULL;
		nnode->next = head;
		head = nnode;
	}
}
void list::join(struct node* zero, struct node* one, struct node* two,struct node** result)
{
	
		(*result)->next = zero;
		while ((*result)->next != NULL)
		{
			(*result) = (*result)->next;
		}
		(*result)->next = one;
		while ((*result)->next != NULL)
		{
			(*result) = (*result)->next;
		}
		(*result)->next = two;
}
void list::display(struct node* link)
{
	while (link!= NULL)
	{
		cout << link->data;
		link = link->next;
	}
	return;
}
int main()
{
	list zero,one,two;
	int i;
	struct node* solution = (struct node*)malloc(sizeof(struct node));
	struct node* result = (struct node*)malloc(sizeof(struct node));
	solution = result;
	cout << "enter elements 0,1,2 and -1 to exit:\n";
	cin >> i;
	while (i != -1)
	{
		if (i == 0)
		{
			zero.insert(i);
		}
		if (i == 1)
		{
			one.insert(i);
		}
		if (i == 2)
		{
			two.insert(i);
		}
		cin >> i;
	}
	zero.join(zero.head, one.head, two.head,&result);
	cout << "output is:\n";
	zero.display(solution->next);
	_getch();
	return 0;
}