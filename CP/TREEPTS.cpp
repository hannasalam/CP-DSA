#include <iostream>
using namespace std;
bool col(int a, int b, int y1, int y2, int y3)
{
    if(a==b)
    {
        int e = (y2-y1);
        if(e!=0)e/=abs(y2-y1);
        int f = (y3-y2);
        if(f!=0) f/=abs(y3-y2);
        if(f==0||e==0) return true;
        if(e==f) return true;
    }
    return false;
}


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int a1,a2,b1,b2,c1,c2;
	    cin>>a1>>a2;
	    cin>>b1>>b2;
	    cin>>c1>>c2;
	    if(col(a1,b1,a2,b2,c2))
	    {
	        cout<<"YES"<<"\n";
	    }
	    else if(col(a2,b2,a1,b1,c1))
	    {
	        cout<<"YES"<<"\n";
	    }
	    else if(col(b1,c1,a2,b2,c2))
	    {
	        cout<<"YES"<<"\n";
	    }
	    else if(col(b2,c2,a1,b1,c1))
	    {
	        cout<<"YES"<<"\n";
	    }
	    else cout<<"NO"<<"\n";
	}
	return 0;
}
