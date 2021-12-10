
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int left = 0;
    int right = people.size() -1;
    
    while(left <= right){
        if(people[left] + people[right] <= limit){
            left++;
            right--;
        }
        else
            right--;
        
        answer++;
        // else의 경우 right줄여주고, answer 증가, 그리고 위에서도 answer 증가(두개 빠지고)
        
    }
    
    
    return answer;
}










// 전의 풀이

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int s = 0;
    int e = people.size() - 1;
    
    while(s <= e){
        if(people[s] + people[e] <= limit){
            s++;
            e--;
        }
        else        // 안되면 그냥 뒤에만 줄여줌
            e--;    // 그래야 제일 많이 탈 수 있음
        
        answer++;
    }
    
    // 앞에 꺼 두개가 아니라 맨 앞과 맨 뒤를 비교해서 하는 것이 더 많이 탈 수 있다.
    
    return answer;
}

