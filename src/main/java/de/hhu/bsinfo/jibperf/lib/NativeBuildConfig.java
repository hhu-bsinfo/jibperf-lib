package de.hhu.bsinfo.jibperf.lib;

import java.io.IOException;

public class NativeBuildConfig {

    static {
        try {
            JniUtil.loadNativeLibraryFromJar("/libIbPerfLibJNI.so");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static native String getVersion();

    public static native String getGitRevision();

    public static native String getGitBranch();

    public static native String getBuildDate();

    public static native boolean areAdditionalExtendedCountersEnabled();

}
