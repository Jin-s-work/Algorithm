
#include <string>
#include <vector>

using namespace std;

// 1,2,4이므로 1을 빼면 0,1,3과 같은 3진법임을 알 수 있다.
string solution(int n) {
    string answer = "";
    
    int num = n;
    int div = -1;
    
    while(num){
        div = num % 3;
        num /= 3;
        
        if(div == 0){
            answer = "4" + answer;
            num--;
        }   // 나머지가 0일 경우 4를 앞에다가 더해주고
            // num을 3으로 먼저 나눈 후에 num을 1빼주어야 하므로
            // div에 미리 다 나머지를 넣어놓고 나누어 주어야 한다.
        else if(div == 1)
            answer = "1" + answer;
        else if(div == 2)
            answer = "2" + answer;
        // 원래 있던거에 붙이기만 하므로 += 가 아니라 = 이다.
    }
    
    
    return answer;
}



//-----------------------------------------










#include <string>
#include <vector>

using namespace std;

// 1,2,4이므로 1을 빼면 0,1,3과 같은 3진법임을 알 수 있다.
string solution(int n) {
    string answer = "";
    
    int tmp = n;
    int minus = -1;
    
    while(tmp!=0){
        minus = tmp % 3;      // 3의 나머지 즉 3진법을 놓는다.
        tmp /= 3;
        
        if(minus == 0){     // 0일때는 4를 넣고, 몫을 1빼주어야 한다.
            answer = "4" + answer;   // 앞에 넣는 거 이므로 이렇게 해야..
            tmp--;
        }
        else if(minus == 1) // 1일때는 1이다.
            answer = "1" + answer;
        else if(minus == 2) // 2일때는 2이다.
            answer = "2" + answer;
            
            
    }
    
    
    
    return answer;
}

