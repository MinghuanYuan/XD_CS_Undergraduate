import java.util.Iterator;
import java.util.Scanner;

import edu.princeton.cs.algs4.DirectedEdge;
import edu.princeton.cs.algs4.In;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		In in = new In("D:\\WorkSpace-Eclipse\\MapRouting\\usa.txt");
		DrawMap DM = new DrawMap(1500, 850);
		EdgeWeightedDigraph G = new EdgeWeightedDigraph(in, DM);
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入起始节点");
		int s = sc.nextInt();
		System.out.println("请输入目的节点");
		int t = sc.nextInt();
		int stepnum = 0;
		long starttime = System.currentTimeMillis();
		Dijkstra sp = new Dijkstra(G, s, t, DM);
		long endtime = System.currentTimeMillis();
		System.out.println("distTo中的值为：" + sp.distTo(t));
		System.out.print("路径为：");
		if(sp.hasPathTo(t)) {
			Iterator<DirectedEdge> it = sp.pathTo(t).iterator();
			while(it.hasNext()) {
				DirectedEdge de = it.next();
				stepnum++;
				DM.addPathLine(G.X()[de.from()], G.Y()[de.from()], G.X()[de.to()], G.Y()[de.to()]);
				System.out.print(de.from() + "->");
				System.out.print(de.to() + "  ");
			}
		}
		System.out.println();
		System.out.println("该路径共由" + stepnum + "条边组成");
		System.out.println("寻找最短路径所需时间：" + (endtime - starttime) + "ms");
	}

}
