class Solution {
public:
    int binarySearch(int left, int right, std::vector<int>& arr){
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            else if(arr[mid] > arr[mid - 1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }   
        }
        return -1;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return binarySearch(1, arr.size() - 1, arr);
    }
};
