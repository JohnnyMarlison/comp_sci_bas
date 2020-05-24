#include <iostream>

#define N 7

using std::cout;
using std::cin;

struct TNode {
	int data;
	TNode *left_branch;
	TNode *right_branch;
};
typedef TNode *PNode;

// Adding a vertex to a tree
void AddVertex(PNode &tree, int data) {
	if(!tree) {
		tree = new TNode;
		tree->data = data;
		tree->left_branch = NULL;
		tree->right_branch = NULL;
		return;
	}

	if(data < tree->data) 
		AddVertex(tree->left_branch, data);
	else 
		AddVertex(tree->right_branch, data);
}

// Search for a record in the tree
bool FindE(PNode root, int E) {
	if(root->left_branch != NULL)
		if(FindE(root->left_branch, E)) return true;

	if(root->data == E) 
		return true;

	if(root->right_branch != NULL)
		if(FindE(root->right_branch, E)) return true;

	return false;
}

// Output values of tree vertices
void OutputVal(PNode root) {
	if(root->right_branch != NULL) 
		OutputVal(root->right_branch);

	cout << root->data << "\n";

	if(root->left_branch != NULL) 
		OutputVal(root->left_branch);
}

void OptionFive(){
// pointer to start root
	PNode tree = NULL;
	int E;

	// array of vertex values
	float data[N] = {1, 3, 5, 7, 9, 11, 13};

	// tree initialization
	for(int i = 0; i < N; i++) 
		AddVertex(tree, data[i]);

	// Output tree output
	cout << "Source tree:\n";
	OutputVal(tree);
	cout << "\n";

	cout << "Value E:\n";
	cin >> E;

	// If the record is not found, it is added
	if(!FindE(tree, E)) {
		AddVertex(tree, E);
		cout << "Added value E:\n";
		OutputVal(tree);
		cout << "\n";
	}
	else {
		cout << "Vertex with the entry E exists!\n";
	}
}

int main() {
	system("clear");
	OptionFive();
	return 0;
}
