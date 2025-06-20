# Network Programming Security (NPS) Lab

## Lab Programs

The following are the lab exercises for NPS:

### Program-1    [Link](https://github.com/Manoj-Kumar-BV/RVCE-NPS_Lab/tree/main/Program-1)
Implement a Client and Server Communication uisng socket programming

### Program-2    [Link](https://github.com/Manoj-Kumar-BV/RVCE-NPS_Lab/tree/main/Program-2)
Write a program to implement distance vector routing protocol for a simple topology of routers

### Program-3    [Link](https://github.com/Manoj-Kumar-BV/RVCE-NPS_Lab/tree/main/Program-3)
Write a program to implement error detection and correction concept using Checksum and Hamming Code

### Program-4    [Link](https://github.com/Manoj-Kumar-BV/RVCE-NPS_Lab/tree/main/Program-4)
Implement a simple multicast routing mechanism

### Program-5    [Link](https://github.com/Manoj-Kumar-BV/RVCE-NPS_Lab/tree/main/Program-5)
Write a program to implement concurrent chat server that allows current logged-in users to communicate one with other

## Program-6  
**Implementation of concurrent and iterative echo servers using both connection and connectionless socket system calls**

- **[a) Concurrent Echo Server (Connection-Oriented Socket)](https://github.com/Manoj-Kumar-BV/RVCE-NPS_Lab/tree/main/Program-6/A)**  
  Implementation of concurrent echo server using connection-oriented socket system call.

- **[b) Iterative Echo Server (Connection-Oriented Socket)](https://github.com/Manoj-Kumar-BV/RVCE-NPS_Lab/tree/main/Program-6/B)**  
  Implementation of iterative echo server using connection-oriented socket system call.

- **[c) Iterative Echo Server (Connectionless Socket)](https://github.com/Manoj-Kumar-BV/RVCE-NPS_Lab/tree/main/Program-6/C)**  
  Implementation of iterative echo server using connectionless socket system call.



### Program-7    [Link](https://github.com/Manoj-Kumar-BV/RVCE-NPS_Lab/tree/main/Program-7)
Implementation of remote command execution using socket system calls.

### Program-8    [Link](https://github.com/Manoj-Kumar-BV/RVCE-CD_Lab/tree/main/Program-8)
Write a program to encrypt and decrypt the data using RSA and Exchange the key securely using Diffie-Hellman Key exchange protocol.

---

## For compiling

```bash
gcc client.c -o client
gcc server.c -o server
```

## For running

```bash
./server
./client 127.0.0.1  (if there is argv[] in main function)
./client  (if there is no arguments in main function)
```
