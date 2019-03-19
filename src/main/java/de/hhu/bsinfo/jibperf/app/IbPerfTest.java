package de.hhu.bsinfo.jibperf.app;

import de.hhu.bsinfo.jibperf.lib.IbFabric;
import de.hhu.bsinfo.jibperf.lib.exception.IbPerfException;

public class IbPerfTest {

    private static boolean isRunning = true;

    public static void main(String[] args) {
        boolean compatibility = false;

        if(args.length < 1) {
            System.out.println("Usage: ./IbPerfTest <mad/compat>");
            System.exit(1);
        }

        Runtime.getRuntime().addShutdownHook(new Thread(() -> isRunning = false));

        IbFabric fabric = new IbFabric(compatibility);

        while(isRunning) {
            try {
                fabric.refreshCounters();
                System.out.println(fabric);

                Thread.sleep(5000);
            } catch(IbPerfException exception) {
                System.out.printf("An exception occurred: %s", exception.getMessage());
            } catch(InterruptedException ignored) {}
        }

        fabric.close();
    }

}
