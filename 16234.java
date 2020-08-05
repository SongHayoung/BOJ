import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int[][] map = new int[50][50];
    static int[][] u = new int[50][50];
    static boolean[][] v = new boolean[50][50];
    static int[] g = new int[2501];
    static int N, L, R;
    static Queue<pair> q = new LinkedList<>();
    public static void main(String[] args) throws IOException {
        Reader r = new Reader();
        int[] dx = {0,1,0,-1};
        int[] dy = {-1,0,1,0};
        int ans = 0;
        boolean flag = true;
        
        N = r.nextInt();
        L = r.nextInt();
        R = r.nextInt();
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                map[i][j] = r.nextInt();

        while(flag) {
            flag = false;
            int gN = 1;
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j) {
                    v[i][j] = false;
                    u[i][j] = gN++;
                }
            gN = 1;
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j) {
                    if(v[i][j]) continue;
                    v[i][j] = true;
                    u[i][j] = gN;
                    int sum = map[i][j];
                    int cnt = 1;
                    q.add(new pair(i,j));
                    while(!q.isEmpty()) {
                        pair p = q.remove();
                        for (int k = 0; k < 4; ++k) {
                            int nx = p.s + dx[k];
                            int ny = p.f + dy[k];
                            if (0 <= nx && nx < N && 0 <= ny && ny < N)
                                if (!v[ny][nx] && L <= Math.abs(map[p.f][p.s] - map[ny][nx]) &&
                                        Math.abs(map[p.f][p.s] - map[ny][nx]) <= R) {
                                    q.add(new pair(ny, nx));
                                    v[ny][nx] = true;
                                    u[ny][nx] = gN;
                                    ++cnt;
                                    sum += map[ny][nx];
                                    flag = true;
                                }
                        }
                    }
                    g[gN++] = sum / cnt;
                }
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    map[i][j] = g[u[i][j]];
            if(flag) ++ans;
        }
        

        System.out.println(ans);
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
