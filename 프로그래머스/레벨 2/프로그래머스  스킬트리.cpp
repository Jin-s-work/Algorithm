
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    map<char, int> mp;
    
    for(int i=0;i<skill.size();i++){
        mp[skill[i]] = i+1;
    }
    
    for(auto k : skill_trees){
        int num = 1;
        bool check = true;
        // k는 즉 각각의 문자열들을 의미
        
        for(int i=0;i<k.length();i++){
            if(mp[k[i]] > num){
                check = false;
                break;
            }
            // 아직 1도 안나왔는데, mp[k[i]]가 그거 보다 크면 false
            // mp[k[i]]는 mp에 관해서 k를 움직이며 문자열을 찾아줌
            // check를 false로 하고 끝내줌
            
            else if(mp[k[i]] == num){
                num++;
            }   // 같을 경우 num을 증가시켜줌
            
        }
        if(check)
            answer++;
    }
    
    
    
    
    return answer;
}





#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    map<char, int> mp;
    
    for(int i=0;i<skill.length();i++){
        mp[skill[i]] = i+1;
        // char는 skill[i]이고, int는 i+1이 된다.
    }
    
    for(auto k : skill_trees){
        int num = 1;
        bool check = true;
        
        for(int i=0;i<k.length();i++){
            if(mp[k[i]] > num){
                check = false;
                break;
                // 하나라도 큰 int 값이 있다면 false하고 break
            }
            else if(mp[k[i]] == num)
                num++;
        }
        
        if(check)
            answer++;
        // check가 계속 true로 나왔다면
        
    }
    
    
    return answer;
}












