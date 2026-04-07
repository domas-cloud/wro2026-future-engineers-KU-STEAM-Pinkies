# Performance Measurements

## What To Measure

- lap consistency;
- steering accuracy;
- obstacle handling reliability;
- recovery after an error or interruption.

## Suggested Recording Template

- test date;
- robot version;
- track setup;
- sensor and power state;
- qualitative result;
- numeric result if available.

## Recommended Metrics

- steering center drift;
- number of obstacle interventions per lap;
- lap completion rate;
- recovery time after a disturbance;
- observed reset or brownout count.

## How To Use The Data

If a metric improves after a build change, record the change and the exact version that produced it.
If the metric does not improve, keep the result anyway so later comparisons remain honest.

## Current Approach

If the repository does not yet contain numeric results, document the measurement method and record the numbers in a consistent format during the next test session.
