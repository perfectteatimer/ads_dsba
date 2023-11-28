/**********************************
struct Node
{
	int key;
	Node* left;
	Node* right;
	Node(){} : left(nullptr), right(nullptr) {}
	Node(int x) : key(x), left(nullptr), right(nullptr){}
};
***********************************/

#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <string>
#include <sstream>
#include "bstree.h"

std::string serialize(Node* root)
{

}

Node* deserialize(std::string& s)
{

}

#endif