#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;

struct TNode;
typedef TNode* PNode;
struct TNode {
	int num;
	PNode next;
};

// Add elem in list
void AddElem(PNode head_first, int num) {
	PNode p = head_first;
	while(p->next != NULL)
		p = p->next;

	PNode new_node = new TNode;
	new_node->num = num;
	new_node->next = NULL;
	p->next = new_node;
}

// output list
void OutputList(PNode head) {
	PNode p = head->next;
	while(p) {
		cout << p->num << " ";
		p = p->next;
	}
	cout << "\n";
}

void InputList(PNode head) {
    //Add elem to list, for end enter 0
	cout << "Add elem to list, for end enter 0" << "\n";

	// Add and pus elem to list
	cout << "Elements:\n";
	while(true) {
		int n;
		cin >> n;

		if(n == 0)
            break;

		AddElem(head, n);
	}
}

// merge lists
PNode MergeLists(PNode list1, PNode list2)
{
	PNode merged = new TNode;
	PNode p;
	p = list1->next;
	while(p != NULL) {
		AddElem(merged, p->num);
		p = p->next;
	}
	p = list2->next;
	while(p != NULL) {
		AddElem(merged, p->num);
		p = p->next;
	}
	return merged;
}

void OptionFive(){
	// begin list
	PNode head_first = new TNode;
	PNode head_second = new TNode;

	InputList(head_first);
	InputList(head_second);

	// input first list
	cout << "First list:\n";
	OutputList(head_first);

    // input head second list
	cout << "Second list:\n";
	OutputList(head_second);

	PNode result_list = MergeLists(head_first, head_second);

	// output merge list
	cout << "Merge list:\n";
	OutputList(result_list);
}

int main() {
	system("clear");
	OptionFive();
	return 0;
}
