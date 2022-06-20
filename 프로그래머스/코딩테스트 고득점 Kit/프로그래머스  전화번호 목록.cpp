#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    // 정렬을 해야 훨씬훨씬 빠를것...
    
    for(int i=0;i<phone_book.size()-1;i++){ // +1로 하므로 -1까지 해야한다.
        string st = phone_book[i];
        if(st == phone_book[i+1].substr(0, st.size()))
                answer = false;
    }
    // 무지성 이중 포문이라 맞지만 시간 초과...
    // 이중 포문을 쓰지 않고 그냥 다음 꺼만 확인해도 된다..
    // ** 정렬을 해주었기에 다음 부분만 맞는지 확인해도 가능! 거의 정렬이 중요 포인트 **
    // 정렬이란 부분을 생각하진 못했지만, substr에 대해 어느정도 익숙해진듯
    // hash로 푸는 것이 메인 풀이이겠지만, 복잡도가 이거보다 오래 걸릴 것 같다.
    
    return answer;
}


// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// bool solution(vector<string> phone_book) {
//     bool answer = true;
    
//     sort(phone_book.begin(), phone_book.end());
//     // 정렬을 해야지 안그러면 이상하게 복잡하게 찾아야 한다.
    
//     for(int i=0;i<phone_book.size()-1;i++){
//         if(phone_book[i] == phone_book[i+1].substr(0,phone_book[i].size()))
//             return false;
//     }       // phone_book[i]에 대하여 다음 부분들이 그만큼의 길이에서 같은 것이 있으면
//             // false
//             // 어차피 순서대로 이므로 다음꺼만 확인해도 된다..?
//             // (문자열에 대하여 정렬을 하였으므로, 이렇게 해도 가능하다.)
    
//     return answer;
// }


// // substr(문자열, 시작 위치, 길이)















