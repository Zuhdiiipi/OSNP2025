#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();

    if (n < 4) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> prefixO(n + 1, 0);
    vector<int> prefixS(n + 1, 0);
    vector<int> prefixN(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefixO[i + 1] = prefixO[i] + (s[i] == 'O');
        prefixS[i + 1] = prefixS[i] + (s[i] == 'S');
        prefixN[i + 1] = prefixN[i] + (s[i] == 'N');
    }

    vector<int> suffixP(n + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
        suffixP[i] = suffixP[i + 1] + (s[i] == 'P');
    }
    
    int ans = -1;

    for (int i = 0; i <= n; ++i) {
        if (prefixO[i] > 0 && prefixS[i] > 0 && prefixN[i] > 0 && suffixP[i] > 0) {
            int current_length = prefixO[i] + prefixS[i] + prefixN[i] + suffixP[i];
            ans = max(ans, current_length);
        }
    }

    cout << ans << endl;

    return 0;
}