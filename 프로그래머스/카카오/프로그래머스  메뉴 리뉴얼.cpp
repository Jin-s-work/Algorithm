#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, int> mp[11];
// 중복을 없애주고, [음식 이름, 횟수]
// index는 음식의 수 즉 mp[4] : 4가지로 만드든 음식의 조합

int cnt[11];
void DFS(string st, int num, string ans){
    if(num == st.size()){
        int ans_num = ans.size();       // 메뉴 개수
        mp[ans_num][ans]++;             // ans : 메뉴 조합
        // 음식이름, 횟수
        cnt[ans_num] = max(cnt[ans_num], mp[ans_num][ans]);
        // 최대인 것으로 갱신한다.
        return;
    }
    
    DFS(st, num + 1, ans + st[num]);   // 해당 문자를 선택
    DFS(st, num + 1, ans);             // 해당 문자를 선택 x
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto k : orders){
        sort(k.begin(), k.end());       // 오름차순이어야 한다.
        DFS(k, 0, "");
    }
    
    for(auto k : course){               // course에 맞는 것 뽑아 넣음
        for(auto num : mp[k]){          // 2명 이상이 시켜야 함
            if(num.second == cnt[k] && num.second >= 2)
                answer.push_back(num.first);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}















