/* Dump registers.
   Copyright (C) 2000, 2001, 2002, 2006 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Andreas Jaeger <aj@suse.de>, 2000.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#include <unistd.h>
#include <string.h>
#include <stdio-common/_itoa.h>

static void
hexvalue (unsigned long int value, char *buf, size_t len)
{
  char *cp = _itoa_word (value, buf + len, 16, 0);
  while (cp > buf)
    *--cp = '0';
}

#define REGDUMP_NREGS 32
#define REGDUMP_PER_LINE (80 / (__WORDSIZE/4 + 4))

static void
register_dump (int fd, struct ucontext *ctx)
{
  int i;
  char regvalue[__WORDSIZE/4 + 1];
  char str[82 * ((REGDUMP_NREGS + REGDUMP_PER_LINE - 1) / REGDUMP_PER_LINE)];

  static const char names[REGDUMP_NREGS][4] = {
    "pc", "ra", "s0", "s1", "s2", "s3", "s4", "s5",
    "s6", "s7", "s8", "s9", "sA", "sB", "sp", "tp",
    "v0", "v1", "a0", "a1", "a2", "a3", "a4", "a5",
    "a6", "a7", "t0", "t1", "t2", "t3", "t4", "gp"
  };

  str[0] = 0;
  for (i = 0; i < REGDUMP_NREGS; i++)
    {
      strcat (str, names[i]);
      strcat (str, " ");
      hexvalue (ctx->uc_mcontext.gregs[i], regvalue, __WORDSIZE/4);
      strcat (str, regvalue);

      if ((i + 1) % REGDUMP_PER_LINE == 0)
	strcat (str, "\n");
    }

  write (fd, str, strlen (str));
}

#define REGISTER_DUMP register_dump (fd, ctx)
