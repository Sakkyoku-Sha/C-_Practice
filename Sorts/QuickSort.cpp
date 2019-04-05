#include<vector>
#include<iostream> 

using namespace std; 

void swap(vector<int>& arr, int x, int y);
int partition(vector<int>& arr, int low, int high);  
void qSort(vector<int>& arr, int low, int high);
void QuickSort(vector<int>& arr);
int partition2(vector<int>& arr, int low, int high);

int main(){
	
	vector<int> arr = {1,5,12,6,2,3}; 
	QuickSort(arr); 
	
	for(int x = 0; x < arr.size(); x++){
		cout << arr[x] << ",";
	}
	
	return 0;
}

void QuickSort(vector<int>& arr){
	qSort(arr,0,arr.size()-1);
}

void qSort(vector<int>& arr, int low, int high){

	if(low < high){
		
		int newPivot = partition2(arr, low, high); //The recursive calls need to change if you change the partition function.

		qSort(arr,low,newPivot-1); //This is newPivot and not newPivot -1 as the j goes 1 too far, newPivot + 1 seperate the values.
		qSort(arr,newPivot+1,high); 
		
	}
}

int partition2(vector<int>& arr, int low, int high){
	
	//Lomuto Partition Scheme //Greatest first. 
	
	int pivotValue = arr[high];
	
	int i = low;
	
	for(int j = low; j < high; j++){
	
		if(arr[j] < pivotValue){
			swap(arr,i,j);
			i++;
		}
	}
	
	swap(arr,i,high);
	
	return i;
}
int partition(vector<int>& arr, int low, int high){
	
	//Hoare Partition Scheme 
	
	int mid = (high+low)/2;
	int i = low-1;
	int j = high+1; //The point of this is so that the while loops break on the right value; 
	
	while(true){
		
		do{
			i++;
		}while(arr[i] < arr[mid]);
		
		do{
			j--;
		}while(arr[j] > arr[mid]); 
		
		if(i >= j) { return j;}
		
		swap(arr,i,j); 
	}
}	

void swap(vector<int>& arr, int x, int y){
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
