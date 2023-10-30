; _______________________________________
; EXERCICE 2 DM PROGRAMMATION ENS L3 INFO
; ABEL VERLEY
; _______________________________________

.ORIG x3000

; Code for question B
LD R0, loop_count ; Deceasing counter for the upcomming for loop
LEA R1, mem 
ADD R1, R1, #1 ; Stores mem +1

loop STR R1, R1, #-1 ; M[R1-1]<-R1 for R1 = mem + i and i = 1,...,99
ADD R1, R1, #1 
ADD R0, R0 ,#-1
BRp loop

HALT

mem .BLKW #100 ; Memory zone for question A
loop_count .FILL #99
.END