#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;

struct TNode;
typedef TNode* PNode;
struct TNode {
	int key;   
	int value; 
	PNode next;		// pointer to next element
};

// Adds a key-value pair to the list
void AddKeyVal(PNode head, int key, int value){
	PNode p = head;
	while(p->next != NULL)
		p = p->next;

	PNode new_node = new TNode;
	new_node->key = key;
	new_node->value = value;
	p->next = new_node;
}

// Returns the minimum item in a list
PNode FindMin(PNode head, int &diff){
	PNode p = head->next;
	PNode searching_node = NULL;	

	PNode last = NULL;	
	PNode next = NULL;	

	while(p){
		next = p->next;
		if(next && last){
			int difference = abs(last->value - next->value);
			if(difference >= 72){
				if(searching_node){
					if(searching_node->value < p->value){
						diff = difference;
						searching_node = p;
					}
				}
				else{
					diff = difference;
					searching_node = p;
				}
			}
		}

		last = p;
		p = p->next;
	}
	return searching_node;
}

// Rearrange the found item to the beginning of the list by key
void Permutation(PNode head, int key){
	PNode p = head;
	if(p->next->key == key) 
		return;

	while(p->next){
		if(p->next->key == key){
			PNode t = p->next->next;
			p->next->next = head->next;
			head->next = p->next;
			p->next = t;
			return;
		}
		p = p->next;
	}
}

// Applying the Transpose Method to a Keyed List
void Transposition(PNode head, int key) {
	PNode p = head;
	PNode next_node = p->next;

	if(next_node->key == key) 
		return;

	while(next_node->next){
		if(next_node->next->key == key) {
			PNode t = next_node->next->next;
			next_node->next->next = p->next;
			p->next = next_node->next;
			next_node->next = t;

			return;
		}
		p = p->next;
		next_node = p->next;
	}
}

// output list
void Output(PNode head) {
	PNode p = head->next;
	while(p){
		cout << p->value << " ";
		p = p->next;
	}
	cout << "\n";
}

void OptionFive(){
	PNode head = new TNode;	// pointer to the beginning of the list
	int diff = 0;			// difference between two neighbors of the desired element

	// Filling the list with 10 elements from 0 to 115
	for(int i = 0; i < 10; i++)
		AddKeyVal(head, i, rand() % 115);

	// List output
	cout << "List:\n";
	Output(head);

	// Search for elements whose neighbors are at least 72
	PNode searching = FindMin(head, diff);

	if(!searching){
		cout << "Element not found!\n";
		return;
	}

	// Output key-value pair of the found element
	cout << "\nSearched array element <k, v>: <" << searching->key << ", " << searching->value << ">" << "\n";
	// Display the difference between the neighbors of the found element
	cout << "The difference between adjacent elements: " << diff << "\n";

	cout << "\nApplying the Transposition Method to a Found Item..." << "\n";
	Transposition(head, searching->key);
	cout << "List:\n";
	Output(head);


	cout << "\nRearrange the found item to the top of the list..." << "\n";
	Permutation(head, searching->key);
	cout << "List:\n";
	Output(head);

}

int main(){
	srand(time(0));
	system("clear");
	OptionFive();
	return 0;
}
