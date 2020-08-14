class LRUCache {
public:
    int sz;
    list<int>recent;
    unordered_map<int,int>mp;
    unordered_map<int,list<int>::iterator>pos;
    void doit(int key)
    {
     if(pos.find(key)!=pos.end())
         recent.erase(pos[key]);
     else if(recent.size()>=sz)
     {
      int zz=recent.back();
      recent.pop_back();
      mp.erase(zz);
      pos.erase(zz);
     }
     recent.push_front(key);
     pos[key]=recent.begin();
    }
    LRUCache(int capacity)
    {
     sz=capacity;
    }

    int get(int key)
    {
     if(mp.find(key)!=mp.end())
     {
      doit(key);
      return mp[key];
     }
     return -1;
    }

    void put(int key, int value)
    {
     doit(key);
     mp[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
