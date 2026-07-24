#include <iostream>
#include <vector>
#include <stack>
#include <climits>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}
};

/*
=========================================================
RECURSIVE INORDER
---------------------------------------------------------
Order:
Left -> Root -> Right

Time:  O(n)
Space: O(h) recursion std::stack

Balanced Tree: O(log n)
Worst Case:    O(n)
=========================================================
*/
void inorderRecursive(TreeNode* root)
{
    if (!root)
        return;

    inorderRecursive(root->left);

    std::cout << root->val << " ";

    inorderRecursive(root->right);
}

/*
=========================================================
ITERATIVE INORDER
---------------------------------------------------------
Uses explicit std::stack.

Time:  O(n)
Space: O(h)

Interview favorite because recursion isn't allowed.
=========================================================
*/
void inorderIterative(TreeNode* root)
{
    // stack of TreeNode
    std::stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr || !st.empty())
    {
        // Go to leftmost node so long as the current node isn't null
        while (curr)
        {
            // add this node to the stack
            st.push(curr);
            // move to this node's left node
            curr = curr->left;
        }

        // at this point the current node is null, the prior node had no left children
        // store the value at the top of the stack
        curr = st.top();
        // then pop it
        st.pop();
        // and print that value
        std::cout << curr->val << " ";
        // then check the right subtree
        curr = curr->right;
    }
}

/*
=========================================================
REVERSE INORDER
---------------------------------------------------------
Right -> Root -> Left

Produces descending order in BST.

Time: O(n)
Space: O(h)
=========================================================
*/
void reverseInorder(TreeNode* root)
{
    if (!root)
        return;

    reverseInorder(root->right);

    std::cout << root->val << " ";

    reverseInorder(root->left);
}

/*
=========================================================
COLLECT SORTED VALUES
---------------------------------------------------------
Classic interview helper.

Time: O(n)
Space: O(n)
=========================================================
*/
void inorderVector(TreeNode* root, std::vector<int>& result)
{
    if (!root)
        return;

    inorderVector(root->left, result);

    result.push_back(root->val);

    inorderVector(root->right, result);
}

/*
=========================================================
VALIDATE BST
---------------------------------------------------------
Inorder traversal of a BST must be strictly increasing.

Time: O(n)
Space: O(h)

Interview classic.
=========================================================
*/
bool validate(TreeNode* root, long long& prev)
{
    if (!root)
        return true;

    if (!validate(root->left, prev))
        return false;

    if (root->val <= prev)
        return false;

    prev = root->val;

    return validate(root->right, prev);
}

bool isValidBST(TreeNode* root)
{
    long long prev = LLONG_MIN;
    return validate(root, prev);
}

/*
=========================================================
KTH SMALLEST
---------------------------------------------------------
Stop traversal once kth node is visited.

Time:
Worst: O(n)

Balanced:
Often O(h + k)

Space: O(h)
=========================================================
*/
void kthHelper(TreeNode* root, int& k, int& answer)
{
    if (!root)
        return;

    kthHelper(root->left, k, answer);

    if (--k == 0)
    {
        answer = root->val;
        return;
    }

    kthHelper(root->right, k, answer);
}

int kthSmallest(TreeNode* root, int k)
{
    int answer = -1;
    kthHelper(root, k, answer);
    return answer;
}

/*
=========================================================
MORRIS INORDER (Advanced)
---------------------------------------------------------
Time: O(n)
Space: O(1)

Idea:
Temporarily thread the tree by linking each node's inorder
predecessor to the current node. This avoids both recursion
and an explicit std::stack. Restore pointers before moving on.

Rarely required, but a strong differentiator in interviews.
=========================================================
*/

/*
=========================================================
INTERVIEW TAKEAWAYS

✓ Inorder = Left Root Right

✓ Recursive solution is the simplest.

✓ Iterative std::stack solution is frequently requested.

✓ Inorder on a BST gives values in ascending order.

✓ Reverse inorder gives descending order.

✓ Validate BST:
    Previous visited value must always increase.

✓ kth Smallest:
    Count nodes during inorder.

✓ Space:
    O(h), where h is tree height.

✓ Be ready to explain WHY inorder is sorted only for BSTs.

✓ Always discuss edge cases:
    - nullptr
    - Single node
    - Skewed tree
    - Balanced tree
    - Duplicate values (clarify BST definition)
=========================================================
*/