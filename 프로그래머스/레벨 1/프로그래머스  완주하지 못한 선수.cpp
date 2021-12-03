

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    map<string, int>mp;
    
    for(auto k : participant)
        mp[k]++;
    // 라고 하면 mp의 k인 string에서 숫자를 하나 증가시켜줌
    for(auto k : completion)
        mp[k]--;
    
    for(auto k : mp){
        if(k.second == 1)
            return k.first;
    }
    // map의 string, int 구조를 파악하기 좋다.
    // string에 따라서 중복은 없이 int를 증가시켜주어서 k에 따라 k.second가 아직
    // 1인 것을 찾아서 first를 출력해준다.
    
}




// 전에 unordered_map으로 푼 풀이
// unordered_map으로 하면 시간복잡도가 O(1)라서 map보다 효율적이긴 하다.

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_map<string, int> m;
    
    for(string name: participant)
        m[name]++;                 // 참가의 경우 그냥 더 해준다.
    for(string name: completion)
        m[name]--;                  // 완료한 경우 그냥 빼준다.
    for(auto pair: m){
        if(pair.second>0)       // 두번째 값이 0 초과일 경우
            return pair.first;  // 첫번째 값을 return한다.
    }
    
}


