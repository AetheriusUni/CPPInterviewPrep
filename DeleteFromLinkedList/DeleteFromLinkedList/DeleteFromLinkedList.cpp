/*
technically DeleteFromLinkedList and InsertToLinkedList functionality could be added on to LinkedListBasics
I just separated them out to different files so I could practice typing out the Linked List basic functionality
*/


#include <iostream>
#include <vector>

class Node
{
public:
	int data;
	Node* next;

public:
	// create node with a data and a next
	Node (int data1, Node* next1)
	{
		data = data1;
		next = next1;
	}

public:
	// create node with a data and a next which points to nullptr
	Node (int data1)
	{
		data = data1;
		next = nullptr;
	}
};

Node* convertArrToLL(std::vector<int>& arr)
{
	Node* head = new Node(arr[0], nullptr);
	Node* currentNode = head;

	for (int i = 1; i < arr.size(); i++)
	{
		Node* nextNode = new Node(arr[i]);
		currentNode->next = nextNode;
		currentNode = currentNode->next;
	}
	return head;
}

Node* deleteHead(Node* head)
{
	if (head == nullptr)
	{
		return head;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
	return head;
}

Node* deleteTail(Node* head)
{
	// if the head is null there's nothing to delete
	// if the next is already pointing to null
	// there is only one element in the linked list
	// so the head is both the head and tail of the linked list
	if (head == nullptr || head->next == nullptr)
	{
		return nullptr;
	}

	Node* currentNode = head;
	// until the next node's next is null
	while (currentNode->next->next != nullptr)
	{
		// traverse through the linked list
		// currentNode = nextNode
		currentNode = currentNode->next;
	}

	// since we are at the second to the last node
	// we can delete the next node AKA the last node AKA the tail
	delete currentNode->next;
	// then have our new tail's next be null
	currentNode->next = nullptr;

	return head;
}

void printLL(Node* head)
{
	if (head == nullptr)
	{
		return;
	}
	Node* currentNode = head;

	while (currentNode)
	{
		std::cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> arr = { 12, 5, 8, 7 };
	// 12 5 8 7
	Node* head = convertArrToLL(arr);
	printLL(head);

	// 5 8 7 -- 12 is removed since it's the first element
	head = deleteHead(head);
	printLL(head);
	
	// 5 8 -- 7 is removed since it's the last element
	head = deleteTail(head);
	printLL(head);
	return 0;
}