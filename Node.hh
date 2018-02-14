#ifndef NODE_H
#define NODE_H
#include <list>
#include <string>
#include <iostream>
#include <math.h>
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
	}
	void execute(Environment *env)
	{
		if (tag == "funccall")
		{
			std::string funcname = children.front().children.front().value;
			Node args = children.back();
			if (funcname == "print")
				exec_print(args, env);
		}
		if (tag == "assign")
		{
			std::string varname = children.front().children.front().value;
			std::string value = std::to_string(exec_num_op(children.back(), env));
			env->vars[varname] = value;
		}
	}
	void exec_print(Node args, Environment *env)
	{
		if(args.tag == "String")
			std::cout << args.value << std::endl;
		else if (args.tag == "emptypara")
			std::cout << std::endl;
		else if(args.children.front().tag == "OP")
		{
			std::cout << exec_num_op(args.children.front(), env) << std::endl;
		}
		else if(args.children.front().tag == "varlist")
		{
			Node varlist = args.children.front();
			for (auto i = varlist.children.begin(); i != varlist.children.end();i++)
			{
			std::cout << env->vars[i->value] << std::endl;
			}
		}
	}
	float exec_num_op(Node op, Environment *env)
	{
		float returnValue;
		std::list<Node>::iterator it = op.children.begin();
		if (it->tag == "Number")
			returnValue = std::stof(it->value);
		else if (it->tag == "varlist")
			returnValue = std::stof(env->vars[it->children.front().value]);
		else 
			returnValue = exec_num_op((*it), env);
		std::advance(it,1);
		while (it != op.children.end())
		{
			if (op.value == "*")
			{
				if (it->tag == "Number")
					returnValue *= std::stof(it->value);
				else if (it->tag == "varlist")
					returnValue *= std::stof(env->vars[it->children.front().value]);
				else 
					returnValue *= exec_num_op((*it), env);
			}
			if (op.value == "/")
			{
				if (it->tag == "Number")
					returnValue /= std::stof(it->value);
				else if (it->tag == "varlist")
					returnValue /= std::stof(env->vars[it->children.front().value]);
				else 
					returnValue /= exec_num_op((*it),env);
			}
			if (op.value == "+")
			{
				if (it->tag == "Number")
					returnValue += std::stof(it->value);
				else if (it->tag == "varlist")
					returnValue += std::stof(env->vars[it->children.front().value]);
				else 
					returnValue += exec_num_op((*it), env);
			}
			if (op.value == "-")
			{
				if (it->tag == "Number")
					returnValue -= std::stof(it->value);
				else if (it->tag == "varlist")
					returnValue -= std::stof(env->vars[it->children.front().value]);
				else 
					returnValue -= exec_num_op((*it), env);
			}
			if (op.value == "^")
				if (it->tag == "Number")
					returnValue = pow(returnValue,std::stof(it->value));
				else if (it->tag == "varlist")
					returnValue = pow(returnValue,std::stof(env->vars[it->children.front().value]));
				else
					returnValue = pow(returnValue,exec_num_op((*it), env));
					
			std::advance(it,1);
		}
		return returnValue;
	}

};
#endif
