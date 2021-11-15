/*
	BOJ2667
	<단지번호붙이기>
	문제
	<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
	그림은 아래 링크에서 확인
	https://www.acmicpc.net/problem/2667
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include<cstdio>
using namespace std;

int graph[25][25];
int v[25][25] = {0,};
int n, cnt;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector <int> ans;

void dfs(int x,int y) {
	v[x][y] = 1; //방문 표시
	cnt++;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; //범위 벗어날 경우 오류처리
		if (v[nx][ny] == 0 && graph[nx][ny]==1) 
			dfs(nx, ny);
	}
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; ++i) { //데이터 넣기
		for (int j = 0;j < n; ++j)
			scanf("%1d", &graph[i][j]);
	}

	for (int i = 0; i < n; ++i) { 
		for (int j = 0; j < n; ++j) {
			if (v[i][j] == 0 && graph[i][j] == 1) {
				cnt=0;
				dfs(i,j);
				ans.push_back(cnt);
			}
		}
	}

	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << '\n';

	return 0;
}
