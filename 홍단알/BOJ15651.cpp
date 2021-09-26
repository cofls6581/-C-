/*
	BOJ15651
	<N과 M (3)>
	문제
	자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
*/

#include <iostream>
using namespace std;

int arr[9];
int N, M;

void dfs(int cnt) {

	if (cnt == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
			arr[cnt] = i;
			dfs(cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> M;
	dfs(0);
	return 0;
}
