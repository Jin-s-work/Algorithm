#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int idx = -1;               // 0부터 검사하는데 밑에가 idx+1부터 해야하므로 -1부터 시작
    int n = number.size();
    for(int i=0;i<n-k;i++){     // 총 개수중에 k개만을 빼기에
        char Max = ' ';          // char 이므로 ' '
        
        for(int j=idx+1;j<=k+i;j++){ // 이렇게 하는 이유는 더 큰 숫자가 나올 수 있어도
            if(Max < number[j]){     // answer의 길이가 정해져있기 때문이다.
                Max = number[j];
                idx = j;            // Max보다 큰 숫자가 나오면 바꾸고 그 idx부터 다시 시작
            }
        }       // answer의 사이즈가 n-k가 나와야한다.
                // 즉 i를 대입하였을때 j <= n-1 까지 이므로
        
        answer += Max;
    }
    // 흠 솔직히 아직 살짝 잘 모르겠다.
    
    return answer;
}

// ** 원래 내가 해보려던 방법 (다른 사람 풀이) **
// #include <string>
// #include <vector>

// using namespace std;

// string solution(string number, int k) {
//     string answer = "";

//     for (int i = 0; i < k; i++){
//         int len = number.length();
//         for (int j = 0; j < len; j++){
//             if (j == len - 1){
//                 number.erase(j, 1);
//                 break;
//             }
//             if (number[j] < number[j + 1]){
//                 number.erase(j, 1);
//                 break;
//             }
//         }
//     }

//     answer = number;

//     return answer;
// }



// #include <string>
// #include <vector>

// using namespace std;

// string solution(string number, int k) {
//     string answer = "";
    
//     int n = number.length();
//     int index = -1;
    
//     for(int i=0;i<n-k;i++){     // number size보다 k작은 만큼 출력되므로
//         char Max = ' ';
//         for(int j=index+1;j<=k+i;j++){  // 다음 인덱스 부터 k+i까지
//             if(Max < number[j]){
//                 Max = number[j];    // ' '보다 클경우에 Max를 갱신
//                 index = j;          // 인덱스를 저장해준다.
//             }
//         }
        
//         answer += Max;
//     }
    
    
//     return answer;
// }












