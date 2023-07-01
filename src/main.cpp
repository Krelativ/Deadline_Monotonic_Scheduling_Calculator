#include <stdio.h>
#include <vector>
#include "dmst.hpp"

extern std::vector<Task> system_tasks;
int main(int argc, char* argv[])
{
    const uint8 selected_task = 2U;
    Dmst myDmst;
    float response_time = myDmst.CalculateResponseTime(selected_task);
    if (response_time <= system_tasks.at(selected_task).deadline + DELTA)
    {
        DMST_DEBUG("[INFO] Task %d is schedulable with converged response time : %f < Task %d deadline : %f \n",
                   selected_task, response_time, selected_task, system_tasks.at(selected_task).deadline);
    }
    else
    {
        DMST_DEBUG("[ERROR] Task %d is NOT schedulable with converged response time : %f > Task %d deadline : %f \n",
                   selected_task, response_time, selected_task, system_tasks.at(selected_task).deadline);
    }
    return 0;
}