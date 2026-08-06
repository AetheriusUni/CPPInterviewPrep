// BFS where we start at node 0

#include <iostream>
#include <vector>
#include <queue>

std::vector<int> bfsOfGraph(int numNodes, std::vector<int> adj[])
{
	// initialize visited vector to have a set size == numNodes and initial values of 0
	std::vector<int> visited(numNodes, 0);
	// set the first node as 1 to signify it's visited as the start point
	visited[0] = 1;

	// queue the nodes as we visit them
	std::queue<int> q;
	q.push(0);

	std::vector<int> bfsTraversal;

	// until the queue of visited nodes is empty
	while (!q.empty())
	{
		// store the front of the queue
		int node = q.front();
		// remove that node from the queue
		q.pop();
		// add that node to the return traversal
		bfsTraversal.push_back(node);

		// for each of the adjacent nodes of the prior front node
		for (auto it : adj[node])
		{
			// if we didn't visit that node before
			if (!visited[it])
			{
				// mark it as visited
				visited[it] = 1;
				// since it's visited add it to the visited queue
				q.push(it);
			}
		}
	}
	return bfsTraversal;
}

int main()
{
	// array of vectors with size 5
	std::vector<int> adj[5];
	int numNodes = 5;

	adj[0].push_back(1);
	adj[0].push_back(2);

	adj[1].push_back(0);
	adj[1].push_back(4);

	adj[2].push_back(0);
	adj[2].push_back(3);

	adj[3].push_back(2);

	adj[4].push_back(1);

	std::vector<int> bfsTraversal = bfsOfGraph(numNodes, adj);

	return 0;
}
