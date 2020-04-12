def Factorial(n):
    if n == 0 or n == 1:
        return 1
    return n*Factorial(n - 1)


maxdigits = 0
for ndigits in xrange(1, 100):
    if len(str(ndigits*Factorial(9))) < ndigits:
        maxdigits = ndigits - 1
        break

candidates = []
for i in xrange(3, 10**maxdigits + 1):
    digits = [int(s) for s in str(i)]
    if i == sum([Factorial(d) for d in digits]):
        candidates.append(i)
        print "current candidates=%r"%candidates


print "candidates=%r; sum=%r"%(candidates, sum(candidates))
