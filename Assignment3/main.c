#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "treeNode.h"

int main() {
	int numOfChar;
	char letters[] = "abcdefghijklmnopqrstuvwxyz";
	int letterNum;
	PBST TheTree = createBST();

	srand(time(0));
	numOfChar = (rand() % 9) + 11;

	for (int i = 0; i < numOfChar; i++) {
		srand(time(0) + i);
		letterNum = rand() % 26;
		insertNodeToBST(createNode(letters[letterNum]), TheTree);
	}
	printf("Letters in Tree: \n");
	for (int j = 0; j < 27; j++) {
		if (searchBST(letters[j], TheTree)) {
			printf("%c ", letters[j]);
		}
	}
	printf("\n\nNode Count: %d ", countNodes(TheTree));
	printf("\nTree Height: %d", findTreeHeight(TheTree));
	return 0;
}