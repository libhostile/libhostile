Using libhostile
================

libhostile adds a very thin layer over every call that it breaks. By default it will not break any calls, it needs to be told what calls you wish to be hostile to. There are two ways of doing this:

1. Using the :doc:`../shell/index` tool
2. Manually as below

Manual hostility
----------------

You can manually invoke libhostile using ``LD_PRELOAD`` as follows:

.. code-block:: bash

   $ LD_PRELOAD=/usr/local/lib/libhostile.so application

Where ``application`` is the application/service you wish to be hostile to.

To become hostile to libc functions you will need to set environment variables. Multiple environment variables can be used in the same run.

Each environment variable should be set to an integer representation of the frequency of failures. For example:

.. code-block:: bash

   $ export HOSTILE_MALLOC=500

The above will tell libhostile to return an error for roughly 1/500 ``malloc()`` calls (there is a random element and a small grace period).

.. envvar:: HOSTILE_ACCEPT

   Become hostile to ``accept()`` calls

.. envvar:: HOSTILE_ACCEPT4

   Become hostile to ``accept4()`` calls

.. envvar:: HOSTILE_BIND

   Become hostile to ``bind()`` calls. Injects ``EADDRINUSE``, ``EACCES``, or ``EADDRNOTAVAIL``.

.. envvar:: HOSTILE_CALLOC

   Become hostile to ``calloc()`` calls. Returns ``NULL`` with ``ENOMEM``.

.. envvar:: HOSTILE_CLOSE

   Become hostile to ``close()`` calls

.. envvar:: HOSTILE_CONNECT

   Become hostile to ``connect()`` calls

.. envvar:: HOSTILE_FCLOSE

   Become hostile to ``fclose()`` calls. Calls the real ``fclose()`` first, then returns ``EOF`` with ``EIO``.

.. envvar:: HOSTILE_FCNTL

   Become hostile to ``fcntl()`` calls. Only affects ``F_GETFL`` and ``F_SETFL`` operations. Injects ``EBADF`` or ``EINVAL``.

.. envvar:: HOSTILE_FOPEN

   Become hostile to ``fopen()`` calls. Injects ``EMFILE``, ``ENOENT``, or ``EACCES``.

.. envvar:: HOSTILE_FREAD

   Become hostile to ``fread()`` calls. Returns 0 or a short read (half the requested count).

.. envvar:: HOSTILE_GETADDRINFO

   Become hostile to ``getaddrinfo()`` calls

.. envvar:: HOSTILE_GETHOSTBYNAME

   Become hostile to ``gethostbyname()`` calls. Returns ``NULL`` with ``HOST_NOT_FOUND`` or ``TRY_AGAIN`` via ``h_errno``.

.. envvar:: HOSTILE_GETRANDOM

   Become hostile to ``getrandom()`` calls (Linux only). Injects ``ENOSYS``, ``EINTR``, ``EAGAIN``, or returns a short read.

.. envvar:: HOSTILE_GETSOCKOPT

   Become hostile to ``getsockopt()`` calls. Injects ``EBADF`` or ``ENOPROTOOPT``.

.. envvar:: HOSTILE_LISTEN

   Become hostile to ``listen()`` calls. Injects ``EADDRINUSE`` or ``EBADF``.

.. envvar:: HOSTILE_MALLOC

   Become hostile to ``malloc()`` calls

.. envvar:: HOSTILE_OPEN

   Become hostile to ``open()`` calls. Injects ``EMFILE``, ``ENOENT``, or ``EACCES``.

.. envvar:: HOSTILE_PIPE

   Become hostile to ``pipe()`` calls

.. envvar:: HOSTILE_PIPE2

   Become hostile to ``pipe2()`` calls

.. envvar:: HOSTILE_POLL

   Become hostile to ``poll()`` calls

.. envvar:: HOSTILE_READ

   Become hostile to ``read()`` calls. For sockets injects ``ECONNRESET``, ``EOF``, or ``EINTR``. For files/devices injects ``EIO`` or a short read.

.. envvar:: HOSTILE_REALLOC

   Become hostile to ``realloc()`` calls

.. envvar:: HOSTILE_RECV

   Become hostile to ``recv()`` calls

.. envvar:: HOSTILE_RECVFROM

   Become hostile to ``recvfrom()`` calls. Injects ``ECONNREFUSED``, ``EOF``, ``EINTR``, ``EAGAIN``, or ``ENOMEM``.

.. envvar:: HOSTILE_SELECT

   Become hostile to ``select()`` calls. Injects timeout (returns 0), ``EINTR``, or ``EBADF``.

.. envvar:: HOSTILE_SEND

   Become hostile to ``send()`` calls

.. envvar:: HOSTILE_SENDMSG

   Become hostile to ``sendmsg()`` calls. Injects ``ECONNRESET``, ``EMSGSIZE``, or ``EAGAIN``.

.. envvar:: HOSTILE_SENDTO

   Become hostile to ``sendto()`` calls. Injects ``ECONNRESET``, ``ENETUNREACH``, ``EMSGSIZE``, ``EAGAIN``, or a short write.

.. envvar:: HOSTILE_SETSOCKOPT

   Become hostile to ``setsockopt()`` calls

.. envvar:: HOSTILE_SOCKET

   Become hostile to ``socket()`` calls

.. envvar:: HOSTILE_WRITE

   Become hostile to ``write()`` calls
