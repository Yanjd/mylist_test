/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素

*/
#include<iostream>
#include<string>
using namespace std;
bool isMatch( string s, string p) {
        bool dp[s.size()+1][p.length()+1];  
	    dp[0][0]=true; 
	    for(int i=0;i<p.length();i++){
		    if(p[i]=='*' && dp[0][i-1]){
			    dp[0][i+1]=true; 
		    }else{
			    dp[0][i+1]=false;
		    }
	    }
	    if(s.length()>=1){
		    for(int i=1;i<s.length()+1;i++){
			    dp[i][0]=false;
		    }
	    }
	    for(int i=0;i<s.length();i++){
		    for(int j=0;j<p.length();j++){
			    if(s[i]==p[j] || p[j]=='.'){
				    dp[i+1][j+1]=dp[i][j];
			    }else if(p[j]=='*'){
				    if(p[j-1]!=s[i] && p[j-1]!='.'){
					    dp[i+1][j+1]=dp[i+1][j-1];
				    }else{
					    if(dp[i][j+1] || dp[i+1][j] || dp[i+1][j-1]) {
						    dp[i+1][j+1]=true;
					    }else{
						    dp[i+1][j+1]=false;
					    }
				    }
			    }
			    else{
				    dp[i+1][j+1]=false;
			    }
		    }
	    }
	    return dp[s.length()][p.length()];
    }
int main()
{
    string s="abc";
    string p="abc*";
    cout<<isMatch(s,p);
    return 0;
}