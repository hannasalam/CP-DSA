void bubbleSort(int arr[], int n)
    {
        int i = n-1;
        while(i){
            bool swapped = false;
            for(int j=0;j<i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swapped = true;
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
            i--;
            if(!swapped)
                break;
                
        }
    }