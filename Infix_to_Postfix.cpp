#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
using namespace std;
int precedence(char op) {
	if (op == '+' || op == '-')
	{
		return 1;
	}	
	if (op == '*' || op == '/')
	{
		return 2;
	}
	return 0;
}
int apply(int a, int b, char op)
{
	switch (op)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
}
struct node
{
	int data;
	struct node* next;
};
struct nodech
{
	char data;
	struct nodech* next;
};
int find(char[]);
class operator_stack
{
public:
	struct nodech* top;
	operator_stack()
	{
		top = '\0';
	}
	void push(char);
	void pop();
	char peek();
};
void operator_stack::push(char x)
{
	struct nodech* temp;
	temp = (struct nodech*)malloc(sizeof(struct nodech));
	temp->data = x;
	temp->next = top;
	top = temp;
}
void operator_stack::pop()
{
	struct nodech* temp;
	if (top == '\0')
	{
		cout << "\n expression_Stack Underflow";
		return;
	}
	else
	{
		temp = top;
		top = top->next;
		temp->next = '\0';
	}
}
char operator_stack::peek()
{
	if (top != '\0')
	{
		return top->data;
	}
	else
	{
		return '\0';
	}
}
class integer_stack
{
public:
	struct node* top;
	integer_stack()
	{
		top = NULL;
	}
	void push(int);
	void pop();
	int peek();
};
void integer_stack::push(int x)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = top;
	top = temp;
}
void integer_stack::pop()
{
	struct node* temp;
	if (top == NULL)
	{
		cout << "\n integer_Stack Underflow";
		return;
	}
	else
	{
		temp = top;
		top = top->next;
		temp->next = NULL;
	}
}
int integer_stack::peek()
{
	if (top != NULL)
	{
		return top->data;
	}
	else
	{
		return -1;
	}
}
int find(char expression[])
{
	integer_stack numbers;
	operator_stack operators;
	int i;
	for (i = 0; i< strlen(expression); i++)
	{
		if (expression[i] == ' ')
		{
			continue;
		}
		else if (expression[i] == '(')
		{
			operators.push(expression[i]);
		}
		else if (isdigit(expression[i]))
		{
			int val = 0;
			while (i < strlen( expression) && isdigit(expression[i]))
			{	
				val = (val * 10) + (expression[i]-'0');
				i++;
			}
			numbers.push(val);
		}
		else if (expression[i] == ')')
		{
			while (operators.peek()!='\0' && operators.peek()!= '(' && numbers.peek()!=-1 )
			{
				int val2 = numbers.peek();
				numbers.pop();
				int val1 = numbers.peek();
				numbers.pop();
				char op = operators.peek();
				operators.pop();
				numbers.push(apply(val1, val2, op));
			}
			operators.pop();
		}
		else
		{
			while (operators.peek() != '\0' && precedence(operators.peek()) > precedence(expression[i]) && numbers.peek() != -1)
			{
				int val2 = numbers.peek();
				numbers.pop();
				int val1 = numbers.peek();
				numbers.pop();
				char op = operators.peek();
				operators.pop();
				numbers.push(apply(val1, val2, op));
			}
			operators.push(expression[i]);
		}
	}
	while (operators.peek() !='\0'&& numbers.peek() != -1)
	{
		if (operators.peek() == '(' ||operators.peek()== ')')
		{
			operators.pop();
		}
		else
		{
			int val2 = numbers.peek();
			numbers.pop();
			int val1 = numbers.peek();
			numbers.pop();
			char op = operators.peek();
			operators.pop();
			numbers.push(apply(val1, val2, op));
		}
	}
	return numbers.peek();
} 
int main()
{
	int output;
	char input[] = "2 * (3 * ( 1 + 2 ) + 3)";
	output=find(input);
	cout << "\n output is:" << output;
	_getch();
	return 0;
}