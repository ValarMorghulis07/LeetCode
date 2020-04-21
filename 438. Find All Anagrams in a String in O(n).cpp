vector<int> findAnagrams(string s, string p)
    {
      int n1=s.length(),n2=p.length();
      vector<int>ans;
      if(n2>n1)
          return ans;
      vector<int>vec1(26),vec2(26);
      for(int i=0;i<n2;i++)
         vec1[p[i]-'a']++;
      for(int i=0;i<n1;i++)
      {
       vec2[s[i]-'a']++;
       if(i>=n2)vec2[s[i-n2]-'a']--;
       if(vec1==vec2)ans.push_back(i-n2+1);
      }
        return ans;
    }
