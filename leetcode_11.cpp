/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
(使用双指针法可减小时间复杂度)
*/
#include<iostream>
#include<vector>
using namespace std;
int maxArea(vector<int>& height) {
        /*
        int area=0,temp=0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                temp=(j-i)*(min(height[i],height[j]));
                if(temp>area){
                    area=temp;
                }
            }
        }
        return area;
        */
        int beg=0,end=height.size()-1;
        int temp=0,area=0;
        while(beg<end){
            temp=(end-beg)*min(height[beg],height[end]);
            area=area>temp?area:temp;
            if(height[beg]<=height[end]){
                beg++;
            }
            else{
                end--;
            }
        }
        return area;
    }
int main()
{
    vector<int> a={1,8,6,2,5,4,8,3,7};
    cout<<"max area is"<<maxArea(a);
    return 0;
}