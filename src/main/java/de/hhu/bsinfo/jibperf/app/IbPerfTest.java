package de.hhu.bsinfo.jibperf.app;

import de.hhu.bsinfo.jibperf.lib.IbFabric;

public class IbPerfTest {

    public static void main(String[] args) {
        boolean compatibility = false;

        if(args.length > 0) {
            compatibility = Boolean.parseBoolean(args[0]);
        }

        IbFabric fabric = new IbFabric(compatibility);

        int numNodes = fabric.getNumNodes();

        System.out.printf("Found %d %s in the fabric!\n", numNodes, numNodes == 1 ? "node" : "nodes");

        fabric.close();
    }

}
