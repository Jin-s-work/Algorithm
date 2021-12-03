#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    bool check = false;
    
    if(hand == "right")
        check = true;
    else
        check = false;
    // 먼저 오른손일때 true 아니면 false
    
    int leftnum = 10;
    int rightnum = 12;
    // 처음엔 기본으로 *와 #에서 시작 하므로, 먼저 이렇게 하고 바뀔 경우 바꾸어 준다.
    
    for(int i=0;i<numbers.size();i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            leftnum = numbers[i];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            rightnum = numbers[i];
        }
        else{
            if(numbers[i] == 0)
                numbers[i] = 11;
            // 0일 경우 11이라고 생각하면 편함
            
            int distL = abs(leftnum - numbers[i]) / 3 + abs(leftnum - numbers[i]) % 3;
            int distR = abs(rightnum - numbers[i]) / 3 + abs(rightnum - numbers[i]) % 3;
            
            if(distL == distR){
                if(check){
                    answer += "R";
                    rightnum = numbers[i];
                }
                else{
                    answer += "L";
                    leftnum = numbers[i];
                }
            }
            else if(distL < distR){
                answer += "L";
                leftnum = numbers[i];
            }
            // 거꾸로 했다. L이 멀면 R을 더해줘야 하는데..
            else{
                answer += "R";
                    rightnum = numbers[i];
            }
            
        }
    
    }
    
    
    
    return answer;
}

// 풀다가 거리 구하는 부분이 생각하다가 조금 보고 했는데 푸니까 확실히 느는 느낌..
// 재밌기도 하다

// 왼쪽은 3의 나머지 1들
// 오른쪽은 3의 나머지 0들
// 가운데는 3의 나머지 2들


// 처음 풀이
//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//string solution(vector<int> numbers, string hand) {
//    string answer = "";
//
//    int n = numbers.size();
//    int tmpL = 10;
//    int tmpR = 12;
//    int distL = 0;
//    int distR = 0;
//
//    for(int i=0;i<n;i++){
//        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
//            answer += 'L';
//            tmpL = numbers[i];
//        }
//        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
//            answer += 'R';
//            tmpR = numbers[i];
//        }
//        else{
//            if(numbers[i] == 0)
//                numbers[i] = 11;
//
//            distL = abs(tmpL - numbers[i]) / 3 + abs(tmpL - numbers[i]) % 3;
//            distR = abs(tmpR - numbers[i]) / 3 + abs(tmpR - numbers[i]) % 3;
//
//            if(distL == distR){
//                if(hand == "right"){
//                    answer += 'R';
//                    tmpR = numbers[i];
//                }
//                else{
//                    answer += 'L';
//                    tmpL = numbers[i];
//                }
//            }
//            else if(distL < distR){
//                answer += 'L';
//                tmpL = numbers[i];
//            }
//            else{
//                answer += 'R';
//                tmpR = numbers[i];
//            }
//
//    }
//    }
//
//    return answer;
//}
//









