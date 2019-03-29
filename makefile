## A poorly made make file 
IncludeFiles = ./Include/*.cpp 
Include = -I./Include/

BSearch: 
	g++ $(Include) -g ./BinarySearch/BinarySearch.cpp $(IncludeFiles) -o BinarySearch.exe
	
BreadthFirst:
	g++ $(Include) -g ./Trees/BreadthFirst.cpp $(IncludeFiles) -o BreathFirst.exe 
	
TList:
	g++ $(Include) -g ./Templated_Link_List/LinkedList.cpp $(IncludeFiles) -o TList.exe
	
clean:
	rm *.exe