import java.util.Scanner;

import java.util.Arrays;

public class HamCycle

{

    private int V, pathCount;

    private int[] path;     

    private int[][] graph;

    /** Function to find cycle **/

    public void findHamiltonianCycle(int[][] g)

    {

        V = g.length;

        path = new int[V];

 

        Arrays.fill(path, -1);

        graph = g;        

        try

        {            

            path[0] = 0;

            pathCount = 1;            

            solve(0);

            System.out.println("No solution");

        }

        catch (Exception e)

        {

            System.out.println(e.getMessage());

            display();

        }

    }

    /** function to find paths recursively **/

    public void solve(int vertex) throws Exception

    {

        /** solution **/

        if (graph[vertex][0] == 1 && pathCount == V)

            throw new Exception("Solution found");

        /** all vertices selected but last vertex not linked to 0 **/

        if (pathCount == V)

            return;

 

        for (int v = 0; v < V; v++)

        {

            /** if connected **/

            if (graph[vertex][v] == 1 )

            {

                /** add to path **/            

                path[pathCount++] = v;    

                /** remove connection **/            

                graph[vertex][v] = 0;

                graph[v][vertex] = 0;

 

                /** if vertex not already selected  solve recursively **/

                if (!isPresent(v))

                    solve(v);

 

                /** restore connection **/

                graph[vertex][v] = 1;

                graph[v][vertex] = 1;

                /** remove path **/

                path[--pathCount] = -1;                    

            }

        }

    }    

    /** function to check if path is already selected **/

    public boolean isPresent(int v)

    {

        for (int i = 0; i < pathCount - 1; i++)

            if (path[i] == v)

                return true;

        return false;                

    }

    /** display solution **/

    public void display()

    {

        System.out.print("\nPath : ");

        for (int i = 0; i <= V; i++)

            System.out.print(path[i % V] +" ");

        System.out.println();

    }    

    /** Main function **/

    public static void main (String[] args) 

    {

        Scanner scan = new Scanner(System.in);

        HamCycle hc = new HamCycle();

        System.out.print("Enter number of vertices: ");

        int V = scan.nextInt();

        // get graph

        System.out.println("Enter matrix:");

        int[][] graph = new int[V][V];

        for (int i = 0; i < V; i++)

            for (int j = 0; j < V; j++)

                graph[i][j] = scan.nextInt();

 

        hc.findHamiltonianCycle(graph);        

    }    

}
