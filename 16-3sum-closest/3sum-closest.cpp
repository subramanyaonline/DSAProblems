class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {

                int localTarget = target - nums[i] - nums[j];

                int left = j + 1;
                int right = nums.size() - 1;

                while(left <= right) {

                    int mid = left + (right - left) / 2;

                    if(abs(nums[i] + nums[j] + nums[mid] - target) <
                       abs(closestSum - target)) {

                        closestSum = nums[i] + nums[j] + nums[mid];
                    }

                    if(nums[mid] == localTarget) {
                        return nums[i] + nums[j] + nums[mid];
                    }
                    else if(nums[mid] < localTarget) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }

                // check neighbors after binary search
                if(left < nums.size()) {
                    int sum = nums[i] + nums[j] + nums[left];

                    if(abs(sum - target) < abs(closestSum - target)) {
                        closestSum = sum;
                    }
                }

                if(right > j) {
                    int sum = nums[i] + nums[j] + nums[right];

                    if(abs(sum - target) < abs(closestSum - target)) {
                        closestSum = sum;
                    }
                }
            }
        }

        return closestSum;
    }
};