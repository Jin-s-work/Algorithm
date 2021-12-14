=

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    
    int start = routes[0][1];   // 가장 빨리 고속도로를 진입한 진출 시점
    
    for(int i=1;i<routes.size();i++){
        if(routes[i][1] < start)
            start = routes[i][1];
            // 카메라 설치한 것보다 나가는 지점이 앞에 있으면
            // 그 차량의 나가는 지점으로 바꾼다.
        // 즉 더 전에꺼 보다 맨 마지막이 안에 있을 경우
        // start를 더 앞으로 설정해준다.
        if(routes[i][0] > start){
            answer++;
            start = routes[i][1];
        }
        // 카메라 설치 한 것보다 들어온게 뒤에 있으면
        // 카메라 하나 더 있어야 하므로 answer 증가시키고,
        // 시작을 그 차가 나가는 지점으로 해준다.
        
        // 그게 아니라 시작하는 부분이 start의 경우보다 뒤에 있으면 하나 더 증가시키고,
        // start를 끝나는 부분으로 설정해준다.
    }
    
    
    
    return answer;
}
