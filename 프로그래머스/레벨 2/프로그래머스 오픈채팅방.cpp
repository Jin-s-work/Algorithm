

//

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<string> state;
    map<string, string> user;
    
    for(int i=0;i<record.size();i++){
        
        string st[3];
        string token;
        stringstream ss(record[i]);
        // 문자열에서 작동하며, 원하는 자료형의 데이터를 추출할 수 있다.
        // record에서 하나씩 받는다.
        // int 로 받으면 숫자를 받아오고,
        // char 로 받으면 모든 문자열을 받는다.
        
        int idx = 0;
        
        while(ss >> token)
            st[idx++] = token;
        // ss >> token은 즉 ss를 각각 넣어줌
        // st[i]에 각각 들어가는 것
        
        if(st[0] == "Enter"){
            state.push_back("님이 들어왔습니다.");
            answer.push_back(st[1]);
            user[st[1]] = st[2];
            // st[i]는 answer에 넣어주고, user[st[1]]에 st[2]를 넣어줌
            
        }
        else if(st[0] == "Leave"){
            state.push_back("님이 나갔습니다.");
            answer.push_back(st[1]);
            // 나갈때는 그냥 나가면서 st[i]을 answer에 넣어줌
        }
        else
            user[st[1]] = st[2];
        // 둘다 아닐 경우는 change 일 경우인데, 그때는 그냥 이름만 바꾼다.
        
    }
    
    for(int i=0;i<answer.size();i++){
        answer[i] = user[answer[i]] + state[i];
        // 각각 i에 맞게 한다.
    }
    
    
    
    return answer;
}
