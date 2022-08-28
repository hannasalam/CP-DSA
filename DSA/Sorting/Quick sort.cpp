class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low<high){
        int m = partition(arr,low,high);
        quickSort(arr,low,m-1);
        quickSort(arr,m+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int p = low;
       int s = low, e = high;
       while(s<e)
       {
           while(s<high&& arr[s]<arr[p])
            s++;
           while(e>low && arr[p]<arr[e])
            e--;
           if(s<e)
           {
               int temp = arr[s];
               arr[s] = arr[e];
               arr[e] = temp;
           }
       }
       swap(arr[e],arr[low]);
       return e;
       
    }
};