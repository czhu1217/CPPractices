package Olympiads;
import java.util.*;
public class vmss7wc16c3p2 {
    static ArrayList<Integer>[] graph;
    static boolean[] vis;

    static void DFS(int n) {
        vis[n] = true;
        for(int neighbour : graph[n]) {
            if(!vis[neighbour]) {
                DFS(neighbour);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        graph = new ArrayList[N+5];
        vis = new boolean[N+5];
        for(int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }
        for(int i = 0; i < M; i++) {
            int X = sc.nextInt();
            int Y = sc.nextInt();
            graph[X].add(Y);
            graph[Y].add(X);
        }
        DFS(A);
        if(vis[B]) {
            System.out.println("GO SHAHIR!");
        } else {
            System.out.println("NO SHAHIR!");
        }
    }
}
