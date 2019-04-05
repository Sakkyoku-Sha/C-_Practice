#include <vector>
#include <iostream> 
#include <iterator> 

using namespace std; 

vector<int> insertionSort(const vector<int>& arr){

	vector<int> sortedArr; 
	
	for(int x = 0; x < arr.size(); x++){
		
		for(int i = 0; i < sortedArr.size(); i++){
			vector<int>::iterator it = lower_bound(sortedArr.begin(), sortedArr.end(), arr[x]);
			sortedArr.insert(*it,arr[x]);
		}
	}
	return sortedArr;
}