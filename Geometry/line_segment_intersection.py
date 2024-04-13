t = int(input())
for _ in range(t):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(int, input().split())

    if x2 == x1 and x3 != x4:
        slope2 = (y4 - y3) / (x4 - x3)
        intercept2 = y3 - slope2 * x3
        ans = slope2 * x2 + intercept2
        ans = round(ans, 10)
        if (y2 < y1):
            y1, y2 = y2, y1
        if (x4 < x3):
            x3, x4 = x4, x3
        if y1 <= ans <= y2 and x3 <= x2 <= x4:
            print("YES")
        else:
            print("NO")
        continue
    elif x3 == x4 and x2 != x1:
        slope2 = (y2 - y1) / (x2 - x1)
        intercept2 = y1 - slope2 * x1
        ans = slope2 * x3 + intercept2
        ans = round(ans, 10)
        if (y4 < y3):
            y3, y4 = y4, y3
        if (x2 < x1):
            x1, x2 = x2, x1
        if y3 <= ans <= y4 and x1 <= x3 <= x2:
            print("YES")
        else:
            print("NO")
        continue
    elif x1 == x2 and x3 == x4:
        if x1 != x3:
            print("NO")
            continue
        if (y2 < y1):
            y1, y2 = y2, y1
        if (y4 < y3):
            y3, y4 = y4, y3
        if y3 <= y1 <= y4 or y1 <= y3 <= y2:
            print("YES")
        else:
            print("NO")
        continue
        


    slope1 = (y2 - y1) / (x2 - x1)
    slope2 = (y4 - y3) / (x4 - x3)

    intercept1 = y1 - slope1 * x1
    intercept2 = y3 - slope2 * x3

    # x = (i1 - i2) / (s1 - s2)
    if slope1 == slope2:
        intercept1 = round(intercept1, 10)
        intercept2 = round(intercept2, 10)
        if intercept1 != intercept2:
            print("NO")
            continue
        if (x2 < x1):
            x1, x2 = x2, x1
        if (x4 < x3):
            x3, x4 = x4, x3
        # check intercept!!
        if x3 <= x1 <= x4 or x1 <= x3 <= x2:
            print("YES")
        else:
            print("NO")
        continue


    i = (intercept2 - intercept1) / (slope1 - slope2)
    i = round(i, 10)
    if (x2 < x1):
        x1, x2 = x2, x1
    if (x4 < x3):
        x3, x4 = x4, x3

    if (x1 <= i <= x2 and x3 <= i <= x4):
        print("YES")
    else:
        print("NO")