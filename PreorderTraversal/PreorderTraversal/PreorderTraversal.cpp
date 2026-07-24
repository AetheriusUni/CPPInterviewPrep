#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

//==============================================================
// Binary Tree Node
//==============================================================
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x)
		: val(x), left(nullptr), right(nullptr) {}
};

//==============================================================
// RECURSIVE PREORDER
//
// Order:
// Root -> Left -> Right
//
// Time:
// O(n)
//
// Space:
// O(h)
// h = tree height
//
// Balanced Tree:
// O(log n)
//
// Worst Case:
// O(n)
//==============================================================
void preorderRecursive(TreeNode* root)
{
	if (root == nullptr)
		return;

	std::cout << root->val << " ";     // Visit root
	preorderRecursive(root->left);     // Traverse left
	preorderRecursive(root->right);    // Traverse right
}

//==============================================================
// ITERATIVE PREORDER
//
// Uses a std::stack.
//
// IMPORTANT:
//
// Push RIGHT first!
// Push LEFT second!
//
// Because std::stack is LIFO.
//
// Time:
// O(n)
//
// Space:
// O(h)
//==============================================================
void preorderIterative(TreeNode* root)
{
	if (!root)
		return;

	std::stack<TreeNode*> st;
	st.push(root);

	while (!st.empty())
	{
		TreeNode* node = st.top();
		st.pop();

		std::cout << node->val << " ";      // Visit node

		// Push right FIRST
		if (node->right)
			st.push(node->right);

		// Push left SECOND
		if (node->left)
			st.push(node->left);
	}
}

// TO RETURN THE PATH OF TRAVERSAL
std::vector<int> preorderIterativeReturn(TreeNode* root)
{
	std::vector<int> preorder;
	if (!root)
		return preorder;


	std::stack<TreeNode*> st;
	// push current node into stack
	st.push(root);

	while (!st.empty())
	{
		TreeNode* node = st.top();
		st.pop();

		preorder.push_back(node->val);

		// Push right FIRST
		if (node->right)
			st.push(node->right);

		// Push left SECOND
		if (node->left)
			st.push(node->left);
	}
	return preorder;
}

//==============================================================
// STORE PREORDER IN VECTOR
//
// Very common in LeetCode.
//
// Time:
// O(n)
//
// Space:
// O(h) recursion
//==============================================================
void preorderVector(TreeNode* root,
	std::vector<int>& result)
{
	if (!root)
		return;

	result.push_back(root->val);

	preorderVector(root->left, result);
	preorderVector(root->right, result);
}

//==============================================================
// COUNT NODES USING PREORDER
//
// Shows preorder can perform work while traversing.
//
// Time:
// O(n)
//==============================================================
int countNodes(TreeNode* root)
{
	if (!root)
		return 0;

	return 1 +
		countNodes(root->left) +
		countNodes(root->right);
}

//==============================================================
// SEARCH USING PREORDER
//
// Stops immediately when target is found.
//
// Worst:
// O(n)
//
// Best:
// O(1)
//==============================================================
bool contains(TreeNode* root, int target)
{
	if (!root)
		return false;

	if (root->val == target)
		return true;

	return contains(root->left, target) ||
		contains(root->right, target);
}

//==============================================================
// TREE HEIGHT
//
// Common recursion interview question.
//
// Time:
// O(n)
//
// Space:
// O(h)
//==============================================================
int height(TreeNode* root)
{
	if (!root)
		return 0;

	return 1 + std::max(height(root->left),
		height(root->right));
}

//==============================================================
// INTERVIEW NOTES
//
// Traversal Orders:
//
// Preorder:
// Root Left Right
//
// Inorder:
// Left Root Right
//
// Postorder:
// Left Right Root
//
// Level Order:
// BFS (Queue)
//
//--------------------------------------------------------------
//
// Recursive DFS Template:
//
// if (!node)
//     return;
//
// process(node);
//
// dfs(node->left);
//
// dfs(node->right);
//
//--------------------------------------------------------------
//
// Iterative DFS:
//
// std::stack<TreeNode*> st;
//
// push(root);
//
// while (!st.empty())
// {
//     node = st.top();
//     st.pop();
//
//     process(node);
//
//     // Push RIGHT first
//     if (node->right)
//         st.push(node->right);
//
//     // Push LEFT second
//     if (node->left)
//         st.push(node->left);
// }
//
//--------------------------------------------------------------
//
// Interview Tips:
//
// ✓ Always check nullptr.
//
// ✓ Recursive preorder is usually the cleanest solution.
//
// ✓ Know how to convert recursion to an explicit std::stack.
//
// ✓ Explain why recursion uses O(h) space.
//
// ✓ Mention worst case is a skewed tree.
//
// ✓ Push RIGHT before LEFT in iterative traversal.
//
// ✓ Preorder is ideal when the parent must be processed before
//   its children (serialization, copying, DFS, directory trees).
//
// ✓ Recursive calls naturally backtrack after exploring a
//   subtree, which is why preorder is a depth-first traversal.
//
//==============================================================