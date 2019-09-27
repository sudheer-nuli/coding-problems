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
	void nthnode(struct node*,int);
};
void list::insert(int x)
{
	if (head==NULL)
	{
		struct node* head = (struct node*)malloc(sizeof(struct node));
		head->data = x;
		head->next = NULL;
		return;
	}
	struct node* nnode = (struct node*)malloc(sizeof(struct node));
	struct node*s;
	s = head;
	while (s->next != NULL)
	{
		s = s->next;
	}
	nnode->data = x;
	nnode->next = NULL;
	s->next = nnode;
}
void list::nthnode(struct node*head,int n)
{
	if (head==NULL)
	{
		cout << "no node exist";
		return;
	}
	struct node *first, *second;
	first = second = head;
	while (n >= 0)
	{
		if (first->next == NULL && n != 0)
		{
			cout << "not possible";
			return;
		}
		first = first->next;
		n--;
	}
	while (first != NULL)
	{
		first = first->next;
		second = second->next;
	}
	cout << "required node is:" << second->data;
}
int main()
{
	int i, n;
	list given;
	cout << "enter the list of elements and to exit enter -1:\n";
	cin >> i;
	while (i != -1)
	{
		given.insert(i);
		cin >> i;
	}
	cout << "enter the number which you want from last:\n";
	cin >> n;
    given.nthnode(given.head,n);
	_getch();
	return 0;
}