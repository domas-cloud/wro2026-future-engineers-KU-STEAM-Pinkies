# Mechanical and control testing

On the first robot we learned that a control problem was often mechanical first. Steering friction, tyre slip or a binding differential could make software tuning look bad even when the controller itself was reasonable.

The main V1 comparisons were the 50/250/1000 rpm motors, several steering layouts, earlier versus silicone front tyres, the metal versus LEGO differential and changes to sensor mounting.

We usually changed one thing, ran the same track section several times and kept the version that behaved more consistently rather than the version that looked best once.

The clean numbers we still trust are kept in [`performance_measurements.md`](performance_measurements.md): 3 m drift improved from 10.6 cm average to 4.0 cm, approximate 90° turn space fell from 46 cm to 39 cm, and the later practice sets produced 5/5 open-straight, 4/5 obstacle-slalom and 4/5 full-route results.

We previously had extra overshoot/recovery numbers in some notes, but they were not logged consistently enough to use as a strict dataset. We therefore do not use them as final evidence.

V2 will repeat the same basic style of testing after the electronics and motor are finished.
