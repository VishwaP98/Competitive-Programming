#include <iostream>
#include <string>

class Car{
	int speed;
	int money;
	std::string model;

	public:
		Car();
		Car(int, int);
		setModel(std::string);
		print(void);
	
};

Car::Car(){
	speed = 10;
	money = 1000;
}

Car::Car(int speed1, int money1){
	speed = speed1;
	money = money1;
}

Car::setModel(std::string model1){
	model = model1;
}

Car::print(){
	std::cout << speed << " " << model << " " << money << std::endl;
}
		

int main(){
	Car car (90,10000);
	car.setModel("Tesla");
	car.print();
	
	Car car2;
	car2.setModel("Bad Car");
	car2.print();
	return 0;
}
