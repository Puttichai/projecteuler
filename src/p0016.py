from numpy import array, zeros

s = 0

carrying = zeros(1000)
lastdigit = 2
for i in xrange(1, 1000):
    lastdigit *= 2
    if lastdigit / 10 > 0:
        carrying[i] = int(lastdigit / 10)
        lastdigit = int(lastdigit % 10)

s += lastdigit

while( any(carrying) ):
    lastdigit = 0
    for i in xrange(1000):
        lastdigit *= 2
        lastdigit += carrying[i]
        carrying[i] = 0
        if lastdigit / 10 > 0:
            carrying[i] = int(lastdigit / 10)
            lastdigit = int(lastdigit % 10)

    s += lastdigit
            
