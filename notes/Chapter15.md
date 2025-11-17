# chapter 15

* we will be learning about how to talk to disks
* Instead of passing all the required information in
registers, we will use a block of RAM memory known as a File
Control Block (FCB).
* FCB says how to find a file on the disk
* the default transient file control block
(TFCB) that CP/M establishes for us at memory locations 005CH
through 007CH.
* CP/M will still make it appear
that you are working with 128 bytes of data for each read or write
operation
* When we want to write a file onto a disk, we provide CP/M with a
FCB containing the drive selection and the file name and type.
* SHOFN:, a subroutine to display the drive, file name, and file type
fields from the TFCB.
* PIP TESTC15.ASM=DISKEQU.LIB, TESTC15.LIB, SHOFN.LIB,CPMIO.LIB to merge files