Link: https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1
 
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        vector<int>nge(arr.size());
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i]=-1;
            }
            else{
                nge[i]=st.top();
            }
            st.push(arr[i]);
        }
        return nge;
    }
};