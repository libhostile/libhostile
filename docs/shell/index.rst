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

.. option:: -c frequency

   Become hostile on ``connect()`` calls

.. option:: -e frequency

   Become hostile on ``recv()`` calls

.. option:: -g frequency

   Become hostile on ``getaddrinfo()`` calls

.. option:: -l frequency

   Become hostile on ``poll()`` calls

.. option:: -m frequency

   Become hostile on ``malloc()`` calls

.. option:: -o frequency

   Become hostile on ``socket()`` calls

.. option:: -p frequency

   Become hostile on ``pipe()`` and ``pipe2()`` calls

.. option:: -r frequency

   Become hostile on ``realloc()`` calls

.. option:: -s frequency

   Become hostile on ``send()`` calls

.. option:: -t frequency

   Become hostile on ``setsockopt()`` calls

.. option:: -w frequency

   Become hostile on ``write()`` calls

.. option:: -x frequency

   Become hostile on ``close()`` calls
