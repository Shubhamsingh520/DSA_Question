class Solution {
public:
    int lastRemaining(int n) {
        return helper(n, 1, 1, true);
    }
    int helper(int n, int head, int diff, bool left) {
        if (n == 1) return head;

        if (left || n % 2 == 1) {
            head += diff;
        }
        return helper(n / 2, head, diff * 2, !left);
    }
};
