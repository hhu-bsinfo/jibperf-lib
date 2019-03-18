package de.hhu.bsinfo.jibperf.lib;

import de.hhu.bsinfo.jibperf.lib.exception.IbFileException;
import de.hhu.bsinfo.jibperf.lib.exception.IbMadException;
import de.hhu.bsinfo.jibperf.lib.exception.IbVerbsException;

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

    public IbFabric(boolean compatibility) throws IbFileException, IbMadException, IbVerbsException {
        init(compatibility);
    }

    private native void init(boolean compatibility) throws IbFileException, IbMadException, IbVerbsException;

    public native void refreshCounters();

    public native void resetCounters();

    public native int getNumNodes();

    public native void close();
}
