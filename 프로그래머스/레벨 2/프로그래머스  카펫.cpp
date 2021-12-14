
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum = brown + yellow;
    
    // 노란색이 최소 1개이므로, 높이는 최소 3이다.
    for(int h=3;h<sum;h++){     // 가로 길이가 세로 길이보다 더 기므로, 세로를 작은거부터 크게
        if(sum % h == 0){
            int w = sum / h;        // 너비
            
            if(yellow == (w-2)*(h-2)){  // 노란색의 수가 맞을 경우
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }
    
    
    
    return answer;
}


//////////////////////////

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // 가로 >= 세로
    
    int sum = brown + yellow;
    
    for(int h=3;;h++){  // 높이는 최소 3이므로 거기부터 시작
        if(!(sum % h)){ // sum의 총 개수는 전체 개수이므로 높이를 나누면 가로길이 이게 나누어떨어질경우에
            int l = sum/h;  // 가로 길이
            if((h-2) * (l-2) == yellow){   // 이 가운데 값이 yellow일때
                answer.push_back(l);
                answer.push_back(h);
                break;  // 그러면 break
            }
            
        }
    }
    
    return answer;
}
