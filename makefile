## A poorly made make file 
IncludeFiles = ./Include/*.cpp 
Include = -I./Include/

BSearch: 
	g++ $(Include) -g ./BinarySearch/BinarySearch.cpp $(IncludeFiles) -o BinarySearch.exe
	
BreadthFirst:
	g++ $(Include) -g ./Trees/BreadthFirst.cpp $(IncludeFiles) -o BreathFirst.exe 
	
TList:
	g++ $(Include) -g ./Templated_Link_List/LinkedList.cpp $(IncludeFiles) -o TList.exe
	
SPath: 
	g++ $(Include) -g ./Graphs/ShortestPath.cpp $(IncludeFiles) -o SPath.exe
	
QSort: 
	g++ -g ./QuickSort/QuickSort.cpp -o Qsort.exe
	
clean:
	rm *.exe