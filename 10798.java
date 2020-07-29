import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] board = new String[5];
        int maxlen = 0;
        for(int i = 0; i < 5; ++i) {
            board[i] = br.readLine();
            maxlen = Math.max(maxlen, board[i].length());
        }
        for(int i = 0; i < maxlen; ++i)
            for(int j = 0; j < 5; ++j) {
                if (board[j].length() <= i) continue;
                bw.write(board[j].charAt(i));
            }
        bw.flush();
    }
}
