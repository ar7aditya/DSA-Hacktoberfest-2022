import java.util.Scanner;

public class Permutations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        perm("",s);
    }
    static void perm(String p,String up){
        if (up.isEmpty()){
            System.out.println(p);
            return;
        }
        char c = up.charAt(0);
        for (int i = 0;i <= p.length();i++){
            String f = p.substring(0,i);
            String s = p.substring(i);
            perm(f + c + s,up.substring(1));
        }
    }
}
