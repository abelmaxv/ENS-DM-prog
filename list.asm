; _______________________________________
; EXERCICE 2 DM PROGRAMMATION ENS L3 INFO
; ABEL VERLEY
; _______________________________________

.ORIG x3000

main ; Test function

JSR create_mem
JSR length_mem
BR end

; Code for question B
create_mem 

LD R0, loop_count ; Deceasing counter for the upcomming for loop
LEA R1, mem 
ADD R1, R1, #1 ; Stores mem +1
loop1 STR R1, R1, #-1 ; M[R1-1]<-R1 for R1 = mem + i and i = 1,...,99
ADD R1, R1, #1 
ADD R0, R0 ,#-1
BRp loop1
RET

; Code for question C 
length_mem 

AND R0, R0, #0 ;R0<-0 (counter)
LEA R1, mem ; R1 stores the curent cell of the list
loop2 ADD R0, R0, #1
LDR R1, R1, #0
BRp loop2
RET

end HALT

mem .BLKW #100 ; Memory zone for question A
loop_count .FILL #99
.END