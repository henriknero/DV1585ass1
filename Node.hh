#ifndef NODE_H
#define NODE_H
#include <list>
#include <string>
#include <iostream>
#include "Environment.hh"
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
	void walk(Environment *env)
	{
		if (tag == "chunk")
			for (std::list<Node>::iterator i = children.begin(); i!=children.end();i++)
			{
				(*i).execute(env);	
			}
		if (tag == "funccall")
		{
			
		}
	}
	void execute(Environment *env)
	{
		if (tag == "funccall")
		{
			std::string funcname = children.front().children.front().value;
			Node args = children.back();
			if (funcname == "print")
				exec_print(args);
		}
	}
	void exec_print(Node args)
	{
		if(args.tag == "String")
			std::cout << args.value << std::endl;
		else if (args.tag == "emptypara")
			std::cout << std::endl;
		else if(args.children.front().tag == "explist")
		{
			explist = args.children.front()
			for (auto i; explist.children.begin(); i != explist.children.end();i++)
			{
				
			}
		}
	}

};
#endif
