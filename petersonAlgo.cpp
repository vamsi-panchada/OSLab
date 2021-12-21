#include<iostream>
#include<pthread.h>
using namespace std;

void* process(void *s);

int flag[2];
int turn;
int count =0;
int mode =0;
const int MAX=1e9;



void lock_init(){
	
	flag[0] = flag[1] = 0;
	turn = 0;
	
}

void lock(int self){
	
	flag[self] = 1;
	turn = 1-self;
	
	while(flag[1-self]==1 && turn == 1-self);
	
}


void unlock(int self){
	
	flag[self] = 0;
	
}


void* process(void *s){
	
	int i=0;
	int current = (int)s;
	
	cout<<"Process : "<< current<<endl;
	
	if(mode == 1)
	lock(current);
	for(i=0; i<MAX; i++)
	count ++;
	
	
	if (mode == 1)
	unlock(current);
	
	
}




int main(){
	
	cout<<"Starting petterson's algo"<<endl;
	
	pthread_t p1, p2, p3, p4;
	
	cout<<"\n\nWithout Locking mechanism\n\n";
	
	pthread_create(&p1, NULL, process, (void*)0);
	pthread_create(&p2, NULL, process, (void*)1);
	
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	
	cout<<"Actual Count: " << count << "\tExpected Count: "<<MAX*2<<endl;
	
	cout<<"\n\nWith Locking \n\n";
	
	count = 0;
	mode = 1;
	lock_init();
	
	pthread_create(&p3, NULL, process, (void*)0);
	pthread_create(&p4, NULL, process, (void*)1);
	
	pthread_join(p3, NULL);
	pthread_join(p4, NULL);	
	
	cout<<"Actual Count: " << count << "\tExpected Count: "<<MAX*2<<endl;
	
	return 0;	
	
}
