class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int dummyArray[r-l+1];
         int i=l, j = m+1;
         int k=0;
         while(i<=m && j<=r)
         {
             if(arr[i]>arr[j]){
                 dummyArray[k] = arr[j];
                 j++;
             }
             else{
                 dummyArray[k] = arr[i];
                 i++;
             }
             k++;
         }
         while(i<=m){
             dummyArray[k] = arr[i];
             i++;
             k++;
         }
         while(j<=r){
             dummyArray[k] = arr[j];
             j++;
             k++;
         }
         int h = l;
         for(int c = 0;c<(r-l+1);c++,h++)
         {
             arr[h] = dummyArray[c];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r)
        {
            mergeSort(arr,l, (l+r)/2);
            mergeSort(arr,((l+r)/2)+1,r);
            merge(arr,l,(l+r)/2,r);
        }
    }
};