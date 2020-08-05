import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int[][] map = new int[50][50];
    static boolean[][] v = new boolean[50][50];
    static int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
    static int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
    static Queue<pair> q = new LinkedList<>();
    static int n, m;
    public static void main(String[] args) throws IOException {
        Reader r = new Reader();
        while(true) {
            m = r.nextInt();
            n = r.nextInt();
            if(n == 0) break;
            int ans = 0;
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j) {
                    map[i][j] = r.nextInt();
                    v[i][j] = false;
                }
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j) {
                    if(v[i][j] || map[i][j] == 0) continue;
                    v[i][j] = true;
                    q.add(new pair(i, j));
                    ++ans;
                    while(!q.isEmpty()) {
                        pair p = q.remove();
                        for(int k = 0; k < 8; ++k) {
                            int nx = p.s + dx[k];
                            int ny = p.f + dy[k];
                            if(0<=nx&&nx<m && 0<=ny&&ny<n && map[ny][nx] == 1 && !v[ny][nx]){
                                q.add(new pair(ny, nx));
                                v[ny][nx] = true;
                            }
                        }
                    }
                }
            System.out.println(ans);
        }
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
