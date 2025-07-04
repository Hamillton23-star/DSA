class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> lengths;
        lengths.push_back(1); // Initially word = "a", so length is 1

        // Step 1: Compute lengths after each operation
        for (int op : operations) {
            if (op == 0) {
                lengths.push_back(lengths.back() * 2);
            } else {
                lengths.push_back(lengths.back() * 2);
            }

            // Cap the length to prevent overflow
            if (lengths.back() > k) break;
        }

        // Step 2: Walk backward from last operation to determine original character
        int shift = 0; // Net alphabetical shifts (number of '1's applied on this branch)
        int i = (int)lengths.size() - 1;

        while (i > 0) {
            int op = operations[i - 1];
            long long half = lengths[i - 1];

            if (k > half) {
                // k-th character is from the **appended** part
                if (op == 0) {
                    k -= half; // From second half, map back to first
                } else if (op == 1) {
                    k -= half; // From shifted half
                    shift++;   // Add one shift level
                }
            }
           
            i--;
        }

      
        char result = 'a' + (shift % 26);
        if (result > 'z') result -= 26;
        return result;
    }
};
