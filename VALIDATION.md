# Solution and validation

The solution uses bounded-knapsack dynamic programming. For each weight residue,
a decreasing queue finds the maximum of `old[r + j*w] - j*v` in the window
`k-p <= j <= k`. Adding `k*v` gives the best value at capacity `r + k*w`.
Each index enters and leaves the queue at most once, giving O(n*m) time and
O(m) auxiliary space. Values use 64-bit integers.

Build with `make`; run `python3 tests/check.py ./code` to check the sample,
edge cases, and deterministic randomized cases against a direct reference.
All 1004 comparisons passed. A maximum-size case (1000 item types and capacity
1000) passed locally in approximately 7 ms. A clean clone also built successfully
with the initial CMake configuration. The final direct Make build passed the
same comparisons.

## Online judge results

All five allowed submissions completed with score 0 and `compile_error`.
The API supplied only the message `compile error`, with no compiler diagnostics
and no test groups. The judge-side cause remains undetermined.

| Submission ID | Build | Git URL form | Result |
| --- | --- | --- | --- |
| 879589 | CMake | HTTPS | Compile Error |
| 879590 | CMake | SSH port 443 | Compile Error |
| 879593 | CMake | Standard SSH | Compile Error |
| 879596 | GNUmakefile | HTTPS | Compile Error |
| 879597 | GNUmakefile | Standard SSH | Compile Error |

Every submitted version was committed and pushed, with its remote hash verified
before submission. No repository modifications or pushes occurred while a
submission was being judged.
