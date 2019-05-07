package de.hhu.bsinfo.jibperf.app;

import de.hhu.bsinfo.jibperf.lib.IbNode;
import de.hhu.bsinfo.jibperf.lib.NativeBuildConfig;
import de.hhu.bsinfo.jibperf.lib.exception.IbPerfException;
import de.hhu.bsinfo.jibperf.lib.exception.IbVerbsException;

public class IbNodeTest {

    private static boolean isRunning = true;

    public static void main(String[] args) {
        System.out.printf("IbPerfLib %s - git %s(%s)\nBuild date: %s\nAdditional extended counters: %s\n\n",
                NativeBuildConfig.getVersion(), NativeBuildConfig.getGitRevision(), NativeBuildConfig.getGitBranch(),
                NativeBuildConfig.getBuildDate(), NativeBuildConfig.areAdditionalExtendedCountersEnabled() ?
                        "Enabled" : "Disabled");

        IbNode[] nodes = null;

        try {
            nodes = IbNode.getLocalNodes();
        } catch(IbVerbsException e) {
            e.printStackTrace();
            System.exit(1);
        }

        Runtime.getRuntime().addShutdownHook(new Thread(() -> isRunning = false));

        while(isRunning) {
            try {
                for(IbNode node : nodes) {
                    node.refreshCounters();
                    System.out.println(node + "\n");
                }

                Thread.sleep(5000);
            } catch(IbPerfException exception) {
                System.out.printf("An exception occurred: %s", exception.getMessage());
            } catch(InterruptedException ignored) {}
        }
    }
}
