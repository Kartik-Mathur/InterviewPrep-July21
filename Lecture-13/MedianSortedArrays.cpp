class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		// Assume nums1 array will always be smaller
		if (nums1.size() > nums2.size()) {
			return findMedianSortedArrays(nums2, nums1);
		}

		int s = 0;
		int e = nums1.size();

		while (s <= e) {

			int mid = (s + e) / 2;

			int p1 = mid;
			int p2 = (nums1.size() + nums2.size() + 1) / 2 - p1;

			int a3 = (p1 == 0) ? INT_MIN : nums1[p1 - 1];
			int a4 = (p1 == nums1.size()) ? INT_MAX : nums1[p1];

			int b3 = (p2 == 0) ? INT_MIN : nums2[p2 - 1];
			int b4 = (p2 == nums2.size()) ? INT_MAX : nums2[p2];

			if (a3 <= b4 and b3 <= a4) {
				if ((nums1.size() + nums2.size()) % 2 == 0) {
					return (max(a3, b3) + min(a4, b5)) / 2;
				}
				else {
					return max(a3, b3);
				}
			}
			else if (a3 > b4) {
				e = p1 - 1;
			}
			else {
				s = p1 + 1;
			}
		}
		return -1;

	}
};