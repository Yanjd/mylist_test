/*
    给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合
    使用回溯法

*/
#include<string>
#include<vector>
#include<iostream>
using namespace std;

void backtrace(vector<string>&res,string cur,int left,int right,int num){
    if(cur.size()==2*num){
         res.push_back(cur);
        return;
    }
    if(left<num){
        backtrace(res,cur+"(",left+1,right,num);
    }
    if(right<left){
        backtrace(res,cur+")",left,right+1,num);
    }
}
vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrace(res,"",0,0,n);
        return res;   
}


int main(){
    vector<string> ans=generateParenthesis(3);
    cout<<"nums is "<<ans.size();
    return 0;
}