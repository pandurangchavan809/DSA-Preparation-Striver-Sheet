#include<bits/stdc++.h>
using namespace std;

// STL :
// Algorithms
// Contaiiners
// Functions
// Iterators

// pairs
void explainPair(){
    pair<int, int> p = {1,3};
    cout<<p.first <<" "<< p.second <<"\n"; 

    // use a different name for the nested pair to avoid redeclaration
    pair<int, pair<int, int>> p2 = {1, {3,4}};

    cout << p2.first << " " << p2.second.second << " " << p2.second.first << "\n";     // 1 4 3

    pair<int, int> arr[] = {{1,2},{2,5},{5,1}};

    cout<<arr[1].second <<"\n";    // 5
}

// vector
void explainVector(){
    // brief vector examples
    vector<int> v = {1,2,3,4};
    cout << "size: " << v.size() << " first: " << v.front() << " last: " << v.back() << "\n";
    v.push_back(5);
    v.emplace_back(5,2);         // fater compared to pushback as not uses curly brackets to pushback.  same work but different in syntax
    cout << "after push_back, last: " << v.back() << "\n";
    for(int x : v) cout << x << ' ';
    cout << '\n';

    vector<int>::iterator it = v.begin();
    it++;
    cout<< *(it)<<" ";

    vector<int>::iterator it = v.end();     // point on last element + 1 position ( outoff range)
    // vector<int>::iterator it = v.rbegin();  //point to the last element
    cout<< v[0] <<" "<< v.at(0);

    for (auto it = v.begin(); it != v.end(); it++){
        cout<<*(it)<<" ";
    }

    for(auto it: v){
        cout<<it<<" ";
    }

    //  { 10, 20, 12, 23}
    v.erase(v.begin()+1);

    //  { 10, 20, 12, 23}
    v.erase(v.begin()+2, v.begin()+4);   // {10, 20, 35} [start, end)

    // Insert function

    vector<int> v(2, 100); // (100, 100)
    v.insert(v.begin(), 300); // (300, 100, 100)
    v.insert(v.begin() + 1, 2, 10); // (300, 10, 10, 100, 100)

    vector<int> copy(2, 50); // (50, 50)
    v.insert(v.begin(), copy.begin(), copy.end()); // (50, 50, 300, 10, 10, 100, 100)

    // (10, 20)
    cout << v.size(); // 2

    // (10, 20)
    v.pop_back(); // (10)

    // v1 -> (10, 20)
    // v2 -> (30, 40)
    // v1.swap(v2); // v1 -> (30, 40); v2 -> (10, 20)

    v.clear(); // erases the entire vector

    cout << v.empty();
}

void explainList(){
    list<int> ls;
    ls.push_back(1);   // {1}
    ls.emplace_back(2);   // {1,2}
    ls.push_front(3);  // {3,1,2}
    ls.emplace_front(4);  // {4,3,1,2}

    for(auto it: ls){
        cout<<it<<" ";          // 4 3 1 2
    }
    cout<<"\n";

    ls.erase(ls.begin());   // erases first element

    for(auto it: ls){
        cout<<it<<" ";     // 3 1 2
    }
    cout<<"\n";

    cout<<"Size: "<< ls.size() <<"\n";

    // rest functions are same as vector
    // begin, end, rbegin, clear, size, swap, insert, etc.
}


void explainDeque(){
    deque<int> dq;
    dq.push_back(1);   // {1}
    dq.emplace_back(2);   // {1,2}
    dq.push_front(3);  // {3,1,2}

    for(auto it: dq){
        cout<<it<<" ";          // 3 1 2
    }

    dq.emplace_front(4);  // {4,3,1,2}

    dq.pop_back();   // {4,3,1}
    cout<<"Size: "<< dq.size() <<"\n";
    dq.front();   // 4
    dq.back();    // 1

    // rest functions are same as vector
    // begin, end, rbegin, clear, size, swap, insert, etc.
}

void explainStack(){
    stack<int> st;
    st.push(1);   // {1}
    st.push(2);   // {1,2}
    st.emplace(3);  // {1,2,3}

    cout<<"Top element: "<< st.top() <<"\n";   // 3
    st.pop();   // {1,2}
    cout<<"Size: "<< st.size() <<"\n";   // 2

    st.empty();   // false

    stack<int> st2, st3;
    st2.swap(st3);   // swaps st2 and st3

    // stack follows LIFO (last in first out)
}   

void explainQueue(){
    queue<int> q;
    q.push(1);   // {1}
    q.push(2);   // {1,2}
    q.emplace(3);  // {1,2,3}

    cout<<"Front element: "<< q.front() <<"\n";   // 1
    cout<<"Back element: "<< q.back() <<"\n";     // 3
    q.pop();   // {2,3}
    cout<<"Size: "<< q.size() <<"\n";   // 2

    q.empty();   // false

    queue<int> q2, q3;
    q2.swap(q3);   // swaps q2 and q3

    // queue follows FIFO (first in first out)
}

void explainPriorityQueue(){
    // max heap
    priority_queue<int> pq;   // greater<int> for min heap

    pq.push(5);   // {5}
    pq.push(2);   // {5,2}
    pq.emplace(8);  // {8,5,2}

    cout<<"Top element: "<< pq.top() <<"\n";   // 8
    pq.pop();   // {5,2}
    cout<<"Size: "<< pq.size() <<"\n";   // 2

    pq.empty();   // false

    priority_queue<int> pq2, pq3;
    pq2.swap(pq3);   // swaps pq2 and pq3

    // size, swap, top, pop, push, emplace same as others
}


void explainSet(){
    set<int> st;
    st.insert(1);   // {1}
    st.emplace(2);  // {1,2}
    st.insert(2);   // {1,2}


    // set stores only unique elements
    // begin(), end(), rbegin(), rend(), size(), clear(), erase(), swap() are same as others

    // {1,2,3,4,5}
    auto it =st.find(3);   // returns iterator to the element 3
    st.erase(2);   // {1,3,4,5}

}

void explainMultiSet(){

    // same as duplicates elements also 

    multiset<int> ms;
    ms.insert(1);   // {1}
    ms.insert(1);   // {1,1}
    ms.emplace(2);  // {1,1,2}

    // multiset stores multiple occurences of same element

    // begin(), end(), rbegin(), rend(), size(), clear(), erase(), swap() are same as others

    // {1,1,2,3,4,5}
    auto it =ms.find(3);   // returns iterator to the element 3
    ms.erase(1);   // {2,3,4,5}   // erases all occurences of 1

}

void explainMap(){

    // key-value pairs , keys are unique 

    map<int, int> mp;
    mp[1] = 2;   // {1:2}
    mp.emplace(3,4);   // {1:2, 3:4}
    mp[1] = 5;   // {1:5, 3:4}   // updates the value at key 1

    // begin(), end(), rbegin(), rend(), size(), clear(), erase(), swap() are same as others

    // {1:5, 3:4, 6:7}
    auto it = mp.find(3);   // returns iterator to the key 3
    mp.erase(1);   // {3:4, 6:7}

    for(auto it: mp){
        cout<< it.first <<" "<< it.second <<"\n";
    }
}

void explainMultiMap(){ 

    // same as map but allows duplicate keys

    multimap<int, int> mmp;
    mmp.insert({1,2});   // {1:2}
    mmp.insert({1,3});   // {1:2, 1:3}
    mmp.emplace(2,4);   // {1:2, 1:3, 2:4}

    // begin(), end(), rbegin(), rend(), size(), clear(), erase(), swap() are same as others

    // {1:2, 1:3, 2:4, 3:5}
    auto it = mmp.find(1);   // returns iterator to the first key 1
    mmp.erase(1);   // {2:4, 3:5}   // erases all occurences of key 1

    for(auto it: mmp){
        cout<< it.first <<" "<< it.second <<"\n";
    }
}   


void explainunorderedSet(){
    // uses hashing , faster than set but not ordered
    unordered_set<int> st;
    st.insert(1);   // {1}
    st.emplace(2);  // {1,2}
    st.insert(2);   // {1,2}    
    // unordered_set stores only unique elements
}

void explainunorderedMap(){
    // uses hashing , faster than map but not ordered
    unordered_map<int, int> mp;
    mp[1] = 2;   // {1:2}
    mp.emplace(3,4);   // {1:2, 3:4}
    mp[1] = 5;   // {1:5, 3:4}   // updates the value at key 1
    // unordered_map stores only unique keys
}   


