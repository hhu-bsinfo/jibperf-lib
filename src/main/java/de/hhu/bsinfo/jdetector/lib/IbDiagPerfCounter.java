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

/**
 * Reads the diagnostic counters of a local device from
 * "/sys/class/infiniband/<device name>/ports/<port number>/hw_counters/".
 *
 * @author Fabian Ruhland, Fabian.Ruhland@hhu.de
 */
public class IbDiagPerfCounter implements AutoCloseable {

    static {
        System.loadLibrary("detectorJNI");
    }

    /**
     * Pointer to the corresponding native object.
     */
    private long m_nativeHandle;

    /**
     * The number of the port, whose diagnostic counters shall be monitored
     */
    private short m_portNumber;

    /**
     * The device's name.
     */
    private String m_deviceName;

    /**
     * Constructor.
     *
     * CAUTION: This class allocates native resources, which need to be cleared by calling
     *          {@link #close()}, once an instance is not needed anymore.
     *
     * @param portNumber The port, whose diagnostic counters shall be monitored (Set to 0 to monitor the whole device)
     * @param deviceName The name of the device, whose diagnostic counters shall be monitored
     */
    private IbDiagPerfCounter(long nativeHandle, short portNumber, String deviceName) {
        this.m_nativeHandle = nativeHandle;
        this.m_portNumber = portNumber;
        this.m_deviceName = deviceName;
    }

    /**
     * Create an instance of IbDiagPerfCounter for every port on every InfiniBand device of the
     * local machine.
     *
     * CAUTION: This class allocates native resources, which need to be cleared by calling
     *          {@link #close()}, once an instance is not needed anymore.
     */
    public static native IbDiagPerfCounter[] getLocalPorts() throws IbFileException;

    /**
     * Get the number of the port, that this counter is monitoring.
     * A value of 0 means, that the whole device is being monitored.
     */
    public short getPortNumber() {
        return m_portNumber;
    }

    /**
     * Get the name of the device, that this counter is monitoring.
     */
    public String getDeviceName() {
        return m_deviceName;
    }

    /**
     * Reset all diagnostic counters.
     */
    public native void resetCounters() throws IbFileException;

    /**
     * Query all diagnostic counters.
     * The resulting values will be saved in the counter variables.
     */
    public native void refreshCounters() throws IbFileException;

    /**
     * Get the lifespan counter.
     */
    public native long getLifespan();

    /**
     * Get the counter for local length errors as responder.
     */
    public native long getRqLocalLengthErrors();

    /**
     * Get the counter for local protection errors as responder.
     */
    public native long getRqLocalProtectionErrors();

    /**
     * Get the counter for local queue pair protection errors as responder.
     */
    public native long getRqLocalQpProtectionErrors();

    /**
     * Get the counter for out of sequence errors as responder.
     */
    public native long getRqOutOfSequenceErrors();

    /**
     * Get the counter for remote access errors as responder.
     */
    public native long getRqRemoteAccessErrors();

    /**
     * Get the counter for remote invalid request errors as responder.
     */
    public native long getRqRemoteInvalidRequestErrors();

    /**
     * Get the counter for RNR NAKs as responder.
     */
    public native long getRqRnrNakNum();

    /**
     * Get the counter for completion queue entry errors as responder.
     */
    public native long getRqCompletionQueueEntryErrors();

    /**
     * Get the counter for bad response errors as requester.
     */
    public native long getSqBadResponseErrors();

    /**
     * Get the counter for local length errors as requester.
     */
    public native long getSqLocalLengthErrors();

    /**
     * Get the counter for local protection errors as requester.
     */
    public native long getSqLocalProtectionErrors();

    /**
     * Get the counter for local queue pair protections errors as requester.
     */
    public native long getSqLocalQpProtectionErrors();

    /**
     * Get the counter for memory window bind errors as requester.
     */
    public native long getSqMemoryWindowBindErrors();

    /**
     * Get the counter for out of sequence errors as requester.
     */
    public native long getSqOutOfSequenceErrors();

    /**
     * Get the counter for remote access errors as requester.
     */
    public native long getSqRemoteAccessErrors();

    /**
     * Get the counter for remote invalid request errors as requester.
     */
    public native long getSqRemoteInvalidRequestErrors();

    /**
     * Get the counter for RNR NAKs as requester.
     */
    public native long getSqRnrNakNum();

    /**
     * Get the counter for remote operation errors as requester.
     */
    public native long getSqRemoteOperationErrors();

    /**
     * Get the counter for RNR NAK retries exceeded errors as requester.
     */
    public native long getSqRnrNakRetriesExceededErrors();

    /**
     * Get the counter for transport retries exceeeded errors as requester.
     */
    public native long getSqTransportRetriesExceededErrors();

    /**
     * Get the counter for completion queue entry errors as requester.
     */
    public native long getSqCompletionQueueEntryErrors();

    @Override
    public native void close();

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
