

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char>ch = {'A', 'E', 'I', 'O', 'U'};
vector<string>v;

void DFS(string word, int len){
    if(len == word.length()){
        v.push_back(word);
        return;
        // len과 word의 길이가 같으면 word를 v에 넣는다.
        
        // 즉 len과 word가 길이가 같아지면 word를 v에 넣어주고, 끝냄
        // 다를 경우 word에 계속 ch를 하나씩 계속 붙여줌
        // len은 일정
    }
    
    for(char k : ch)
        DFS(word + k, len);
    // ch에 있는 모음들을 word에 계속 더해서 해본다 len은 일정
}


int solution(string word) {
    int answer = 0;
    
    for(int i=1;i<=5;i++){
        string word = "";
        DFS(word, i);
        
        // i를 1부터 5까지에 대해 DFS
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0;i<v.size();i++){
        if(word == v[i])
            return i+1;
        // word가 v의 i와 같을 경우 i+1을 내보낸다.
    }
    
    
    
}

// 5진법인가만 생각하고 솔직히 감이 안와서 풀이를 보았다..













