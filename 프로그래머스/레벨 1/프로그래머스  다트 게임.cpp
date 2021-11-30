#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    int num = 0;
    vector<int>v;
    for(int i=0;i<dartResult.length();i++){
        if(dartResult[i] == 'S'){
        }
        else if(dartResult[i] == 'D')
            v[num-1] = v[num-1] * v[num-1];
        else if(dartResult[i] == 'T')
            v[num-1] = v[num-1] * v[num-1] * v[num-1];
        else if(dartResult[i] == '*'){
            v[num-1] = v[num-1] * 2;
            if(num > 1)     // 그 전도 있으면 그것도 2배로 해준다.
                v[num-2] = v[num-2] * 2;
        }
        else if(dartResult[i] == '#'){
            v[num-1] = v[num-1] * (-1);
        }
        // #인 경우에는 마이너스가 되는데, *와 만났을때는 -2배가 되므로 그냥 -1로 해주면 된다.
        else{   // 숫자일 경우
            if(dartResult[i+1] == '0'){
                v.push_back(10);
                i++;
                // 하나를 뛰어넘으므로 i를 한번 더 증가시킨다.
            }
            else{
                v.push_back(dartResult[i] - '0');
                // string을 int로 바꾸어서 넣어준다.
            }
            
            num++;
            // 숫자를 넣었으므로 num을 증가시켜준다.
            // 하면서 v[num]에서 num을 증가시키는 것, 즉 수가 나오면 증가한다.
            // 10일 경우 i++를 해주었길래 같이 증가한다.
        }
        
    }
    
    for(int i=0;i<v.size();i++){
        answer += v[i];
        // v의 숫자들을 각각 모두 더해주어 답을 구한다.
    }
    
    return answer;
}

// 그나마 쉬운 레벨1 구현인데 참조를 많이 하면서 풀었다.
// 구현에 익숙해져서 더 많은 문제를 풀어 봐야 할 것...
