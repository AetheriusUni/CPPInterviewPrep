#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

/*
==========================================================
Breadth First Search (BFS) Cheat Sheet
==========================================================

WHEN TO USE:
-------------
✔ Shortest path in an UNWEIGHTED graph
✔ Minimum number of moves
✔ Level-order traversal
✔ Multi-source spread (fire, infection, rotten oranges)
✔ Grid traversal (4 or 8 directions)

CORE IDEA:
-----------
Explore nodes one "layer" at a time using a std::queue.

Time Complexity:
----------------
Adjacency List:
    O(V + E)

Adjacency Matrix:
    O(V²)

Space:
------
std::queue + visited:
    O(V)

Interview Tip:
--------------
Always mark nodes as visited WHEN ENQUEUING,
not when dequeuing, to avoid duplicates.
*/

////////////////////////////////////////////////////////////
// Standard Graph BFS
////////////////////////////////////////////////////////////
void bfs(const std::vector<std::vector<int>>& graph, int start)
{
    int n = graph.size();

    std::vector<bool> visited(n, false);
    std::queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())             // O(V)
    {
        int node = q.front();      // O(1)
        q.pop();                   // O(1)

        std::cout << node << " ";

        for (int neighbor : graph[node])   // Total O(E)
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

////////////////////////////////////////////////////////////
// BFS Shortest Distance
////////////////////////////////////////////////////////////
std::vector<int> shortestDistance(const std::vector<std::vector<int>>& graph,
    int start)
{
    int n = graph.size();

    std::vector<int> dist(n, -1);

    std::queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int next : graph[node])
        {
            if (dist[next] == -1)
            {
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }

    return dist;
}

////////////////////////////////////////////////////////////
// BFS with Parent Tracking
////////////////////////////////////////////////////////////
std::vector<int> shortestPath(const std::vector<std::vector<int>>& graph,
    int start,
    int target)
{
    int n = graph.size();

    std::vector<int> parent(n, -1);
    std::vector<bool> visited(n, false);

    std::queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == target)
            break;

        for (int nxt : graph[cur])
        {
            if (!visited[nxt])
            {
                visited[nxt] = true;
                parent[nxt] = cur;
                q.push(nxt);
            }
        }
    }

    std::vector<int> path;

    if (!visited[target])
        return path;

    for (int v = target; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    return path;
}

////////////////////////////////////////////////////////////
// Level Order Traversal (Binary Tree Style)
//
// Processes one BFS "layer" at a time.
//
// Time: O(V)
// Space: O(V)
////////////////////////////////////////////////////////////
void levelOrderExample(std::queue<int>& q)
{
    while (!q.empty())
    {
        int levelSize = q.size();

        while (levelSize--)
        {
            int node = q.front();
            q.pop();

            // process node

            // enstd::queue children...
        }
    }
}

////////////////////////////////////////////////////////////
// Multi-Source BFS
//
// Start from MANY nodes simultaneously.
//
// Used for:
//
// Rotten Oranges
// Fire Spread
// Walls and Gates
//
// Time: O(V + E)
//
////////////////////////////////////////////////////////////
void multiSourceExample(std::queue<int>& q,
    std::vector<bool>& visited)
{
    // Push ALL sources before BFS begins.
    // Example:
    //
    // q.push(source1);
    // q.push(source2);
    // q.push(source3);
}

////////////////////////////////////////////////////////////
// Grid BFS
////////////////////////////////////////////////////////////
void gridBFS(std::vector<std::vector<int>>& grid,
    int startRow,
    int startCol)
{
    int rows = grid.size();
    int cols = grid[0].size();

    std::vector<std::vector<bool>> visited(
        rows,
        std::vector<bool>(cols, false));

    std::queue<std::pair<int, int>> q;

    q.push({ startRow, startCol });
    visited[startRow][startCol] = true;

    // Up, Down, Left, Right
    std::vector<std::pair<int, int>> dirs =
    {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        for (auto [dr, dc] : dirs)
        {
            int nr = r + dr;
            int nc = c + dc;

            // Bounds check
            if (nr < 0 || nc < 0 ||
                nr >= rows || nc >= cols)
                continue;

            if (visited[nr][nc])
                continue;

            visited[nr][nc] = true;
            q.push({ nr, nc });
        }
    }
}

/*
==========================================================
std::queue Operations (all O(1))
==========================================================

q.push(x);      // enstd::queue
q.pop();        // destd::queue
q.front();      // front element
q.empty();      // std::queue empty?
q.size();       // number of elements

==========================================================
BFS Interview Checklist
==========================================================

✓ std::queue
✓ Visited array/set
✓ Mark visited BEFORE enstd::queueing neighbors
✓ Process neighbors
✓ O(V + E) on adjacency lists
✓ O(V²) on adjacency matrices
✓ Shortest path ONLY for unweighted graphs
✓ Level-order traversal via std::queue.size()
✓ Multi-source BFS for simultaneous starts
✓ Grid BFS uses direction arrays
✓ Track distance for minimum moves
✓ Track parent to reconstruct paths

==========================================================
Classic LeetCode Problems
==========================================================

102  Binary Tree Level Order Traversal
200  Number of Islands
733  Flood Fill
994  Rotting Oranges
286  Walls and Gates
752  Open the Lock
1091 Shortest Path in Binary Matrix
127  Word Ladder
815  Bus Routes

==========================================================
Most Important Interview Pattern
==========================================================

std::queue.push(start);
visited[start] = true;

while (!std::queue.empty())
{
    current = std::queue.front();
    std::queue.pop();

    for (neighbor : graph[current])
    {
        if (!visited[neighbor])
        {
            visited[neighbor] = true;
            std::queue.push(neighbor);
        }
    }
}

Memorize this template—it solves the vast majority of BFS interview problems.
==========================================================
*/