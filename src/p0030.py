# see the upper limit
maxnumdigits = 1
for numdigits in xrange(2, 10):
    if len( str(numdigits * (9**5)) ) < numdigits:
        maxnumdigits = numdigits - 1
        break

# start from 2 since not counting 1.
sequences = []
for i in xrange(2, 9**maxnumdigits):
    s = str(i)
    digits = [int(number) for number in s]
    if i == sum([x**5 for x in digits]):
        print i
        sequences.append(i)

print 'sum is %d'%(sum(sequences))
