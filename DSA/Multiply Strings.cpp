   string multiply(string num1, string num2) {
        string ans(num1.size()+num2.size(),'0');
        for(int i = num1.size()-1;i>=0;i--)
        {
            for(int j= num2.size()-1;j>=0;j--)
            {
                int mul = ((num1[i]-'0') * (num2[j]-'0')) + (ans[i+j+1]-'0') ;
                ans[i + j + 1] = mul % 10 + '0';
                ans[i + j] += mul / 10;
            }
        }
        for(int i = 0;i<ans.size();i++)
        {
            if(ans[i]!='0')
                return ans.substr(i);
        }
        return "0";
        
    }
};