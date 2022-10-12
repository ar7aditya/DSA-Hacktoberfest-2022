public class depthFirstSearch {
    public ArrayList<Integer> dfs(int V, ArrayList<ArrayList<Integer>> adj)
    {
        boolean[] visited= new boolean[V];
        ArrayList<Integer> ans= new ArrayList<>();
        

        Arrays.fill(visited, false);
        dfsUtil(V, ans, visited,adj);
        return ans;
    }
     dfsUtil(int V, ArrayList<Integer> ans, boolean[] visited, ArrayList<ArrayList<Integer>> adj)
    {
        visited[V]=true;
        ans.add(V);

        for (int i = 0; i < adj.get(V).size(); i++) 
            {

                    int neighbour = adj.get(V).get(i);

                    if(visited[neighbour]==false)
                    {
                       dfsUtil(V,ans, visited, adj)
                    }
                    
            }
        }


    }

}
