import java.io.*;

public class Main {
    static int[][] map = new int[8][8];
    static int[][] v = new int[8][8];
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
                    cctvs[cnt++] = new cctv(i, j);
            }
        for(int i = 0; i < cnt; ++i)
            if(map[cctvs[i].f][cctvs[i].s] == 5)
                for(int k = 0; k < 4; ++k) {
                    int nx = cctvs[i].s + dx[k];
                    int ny = cctvs[i].f + dy[k];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        ++v[ny][nx];
                        ny += dy[k];
                        nx += dx[k];
                    }
                }

        bfs(0);
        System.out.println(ans);
    }

    static void bfs(int idx) {
        if(idx == cnt) {
            int ret = 0;
            for(int i = 0; i < n && ret < ans && ans != 0; ++i)
                for(int j = 0; j < m; ++j)
                    if(v[i][j] == 0 && map[i][j] == 0)
                        ++ret;
            ans = Math.min(ans, ret);
            return;
        }
        switch (map[cctvs[idx].f][cctvs[idx].s]) {
            case 1:
                for(int d = 0; d < 4; ++d) {
                    int nx = cctvs[idx].s + dx[d];
                    int ny = cctvs[idx].f + dy[d];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        ++v[ny][nx];
                        ny += dy[d];
                        nx += dx[d];
                    }
                    bfs(idx + 1);
                    nx = cctvs[idx].s + dx[d];
                    ny = cctvs[idx].f + dy[d];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        --v[ny][nx];
                        ny += dy[d];
                        nx += dx[d];
                    }
                }
                break;
            case 2:
                for(int d = 0; d < 2; ++d) {
                    int nx = cctvs[idx].s + dx[d];
                    int ny = cctvs[idx].f + dy[d];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        ++v[ny][nx];
                        ny += dy[d];
                        nx += dx[d];
                    }
                    nx = cctvs[idx].s + dx[d + 2];
                    ny = cctvs[idx].f + dy[d + 2];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        ++v[ny][nx];
                        ny += dy[d + 2];
                        nx += dx[d + 2];
                    }
                    bfs(idx + 1);
                    nx = cctvs[idx].s + dx[d];
                    ny = cctvs[idx].f + dy[d];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        --v[ny][nx];
                        ny += dy[d];
                        nx += dx[d];
                    }

                    nx = cctvs[idx].s + dx[d + 2];
                    ny = cctvs[idx].f + dy[d + 2];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        --v[ny][nx];
                        ny += dy[d + 2];
                        nx += dx[d + 2];
                    }
                }
                break;
            case 3:
                for(int d = 0; d < 4; ++d) {
                    int nx = cctvs[idx].s + dx[d];
                    int ny = cctvs[idx].f + dy[d];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        ++v[ny][nx];
                        ny += dy[d];
                        nx += dx[d];
                    }
                    nx = cctvs[idx].s + dx[(d + 1) % 4];
                    ny = cctvs[idx].f + dy[(d + 1) % 4];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        ++v[ny][nx];
                        ny += dy[(d + 1) % 4];
                        nx += dx[(d + 1) % 4];
                    }
                    bfs(idx + 1);
                    nx = cctvs[idx].s + dx[d];
                    ny = cctvs[idx].f + dy[d];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        --v[ny][nx];
                        ny += dy[d];
                        nx += dx[d];
                    }
                    nx = cctvs[idx].s + dx[(d + 1) % 4];
                    ny = cctvs[idx].f + dy[(d + 1) % 4];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        --v[ny][nx];
                        ny += dy[(d + 1) % 4];
                        nx += dx[(d + 1) % 4];
                    }
                }
                break;
            case 4:
                for(int d = 0; d < 4; ++d) {
                    int nx = cctvs[idx].s + dx[d];
                    int ny = cctvs[idx].f + dy[d];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        ++v[ny][nx];
                        ny += dy[d];
                        nx += dx[d];
                    }
                    nx = cctvs[idx].s + dx[(d + 1) % 4];
                    ny = cctvs[idx].f + dy[(d + 1) % 4];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        ++v[ny][nx];
                        ny += dy[(d + 1) % 4];
                        nx += dx[(d + 1) % 4];
                    }

                    nx = cctvs[idx].s + dx[(d + 3) % 4];
                    ny = cctvs[idx].f + dy[(d + 3) % 4];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        ++v[ny][nx];
                        ny += dy[(d + 3) % 4];
                        nx += dx[(d + 3) % 4];
                    }
                    bfs(idx + 1);
                    nx = cctvs[idx].s + dx[d];
                    ny = cctvs[idx].f + dy[d];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        --v[ny][nx];
                        ny += dy[d];
                        nx += dx[d];
                    }
                    nx = cctvs[idx].s + dx[(d + 1) % 4];
                    ny = cctvs[idx].f + dy[(d + 1) % 4];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        --v[ny][nx];
                        ny += dy[(d + 1) % 4];
                        nx += dx[(d + 1) % 4];
                    }
                    nx = cctvs[idx].s + dx[(d + 3) % 4];
                    ny = cctvs[idx].f + dy[(d + 3) % 4];
                    while(0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] != 6) {
                        --v[ny][nx];
                        ny += dy[(d + 3) % 4];
                        nx += dx[(d + 3) % 4];
                    }
                }
                break;
            case 5: bfs(idx + 1);
            default: break;
        }
    }

    static class cctv{
        public int f, s;
        public cctv(int f, int s) {
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
