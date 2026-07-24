#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

/*
============================================================
POSTORDER TRAVERSAL CHEAT SHEET

Traversal Order:
    Left -> Right -> Root

Time Complexity:
    Recursive: O(n)
    Iterative (1 std::stack): O(n)
    Iterative (2 stacks): O(n)

Space Complexity:
    Recursive: O(h)
    Iterative (1 std::stack): O(h)
    Iterative (2 stacks): O(n)

Interview Tip:
Use postorder whenever a node's answer depends on its children.
============================================================
*/

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}
};

/////////////////////////////////////////////////////////////
// Recursive Postorder (Most Common)
// Time : O(n)
// Space: O(h)
/////////////////////////////////////////////////////////////

void postorder(TreeNode* root)
{
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);

    std::cout << root->val << " ";
}

/////////////////////////////////////////////////////////////
// Height of Binary Tree
// Time : O(n)
// Space: O(h)
//
// Parent depends on child heights.
// Classic postorder problem.
/////////////////////////////////////////////////////////////

int height(TreeNode* root)
{
    if (!root)
        return 0;

    return 1 + std::max(height(root->left),
        height(root->right));
}

/////////////////////////////////////////////////////////////
// Sum of Subtree
// Time : O(n)
// Space: O(h)
//
// Parent uses sums from children.
/////////////////////////////////////////////////////////////

int subtreeSum(TreeNode* root)
{
    if (!root)
        return 0;

    int left = subtreeSum(root->left);
    int right = subtreeSum(root->right);

    return left + right + root->val;
}

/////////////////////////////////////////////////////////////
// Delete Entire Tree
// Time : O(n)
// Space: O(h)
//
// Delete children BEFORE parent.
/////////////////////////////////////////////////////////////

void destroy(TreeNode* root)
{
    if (!root)
        return;

    destroy(root->left);
    destroy(root->right);

    delete root;
}

/////////////////////////////////////////////////////////////
// Iterative Postorder (One Stack)
// Time : O(n)
// Space: O(h)
//
// Harder interview implementation.
// Remember lastVisited to know when a right subtree
// has already been processed.
/////////////////////////////////////////////////////////////

std::vector<int> postorderIterative(TreeNode* root)
{
    std::vector<int> result;

    std::stack<TreeNode*> st;
    TreeNode* current = root;
    TreeNode* lastVisited = nullptr;

    // if the node is not null or stack is not empty
    while (current || !st.empty())
    {
        // so long as the current node is not null
        while (current)
        {
            // push that node to the stack
            st.push(current);
            // move to the left node
            current = current->left;
        }

        // the current node is now null, there was no left node
        // peek at the node at the top of the stack
        TreeNode* peek = st.top();

        // if there's a node to the right of the node at the top of the stack and we didn't already process that node's subtree
        if (peek->right && lastVisited != peek->right)
        {
            // make that node our current node so we can process it
            current = peek->right;
        }
        // if there's no node to the right or if the node to the right has already been processed
        else
        {
            // push the node at the top of the stack to the result vector
            result.push_back(peek->val);
            // set the last visited node to be the one we just pushed
            lastVisited = peek;
            // pop the top node since it's been processed here
            st.pop();
        }
    }

    return result;
}

/////////////////////////////////////////////////////////////
// Iterative Postorder (Two Stacks)
// Time : O(n)
// Space: O(n)
//
// Easier to remember than the one-std::stack version.
/////////////////////////////////////////////////////////////

std::vector<int> postorderTwoStacks(TreeNode* root)
{
    std::vector<int> result;

    if (!root)
        return result;

    std::stack<TreeNode*> s1;
    std::stack<TreeNode*> s2;

    s1.push(root);

    while (!s1.empty())
    {
        TreeNode* node = s1.top();
        s1.pop();

        s2.push(node);

        if (node->left)
            s1.push(node->left);

        if (node->right)
            s1.push(node->right);
    }

    while (!s2.empty())
    {
        result.push_back(s2.top()->val);
        s2.pop();
    }

    return result;
}

/*
============================================================
Interview Recognition Guide

Need child information first?
    -> Postorder

Examples:
✔ Height
✔ Diameter
✔ Balanced Tree
✔ Delete Tree
✔ Subtree Sum
✔ Evaluate Expression Tree
✔ Dynamic Programming on Trees

Traversal Summary

Preorder:
    Root Left Right
    Build / Copy / Serialize

Inorder:
    Left Root Right
    BST problems

Postorder:
    Left Right Root
    Aggregate / Cleanup / DP

Complexities

Recursive:
    Time  O(n)
    Space O(h)

Balanced Tree:
    O(log n) recursion depth

Worst Case:
    O(n) recursion depth

Common Mistakes

✘ Visit node before recursion
✘ Delete parent before children
✘ Forget nullptr base case
✘ Claim recursive space is O(1)

Golden Rule:
If the parent cannot compute its answer until both children are finished,
postorder traversal is usually the correct traversal.
============================================================
*/