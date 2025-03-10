class Solution {
public:
    long long countAtLeastMConsonants(string& word, int m) {
        int n = word.size();
        unordered_map<char, int> vowels_map;
        long long l = 0, r = 0, cnt = 0, ans = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        while (r < n || l < n) {
            if (vowels_map.size() == 5 && cnt >= m) {
                ans += (n - r + 1);
                if (vowels.find(word[l]) == vowels.end()) {
                    cnt--;
                } else {
                    vowels_map[word[l]]--;
                    if (vowels_map[word[l]] == 0) {
                        vowels_map.erase(word[l]);
                    }
                }
                l++;
            } else {
                if (r == n) break;
                if (vowels.find(word[r]) == vowels.end()) {
                    cnt++;
                } else {
                    vowels_map[word[r]]++;
                }
                r++;
            }
        }
        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return countAtLeastMConsonants(word, k) - countAtLeastMConsonants(word, k + 1);
    }
};