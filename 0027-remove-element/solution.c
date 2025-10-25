int removeElement(int* nums, int numsSize, int val) {
    
    int l = 0;
    int r = numsSize - 1;

    while(l<r) {

        if(*(nums+l)!=val) {
            l++;
        }

        else if(*(nums+l)==val && *(nums+r)!=val) {
            int temp = *(nums+l);
            *(nums+l) = *(nums+r);
            *(nums+r) = temp;
            l++;
            r--;
        }

        else {
            r--;
        }
    }

    int x =0;

    for(int i=0;i<numsSize;i++) {
        if(*(nums+i)!=val) {
            x++;
        }
    }

    return x;
}
