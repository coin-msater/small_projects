def ndigits(x):
        digits = 0
        while x:
            digits += 1
            x //= 10
        return digits

def isPalindrome(x):
    if x < 0:
        return False
    
    n = ndigits(x)
    new_x = x
    y = 0
    for i in range(n):
        add_x = new_x % 10
        y = y * 10 + add_x
        new_x //= 10
        print(new_x, y)
    return x == y

