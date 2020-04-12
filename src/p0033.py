candidates = []

for den in xrange(1, 100 + 1):
    for num in xrange(1, den):
        snum = str(num)
        sden = str(den)
        oldval = float(num)/float(den)

        snewnum = ''.join([s for s in snum if s not in sden])
        snewden = ''.join([s for s in sden if s not in snum])
        if len(snewnum) == 0 or len(snewden) == 0:
            continue
        if int(snewden) == 0:
            continue
        
        if len(snewnum) == len(snum):
            # No cancellation happens
            continue
        if len(snewden) == len(sden):
            # No cancellation happens
            continue

        if '0' in snum or '0' in sden:
            # Trivial cancellation
            continue
        
        newval = float(int(snewnum))/float(int(snewden))
        if abs(newval - oldval) < 1e-8:
            candidates.append((snum + '/' + sden))
