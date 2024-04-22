import Foundation

func solution(_ money:Int) -> [Int] {
    
    var answer : [Int] = []
    answer.append(money / 5500)
    answer.append(money % 5500)
    
    return answer
}