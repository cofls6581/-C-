#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    string substr="";
    char star='*';
    int n=phone_number.size();
    for(int i=0;i<(n-4);i++)
        answer.push_back(star);
    substr=phone_number.substr((n-4),4);
    answer=answer+substr;
    return answer;
}
