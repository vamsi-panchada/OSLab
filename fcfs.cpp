#include<iostream> 

using namespace std;

struct process{
	int arrtime;
	int bursttime;
	int waittime;
	int tattime;
//	int servicetime;
};

int main(){
	
	int n;
	cout<<"\nStarting the application.\n";
	cout<<"Enter total no.of processes: ";
	cin >> n;
	
	struct process p[n];
	
	//getting input from user
	
	for(int i=0; i<n; i++){
		
		cout<<"Enter arrival time of process "<<i+1<<" : ";
		cin >> p[i].arrtime;
		cout<<"Enter burst time of process "<<i+1<<" : ";
		cin >> p[i].bursttime;
		
	}
	cout<<endl;
	
	//sorting the processes based on the arrival time.

	for( int i=0; i<n; i++){
		
		for(int j=i; j<n; j++){
			
			if(p[i].arrtime>p[j].arrtime){
				
				
				struct process temp;
				
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
				
			}
			
		}
		
	}
	
	
	// computing the waiting time.
	
	
	p[0].waittime = 0;
	for(int i =0 ; i<n; i++){
		
		p[i].waittime = p[i-1].bursttime + p[i-1].waittime;
		
	}
	
	for(int i=0; i<n; i++){
		
		p[i].tattime = p[i].bursttime+p[i].waittime;
		
	}
	
	cout<<"\tProcess\tArrivalTime\tBurstTime\tWaitTime\tTurnAroundTime"<<endl;
	
	for(int i = 0; i< n ; i++)
	cout<<"\t"<<i<<"\t"<<p[i].arrtime<<"\t"<<p[i].bursttime<<"\t"<<p[i].waittime<<"\t"<<p[i].tattime<<endl;
	
	return 0;
}
