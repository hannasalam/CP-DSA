double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,[](const Item &item1, const Item &item2)
        {
            if(double(item1.value)/double(item1.weight)<double(item2.value)/double(item2.weight)) return true;
            return false;
        });
        // for(int j = 0;j<n;j++)
        // {
        //     cout<<arr[j].value<<"\t"<<arr[j].weight<<"\t";
        // }
        double maxWeight = 0;
        double maxValue = 0.0;
        int i = 1;
        while(maxWeight<W && i<=n){
            if(maxWeight+arr[n-i].weight>W)
            {
                int rem = W-maxWeight;
                maxValue+= (rem*(double(arr[n-i].value)/double(arr[n-i].weight)));
                //cout<<arr[n-i].value/rem;
                maxWeight+= rem;
                i++;
            }
            else{
                maxValue+= (arr[n-i].value);
                maxWeight+= arr[n-i].weight;
                i++;
            }
        }
        return maxValue;
    }