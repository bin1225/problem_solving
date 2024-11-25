package BOJ.구현;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ10798 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[][] ch= new char[5][15];
        int maxLen = 0;

        for (int i = 0; i < 5; i++) {
            String s = br.readLine();
            maxLen = Math.max(maxLen, s.length());

            for(int j=0; j<s.length(); j++){
                ch[i][j] = s.charAt(j);
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int j=0; j<maxLen; j++){
            for(int i=0; i<5; i++){
                if(ch[i][j]=='\0') continue;
                sb.append(ch[i][j]);
            }
        }

        System.out.println(sb);
    }
}
