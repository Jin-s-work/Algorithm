

n = int(input())
arr = [input().strip() for _ in range(n)]

# 알파벳에 따라서 가중치 계산
alp = {}
for word in arr:
    word_len = len(word)
    for i in range(word_len):
        a = word[i]
        value = 10 ** (word_len - i - 1)

        if a in alp:
            alp[a] += value
        else:
            alp[a] = value

letter_sort = sorted(alp.items(), key=lambda x : x[1], reverse=True)
# 내림차순으로 가중치를 정렬

letter_digit = {}
digit = 9
for ch, _ in letter_sort:
    letter_digit[ch] = digit
    digit -= 1
# 각각 내림차순으로 digit 배정

# 뒤에서부터 해서 각각의 값을 넣어준다.
# num * 10 을 통해서 윗자리수로 올라가준다.
total = 0
for word in arr:
    num = 0
    for ch in word:
        num = num * 10 + letter_digit[ch]
    total += num

print(total)