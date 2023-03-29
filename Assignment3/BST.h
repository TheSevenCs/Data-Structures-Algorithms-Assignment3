#pragma once
#include <stdio.h>
#include "treeNode.h"
#include <stdbool.h>

typedef struct BST {
	TreeNode* Root;
}BST, * PBST;

PBST createBST();
void insertNodeToBST(TreeNode*, PBST);
bool searchBST(char, PBST);
int countNodes(PBST);
int findTreeHeight(PBST);