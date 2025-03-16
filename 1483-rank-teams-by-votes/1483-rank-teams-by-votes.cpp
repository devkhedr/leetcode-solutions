class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if (votes.empty()) {
            return "";
        }
        vector<char> teams;
        for (char c : votes[0]) {
            teams.push_back(c);
        }
        int num_positions = teams.size();
        unordered_map<char, vector<int>> count_map;
        for (char c : teams) {
            count_map[c] = vector<int>(num_positions, 0);
        }
        for (const string& vote : votes) {
            for (int i = 0; i < num_positions; ++i) {
                char current_char = vote[i];
                count_map[current_char][i]++;
            }
        }
        sort(teams.begin(), teams.end(), [&count_map, num_positions](char a, char b) {
            const vector<int>& a_counts = count_map.at(a);
            const vector<int>& b_counts = count_map.at(b);
            for (int i = 0; i < num_positions; ++i) {
                if (a_counts[i] > b_counts[i]) {
                    return true;
                } else if (a_counts[i] < b_counts[i]) {
                    return false;
                }
            }
            return a < b;
        });
        return string(teams.begin(), teams.end());
    }
};