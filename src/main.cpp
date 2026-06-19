#include <iostream>
#include <Color.h>
#include <CommandParser.h>
#include <vector>

int main()
{
	Color whiet(255, 255, 255);

	std::string input1;
	std::getline(std::cin, input1);
	std::vector<std::string> res = {""};
	res = CommandParser::parse(input1);

	for(std::string word : res){
		std::cout << word << " ";
	}
	return 0;
} 