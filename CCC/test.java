package CCC;
import java.util.*;
public class test{
    static int compare(String a, String b){
        int cnt = 0;
        for(int i=0;i<Math.min(a.length(),b.length());i++){
            if(a.charAt(i)==b.charAt(i)) cnt++;
            else return cnt;
        }
        return cnt;
    }
    public static void main(String[] args){
        List<String> ls = new ArrayList<String>();
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        ls.add(" ");
        ls.add(s);
        int Q = sc.nextInt();
        char op;
        for(int i=0;i<Q;i++){
            op = sc.next().charAt(0);
            if(op=='C'){
                int t = sc.nextInt();
                char c = sc.next().charAt(0);
                String nw = ls.get(t) + c;
                ls.add(nw);
            }
            else{
                s = sc.next();
                int mx = 0, mxpos = -1;
                for(int j=1;j<ls.size();j++){
                    int num = compare(ls.get(j), s);
                    if(num>mx){
                        mx = num;
                        mxpos = j;                    }
                }
                System.out.println(mxpos);
            }
        }
    }
}
