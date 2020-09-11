import edu.princeton.cs.algs4.DirectedEdge;
import edu.princeton.cs.algs4.IndexMinPQ;
import edu.princeton.cs.algs4.Stack;

public class Dijkstra {

	
	private DirectedEdge[] edgeTo;
	private double[] distTo;
    private IndexMinPQ<Double> pq;
    
    public Dijkstra(EdgeWeightedDigraph G, int s, int t, DrawMap DM) {
    	distTo = new double[G.V()];
    	edgeTo = new DirectedEdge[G.V()];
    	pq = new IndexMinPQ<Double>(G.V());
    	for(int v = 0; v < G.V(); v++)
    		distTo[v] = Double.POSITIVE_INFINITY;
    	distTo[s] = 0.0;
    	pq.insert(s, 0.0);
    	while(!pq.isEmpty()) {
    		int v = pq.delMin();
//    		if(v == t)break;
    		for(DirectedEdge e: G.adj(v))
    			relax(e, G, t, DM);
    	}
    }
    
    private void relax(DirectedEdge e, EdgeWeightedDigraph G, int t, DrawMap DM) {
        int v = e.from(), w = e.to();
        DM.addSearchLine(G.X()[v], G.Y()[v], G.X()[w], G.Y()[w]);
//        double absxwt = Math.abs(G.X()[w] - G.X()[t]);
//        double absywt = Math.abs(G.Y()[w] - G.Y()[t]);
//        double weightwt = Math.sqrt(absxwt*absxwt + absywt*absywt);
//        double absxvt = Math.abs(G.X()[v] - G.X()[t]);
//        double absyvt = Math.abs(G.Y()[v] - G.Y()[t]);
//        double weightvt = Math.sqrt(absxvt*absxvt + absyvt*absyvt);
//        if (distTo[w] > distTo[v] + e.weight() + weightwt - weightvt) {
//            distTo[w] = distTo[v] + e.weight() + weightwt - weightvt;
//            //System.out.println(distTo[w]);
//            edgeTo[w] = e;
//            if (pq.contains(w))
//            	pq.decreaseKey(w, distTo[w]);
//            else
//            	pq.insert(w, distTo[w]);
//        }
        if (distTo[w] > distTo[v] + e.weight()) {
            distTo[w] = distTo[v] + e.weight();
            edgeTo[w] = e;
            if (pq.contains(w))
            	pq.decreaseKey(w, distTo[w]);
            else
            	pq.insert(w, distTo[w]);
        }
    }
    
    public double distTo(int v) {
        return distTo[v];
    }
    
    public boolean hasPathTo(int v) {
        return distTo[v] < Double.POSITIVE_INFINITY;
    }
    
    public Iterable<DirectedEdge> pathTo(int v) {
        if (!hasPathTo(v)) return null;
        Stack<DirectedEdge> path = new Stack<DirectedEdge>();
        for (DirectedEdge e = edgeTo[v]; e != null; e = edgeTo[e.from()]) {
            path.push(e);
        }
        return path;
    }
    
}
