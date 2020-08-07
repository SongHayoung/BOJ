import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static Reader r = new Reader();
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static boolean[] v = new boolean[100001];
    public static void main(String[] args) throws IOException {
        int val = r.nextInt(), k = r.nextInt(), ans = 0;
        boolean f = val != k;
        if(val > k) ans = val - k;
        else {
            Queue<Integer> q = new LinkedList<>();
            q.add(val);
            v[val] = true;
            while(f) {
                ++ans;
                int size = q.size();
                for(int i = 0; i < size; ++i) {
                    val = q.remove();
                    if(val + 1 == k || val == k + 1 || (val<<1) == k) {
                        f = false;
                        break;
                    }
                    if(val >= 1 && !v[val-1]) {
                        q.add(val - 1);
                        v[val-1] = true;
                    }
                    if(val <= 99999 && !v[val+1]) {
                        q.add(val + 1);
                        v[val+1] = true;
                    }
                    if(val <= 50000 && !v[val<<1]) {
                        q.add(val<<1);
                        v[val<<1] = true;
                    }
                }
            }
        }
        bw.write(ans+"");
        bw.flush();
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
