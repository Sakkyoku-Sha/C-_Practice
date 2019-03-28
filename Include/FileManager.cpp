#include "FileManager.hpp" //Note the relative file path.

std::vector<std::string> FileManager::readAllLines(std::string FileName){
			
	std::ifstream input(FileName); 
 	
	std::vector<std::string> lines; 
	std::string line; 
	
	while(std::getline(input, line)){
		lines.push_back(line); 
	}
	
	return lines; 
}