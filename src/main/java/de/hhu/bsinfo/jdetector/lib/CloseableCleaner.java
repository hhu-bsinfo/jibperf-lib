package de.hhu.bsinfo.jdetector.lib;

class CloseableCleaner implements Runnable {

    private final AutoCloseable closeable;

    CloseableCleaner(AutoCloseable closeable) {
        this.closeable = closeable;
    }

    @Override
    public void run() {
        try {
            closeable.close();
        } catch (Exception ignored) {}
    }
}
