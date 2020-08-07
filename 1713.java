import java.io.*;
import java.util.*;

public class Main {
    static Tuple[] frame = new Tuple[1000];
    static int n, m, num, idx = 0, filled = 0;

    static Reader r = new Reader();
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        n = r.nextInt();
        m = r.nextInt();
        for(int i = 0; i < m; ++i) {
            num = r.nextInt();
            boolean e = false;
            for(int j = 0; j < idx; ++j)
                if(frame[j].v == num) {
                    ++frame[j].c;
                    frame[j].t = i;
                    e = true;
                    break;
                }
            if(!e) {
                frame[idx] = new Tuple(num, i, 1);
                filled = idx + 1;
                idx = idx + 1 < n ? idx + 1 : idx;
            }
            Arrays.sort(frame, 0, filled, comparator);
        }
        Arrays.sort(frame, 0, filled, getAns);
        for(int i = 0;i < filled; ++i)
            System.out.print(frame[i].v + " ");
    }

    static Comparator<Tuple> comparator = new Comparator<Tuple>() {
        @Override
        public int compare(Tuple o1, Tuple o2) {
            return o1.c == o2.c ? o2.t - o1.t : o2.c - o1.c;
        }
    };

    static Comparator<Tuple> getAns = new Comparator<Tuple>() {
        @Override
        public int compare(Tuple o1, Tuple o2) {
            return o1.v - o2.v;
        }
    };

    static class Tuple {
        public int v, t, c;
        public Tuple(int v, int t, int c) {
            this.v = v;
            this.t = t;
            this.c = c;
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
            if(c == '-') {ㅎ
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
