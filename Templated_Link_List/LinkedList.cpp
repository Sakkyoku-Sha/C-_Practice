#include "FileManager.hpp"  //Note the NOT relative path USE -I to compile
#include "strExtension.hpp"

using namespace std; 

template<typename T>
class node{

public:
	node* next; 
	T data; 
	
	node(){
		this->next = NULL;
		data = -1;	
	}
	node(const T& data)
	{
		this->next = NULL;
		this->data = data;
	}
	
	bool operator>(const node& other) const{
		return (this->data > other.data);	 //This might return an error if the data type given doesn't support thhe oprerator
	}
	bool operator<(const node& other) const{
		return other > *this;
	}
	bool operator==(const node& other) const{
		return this->data == other.data;
	}
};

template<typename T> 
class LinkedList{
	
public: 
	int length; 
	node<T>* head; 
	node<T>* tail;
	
	LinkedList(){
		head = NULL;
		tail = NULL;
		length = 0;
	}
	
	void Add(const T& value){
		
		node<T>* temp = new node<T>(value);
		
		if(head == NULL){
			head = temp;
			tail = head;
		}
		else{
			tail->next = temp;
			tail = temp;
		}
		
		length++;
	}
	
	//Add merge sort method 
	void sort(){
		head = mergeSort(head);
		
		node<T>* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		
		tail = temp;
	}
	//Reversing a linked list in O(n) , O(n) 
	void reverse(){
		
		if(length > 1){ //no point in reveseing a list with 1 or less elements.
			
			node<T>* currentHead = head; 
			node<T>* newHead = head->next; 
			tail = head;
			tail->next = NULL;
			
			while(newHead != NULL){
				node<T>* restOfList = newHead->next;
				newHead->next = currentHead;
				currentHead = newHead;
				newHead = restOfList;		
			}
			
			head = currentHead;
		}
	}
	
	void print() const{
		
		node<T>* temp = head;
		
		while(temp != NULL){
			cout << temp->data << ",";           //Assumes the node's data can be printed;
			temp = temp->next;
		}		
	}

private:
	
	node<T>* merge(node<T>* left, node<T>* right){
		
		node<T>* currNode; 
		
		if(*left < *right){ 
			currNode = left;
			left = left->next;
		}		
		else{
			currNode = right;
			right = right->next;
		}
		
		node<T>* newHead = currNode;
	
		while(left != NULL || right != NULL){
			
			bool addRight = true; 
			
			if(left != NULL){
				
				if(right == NULL){
					addRight = false;
				}
				else if(*left < *right){
					addRight = false;
				}
			}
			if(addRight){
				currNode->next = right;
				right=right->next;
			}
			else{
				currNode->next = left;
				left=left->next;
			}
			
			currNode = currNode->next;
		}
		
		return newHead;
	}
	
	node<T>* mergeSort(node<T>* currHead){
		
		if(currHead->next == NULL){
			return currHead;
		}
		
		node<T>* left = currHead;
		node<T>* right = currHead;
		node<T>* doubler = currHead; 
		node<T>* prevRight = right;;
		
		//Get the mid point 
		while(doubler != NULL){
			
			prevRight = right;
			right = right->next;
			
			doubler = doubler->next;
			if(doubler != NULL){
				doubler = doubler->next;
			}		
		}
		
		prevRight->next = NULL; //Split the list;
		
		left = mergeSort(left);
		right = mergeSort(right);
		
		return merge(left,right);
	}
	
};

int main(int argc, char **argv){
	
	if(argc == 2){
		
		vector<string> allLines = FileManager::readAllLines(argv[1]); 		
		vector<char> delimeters = {' ', ','};
		
		for(int x = 0; x < allLines.size(); x++){
		
			vector<string> tokens = strExtension::split(allLines[x],delimeters);			
			LinkedList<int> *List = new LinkedList<int>();
			
			for(int i = 0; i < tokens.size(); i++){
				List->Add(stoi(tokens[i]));
			}		
					
			List->print();
			List->reverse();
			cout << endl;
			List->print();
			List->sort();
			cout << endl;
			List->print();
			
			delete List; //free up the space;
		}
		
	}
	else{
		cout << "Wrong number of arguments";
	}
	
	return 0;
}

