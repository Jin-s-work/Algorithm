
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string new_id) {
    
    int size = new_id.length();
    
    for(int i=0;i<new_id.length();i++){
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] = new_id[i] - 'A' + 'a';
    }   // 대문자를 소문자로
    
    for(int i=0;i<new_id.length();){
        if((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            i++;
            continue;
            // 여기서 i를 따로 구분하여서 밑에서 지웠을때, 뒤에가 앞으로 오므로 거기서 다시
            // 해주어야 해서 그냥 이렇게 넘어가면 안됨.. erase를 주의하자
        }
        else
            new_id.erase(new_id.begin() + i);
    }
    
    for(int i=1;i<new_id.length();){
        if(new_id[i-1] == '.' && new_id[i] == '.'){
            new_id.erase(new_id.begin() + i);
            continue;
        }
        else
            i++;
    }
    
    if(new_id.front() == '.')
        new_id.erase(new_id.begin());
    
    if(new_id.back() == '.')
        new_id.erase(new_id.end() - 1);
    
    if(new_id.empty())
        new_id += "a";
    
    if(new_id.length() >= 16){
        new_id.erase(15);
    }
    if(new_id.back() == '.')
        new_id.erase(new_id.end() - 1);
    // 맨뒤가 .일때는 그냥 따로 빼서 해주면 된다.
    
    if(new_id.length() <= 2){
        while(new_id.length() != 3){
            new_id += new_id.back();
        }
    }
    // 2보다 작으면 3이 아닐때까지 맨 뒤를 넣어준다.
    
    return new_id;
}

// erase를 사용할때는 그냥 무작정 i++를 for문에 돌리면 안되고,
// 조건을 충족할 경우 i++ 를 하고 continue를 하고 아닐 경우에는 i를 증가시키면 안된다.
// 왜냐하면 erase를 하면, 뒤에 있던 것이 앞으로 오는데 이때 i를 넘어가면 무시되므로
// 따로 해야 한다.

// 이 문제 역시 시험 당시는 못 풀었던 것 같은데, 다시 하니까 예외 처리 한두개를 제외하면
// 거의 풀 수 있었다. 역시 구현은 많이 풀 수록 느는 것 같다. 앞으로 더 열심히 해 보겠다.




---------------------------------------------------------------------

// 예전에 참조하여 풀었던 풀이

//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//string solution(string new_id) {
//
//    int n = new_id.length();
//
//    for(int i=0;i<new_id.length();i++){
//        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
//            new_id[i] += 'a' - 'A';
//    }
//
//    for(int i=0;i<new_id.length(); ){
//        if((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
//            i++;
//            continue;
//        }
//        new_id.erase(new_id.begin() + i);   // i번째의 항목들 지워준다.
//    }
//
//    for(int i=1;i<new_id.length(); ){
//        if(new_id[i] == '.' && new_id[i-1] == '.'){
//            new_id.erase(new_id.begin() + i);   // 그 전과 이 배열이 .이면
//            continue;               // 이를 지운다.
//        }
//        else
//            i++;
//    }
//
//    if(new_id.front() == '.')       // 처음에 .가 있으면 없앤다.
//        new_id.erase(new_id.begin());
//    if(new_id.back() == '.')        // 마지막에 .가 있으면 없앤다.
//        new_id.erase(new_id.end() - 1);
//
//    if(new_id.length() == 0)
//        new_id = "a";
//
//    if(new_id.length() >= 16){
//        while(new_id.length() != 15){
//            new_id.erase(new_id.begin() + 15);
//        }
//    }
//
//    if(new_id.back() == '.')
//        new_id.erase(new_id.end() - 1);
//
//    if(new_id.length() <= 2){
//        while(new_id.length() != 3){
//            new_id += new_id.back();
//    }
//    }
//
//
//    return new_id;
//}
