import Foundation

func solution(_ hp:Int) -> Int {
    
    var n = hp
    var answer = 0
    if n >= 5{
        answer += (n / 5)
        n %=  5
    }
    
    answer += (n / 3)
    answer += (n % 3)
    
    
    
    
    
    return answer
}