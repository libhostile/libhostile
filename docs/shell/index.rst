hostile.sh
==========

.. program:: hostile.sh

The ``hostile.sh`` script is a wrapper for ``libhostile``. It will do the ``LD_PRELOAD`` for you as well as setup the required calls you want to be hostile with. It should be used as follows:

.. code-block:: bash

   $ hostile.sh [options] <program> [program_options]

Where ``<program>`` is the application/service you wish to be hostile to and ``[program_options]`` are the options for it. For example, this would be hostile to ``malloc()`` calls with ``curl``:

.. code-block:: bash

   $ hostile.sh -m 500 curl -L http://www.google.com/

With all the below options the ``frequency`` is roughly how often the call should fail. So a frequency of 500 will fail roughly every 1/500 calls (there is a random element to it and a small grace period).

.. option:: -a frequency

   Become hostile on ``accept()`` and ``accept4()`` calls.

.. option:: -b frequency

   Become hostile on ``bind()`` calls

.. option:: -c frequency

   Become hostile on ``connect()`` calls

.. option:: -C frequency

   Become hostile on ``calloc()`` calls

.. option:: -d frequency

   Become hostile on ``read()`` calls

.. option:: -D frequency

   Become hostile on ``fread()`` calls

.. option:: -e frequency

   Become hostile on ``recv()`` calls

.. option:: -f frequency

   Become hostile on ``fcntl()`` calls

.. option:: -F frequency

   Become hostile on ``fopen()`` calls

.. option:: -g frequency

   Become hostile on ``getaddrinfo()`` calls

.. option:: -G frequency

   Become hostile on ``getrandom()`` calls (Linux only)

.. option:: -H frequency

   Become hostile on ``gethostbyname()`` calls

.. option:: -k frequency

   Become hostile on ``getsockopt()`` calls

.. option:: -l frequency

   Become hostile on ``poll()`` calls

.. option:: -m frequency

   Become hostile on ``malloc()`` calls

.. option:: -M frequency

   Become hostile on ``sendmsg()`` calls

.. option:: -n frequency

   Become hostile on ``listen()`` calls

.. option:: -o frequency

   Become hostile on ``socket()`` calls

.. option:: -O frequency

   Become hostile on ``open()`` calls

.. option:: -p frequency

   Become hostile on ``pipe()`` and ``pipe2()`` calls

.. option:: -r frequency

   Become hostile on ``realloc()`` calls

.. option:: -R frequency

   Become hostile on ``recvfrom()`` calls

.. option:: -s frequency

   Become hostile on ``send()`` calls

.. option:: -S frequency

   Become hostile on ``select()`` calls

.. option:: -t frequency

   Become hostile on ``setsockopt()`` calls

.. option:: -T frequency

   Become hostile on ``sendto()`` calls

.. option:: -w frequency

   Become hostile on ``write()`` calls

.. option:: -x frequency

   Become hostile on ``close()`` calls

.. option:: -X frequency

   Become hostile on ``fclose()`` calls
