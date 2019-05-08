package de.hhu.bsinfo.jibperf.app;

import de.hhu.bsinfo.jibperf.lib.IbDiagPerfCounter;
import de.hhu.bsinfo.jibperf.lib.NativeBuildConfig;
import de.hhu.bsinfo.jibperf.lib.exception.IbFileException;
import de.hhu.bsinfo.jibperf.lib.exception.IbPerfException;

public class IbDiagPerfTest {

    private static final String CLASS_NAME = IbDiagPerfTest.class.getSimpleName();

    private static boolean isRunning = true;

    public static void main(String[] args) {
        System.out.printf("Running %s!\nUsing IbPerfLib %s - git %s(%s)\nBuild date: %s\n" +
                        "Additional extended counters: %s\n\n", CLASS_NAME, NativeBuildConfig.getVersion(),
                NativeBuildConfig.getGitRevision(), NativeBuildConfig.getGitBranch(), NativeBuildConfig.getBuildDate(),
                NativeBuildConfig.areAdditionalExtendedCountersEnabled() ? "Enabled" : "Disabled");

        IbDiagPerfCounter[] counters = null;

        try {
            counters = IbDiagPerfCounter.getLocalPorts();
        } catch(IbFileException e) {
            e.printStackTrace();
            System.exit(1);
        }

        Runtime.getRuntime().addShutdownHook(new Thread(() -> isRunning = false));

        while(isRunning) {
            try {
                for(IbDiagPerfCounter counter : counters) {
                    counter.refreshCounters();
                    System.out.println(counter + "\n");
                }

                System.out.println();

                Thread.sleep(5000);
            } catch(IbPerfException exception) {
                System.out.printf("An exception occurred: %s", exception.getMessage());
            } catch(InterruptedException ignored) {}
        }
    }
}
