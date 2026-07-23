/*
==========================================================
DEPTH FIRST SEARCH (DFS) - C++ Interview Cheat Sheet
==========================================================

TIME COMPLEXITIES

Tree DFS
---------
Traversal                    O(N)

Graph DFS
----------
Traversal                    O(V + E)

Grid DFS
---------
Traversal                    O(R * C)

Recursive Space
---------------
Balanced Tree                O(log N)
Worst Tree                   O(N)
Graph                         O(V)
Grid                          O(R * C)

==========================================================
*/

#include <iostream>
#include <vector>
#include <stack>

///////////////////////////////////////////////////////////
// Binary Tree DFS (Recursive)
// Time: O(N)
// Space: O(H)
///////////////////////////////////////////////////////////

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* node)
{
    if (!node)
        return;

    std::cout << node->val << " ";      // Process

    preorder(node->left);

    preorder(node->right);
}

///////////////////////////////////////////////////////////
// Graph DFS (Recursive)
// Time: O(V + E)
// Space: O(V)
///////////////////////////////////////////////////////////

void dfsGraph(int node,
    const std::vector<std::vector<int>>& graph,
    std::vector<bool>& visited)
{
    visited[node] = true;

    std::cout << node << " ";

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
            dfsGraph(neighbor, graph, visited);
    }
}

///////////////////////////////////////////////////////////
// Graph DFS (Iterative)
// Time: O(V + E)
// Space: O(V)
///////////////////////////////////////////////////////////

void dfsIterative(int start,
    const std::vector<std::vector<int>>& graph)
{
    std::vector<bool> visited(graph.size(), false);

    std::stack<int> st;

    st.push(start);

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (visited[node])
            continue;

        visited[node] = true;

        std::cout << node << " ";

        // Reverse iteration preserves recursive traversal order.
        for (int i = static_cast<int>(graph[node].size()) - 1; i >= 0; --i)
        {
            int neighbor = graph[node][i];

            if (!visited[neighbor])
                st.push(neighbor);
        }
    }
}

///////////////////////////////////////////////////////////
// Grid DFS
// Time: O(R * C)
// Space: O(R * C) worst-case recursion
///////////////////////////////////////////////////////////

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void dfsGrid(int r,
    int c,
    std::vector<std::vector<char>>& grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    if (r < 0 || c < 0 || r >= rows || c >= cols)
        return;

    if (grid[r][c] == '0')
        return;

    grid[r][c] = '0'; // Mark visited

    for (int i = 0; i < 4; i++)
    {
        dfsGrid(r + dr[i], c + dc[i], grid);
    }
}

///////////////////////////////////////////////////////////
// Backtracking Template
///////////////////////////////////////////////////////////

void backtrack(std::vector<int>& nums,
    std::vector<int>& path,
    std::vector<bool>& used)
{
    if (path.size() == nums.size())
    {
        // Found one solution
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i])
            continue;

        used[i] = true;
        path.push_back(nums[i]);

        backtrack(nums, path, used);

        // Undo choice (backtrack)
        path.pop_back();
        used[i] = false;
    }
}

/*
==========================================================
INTERVIEW TIPS

✓ Trees don't need a visited array.

✓ Graphs almost always do.

✓ Mark visited BEFORE recursion.

✓ Pass large containers by const reference (&).

✓ Know both recursive and iterative DFS.

✓ Always identify the base case first.

✓ Grid DFS usually needs:
    - boundary check
    - visited marking
    - direction arrays

✓ DFS is the foundation for:
    - Backtracking
    - Flood Fill
    - Number of Islands
    - Connected Components
    - Cycle Detection
    - Topological Sort
    - Tree Traversals
    - Maze/Search problems

==========================================================
*/