import java.io.*;

public class Main {
    static int[][] map = new int[8][8];
    static boolean[][] v = new boolean[8][8];
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {-1, 0, 1, 0};
    static cctv[] cctvs = new cctv[8];
    static int n, m, cnt, ans = 987654321;
    public static void main(String[] args) throws IOException {
        Reader r = new Reader();
        n = r.nextInt();
        m = r.nextInt();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                map[i][j] = r.nextInt();
                if(1 <= map[i][j] && map[i][j] <= 5)
                    cctvs[cnt++] = new cctv(i, j, 0);
            }

        bfs(0);
        System.out.println(ans);
    }

    static void bfs(int idx) {
        if(idx == cnt) {
            solution();
            return;
        }
        switch (map[cctvs[idx].f][cctvs[idx].s]) {
            case 1:
            case 3:
            case 4:
                for(cctvs[idx].d = 0; cctvs[idx].d < 4; ++cctvs[idx].d)
                    bfs(idx + 1);
                break;
            case 2:
                for(cctvs[idx].d = 0; cctvs[idx].d < 2; ++cctvs[idx].d)
                    bfs(idx + 1);
                break;
            case 5: bfs(idx + 1);
            default: break;
        }
    }

    static void solution() {
        int ret = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                v[i][j] = false;
        for(int i = 0; i < cnt; ++i) {
            switch (map[cctvs[i].f][cctvs[i].s]) {
                case 1:
                case 2:{
                    int nx = cctvs[i].s + dx[cctvs[i].d];
                    int ny = cctvs[i].f + dy[cctvs[i].d];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n) {
                        if(map[ny][nx] == 6) break;
                        v[ny][nx] = true;
                        ny += dy[cctvs[i].d];
                        nx += dx[cctvs[i].d];
                    }
                }
                if(map[cctvs[i].f][cctvs[i].s] == 1) break;
                {
                    int nx = cctvs[i].s + dx[cctvs[i].d + 2];
                    int ny = cctvs[i].f + dy[cctvs[i].d + 2];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n) {
                        if(map[ny][nx] == 6) break;
                        v[ny][nx] = true;
                        ny += dy[cctvs[i].d + 2];
                        nx += dx[cctvs[i].d + 2];
                    }
                }
                break;
                case 3:
                case 4:{
                    int nx = cctvs[i].s + dx[cctvs[i].d];
                    int ny = cctvs[i].f + dy[cctvs[i].d];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n) {
                        if(map[ny][nx] == 6) break;
                        v[ny][nx] = true;
                        ny += dy[cctvs[i].d];
                        nx += dx[cctvs[i].d];
                    }
                    nx = cctvs[i].s + dx[(cctvs[i].d + 1) % 4];
                    ny = cctvs[i].f + dy[(cctvs[i].d + 1) % 4];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n) {
                        if(map[ny][nx] == 6) break;
                        v[ny][nx] = true;
                        ny += dy[(cctvs[i].d + 1) % 4];
                        nx += dx[(cctvs[i].d + 1) % 4];
                    }

                    if(map[cctvs[i].f][cctvs[i].s] == 3) break;

                    nx = cctvs[i].s + dx[(cctvs[i].d + 3) % 4];
                    ny = cctvs[i].f + dy[(cctvs[i].d + 3) % 4];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n) {
                        if(map[ny][nx] == 6) break;
                        v[ny][nx] = true;
                        ny += dy[(cctvs[i].d + 3) % 4];
                        nx += dx[(cctvs[i].d + 3) % 4];
                    }
                    break;
                }
                case 5: {
                    for(int j = 0; j < 4; ++j) {
                        int nx = cctvs[i].s + dx[j];
                        int ny = cctvs[i].f + dy[j];
                        while(0 <= nx && nx < m && 0 <= ny && ny < n) {
                            if(map[ny][nx] == 6) break;
                            v[ny][nx] = true;
                            ny += dy[j];
                            nx += dx[j];
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(!v[i][j] && map[i][j] == 0)
                    ++ret;
        ans = Math.min(ans, ret);
    }

    static class pair{
        public int f, s;
        public pair(int f, int s){
            this.f = f;
            this.s = s;
        }
    }

    static class cctv{
        public int f, s, d;
        public cctv(int f, int s, int d) {
            this.f = f;
            this.s = s;
            this.d = d;
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
