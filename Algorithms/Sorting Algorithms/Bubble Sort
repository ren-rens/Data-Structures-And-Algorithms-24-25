void bubbleSort(std::vector<int>& nums){
    int lastSwappedIndex = nums.size() - 1;

    for(int i = 0; i < nums.size(); i++){
        int currentSwappedIndex = 0;
        for(int j = 0; j < lastSwappedIndex; j++){
          if(nums[j] > nums[j + 1]){
              std::swap(nums[j], nums[j + 1]);
              currentSwappedIndex = j;
          }
        }

        if(currentSwappedIndex == 0){
            return;
        }

        lastSwappedIndex = currentSwappedIdex;
      }
}
