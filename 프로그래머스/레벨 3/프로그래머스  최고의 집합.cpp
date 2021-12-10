


#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s){
        answer.push_back(-1);
        return answer;
    }
    
    int div = s / n;
    int remain = s % n;
    for(int i=1;i<=n;i++)
        answer.push_back(div);
    
    for(int i=1;i<=remain;i++)
        answer[n-i] += 1;
    
    
    
    
    return answer;
}












