int sumOfDependencies(vector<int> adj[], int V) {
        // code here
        int sum=0;
        for(int i=0;i<V;i++){
            sum+=adj[i].size();
        }
        return sum;
    }