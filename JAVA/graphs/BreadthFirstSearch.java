public class BreadthFirstSearch {
    ArrayList<Integer> bfs(int V, ArrayList<ArrayList<Integer>> adj)
    {
        ArrayList<Integer> ans= new ArrayList<>();
        boolean[] visited= new boolean[V];
        Queue<Integer> queue= new LinkedList<>();

        visited[0]=0;
        queue.add(0);

        while(!queue.isEmpty())
        {
            int curr= queue.remove();
            ans.add(curr);

            for(Integer neighbour: adj.get(curr).size())
            {
                if(!visited[neighbour])
                {
                    visited[neighbour]= true;
                    queue.add(neighbour);
                }
            }
        }

        return ans;
        
    }
}
