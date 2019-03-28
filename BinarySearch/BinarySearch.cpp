#include "FileManager.hpp"  //Note the NOT relative path USE -I to compile
#include "strExtension.hpp"
#include <algorithm>
using namespace std; 
/*
	This basic binary search solution takes an input file of the form

	<array of integers><space><value to be searched> \n
	
	5,47,5,1456,47,4 50
	5,4,3,2,1 1
	
	expected output 
	FALSE
	TRUE
	
*/


bool binarySearchHelpler(const vector<int>& arr, const int number, int min, int max){
	
	int mid = (max+min)/2;
	
	cout << arr[min] << " | " << arr[mid] << " | " << arr[max] << endl;
	
	if(arr[mid] == number){return true;}
	
	if(min >= max){ return false; }
	
	if(arr[mid] > number){
		return binarySearchHelpler(arr,number,min,mid-1);
	}
	else{ 
		return binarySearchHelpler(arr,number,mid+1,max);
	}
	
	return true;
	
}
//We need to make sure that the values are sorted before binary search can work 
bool binarySearch(vector<int> arr, const int number){
	sort(arr.begin(), arr.end()); 
	return binarySearchHelpler(arr,number,0,arr.size()-1); 
	
	return true;
}


int main(int argc, char *argv[]){
	
	if(argc == 2){
		
		//c++ main line has 1 default value, so the second one (index 1) needs to be used. 
		vector<string> allLines = FileManager::readAllLines(argv[1]); 		
		vector<char> delimeters = {' ', ','};
		
		for(int x = 0; x < allLines.size(); x++){
		
			vector<string> tokens = strExtension::split(allLines[x],delimeters);
			
			vector<int> arr;
			int searchNum = stoi(tokens[tokens.size()-1]);
			
			for(int i = 0; i < tokens.size()-1; i++){
				arr.push_back(stoi(tokens[i])); 
			}		

			if(binarySearch(arr,searchNum)){ cout << "TRUE\n";}
			else {cout << "FALSE\n";}
		}
	}
	else{
		std::cout<<"Wrong number of arguments"; 
	}
	
	return 0;
}