#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	while (N--) {
		int r, e, c;
		cin >> r >> e >> c;

		if (e - r > c) {
			cout << "advertise" << "\n";
		}
		else if(e - r == c){
			cout << "does not matter" << "\n";
		}
		else {
			cout << "do not advertise" << "\n";
		}
	}
	

	return 0;
}