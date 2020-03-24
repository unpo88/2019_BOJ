#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int K;
int N;
int S;
int Y;
int cnt;
int arr[2][6];

int main() {

	cin >> N;
	cin >> K;

	cnt = 0;
	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < N; i++) {
		cin >> S;
		cin >> Y;

		arr[S][Y - 1]++;

	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			double temp;

			temp = arr[i][j] / (double)K;
			cnt += ceil(temp);
		}
	}

	cout << cnt;

	return 0;
}