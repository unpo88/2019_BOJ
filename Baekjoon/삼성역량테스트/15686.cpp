#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits.h>
using namespace std;

int map[51][51];
int N, M;
bool check[13];

vector<pair<int, int> > house;
vector<pair<int, int> > chicken;

int answer = INT_MAX;

void BFS(int idx, int cnt) {
	if (idx > chicken.size())	return;

	if (cnt == M) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int dist = INT_MAX;
			for (int j = 0; j < chicken.size(); j++) {
				if (check[j]) {
					int d = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
					dist = min(dist, d);
				}
			}
			sum += dist;
		}
		answer = min(answer, sum);
		return;
	}

    // 완전 탐색
    for(int i = idx; i < chicken.size(); i++){
        if(check[i] == false){
            check[i] = true;
            BFS(i, cnt + 1);
            check[i] = false;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
		}
	}

	BFS(0, 0);

	cout << answer << endl;

	return 0;
}