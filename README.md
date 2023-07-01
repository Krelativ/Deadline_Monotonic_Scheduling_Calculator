## The Deadline Monotonic Scheduling Formula
$$Ri = Bi + Ci + 2Cx +\sum_{j\in HighPriority(i)} \lceil Ri/Tj\rceil * (Cj+ 4 Cx)  $$

- Where: 
    - Ri: Response time of task i
    - Bi: The maximum blocking time process i suffers (from lower priority processes)
    - Ci: Execution time for task i
    - Cx: Context switching time
    - Tj: Period of Task j of higher priority than task i
