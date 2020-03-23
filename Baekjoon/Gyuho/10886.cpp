#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int N;
	cin >> N;

	int cnt[2] = { 0, };

	while (N--) {
		int num;
		cin >> num;
		cnt[num]++;
	}

	if (cnt[0] > cnt[1]) {
		cout << "Junhee is not cute!";
	}
	else if(cnt[0] < cnt[1]){
		cout << "Junhee is cute!";
	}

	return 0;
}