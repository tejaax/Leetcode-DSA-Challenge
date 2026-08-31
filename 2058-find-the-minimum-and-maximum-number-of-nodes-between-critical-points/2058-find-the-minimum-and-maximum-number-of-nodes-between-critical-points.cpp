/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev=head->val;
        auto temp=head->next;
        vector<int>v;
        int i=0;
        while(temp->next!=nullptr){
            int cur=temp->val;
            int nxt=temp->next->val;
            if((cur<nxt && cur<prev) || (cur>prev && cur>nxt)){
                v.push_back(i);
            }
            i++;
            temp=temp->next;
            prev=cur;
        }

        if(v.size()<2){
            return {-1,-1};
        }

        int mini=INT_MAX;
        int maxi=v[v.size()-1]-v[0];
        for(int i=1;i<v.size();i++){
            mini=min(mini,v[i]-v[i-1]);
        }

        return {mini,maxi};
    }
};