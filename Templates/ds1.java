import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.regex.Pattern;

public class BinaryIndexTree {
  private static final Pattern SPACE = Pattern.compile(" ");

  private final long[] tree;
  private final long[] data;
  //BIT with data
  public BinaryIndexTree(long[] input) {
    int len = (Integer.highestOneBit(input.length) << 1) + 1;
    tree = new long[len];
    data = new long[len];

    for (int i = 0; i < input.length; i++) {
      set(i + 1, input[i]);
    }
  }

  public void set(int index, long value) {
    long diff = value - data[index];

    incr(index, diff);
  }

  public void incr(int index, long value) {
    int i = index;
    while (i <= (tree.length - 1)) {
      tree[i] += value;
      i += (i & -i); // can also use Long.lowestOneBit(), they're the same thing
    }

    data[index] += value;
  }

  public long sumTo(int index) {
    long result = 0;

    int i = index;
    while (i != 0) {
      result += tree[index];
      i -= (i & -i); // can also use Long.lowestOneBit(), they're the same thing
    }
    return result;
  }

  public static void main(String[] args) throws Exception{
    try (BufferedReader readIn = new BufferedReader(new InputStreamReader(System.in))) {
      // var init
      final int count;
      final BinaryIndexTree sumTree;
      final BinaryIndexTree freqTree;
      {
        //init count
        String line = readIn.readLine();
        count = Integer.parseInt(line.substring(line.indexOf(' ') + 1));
        //init sum tree
        long[] input = Arrays.stream(SPACE.split(readIn.readLine())).mapToLong(Long::parseLong).toArray();
        sumTree = new BinaryIndexTree(input);
        //init freq tree
        long[] freq = new long[100000];
        for (long l: input) {
          freq[(int) (l - 1)]++;
        }
        freqTree = new BinaryIndexTree(freq);
      }

      for (int i = 0; i < count; i++) {
        String[] tokens = SPACE.split(readIn.readLine());

        switch (tokens[0].charAt(0)) {
          case 'C' : 
            int index = Integer.parseInt(tokens[1]);
            long value = Long.parseLong(tokens[2]);
            long oldValue = sumTree.data[index];

            sumTree.set(index, value);

            freqTree.incr((int) value, 1);
            freqTree.incr((int) oldValue, -1);
          break;
          case 'S' : 
            int left = Integer.parseInt(tokens[1]);
            int right = Integer.parseInt(tokens[2]);

            System.out.println(sumTree.sumTo(right) - sumTree.sumTo(left - 1));
          break;
          case 'Q' :
            int index2 = Integer.parseInt(tokens[1]);

            System.out.println(freqTree.sumTo(index2));
          break;
        }
      }
    }
  }
}