#include <iostream>

class stack{
	int top;
	int a[100];
public:
	stack(){
		top = -1;
	}
	bool push(int x);
	int pop();
	bool isEmpty();
	int len();
	empty();
};

bool stack::push(int x){
	bool state = false;
	if(top >= 100){
		std::cout << "Stack Overflow" << std::endl;
	}
	else{
		a[++top] = x;
		state = true;	
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

int stack::len(){
	return (top + 1);
}

stack::empty(){
	top = -1;
}

int stock_span(int array[], int day){
	int max = 0;
	stack prices;
	int counter = 1;
	while(counter <= day){
		if(array[counter - 1] <= array[day - 1]){
			prices.push(array[counter]);
			std::cout << "Hello" << std::endl;
		}
		else{
			std::cout << "Hello2" << std::endl;
			int max2 = prices.len();
			if(max2 > max){
				max = max2;
			}
			prices.empty();			
		}
		counter++;
	}
	int max2 = prices.len();
	if(max2 > max){
		max = max2;
	}
	
	return max;
}

int main(){
	int array[7] = {100,80,60,70,60,75,85};
	int max = stock_span(array, 5);
	std::cout << max << std::endl;
	stack s;
	s.push(30);
	s.push(20);
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	return 0;
}
