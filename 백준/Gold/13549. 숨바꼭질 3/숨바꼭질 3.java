import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Loc implements Comparable<Loc> {
        int now;
        int time;

        Loc(int now, int time) {
            this.now = now;
            this.time = time;
        }

        @Override
        public int compareTo(Loc o) {
            return this.time - o.time;
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N, K;
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        PriorityQueue<Loc> PQ = new PriorityQueue<>();
        int[] visited = new int[100001];
        Arrays.fill(visited, 987654321);
        PQ.add(new Loc(N, 0));
        visited[N] = 0;

        while (!PQ.isEmpty()) {
            Loc loc = PQ.poll();
            int x = loc.now;
            int time = loc.time;

            if (x == K) {
                System.out.println(time);
                return;
            }
            if (x * 2 <= 100000 && time < visited[x * 2]) {
                visited[x * 2] = time;
                PQ.add(new Loc(x * 2, time));
            }
            if (x + 1 <= 100000 && time + 1 < visited[x + 1]) {
                visited[x + 1] = time + 1;
                PQ.add(new Loc(x + 1, time + 1));
            }
            if (x - 1 >= 0 && time + 1 < visited[x - 1]) {
                visited[x - 1] = time + 1;
                PQ.add(new Loc(x - 1, time + 1));
            }

        }
    }

}