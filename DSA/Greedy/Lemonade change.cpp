bool lemonadeChange(vector<int>& bills) {
        int fivedollars = 0;
        int tendollars = 0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)
                fivedollars++;
            else if(bills[i] == 10)
            {
                if(fivedollars<1)
                    return false;
                else{
                    fivedollars--;
                    tendollars++;
                }
            }
            else
            {
                if(tendollars>0 && fivedollars>0)
                {
                    fivedollars--;
                    tendollars--;
                }
                else if(fivedollars>2){
                    fivedollars-=3;
                }
                else
                    return false;
            }
        }
        return true;
        
    }