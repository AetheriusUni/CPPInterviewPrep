#include <iostream>
#include <vector>

// contains data and next
class Node {
public:
	int data;
	Node* next;

public:
	// constructor with data and next
	Node(int data1, Node* next1)
	{
		data = data1;
		next = next1;
	}

public:
	// constructer for node where next is always nullptr
	Node(int data1)
	{
		data = data1;
		next = nullptr;
	}
};

// converts a vector to a linked list
// O(n) since we go through every element once
Node* convertArr2LL(std::vector<int>& arr)
{
	// always have head at the start
	Node* head = new Node(arr[0]);
	// keep track of the current node
	Node* currentNode = head;
	// for each of the elements in the array after the initial head value
	for (int i = 1; i < arr.size(); i++)
	{
		// store the next node
		Node* nextNode = new Node(arr[i]);
		// have this currentNode's next now point to the nextNode
		currentNode->next = nextNode;
		// now that currentNode->next is the new end of the list
		// our current node for the next iteration will be this
		currentNode = currentNode->next;
	}
	return head;
}

// get length of linked list
// O(n) since we go through each element once
int lengthOfLL(Node* head)
{
	int count = 0;
	Node* currentNode = head;
	// count every element until currentNode becomes nullptr AKA end of list
	while (currentNode)
	{
		currentNode = currentNode->next;
		count++;
	}
	return count;
}

// find value in linked list, return 1 if found, 0 if not
// O(n) worst case, O(1) best case, amortized O(n/2)
int findInLL(Node* head, int target)
{
	int count = 0;
	Node* currentNode = head;
	// go through each element until
	while (currentNode)
	{
		// the target is found
		if (currentNode->data == target)
		{
			// return 1 which is true
			return 1;
		}
		currentNode = currentNode->next;
	}
	// if target is not found we return 0 which is false
	return 0;
}

int main()
{
	std::vector<int> arr = { 2, 5, 8, 7 };
	
	Node* y = new Node(arr[0], nullptr);
	std::cout << y->data;
	std::cout << y->next;
	// effectively the same thing as y, just constructed differently
	Node* z = new Node(arr[0]);

	Node* convertedArr = convertArr2LL(arr);
	Node* currentNode = convertedArr;
	// linked list traversal
	// print every element until currentNode becomes nullptr AKA end of list
	// O(n) since we go through every element once
	while (currentNode)
	{
		std::cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}

	int target = 5;
	int searchedLL = findInLL(convertedArr, target);

	return 0;
}