package de.hhu.bsinfo.jibperf.app;

import de.hhu.bsinfo.jibperf.lib.IbFabric;

public class IbPerfTest {

    public static void main(String[] args) {
        boolean compatibility = false;

        if(args.length < 1) {
            System.out.println("Usage: ./IbPerfTest <mad/compat>");
            System.exit(1);
        }

        IbFabric fabric = new IbFabric(compatibility);

        System.out.println(fabric);

        fabric.close();
    }

}
