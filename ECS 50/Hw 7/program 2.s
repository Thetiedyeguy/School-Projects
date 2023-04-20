            .text
            .align 2
main:       li $v0, 5 #take in a number input
            syscall
            li $t0, 31 # set registers for reference later
            li $t1, 1
            li $t4, 2
loop:       and $t2, $t1, $v0 # check a specific bit
            beq $t2, $t1 equal
            mul $t1, $t1, $t4
            b loop_end
equal:      lw $t3, parity($zero) # increase the count of 1 bits
            addi $t3, $t3, 1
            sw $t3, parity
            mul $t1, $t1, $t4
loop_end:   addi $t0, $t0, -1 # keep track of how many times the loop has been run
            bgez $t0, loop
            lw $t3, parity # check if the parity is even or odd
            div $t3, $t4
            mfhi $t3
            beqz $t3, end
            lui $t5, 0x8000 # sets the most significant bit if the parity is odd
            or $v0, $v0, $t5
end:        sw $v0 parity($zero) # prints out the possibly changed value
            li $v0, 1
            lw $a0, parity($zero)
            syscall
            jr $31

            .data
parity:     .word 0
msb:        .word 0x80000000
