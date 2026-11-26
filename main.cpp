#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, capacity;
    if (!(std::cin >> n >> capacity)) return 0;

    std::vector<long long> dp(capacity + 1, 0), next(capacity + 1);
    std::vector<int> queue(capacity + 1);
    for (int item = 0; item < n; ++item) {
        int count, weight;
        long long value;
        std::cin >> count >> weight >> value;
        if (weight == 0) {
            if (value > 0) {
                for (auto& best : dp) best += count * value;
            }
            continue;
        }
        if (weight > capacity || count == 0 || value <= 0) continue;
        count = std::min(count, capacity / weight);

        // In each residue class, maximize dp[r + j*w] - j*v
        // over the sliding window k-count <= j <= k.
        for (int residue = 0; residue < weight; ++residue) {
            int head = 0, tail = 0;
            for (int k = 0, position = residue; position <= capacity;
                 ++k, position += weight) {
                while (head < tail && queue[head] < k - count) ++head;
                const long long candidate = dp[position] - k * value;
                while (head < tail) {
                    const int j = queue[tail - 1];
                    if (dp[residue + j * weight] - j * value > candidate) break;
                    --tail;
                }
                queue[tail++] = k;
                const int best = queue[head];
                next[position] = dp[residue + best * weight] + (k - best) * value;
            }
        }
        dp.swap(next);
    }
    std::cout << dp[capacity] << '\n';
}
