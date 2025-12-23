#include <iostream>
using namespace std;
template<class t>
class stack {
	struct node {
		t item;
		node* next;
	};
	node* top, *cur;
public:
	stack() {
		top = NULL;
	}
	bool isEmpty() {
		return top == NULL;
	}
	void push(t newItem) {
		node* newItemPtr = new node;
		newItemPtr->item = newItem;
		newItemPtr->next = top;
		top = newItemPtr;
	}
	void pop(t&stackTop) {
		if (isEmpty())
			cout << "Stack is empty.";
		else {
			node* temp = new node;
			temp = top;
			stackTop = top->item;
			top = top->next;
			temp = temp->next = NULL;
			delete temp;
		}
	}
	void getTop(t& stackTop) {
		if (isEmpty()) {
			cout << "Stack is empty.";
		}
		else {
			stackTop = top->item;
		}
	}

	void display() {
		cur = top;
		cout << "Items in the stack: ";
		cout << "[";
		while (cur != NULL) {
			cout << cur->item;
			cur = cur->next;
		}
		cout << "]\n";
	}
};
int main()
{
	stack<int>s;
	s.push(5);
	s.push(10);
	s.push(4);
	int y = 0;
	s.display();
}