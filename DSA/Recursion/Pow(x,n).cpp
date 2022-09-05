public:
    double pow(double x, int n)
    {
        if(n==0) return 1;
        double P = pow(x,n/2);
        if(n%2==0) return P*P;
        return P*P*x;
    }    
    double myPow(double x, int n) {
        if(n>0) return pow(x,n);
        return 1/pow(x,n);
    }
};