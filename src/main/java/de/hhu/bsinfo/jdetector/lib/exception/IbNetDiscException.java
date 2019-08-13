package de.hhu.bsinfo.jdetector.lib.exception;

/**
 * An exception, which signalises an error during an ibnetdisc-operation.
 *
 * @author Fabian Ruhland, Fabian.Ruhland@hhu.de
 */
public class IbNetDiscException extends IbPerfException {

    /**
     * Constructor.
     *
     * @param message Error message
     */
    IbNetDiscException(String message) {
        super(message);
    }
}