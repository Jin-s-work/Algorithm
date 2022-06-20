

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int>mp;
    for(auto k : participant)
        mp[k]++;
    for(auto k : completion)
        mp[k]--;
    // 있으면 ++로 증가시키고, 또 있으면 다시 completion으로 줄인다.
    
    for(auto k : mp){
        if(k.second == 1)
            return k.first;
    }
    // map을 쓰는 법이 다시 기억났다..
    // 같은지 보는거 이므로 그냥 sort해서 다른 부분 찾으면 되긴 할듯..
        
    return answer;
}


// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <unordered_map>
// #include <map>

// using namespace std;

// string solution(vector<string> participant, vector<string> completion) {
    
//     map<string, int>mp;
    
//     for(auto k : participant)
//         mp[k]++;
//     // 라고 하면 mp의 k인 string에서 숫자를 하나 증가시켜줌
//     for(auto k : completion)
//         mp[k]--;
    
//     for(auto k : mp){
//         if(k.second == 1)
//             return k.first;
//     }
//     // map의 string, int 구조를 파악하기 좋다.
//     // string에 따라서 중복은 없이 int를 증가시켜주어서 k에 따라 k.second가 아직
//     // 1인 것을 찾아서 first를 출력해준다.
    
// }













