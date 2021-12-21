//implementing roundrobin algorithm;

#include<iostream>
#include<queue>
using namespace std;

struct process{
	int processid;
	int arrtime;
	int bursttime;
	int waittime;
};

int main(){
	
	int n;
	cout<<"\nStarting the round robin application.\n";
	cout<<"Enter total no.of processes: ";
	cin >> n;
	
	std::queue<process> myqueue;
	struct process p;
	struct process res[n];
	//getting input from user
	
	for(int i=0; i<n; i++){
		
		p.processid=i+1;
		cout<<"Enter arrival time of process "<<i+1<<" : ";
		cin >> p.arrtime;
		cout<<"Enter burst time of process "<<i+1<<" : ";
		cin >> p.bursttime;
		myqueue.push(p);
	}
	cout<<endl;
	
	//considering burst time of the round robin is 5ms
	
	int i =0 ;
	myqueue.front().waittime = 0;
	int timer = 0;
	
	while (!myqueue.empty()){
		
		process temp = myqueue.front();
		myqueue.pop();
		
		if(temp.bursttime > 5){
			temp.bursttime = temp.bursttime - 5;
			myqueue.push(temp);
			timer += 5;
		}
		else{
			temp.waittime = timer + temp.bursttime;
			timer += temp.bursttime;
			temp.bursttime = 0;
			res[i] = temp;
			i++;
		}
		
	}
	
	//printing the result
	
	cout<<endl<<"\tProcessId\t"<<"completedtime\t"<<endl;
	
	for(i=0; i<n; i++){
		
		cout<<"\t"<<res[i].processid<<"\t\t"<<res[i].waittime<<endl;
		
	}
	
	return 0;
	
}
