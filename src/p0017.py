

numbers = dict()
numbers[0] = ''
numbers[1] = 'one'
numbers[2] = 'two'
numbers[3] = 'three'
numbers[4] = 'four'
numbers[5] = 'five'
numbers[6] = 'six'
numbers[7] = 'seven'
numbers[8] = 'eight'
numbers[9] = 'nine'
numbers[10] = 'ten'
numbers[11] = 'eleven'
numbers[12] = 'twelve'
numbers[13] = 'thirteen'
numbers[14] = 'fourteen'
numbers[15] = 'fifteen'
numbers[16] = 'sixteen'
numbers[17] = 'seventeen'
numbers[18] = 'eighteen'
numbers[19] = 'nineteen'
numbers[20] = 'twenty'
numbers[30] = 'thirty'
numbers[40] = 'forty'
numbers[50] = 'fifty'
numbers[60] = 'sixty'
numbers[70] = 'seventy'
numbers[80] = 'eighty'
numbers[90] = 'ninety'
numbers[100] = 'hundred'
numbers[1000] = 'thousand'
sep = 'and'

def Spell(num):
    spelling = ''
    nthousand = num / 1000
    nhundred = (num % 1000) / 100
    nten = (num % 100) / 10
    n = num % 10

    if nthousand > 0:
        # Spell 'X thousand'
        spelling += numbers[nthousand]
        spelling += ' '
        spelling += numbers[1000]
    if nhundred > 0:
        # Spell 'X hundred'
        if len(spelling) > 0:
            spelling += ' '
        spelling += numbers[nhundred]
        spelling += ' '
        spelling += numbers[100]

    if len(spelling) > 0 and (num % 100) > 0:
        spelling += ' and '
        
    if nten > 1:
        spelling += numbers[10 * nten]
        if n > 0:
            spelling += ' '
            spelling += numbers[n]
    else:
        if num % 100 > 0:
            spelling += numbers[num%100]
        
    return spelling

numletters = 0
for i in xrange(1, 1001):
    spelling = Spell(i)
    numletters += sum([len(s) for s in spelling.split(' ')])

print "numletters = {}".format(numletters)
