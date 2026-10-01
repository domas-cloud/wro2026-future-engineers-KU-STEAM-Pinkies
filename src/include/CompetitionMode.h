#pragma once

#ifndef WRO_CHALLENGE_MODE
#error "WRO_CHALLENGE_MODE must be defined: 0=open_challenge, 1=obstacle_challenge"
#endif

#if WRO_CHALLENGE_MODE != 0 && WRO_CHALLENGE_MODE != 1
#error "WRO_CHALLENGE_MODE must be 0 (Open) or 1 (Obstacle)"
#endif

constexpr bool OBSTACLE_ROUND = (WRO_CHALLENGE_MODE == 1);
