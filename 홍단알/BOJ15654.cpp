/*
	BOJ15654
	<N과 M (5)>
	문제
	N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

N개의 자연수 중에서 M개를 고른 수열
*/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
int num[9];
bool check[9];
int N, M;

void dfs(int cnt) {

	if (cnt == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			check[i] = true;
			arr[cnt] = num[i-1];
			dfs(cnt + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num,num+N);
	dfs(0);
}
