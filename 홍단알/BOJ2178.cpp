/*
	BOJ2178
	<미로 탐색>
	문제
	N×M크기의 배열로 표현되는 미로가 있다.
	미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
	위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define max 100

int visit[max][max] = {0, }; //방문 기록
int ans[max][max];
int map[max][max]; 
queue<pair<int, int>> q;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n, m;

void bfs(int x, int y) {
	visit[x][y] = 1;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = dx[i] + xx;
			int ny = dy[i] + yy;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 1 && visit[nx][ny] == 0) {
				visit[nx][ny] = 1;
				q.push(make_pair(nx, ny));
				ans[nx][ny]=ans[xx][yy] + 1;
			}

		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	cin >> n >> m; 
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < m; j++) {
			map[i][j] = input[j] - '0';
		}
	}
	ans[0][0] = 1;
	bfs(0, 0);

	cout << ans[n - 1][m - 1];

	return 0;
}
