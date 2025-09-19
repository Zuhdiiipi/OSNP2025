#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long N, K;
    std::cin >> N >> K;
    std::map<long long, long long> candidates;

    for (int i = 0; i < N; ++i) {
        long long length;
        std::cin >> length;

        long long count = 1;

        while (length > 0 && length % 2 == 0) {
            length /= 2;
            count *= 2;
        }
        if (length > 0) {
            candidates[length] += count;
        }
    }

    std::vector<std::pair<long long, long long>> sorted_candidates;
    for (auto const& [len, cnt] : candidates) {
        sorted_candidates.push_back({len, cnt});
    }

    long long total_sum = 0;

    for (auto it = candidates.rbegin(); it != candidates.rend(); ++it) {
        if (K == 0) {
            break;
        }

        long long length = it->first;
        long long count = it->second;

        long long take_count = std::min(K, count);

        total_sum += length * take_count;
        K -= take_count;
    }

    std::cout << total_sum << std::endl;

    return 0;
}