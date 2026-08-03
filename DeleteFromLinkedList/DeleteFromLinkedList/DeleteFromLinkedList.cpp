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

Node* deleteKthElement(Node* head, int k)
{
	if (head == nullptr)
	{
		return nullptr;
	}

	Node* currentNode = head;

	// we want to delete the first element AKA the head
	if (k == 1)
	{
		head = head->next;
		delete currentNode;
		return head;
	}

	Node* previousNode = nullptr;
	int elementNum = 1;
	// travese up to the kth element
	while (currentNode != nullptr)
	{
		if (elementNum == k)
		{
			// make the previous node point to kth element's next node
			previousNode->next = currentNode->next;
			// delete the kth element
			delete currentNode;
			break;
		}
		// previousNode stores the node we just looked at
		previousNode = currentNode;
		// look at the next node to be the current node of the next iteration
		currentNode = currentNode->next;
		// keep track of which element we're looking at (1 indexed)
		elementNum++;
	}

	return head;
}

Node* deleteVal(Node* head, int val)
{
	if (head == nullptr)
	{
		return nullptr;
	}

	Node* currentNode = head;

	if (head->data == val)
	{
		head = head->next;
		delete currentNode;
		return head;
	}

	Node* previousNode = nullptr;

	while (currentNode != nullptr)
	{
		if (currentNode->data == val)
		{
			previousNode->next = currentNode->next;
		}
		previousNode = currentNode;
		currentNode = currentNode->next;
	}

	return head;
}

void printLL(Node* head)
{
	if (head == nullptr)
	{
		std::cout << "Linked List Empty" << std::endl;
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

// comments of values in head are for if all of these are ran in order
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

	// 5 -- 8 is removed since it's the second element
	int k = 2;
	head = deleteKthElement(head, k);
	printLL(head);

	// empty since we removed 5
	int val = 5;
	head = deleteVal(head, val);
	printLL(head);

	return 0;
}