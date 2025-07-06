class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);           // Final answer
        vector<int> index(n);              // Original indices
        for (int i = 0; i < n; ++i) index[i] = i;

        mergeSort(nums, index, count, 0, n - 1);
        return count;
    }

    void mergeSort(vector<int>& nums, vector<int>& index, vector<int>& count, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, index, count, left, mid);
        mergeSort(nums, index, count, mid + 1, right);
        merge(nums, index, count, left, mid, right);
    }

    void merge(vector<int>& nums, vector<int>& index, vector<int>& count, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        int rightCount = 0;  // number of elements from right half that are less than nums[index[i]]

        while (i <= mid && j <= right) {
            if (nums[index[j]] < nums[index[i]]) {
                temp[k++] = index[j++];
                rightCount++;
            } else {
                count[index[i]] += rightCount;
                temp[k++] = index[i++];
            }
        }

        while (i <= mid) {
            count[index[i]] += rightCount;
            temp[k++] = index[i++];
        }

        while (j <= right) {
            temp[k++] = index[j++];
        }

        // Copy sorted index positions back to original index array
        for (int p = 0; p < temp.size(); ++p) {
            index[left + p] = temp[p];
        }
    }
};
