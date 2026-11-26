"""Compare the executable with a direct bounded-knapsack reference."""
import random
import subprocess
import sys


def check(items, capacity):
    dp = [0] * (capacity + 1)
    for count, weight, value in items:
        dp = [max(dp[c - k * weight] + k * value
                  for k in range(count + 1) if k * weight <= c)
              for c in range(capacity + 1)]
    data = f"{len(items)} {capacity}\n" + "".join(
        f"{p} {w} {v}\n" for p, w, v in items)
    result = subprocess.check_output([sys.argv[1]], input=data, text=True)
    assert int(result) == dp[capacity], (data, result, dp[capacity])


check([(1, 2, 3), (2, 3, 4), (3, 4, 5)], 9)
check([(1000, 1, 10**9)], 1000)
check([(2, 0, 7), (1, 3, 5)], 3)
check([(1, 4, 10), (2, 2, 3)], 3)
random.seed(108)
for _ in range(1000):
    check([(random.randint(1, 8), random.randint(1, 15),
            random.randint(0, 50)) for _ in range(random.randint(1, 8))],
          random.randint(1, 30))
print("Passed 1004 reference comparisons.")
