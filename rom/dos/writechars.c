/*
    (C) 1995-97 AROS - The Amiga Replacement OS
    $Id$

    Desc: Writes a buffer to the current output.
    Lang: english
*/
#include <proto/exec.h>
#include <dos/dosextens.h>
#include "dos_intern.h"

/*****************************************************************************

    NAME */
#include <proto/dos.h>

	AROS_LH2(LONG, WriteChars,

/*  SYNOPSIS */
	AROS_LHA(STRPTR, buf, D1),
	AROS_LHA(ULONG , buflen, D2),

/*  LOCATION */
	struct DosLibrary *, DOSBase, 157, Dos)

/*  FUNCTION
	Writes the contents of the buffer to the current output stream.
	The number of bytes written is returned.

    INPUTS
	buf - Buffer to be written.
	buflen - Size of the buffer in bytes.

    RESULT
	The number of bytes written or EOF on failure. IoErr() gives
	additional information in that case.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
	FPuts(), FPutC(), FWrite(), PutStr()

    INTERNALS

    HISTORY
	5-12-96    turrican automatically created from
			    dos_lib.fd and clib/dos_protos.h

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct DosLibrary *,DOSBase)
    ULONG i;
    BPTR file = Output();

    for (i = 0; i < buflen; i++)
	if (FPutC(file, buf[i]) < 0)
	    return EOF;

    return (LONG)i;
    AROS_LIBFUNC_EXIT
} /* WriteChars */
