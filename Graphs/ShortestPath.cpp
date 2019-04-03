#include "FileManager.hpp"
#include "strExtension.hpp"
#include "Graph.hpp" 

#include <climits>
#include <queue>
#include <unordered_set>

using namespace std; 

/*
	Input file specfication. 
	
	<Start_Node_ID> <End_Node_ID>
	(<Node ID> (<connectionID><connection> weight>)* \n)* 

	e.g 
	
	A B 
	A B2 C8
	B A4 C3
	C B1 A4
	
	There will be no checking to make sure that each node is defined correctly.

*/

//Dijkstras algorithm.
int shortestPath(Graph graph, const char& start, const char& end) {

	vector<char> path;
	path.push_back(start);

	unordered_map<char, int> shortestPaths;
	unordered_set<char> visitedNodes;
	unordered_set<char> n;

	//Initialize all paths with INT_MAX
	vector<char> allIds = graph.getIds();

	for (char &e : allIds) {

		if (e != start) {
			shortestPaths.insert(make_pair(e, INT_MAX));
		}
		else {
			shortestPaths.insert(make_pair(e, 0));
		}

		n.insert(e);
	}

	while (n.empty() == false) {

		//get min in n.
		char minID = ' ';
		int minVal = INT_MAX;

		unordered_set<char>::iterator it;

		for (it = n.begin(); it != n.end(); it++) {

			if (shortestPaths[*it] < minVal) {
				minID = *it;
				minVal = shortestPaths[*it];
			}
		}

		n.erase(minID);

		//First time it should be the start node 
		unordered_map<char, int> currLinks = graph.getLinks(minID);
		unordered_map<char, int>::iterator l_it;

		for (l_it = currLinks.begin(); l_it != currLinks.end(); l_it++) {

			if (shortestPaths[minID] + l_it->second < shortestPaths[l_it->first]) {
				shortestPaths[l_it->first] = shortestPaths[minID] + l_it->second;
			}
		}
	}

	return shortestPaths[end];
}
//Link is a typedef from Graph.hpp it is just a Pair<char,int> 
vector<Link> createLinks(vector<string> line_tokens) {

	vector<Link> Links;

	for (int x = 1; x < line_tokens.size(); x++) {

		char ID = line_tokens[x][0];
		string int_weight(line_tokens[x].begin() + 1, line_tokens[x].end());

		Link newLink(ID, stoi(int_weight));
		Links.push_back(newLink);

	}

	return Links;
}
int main(int argc, char **argv) {

	Graph graph;

	vector<string> allLines = FileManager::readAllLines(argv[1]);
	vector<char> delimeters = { ' ',',','\r','\n'};

	vector<string> start_end = strExtension::split(allLines[0], delimeters);

	char start_id = start_end[0][0];
	char end_id = start_end[1][0];

	vector<Link> endLinks; 
	graph.addNode(end_id, endLinks);

	for (int x = 1; x < allLines.size(); x++) {
	
		vector<string> tokens = strExtension::split(allLines[x], delimeters);

		char currID = tokens[0][0];
		vector<Link> currLinks = createLinks(tokens);

		graph.addNode(currID, currLinks);
	}

	cout << shortestPath(graph, start_id, end_id) << endl;
	
	return 0;
}