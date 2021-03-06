/*  vim:expandtab:shiftwidth=2:tabstop=2:smarttab:
 *
 *  Data Differential's libhostle
 *
 *  Copyright (C) 2012 Data Differential, http://datadifferential.com/
 *  Copyright (C) 2015 Andrew Hutchings <andrew@linuxjedi.co.uk>
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *      * Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *
 *      * Redistributions in binary form must reproduce the above
 *  copyright notice, this list of conditions and the following disclaimer
 *  in the documentation and/or other materials provided with the
 *  distribution.
 *
 *      * The names of its contributors may not be used to endorse or
 *  promote products derived from this software without specific prior
 *  written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "config.h"

#include "src/function.h"
#include "src/initialize.h"

#include <assert.h>
#include <netdb.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

static int not_until= 50;

static enum hostile_poll_t hostile_poll_type= HOSTILE_POLL_CLOSED;

static struct function_st __function;

static pthread_once_t function_lookup_once = PTHREAD_ONCE_INIT;
static void set_local(void)
{
  __function= set_function("poll", "HOSTILE_POLL");
}

void set_poll_close(bool arg, int frequency, int not_until_arg,  enum hostile_poll_t poll_type)
{
  if (arg)
  {
    __function.frequency= frequency;
    not_until= not_until_arg;
    hostile_poll_type= poll_type;
  }
  else
  {
    __function.frequency= 0;
    not_until= 0;
    hostile_poll_type= HOSTILE_POLL_CLOSED;
  }
}

int poll(struct pollfd *fds, nfds_t nfds, int timeout)
{

  hostile_initialize();

  (void) pthread_once(&function_lookup_once, set_local);

  if (__function.frequency)
  {
    if ((--not_until) < 0 && !(rand() % __function.frequency))
    {
      for (nfds_t x= 0; x < nfds; nfds++)
      {
        switch (hostile_poll_type)
        {
          case HOSTILE_POLL_CLOSED:
            shutdown(fds[x].fd, SHUT_RDWR);
            close(fds[x].fd);
            fds[x].revents= POLLIN|POLLHUP;
            break;

          case HOSTILE_POLL_SHUT_WR:
            shutdown(fds[x].fd, SHUT_WR);
            close(fds[x].fd);
            fds[x].revents= POLLIN;
            break;

          case HOSTILE_POLL_SHUT_RD:
            shutdown(fds[x].fd, SHUT_RD);
            fds[x].revents= POLLIN;
            break;

          default:
            assert(0);
            abort();
        }
      }
      return nfds;
    }
  }

  int ret= __function.function.poll(fds, nfds, timeout);

  return ret;
}
