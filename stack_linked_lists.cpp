#include <iostream>
using namespace std;
template<class t>
class stack {
	struct node {
		t item;
		node* next;
	};
	node* top, * cur;
public:
	stack() {
		top = nullptr;
	}
	bool isEmpty() {
		return top == nullptr;
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
			temp = temp->next = nullptr;
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
		while (cur != nullptr) {
			cout << cur->item << " ";
			cur = cur->next;
		}
		cout << "]\n";
	}
};
int main()
{
	stack<int> s;
	int x;

	// Push elements
	s.push(5);
	s.push(10);
	s.push(4);

	// Display stack
	s.display();        // Output: [4 10 5]

	// Get top element
	s.getTop(x);
	cout << "Top = " << x << endl;   // Top = 4

	// Pop an element
	s.pop(x);
	cout << "Popped = " << x << endl;  // Popped = 4

	// Display again
	s.display();        // Output: [10 5]

	// Check if stack is empty
	if (s.isEmpty())
		cout << "Stack is empty";
	else
		cout << "Stack is not empty";

}
