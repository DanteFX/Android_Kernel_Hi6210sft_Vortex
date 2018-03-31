/*
 ******************************************************************************
 *                     SOURCE FILE
 *
 *     Document no: @(#) $Name: VXWORKS_ITER18A_FRZ10 $ $RCSfile: ipcom_uname.c,v $ $Revision: 1.1 $
 *     $Source: /home/interpeak/CVSRoot/ipcom/port/src/ipcom_uname.c,v $
 *     $Author: lob $ $Date: 2004-08-12 15:35:14 $
 *     $State: Exp $ $Locker:  $
 *
 *     INTERPEAK_COPYRIGHT_STRING
 *     Design and implementation by Lennart Bang <lob@interpeak.se>
 ******************************************************************************
 */

/*
 ****************************************************************************
 * 1                    DESCRIPTION
 ****************************************************************************
 */

/*
 ****************************************************************************
 * 2                    CONFIGURATION
 ****************************************************************************
 */

#include "ipcom_config.h"


/*
 ****************************************************************************
 * 3                    INCLUDE FILES
 ****************************************************************************
 */

#define IPCOM_USE_CLIB_PROTO
#include "ipcom_clib.h"


/*
 ****************************************************************************
 * 4                    EXTERN PROTOTYPES
 ****************************************************************************
 */

/*
 ****************************************************************************
 * 5                    DEFINES
 ****************************************************************************
 */

/*
 ****************************************************************************
 * 6                    TYPES
 ****************************************************************************
 */

/*
 ****************************************************************************
 * 7                    LOCAL PROTOTYPES
 ****************************************************************************
 */

/*
 ****************************************************************************
 * 8                    DATA
 ****************************************************************************
 */

/*
 ****************************************************************************
 * 9                    LOCAL FUNCTIONS
 ****************************************************************************
 */

/*
 ****************************************************************************
 * 10                   PUBLIC FUNCTIONS
 ****************************************************************************
 */

/*
 *===========================================================================
 *                      ipcom_uname
 *===========================================================================
 * Description:
 * Parameters:
 * Returns:
 *
 */
IP_PUBLIC int
ipcom_uname(struct Ip_utsname *info)
{
    ipcom_memset(info, 0, sizeof(*info));
    return 0;
}


/*
 ****************************************************************************
 *                      END OF FILE
 ****************************************************************************
 */