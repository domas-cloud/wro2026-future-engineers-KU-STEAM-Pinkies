# Iteration log

This page records the larger changes that affected how the robot drove.

| Stage | Problem we saw | Change | Result / next check |
|---|---|---|---|
| early steering | servo worked hard and centre was inconsistent | shortened/corrected linkage geometry | lower load and better repeatability on V1 |
| early front wheels | steering command partly disappeared in tyre slip | made silicone front tyres | stronger real steering effect |
| metal differential | binding in corners | changed to LEGO differential | smoother cornering on V1 |
| loose heading setup | heading behaviour varied between runs | mounted BNO085 more rigidly | more repeatable heading behaviour |
| V1 motor choice | 50 rpm too slow; 1000 rpm hard to use well | kept 250 rpm for V1 | useful balance for the first build |
| Hardware V2 rebuild | old electronics/software no longer matched the direction of the robot | custom PCB, LiPo, PixyCam, faster-motor plan; old software moved to brainstorm | V2 still needs bench and field tests |

For new V2 failures we will add the date/revision, what happened, what we changed and what the retest showed. Failed attempts are useful here; this log should not become a list of only successful runs.
