class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = 0, ptr2 = 0;
        
        vector<int> v = nums1;
        
        int ptr = 0;
        
        while (ptr1 < m && ptr2 < n)
        {
            if (v[ptr1] <= nums2[ptr2])
            {
                nums1[ptr] = v[ptr1];
                ptr++;
                ptr1++;
            }
            else
            {
                nums1[ptr] = nums2[ptr2];
                ptr++;
                ptr2++;
            }
        }
        
        while (ptr1 < m)
        {
            nums1[ptr++] = v[ptr1];
            ptr1++;
        }
        
        while (ptr2 < n)
        {
            nums1[ptr++] = nums2[ptr2];
            ptr2++;
        }
    }
};
