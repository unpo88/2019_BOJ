//����
//ũ�Ⱑ 3��3�� �迭 A�� �ִ�. 1�ʰ� ���������� �迭�� ������ ����ȴ�.
//
//R ���� : �迭 A�� ��� �࿡ ���ؼ� ������ �����Ѵ�.���� ���� �� ���� ������ ��쿡 ����ȴ�.
//C ���� : �迭 A�� ��� ���� ���ؼ� ������ �����Ѵ�.���� ���� < ���� ������ ��쿡 ����ȴ�.

//	�� �� �Ǵ� ���� �ִ� ���� �����Ϸ���, ������ ���� �� �� ���Դ��� �˾ƾ� �Ѵ�.
//  �� ����, ���� ���� Ƚ���� Ŀ���� ������, �׷��� ���� ���������� ���� Ŀ���� ������ �����Ѵ�.
//  �� �������� �迭 A�� ���ĵ� ����� �ٽ� �־�� �Ѵ�.���ĵ� ����� �迭�� ���� ����, ���� ���� Ƚ���� ��� ������, ������ ���� �����̴�.
// ���� ���, [3, 1, 1]���� 3�� 1��, 1�� 2�� �����Ѵ�.����, ���ĵ� �����[3, 1, 1, 2]�� �ȴ�.�ٽ� �� �迭���� 3�� 1��, 1�� 2��, 2�� 1�� �����Ѵ�.�ٽ� �����ϸ�[2, 1, 3, 1, 1, 2]�� �ȴ�.
//	���ĵ� ����� �迭�� �ٽ� ������ �� �Ǵ� ���� ũ�Ⱑ Ŀ�� �� �ִ�.
//R ������ ����� ��쿡�� ���� ũ�Ⱑ ���� ū ���� �������� ��� ���� ũ�Ⱑ Ŀ����, 
//C ������ ����� ��쿡�� ���� ũ�Ⱑ ���� ū ���� �������� ��� ���� ũ�Ⱑ Ŀ����.�� �Ǵ� ���� ũ�Ⱑ Ŀ�� ������ 0�� ä������.
//���� ������ �� 0�� �����ؾ� �Ѵ�.���� ���, [3, 2, 0, 0]�� ������ �����[3, 2]�� ������ ����� ����.
//	�� �Ǵ� ���� ũ�Ⱑ 100�� �Ѿ�� ��쿡�� ó�� 100���� ������ �������� ������.
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

//	�迭 A�� ����ִ� ���� r, c, k�� �־����� ��, A[r][c]�� ����ִ� ���� k�� �Ǳ� ���� �ּ� �ð��� ���غ���.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	//	ù° �ٿ� r, c, k�� �־�����. (1 �� r, c, k �� 100)
	cin >> r >> c >> k;

	// ũ�Ⱑ 3��3�� �迭 A�� �ִ�. 1�ʰ� ���������� �迭�� ������ ����ȴ�.
	//	��° �ٺ��� 3���� �ٿ� �迭 A�� ����ִ� ���� �־�����.�迭 A�� ����ִ� ���� 100���� �۰ų� ���� �ڿ����̴�.
	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 3; ++x) {
			cin >> A[y][x];
		}
	}

	//	A[r][c]�� ����ִ� ���� k�� �Ǳ� ���� ������ �ּ� �ð��� ����Ѵ�.�� ���� 100�� �Ѿ�� ��쿡�� - 1�� ����Ѵ�.
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