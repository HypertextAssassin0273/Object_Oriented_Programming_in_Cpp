#include <iostream>
#include <thread>

using namespace std;

void Loop() {
	int count;
    while(count<1000000) {
    	count++;
       cout<<"hi ";
    }
}

void SecondLoop() {
	int count;
    while(count<1000000) {
    	count++;
        cout<<"bye ";
    }
}

int main() {
    thread t1(Loop);
    thread t2(SecondLoop);
    
    t1.join();
    t2.join();

    return false;
}
