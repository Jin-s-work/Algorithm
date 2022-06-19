#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int>q;
    for(int i=0;i<progresses.size();i++){
        int remain = (100 - progresses[i]);
        
        if(remain % speeds[i] != 0){
            remain += speeds[i];
        }
        // 바로 안나누어지는 경우 왜 speeds[i]만큼을 remain에 더하냐면
        // 밑에서 remain / speeds[i]를 하는 경우에서 +1로 하여 하루를 더 해주기 위하여
        
        q.push(remain / speeds[i]);
    }
    
    // (7, 3, 9)
    int day = q.front();
    int num = 0;
    
    while(!q.empty()){
        if(day < q.front()){    // 계속 해나가다가 결국 뒤에가 더 커지는 경우 멈춘다.
            answer.push_back(num);  // 지금까지 해나간 num을 넣어준다.
                                // 처음에는 day = q.front()이므로 뒤에를 무조건 해야함
            day = q.front();    // 다 끝났으므로 다시 day를 그 다음으로 넘어감
            num = 0;            // num 을 초기화
            
        }
        else{
            num++;
            q.pop();

        }

    }   // 이중포문이나 그런 것 안쓰고 뒤로 넘어가기
    
    if(num){
        answer.push_back(num);
    }
    // 제일 마지막에 q가 empty이지만, 남아있는 num이 있는 경우 그것을 answer에 넣어주어야함
    
    return answer;
}




// #include <string>
// #include <vector>
// #include <queue>

// using namespace std;

// vector<int> solution(vector<int> progresses, vector<int> speeds) {
//     vector<int> answer;
    
//     queue<int>q;
    
//     for(int i=0;i<progresses.size();i++){
//         int remain = 100 - progresses[i];
        
//         if(remain % speeds[i] != 0)
//             remain += speeds[i];
        
//         q.push(remain / speeds[i]);
//         // 즉 remain 에서 speeds가 안나누어지면 remain/speeds + 1로 해서
//         // 나머지가 있을 경우 몫을 하나 늘려주는 것
//     }
    
//     int day = q.front();
//     int num = 0;
    
//     while(!q.empty()){
//         if(day < q.front()){     // 즉 q.front()가 더 커지는 순간으로 작아지기 전까지를
//                                  // 고려해주는 것
//             answer.push_back(num);
//             day = q.front();
//             num = 0;        // num도 새로 갱신해주고, day도 q.front()로 대체
            
//         }
//         else{           // 아닌 경우는 num을 증가시키구, q도 pop해서 다음으로 넘어감
//             num++;
//             q.pop();
//         }
        
//     }
    
//     if(num)
//         answer.push_back(num);
//     // 마지막 q가 없어졌을때도 num이 남아있다면 즉 0이 아닐 경우에도 추가
    
    
//     return answer;
// }
