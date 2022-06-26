#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int left = 0;
    int right = people.size() - 1;
    
    while(left <= right){   // 제일 마지막의 경우까지도 추가 해야하므로 같은 것으로 해아한다.
        if(people[left] + people[right] <= limit){
            left++;
            right--;
        }
        else{
            right--;
        }
        
        answer++;
        // 안되는 경우에도 위에 부분은 한개로 추가고
        // 밑에 부분이 안되도 제일 큰 right가 줄어들고 한개가 늘어야하는 것이 맞다.
    }
    
    // 이분탐색으로 풀어야 한다.
    
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
    
//     while(left < right){
//         if(people[left] + people[right] <= limit){
//             left++;
//             right--;
//         }
//         else{
//             right--;
//         }
        
//         answer++;
    
        
//     }
    
    
    
    
//     return answer;
// }




















