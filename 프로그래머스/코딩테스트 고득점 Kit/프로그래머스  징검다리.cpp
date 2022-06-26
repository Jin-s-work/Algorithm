#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    // 2 11 14 17 21
    // 2 9 3 3 4 4
    
    int start = 0;
    int end = distance;
    
    while(start <= end){
        int mid = (start + end) / 2;
        int num = 0;
        int dist = 0;   // 여기서의 dist는 바위가 위치한 곳을 차례로 옮겨서 거리 재는 역할
        
        for(int i=0;i<rocks.size();i++){
            if(rocks[i] - dist < mid){
                num++;    // 차이가 mid보다 작을 경우 바위를 제거해야하므로 num을 크게 한다.
            }             // 최대로 해야하기 때문에
            else     // 차이가 mid보다 클 경우 바위를 제거할 필요 없어서 dist를 갱신
                dist = rocks[i];
        }
        
        if(distance - dist < mid)
            num++;
        // 맨 마지막에 끝과도 비교해주어야 하므로 num을 증가시킴
        
        if(num <= n){  // 없애야 할 돌의 개수가 n보다 작을 동안
            answer = max(answer, mid);
            start = mid + 1;
        }
        else        // 아닐 경우 왼쪽으로
            end = mid - 1;
    }
    
    return answer;
}

// 거리의 최대를 구하는 것이 아닌
// 각 지점 사이의 거리의 최솟값이 x를 만족하는 가 중 최대인 x를 찾는다.

// 이전 바위와의 거리가 mid보다 작으면 바위를 제거해주어야 한.
// ** mid == 거리의 최솟값 **
// 즉 위의 x가 mid라고 생각하면 됨

// 이전 바위와의 거리가 mid 이상일 경우 바위를 제거할 필요가 없어 다음 바위의 위치로 갱신

// 제거한 바위의 수가 n보다 작은 경우에서는 바위 사이의 거리의 최소가 mid가 되므로
// 다음 mid는 현재보다 크게 해야 하고, 아닐 경우 mid를 줄여 최대값을 찾는다.




// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int solution(int distance, vector<int> rocks, int n) {
//     int answer = 0;
    
//     sort(rocks.begin(), rocks.end());
//     int s = 0;
//     int e = distance;
    
//     while(s<=e){
//         int mid = (s + e) / 2;
//         int tmp = 0, num = 0;
        
//         for(int i=0;i<rocks.size();i++){
//             if(rocks[i] - tmp < mid)    // rock[i]와 전의 차이가
//                 num++;                 // mid보다 작으면 num더해줌
//             else
//                 tmp = rocks[i]; // 차이가 더 클경우 이전을 rocks[i]에 저장
//         }
        
//         if(distance - tmp < mid)
//             num++;
        
//         if(num <= n){           // 없애는 num이 n이하일 동안
//             answer = max(mid, answer);
//             s = mid + 1;
//         }
//         else
//             e = mid - 1;
        
//     }
    
    
    
//     return answer;
// }


// // 이분 탐색을 이용해 거리의 최대를 구하는 것이 아니라
// // 각 지점 사이의 거리의 최솟값이 x를 만족하는 가? 를 만족하는 x중 최대값을 찾는다.

// // 이전 바위와의 거리가 mid보다 작으면 현재 바위를 제거한다.
// // ((((( mid = 거리의 최솟값)))))

// // 이전 바위와의 거리가 mid 이상이면 바위를 제거할 필요가 없어
// // 현재 바위가 다음 바위의 이전 위치가 된다.

// // 제거한 바위의 수가 n보다 작으면 바위 사이의 거리의 최솟값이 mid가 되므로
// // 다음 mid값은 현재보다 크게 해야한다.
// // 아닌 경우 mid를 줄여 최댓값을 찾는다.
















