#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string s1, s2;

	int cnt = 0, cnt2 = 0; 
	
	cin >> s1 >> s2; 
	
	for (auto i : s1) 
		if (i == 'a') 
			cnt++; 
	
	for (auto i : s2) 
		if (i == 'a') 
			cnt2++; 
	
	if (cnt >= cnt2) 
		cout << "go";
	else cout << "no";

	return 0;
}