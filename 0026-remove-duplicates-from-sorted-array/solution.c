int removeDuplicates(int* nums, int numsSize) {
    
    int i=0;

   for(int j=0;j<numsSize;j++) {
        if(*(nums+i)!=*(nums+j)) {
            i++;
            *(nums+i) = *(nums+j);
        }
   }

   return i+1;


}
