#include <iostream>
#include <cstdlib>
#include <ctime>

#define NAME_COUNT 15
#define PRIZE_COUNT 5

using std::cout;
using std::cin;
using std::string;

struct TNode;
typedef TNode* PNode;
struct TNode
{
	string name;
	PNode next;
};


// add elem in list
void AddElem(PNode first, string name){
	PNode p = first;
	while(p->next != NULL && p->next != first)
		p = p->next;

	PNode q = new TNode;
	q->name = name;
	q->next = first;

	p->next = q;
}


// return node list in index
PNode GetInd(PNode first, int index){
	int iter = 0;
	PNode p = first->next;
	while(iter != index){
		p = p->next;
		if (p == first) p = p->next;
		iter++;
	}
	return p;
}

// del elem from list
void DelElem(PNode first, PNode oldNode){
	PNode p = first;
	if(first == oldNode)
		first = oldNode->next;
	else{
		while(p && p->next != oldNode) p = p->next;
		if(p == NULL) return;
		p->next = oldNode->next;
	}

	delete oldNode;
}

// output list
void OutputList(PNode first){
	PNode p = first->next;
	int iter = 1;
	while(p && p != first){
		cout << iter++ << ": " << p->name << "\n";
		p = p->next;
	}
	cout << "\n";
}

// output winners
void FindWins(PNode names, PNode prizes){
	int K, t, iter = 1, count = 0;
	cout << "Win each K: ";
	cin >> K;

	cout << "Elem for recalculation t: ";
	cin >> t;

	cout << "\n";

	PNode p = names->next;
	while(count < t) {
		// recalculate each k member
		if(iter % K == 0) {
			if(count == PRIZE_COUNT) {
				cout << "Prize ended!\n";
				break;
			}
			if(count == NAME_COUNT) {
				cout << "All member received prizes!\n" << "\n";
				break;
			}

			// give first prize
			PNode prize = GetInd(prizes, 0);

			// output winner
			cout << "Winner:\n"; 
			cout << p->name << "(" << prize->name << ")" << "\n\n";
			++count;

			// del member and prize
			PNode oldNode = p;

			DelElem(names, oldNode);
			DelElem(prizes, prize);
		}
		++iter;
		p = p->next;
		if(p == names) p = p->next;
	}
}

void OptionFive(){
	string nameList[NAME_COUNT] = {"Volkov", "Makarov", "Zaharov", "Skolkov", "Pechkin", "Zaycev", "Antonov", "Pushkin", "Zhukov", "Komarov", "Nikolaev", "Leonov", "Yashev", "Ermolin", "Valeriev"};
	string prizeList[PRIZE_COUNT] = {"Sport Car", "Apple Iphone X", "PlayStation", "Autographed t-shirt", "Free app from appstore"};
	PNode names = new TNode;
	PNode prizes = new TNode;
	
	for(int iter = 0; iter < NAME_COUNT; iter++) {
		AddElem(names, nameList[iter]);
	}
	for(int iter = 0; iter < PRIZE_COUNT; iter++) {
		AddElem(prizes, prizeList[iter]);
	}
	cout << "List members:\n";
	OutputList(names);
	cout << "List prizes:\n";
	OutputList(prizes);
	FindWins(names, prizes);
}


int main(){
	srand(time(0));
	system("clear");
	OptionFive();
	return 0;
}
