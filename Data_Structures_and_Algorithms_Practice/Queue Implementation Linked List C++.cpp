#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Queue{
	int rear;
	int front;
	int size;
	unsigned capacity;
	int * array;
};

struct Queue * create_queue(unsigned capacity){
	
	struct Queue * queue = new Queue;
	queue->size = queue->front = 0;
	queue->capacity = capacity;
	queue->rear = -1;
	int* array2 = new int[queue->capacity];
	queue->array = array2;
	return queue;
}
int isFull(Queue * queue){
	return (queue->size != queue->capacity);
}

int isEmpty(Queue * queue){
	return (queue->size != 0);
}

void enqueue(struct Queue * queue, int key){
	if(isFull(queue)){
		queue->rear = (queue->rear + 1) % queue->capacity;
		queue->array[queue->rear] = key;
		queue->size = queue->size + 1;
		printf("Enqueued %d %d \n", key, queue->array[queue->rear]);
	}
}

int dequeue(struct Queue * queue){
	int item = -1;
	if(isEmpty(queue)){
		item = queue->array[queue->front];
		queue->front = (queue->front + 1) % queue->capacity;
		queue->size = queue->size - 1;
	}
	return item;
}

int front(struct Queue * queue){
	int front = -1;
	if(isEmpty(queue)){
		front = queue->array[queue->front];
	}
	return front;
}

int rear(struct Queue * queue){
	int rear = -1;
	if(isEmpty(queue)){
		rear = queue->array[queue->rear];
	}
	return rear;
}

void print_queue(struct Queue * queue){
	while(queue->front != queue->rear + 1){
		printf("%d ",queue->array[queue->front]);
		queue->front = (queue->front + 1) % queue->capacity;
	}
	printf("\n");
}

int main(){
	struct Queue* queue = create_queue(5);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    printf("%d dequeued from queue\n", dequeue(queue));
 
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
    
    print_queue(queue);

	return 0;
}
