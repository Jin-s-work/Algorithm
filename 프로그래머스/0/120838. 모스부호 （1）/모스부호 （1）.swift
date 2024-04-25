import Foundation

func solution(_ letter:String) -> String {
    
    let morse: [String: Character] = [
        ".-": "a", "-...": "b", "-.-.": "c", "-..": "d", ".": "e", "..-.": "f",
        "--.": "g", "....": "h", "..": "i", ".---": "j", "-.-": "k", ".-..": "l",
        "--": "m", "-.": "n", "---": "o", ".--.": "p", "--.-": "q", ".-.": "r",
        "...": "s", "-": "t", "..-": "u", "...-": "v", ".--": "w", "-..-": "x",
        "-.--": "y", "--..": "z"
    ]
    
    let word = letter.components(separatedBy : " ")
    var ans = ""
    
    for k in word{
        if let st = morse[k]{
            ans.append(st)
        }
    }
    
    
    return ans
}