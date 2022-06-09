    int mySqrt(int x) {
        ll s=0, e=x;
        ll ans=-1;
        while(s<=e){
            ll mid=s+(e-s)/2;
            ll square = mid*mid;
            if(square==x)
                return mid;
            else if(square<x){
                ans=mid;
                s=mid+1;
            }
            else
                e=mid-1;
        }
        return ans;    
    }
