#ifndef GRAPH_NODE_HPP
#define GRAPH_NODE_HPP

#include<unordered_map>
#include<vector>
#include<iterator> 
#include<utility>

using namespace std;
typedef pair<char, int> Link; //ID and weight

class Graph_Node {

public:
	unordered_map<char, int> Links;//Set of pointers to nodes paired with a weight to go to that node;
	char nodeID;

	Graph_Node() {
		nodeID = -1;
	}
	Graph_Node(char ID, vector<Link> givenLinks) {

		nodeID = ID;
		for (Link &l : givenLinks) {
			Links.insert(make_pair(l.first, l.second));
		}
	}

	//returns -1 if no link exists (means no negative weights are possible in this graph)
	int getWeight(char nodeID) {

		unordered_map<char, int>::iterator it;

		it = Links.find(nodeID);

		if (it != Links.end()) {
			return it->second;
		}
		else {
			return -1;
		}
	}
	void Add_Link(char ID, int weight) {
		Link newLink(ID, weight);
		Links.insert(newLink);
	}
};

class Graph {

public:

	unordered_map<char, Graph_Node*> nodes; //node ID to graph node;

	Graph() {
		
	}

	void addNode(char ID, vector<Link> links) {

		Graph_Node* newNode = new Graph_Node(ID, links);
		nodes.insert(make_pair(ID, newNode));
	}

	int GetWeight(char ID) {

		unordered_map<char, Graph_Node*>::iterator it;

		it = nodes.find(ID);

		if (it != nodes.end()) {
			return it->second->getWeight(ID);
		}
		else {
			return -1;
		}
	}

	unordered_map<char, int> getLinks(char ID) {

		unordered_map<char, Graph_Node*>::iterator it;

		it = nodes.find(ID);

		if (it != nodes.end()) {
			return it->second->Links;
		}
		else {
			return {};
		}
	}


	//returns the ID's of every node in the graph
	vector<char> getIds() {

		vector<char> node_ids;

		unordered_map<char, Graph_Node*>::iterator it;

		for (it = nodes.begin(); it != nodes.end(); it++) {
			node_ids.push_back(it->first);
		}

		return node_ids;
	}
};


#endif 
