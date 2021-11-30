

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer;
    
    int w = 0;
    int h = 0;
    
    for(auto k : sizes){
        w = max(w, max(k[0], k[1]));
        // 하나는 최대 중 골라 계속 최대를 찾아주고
        h = max(h, min(k[0], k[1]));
        // 하나는 최소 중 제일 큰 최소를 찾아준다.
    }
    // 이렇게 둘을 바꾸어 보면서 하지 않고, 둘을 같이 비교하면 간단하게 가능
    
    answer = w * h;
    
    return answer;
}













