import com.beust.jcommander.Parameter;
import com.github.chrishantha.sample.base.SampleApplication;

public class LatenciesApplication implements SampleApplication {

    @Parameter(names = "--count", description = "Print Count")
    private int count = 50;

    private class EvenThread extends Thread {

        public EvenThread() {
            super("Even-Thread");
        }

        @Override
        public void run() {
            for (int i = 0; i < count; i++) {
                if (isEven(i)) {
                    printNumber(i);
                }
            }
        }
    }

    private class OddThread extends Thread {

        public OddThread() {
            super("Odd-Thread");
        }

        @Override
        public void run() {
            for (int i = 0; i < count; i++) {
                if (!isEven(i)) {
                    printNumber(i);
                }
            }
        }
    }


    private void printNumber(int i) {
        System.out.format("Thread: %s, Number: %d%n", Thread.currentThread().getName(), i);
    }

    private synchronized boolean isEven(int i) {
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return i % 2 == 0;
    }

    @Override
    public void start() {
        new EvenThread().start();
        new OddThread().start();
    }

    @Override
    public String toString() {
        return "LatenciesApplication{" +
                "count=" + count +
                '}';
    }
}
