#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    
    int n = phone_number.length();
    
    for(int i=0;i<n-4;i++){
        answer += '*';
    }
    
    for(int i=n-4;i<n;i++){
        answer += phone_number[i];
    }
    // 그냥 간단하게 더해주면 댐..
    
    
    return answer;
}
