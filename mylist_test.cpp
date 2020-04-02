#include<iostream>
#include"myList.h"
using namespace std;

int main()
{
    DCLink<int> dc;
    for(int i=0;i<10;i++){
        dc.push_back(i);
    }
    dc.show();
    dc.push_front(11);
    dc.show();
    dc.pop_back();
    dc.show();
    dc.clear();
    dc.show();
    return 0;
}

