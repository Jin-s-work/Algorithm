
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    // 정렬을 해야지 안그러면 이상하게 복잡하게 찾아야 한다.
    
    for(int i=0;i<phone_book.size()-1;i++){
        if(phone_book[i] == phone_book[i+1].substr(0,phone_book[i].size()))
            return false;
    }       // phone_book[i]에 대하여 다음 부분들이 그만큼의 길이에서 같은 것이 있으면
            // false
            // 어차피 순서대로 이므로 다음꺼만 확인해도 된다..?
            // (문자열에 대하여 정렬을 하였으므로, 이렇게 해도 가능하다.)
    
    return answer;
}


// substr(문자열, 시작 위치, 길이)

// 이 부분이 예전에 쉽게 풀었던 풀이
// 분류는 해쉬로 되어있어서 unordered_map으로 하는게 맞긴 한거 같지만, 이렇게 해도 된다.




// 이 부분이 처음시도 인데 너무 노가다 성이라 시간이 엄청 길었다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(int i=0;i<phone_book.size();i++){
        string st = phone_book[i];
        int n = st.size();
        
        for(int j=0;j<phone_book.size() && j!=i;j++){
            if(phone_book[j].substr(0, n) == st)
                answer = false;
        }
        // 기대 안했는데 거의 다 맞았다.
    }
    
    
    return answer;
}


// substr(문자열, 시작 위치, 길이)
















