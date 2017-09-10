#include <iostream>

class stack{
	int top;
	int max_size;
public:
	int a[max_size];
	stack(){
		top = -1;
	}
	bool push(int x);
	int pop();
	bool isEmpty();
};

bool stack::push(int x){
	bool state = False;
	if(top >= max_size){
		std::cout << "Stack Overflow" << std::endl;
	}
	else{
		a[++top] = x;
		state = True;	
	}
	
	return state;
}

int stack::pop(){
	int item = 0;
	if(top > -1){
		item = a[top--];
	}
	else{
		std::cout << "Pop from an Empty Stack" << std::endl;
	}
	return item;
}

bool stack::isEmpty(){
	return (top == -1);
}

int stock_span(int[] array){
	
}

int main(){
	int[] array = [100, 80, 60, 70, 60, 75, 85];
	max = stock_span(array);
	return 0;
}
