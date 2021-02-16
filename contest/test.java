import java.util.*;
 
public class Main{
	public static void main (String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int o = sc.nextInt();
	    
	    for(int b = 0; b < o; b ++){
    String str = sc.next();
    int x = Integer.parseInt(str);
    int a = x / 2;
    if(a % 2 == 0 ){
        System.out.println("DA");
    }
    else{
        System.out.println("NET");
    }
	    }
        
	}
}