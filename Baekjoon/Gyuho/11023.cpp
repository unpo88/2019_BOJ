#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	int n, sum = 0;
	while (scanf("%d", &n) != EOF)
		sum += n;

	cout << sum << '\n';

	return 0;
}