def lcs(a, b):
  n = len(a)
  m = len(b)
  dp = [[ [] for j in range(m+1)] for i in range(n+1)]
  for i in range(1, n+1):
    for j in range(1, m+1):
      if a[i-1] == b[j-1]:
        dp[i-1][j-1].append(a[i-1])
        dp[i][j] = dp[i-1][j-1].copy()
      else:
        temp = max(dp[i][j-1], dp[i-1][j], key = len)
        dp[i][j] = temp.copy()
  return dp[n][m]
		
n, m = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
b = list(map(int, input().split(' ')))
result = lcs(a, b)
for i in result:
		print(i, end = " ")