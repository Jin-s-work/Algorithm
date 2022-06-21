
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    vector<int>v;
    
    for(int i=0;i<commands.size();i++){
        int a = commands[i][0];
        int b = commands[i][1];
        int c = commands[i][2];
        
        for(int j=a-1;j<b;j++){
            v.push_back(array[j]);
        }
        
        sort(v.begin(), v.end());
        
        answer.push_back(v[c-1]);
        
        v.clear();
    }
    // 맞긴 했는데 효율성이 괜찮을까...?
    
    return answer;
}

// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//     vector<int> answer;
    
//     vector<int>v;
//     for(int i=0;i<commands.size();i++){
//         for(int j=commands[i][0]-1;j<=commands[i][1]-1;j++){
//             v.push_back(array[j]);
//         }
//         sort(v.begin(), v.end());
//         answer.push_back(v[commands[i][2]-1]);
//         v.clear();
//     }
//     // 혼자 풀었지만 인덱스가 조금 헷갈렸다..
    
//     return answer;
    
// }














