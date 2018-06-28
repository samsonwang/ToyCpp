There are some tests ripped out from git://repo.or.cz/ltp-debian.git/testcases/open_posix_testsuite/conformance/interfaces and made self-containing. They demonstrate and can be used to test the POSIX AIO interface for asynchronous I/O and formerly file IO.

Build with a c compiler (for instance `clang` or `cc`):

    cc -o aio_read-test aio_read-test.c && ./aio_read-test

Note: Contrary to popular belief, it has been tested and confirmed to actually be asynchronous on Darwin 10.6.0 (xnu 1504.9.26~3).