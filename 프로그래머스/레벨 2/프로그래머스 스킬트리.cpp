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

// <char, int>를 사용하는 map 즉 해시를 사용해야 한다.
// mp[char] = int 라고 하면 char, int 형식으로 저장이 된다.
