import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static String[] map = new String[25];
    static boolean[][] v = new boolean[25][25];
    static int[] ans = new int[625];
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {-1, 0, 1, 0};
    static Queue<pair> q = new LinkedList<>();
    static int n, g;
    public static void main(String[] args) throws IOException {
        Reader r = new Reader();
        n = r.nextInt();
        for(int i = 0; i < n; ++i)
                map[i] = r.readLine();

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                if(map[i].charAt(j) == '0' || v[i][j]) continue;
                q.add(new pair(i, j));
                v[i][j] = true;
                int cnt = 1;
                while(!q.isEmpty()){
                    pair p = q.remove();
                    for(int k = 0; k < 4; ++k) {
                        int nx = p.s + dx[k];
                        int ny = p.f + dy[k];
                        if(0<= nx && nx < n && 0 <= ny && ny < n && !v[ny][nx] && map[ny].charAt(nx) == '1'){
                            q.add(new pair(ny, nx));
                            v[ny][nx] = true;
                            ++cnt;
                        }
                    }
                }
                ans[g++] = cnt;
            }

        Arrays.sort(ans, 0, g);
        System.out.println(g);
        for(int i = 0; i < g; ++i)
            System.out.println(ans[i]);
    }

    static class pair{
        public int f, s;
        public pair(int f, int s){
            this.f = f;
            this.s = s;
        }
    }

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public int nextInt() throws IOException {
            int ret = 0, flag = 1;
            byte c = read();
            if(c == '-') {
                flag = -1;
                c = read();
            }
            do {
                ret = (ret<<3) + (ret<<1) + (c & 0b1111);
            }  while ((c = read()) >= '0' && c <= '9');

            return ret * flag;
        }
        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1)
            {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }


        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
    }
}
