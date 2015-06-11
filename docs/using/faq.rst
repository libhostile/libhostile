FAQ
===

#. Why do I not get the familar "Hostile Engaged" when trying to be hostile to certain binaries?

   This is because ``LD_PRELOAD`` will not work on binaries that do not have the same set-user-ID/set-group-ID as the libarary. This is from the documentation of ``LD_PRELOAD``:

   .. pull-quote::

      A whitespace-separated list of additional, user-specified, ELF shared
      libraries to be loaded before all others.  This can be used to
      selectively override functions in other shared libraries.  For set-
      user-ID/set-group-ID ELF binaries, only libraries in the standard
      search directories that are also set-user-ID will be loaded.
