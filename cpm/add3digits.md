CR      EQU     0DH             
LF      EQU     0AH             
CTRLZ   EQU     1AH            
RCONF   EQU     1               
WCONF   EQU     2              
RBUFF   EQU     10              
RBOOT   EQU     0               
BDOS    EQU     5               
TPA     EQU     100H            
ORG     TPA             
START:  LXI     SP,STAK         

MAIN:   CALL    TWOCR           DOUBLE SPACE
        CALL    SPMSG
        DB      'ADD 3 Digit Numbers',0
        CALL    TWOCR
        
        CALL    SPMSG
        DB      'ENTER NUMBER: ',0
        CALL    GETNUM          GET NUMBER INTO HL
        SHLD    NUM1            SAVE FIRST NUMBER
        
        CALL    SPMSG
        DB      'ENTER SECOND NUMBER: ',0
        CALL    GETNUM          GET NUMBER INTO HL
        SHLD    NUM2            SAVE SECOND NUMBER
        
        LHLD    NUM1            LOAD FIRST NUMBER
        XCHG                    MOVE TO DE
        LHLD    NUM2            LOAD SECOND NUMBER
        DAD     D               HL = HL + DE
        SHLD    RESULT          SAVE RESULT
        
        CALL    CCRLF
        CALL    SPMSG
        DB      'SUM: ',0
        LHLD    RESULT
        CALL    PRTNUM          PRINT THE NUMBER
        
        CALL    CCRLF
        CALL    SPMSG
        DB      'AGAIN?',0
        CALL    GETYN
        JZ      MAIN            IF YES, DO ANOTHER
        
        JMP     RBOOT            EXIT TO CP/M

GETNUM: CALL    CIMSG           GET INPUT LINE
        CALL    CCRLF
        LXI     H,INBUF+2       POINT TO FIRST CHARACTER
        LXI     D,0             CLEAR RESULT IN DE
        
GNUM1:  MOV     A,M             GET CHARACTER
        ORA     A               CHECK FOR END
        JZ      GNUM2           DONE IF ZERO
        CPI     '0'             CHECK IF DIGIT
        JC      GNUM1X          SKIP IF NOT
        CPI     '9'+1
        JNC     GNUM1X          SKIP IF NOT
        
        PUSH    H               SAVE POINTER
        PUSH    D               SAVE CURRENT RESULT
        MOV     H,D             COPY DE TO HL
        MOV     L,E
        DAD     H               HL = DE * 2
        DAD     H               HL = DE * 4
        POP     D               RESTORE ORIGINAL DE
        PUSH    D               SAVE IT AGAIN
        DAD     D               HL = DE * 5
        DAD     H               HL = DE * 10
        POP     D               CLEAN UP STACK
        XCHG                    RESULT TO DE
        
        POP     H               RESTORE POINTER
        MOV     A,M             GET DIGIT CHARACTER
        SUI     '0'             CONVERT TO BINARY
        ADD     E               ADD TO LOW BYTE
        MOV     E,A
        MVI     A,0
        ADC     D               ADD CARRY TO HIGH BYTE
        MOV     D,A
        
GNUM1X: INX     H               NEXT CHARACTER
        JMP     GNUM1
        
GNUM2:  XCHG                    RESULT TO HL
        RET
