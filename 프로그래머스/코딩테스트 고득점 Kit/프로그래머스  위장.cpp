#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int>mp;
    // unordered_map은 O(1)이고 중복을 제거해줘서 유용
    // map에서는 중복을 검사해야하고 O(logn)
    
    for(auto k : clothes){
        mp[k[1]]++;
    }   // 속성에 대하여 개수를 올려줌
    
    for(auto k : mp){
        answer *= (k.second + 1);
    }   // mp에 있는 개수들을 1더해서 곱해준다.
    
    answer--;
    // 경우의 수 : (a + 1) * (b + 1) - 1
    // 이런 느낌
    
    
    
    return answer;
}

// #include <string>
// #include <vector>
// #include <unordered_map>
// #include <map>

// using namespace std;

// int solution(vector<vector<string>> clothes) {
//     int answer = 1;
    
//     unordered_map<string, int>mp;
//     // unordered_map은 시간복잡도가 O(1)이고, 중복을 허용하지 않으므로
//     // map에서 중복을 검사하는 대신 이를 사용하여 편하게 활용 가능
//     // map은 O(logn)
    
//     for(auto k : clothes){
//         mp[k[1]]++;
//     }   // 하의에 대해서 더해준다.
    
//     for(auto k : mp)
//         answer *= (k.second + 1);
//     // int 값에 대해서 1더해서 곱해줌
    
//     answer--;
//     // 0으로 할 경우 곱할때 계속 0이 나오므로 이런 식으로 해준다.
    
//     // 경우의 수 자체가 (a + 1) * (b + 1) - 1
//     // 이런 식으로 진행
    
//     return answer;
// }
















