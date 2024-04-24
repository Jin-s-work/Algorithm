import Foundation

func solution(_ numbers:[Int], _ direction:String) -> [Int] {
    
    var ans = numbers
    if direction == "left"{
        let firstElement = ans.removeFirst()
        ans.append(firstElement)
    }
    else{
        let lastElement = ans.removeLast()
        ans.insert(lastElement, at: 0)
    }
    
    return ans
}