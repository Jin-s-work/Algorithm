
// unordered_map을 사용하면 더 간단하게 할 수 있다.
// 프로그래머스에는 이러한 유형이 좀 더 나오는 걸로 봐서 공부해보자

#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int>mp;
    // unordered_map은 시간복잡도가 O(1)이고, 중복을 허용하지 않으므로
    // map에서 중복을 검사하는 대신 이를 사용하여 편하게 활용 가능
    // map은 O(logn)
    
    for(auto k : clothes){
        mp[k[1]]++;
    }   // 하의에 대해서 더해준다.
    
    for(auto k : mp)
        answer *= (k.second + 1);
    // int 값에 대해서 1더해서 곱해줌
    
    answer--;
    // 0으로 할 경우 곱할때 계속 0이 나오므로 이런 식으로 해준다.
    
    // 경우의 수 자체가 (a + 1) * (b + 1) - 1
    // 이런 식으로 진행
    
    return answer;
}











// map을 사용하는 살짝 더 긴 방식

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m;
    
    int size = clothes.size();
    for(int i=0;i<size;i++)
        m[clothes[i][1]]++;
    
    
    for(auto it = m.begin(); it != m.end(); it++){
        answer *= (it->second + 1);   // 각각 1더해서 곱함
    }   // 옷 종류만큼 반복하므로 (옷개수+1)을 각각 곱하고 마지막에 1 감소
    
    answer--;
    // 최소 한개는 입어야 하므로 하나도 입지 않는 경우는 마지막에 뺌
    
    return answer;
}

