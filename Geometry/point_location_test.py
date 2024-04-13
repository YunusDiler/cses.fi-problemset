t = int(input())
for _ in range(t):
    x1, y1, x2, y2, x3, y3 = map(int, input().split())

    if x1 == x2:
        if x3 == x1:
            print("TOUCH")
        elif y1 < y2:
            if x3 < x1:
                print("LEFT")
            else:
                print("RIGHT")
        else:
            if x3 < x1:
                print("RIGHT")
            else:
                print("LEFT")
        continue

    slope = (y2 - y1) / (x2 - x1)
    intercept = y1 - slope * x1

    ans = slope * x3 + intercept

    ans = round(ans, 6)

    if y3 == ans:
        print("TOUCH")
    elif y3 < ans:
        if x1 < x2:
            print("RIGHT")
        else:
            print("LEFT")
    else:
        if x1 < x2:
            print("LEFT")
        else:
            print("RIGHT")
    
    