#include <iostream>

// making stack with Array
class ArrayStack
{
public:
	int top = -1;
	int st[10];

	void push(int x)
	{
		// we can only have elements from index 0-9
		if (top < 10)
		{
			top = top + 1;
			st[top] = x;
		}
		else
		{
			std::cout << "Size of Stack Exceeded" << std::endl;
		}
	}

	int top()
	{
		if (top == -1)
		{
			std::cout << "Stack is Empty" << std::endl;
		}
	}

	void pop()
	{
		if (top == -1)
		{
			top = top - 1;
		}
	}

	int size()
	{
		return top + 1;
	}
};

class Node
{
public:
	int data;
	Node* next;

public:
	Node(int data1, Node* next1)
	{
		data = data1;
		next = next1;
	}

public:
	Node(int data1)
	{
		data = data1;
		next = nullptr;
	}
};

class LLStack
{
public:
	Node* top;
	int size = 0;

	void push(int x)
	{
		Node* currentNode = new Node(x);
		currentNode->next = top;
		top = currentNode;
		size++;
	}

	void pop()
	{
		Node* currentNode = top;
		top = top->next;
		delete currentNode;
		size--;
	}

	int top()
	{
		return top->data;
	}

	int size()
	{
		return size;
	}
};

int main()
{
	return 0;
}