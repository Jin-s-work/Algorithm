

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int>q;
    
    for(int i=0;i<progresses.size();i++){
        int remain = 100 - progresses[i];
        
        if(remain % speeds[i] != 0)
            remain += speeds[i];
        
        q.push(remain / speeds[i]);
        // 즉 remain 에서 speeds가 안나누어지면 remain/speeds + 1로 해서
        // 나머지가 있을 경우 몫을 하나 늘려주는 것
    }
    
    int day = q.front();
    int num = 0;
    
    while(!q.empty()){
        if(day < q.front()){     // 즉 q.front()가 더 커지는 순간으로 작아지기 전까지를
                                 // 고려해주는 것
            answer.push_back(num);
            day = q.front();
            num = 0;        // num도 새로 갱신해주고, day도 q.front()로 대체
            
        }
        else{           // 아닌 경우는 num을 증가시키구, q도 pop해서 다음으로 넘어감
            num++;
            q.pop();
        }
        
    }
    
    if(num)
        answer.push_back(num);
    // 마지막 q가 없어졌을때도 num이 남아있다면 즉 0이 아닐 경우에도 추가
    
    
    return answer;
}













