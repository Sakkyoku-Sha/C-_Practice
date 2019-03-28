#include "strExtension.hpp"

std::vector<std::string> strExtension::split(const std::string& data, const std::vector<char>& delimeters ){
	
	std::vector<std::string> returnedData; 
	std::unordered_set<char> delimSet; 
	std::unordered_set<char>::iterator it; 
	//Put all delimeters in a set, so we check later to see if the current char is in the set to break on.
	for(int x = 0; x < delimeters.size(); x++) {delimSet.insert(delimeters[x]);}
	
	
	std::string temp = "";
	for(int x = 0; x < data.length(); x++){
		it = delimSet.find(data[x]);
		if(it == delimSet.end()){
			temp += data[x]; 
		}
		else{
			if(temp.length() > 0){
				returnedData.push_back(temp);
				temp = "";
			}
		}
	}
	
	if(temp.length() != 0){
		returnedData.push_back(temp);
	}
	return returnedData;
}