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
 * Represents a node in an InfiniBand-fabric (e.g. a Switch or an HCA).
 * The performance counters are aggregated over all of the node's ports.
 *
 * @author Fabian Ruhland, Fabian.Ruhland@hhu.de
 */
public class IbNode implements IbPerfCounter {

    /**
     * Pointer to the corresponding native object.
     */
    private long m_nativeHandle;

    /**
     * The node's global unique id.
     */
    private long m_guid;

    /**
     * A short string describing the node (e.g. hostname, manufacturer, ...)
     */
    private String m_description;

    /**
     * All of the node's ports.
     */
    private IbPort[] m_ports = null;

    /**
     * Constructor.
     *
     * @param nativeHandle Pointer to the corresponding native
     * @param guid The node's global unique id
     * @param description The node's description
     */
    private IbNode(long nativeHandle, long guid, String description) {
        this.m_nativeHandle = nativeHandle;
        this.m_guid = guid;
        this.m_description = description;
    }

    /**
     * Get the node's description;
     */
    public String getDescription() {
        return m_description;
    }

    /**
     * Get the node's global unique id;
     */
    public long getGuid() {
        return m_guid;
    }

    /**
     * Get the amount of ports the node has.
     */
    public short getNumPorts() {
        return 0;
    }

    /**
     * Get all of the node's ports in an array.
     */
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
