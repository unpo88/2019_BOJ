#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int N, W, H;
	cin >> N >> W >> H;

	int sum = sqrt(W * W + H * H);

	while (N--) {
		int num;
		cin >> num;
		if (sum >= num) {
			cout << "DA\n";
		}
		else {
			cout << "NE\n";
		}
	}
	return 0;
}