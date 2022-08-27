void selectionSort(int arr[], int n)
    {
        int j = n-1;
        while(j)
        {
            int max = 0;
            for(int i=0;i<=j;i++)
            {
                if(arr[i]>arr[max])
                    max = i;
            }
            int temp = arr[j];
            arr[j] = arr[max];
            arr[max] = temp;
            j--;
        }
    }