/****************************************************************************
 * Title                 :   dmst
 * Filename              :   dmst.hpp
 * Author                :   kmuhamm1
 * Origin Date           :   17/06/2023
 * Version               :   0.0.1
 * Notes                 :   None
 *****************************************************************************/

#ifndef DEADLINE_H_
#define DEADLINE_H_

/******************************************************************************
 * Includes
 *******************************************************************************/
#include "dmst_cfg.hpp"

/******************************************************************************
 * Configuration Constants
 *******************************************************************************/

/******************************************************************************
 * Macros
 *******************************************************************************/

/******************************************************************************
 * Typedefs
 *******************************************************************************/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

class Task
{
public:
    // uint8 task_id;
    float execution_time;
    float deadline;
    float period;
    float blocking_time; //! is the maximum blocking time process i suffers (from lower priority processes)
    // float context_switching;
    uint8 priority; //! higher number means higher priority
};

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif
class Dmst
{
private:
    /* data */
public:
    Dmst(/* args */);
    ~Dmst();
    float CalculateResponseTime(uint8);
};

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*DEADLINE_H_*/

/************************* End of File *****************************************/