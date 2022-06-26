

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long start = 1;
    long long end = (long long) times[times.size() - 1] * n;
    // 가장 오래 걸리는 사람에게 모두가 갔을 경우 (그래서 n을 곱해준다.) : 즉 최대 시간
    
    long long mid;
    
    
    while(start <= end){
        mid = (start + end) / 2;
        
        long long num = 0;
        for(int i=0;i<times.size();i++){
            num += mid / times[i];
        }   // num에다가 mid라는 시간에 times를 모두 나누어 얼마 걸릴지 더한다.
        
        // ** num이 mid 시간 동안 처리 할 수 있는 사람 이고
        // ** n이 처리해야할 사람 이므로 num < n 일 경우에 처리 할 수 없으므로 더 늘려준다.
        
        // mid 시간 동안 처리할 수 있는 사람의 경우 : num가 n보다 작으면
        if(num < n){    // 이분탐색에서 오른쪽으로
            start = mid + 1;
        }
        // mid 시간 동안 처리 할 수 있는 사람이 더 많으므로 가능하다는 뜻
        else{                   // 아닐 경우 즉 num이 n보다 크면
            if(mid <= end)      // 이때 mid가 end 전에 있다면
                answer = mid;   // 최솟값이 될수 있으므로 answer에 mid를 넣어준다.
                                
            end = mid - 1;     // 다른 최솟값이 있을 수도 있으니 왼쪽으로 이동하여 더 탐색한다.
        }
        
        
    }
    
    
    return answer;
}



// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// long long solution(int n, vector<int> times) {
//     long long answer = 0;
//     long long high;
    
//     sort(times.begin(), times.end());
    
//     high = (long long)times[times.size()-1] * n;
    
    
//     long long low = 1;
    
//     while(low <= high){
//         long long sum = 0;
        
//         long long mid = (high + low)/2;
        
//         for(int i=0;i<times.size();i++){
//             sum += mid / times[i];
//         }
        
//         if(sum < n){
//             low = mid + 1;
//         }
//         else{
//             if(mid <= high)    // mid가 최대 시간 보다 작으면
//                 answer = mid;
//             // mid가 최소가 될 수도 있어서 answer에 넣어줌
            
//             high = mid - 1;
//         }
//     }
    
//     return answer;
// }













