/*
	BOJ11724
	<연결 요소의 개수>
	문제
	방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <vector>

using namespace std;

int n, m;
int v[1001] = {0,};
int cnt;
vector <int> graph[1001];

void dfs(int idx) {
	v[idx] = 1; //방문 표시
	for (int i = 0; i < graph[idx].size(); ++i) {
		int next = graph[idx][i];
		if (v[next] == 0) 
			dfs(next);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n>>m;
	int x, y;
	for (int i = 1; i <= m; ++i) { //간선 값 넣기
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		if (v[i]==0) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
	return 0;
}
