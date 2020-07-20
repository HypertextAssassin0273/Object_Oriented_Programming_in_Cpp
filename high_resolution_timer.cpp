#include<iostream>
#include<windows.h>
class CTimer{
public:
	CTimer() {
		QueryPerformanceFrequency(&mqFreq);
	}
	~CTimer() {}

	void Start() {
		QueryPerformanceCounter(&mqStart);
	}
	void End() {
		QueryPerformanceCounter(&mqEnd);
	}
	double GetTimeInSeconds() {
		return (mqEnd.QuadPart - mqStart.QuadPart)/(double)mqFreq.QuadPart;
	}
	double GetTimeInMilliseconds() {
		return (1.0e3*(mqEnd.QuadPart - mqStart.QuadPart))/mqFreq.QuadPart;
	}
	double GetTimeInMicroseconds() {
		return (1.0e6*(mqEnd.QuadPart - mqStart.QuadPart))/mqFreq.QuadPart;
	}
	double GetTimeInNanoseconds() {
		return (1.0e9*(mqEnd.QuadPart - mqStart.QuadPart))/mqFreq.QuadPart;
	}

private:
	LARGE_INTEGER mqStart;
	LARGE_INTEGER mqEnd;
	LARGE_INTEGER mqFreq;
};

void Bubblesort(int iaArray[], int iLength)
{
	for (int iIndex1 = 0; iIndex1 < iLength; ++iIndex1) {
		for (int iIndex2 = 0; iIndex2 < iLength - iIndex1 - 1; ++iIndex2) {
			if (iaArray[iIndex2] > iaArray[iIndex2 + 1]) {
				int iTemp = iaArray[iIndex2];
				iaArray[iIndex2] = iaArray[iIndex2 + 1];
				iaArray[iIndex2 + 1] = iTemp;
			}
		}
	}
}
int main(){
	using namespace std;
	// Fill an array with random integer values for sorting
	const int kiLength = 10000;
	int iaArray[kiLength];
	for (int iIndex = 0; iIndex < kiLength; ++iIndex) {
		iaArray[iIndex] = rand();
	}
	// Time the sort
	CTimer qTimer;
	qTimer.Start();
	Bubblesort(iaArray, kiLength);
	qTimer.End();
	cout << qTimer.GetTimeInSeconds() << " seconds" << endl;
	cout << qTimer.GetTimeInMilliseconds() << " milliseconds" << endl;
	cout << qTimer.GetTimeInMicroseconds() << " microseconds" << endl;
	cout << qTimer.GetTimeInNanoseconds() << " nanoseconds" << endl;
}
