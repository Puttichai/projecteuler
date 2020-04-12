def IsPalindromic10(n):
    s = str(n)
    for i in xrange(len(s)/2):
        if s[i] != s[len(s) - 1 - i]:
            return False

    return True


def IsPalindromic2(n):
    s = bin(n)[2:]
    for i in xrange(len(s)/2):
        if s[i] != s[len(s) - 1 - i]:
            return False

    return True


results = []
for n in xrange(1, 1000000):
    if IsPalindromic10(n) and IsPalindromic2(n):
        results.append(n)
