/*
	BOJ14501
	<퇴사>
	문제
	길어서 링크로
	https://www.acmicpc.net/problem/14501
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ans=-1;
pair <int, int> v[15];

void dfs(int cnt,int temp) {
	if (cnt == N) {
		ans = max(ans, temp);
		return;
	}
	if (cnt + v[cnt].first <= N)
		dfs(cnt + v[cnt].first, temp + v[cnt].second);
	if (cnt <= N)
		dfs(cnt + 1, temp);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) 
		cin >> v[i].first>>v[i].second;
	dfs(0,0);
	cout << ans;
	return 0;
}
