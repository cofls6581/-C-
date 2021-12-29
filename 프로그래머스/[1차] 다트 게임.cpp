#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector <int> score;
    int idx=0;
    
    for(int i=0;i<dartResult.length();++i){
        if(dartResult[i]=='S') continue;
        else if(dartResult[i]=='D')
            score[idx-1]=pow(score[idx-1],2);
        else if(dartResult[i]=='T')
            score[idx-1]=pow(score[idx-1],3);
    
        else if(dartResult[i]=='*'){
            if(idx>1){
                score[idx-2]*=2;
                score[idx-1]*=2;
            }
            else score[idx-1]*=2;
        }
        else if (dartResult[i] == '#') 
			score[idx - 1]*= -1;
		
        else{
            if (dartResult[i + 1] == '0') {
				score.push_back(10);
				i++;
			}	
			else 
				score.push_back(dartResult[i] -'0');
            idx++;
        }
    }

    for(int i=0;i<score.size();++i)
        answer+=score[i];
    
    return answer;
}
