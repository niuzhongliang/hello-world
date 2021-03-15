#include "common.h"
#include "sysutil.h"
#include "session.h"

/*
typedef struct session
{
	// ��������
	char cmdline[MAX_COMMAND_LINE];
	char cmd[MAX_COMMAND];
	char arg[MAX_ARG];

	// ���ӽ���ͨ��
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


   //��ʼ�� session�Ự
	session_t sess = 
	{
		/* �������� */
		-1, "", "", "",
		/* ���ӽ���ͨ�� */
		-1, -1
	};
	
	// ����miniftpd���������ṩһ��IP��ַ ����NULL��ʾ�����������ַ���˿ںţ�FTP�˿ں���21����ʱ��д5188�����ڻ��Ϊͨ�������ļ���ȡ
	int listenfd = tcp_server(NULL, 5188);
	int conn;
	pid_t pid;

	while (1)
	{
		//NULL��ʾ�Եȷ���ַ��0��ʾ�����ó�ʱ��ʽ���ӣ������������׽���
		conn = accept_timeout(listenfd, NULL, 0);
		if (conn == -1)
			ERR_EXIT("accept_tinmeout");

		//������سɹ�������һ�����̳���
		pid = fork();
		if (pid == -1)
			ERR_EXIT("fork");

		if (pid == 0)
		{
			close(listenfd);
			sess.ctrl_fd = conn; //���������׽��ֵ���conn
			//�ͻ��˺ͷ����ͨ�ſ��Կ�����һ���Ự������һ���Ự������һ���������׽��ֹ���
			begin_session(&sess);
		}
		else
			close(conn);
	}
	return 0;
}
