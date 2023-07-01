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
extern std::vector<Task> system_tasks;

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
        const float context_switching = CONTEXT_SWITCH_TIME;
        do
        {
            //! Back up response to determine divergence
            previous_response_time_iteration = current_response_time_iteration;

            //! init intermediate response time to re fill it
            current_response_time_iteration = system_tasks.at(task_index).execution_time + 2 * context_switching;

            //! calculate interference of higher priority tasks
            for (int i = 0; i < NUM_OF_TASKS - 1; i++)
            {
                //! Response time for task i = Execution time of Task i +
                //! B the maximum blocking time process i suffers (from lower priority processes) +
                //! I is the interference process i gets from higher priority tasks
                current_response_time_iteration +=
                    system_tasks.at(i).blocking_time +
                    (system_tasks.at(i).execution_time + (4 * context_switching)) *
                        ceil(previous_response_time_iteration / system_tasks.at(i).period);
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