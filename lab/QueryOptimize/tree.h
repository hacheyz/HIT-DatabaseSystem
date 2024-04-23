//
// Created by zl on 2023/12/12.
//

#ifndef QUERYOPTIMIZE_TREE_H
#define QUERYOPTIMIZE_TREE_H

#include <string>

class TreeNode
{
public:
	std::string type; // 4 types: SELECT, PROJECTION, JOIN, LEAF
	TreeNode *left;
	TreeNode *right;
	std::string info; // extra information

	TreeNode() : type(""), left(NULL), right(NULL), info("")
	{
	}

	TreeNode(std::string op) : type(op), left(NULL), right(NULL), info("")
	{
	}

	TreeNode(std::string op, std::string info) : type(op), left(NULL), right(NULL), info(info)
	{
	}

	void preOrder(int level);
};

#endif //QUERYOPTIMIZE_TREE_H
