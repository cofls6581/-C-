/*
	BOJ18290
	<NM과 K (1)>
	문제
크기가 N×M인 격자판의 각 칸에 정수가 하나씩 들어있다. 이 격자판에서 칸 K개를 선택할 것이고, 선택한 칸에 들어있는 수를 모두 더한 값의 최댓값을 구하려고 한다. 단, 선택한 두 칸이 인접하면 안된다. r행 c열에 있는 칸을 (r, c)라고 했을 때, (r-1, c), (r+1, c), (r, c-1), (r, c+1)에 있는 칸이 인접한 칸이다.
*/

#include <iostream>
#include <algorithm>

using namespace std;
const int maxx = 10;

int arr[maxx][maxx];
bool check[maxx][maxx] = {false,};
int N, M, K;
int sum = -987654321;
pair<int, int> v[maxx];

bool ch(int i, int j,int cnt) {
	bool ans = true;
	for (int k = 0; k < cnt; ++k) {
		if (v[k].first + 1 == i && v[k].second == j) ans = false;
		else if (v[k].first == i && v[k].second+1 == j) ans = false;
		else if (v[k].first -1 == i && v[k].second == j) ans = false;
		else if (v[k].first  == i && v[k].second-1 == j) ans = false;
	}
	return ans;
}

void dfs(int cnt, int t) {

	if (cnt == K) {
		if (t > sum)
			sum=t;
		return;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (check[i][j] == false && ch(i, j,cnt)) {
				check[i][j] = true;
				v[cnt]={ i,j };
				dfs(cnt + 1, t+ arr[i][j]);
				check[i][j] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> arr[i][j];
	}
	dfs(0, 0);
	cout << sum;
	return 0;
}
