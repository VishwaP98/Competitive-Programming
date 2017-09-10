#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sstream>
#include <stack>
#include <vector>

class stack_plates{
	std::vector<std::stack<int> > plates;
	int capacity;
public:
	stack_plates(int capacity);
	void push(int num);
	int pop();
	int popAt(int index);
	int getSize();
};

stack_plates::stack_plates(int cap){
	capacity = cap;
	std::stack<int> set;
	plates.push_back(set);
}

void stack_plates::push(int num){
	if(plates.back().size() != capacity){
		plates.back().push(num);
	}else{
		std::stack<int> set;
		set.push(num);
		plates.push_back(set);
	}

}

int stack_plates::pop(){
	int val = 0;
	if(plates.back().size() == 0 && plates.size() > 1){
		plates.pop_back();
		return plates.back().top();
	}
	val = plates.back().top();
	if(plates.back().size() == 0 && plates.size() > 1){
		plates.pop_back();
	}
	return val;
}

int stack_plates::popAt(int index){
	if(index > plates.size() - 1){
		printf("Exception here 1!\n");
	}
	if(plates[index].size() == 0){
		printf("Exception here 2!\n");
	}
	int val = plates[index].top();
	plates[index].pop();
	if(plates[index].size() == 0 && index != 0){
		plates.erase(plates.begin(),plates.begin() + index);
	}
	return val;
}

int stack_plates::getSize(){
	return plates.size();
}

int main(){
	 stack_plates stack(2);
	 stack.push(1);
	 stack.push(2);
	 stack.push(3);
	 printf("The size is %d\n",stack.getSize());
	 printf("The value is %d\n",stack.popAt(0));

	 stack_plates stack1(3);
	 stack1.push(1);
	 stack1.push(2);
	 stack1.push(3);
	 stack1.push(4);
	 stack1.push(5);

	 printf("The size is %d\n",stack1.getSize());
	 printf("The value is %d\n",stack1.popAt(1));
	 printf("The size is %d\n",stack1.getSize());
	 printf("The value is %d\n",stack1.popAt(1));
	 printf("The size is %d\n",stack1.getSize());

	 return 0;
}
