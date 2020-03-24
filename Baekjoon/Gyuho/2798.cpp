#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	int A[100];
	cin >> N >> M;
	int result = 0;
	for (int i = 0; i < N; i++) cin >> A[i];

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				if (A[i] + A[j] + A[k] <= M && M - (A[i] + A[j] + A[k]) < M - result)
				{
					result = A[i] + A[j] + A[k];
				}
			}
		}
	}
	cout << result;

	return 0;
}