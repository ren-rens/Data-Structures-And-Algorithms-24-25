void selectionSort(std::vector<int>& nums){
    int size = nums.size() - 1;

    for(int i = 0; i < size - 1; i++){
        int minIndex = i;

        for(int j = i + 1; j < size; j++){
            if(nums[minIndex] > nums[j]){
                minIndex = j;
            }
        }

        if(minIndex != i){
            std::swap(nums[i], nums[minIndex]);
        }
    }
}
