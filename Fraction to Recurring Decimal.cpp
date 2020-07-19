class Solution {
public:
    map<long long,long long>mp;
    string res;
    long long rem;
    
     void doit(long long num,long long den)
     {
      rem=num%den;
      while(rem!=0 && mp.find(rem)==mp.end())
      {
       mp[rem]=res.length();
       rem*=10;
       res+=to_string(rem/den);
       rem%=den;
      }
       /*if(rem==0)//Recurring
       else //Not*/
     }
     
    string fractionToDecimal(long long  numerator, long long denominator) 
    {
      mp.clear();
      res="";
      if(numerator==0)
          return "0";
      bool sign=(numerator<0)^(denominator<0);
     
      numerator=abs(numerator);
      denominator=abs(denominator);
      long long  num=numerator,den=denominator;
      //cout<<num<<" "<<den;
      long long  zz=__gcd(num,den);
      num/=zz;
      den/=zz;
      string ans="";
       if(sign)
           ans+="-";
      if(num%den==0)
        ans+=to_string(num/den);
      else
      {
       ans+=to_string(num/den);
       ans+=".";
       doit(num,den);
       if(rem==0)
           ans+=res;
       else
       {
        ans+=res.substr(0,mp[rem]);
        ans+='(';
        ans+=res.substr(mp[rem]);
        ans+=')';
       }
        
      }
        return ans;
     }
    
};
