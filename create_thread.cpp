#include<windows.h>
#include<iostream>
DWORD WINAPI ThreadFn(LPVOID vpParam);
int main(){
	using namespace std;
	// Create the thread and pass in the function pointer and counter
	unsigned int uiCounter = 0;
	DWORD qThreadID;
	HANDLE hThread = CreateThread(0, 0, ThreadFn, &uiCounter, 0, &qThreadID);

	// Loop until the user enters 'q'
	char cChar = ' ';
	while (cChar != 'q') {
		cout << uiCounter << endl;
		cChar = (char)getchar();
	}

	// Close the handle to the thread
	CloseHandle(hThread);

	return 0;
}
DWORD WINAPI ThreadFn(LPVOID vpParam){
	unsigned int& uirCounter = *((unsigned int*)vpParam);
	// Increment up to the maximum value
	while (uirCounter < 0xFFFFFFFF) {
		++uirCounter;
	}
	return 0;
}
