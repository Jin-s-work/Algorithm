

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int a[5] = {1,2,3,4,5};
int b[8] = {2,1,2,3,2,4,2,5};
int c[10] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int>v(3);
    // 값들을 저장해줄 벡터
    
    for(int i=0;i<answers.size();i++){
        if(a[i % 5] == answers[i])
            v[0]++;
        if(b[i % 8] == answers[i])
            v[1]++;
        if(c[i % 10] == answers[i])
            v[2]++;
    }
    
    int Max = max(v[0], max(v[1], v[2]));
    
    for(int i=0;i<3;i++){
        if(v[i] == Max)
            answer.push_back(i+1);
    }
    // %에 관해서는 생각했으나, 구체적인 해법은 조금만 보고 함
    
    
    return answer;
}













