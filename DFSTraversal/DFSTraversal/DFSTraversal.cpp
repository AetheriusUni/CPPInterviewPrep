#include <iostream>
#include <vector>

void dfs(int node, std::vector<int> adj[], std::vector<int>& visited, std::vector<int>& visitedNodeOrder)
{
	// mark this node as visited
	visited[node] = 1;
	
	// add it to the visited node order vector
	visitedNodeOrder.push_back(node);

	// for each of the adjacent nodes
	for (auto it : adj[node])
	{
		// if the node wasn't visited yet
		if (visited[it] == 0)
		{
			// check its neighbors
			dfs(it, adj, visited, visitedNodeOrder);
		}
	}
}

std::vector<int> dfsGraphTraversal(int numNodes, std::vector<int> adj[])
{
	std::vector<int> visited(numNodes, 0);
	int start = 0;
	std::vector<int> visitedNodeOrder;
	dfs(start, adj, visited, visitedNodeOrder);
	return visitedNodeOrder;
}


int main()
{
	std::vector<int> adj[8];
	int numNodes = 8;

	adj[0].push_back(1);
	adj[0].push_back(2);

	adj[1].push_back(0);
	adj[1].push_back(4);
	adj[1].push_back(5);

	adj[2].push_back(0);
	adj[2].push_back(3);
	adj[2].push_back(6);

	adj[3].push_back(2);
	adj[3].push_back(7);

	adj[4].push_back(1);

	adj[5].push_back(1);

	adj[6].push_back(2);
	adj[6].push_back(7);

	adj[7].push_back(3);
	adj[7].push_back(6);

	std::vector<int> dfsPath = dfsGraphTraversal(numNodes, adj);

	for (int i = 0; i < dfsPath.size(); i++)
	{
		std::cout << dfsPath[i] << " ";
	}
	return 0;
}