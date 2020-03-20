#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100;
const int MAXV = 1000;

int N, S, M;

int playList[MAX + 1];
int cache[MAXV + 1][MAX + 1];

int	maxVolume(int volume, int idx) {
	if (volume < 0 || volume > M)	return -100;
	if (idx == N)	return volume;

	int &result = cache[volume][idx];

	if (result != -1)
		return result;

	return result = max(maxVolume(volume + playList[idx + 1], idx + 1), maxVolume(volume - playList[idx + 1], idx + 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> S >> M;

	for (int i = 1; i <= N; i++) {
		cin >> playList[i];
	}

	memset(cache, -1, sizeof(cache));

	int result = maxVolume(S, 0);

	if (result == -100)
		cout << -1 << endl;
	else
		cout << result << endl;

	return 0;
}