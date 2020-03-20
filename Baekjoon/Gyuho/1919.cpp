#include <iostream>
#include <string>
using namespace std;

int alpha1[26];
int alpha2[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.length(); i++) {
		alpha1[a[i] - 'a']++;
	}
	
	for (int i = 0; i < b.length(); i++) {
		alpha2[b[i] - 'a']++;
	}

	int cnt = 0;

	for (int i = 0; i < 26; i++) {
		if (alpha1[i] != alpha2[i])	cnt += abs(alpha1[i] - alpha2[i]);
	}
	
	cout << cnt;

	return 0;
}