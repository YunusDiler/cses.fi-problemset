import math

def AreabyCoordinates(x1, y1, x2, y2, x3, y3):
    return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)))

def pointlocation(x1, y1, x2, y2, x3, y3):
    if x1 == x2:
        if x3 == x1:
            return 0
        elif y1 < y2:
            if x3 < x1:
                return 1
            else:
                return 0
        else:
            if x3 < x1:
                return 0
            else:
                return 1
    slope = (y2 - y1) / (x2 - x1)
    intercept = y1 - slope * x1
    ans = slope * x3 + intercept
    ans = round(ans, 6)
    if y3 == ans:
        return 0
    elif y3 < ans:
        if x1 < x2:
            return 0
        else:
            return 1
    else:
        if x1 < x2:
            return 1
        else:
            return 0


edgecount = int(input())
v1, v2 = map(int, input().split())
u1, u2 = map(int, input().split())

boundary = math.gcd(abs(u2 - v2), abs(u1 - v1))
leftarea = 0
rightarea = 0

for i in range(edgecount-2):
    x3, y3 = map(int, input().split())
    boundary += math.gcd(abs(u2 - y3), abs(u1 - x3))
    area = AreabyCoordinates(v1, v2, u1, u2, x3, y3)
    if pointlocation(v1, v2, u1, u2, x3, y3) == 1:
        leftarea += area
    else:
        rightarea += area
    u1, u2 = x3, y3
boundary += math.gcd(abs(u2 - v2), abs(u1 - v1))

area = abs(leftarea - rightarea)
internal = (area + 2 - boundary) // 2
print(internal, boundary)