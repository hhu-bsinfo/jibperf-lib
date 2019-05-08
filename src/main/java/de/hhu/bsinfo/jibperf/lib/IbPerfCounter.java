package de.hhu.bsinfo.jibperf.lib;

import de.hhu.bsinfo.jibperf.lib.exception.IbFileException;
import de.hhu.bsinfo.jibperf.lib.exception.IbMadException;

public interface IbPerfCounter {

    void resetCounters() throws IbFileException, IbMadException;

    void refreshCounters() throws IbMadException;

    long getXmitDataBytes();

    long getRcvDataBytes();

    long getXmitPkts();

    long getRcvPkts();

    long getUnicastXmitPkts();

    long getUnicastRcvPkts();

    long getMulticastXmitPkts();

    long getMulticastRcvPkts();

    long getSymbolErrors();

    long getLinkDownedCounter();

    long getLinkRecoveryCounter();

    long getRcvErrors();

    long getRcvRemotePhysicalErrors();

    long getRcvSwitchRelayErrors();

    long getXmitDiscards();

    long getXmitConstraintErrors();

    long getRcvConstraintErrors();

    long getLocalLinkIntegrityErrors();

    long getExcessiveBufferOverrunErrors();

    long getVL15Dropped();

    long getXmitWait();
}
