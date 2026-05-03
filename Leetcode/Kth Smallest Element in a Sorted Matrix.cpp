Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/



class Solution {
public:


    int check(int mid,vector<vector<int>>& matrix){
        int n = matrix.size();
        int i=n-1;
        int j = 0;

        int count=0;
        while(i>=0 && j<n){
            if(matrix[i][j]<=mid){
                count+=i+1;
                j++;
            }
            else{
                i--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n =matrix.size();
        int l = matrix[0][0];
        int h = matrix[n-1][n-1];
        while(l<=h){
            int mid = (l+(h-l)/2);
            if(check(mid,matrix)>=k){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
