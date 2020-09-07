import java.io.*;
import java.util.*;
import java.util.concurrent.Semaphore;


public class Main {
    static int n, m, h;
    static int[][] dp = new int[51][1001];
    static List<Integer> l[] = new ArrayList[51];
    public static void main( String[] argc ) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        h = sc.nextInt();
        sc.nextLine();
        for(int i = 0; i < n; i++) {
            l[i] = new ArrayList<>();
            StringTokenizer st = new StringTokenizer(sc.nextLine());
            while(st.hasMoreTokens()) {
                l[i].add(Integer.parseInt(st.nextToken()));
            }
            dp[i][0] = 1;
            for(int j = 1; j <= h; j++)
                dp[i][j] = -1;
        }
        System.out.println(dpf(0, h));
    }
    static int dpf(int cur, int left) {
        if(left == 0) return 1;
        if(left < 0) return 0;
        if(dp[cur][left]!=-1) return dp[cur][left];
        if(cur == n) return 0;
        dp[cur][left] = dpf(cur + 1,left);
        for(int possible : l[cur]) {
            dp[cur][left] += dpf(cur+1, left - possible);
        }
        dp[cur][left] %= 10007;
        return dp[cur][left];
    }
}
