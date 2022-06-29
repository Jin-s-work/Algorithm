
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    vector<int>check(words.size(), 0);  // 이동했는지 확인을 단어 개수만큼
    queue<pair<string, int>> q;     // 단어, 횟수
    
    q.push({begin, 0});     // 처음단어, 처음이므로 0
    
    while(!q.empty()){
        string start = q.front().first;     // 시작 string은 first
        int cnt = q.front().second;         // 횟수는 second
        q.pop();
        
        int num;
        for(int i=0;i<words.size();i++){
            num = 0;
            if(check[i])   // 방문 했을 경우 넘어감
                continue;
            for(int j=0;j<begin.size();j++){
                if(start[j] != words[i][j])
                    num++;
            }   // start 부분의 단어와 words에서의 단어가 다를 때 num을 증가
        
        
            if(num == 1){   // 다른 개수가 1일 경우
                if(words[i] == target)      // 같을 경우 cnt를 증가시켜서 끝낸다.
                    return cnt+1;
            
                check[i] = 1;               // 방문함을 체크하고
                q.push({words[i], cnt+1});  // 바꾼 word를 넣어주고, cnt를 증가시킨다.
            }
        }
        
        
    }
    
    
    
    return answer;
}


// #include <string>
// #include <vector>
// #include <queue>

// using namespace std;

// int solution(string begin, string target, vector<string> words) {
//     int answer = 0;
    
//     vector<int> visit(words.size(), 0);
//     queue<pair<string, int>> q;     // 앞에는 words, 뒤에는 횟수
    
//     q.push({begin, 0});     // 처음 단어와 처음이므로 0
    
//     while(!q.empty()){
//         string start = q.front().first;
//         int cnt = q.front().second;
//         q.pop();
        
//         int num;
//         for(int i=0;i<words.size();i++){
//             num = 0;
//             if(visit[i] != 0)       // 방문 했으면 넘어감
//                 continue;
            
//             for(int j=0;j<begin.size();j++){
//                 if(start[j] != words[i][j])
//                     num++;      // 다를 경우 num을 증가
//             }
            
//             if(num == 1){       // 한번만 바뀌고 target과 같으면
//                 if(words[i] == target)
//                     return cnt+1;   // 횟수를 증가
                
//                 visit[i] = 1;
//                 q.push({words[i], cnt+1});
//             }
//         }
        
        
//     }
    
//     return answer;
// }















