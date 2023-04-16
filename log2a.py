def binLeng(bin : int):
    size = bin.__sizeof__() - 24
    maxE = (size >> 1) * 15 # same as size // 4 * 30
    
    for val in reversed(range(maxE)): 
        if bin & (1 << val): return(val+1)

def log2a(n : int):
    l = binLeng(n) #n.bit_length()
    if n == 0: return(0)
    r = (n & (1 << (l-1))-1 ) / (1<<l) *2 
    return( float(l - 1) + r)