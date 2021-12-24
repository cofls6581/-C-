#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool cmp(string i,string j){
    if(i[N]!=j[N]) return i[N]<j[N];
    else return i<j;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    answer=strings;
    N=n;
    sort(answer.begin(),answer.end(),cmp);
    return answer;
}
