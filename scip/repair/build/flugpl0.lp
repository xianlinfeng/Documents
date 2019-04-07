\ SCIP STATISTICS
\   Problem name     : FLUGPL
\   Variables        : 18 (0 binary, 11 integer, 0 implicit integer, 7 continuous)
\   Constraints      : 18
\   Obj. scale       : 1
\   Obj. offset      : 0
Minimize
 Obj: +2700 STM6 +1500 ANM5 +2700 STM5 +1500 ANM4 +2700 STM4 +1500 ANM3 +2700 STM3 +1500 ANM2 +2700 STM2
      +1500 ANM1 +1500 ANM6 +30 UE4 +30 UE1 +30 UE3 +30 UE5 +30 UE2 +2700 STM1 +30 UE6
Subject to
 ANZ1: +1 STM1 = +60
 STD1: +150 STM1 -100 ANM1 +1 UE1 >= +8000
 UEB1: -20 STM1 +1 UE1 <= +0
 STD2: +150 STM2 -100 ANM2 +1 UE2 >= +9000
 UEB2: -20 STM2 +1 UE2 <= +0
 ANZ3: +0.9 STM2 +1 ANM2 -1 STM3 = +0
 UEB3: -20 STM3 +1 UE3 <= +0
 ANZ4: +0.9 STM3 +1 ANM3 -1 STM4 = +0
 STD4: +150 STM4 -100 ANM4 +1 UE4 >= +10000
 UEB4: -20 STM4 +1 UE4 <= +0
 ANZ5: +0.9 STM4 +1 ANM4 -1 STM5 = +0
 STD5: +150 STM5 -100 ANM5 +1 UE5 >= +9000
 UEB5: -20 STM5 +1 UE5 <= +0
 ANZ6: +0.9 STM5 +1 ANM5 -1 STM6 = +0
 STD6: +150 STM6 -100 ANM6 +1 UE6 >= +12000
 UEB6: -20 STM6 +1 UE6 <= +0
Bounds
 57 <= STM6 <= 75
 0 <= ANM5 <= 18
 57 <= STM5 <= 75
 0 <= ANM4 <= 18
 57 <= STM4 <= 75
 0 <= ANM3 <= 18
 57 <= STM3 <= 75
 0 <= ANM2 <= 18
 57 <= STM2 <= 75
 0 <= ANM1 <= 18
 0 <= ANM6 <= 18
Generals
 STM6 ANM5 STM5 ANM4 STM4 ANM3 STM3 ANM2 STM2 ANM1 ANM6
End
