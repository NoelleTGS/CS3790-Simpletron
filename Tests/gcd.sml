100020   ; READ first num
100021   ; READ second num
200020   ; LOAD first num into acc
320021   ; SUBTRACT second number from acc
420015   ; BRANCH to halt if done (a == b)
200021   ; LOAD b into acc
320020   ; SUBTRACT a from b
410010   ; BRANCH if (a > b)
250021   ; set b to b - a
400013
200020
320021
250020   ; set a to a - b
400002   ; BRANCH to start of loop
110020
450000