import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n, k;
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        ArrayList<Integer> coins = new ArrayList<Integer>();
        for(int i=0; i<n; i++){
            int a = Integer.parseInt(br.readLine());
            coins.add(a);
        }


        int[] dp = new int[k+1];
        Arrays.fill(dp, 101010);
        dp[0] = 0;
        for(int i=0; i<=k; i++){
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        if(dp[k] != 101010) System.out.println(dp[k]);
        else System.out.println(-1);
    }

}