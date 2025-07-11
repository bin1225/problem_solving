import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static int N, K;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N, d, k, c;
        N = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        int[] A = new int[N];
        for(int i=0; i<N; i++) {
            A[i] = Integer.parseInt(br.readLine());
        }

        int[] check = new int[d + 1];
        check[c]++;

        int cnt = 1;
        for (int i = 0; i < k; i++) {
            if(check[A[i]] == 0) cnt++;
            check[A[i]]++;
        }

        int answer = 0;
        for(int i=0; i<N; i++) {
            check[A[i]]--;
            if(check[A[i]] == 0) cnt--;

            int idx = (i+k)%N;
            if(check[A[idx]] == 0) cnt++;
            check[A[idx]]++;

            answer = Math.max(answer, cnt);
        }

        System.out.println(answer);
    }
}
