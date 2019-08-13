package de.hhu.bsinfo.jdetector.lib.exception;

/**
 * An exception, which signalises an error during an ibverbs-operation.
 *
 * @author Fabian Ruhland, Fabian.Ruhland@hhu.de
 */
public class IbVerbsException extends IbPerfException {

    /**
     * Constructor.
     *
     * @param message Error message
     */
    IbVerbsException(String message) {
        super(message);
    }
}
