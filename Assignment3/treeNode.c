#include "treeNode.h"

TreeNode* createNode(char ch) {
	TreeNode* newNode = calloc(1, sizeof(TreeNode));
	newNode->ch = ch;
	return newNode;
}