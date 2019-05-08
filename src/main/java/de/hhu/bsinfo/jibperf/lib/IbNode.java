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

package de.hhu.bsinfo.jibperf.lib;

import de.hhu.bsinfo.jibperf.lib.exception.IbFileException;
import de.hhu.bsinfo.jibperf.lib.exception.IbMadException;
import de.hhu.bsinfo.jibperf.lib.exception.IbVerbsException;

public class IbNode implements IbPerfCounter {

    static {
        JniUtil.loadIbPerfLibJNI();
    }

    private long m_nativeHandle;

    private long m_guid;

    private String m_description;

    private IbPort[] m_ports = null;

    private IbNode(long nativeHandle, long guid, String description) {
        this.m_nativeHandle = nativeHandle;
        this.m_guid = guid;
        this.m_description = description;
    }

    public static native IbNode[] getLocalNodes() throws IbVerbsException;

    public String getDescription() {
        return m_description;
    }

    public long getGuid() {
        return m_guid;
    }

    public short getNumPorts() {
        return 0;
    }

    public IbPort[] getPorts() {
        return m_ports;
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
        StringBuilder builder = new StringBuilder("Name: ")
                .append(m_description)
                .append(", ")
                .append("GUID: 0x")
                .append(String.format("%016x", m_guid))
                .append("\n");

        for(IbPort port : m_ports) {
            builder.append("    ").append(port).append("\n");
        }

        builder.setLength(builder.length() - 1);

        return builder.toString();
    }
}
