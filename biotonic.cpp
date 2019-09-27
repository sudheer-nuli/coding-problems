#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct node
{
	int data;
	struct	node *next;
};

class s_llist
{
public:
	struct node* start;
	s_llist()
	{
		start = NULL;
	}
	void insert(int x);
	//node *arrange(struct node *,struct node *);
	void display(struct node *);
	void sort_b(struct node ** head, struct node *, struct node * junc, struct node ** result);
	
};
void s_llist::insert(int x)
{
	if (start == NULL)
	{
		start = (struct node *) malloc(sizeof(struct node));
		start->data = x;
		start->next = NULL;
	}
	else
	{
		struct node* nnode = (struct node*)malloc(sizeof(struct node));
		struct node *s;
		s = start;
		while (s->next != NULL)
		{
			s = s->next;
		}
		nnode->data = x;
		nnode->next = NULL;
		s->next = nnode;
	}
}
/* node* s_llist::arrange(struct node *ptr,struct node *prev)
{
	node *temp;
	if (ptr->next== NULL)
	{
		ptr->next = prev;
		return ptr;
	}
	else
	{
		temp = arrange(ptr->next, ptr);
		ptr->next = prev;
		return temp;
	}
}*/
void s_llist::display(struct node *start)
{
	if (start == NULL)
	{
		return;
	}
	else
	{
		cout << start->data<<"->";
	}
	display(start->next);
}


void s_llist::sort_b(struct node ** head, struct node * current, struct node * junc, struct node ** result) {
	if (current == NULL) {
		(*result)->next = *head;
		return;
	}
	node * dPointer = current->next;
	if (junc != NULL) {
		while ((*head)->data <= current->data) {
			(*result)->next = *head;
			*result = (*result)->next;
			*head = (*head)->next;
		}
		(*result)->next = current;
		*result = (*result)->next;
	}
	if (current->next != NULL && current->data > current->next->data && junc== NULL) {
		junc = (current ->next);
		dPointer = current->next;
		current->next = NULL;
	}
	sort_b(head, dPointer, junc, result);
}
int main()

{
	s_llist given;
	struct node* newhead= (struct node*)malloc(sizeof(struct node)),*solution= (struct node*)malloc(sizeof(struct node));
	int i,n = 11;
	int elem[] = { 1, 2, 6,9,10,1,3,4,5,7,8 };
	cout << "enter elements:\n";
	for (i = 0; i < n; i++)
	{
		given.insert(elem[i]);
	}
	given.display(given.start);
	//newhead = given.arrange(given.start, NULL);
	cout << endl;
	//given.display(newhead);
	node * result = (struct node *) malloc(sizeof(struct node));
	node * solutio = result;
	given.sort_b(&given.start, given.start, NULL, &result);
	//solution = given.sort(given.start);
	given.display(solutio->next);
	_getch();
	return 0;
}