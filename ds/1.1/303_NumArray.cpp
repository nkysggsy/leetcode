//
// Created by yesonggao on 2024/5/5.
//
class NumArray {
public:
    NumArray(vector<int>& nums) {
        sums.push_back(0);
        int val = 0;
        for (int num : nums) {
            val += num;
            sums.push_back(val);
        }
    }

    int sumRange(int left, int right) {
        return sums[right + 1]- sums[left];
    }
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */