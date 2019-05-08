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

public class IbDiagPerfCounter {

    static {
        JniUtil.loadIbPerfLibJNI();
    }

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
