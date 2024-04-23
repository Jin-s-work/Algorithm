import Foundation

func solution(_ my_string:String) -> [String] {
    
    let ans = my_string.components(separatedBy: .whitespaces).filter { !$0.isEmpty }

    
    return ans
}