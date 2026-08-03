#include <iostream>
#include <vector>

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

void printLL(Node* head)
{
	if (head == nullptr)
	{
		return;
	}

	Node* currentNode = head;

	while (currentNode != nullptr)
	{
		std::cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}
	std::cout << std::endl;

	return;
}

Node* convertArrToLL(std::vector<int> arr)
{
	Node* head = new Node(arr[0]);
	Node* currentNode = head;

	for (int i = 1; i < arr.size(); i++)
	{
		Node* nextNode = new Node(arr[i]);
		currentNode->next = nextNode;
		currentNode = nextNode;
	}

	return head;
}

Node* insertHead(Node* head, int val)
{
	/*
	Node* newHead = new Node(val, head);
	head = newHead;
	return head;
	*/
	return new Node(val, head);
}

Node* insertTail(Node* head, int val)
{
	if (head == nullptr)
	{
		return new Node(val);
	}

	// traverse the LL until we get to the tail
	Node* currentNode = head;

	while (currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
	}

	// now that the currentNode is the tail
	Node* newTail = new Node(val);
	currentNode->next = newTail;
	return head;
}

Node* insertValueAtK(Node* head, int val, int k)
{
	if (head == nullptr)
	{
		if (k == 1)
		{
			return new Node(val);
		}
		else
		{
			return nullptr;
		}
	}

	Node* currentNode = head;
	Node* previousNode = nullptr;
	
	int elementNum = 1;

	while (currentNode != nullptr)
	{
		if (elementNum == k)
		{
			Node* kthValue = new Node(val, currentNode);
			previousNode->next = kthValue;
			break;
		}
		previousNode = currentNode;
		currentNode = currentNode->next;
		elementNum++;
	}
	return head;
}

Node* insertBeforeValue(Node* head, int val, int targetVal)
{
	return head;
}


int main()
{
	std::vector<int> arr = { 12, 5, 8, 7, 4 };
	Node* head = convertArrToLL(arr);
	printLL(head);

	int newHead = 3;
	head = insertHead(head, newHead);
	printLL(head);

	int newTail = 10;
	head = insertTail(head, newTail);
	printLL(head);

	int k = 4;
	int kVal = 33;
	head = insertValueAtK(head, kVal, k);
	printLL(head);

	int valBeforeTarget = 17;
	int target = 8;
	head = insertBeforeValue(head, valBeforeTarget, target);
	printLL(head);

	return 0;
}