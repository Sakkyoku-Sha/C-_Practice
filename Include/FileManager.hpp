#ifndef FILEMANAGER_H //Header guards 
#define FILEMANAGER_H

#include<fstream> 
#include<sstream>
#include<string> 
#include<vector> 
#include<iostream>

/*
	A general static class for file input and output, things will be added here as they are needed. 
	freopen could be used as well which changes the output and input of STDOUT and STDIN, but I prefer to use fstream. 
	
	Currently Functional: 
	
		readAllLines() reads all lines from the given file to a vector of strings, this would be a *string array in C.
*/
class FileManager{
	
	public: 
		static std::vector<std::string> readAllLines(std::string FileName); 

};

#endif