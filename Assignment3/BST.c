#include "BST.h"

PBST createBST() {
	PBST newBST = (struct BST*)calloc(1, sizeof(struct BST));
	return newBST;
}


void insertNodeToBST(TreeNode* newNode, PBST tree) {
	if (tree->Root == NULL) {
		tree->Root = newNode;
	}
	else {
		TreeNode* currentNode = tree->Root;
		while (1) {
			if (newNode->ch < currentNode->ch) {
				if (currentNode->lesserNode == NULL) {
					currentNode->lesserNode = newNode;
					break;
				}
				currentNode = currentNode->lesserNode;
			}
			else if (newNode->ch > currentNode->ch) {
				if (currentNode->greaterNode == NULL) {
					currentNode->greaterNode = newNode;
					break;
				}
				currentNode = currentNode->greaterNode;
			}
			else {
				break;
			}
		}
	}
}

bool searchBST(char search, PBST Tree) {
	TreeNode* currentNode = Tree->Root;
	while (true) {
		if (currentNode == NULL) {
			return false;
		}
		
		else if (currentNode->ch > search) {
			currentNode = currentNode->lesserNode;
		}
		else if (currentNode->ch < search) {
			currentNode = currentNode->greaterNode;
		}
		else {
			return true;
		}
	}
}

int countNodes(PBST Tree) {
	int count = 0;
	char letters[] = "abcdefghijklmnopqrstuvwxyz";
	for (int j = 0; j < 27; j++) {
		if (searchBST(letters[j], Tree)) {
			count++;
		}
	}
	return count;
}

int nodeDepth(char node, PBST Tree) {
	int count = 0;
	TreeNode* currentNode = Tree->Root;
	while (true) {
		if (currentNode == NULL) {
			return 0;
		}

		else if (currentNode->ch > node) {
			currentNode = currentNode->lesserNode;
			count++;
		}
		else if (currentNode->ch < node) {
			currentNode = currentNode->greaterNode;
			count++;
		}
		else {
			return count;
		}
	}
}

int findTreeHeight(PBST Tree) {
	int maxHeight = 0;
	int num;
	char letters[] = "abcdefghijklmnopqrstuvwxyz";
	for (int j = 0; j < 27; j++) {
		num = nodeDepth(letters[j], Tree);
		if (num > maxHeight) {
			maxHeight = num;
		}
	}
	return maxHeight;
}