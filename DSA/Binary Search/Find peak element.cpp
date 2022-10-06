int findPeakElement(vector<int>& arr) {
        int n = arr.size()-1;
        int l=0, h = arr.size()-1;
        while(l<=h){
            int mid = l+(h-l)/2;
           if (mid == 0)
            return arr[0] > arr[1] ? 0 : 1;
           if (mid == arr.size() - 1)
            return arr[n - 1] > arr[n - 2] ? n - 1 : n - 2;
          if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
              return mid;
         if (arr[mid] < arr[mid - 1])
            h = mid - 1;
        else
            l = mid + 1;
        }
        return -1;
    }
};