# chapter 2

-  The smallest loader is called the bootstrap loader
-  core memory used to be magnetic cores and would store when powered off
-  small loader reads in a smart loader
-  core memory replaced by semiconductor memory
-  semiconductor memory loses memory when power goes down
-  they started putting butstrap loaders on rom
-  software on rom is firmwear becusae it doesnt leave when power goes out
-  8080 starts powerup by fetching comand at memory location 0
-  so when power is turned on a signil gets sent to subsutue the 0 slot in ram with a shadow prom and then it sets it back
-  basic comand would just be a jump to the beginig of the monitor code which is normaly located at the top of main memory
- adress bus contains adress of the next memory location for read/write


## 1. Power on / Reset
- Disable low RAM  
- Enable shadow PROM  
- Fetch 1st instruction from shadow PROM  
- Jump to Monitor PROM  
- Disable shadow PROM  
- Enable low RAM  
## 2. Monitor PROM Loader
- Read bootstrap from Disk A (Track 0, Sector 1)  
- If disk error → Run Monitor  
## 3. Bootstrap Loader
- Jump to bootstrap  
- Load CP/M system from disk  
- If disk error → Run Monitor  
## 4. CP/M
- Sign on and run CP/M  


- firmware monitor takes about 6k
- some of bottom of ram used by operating system
- smallest possible c/pm system on 16k
- CP/M loads and executes user programs in RAM in an area known as the "transient program area," or TPA. 
- tpa beginis at a fixed location and uses all ram not requitred by os
- user softwair is called application programs
- Editor : ED
- Asmbler : ASM
- Loader : LOAD
- debuger : DDT
- these programs get loaded into memory when we use them
- lowest adress are vectors
- vectors are like uncondtional jumps like the one for 00 on startup 
- alot of times we get to use less momry than we have to protect from overwrting needed thing like the monitor



# Monitor Memory Map
- **Top of Memory (65535)**  
  - **Monitor (PROM)** → 1–2K  
- **Unused Address Space**
- **Monitor RAM** → 0–2K  
- **CP/M Operating System** → 6–8K  
- **Transient Program Area (TPA)**  
  - Main program execution space  
  - Size = Total RAM – (7–9K overhead)  
- **Buffers** → ~256 bytes  (this is buffers + vectors)
- **Vectors** → 64 bytes (lowest addresses)  
- **Bottom of Memory (0)**


