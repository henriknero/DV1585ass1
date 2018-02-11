#ifndef NODE_H
#define NODE_H
#include <list>
#include <string>
#include <iostream>

class Node {
public:
	std::string tag, value;
	int id;
    std::list<Node> children;
	Node(std::string t, std::string v, int i) : tag(t), value(v), id(i) {}	
	Node() { tag="uninitialised"; value="uninitialised"; id =-1;}   // Bison needs this.
    void dump(int depth=0)
    {
    for(int i=0; i<depth; i++)
        std::cout << "  ";
    std::cout << tag << ":" << value << std::endl;
    for(std::list<Node>::iterator i=children.begin(); i!=children.end(); i++)
        (*i).dump(depth+1);
	}
	void dump_visual()
	{
		std::cout << id << " [label=\"" << tag << ":" << value << "\"];" << std::endl;	
		for (std::list<Node>::iterator i=children.begin(); i!=children.end();i++){
			(*i).dump_visual();
			std::cout << id << " -> " << (*i).id << ";" << std::endl;
		}
		
		
	}
};
#endif
