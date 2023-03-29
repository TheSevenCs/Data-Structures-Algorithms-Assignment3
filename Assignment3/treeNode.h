#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	char ch;
	struct TreeNode* lesserNode;
	struct TreeNode* greaterNode;
}TreeNode;

TreeNode* createNode(char);
