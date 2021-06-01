// this ques is hard and as well as important

#include <iostream>
#include <vector>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;

void insert(int x){
   if(pqmax.size() == pqmin.size())
   {
       if(pqmax.size() == 0)
       {
           pqmax.push(x);
           return;
       }

       if(x < pqmax.top())
       {
           pqmax.push(x);
       }else
       {
           pqmin.push(x);
       }
   }
   else
   {
       //2 - condition arises
       // 1- maxheap > minheap AND 2 - minheap > maxheap

       if(pqmax.size() > pqmin.size())
       {
        if(x >= pqmax.top())
        {
            pqmin.push(x);
        }else
        {
            int temp = pqmax.top();
            pqmax.pop();
            pqmax.push(x);
            pqmin.push(temp);
        }
       }
       else
       {
           if(x <= pqmin.top())
           {
               pqmax.push(x);
           }
           else
           {
               int temp = pqmin.top();
               pqmin.pop();
               pqmax.push(temp);
               pqmin.push(x);
           }
       }
   }
}

double findMedian(){
    
    if(pqmax.size() == pqmin.size())
    {
        return (pqmax.top() + pqmin.top()) / 2.0;
    }
    else if(pqmax.size() > pqmin.size())
    {
        return pqmax.top();
    }
    else
    {
        return pqmin.top();
    }
}

int main(){
    insert(10);
    cout << findMedian() << endl;
     insert(15);
    cout << findMedian() << endl;
     insert(21);
    cout << findMedian() << endl;
     insert(30);
    cout << findMedian() << endl;
     insert(18);
    cout << findMedian() << endl;
     insert(19);
    cout << findMedian() << endl;

}