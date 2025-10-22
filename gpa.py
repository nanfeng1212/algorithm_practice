i = 1
ans = 0.0
total_xf = 0.0
while i<=30:
    gp, xf = map(float, input().split())
    result = 4-3*(100-gp)*(100-gp)/1600
    print(f"{result:.6f}",f"{result*xf:.6f}")
    i+=1
    total_xf += xf
    ans += result*xf
print(f"{ans:.6f}")
ans /= total_xf
print(f"{ans:.6f},{total_xf:.6f}")