#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string A, B;
	cin >> A >> B;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] == '6')	A[i] = '5';
	}

	for (int i = 0; i < B.size(); i++) {
		if (B[i] == '6')		B[i] = '5';
	}

	cout << stoi(A) + stoi(B) << " ";

	for (int i = 0; i < A.size(); i++) {
		if (A[i] == '5')	A[i] = '6';
	}

	for (int i = 0; i < B.size(); i++) {
		if (B[i] == '5')		B[i] = '6';
	}

	cout << stoi(A) + stoi(B) << " ";

	return 0;
}