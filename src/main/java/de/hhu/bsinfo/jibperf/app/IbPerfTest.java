package de.hhu.bsinfo.jibperf.app;

import de.hhu.bsinfo.jibperf.lib.IbFabric;
import de.hhu.bsinfo.jibperf.lib.NativeBuildConfig;
import de.hhu.bsinfo.jibperf.lib.exception.IbPerfException;

public class IbPerfTest {

    private static boolean isRunning = true;

    public static void main(String[] args) {
        System.out.printf("IbPerfLib %s - git %s(%s)\nBuild date: %s\nAdditional extended counters: %s\n\n",
                NativeBuildConfig.getVersion(), NativeBuildConfig.getGitRevision(), NativeBuildConfig.getGitBranch(),
                NativeBuildConfig.getBuildDate(), NativeBuildConfig.areAdditionalExtendedCountersEnabled() ?
                "Enabled" : "Disabled");

        if(args.length < 1) {
            System.out.println("Usage: ./IbPerfTest <mad/compat>");
            System.exit(1);
        }

        IbFabric fabric = null;

        if(args[0].equals("mad")) {
            fabric = new IbFabric(false);
        } else if(args[0].equals("compat")){
            fabric = new IbFabric(true);
        } else {
            System.out.println("Usage: ./IbPerfTest <mad/compat>");
            System.exit(1);
        }

        Runtime.getRuntime().addShutdownHook(new Thread(() -> isRunning = false));

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
