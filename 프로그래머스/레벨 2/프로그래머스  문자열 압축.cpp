

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    
    int answer = s.size();
    
    for(int i=1;i<s.size()/2 + 1;i++){
        int num = 1;
        int tmp = 0;
        
        string str = s.substr(0, i);
        // i개를 부분적인 문자열로 받아 str을 만듬
        // 즉 substr는 0-(i-1) 인덱스 까지를 뽑는다.
        
        // 잡아준 i까지로 시작하여 str.size()만큼씩 움직이며 확인 해준다.
        for(int j=i;j<s.size();j+=str.size()){
            if(str == s.substr(j, i))
                num++;
            // 만약 뽑은 str과 str.size() 씩 움직이는 j로 substr(j,i)가
            // 같다면 num을 증가시켜줌
            else{       // 다른 경우에는
                if(num == 1)
                    tmp += str.size();
                // 그냥 한개만 나올 경우 str크기만을 그냥 더해줌
                else
                    tmp += (to_string(num).size() + str.size());
                // 1개가 아니면, num을 string으로 했을 때의 크기 + str 크기
                str = s.substr(j, i);
                num = 1;
            // 그러고 str을 새로 substr로 바꾸어주고, num도 1로 새로 해준다.
            }
        }
        
        if(num == 1)
            tmp += str.size();
        else
            tmp += to_string(num).size() + str.size();
        // 마지막에 나온 케이스도 고려해주어야 한다.
        
        if(tmp < answer)
            answer = tmp;
        // 그냥 s.size()가 더 클 경우 tmp로 갱신하여 바꾸어줌
        
    }
    
    
    
    return answer;
}


// 솔직히 좀 어렵다...
