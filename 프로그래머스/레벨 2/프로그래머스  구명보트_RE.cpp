#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int left = 0;
    int right = people.size() - 1;
    
    while(left <= right){
        if(people[left] + people[right] <= limit){
            left++;
            right--;
        }   // 양 끝단의 합이 한계보다 작을 경우 둘을 하나씩 빼주고 그 안으로 들어가는 형식
        else
            right--;
        // 더 클경우에는 right을 줄여야 하므로 right만 줄여준다.
        
        answer++;
        // 어떠한 경우이건 하나씩 사용하므로 증가시켜주기
    }
    
    
    return answer;
}

// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int solution(vector<int> people, int limit) {
//     int answer = 0;
    
//     sort(people.begin(), people.end());
    
//     int left = 0;
//     int right = people.size() - 1;
    
//     while(left <= right){   // 제일 마지막의 경우까지도 추가 해야하므로 같은 것으로 해아한다.
//         if(people[left] + people[right] <= limit){
//             left++;
//             right--;
//         }
//         else{
//             right--;
//         }
        
//         answer++;
//         // 안되는 경우에도 위에 부분은 한개로 추가고
//         // 밑에 부분이 안되도 제일 큰 right가 줄어들고 한개가 늘어야하는 것이 맞다.
//     }
    
//     // 이분탐색으로 풀어야 한다.
    
//     return answer;
// }




// // #include <string>
// // #include <vector>
// // #include <algorithm>

// // using namespace std;

// // int solution(vector<int> people, int limit) {
// //     int answer = 0;
    
// //     sort(people.begin(), people.end());
    
// //     int left = 0;
// //     int right = people.size() - 1;
    
// //     while(left < right){
// //         if(people[left] + people[right] <= limit){
// //             left++;
// //             right--;
// //         }
// //         else{
// //             right--;
// //         }
        
// //         answer++;
    
        
// //     }
    
    
    
    
// //     return answer;
// // }
