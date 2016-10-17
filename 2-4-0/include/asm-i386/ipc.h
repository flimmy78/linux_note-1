#ifndef __i386_IPC_H__
#define __i386_IPC_H__

/* 
 * These are used to wrap system calls on x86.
 *
 * See arch/i386/kernel/sys_i386.c for ugly details..
 */
struct ipc_kludge {
	struct msgbuf *msgp;
	long msgtyp;
};
/*
 *SEM为信号量设置的
 *MSG为报文传递设置的
 *SHM为共享内存设置的
 * */
#define SEMOP		 1
#define SEMGET		 2
#define SEMCTL		 3
#define MSGSND		11
#define MSGRCV		12
#define MSGGET		13
#define MSGCTL		14
#define SHMAT		21
#define SHMDT		22
#define SHMGET		23
#define SHMCTL		24

/* Used by the DIPC package, try and avoid reusing it */
#define DIPC            25

#define IPCCALL(version,op)	((version)<<16 | (op))

#endif