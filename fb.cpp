#include<iostream>
using namespace std;



int main(){
    return 0;
}



//[1,2,4,4,7,7,7,9]
int count(vector<int> nums, int k){
    if(nums.empty()){
      return 0;
    }
    auto first=lower_bound(nums.begin(),nums.end(),k);//logN
    if(first==nums.end() || *first!=k){
      return 0;
    }
    auto second=upper_bound(nums.begin(),nums.end(),k);//logN
    return second-first;
}

k=4
k=5;
k=7;
k=8;




enum Direction { UP, DOWN, LEFT, RIGHT };

bool isGoal();
bool move(Direction d);


int i=0,j=0;
bool canMove(){
  if(isGoal()){
    return true;
  }
  queue<pair<int,int>>q;
  map<pair<int,int>,set<i>>seen;
  q.push(make_pair(i,j));
  seen.insert(make_pair(i,j));
  while(!q.empty()){
    int x=q.front();
    int y=q.front();

    for(int k=0;k<4;k++){
      if(seen[newpair(x,y,Direction[k])].size()==4){
        q.pop();
        continue;
      }
      if(move(Direction[k])){
        if(isGoal()){
          return true;
        }
        seen[newpair(x,y,Direction[k])].insert(k);
        putbackq(x,y,Direction);
        break;
      }else{

      }
    }
  }
  return false;
}

q:
// [0,0]
// [0,1]
// [1,1]
[2,1]


enum Direction { UP, DOWN, LEFT, RIGHT };
enum OppositeDirection {DOWN, UP, RIGHT, LEFT};
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool isGoal();
bool move(Direction d);
int i=0,j=0;
bool canMove(){
    bool res=false;
    map<pair<int,int>,set<int>>seen;
    dfs(res,i,j,seen);
    return res;
}
void dfs(bool &res,int i,int j, map<pair<int,int>,set<int>>&seen){
    if(res){
        return;
    }
    if(isGoal()){
        res=true;
        return;
    }
    if(seen[make_pair(i,j)].size()==4){
        return;
    }
    for(int k=0;k<4;k++){
        if(seen[make_pair(i,j)].count(k)){
            continue;
        }
        int x=i+dx[k];
        int y=j+dy[k];
        seen[make_pair(i,j)].insert(k);
        if(move(Direction[k])){
            dfs(res,x,y,seen);
            move(OppositeDirection[k]);
        }else{

        }
    }
}

Welcome to Facebook!

This is just a simple shared plaintext pad, with no execution capabilities.

When you know what language you'd like to use for your interview,
simply choose it from the dropdown in the top bar.

Enjoy your interview!

Question 1:

# Intersection of two arrays of integers

Given two arrays of integers, find the elements common to both.

Example: [1, 3, 5, 7] & [2, 3, 4, 5] -> [3, 5]

--- candidate

vector<int> intersection(vector<int> a, vector<int> b){
  if(a.empty()){
    return {};
  }
  if(b.empty()){
    return {};
  }
  int m=a.size();
  int n=b.size();
  vector<int>res;
  if(m>n){
    for(int i=0;i<n;i++){
      auto it=lower_bound(a.begin(),a.end(),b[i]);
      if(it==a.end()){
        break;
      }
      if(it!=a.end() && *it==b[i]){
        res.push_back(*it);
      }
    }
  }else{
    for(int i=0;i<m;i++){
      auto it=lower_bound(b.begin(),b.end(),a[i]);
      if(it==b.end()){
        break;
      }
      if(it!=b.end() && *it==a[i]){
        res.push_back(*it);
      }
    }
  }
  res.erase(unique(res.begin
  res.end()),res.end());
  return res;
}


------


# Tree to List

Here is a struct definition for a node that works for both binary trees and doubly-linked lists:
struct Node {
  struct Node* left;
  struct Node* right;
  int data;
}

Given a binary tree made of these nodes, convert it, in-place, into a doubly linked list in the same order as an in-order traversal of the tree.

You should return the head and tail of the linked list.
Example
 ->   7
     / \
    3   9
   /   /
  1   8
   \
    2

Output
-> 1 <-> 2 <-> 3 <-> 7 <-> 8 <-> 9

--- candidate

Node* convert2LinkdedNode(Node* root){
  pair<Node*,Node*> res=postorder(root);
  return res.second;
}
//<max,min>
pair<Node*,Node*> postorder(Node* root){
  if(root==NULL){
    return make_pair(NULL,NULL);
  }
  if(root->left==NULL && root->right==NULL){
    return make_pair(root,root);
  }
  pair<Node*,Node*> leftTree = postorder(root->left);
  pair<Node*,Node*> rightTree = postorder(root->right);
  root->left=leftTree.first;
  root->right=rightTree.second;
  return make_pair(rightTree.first,leftTree.second);
}