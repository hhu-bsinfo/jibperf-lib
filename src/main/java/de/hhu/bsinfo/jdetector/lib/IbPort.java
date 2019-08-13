/*
 * Copyright (C) 2019 Heinrich-Heine-Universitaet Duesseldorf, Institute of Computer Science,
 * Department Operating Systems
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

package de.hhu.bsinfo.jdetector.lib;

import de.hhu.bsinfo.jdetector.lib.exception.IbFileException;
import de.hhu.bsinfo.jdetector.lib.exception.IbMadException;

/**
 * Reads performance counters from a single port of an InfiniBand device.
 *
 * @author Fabian Ruhland, Fabian.Ruhland@hhu.de
 */
public class IbPort implements IbPerfCounter {

    /**
     * Pointer to the corresponding native object.
     */
    private long m_nativeHandle;

    /**
     * The lid of the port, that shall be monitored.
     */
    private short m_lid;

    /**
     * The number, that the port has on its device.
     */
    private short m_portNum;

    /**
     * The port's active link width.
     */
    private short m_linkWidth;

    /**
     * Constructor.
     *
     * @param nativeHandle Pointer to the corresponding native
     * @param lid The port's local id
     * @param portNum The number, that the port has on its device
     * @param linkWidth The port's link width
     */
    private IbPort(long nativeHandle, short lid, short portNum, short linkWidth) {
        this.m_nativeHandle = nativeHandle;
        this.m_lid = lid;
        this.m_portNum = portNum;
        this.m_linkWidth = linkWidth;
    }

    /**
     * Get the port's local id.
     */
    public short getLid() {
        return m_lid;
    }

    /**
     * Get the number, that the port has on its device.
     */
    public short getNum() {
        return m_portNum;
    }

    /**
     * Get the port's link width.
     */
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
