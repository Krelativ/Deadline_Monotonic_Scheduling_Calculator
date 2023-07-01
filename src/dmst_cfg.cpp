/****************************************************************************
 * Title                 :   dmst
 * Filename              :   dmst_cfg.cpp
 * Author                :   kmuhamm1
 * Origin Date           :   17/06/2023
 * Version               :   0.0.1
 * Notes                 :   None
 *****************************************************************************/

/******************************************************************************
 * Includes
 *******************************************************************************/
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <vector>
#include "dmst_cfg.hpp"
#include "dmst.hpp"

/******************************************************************************
 * Configuration Constants
 *******************************************************************************/

/******************************************************************************
 * Macros
 *******************************************************************************/

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/******************************************************************************
 * Variables
 *******************************************************************************/
std::vector<Task> system_tasks = { { 1.0F, 3.0F, 4.0F, BLOCKING_TIME, 3U },
                                   { 2.0F, 5.0F, 6.0F, BLOCKING_TIME, 2U },
                                   { 3.0F, 12.0F, 10.0F, BLOCKING_TIME, 1U } };
//! Response_time
/******************************************************************************
 * Function Prototypes
 *******************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif


#ifdef __cplusplus
} // extern "C"
#endif

/************************* End of File *****************************************/