Assignment 1
## Team Members
k21-3010 Huzaifa Zulfiqar
k21-3066 Omer Shoaib
k21-3088 Wajahat Khan
## Output Screenshots
Sequence matrix vector multiplication
![svmm](https://github.com/NUCES-Khi/matrixtimesvector-howteam/assets/162980388/503a61b1-061d-483f-ba46-e99f16ae294f)

Naive MPI
![Naive mpi](https://github.com/NUCES-Khi/matrixtimesvector-howteam/assets/162980388/e80bd4bd-8852-4e1f-a8fd-7dac178da4f1)

Naive OMP
![Naive omp](https://github.com/NUCES-Khi/matrixtimesvector-howteam/assets/162980388/d5e7adfe-d5cf-416b-b7bd-2910d6a2ec8b)

Matrix Vector Multiplication OMP (tiling)
![tiling omp](https://github.com/NUCES-Khi/matrixtimesvector-howteam/assets/162980388/2ef271a7-eb93-4f92-bab6-506324ae73ae)

Matrix Vector Multuplication MPI (tiling)
![tiling mpi](https://github.com/NUCES-Khi/matrixtimesvector-howteam/assets/162980388/43e063ba-1af6-4276-8eb3-58322d047fb0)

## Results and Analysis
Bar and Line graph for 128 and 256 MPI MVM
![newplot](https://github.com/NUCES-Khi/matrixtimesvector-howteam/assets/127028606/e5dff4ac-327a-4a1b-8a04-59f3ad058001)
![newplot (1)](https://github.com/NUCES-Khi/matrixtimesvector-howteam/assets/127028606/75993d2d-8866-411d-a554-ff943611d6d9)
![newplot (2)](https://github.com/NUCES-Khi/matrixtimesvector-howteam/assets/127028606/2a26faec-341c-4eff-96bb-374a99b51754)

Line graph for 128 OpenMP NMVM
![newplot (3)](https://github.com/NUCES-Khi/matrixtimesvector-howteam/assets/127028606/756d52e4-15e8-4a7f-a414-b15c3980a0ec)

Line graph for 256 OpenMP NMVM
![newplot (4)](https://github.com/NUCES-Khi/matrixtimesvector-howteam/assets/127028606/6535814d-aea7-4f01-8ff2-a691036d71de)


## Major Problems Encountered
1. Issue 1: MPI and OMP not working properly on windows 
    - Solution1: We use of linux to run the mpi and openmp codes
    - Solution2: We install the packages on linux like sudo apt-get install mpich
    - **Resolved**
3. Issue 2: Blah blah blah ....
    - Solution1: tried to blah blahb
    - **Resolved**
