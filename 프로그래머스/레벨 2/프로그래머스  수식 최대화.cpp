

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

ll cal(ll a, ll b, char op){
    if(op == '+')
        return a + b;
    else if(op == '-')
        return a - b;
    return a * b;
}
// 계산해주는 함수

long long solution(string expression) {
    long long answer = 0;
    
    string st = "*+-";
    vector<ll>v;
    string tmp;
    
    string operand;
    
    sort(st.begin(), st.end());
    
    for(char k : expression){
        if(k >= '0' && k <= '9')
            tmp += k;
        // k가 숫자일 경우 tmp에 더해다 줌
        // 여기서 숫자로 안하고 string으로 더하므로 10곱하고 그런거 안해도댐
        else{
            v.push_back(stoi(tmp));
            operand += k;
            tmp = "";
        }
        // 부호가 나올 경우 v에 이제까지 있던 tmp를 int로 바꾸어 넣어준다.
        // 그러고 부호를 operand에 저장해놓고, tmp도 초기화 시켜줌
    }
    v.push_back(stoi(tmp));
    // 남은 것도 넣어다 줌
    
    do{
        string str = operand;
        // 이제까지 들어간 부호들을 str에 넣어준다.
        vector<ll>v2 = v;
        
        for(char k : st){
            for(int i=0;i<str.size();i++){
                // 들어간 부호들을 조사
                if(k == str[i]){
                    // st를 돌리면서 str과 부호가 같은 경우
                    ll cnt = cal(v2[i], v2[i+1], k);
                    // v에는 각각 숫자들이 들어감으로 그거에 관해 계산한다.
                    
                    v2.erase(v2.begin() + i);
                    v2.erase(v2.begin() + i);
                    // v2에서 쓴 2가지 수를 지우고
                    
                    v2.insert(v2.begin() + i, cnt);
                    str.erase(str.begin() + i);
                    i--;
                    // v2에 계산한 cnt를 다시 넣어준다.
                    // 그러고 사용한 str 즉 부호를 지워주고,
                    // i는 하나만 줄여줌 ( 해야한다 )
                }
            }
        }
        answer = max(answer, abs(v2[0]));
        // v2[0] 즉 계산 된 값이 answer의 최대 보다 클 경우 갱신해준다.
        
    }while(next_permutation(st.begin(), st.end()));
    
    
    return answer;
}













