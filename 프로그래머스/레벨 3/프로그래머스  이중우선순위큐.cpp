

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    
    priority_queue<int, vector<int>, greater<int>> pq_sort;
    // 이것이 내림차순이다.
    priority_queue<int, vector<int>> pq;
    // 그냥 하면 오름차순
    int num = 0;
    
    for(auto k : operations){
        if(!num){
            while(!pq_sort.empty())
                pq_sort.pop();
            while(!pq.empty())
                pq.pop();
        }
        // num이 0일 경우에 pq가 비어있지 않은 경우에 계속 pop해서 빼준다.
        
        if(k[0] == 'I'){
            pq_sort.push(stoi(k.substr(2)));
            pq.push(stoi(k.substr(2)));
            num++;
            // 넣는 만큼 num 증가시킴
            // 2로 하여금 그부터 있는만큼의 string을 int로 바꾸어서 둘다에 push
        }
        else{       // 즉 D일경우
            if(!num)
                continue;
            // num이 0이면 지나감
            
            if(k[2] == '1'){
                pq.pop();
                num--;
            }
            // 1이면 오름차순에 있는 것을 빼주고 num을 감소
            // 즉 제일 오른쪽이므로, 최대값을 삭제
            else{
                pq_sort.pop();
                num--;
            }
            // 음수 일 경우 오름차순에 있는 것을 빼고 num 감소
            // 즉, 제일 왼쪽이므로, 최솟값을 삭제한다.
        }
    
    }
    
    if(num){
        answer[0] = pq.top();
        answer[1] = pq_sort.top();
    }
    // 앞에는 오름차순의 제일 위 즉 최대값
    // 밑에는 내림차순의 제일 위 즉 최솟값
    
    
    return answer;
}













