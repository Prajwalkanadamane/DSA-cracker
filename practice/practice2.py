decNum = 10
ans = 0
pow = 1

while decNum > 0:

    remainder = decNum%2
    decNum = decNum//2

    ans += (remainder*pow)
    pow = pow*10

print(ans)