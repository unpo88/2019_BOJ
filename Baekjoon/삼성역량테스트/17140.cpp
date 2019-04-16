//문제
//크기가 3×3인 배열 A가 있다. 1초가 지날때마다 배열에 연산이 적용된다.
//
//R 연산 : 배열 A의 모든 행에 대해서 정렬을 수행한다.행의 개수 ≥ 열의 개수인 경우에 적용된다.
//C 연산 : 배열 A의 모든 열에 대해서 정렬을 수행한다.행의 개수 < 열의 개수인 경우에 적용된다.

//	한 행 또는 열에 있는 수를 정렬하려면, 각각의 수가 몇 번 나왔는지 알아야 한다.
//  그 다음, 수의 등장 횟수가 커지는 순으로, 그러한 것이 여러가지면 수가 커지는 순으로 정렬한다.
//  그 다음에는 배열 A에 정렬된 결과를 다시 넣어야 한다.정렬된 결과를 배열에 넣을 때는, 수와 등장 횟수를 모두 넣으며, 순서는 수가 먼저이다.
// 예를 들어, [3, 1, 1]에는 3이 1번, 1가 2번 등장한다.따라서, 정렬된 결과는[3, 1, 1, 2]가 된다.다시 이 배열에는 3이 1번, 1이 2번, 2가 1번 등장한다.다시 정렬하면[2, 1, 3, 1, 1, 2]가 된다.
//	정렬된 결과를 배열에 다시 넣으면 행 또는 열의 크기가 커질 수 있다.
//R 연산이 적용된 경우에는 행의 크기가 가장 큰 행을 기준으로 모든 행의 크기가 커지고, 
//C 연산이 적용된 경우에는 열의 크기가 가장 큰 열을 기준으로 모든 열의 크기가 커진다.행 또는 열의 크기가 커진 곳에는 0이 채워진다.
//수를 정렬할 때 0은 무시해야 한다.예를 들어, [3, 2, 0, 0]을 정렬한 결과는[3, 2]를 정렬한 결과와 같다.
//	행 또는 열의 크기가 100을 넘어가는 경우에는 처음 100개를 제외한 나머지는 버린다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k;
int A[101][101];

int check[101];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

//	배열 A에 들어있는 수와 r, c, k가 주어졌을 때, A[r][c]에 들어있는 값이 k가 되기 위한 최소 시간을 구해보자.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	//	첫째 줄에 r, c, k가 주어진다. (1 ≤ r, c, k ≤ 100)
	cin >> r >> c >> k;

	// 크기가 3×3인 배열 A가 있다. 1초가 지날때마다 배열에 연산이 적용된다.
	//	둘째 줄부터 3개의 줄에 배열 A에 들어있는 수가 주어진다.배열 A에 들어있는 수는 100보다 작거나 같은 자연수이다.
	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 3; ++x) {
			cin >> A[y][x];
		}
	}

	//	A[r][c]에 들어있는 값이 k가 되기 위한 연산의 최소 시간을 출력한다.이 값이 100을 넘어가는 경우에는 - 1을 출력한다.
	int time = 0;

	int i = 3;
	int j = 3;
	int jj = 0;
	int ii = 0;

	while (A[r-1][c-1] != k) {
		if (time > 100) {
			cout << "-1\n";
			return 0;
		}

		int temp_A[101][101] = { 0, };
		
		if (i >= j) {
			for (int y = 0; y < i; ++y) {
				vector<pair<int, int> > v;
				for (int x = 0; x < j; ++x) {
					check[A[y][x]]++;
				}

				for (int k = 0; k < 101; ++k) {
					if (check[k]) {
						v.push_back(make_pair(k, check[k]));
					}
				}

				for (int x = 0; x < j; ++x) {
					check[A[y][x]] = 0;
				}

				sort(v.begin(), v.end(), cmp);

				vector<int> v2;
				
				for (int k = 0; k < v.size(); ++k) {
					if (v[k].first != 0) {
						//cout << v[k].first << " " << v[k].second << ", ";
						v2.push_back(v[k].first);
						v2.push_back(v[k].second);
					}
				}
				
				for (int k = 0; k < v2.size(); ++k) {
					if (jj < v2.size()) {
						jj = v2.size();
					}
					temp_A[y][k] = v2[k];
				}
			}
			
			j = jj;

			for (int y = 0; y < i; ++y) {
				for (int x = 0; x < j; ++x) {
					A[y][x] = temp_A[y][x];
					//cout << A[y][x] << " ";
				}
				//cout << "\n";
			}
		}
		else {
			for (int x = 0; x < j; ++x) {
				vector<pair<int, int> > v;
				for (int y = 0; y < i; ++y) {
					check[A[y][x]]++;
				}

				for (int k = 0; k < 101; ++k) {
					if (check[k]) {
						v.push_back(make_pair(k, check[k]));
					}
				}

				for (int y = 0; y < i; ++y) {
					check[A[y][x]] = 0;
				}

				sort(v.begin(), v.end(), cmp);

				vector<int> v2;

				for (int k = 0; k < v.size(); ++k) {
					if (v[k].first != 0) {
						//cout << v[k].first << " " << v[k].second << ", ";
						v2.push_back(v[k].first);
						v2.push_back(v[k].second);
					}
				}
				//cout << endl;

				for (int k = 0; k < v2.size(); ++k) {
					if (ii < v2.size()) {
						//cout << v2.size() << endl;
						ii = v2.size();
					}
					temp_A[k][x] = v2[k];
				}		
			}

			i = ii;

			for (int y = 0; y < i; ++y) {
				for (int x = 0; x < j; ++x) {
					A[y][x] = temp_A[y][x];
					//cout << A[y][x] << " ";
				}
				//cout << "\n";
			}
		}
		time++;
	}
	
	cout << time << "\n";
	return 0;
}