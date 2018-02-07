#include<iostream>
#include "interpreter.tab.hh"
extern std::string output;

void yy::parser::error(std::string const&err)
{
  std::cout << "It's one of the bad ones... " << err << std::endl;
}

int main(int argc, char **argv)
{
	if(argc > 1)
		std::cout << argv[1];
	yy::parser parser;
    if(!parser.parse())
    	std::cout << output << std::endl;
	return 0;
 }
