/*
	BOJ15650
	<N과 M (2)>
	문제
	자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
고른 수열은 오름차순이어야 한다.
*/

#include <iostream>
using namespace std;

int arr[9];
bool check[9];
int N, M;

void dfs(int n,int cnt) {

	if (cnt == M) {
		for (int i = 0; i < M; i++) 
			cout << arr[i] << ' ';
		cout << '\n';
	}
	for (int i = n; i <= N; i++) {
		if (!check[i]) {
			check[i] = true;
			arr[cnt] = i;
			dfs(i + 1,cnt+1);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> M;
	dfs(1,0);
}
