class Solution {
public:
    int solve(string &sequence, string current, string &word) {
        if (sequence.find(current) == string::npos) {
            return 0;
        }
        return 1 + solve(sequence, current + word, word);
    }

    int maxRepeating(string sequence, string word) {
        return solve(sequence, word, word);
    }
};
