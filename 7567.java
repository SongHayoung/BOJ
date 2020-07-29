import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String plate = br.readLine();
        int ans = 10;
        for(int i = 1; i < plate.length(); ++i)
            ans += plate.charAt(i - 1) == plate.charAt(i) ? 5 : 10;
        bw.write(Integer.toString(ans));
        bw.flush();
    }
}
