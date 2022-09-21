

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    map<string, int>mp;
    // map으로 string에 따른 개수를 확인하여 중복을 확인하기
    
    mp[words[0]]++;
    // 처음의 경우에 넣어준다.
    
    int ans = 0;
    bool check = false;
    for(int i=1;i<words.size();i++){
        if(mp[words[i]] || words[i].front() != words[i-1].back()){
            check = true;   // mp가 0이 아니고 1이거나 앞뒤가 다를 경우에 ans를 입력한다.
            ans = i;
            break;
        }
        
        mp[words[i]]++;
        // words에 대한 중복을 확인시켜주기 위해 하나씩 늘려준다.
    }
    
    if(!check){     // 다 같거나 중복이 없을 경우
        answer.push_back(0);
        answer.push_back(0);
    }
    else{       // 다 다를 경우
        answer.push_back((ans) % n + 1);
        answer.push_back(((ans) / n) + 1);
    }
    

    return answer;
}

//     vector<string> v;
//     bool check = false;
//     int ans = 0;
    
//     v.push_back(words[0]);
//     for(int i=0;i<words.size()-1;i++){
        
//         // 같은 경우도 고려해야 한다...
//         if((words[i][words[i].size()-1] != words[i+1][0]) || (find(v.begin(), v.end(), words[i+1]) == v.end()) ){   // 끝들이 다르거나 같은게 있을 경우에
//             check = true;      // 틀릴 경우 true
//             ans = i;
//             break;
//         }
//         else{
//             v.push_back(words[i+1]);
//         }
        
//     }



// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// vector<int> solution(int n, vector<string> words) {
//     vector<int> answer;
    
//     vector<string>v;
//     int s = words.size();
//     int num = 1, cnt = 1;
    
//     answer.push_back(0);
//     answer.push_back(0);    // 먼저 이 둘을 설정해 놓아야 한다.

//     v.push_back(words[0]);
    
//     for(int i=1;i<s;i++){   // 두번째부터 하므로 1부터임
//         num++;
//         if(words[i].front() == words[i-1].back()){
//             if(find(v.begin(), v.end(), words[i]) == v.end()){
//                 if(i == s-1)
//                     return answer;
//                 v.push_back(words[i]);
//             }
//             else
//                 break;
//         }
//         else
//             break;
        
//         if(num == n){
//             cnt++;
//             num = 0;
//         }
//     }
    
//     answer[0] = num;        // 첫번째가 사람
//     answer[1] = cnt;        // 두번째가 몇번째

//     return answer;
// }















