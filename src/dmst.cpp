/****************************************************************************
 * Title                 :   dmst
 * Filename              :   dmst.cpp
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
std::vector<Task> system_tasks = { { 1.0F, 3.0F, 4.0F, 0.5F, 3U },
                                    { 2.0F, 5.0F, 6.0F, 0.5F, 2U },
                                    { 3.0F, 12.0F, 10.0F, 0.5F, 1U } };
//! Response_time
/******************************************************************************
 * Function Prototypes
 *******************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

Dmst::Dmst()
{
}

Dmst::~Dmst()
{
}

float Dmst::CalculateResponseTime(uint8 task_index)
{
    float previous_response_time_iteration = 0.0F;
    float current_response_time_iteration = 0.0F;
    uint16 iteration_count = 0U;
    do
    {
        //! Back up response to determine divergence
        previous_response_time_iteration = current_response_time_iteration;

        //! init intermediate response time to re fill it
        current_response_time_iteration = system_tasks.at(task_index).execution_time;

        //! calculate interference of higher priority tasks
        for (int i = 0; i < NUM_OF_TASKS - 1; i++)
        {
            current_response_time_iteration +=
                (system_tasks.at(i).execution_time * ceil(previous_response_time_iteration / system_tasks.at(i).period));
        }
        DMST_DEBUG(">>>>[INFO] R[%d](iteration: %d) : %f \n", task_index + 1, iteration_count,
                   current_response_time_iteration);
        iteration_count++;
    } while (previous_response_time_iteration != current_response_time_iteration);

    return (current_response_time_iteration);
}

#ifdef __cplusplus
} // extern "C"
#endif

/************************* End of File *****************************************/