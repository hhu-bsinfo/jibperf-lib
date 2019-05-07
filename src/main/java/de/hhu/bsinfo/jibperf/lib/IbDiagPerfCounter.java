package de.hhu.bsinfo.jibperf.lib;

import de.hhu.bsinfo.jibperf.lib.exception.IbFileException;

public class IbDiagPerfCounter {

    private long m_nativeHandle;

    private short m_portNumber;

    private String m_deviceName;

    private IbDiagPerfCounter(long nativeHandle, short portNumber, String deviceName) {
        this.m_nativeHandle = nativeHandle;
        this.m_portNumber = portNumber;
        this.m_deviceName = deviceName;
    }

    public static native IbDiagPerfCounter[] getLocalPorts() throws IbFileException;

    public short getPortNumber() {
        return m_portNumber;
    }

    public String getDeviceName() {
        return m_deviceName;
    }

    public native void resetCounters();

    public native void refreshCounters() throws IbFileException;

    public native long getLifespan();

    public native long getRqLocalLengthErrors();

    public native long getRqLocalProtectionErrors();

    public native long getRqLocalQpProtectionErrors();

    public native long getRqOutOfSequenceErrors();

    public native long getRqRemoteAccessErrors();

    public native long getRqRemoteInvalidRequestErrors();

    public native long getRqRnrNakNum();

    public native long getRqCompletionQueueEntryErrors();

    public native long getSqBadResponseErrors();

    public native long getSqLocalLengthErrors();

    public native long getSqLocalProtectionErrors();

    public native long getSqLocalQpProtectionErrors();

    public native long getSqMemoryWindowBindErrors();

    public native long getSqOutOfSequenceErrors();

    public native long getSqRemoteAccessErrors();

    public native long getSqRemoteInvalidRequestErrors();

    public native long getSqRnrNakNum();

    public native long getSqRemoteOperationErrors();

    public native long getSqRnrNakRetriesExceededErrors();

    public native long getSqTransportRetriesExceededErrors();

    public native long getSqCompletionQueueEntryErrors();

    @Override
    public String toString() {
        return "Device: " + m_deviceName +
                (m_portNumber > 0 ? ", Port: "  + m_portNumber : "") + "\n" +
                "    Lifespan: " + getLifespan() + "\n" +
                "    RqLocalLengthErrors: " + getRqLocalLengthErrors() + "\n" +
                "    RqLocalProtectionErrors: " + getRqLocalProtectionErrors() + "\n" +
                "    RqLocalQpProtectionErrors: " + getRqLocalQpProtectionErrors() + "\n" +
                "    RqOutOfSequenceErrors: " + getRqOutOfSequenceErrors()+ "\n" +
                "    RqRemoteAccessErrors: " + getRqRemoteAccessErrors() + "\n" +
                "    RqRemoteInvalidRequestErrors: " + getRqRemoteInvalidRequestErrors() + "\n" +
                "    RqRnrNakNum: " + getRqRnrNakNum() + "\n" +
                "    RqCompletionQueueEntryErrors: " + getRqCompletionQueueEntryErrors() + "\n" +
                "    SqBadResponseErrors: " + getSqBadResponseErrors() + "\n" +
                "    SqLocalLengthErrors: " + getSqLocalLengthErrors() + "\n" +
                "    SqLocalProtectionErrors: " + getSqLocalProtectionErrors() + "\n" +
                "    SqLocalQpProtectionErrors: " + getSqLocalQpProtectionErrors() + "\n" +
                "    SqMemoryWindowBindErrors: " + getSqMemoryWindowBindErrors() + "\n" +
                "    SqOutOfSequenceErrors: " + getSqOutOfSequenceErrors() + "\n" +
                "    SqRemoteAccessErrors: " + getSqRemoteAccessErrors() + "\n" +
                "    SqRemoteInvalidRequestErrors: " + getSqRemoteInvalidRequestErrors() + "\n" +
                "    SqRnrNakNum: " + getSqRnrNakNum() + "\n" +
                "    SqRemoteOperationErrors: " + getSqRemoteOperationErrors() + "\n" +
                "    SqRnrNakRetriesExceededErrors: " + getSqRnrNakRetriesExceededErrors() + "\n" +
                "    SqTransportRetriesExceededErrors: " + getSqTransportRetriesExceededErrors() + "\n" +
                "    SqCompletionQueueEntryErrors: " + getSqCompletionQueueEntryErrors();
    }
}
