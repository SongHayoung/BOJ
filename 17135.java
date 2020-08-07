import java.io.*;
import java.util.*;

import java.io.*;
import java.util.*;

public class Main {
    static void play() {
        int[][] p = new int[3][2];
        p[0][0] = p[1][0] = p[2][0] = n + 1;
        p[0][1] = arrow[0]; p[1][1] = arrow[1]; p[2][1] = arrow[2];
        int cnt = 0;
        boolean find;
        while(p[2][0] > 1) {
            Queue<pair> killed = new LinkedList<>();
            for(int k=0;k<3;k++) {
                find = false;
                for (int i = 1; i <= d; i++) {
                    int dx = -1;
                    int dy = 1 - i;
                    for (int j = 1; j < i * 2; j++) {
                        int nx = p[k][0]+dx;
                        int ny = p[k][1]+dy;

                        dx = (j<i)?dx-1:dx+1;
                        dy++;
                        if(nx<=0||ny<=0||ny>m)
                            continue;
                        if(map_cpy[nx][ny]==1){
                            if(status_cpy[nx][ny]){
                                cnt++;
                                status_cpy[nx][ny]=false;
                                killed.add(new pair(nx,ny));
                            }
                            find=true;
                            break;
                        }
                    }
                    if(find)
                        break;
                }
                p[k][0]--;
            }
            while(!killed.isEmpty()){
                pair pa = killed.remove();
                int nx = pa.f;
                int ny = pa.s;
                map_cpy[nx][ny]=0;
            }
        }
        ans = Math.max(ans, cnt);
        return;
    }

    static void DFS(int val, int idx) {
        if (idx == 3) {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++) {
                    map_cpy[i][j] = map[i][j];
                    status_cpy[i][j] = status[i][j];
                }
            play();
            return ;
        }
        for (int i = val; i <= m; i++) {
            arrow[idx] = i;
            DFS(i + 1, idx + 1);
        }
    }

    static int[][] map = new int[16][16];
    static int[][] map_cpy = new int[16][16];
    static boolean[][] status = new boolean[16][16];
    static boolean[][] status_cpy = new boolean[16][16];
    static int n, m, ans, d;
    static int[] arrow = new int[3];

    static Reader r = new Reader();
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        n = r.nextInt();
        m = r.nextInt();
        d = r.nextInt();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) {
                map[i][j] = r.nextInt();
                if(map[i][j]==1)
                    status[i][j]=true;
            }

        DFS(1, 0);
        System.out.println(ans);

    }

    static class pair {
        public int f, s;
        public pair(int f, int s) {
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
