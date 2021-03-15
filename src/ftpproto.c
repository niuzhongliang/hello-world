#include "ftpproto.h"
#include "sysutil.h"

void handle_child(session_t *sess)
{
	//当连接成功的时候向客户端发送一个220信息
	writen(sess->ctrl_fd, "220 (miniftpd 0.1)\r\n", strlen("220 (miniftpd 0.1)\r\n"));
	while (1)
	{
		memset(sess->cmdline, 0, sizeof(sess->cmdline));
		memset(sess->cmd, 0, sizeof(sess->cmd));
		memset(sess->arg, 0, sizeof(sess->arg));
		readline(sess->ctrl_fd, sess->cmdline, MAX_COMMAND_LINE);//按行读取，最大值等于MAX_COMMAND_LINE
		// 解析FTP命令与参数
		// 处理FTP命令
		//可能需要nobody进程的协助，可以向nobody进程发送相应的命令
	}
}