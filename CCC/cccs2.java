import java.util.*;
import java.io.*;

public class escaperoom {
	static boolean ifpossible(int rowx, int columny, int rows, int columns) {
		if (rowx <= rows && columny <= columns) {
			return true;
		}
		return false;
	}
	static ArrayList<Integer> factorfinder(int test, int columns, int rows, ArrayList<ArrayList<Integer>> factors){
		int counter = 0;
		if (factors.get(test).isEmpty()) {
			for (int i = 1; i <= Math.sqrt(test); ++i) {
				if (test % i == 0) { 
					factors.get(test).add(counter, i);
					int otheri = test/i;
					factors.get(test).add(factors.get(test).size() - counter, otheri);
					counter += 1;
	        	}
			}    
	    } 
		return factors.get(test);
	}
	static boolean isescapeable(int[][] escaperoom, int rows, int columns, boolean[] visited, ArrayList<ArrayList<Integer>> factors) {
		LinkedList<Integer> queue = new LinkedList<Integer>();
		//access numbner in cell, mark as true then proccess its factors and neighbouts and add it to the queue
		queue.add(1);
		queue.add(1);
		
		while (!queue.isEmpty()) {
			int rowindex = queue.remove(0);
			int columnindex = queue.remove(0);
			if (columnindex == columns && rowindex == rows) {
				return true;
			}
			int test = escaperoom[columnindex][rowindex];
			//System.out.println(test);
			if (!visited[escaperoom[columnindex][rowindex]]) {
				visited[escaperoom[columnindex][rowindex]] = true;
				ArrayList<Integer> first = new ArrayList<Integer>();
				ArrayList<Integer> second = new ArrayList<Integer>();
				ArrayList<Integer> testfactors = factorfinder(test, columns, rows, factors);
		        for (int i = 0; i < testfactors.size() / 2; i++) {
		            first.add(testfactors.get(i)); 
		        }
		        for (int i = testfactors.size()-1; i >= testfactors.size()/2; i--) {
		            second.add(testfactors.get(i)); 
		            //System.out.println(second);
		        }
		        for (int j = 0; j<= first.size() -1; j++) {
		        	int rowx = first.get(j);
		        	int columny = second.get(j);
		        	if (ifpossible(rowx, columny, rows, columns)) {
		        		queue.add(rowx);
		        		queue.add(columny);
		        	}
		        	if (ifpossible(columny, rowx, rows, columns)) {
		        		queue.add(columny);
		        		queue.add(rowx);
		        	}
		        }
			}
		}
		return false;
	}
	public static void main(String[] args)throws Exception {
		//Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int rows = Integer.parseInt(br.readLine());
		int columns = Integer.parseInt(br.readLine());
		
		int escaperoom[][] = new int[columns+1][rows+1];
		boolean visited[] = new boolean[1000005];
		ArrayList<ArrayList<Integer>> factors = new ArrayList<ArrayList<Integer>>();
		
		
		for (int i = 0; i <= 1000000; i++) {
			ArrayList<Integer> empty = new ArrayList<Integer>();
            factors.add(empty);
            visited[i]=false;
		}
		
		for (int i = 0; i <= rows; i ++) {
			for (int j = 0; j <= columns; j ++) {
				escaperoom[j][i] = 0;
			}
		}
		for (int i = 1; i <= rows; i ++) {
			String input[] = br.readLine().split(" ");
			//System.out.println(input);
			for (int j = 1; j <= columns; j ++) {
				escaperoom[j][i] = Integer.parseInt(input[j-1]);
				
//				if (factors.get(escaperoom[j][i]).isEmpty()) {
//					System.out.println(escaperoom[j][i]);
//					System.out.println(factors.get(escaperoom[j][i]));
//				    for (int g = 1; g <= escaperoom[j][i]; g++) {
//				    	if (escaperoom[j][i]% g == 0) { 
//				    		factors.get(escaperoom[j][i]).add(g);
//				    		//System.out.println(factors.get(escaperoom[j][i]));
//				    		if (g * g == escaperoom[j][i]) {
//				    			factors.get(escaperoom[j][i]).add(g);
//				    		}
//				    	}
//				    }
//				}
			}
		}
		if (isescapeable(escaperoom, rows, columns, visited, factors)) {
			System.out.println("yes");
		} else {
			System.out.println("no");
		}
	}
}