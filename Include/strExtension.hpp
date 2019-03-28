#ifndef STREXTENSION_H
#define STREXTENSION_H

#include<vector>
#include<iostream> 
#include<string> 
#include<unordered_set>
#include<iterator>

//Implementations of basic string operations that aren't included in the default #include <string>
//I am fully aware there are C++ libraries that implement these extensions such as boost. 

class strExtension{
	
	public: 
		static std::vector<std::string> split(const std::string& data, const std::vector<char>& delimeters ); 
		
		
	
};




 #endif