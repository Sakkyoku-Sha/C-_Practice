#include "FileManager.hpp" //Note the relative file path.

std::vector<std::string> FileManager::readAllLines(std::string FileName) {

	try{
		std::ifstream input(FileName);

		std::vector<std::string> lines;
		std::string line;

		while (std::getline(input, line)) {
			
			if(line.length() != 0)
			{ 
				lines.push_back(line);
			}
		}

		return lines;
	}
	catch(const std::exception &e){
		e.what();
		exit(0); 
	}
}