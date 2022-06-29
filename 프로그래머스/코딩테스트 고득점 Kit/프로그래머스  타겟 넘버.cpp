
#include <string>
#include <vector>

using namespace std;

int answer = 0;
void DFS(vector<int> numbers, int target, int sum, int cnt){
    
    if(numbers.size() == cnt){
        if(sum == target){      // 결과인 target과 같다면 늘리고 끝
            answer++;
        }
        return;
    }
    
    DFS(numbers, target, sum + numbers[cnt], cnt+1);
    DFS(numbers, target, sum - numbers[cnt], cnt+1);
    // sum에 더하거나 빼준다.
    // 이렇게 계속 재귀로 들어가는 것이 DFS의 성질
}

int solution(vector<int> numbers, int target) {
    
    DFS(numbers, target, 0, 0);
    
    
    return answer;
}



// #include <string>
// #include <vector>

// using namespace std;

// int answer = 0;

// void DFS(vector<int>numbers, int target, int sum, int cnt){
//     if(numbers.size() == cnt){
//         if(sum == target){
//             answer++;
//         }
//         return;
//     }
    
//     DFS(numbers, target, sum + numbers[cnt], cnt+1);
//     DFS(numbers, target, sum - numbers[cnt], cnt+1);
//     // cnt를 0부터 증가시키면서 더하거나 빼준다. 0일때도 마찬가지
//     // 그래서 sum을 0부터 거기다가 -로 빼주는 식
// }

// int solution(vector<int> numbers, int target) {
    
//     DFS(numbers, target, 0, 0);
    
//     return answer;
// }














