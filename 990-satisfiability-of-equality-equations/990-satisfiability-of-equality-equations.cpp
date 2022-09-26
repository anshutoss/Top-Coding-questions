class DSU{
  public:
    vector<int>par;
    
    DSU(){
        for(int i=0; i<26; i++)par.push_back(-1);
    }
    
    int find_parent(int v){
        return par[v]<0 ? v : par[v] = find_parent(par[v]);
    }
    
    void merge(int x,int y){
        if((x=find_parent(x))==(y=find_parent(y))) return;
        if(par[y]>par[x])swap(x,y);
        if(par[x]==par[y])par[x]--;
        par[y]=x;
    }
    
};



class Solution {
public:
    bool equationsPossible(vector<string>& v) {
        int n=v.size();
        DSU* dsu= new DSU();
        for(int i=0; i<v.size(); i++){
            if(v[i][1]=='=')dsu->merge(v[i][0]-'a',v[i][3]-'a');
        }
        for(int i=0; i<v.size(); i++){
            if(v[i][1]=='!')if(dsu->find_parent(v[i][0]-'a')==dsu->find_parent(v[i][3]-'a'))return false;
        }
        return true;
    }
};