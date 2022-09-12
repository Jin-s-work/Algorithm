#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>


using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int>v;
    
    // 이 풀이는 stringstream을 통한 빠른 풀이
    // string tmp;
    // for(stringstream str(s); str >> tmp;)
    //     v.push_back(stoi(tmp));
    
    string str = "";
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            v.push_back(stoi(str));
            str = "";
            // str 초기화
        }
        else
            str += s[i];
    }
    // 마지막으로 끝낸 것이 아니므로 하나가 남아있을 것이다.
    if(str != "")
        v.push_back(stoi(str));
    
    sort(v.begin(), v.end());
    
    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v[v.size() - 1]);
    
    return answer;
}
