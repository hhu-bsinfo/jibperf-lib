package de.hhu.bsinfo.jibperf.lib;

import de.hhu.bsinfo.jibperf.lib.exception.IbFileException;
import de.hhu.bsinfo.jibperf.lib.exception.IbMadException;

public class IbPort implements IbPerfCounter {

    static {
        JniUtil.loadIbPerfLibJNI();
    }

    private long m_nativeHandle;

    private short m_lid;

    private short m_portNum;

    private short m_linkWidth;

    private IbPort(long nativeHandle, short lid, short portNum, short linkWidth) {
        this.m_nativeHandle = nativeHandle;
        this.m_lid = lid;
        this.m_portNum = portNum;
        this.m_linkWidth = linkWidth;
    }

    public short getLid() {
        return m_lid;
    }

    public short getNum() {
        return m_portNum;
    }

    public short getLinkWidth() {
        return m_linkWidth;
    }

    @Override
    public native void resetCounters() throws IbFileException, IbMadException;

    @Override
    public native void refreshCounters() throws IbMadException;

    @Override
    public native long getXmitDataBytes();

    @Override
    public native long getRcvDataBytes();

    @Override
    public native long getXmitPkts();

    @Override
    public native long getRcvPkts();

    @Override
    public native long getUnicastXmitPkts();

    @Override
    public native long getUnicastRcvPkts();

    @Override
    public native long getMulticastXmitPkts();

    @Override
    public native long getMulticastRcvPkts();

    @Override
    public native long getSymbolErrors();

    @Override
    public native long getLinkDownedCounter();

    @Override
    public native long getLinkRecoveryCounter();

    @Override
    public native long getRcvErrors();

    @Override
    public native long getRcvRemotePhysicalErrors();

    @Override
    public native long getRcvSwitchRelayErrors();

    @Override
    public native long getXmitDiscards();

    @Override
    public native long getXmitConstraintErrors();

    @Override
    public native long getRcvConstraintErrors();

    @Override
    public native long getLocalLinkIntegrityErrors();

    @Override
    public native long getExcessiveBufferOverrunErrors();

    @Override
    public native long getVL15Dropped();

    @Override
    public native long getXmitWait();

    @Override
    public String toString() {
        return "Port Number: " +
                m_portNum +
                String.format(", LID: 0x%x", m_lid) +
                ", Link width: " +
                m_linkWidth +
                "x, XmitBytes: " +
                getXmitDataBytes() +
                " Bytes, RcvBytes: " +
                getRcvDataBytes() +
                " Bytes";
    }
}
