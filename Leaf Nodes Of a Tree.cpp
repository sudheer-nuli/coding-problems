#include <iostream> 
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std; 
struct node
{
	int data;
	struct node *left, *right;
};
void printLeafNodes(node *root)
{
	if (root==NULL)
	{
		return;
	}
	if (root->left==NULL && root->right==NULL)
	{
		cout << root->data << " ";
		return;
	}
	if (root->left != NULL)
	{
		printLeafNodes(root->left);
	}
	if (root->right != NULL)
	{
		printLeafNodes(root->right);
	}
		
}
node* newnode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
int main()
{
	node *root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->right->left = newnode(5);
	root->right->right = newnode(6);
	root->right->left->left = newnode(7);
	root->right->left->right = newnode(8);
	root->right->right->left = newnode(9);
	root->right->right->right = newnode(10);
	printLeafNodes(root);
	_getch();
	return 0;
	
}