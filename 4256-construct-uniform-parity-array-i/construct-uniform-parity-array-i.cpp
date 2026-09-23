class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        /*
        nums1 contains all even or odd then 
        nums2 = nums1 (because it is already either all even or all odd)

        suppose nums1 contains both odd and even no.
        nums1 is of size n => 1 odd and n-1 even
        nums1[0] = 1;
        nums1[1] = even;
        .....

        nums2[0] = 1;
        nums2[1] = nums1[1] - nums1[0];

        odd - even = odd
        even - odd = odd

        if(odd) then keep it same otherwise
        if(even) make it even - odd or odd - even 
        */
        return true;
    }
};