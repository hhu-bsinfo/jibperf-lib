package de.hhu.bsinfo.jibperf.app;

import de.hhu.bsinfo.jibperf.lib.IbFabric;

public class IbPerfTest {

    public static void main(String[] args) {
        IbFabric fabric = new IbFabric(false);

        System.out.println(fabric.getNumNodes());
    }

}
