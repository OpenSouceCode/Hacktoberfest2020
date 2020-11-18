// Algorith for a Depth first search on a tree

#include<bits/stdc++.h>
using namespace std;

#define pb push_back

void dfs(vector<vector<int>> &tree , int level[] , int currentNode , int parentNode){
	for(auto connectedNodeToCurrentNode : tree[currentNode]){
		// if the node connected to the current node is not the parent of the current node, that means we have not already visited it
		// hence we need to visit the nodes except the parent node of the current node
		if(connectedNodeToCurrentNode != parentNode){
			// as we are moving from current node to that node,  so the current node becomes the parent of that node 
			// hence the level of that node  = level of current node +1
			level[connectedNodeToCurrentNode] = level[currentNode] + 1;
			
			dfs(tree , level , connectedNodeToCurrentNode , currentNode);
		}
	}
}

int main(){
	// stores the total node count of a tree
	int nodes;
	cin >> nodes;
	
	//stores the level of each node
	int level[nodes] = {};
	
	// stores the number of edges connecting the tree
	int edges;
	cin >> edges;
	
	// creating a tree with 'nodes' size 
	// nodes are considered to be 0 based indexed
	vector<vector<int>> tree(nodes);
	
	// connecting the nodes of the tree with edges
	for(int i = 0 ; i < edges ; i++){
		int node1 , node2; // input format considered as an edge is between node1 and node2
		cin >> node1 >> node2;
		
		tree[node1].pb(node2);
		tree[node2].pb(node1);
	}
	
	// as tree is considered to be rooted at node 0, so setting the level of node 0 to 1
	level[0] = 1;
	
	// calling the recursive dfs function
	dfs(tree , level , 0 , -1);
	
	// now we can simply print the level of all the nodes
	for(int x = 0 ; x < nodes ; x++){
		cout << "level of node " << x << " = " << level[x] << endl;
	}
}
