            .text
            .align 2
main:       lui $t0, 0xffff # used to access the io memory
            lw $s0, reciever_enable($zero) # allow characters to be inputted
            sw $s0, 0($t0)
            lw $s0, transmitter_enable($zero) # allow characters to be outputted
            sw $s0, 8($t0)
r_loop:     lw $s0, 0($t0) # checks if there is a character to read
            andi $s0, $s0, 1
            beqz $s0 r_loop
            lw $s0, 4($t0) # reads the character
            addi $s0, $s0, 1 # increments to the next ascii value
            andi $s0, $s0, 0xFF # ignores everything but the first two bytes
t_loop:     lw $s1, 8($t0) # checks if its ready for output
            andi $s1, $s1, 1
            beqz $s1 t_loop
            sw $s0, 12($t0) # outputs the new character
            b r_loop # branches back for the next character
            jr $31
            .data
            .align 2
reciever_enable:    .word 2
transmitter_enable: .word 2
reciever_control:   .word 0x0000
reciever_data:      .word 0x0004
transmitter_control:   .word 0x0008
transmitter_data:      .word 0x000c
letter:     .byte 0
