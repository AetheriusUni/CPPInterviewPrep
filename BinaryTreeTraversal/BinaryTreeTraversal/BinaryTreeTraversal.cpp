#include <iostream>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

	Node(int val)
	{
		data = val;
		left = right = nullptr;
	}
};

void inOrderRecursive(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	inOrderRecursive(node->left);
	std::cout << node->data << " ";
	inOrderRecursive(node->right);
}

void preOrderRecursive(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	std::cout << node->data << " ";
	inOrderRecursive(node->left);
	inOrderRecursive(node->right);
}

void postOrderRecursive(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	inOrderRecursive(node->left);
	inOrderRecursive(node->right);
	std::cout << node->data << " ";
}

int main()
{
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(5);
	return 0;
}