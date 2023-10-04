class MyHashMap {
    //Time Complexity :O(n) && Space Complexity :O(n)
// private:
//     vector<pair<int, int>> data;

// public:
//     MyHashMap() {
        
//     }
    
//     void put(int key, int value) {
//         for(auto &i : data)
//         {
//             if(i.first == key)
//             {
//                 i.second = value;
//                 return ;
//             }
//         }

//         data.push_back({key, value});
//     }
    
//     int get(int key) {
//         for(auto &i : data)
//         {
//             if(i.first == key)
//             {
//                 return i.second;
//             }
//         }

//         return -1;
//     }
    
//     void remove(int key) {
//         for(auto i = data.begin();i != data.end();i++)
//         {
//             if(i->first == key)
//             {
//                 data.erase(i);
//                 return;
//             }
//         }
//     }

//Time Complexity :O(n) && Space Complexity :O(n)
private:
    int mp[1000001];

public:
    MyHashMap() {
        for(int i=0;i<1e6 + 1;i++)
        {
            mp[i] = -1;
        }
    }
    
    void put(int key, int value) {
        mp[key] = value;
    }
    
    int get(int key) {
        return mp[key];
    }
    
    void remove(int key) {
        mp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
