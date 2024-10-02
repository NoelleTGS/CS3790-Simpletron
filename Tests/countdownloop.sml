100010   ; READ starting number from term to mem
200010   ; LOAD starting number from mem to acc
320008   ; SUBTRACT 1 from the accumulator
250011   ; STORE number in mem loc 11
110011   ; WRITE number to terminal
420007   ; BRANCH if accumulator is zero (end of loop)
400002   ; BRANCH to start of loop
450000   ; HALT
000001