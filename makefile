## A poorly made make file 
IncludeFiles = ./Include/*.cpp 
Include = -I./Include/

BSearch: 
	g++ $(Include) ./BinarySearch/BinarySearch.cpp $(IncludeFiles) -o BinarySearch.exe
clean:
	rm BinarySearch.exe