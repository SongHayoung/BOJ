import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int[][] map = new int[1000][1000];
    static int[] dy = {-1,0,1,0};
    static int y, x;
    static int[] dx = {0,1,0,-1};
    public static void main(String[] args) throws IOException {
        Reader r = new Reader();
        Queue<tomato> q = new LinkedList<>();
        x = r.nextInt(); y = r.nextInt();
        int tomatoes = y * x, days = 0;
        for(int i = 0; i < y; ++i)
            for(int j = 0; j < x; ++j) {
                map[i][j] = r.nextInt();
                switch (map[i][j]) {
                    case 1: q.offer(new tomato(i, j));
                    case -1: --tomatoes;
                    default: break;
                }
            }
        while(!q.isEmpty() && tomatoes != 0) {
            int size = q.size();
            for(int e = 0; e < size; ++e) {
                tomato t = q.remove();
                for (int i = 0; i < 4; ++i) {
                    int nx = t.x + dx[i];
                    int ny = t.y + dy[i];
                    if (0 <= nx && nx < x && 0 <= ny && ny < y && map[ny][nx] == 0) {
                        map[ny][nx] = 1;
                        q.offer(new tomato(ny, nx));
                        --tomatoes;
                    }
                }
            }
            ++days;
        }
        System.out.println(tomatoes == 0 ? days : -1);
    }
    static class tomato {
        public int y, x;
        public tomato(int y, int x) {
            this.y = y;
            this.x = x;
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
            int ret = 0;
            byte c = read();
            while (c <= 32)
                c = read();
            boolean neg = (c == 45);
            if (neg)
                c = read();
            do {
                ret = (ret<<3) + (ret<<1)  + (c & 0b1111);
            } while ((c = read()) >= 48 && c <= 57);

            if (neg)
                return -ret;
            return ret;
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
