#include "common.h"
#include "sysutil.h"
#include "session.h"

/*
typedef struct session
{
	// 控制连接
	char cmdline[MAX_COMMAND_LINE];
	char cmd[MAX_COMMAND];
	char arg[MAX_ARG];

	// 父子进程通道
	int parent_fd;
	int child_fd;
} session_t;
*/


int main(void)
{
	if (getuid() != 0)
	{
		fprintf(stderr, "miniftpd: must be started as root\n");
		exit(EXIT_FAILURE);
	}


   //初始化 session会话
	session_t sess = 
	{
		/* 控制连接 */
		-1, "", "", "",
		/* 父子进程通道 */
		-1, -1
	};
	
	// 启动miniftpd服务器，提供一个IP地址 ，填NULL表示本机的任意地址，端口号，FTP端口号是21，暂时填写5188，后期会改为通过配置文件读取
	int listenfd = tcp_server(NULL, 5188);
	int conn;
	pid_t pid;

	while (1)
	{
		//NULL表示对等方地址，0表示不采用超时方式连接，返回已连接套接字
		conn = accept_timeout(listenfd, NULL, 0);
		if (conn == -1)
			ERR_EXIT("accept_tinmeout");

		//如果返回成功，创建一个进程出来
		pid = fork();
		if (pid == -1)
			ERR_EXIT("fork");

		if (pid == 0)
		{
			close(listenfd);
			sess.ctrl_fd = conn; //控制连接套接字等于conn
			//客户端和服务端通信可以看作是一个会话，创建一个会话，传递一个已连接套接字过来
			begin_session(&sess);
		}
		else
			close(conn);
	}
	return 0;
}
