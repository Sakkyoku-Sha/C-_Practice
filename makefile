## A poorly made make file 
IncludeFiles = ./Include/*.cpp 
Include = -I./Include/

BSearch: 
	g++ $(Include) ./BinarySearch/BinarySearch.cpp $(IncludeFiles) -o BinarySearch.exe
	
BreadthFirst:
	g++ $(Include) ./Trees/BreadthFirst.cpp $(IncludeFiles) -o BreathFirst.exe 
	
clean:
	rm BinarySearch.exe