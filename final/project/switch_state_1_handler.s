.arch msp430g2553
.p2align 1,0
.text

.global switch_state_1_handler

; Define the addresses of the CCR0 and CCR1 registers
.equ CCR0, 0x0172
.equ CCR1, 0x0174

switch_state_1_handler:
    mov #1300, &CCR0      ; Directly set CCR0 to 1300 (determines the frequency)
    mov #650, &CCR1       ; Directly set CCR1 to 650 (determines the duty cycle)
    ret                   ; Return from the function
