s = input()

# 全ての部分文字列を列挙
for i in range(0, len(s)):
    for j in range(i, len(s)+1):
        substring = s[i:j]