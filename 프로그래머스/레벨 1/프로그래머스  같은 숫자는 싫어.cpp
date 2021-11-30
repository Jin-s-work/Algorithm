

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    // 그냥 unique를 사용하면 쓰레기 값들을 뒤로 보내버리므로, 따로 잘라줘야 한다.
    // 따라서 erase를 사용하여 unique를 한 곳 부터 end 까지를 erase해주면 된다.
    answer = arr;
    
    return answer;
}


// 중복하는 것을 확인하여 사용하는 전에 풀었던 방법인데,
// unique와 erase를 사용하여 푸는 것이 간편하니 이를 외우면 조을 듯

//
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//vector<int> solution(vector<int> arr)
//{
//    vector<int> answer;
//
//    int n = arr.size();
//    int cur = arr.front();
//
//    for(int i=1;i<n;i++){
//        if(cur != arr[i]){      // 처음과 다르면
//            answer.push_back(cur);    // 그대로 push
//            cur = arr[i];           // 하고 cur를 여기서부터 다시 설정한다.
//        }
//    }
//
//    answer.push_back(cur);  // 마지막으로 넣어준다.
//
//    return answer;
//}











