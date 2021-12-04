#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int count=0,idx=0;
    
    while(idx<=s.size()-1) {
        while(s[idx]!=' '&&idx!=s.size()){
            if( count%2==0)
                s[idx]=toupper(s[idx]);
            else 
                s[idx]=tolower(s[idx]);
            ++idx; ++count;
        }
       idx++; count=0;
    }
    
    return s;
}
