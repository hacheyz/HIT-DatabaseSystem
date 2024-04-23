//
// Created by zl on 2023/12/12.
//

#include <iostream>
#include <string>
#include "tree.h"

void TreeNode::preOrder(int level)
{
	if (this->type == "LEAF") {
		for (int i = 0; i < level; i++) {
			std::cout << "    "; // 4 spaces
		}
		std::cout  << this->info << std::endl;
	} else {
		for (int i = 0; i < level; i++) {
			std::cout << "    ";
		}
		std::cout << this->type << " " << this->info << std::endl;
	}
	if (this->left != NULL) {
		this->left->preOrder(level + 1);
	}
	if (this->right != NULL) {
		this->right->preOrder(level + 1);
	}
}
