#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    string day[] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int sum=0;
    
    for(int i=0;i<a-1;++i)
        sum+=month[i];
    sum+=b-1;
    answer=day[sum%7];
    
    return answer;
}
