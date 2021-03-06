/*******************************************************************  
* (c) Copyright 2011-2012 Discretix Technologies Ltd.              *
* This software is protected by copyright, international           *
* treaties and patents.                                            *
* Use of this Software as part of or with the Discretix CryptoCell *
* or Packet Engine products is governed by the products'           *
* commercial end user license agreement ("EULA").                  *
* It is possible that copies of this Software might be distributed *
* under some type of GNU General Public License ("GPL").           *
* Notwithstanding any such distribution under the terms of GPL,    *
* GPL does not govern the use of this Software as part of or with  *
* the Discretix CryptoCell or Packet Engine products, for which a  *
* EULA is required.                                                *
* If the product's EULA allows any copy or reproduction of this    *
* Software, then such copy or reproduction must include this       *
* Copyright Notice as well as any other notices provided           *
* thereunder.                                                      *
********************************************************************/



/************* Include Files ****************/

#include "dx_pal_types.h"
#include "dx_pal_sem.h"

/************************ Defines ******************************/

/************************ Enums ******************************/

/************************ Typedefs ******************************/



/************************ Global Data ******************************/
DX_PAL_SEM SemPkaId;
/************************ Private Functions ******************************/
                                                    
/************************ Public Functions ******************************/


/*! 
 * Init function for asymmetric code
 * 
 * \return DxError_t - DX_OK
 */
DxError_t DX_ASYM_Init(void)
{
	DxError_t error;
	/* Initialize PKA's semaphore */
	error = DX_PAL_SemCreate(&SemPkaId, 1);

	return error;
}




