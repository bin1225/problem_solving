import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N, K;
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        PriorityQueue<Integer> PQ = new PriorityQueue<>();
        int[] visited = new int[100001];
        Arrays.fill(visited, 987654321);

        PQ.add(N);
        visited[N] = 0;

        while (!PQ.isEmpty()) {
            int x = PQ.poll();
            int time = visited[x];

            if (x * 2 <= 100000 && time < visited[x * 2]) {
                visited[x * 2] = time;
                PQ.add(x*2);
            }
            if (x + 1 <= 100000 && time + 1 < visited[x + 1]) {
                visited[x + 1] = time + 1;
                PQ.add(x+1);
            }
            if (x - 1 >= 0 && time + 1 < visited[x - 1]) {
                visited[x - 1] = time + 1;
                PQ.add(x-1);
            }
        }

        System.out.println(visited[K]);
    }

}