#include<iostream>
#include "interpreter.tab.hh"
#include "Node.hh"
extern Node root;
void yy::parser::error(std::string const&err)
{
  std::cout << "It's one of the bad ones... " << err << std::endl;
}

int main(int argc, char **argv)
{
	yy::parser parser;
    if(!parser.parse())
		root.dump();

		freopen("output.dot","w",stdout);
		std::cout << "digraph {" << std::endl;
		root.dump_visual();
		std::cout << "}" << std::endl;
	return 0;
 }
