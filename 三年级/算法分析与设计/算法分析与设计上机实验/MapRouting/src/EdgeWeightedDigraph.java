import edu.princeton.cs.algs4.Bag;
import edu.princeton.cs.algs4.DirectedEdge;
import edu.princeton.cs.algs4.In;

public class EdgeWeightedDigraph {

	private int V;
	private int E;
	private Bag<DirectedEdge>[] adj;
	private int[] X;
	private int[] Y;
	
	public EdgeWeightedDigraph(In in, DrawMap DM) {
        this.V = in.readInt();
        this.E = in.readInt();
        if (V < 0) throw new IllegalArgumentException("Number of vertices in a Digraph must be nonnegative");
        if (E < 0) throw new IllegalArgumentException("Number of edges must be nonnegative");
        this.X = new int[this.V];
        this.Y = new int[this.V];
//        System.out.println(V);
//        System.out.println(E);
        this.adj = (Bag<DirectedEdge>[]) new Bag[V];
        for (int v = 0; v < V; v++)
            adj[v] = new Bag<DirectedEdge>();
        for (int i = 0; i < V; i++) {
        	int index = in.readInt();
        	X[index] = in.readInt();
        	Y[index] = in.readInt();
        }
        for (int i = 0; i < E; i++) {
            int v = in.readInt();
            int w = in.readInt();
            DM.addMapLine(X[v], Y[v], X[w], Y[w]);
            double absx = Math.abs(X[v] - X[w]);
            double absy = Math.abs(Y[v] - Y[w]);
            double weight = Math.sqrt(absx*absx + absy*absy);
            DirectedEdge e = new DirectedEdge(v, w, weight);
            adj[v].add(e);
            e = new DirectedEdge(w, v, weight);
            adj[w].add(e);
//            System.out.println(weight);
        }
    }
	
	public int V() {
		return V;
	}
	
	public int[] X() {
		return X;
	}
	
	public int[] Y() {
		return Y;
	}
	
	public Iterable<DirectedEdge> adj(int v) {
        return adj[v];
    }
	
}
