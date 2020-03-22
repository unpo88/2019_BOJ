#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	for (int j = 0; j < N; j++) {
		string A, B;
		cin >> A >> B;

		cout << "Distances: ";
		
		for (int i = 0; i < A.length(); i++){
			int y = B[i] - '0';
			int x = A[i] - '0';
			
			if (y - x >= 0)
				cout << y - x << " ";
			else
				cout << y - x + 26 << " ";
		}
		cout << "\n";
	}

	return 0;
}