double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len = nums1Size + nums2Size;
    float arr[len];
    int i=0,j=0;
    int in;
    for (in = 0; in < len; in ++)
    {
        if (i < nums1Size && j < nums2Size)
        {
            if (nums1[i] < nums2[j])
            {
                arr[in] = nums1[i];
                i++;
            }
            else
            {
                arr[in] = nums2[j];
                j++;
            }
        }
        else if (i < nums1Size)
        {
            arr[in] = nums1[i];
            i++;
        }
        else
        {
            arr[in] = nums2[j];
            j++;
        }
    }
    if(len%2==0)
    {
        float f;
        f=((arr[len/2] + arr[(len/2)-1])/2);
        return f;
    }
    else
    {
        return arr[(len/2)];
    }
}