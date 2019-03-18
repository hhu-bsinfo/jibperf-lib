package de.hhu.bsinfo.jibperf.lib;

import java.io.IOException;

public class IbFabric {

    static {
        try {
            JniHelper.loadNativeLibraryFromJar("/libIbPerfLibJNI.so");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private long nativeHandle = 0;

    public IbFabric(boolean compatibility) {
        init(compatibility);
    }

    private native void init(boolean compatibility);

    public native void refreshCounters();

    public native void resetCounters();

    public native int getNumNodes();

    public native void close();
}
