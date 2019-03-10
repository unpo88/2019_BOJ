// [시뮬레이션 + DFS]
// 1. 축구를 하기 위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다.이제 N / 2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.
// 2. BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고,
//    아래와 같은 능력치를 조사했다.능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치이다.
//    팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다.Sij는 Sji와 다를 수도 있으며, i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다.

//    N = 4이고, S가 아래와 같은 경우를 살펴보자.
//	  i\j	1	2	3	4
//     1	 	1	2	3
//     2	4	 	5	6
//     3	7	1	 	2
//     4	3	4	5

//	  예를 들어, 1, 2번이 스타트 팀, 3, 4번이 링크 팀에 속한 경우에 두 팀의 능력치는 아래와 같다.
//    스타트 팀 : S12 + S21 = 1 + 4 = 5
//    링크 팀 : S34 + S43 = 2 + 5 = 7

//    1, 3번이 스타트 팀, 2, 4번이 링크 팀에 속하면, 두 팀의 능력치는 아래와 같다.
//    스타트 팀 : S13 + S31 = 2 + 7 = 9
//    링크 팀 : S24 + S42 = 6 + 4 = 10

// 3. 축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다.
//    위의 예제와 같은 경우에는 1, 4번이 스타트 팀, 2, 3번 팀이 링크 팀에 속하면
//    스타트 팀의 능력치는 6, 링크 팀의 능력치는 6이 되어서 차이가 0이 되고 이 값이 최소이다.
// 4. 첫째 줄에 N(4 ≤ N ≤ 20, N은 짝수)이 주어진다.
// 5. 둘째 줄부터 N개의 줄에 S가 주어진다.각 줄은 N개의 수로 이루어져 있고,
//    i번 줄의 j번째 수는 Sij 이다.Sii는 항상 0이고, 나머지 Sij는 1보다 크거나 같고, 100보다 작거나 같은 정수이다.
// 6. 첫째 줄에 스타트 팀과 링크 팀의 능력치의 차이의 최솟값을 출력한다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// N(4 ≤ N ≤ 20, N은 짝수)
#define MAX_SIZE 21

// 1. 축구를 하기 위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다.이제 N / 2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.
int n;
bool is_used[MAX_SIZE];
int s[MAX_SIZE][MAX_SIZE];
int ans = 987654321;

// curr_player번 선수를 스타트 팀으로 뽑는다, cnt : 뽑은 명수
void Dfs(int curr_player, int cnt)
{
	// n/2명을 뽑았으면 차이를 계산
	if (cnt == n / 2)
	{
		vector<int> team_link, team_start;

		// 뽑은 선수들은 스타트팀으로
		for (int i = 0; i < n; i++)
		{
			if (is_used[i]) team_start.push_back(i);
			else team_link.push_back(i);
		}

		// 스타트팀과 링크팀의 능력치 차이 구하기
		int stat_start = 0, stat_link = 0;
		for (int i = 0; i < team_start.size(); i++)
		{
			for (int j = i + 1; j < team_start.size(); j++)
			{
				int start_x = team_start[i];
				int start_y = team_start[j];
				int link_x = team_link[i];
				int link_y = team_link[j];
				stat_start += s[start_x][start_y] + s[start_y][start_x];
				stat_link += s[link_x][link_y] + s[link_y][link_x];
			}
		}

		// 3. 축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다.
		ans = min(ans, abs(stat_start - stat_link));
		return;
	}

	// 완전탐색 -> DFS 기본
	for (int i = curr_player + 1; i < n; i++)
	{
		if (is_used[i] == false)
		{	
			// 원 상태
			is_used[i] = true;
			// 백트래킹
			Dfs(i, cnt + 1);
			// 이전 상태
			is_used[i] = false;
		}
	}
}

// 3. 축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다.
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 4. 첫째 줄에 N(4 ≤ N ≤ 20, N은 짝수)이 주어진다.
	cin >> n;

	// 5. 둘째 줄부터 N개의 줄에 S가 주어진다.각 줄은 N개의 수로 이루어져 있고,
	//    i번 줄의 j번째 수는 Sij 이다.Sii는 항상 0이고, 나머지 Sij는 1보다 크거나 같고, 100보다 작거나 같은 정수이다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> s[i][j];
		}
	}

	// 모든 경우의 수 탐색
	Dfs(0, 0);

	// 6. 첫째 줄에 스타트 팀과 링크 팀의 능력치의 차이의 최솟값을 출력한다.
	cout << ans << "\n";

	return 0;
}