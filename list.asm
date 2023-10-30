; _______________________________________
; EXERCICE 2 DM PROGRAMMATION ENS L3 INFO
; ABEL VERLEY
; _______________________________________

.ORIG x3000

; Code for question B
LD R0, loop_count ; Deceasing counter for the upcomming for loop
LEA R1, mem ; Stores the destination adress
ADD R2, R1, #1 ; Stores the adress to write

loop STR R2, R1, #0 ; Writes at adress R1 the adress R2 
ADD R1, R1, #1 
ADD R2, R2, #1 
ADD R0, R0 ,#-1
BRp loop

HALT

mem .BLKW #100 ; Memory zone for question A
loop_count .FILL #99
.END