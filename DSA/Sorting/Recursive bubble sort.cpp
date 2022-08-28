void bubbleSort(int arr[], int n)
    {
        if(n>1){
            bool swapped = false;
            for(int j=0;j<n-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swapped = true;
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
            if(!swapped)
                return;
            bubbleSort(arr,n-1);
        }
        
    }