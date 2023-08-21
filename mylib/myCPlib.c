void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
static int partition_QS (int *arr, int start, int end ,int *pivot){
    int i = start, j = start-1;
    for (; i < end-1; i++)
    {
        if(arr[i] <= *pivot){
            j++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(pivot, &arr[j + 1]);
    return j+1;
}
void Quick_Sort(int *arr,int start, int length)
{
    int *pivot = &arr[length - 1];
    if(start < length){
        int mid = partition_QS(arr, start, length, pivot);
        Quick_Sort(arr, start, mid);
        Quick_Sort(arr, mid+1, length);
    }
}

int Binary_Search(const int *arr,int start,int end,int num)
{
    if(start <= end){
        int mid = (start + end)/2;
        if(arr[mid]==num){
            return mid;
        }else if(arr[mid]>num){
            return Binary_Search(arr, start, mid-1, num);
        }else{
            return Binary_Search(arr,mid+1,end,num);
        }
    }
    return -1;
}