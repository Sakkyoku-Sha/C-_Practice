#include "FileManager.hpp" 
#include "strExtension.hpp" 

using namespace std; 

struct node{
	node *left;
	node *right; 
	int data; 
	
	node(){
		left = NULL;
		right = NULL;
		data = -1;
	}
	
	node(int val){
		left = NULL;
		right = NULL;
		data = val;
	}
	
	node(const node& givenNode){
		this->left = givenNode.left;
		this->right = givenNode.right;
		this->data = givenNode.data;
	}
	
	//Overload operator for the nodes
	friend bool operator>(const node& a, const node& b){
		return a.data > b.data; 
	}
};



/*




*/
void BreadthFirstPrint(node* head){

	if(head == NULL){return;}
	
	BreadthFirstPrint(head->left);
	cout << head->data << ",";
	BreadthFirstPrint(head->right);
}

void addToTree(node* head, int value){

	node* currNode = head;
	node* newNode = new node(value);
	
	while(currNode != NULL){
		
		if(*newNode > *currNode){
			
			if(currNode->right == NULL){
				currNode->right = newNode;
				break;
			}
	
			currNode = currNode->right;		
		}
		else{
			
			if(currNode->left == NULL){
				currNode->left = newNode;
				break;
			}
			
			currNode = currNode->left;
		}	
	}
}

node* genTree(const vector<int>& arr){
	
	//Create the head of the tree.
	node* head = new node(); 
	head->data = arr[0]; 
	
	for(int x = 1; x < arr.size(); x++){
		addToTree(head,arr[x]);
	}
	
	return head;
}

//Reads in a list of numbers from a file then prints out the breadth first search of the tree.
//This makes the assumptions that all numbers given numbers are uniquue.

int main(int argc, char **argv) {
	
	if(argc == 2){
		vector<string> allLines = FileManager::readAllLines(argv[1]); 
		vector<char> delimeters = {' ', ','};
		
		for(int x = 0; x < allLines.size(); x++){
			
			vector<string> tokens = strExtension::split(allLines[x],delimeters);
			
			vector<int> arr;
			for(int i = 0; i < tokens.size()-1; i++){
				arr.push_back(stoi(tokens[i])); 
			}	
			
			node* head = genTree(arr); 
			
			BreadthFirstPrint(head);
			cout << endl;
		}
	}
	else{
		cout << "Wrong number of arguments\n"; 
	}
	
	
	
	return 0;
}

