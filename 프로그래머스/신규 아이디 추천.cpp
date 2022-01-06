#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for(int i=0;i<new_id.size();++i){ //1단계
        if('A'<=new_id[i]<='Z')
            new_id[i]=tolower(new_id[i]);   
    }
    for(int i=0;i<new_id.size();++i){ //2단계
        if(isalpha(new_id[i])||isdigit(new_id[i])||new_id[i]=='-'||new_id[i]=='_'||new_id[i]=='.') answer+=new_id[i];
    }
    //3단계
   int z=answer.find("..");
  while(z!=-1){
      answer.replace(z,2,".");
      z=answer.find(".."); 
  }
    //4단계
    if(answer[0]=='.') answer.erase(answer.begin());
    if(answer[answer.size()-1]=='.') answer.erase(answer.end()-1);
    //5단계
    if(answer.size()==0) answer.append("a");
    //6단계
    if(answer.length()>=16) answer.erase(answer.begin()+15,answer.end());
    if(answer[answer.size()-1]=='.') answer.erase(answer.end()-1);
    //7단계
    while(answer.length()<3) {
        char c=answer.back();
        answer.push_back(c);
    }

    return answer;
}
