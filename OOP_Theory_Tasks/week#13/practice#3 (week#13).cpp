#include <iostream> 
#include <iterator> 
#include <map> 
using namespace std; 

int main(){
	// empty map container 
	map<int, string> gquiz1; 

	// insert elements in random order 
	gquiz1.insert(pair<int, string>(1, "mangoes")); 
	gquiz1.insert(pair<int, string>(2, "apples")); 
	gquiz1.insert(pair<int, string>(3, "bananas")); 
	gquiz1.insert(pair<int, string>(4, "grapes")); 
	gquiz1.insert(pair<int, string>(4, "apples")); //i.e. this pair will be discarded as key is same as above
	gquiz1.insert(pair<int, string>(5, "oranges")); 
	gquiz1.insert(pair<int, string>(6, "pineapples")); 

	// printing map gquiz1 
	cout << "The map gquiz1 is : \n\tKEY\tELEMENT\n"; 
	for (const auto& itr : gquiz1) //i.e. auto -> map<int, int>::iterator itr; 
		cout << '\t' << itr.first << '\t' << itr.second << endl; 

	// assigning the elements from gquiz1 to gquiz2 
	map<int, string> gquiz2(gquiz1.begin(), gquiz1.end()); 

	// print all elements of the map gquiz2 
	cout << "\nThe map gquiz2 after assign from gquiz1 is : \n\tKEY\tELEMENT\n"; 
	for (const auto& itr : gquiz2)
		cout << '\t' << itr.first << '\t' << itr.second << endl; 

	// remove all elements up to element with key=3 in gquiz2 
	cout << "\ngquiz2 after removal of elements less than key = 3 : \n\tKEY\tELEMENT\n"; 
	gquiz2.erase(gquiz2.begin(), gquiz2.find(3)); 
	for (const auto& itr : gquiz2)
		cout << '\t' << itr.first << '\t' << itr.second << endl;

	// remove all elements with key = 4
	cout << "\ngquiz2.erase(4) : index "<< gquiz2.erase(4) << "data removed \n\tKEY\tELEMENT\n"; 
	for (const auto& itr : gquiz2)
		cout << '\t' << itr.first << '\t' << itr.second << endl; 

	// lower bound and upper bound for map gquiz1 key = 5 
	cout << "\ngquiz1.lower_bound(5) : \tKEY = " << gquiz1.lower_bound(5)->first << '\t'; 
	cout << "\tELEMENT = "<< gquiz1.lower_bound(5)->second << endl; 
	cout << "gquiz1.upper_bound(5) : \tKEY = " << gquiz1.upper_bound(5)->first << '\t'; 
	cout << "\tELEMENT = "<< gquiz1.upper_bound(5)->second << endl;
	return 0; 
} 

