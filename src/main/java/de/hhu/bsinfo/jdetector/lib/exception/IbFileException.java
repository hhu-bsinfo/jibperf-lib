package de.hhu.bsinfo.jdetector.lib.exception;

/**
 * An exception, which signalises an error during a file-operation.
 *
 * @author Fabian Ruhland, Fabian.Ruhland@hhu.de
 */
public class IbFileException extends IbPerfException {

    /**
     * Constructor.
     *
     * @param message Error message
     */
    IbFileException(String message) {
        super(message);
    }
}
