package de.hhu.bsinfo.jibperf.lib;

public class NativeBuildConfig {

    static {
        JniUtil.loadIbPerfLibJNI();
    }

    public static native String getVersion();

    public static native String getGitRevision();

    public static native String getGitBranch();

    public static native String getBuildDate();

    public static native boolean areAdditionalExtendedCountersEnabled();

}
