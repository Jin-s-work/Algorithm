

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum = brown + yellow;

    for(int h=3;h<sum;h++){     // 최소 높이는 3
        if(sum % h == 0){
            int w = sum / h;
        
        
            if(yellow == (w - 2) * (h - 2)){     // yellow가 안의 칸의 넓이와 같을 경우
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }
    
    return answer;
}


// #include <string>
// #include <vector>

// using namespace std;

// vector<int> solution(int brown, int yellow) {
//     vector<int> answer;
    
//     int sum = brown + yellow;
    
//     // 노란색이 최소 1개이므로, 높이는 최소 3이다.
//     for(int h=3;h<sum;h++){     // 가로 길이가 세로 길이보다 더 기므로, 세로를 작은거부터 크게
//         if(sum % h == 0){
//             int w = sum / h;        // 너비
            
//             if(yellow == (w-2)*(h-2)){  // 노란색의 수가 맞을 경우
//                 answer.push_back(w);
//                 answer.push_back(h);
//                 break;
//             }
//         }
//     }
        
//     return answer;
// }













