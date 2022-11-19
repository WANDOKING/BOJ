inputValue = input().split()
n = int(inputValue[0])
m = int(inputValue[1])

dp = [ [1], [1, 1] ]

for i in range(2, n + 1):
    dp.append([])

    dp[i].append(1)

    for j in range(1, i):
        dp[i].append(dp[i - 1][j - 1] + dp[i - 1][j])

    dp[i].append(1)

print(dp[n][m])
