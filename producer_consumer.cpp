//producer comsumer

#include<iostream>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

using namespace std;

sem_t mutex, fullcount, emptycount;
int arr[5];
int front=-1, rear = -1;
int p,c;
int remove_item();
int produce_item();
void insert_item(int);
void *produce(void* z){
	
	int item;
	
	while(true){
		
		item = produce_item();
		sem_wait(&emptycount);
		sem_wait(&mutex);
		cout<<"Producer produces an item: "<<item<<endl;
		insert_item(item);
		sem_post(&mutex);
		sem_post(&fullcount);
		
	}
	
}

void *consumer(void* z){
	
	int item;
	while(true){
		sleep(2);
		sem_wait(&fullcount);
		sem_wait(&mutex);
		item = remove_item();
		cout<<"Consumer consume an item: "<<item<<endl;
		sem_post(&mutex);
		sem_post(&emptycount);
	}
	
}

int produce_item(){
	
	static int a=1;
	return a++;
	
}

void insert_item(int item){
	
	rear = rear+1;
	rear = rear%5;
	arr[rear]=item;
	
}

int remove_item(){
	
	front = front+1;
	front = front%5;
	int item = arr[front];
	return item;
	
}

int main(){
	
	int i;
	pthread_attr_t *attr=NULL;
	pthread_t pid, cid;
	sem_init(&mutex, 0 ,1);
	sem_init(&emptycount, 0, 5);
	sem_init(&fullcount, 0, 0);
	
	pthread_create(&pid, attr, produce, 0);
	pthread_create(&cid, attr, consumer, 0);
	pthread_join(pid, NULL);
	pthread_join(cid, NULL);
	
	return 0;
	
}
