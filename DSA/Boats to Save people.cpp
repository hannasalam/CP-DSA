    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0, right = people.size()-1;
        int count = 0;
        sort(people.begin(),people.end());
        while(left<=right)
        {
            if(people[left]+people[right]<=limit)
            {
                left++;
                right--;
            }
            else
            {
                right--;
            }
            count++;
        }
        return count;
    }