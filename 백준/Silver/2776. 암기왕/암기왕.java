import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(br.readLine());
        while(T-->0) {
            solution();
        }
    }

    private static void solution() throws IOException{
        int N, M;

        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        Set<String> set = new HashSet<>();
        for(int i=0; i<N; i++) {
            set.add(st.nextToken());
        }

        M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        List<Integer> list = new ArrayList<>();
        for(int i=0; i<M; i++) {
            if (set.contains(st.nextToken())) {
                list.add(1);
            }
            else list.add(0);
        }

        for (Integer integer : list) {
            System.out.println(integer);
        }
    }
}