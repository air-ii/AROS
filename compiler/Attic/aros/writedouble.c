/*
    (C) 1995-96 AROS - The Amiga Replacement OS
    $Id$

    Desc: Write a big endian floating point (64bit) from a file
    Lang: english
*/
#include <proto/dos.h>

/******************************************************************************

    NAME */
#include <stdio.h>
#include <proto/alib.h>

	BOOL WriteDouble (

/*  SYNOPSIS */
	BPTR   fh,
	DOUBLE data)

/*  FUNCTION
	Writes one big endian 64bit double precision floating point value
	to a file.

    INPUTS
	fh - Write to this file
	data - Data to be written

    RESULT
	The function returns TRUE on success and FALSE otherwise.
	See IoErr() for the reason in case of an error.

    NOTES
	This function writes big endian values to a file even on little
	endian machines.

    EXAMPLE

    BUGS

    SEE ALSO
	Open(), Close(), ReadByte(), ReadWord(), ReadLong(), ReadDouble(),
	ReadString(), WriteByte(), WriteWord(), WriteLong(), WriteDouble(),
	WriteString()

    HISTORY
	14.09.93    ada created

******************************************************************************/
{
    UBYTE * ptr;
    LONG    rc;

#if AROS_BIG_ENDIAN
    ptr = (UBYTE *)&data;
#   define NEXT ptr++
#else
    ptr = ((UBYTE *)&data) + 7;
#   define NEXT ptr--
#endif

#define WRITE_ONE_BYTE	    \
    rc = FPutC (fh, *ptr);  \
			    \
    if (rc == EOF)          \
	return FALSE;	    \
			    \
    NEXT

    WRITE_ONE_BYTE;
    WRITE_ONE_BYTE;
    WRITE_ONE_BYTE;
    WRITE_ONE_BYTE;
    WRITE_ONE_BYTE;
    WRITE_ONE_BYTE;
    WRITE_ONE_BYTE;
    WRITE_ONE_BYTE;

    return TRUE;
} /* WriteDouble */

