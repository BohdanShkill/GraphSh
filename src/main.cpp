#include <iostream>
#include <Color.h>
#include <CommandParser.h>
#include <vector>
#include <Canvas.h>

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
	Color orange(45, 56, 145);
	Canvas mousePaint(10, 10);
	mousePaint.setPixel(9, 9, orange);
	return 0;
} 