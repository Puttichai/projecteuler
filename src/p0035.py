import itertools

def IsPrime(target):
    if target < 0:
        target = -target
    if target < 2:
        return False
    if target == 2:
        return True
    if target%2 == 0:
        return False
    for i in xrange(3, target/2, 2):
        if target%i == 0:
            return False

    return True

# The following takes ages to finish. Need improvement.
candidates = []
maxdigits = 6
for ndigits in xrange(1, maxdigits + 1): # test all numbers having less than 7 digits
    # for digits in itertools.combinations_with_replacement(range(1, 10), ndigits):
    checkedcombinations = set() # checked numbers that fail
    for digits in itertools.product(*[range(1, 10)]*ndigits):
        curlist = list(digits)
        
        curcandidates = []
        bIsOk = True
        bPrevChecked = False
        for i in xrange(ndigits):
            n = int(''.join([str(d) for d in curlist]))
            if n in checkedcombinations:
                bIsOk = False
                break
            if n in curcandidates:
                continue
            if n in candidates:
                # In this case, this whole set of combinations have been checked and passed.
                bPrevChecked = True
                break
            if not IsPrime(n):
                bIsOk = False
                break
            curcandidates.append(n)
            curlist.append(curlist.pop(0)) # rotate
        if bIsOk:
            if bPrevChecked:
                continue
            # print curlist, digits
            candidates.extend(curcandidates)
            print 'cur candidates=%r'%candidates
        else:
            failednumbers = []
            for i in xrange(ndigits):
                failednumbers.append(int(''.join([str(d) for d in curlist])))
            checkedcombinations.update(set(failednumbers))

# candidates=[2, 3, 5, 7, 11, 13, 31, 17, 71, 37, 73, 79, 97, 113, 131, 311, 197, 971, 719, 199, 991, 919, 337, 373, 733, 1193, 1931, 9311, 3119, 3779, 7793, 7937, 9377, 11939, 19391, 93911, 39119, 91193, 19937, 99371, 93719, 37199, 71993, 193939, 939391, 393919, 939193, 391939, 919393, 199933, 999331, 993319, 933199, 331999, 319993]
