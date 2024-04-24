import Foundation

func solution(_ myString:String) -> [String] {
    
    let substrings = myString.split(separator: "x")
    
    let sortedSubstrings = substrings.filter { !$0.isEmpty }.sorted()
    
    return sortedSubstrings.map { String($0) }
}