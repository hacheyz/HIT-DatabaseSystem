#include <iostream>
#include <string>
#include <vector>
#include "tree.h"

using namespace std;

void parseQuery(TreeNode *root, string query);
TreeNode *optimizeQuery(TreeNode *root, vector<string> info);

int main()
{
	string query1 = "SELECT [ ENAME = 'Mary' & DNAME = 'Research' ] ( EMPLOYEE JOIN DEPARTMENT )";
	string query2 = "PROJECTION [ BDATE ] ( SELECT [ ENAME = 'John' & DNAME = 'Research' ] ( EMPLOYEE JOIN DEPARTMENT ) )";
	string query3 = "SELECT [ ESSN = '01' ] ( PROJECTION [ ESSN, PNAME ] ( WORKS_ON JOIN PROJECT ) )";
	string query[3] = { query1, query2, query3 };

	for (int i = 0; i < 3; i++) {
		cout << "Query " << i + 1 << ":" << endl << endl;
		TreeNode *root = new TreeNode(); // root node does not store any information
		parseQuery(root, query[i]);
		root->left->preOrder(0);
		cout << endl;
		root->left = optimizeQuery(root->left, vector<string>());
		root->left->preOrder(0);
		cout << endl;
	}

	return 0;
}

void parseQuery(TreeNode *root, string query)
{
	// get tokens seperated by space
	vector<string> token;
	string temp = "";
	for (int i = 0; i < query.length(); i++) {
		if (query[i] == ' ') {
			token.push_back(temp);
			temp = "";
		} else {
			temp += query[i];
		}
	}

	// parse
	TreeNode *p = root;
	auto it = token.begin();
	while (it != token.end()) {
		if (*it == "[") {
			it++;
			string info = "";
			while (*it != "]") {
				info += *it;
				it++;
			}
			p->info = info;
			it++; // it points to "]".next now
		} else if (*it == "(") {
			it++;
			if (*it == "SELECT" || *it == "PROJECTION") {
				TreeNode *q = new TreeNode(*it);
				p->left = q;
				p = q;
				it++;
				if (*it == "[") {
					it++;
					string info = "";
					while (*it != "]") {
						info += *it;
						it++;
					}
					p->info = info;
					it++; // it points to "]".next now
				}
			} else if (*it != ")" && *it != ",") {
				TreeNode *q = new TreeNode("JOIN");
				p->left = q;
				p = q;
				TreeNode *left = new TreeNode("LEAF", *it);
				p->left = left;
				it += 2;
				TreeNode *right = new TreeNode("LEAF", *it);
				p->right = right;
				it++; // it point to ")".next now
			}
		} else if (*it == ")" || *it == ",") {
			it++;
		} else {
			TreeNode *q = new TreeNode(*it);
			p->left = q;
			p = q;
			it++;
		}
	}
}

TreeNode *optimizeQuery(TreeNode *root, vector<string> info)
{
	TreeNode *p = root;
	if (p->type == "SELECT") {
		// split SELECT condtion by '&'
		vector<string> condition;
		string temp = "";
		for (int i = 0; i < p->info.length(); i++) {
			if (p->info[i] == '&') {
				condition.push_back(temp);
				temp = "";
			} else {
				temp += p->info[i];
			}
		}
		condition.push_back(temp);
		p = optimizeQuery(p->left, condition);
	} else if (p->type == "PROJECTION") {
		p->left = optimizeQuery(p->left, info);
	} else if (p->type == "JOIN") {
		string op = "SELECT";
		TreeNode *q = new TreeNode(op, info[0]);
		q->left = p->left; // move join.left to select.left
		p->left = q;
		if (info.size() > 1) {
			TreeNode *r = new TreeNode(op, info[1]);
			r->left = p->right; // move join.right to select.left
			p->right = r;
		}
	}
	return p;
}
