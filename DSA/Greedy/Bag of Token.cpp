int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int s = 0, e = tokens.size()-1;
        int score = 0;
        while(s<=e)
        {
            if(power>=tokens[s]){
                score++;
                power-=tokens[s];
                s++;
            }
            else if(score>0 && (s!=e)){
                power+= tokens[e];
                e--;
                score--;
            }
            else {
                return score;
            }
            cout<<score<<" \t";
        }
        return score;
    }