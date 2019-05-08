package de.hhu.bsinfo.jibperf.app;

import de.hhu.bsinfo.jibperf.lib.IbFabric;
import de.hhu.bsinfo.jibperf.lib.NativeBuildConfig;
import de.hhu.bsinfo.jibperf.lib.exception.*;

public class IbPerfTest {

    private static final String CLASS_NAME = IbPerfTest.class.getSimpleName();

    private static boolean isRunning = true;

    public static void main(String[] args) {
        System.out.printf("Running %s!\nUsing IbPerfLib %s - git %s(%s)\nBuild date: %s\n" +
                        "Additional extended counters: %s\n\n", CLASS_NAME, NativeBuildConfig.getVersion(),
                NativeBuildConfig.getGitRevision(), NativeBuildConfig.getGitBranch(), NativeBuildConfig.getBuildDate(),
                NativeBuildConfig.areAdditionalExtendedCountersEnabled() ? "Enabled" : "Disabled");

        if(args.length < 1) {
            System.out.println("Usage: ./IbPerfTest <mad/compat>");
            System.exit(1);
        }

        boolean compatability = false;

        if(args[0].equals("compat")){
            compatability = true;
        } else if(!args[0].equals("mad")){
            System.out.println("Usage: ./IbPerfTest <mad/compat>");
            System.exit(1);
        }

        IbFabric fabric = null;

        try {
            fabric = new IbFabric(compatability);
        } catch (IbFileException | IbMadException | IbVerbsException | IbNetDiscException e) {
            e.printStackTrace();
            System.exit(1);
        }

        Runtime.getRuntime().addShutdownHook(new Thread(() -> isRunning = false));

        while(isRunning) {
            try {
                fabric.refreshCounters();
                System.out.println(fabric + "\n");

                Thread.sleep(5000);
            } catch(IbPerfException exception) {
                System.out.printf("An exception occurred: %s", exception.getMessage());
            } catch(InterruptedException ignored) {}
        }

        fabric.close();
    }
}
