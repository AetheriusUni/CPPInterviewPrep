#include <iostream>

// push, pop, top, size are all O(1)
class ArrayQueue
{
public:
	int start = -1;
	int end = -1;
	static const int size = 10;
	int q[size];
	int currentSize = 0;

	void push(int x)
	{
		if (currentSize == size)
		{
			std::cout << "Queue is full" << std::endl;
		}

		if (currentSize == 0)
		{
			start = 0;
			end = 0;
		}
		else
		{
			end = (end + 1) % size;
		}

		q[end] = x;
		currentSize++;
	}

	void pop()
	{
		if (currentSize == 0)
		{
			std::cout << "Queue is empty" << std::endl;
		}

		if (currentSize == 1)
		{
			start = -1;
			end = -1;
		}
		else
		{
			start = (start + 1) % size;
		}
		
		currentSize--;
	}

	int top()
	{
		if (currentSize == 0)
		{
			return -1;
		}
		return q[start];
	}

	int size()
	{
		return currentSize;
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

class LLQueue
{
public:
	Node* start;
	Node* end;
	int size = 0;

	void push(int x)
	{
		Node* newNode = new Node(x);

		if (start == nullptr)
		{
			start = end = newNode;
		}
		else
		{
			end->next = newNode;
		}
		size++;
	}

	void pop()
	{
		if (start == nullptr)
		{
			std::cout << "Queue is empty" << std::endl;
		}

		Node* temp = start;
		start = start->next;
		delete temp;
		size--;
	}

	int top()
	{
		if (start == nullptr)
		{
			return NULL;
		}
		return start->data;
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