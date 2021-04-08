/*++

	source.cpp, 2019/3/16
	(c) Qiansi Corporation, All rights reserved.

--*/
#include <iostream>
#include "diskpart.h"

int main()
{
	printf("Disk Operating System\n"
		   "(c) Qiansi Corporation, 2019.\n\n");
	Disk disk;

	while(true)
	{
		char cmd[256] = {0}, *ptr;
		int i = 0;

		printf("disk>");
		while((cmd[i] = getchar()) != '\n' && i < 255)
			i++;
		cmd[i] = '\0';
		ptr = disk.nextparam(cmd);

		#define command(x)		\
		if(!_strcmpi(cmd, #x))	\
		{						\
			disk.x(ptr);		\
			continue;			\
		}

		command(clear);
		command(shows);
		command(find);
		command(fill);
		command(findsign);

		command(load);
		command(read);
		command(replace);
		command(setsign);
		command(setdisk);

		command(save);
		command(write);
		command(crc32);

		// exit
		if(!_strcmpi(cmd, "quit") || !_strcmpi(cmd, "exit"))
			break;

		// help
		printf("Exec commands:\n"
				"  clear\n"
				"  fill\n"
				"  find\n"
				"  findsign\n"
				"  load\n"
				"  read\n"
				"  replace\n"
				"  save\n"
				"  setdisk\n"
				"  setsign\n"
				"  shows\n"
				"  write\n"
				"\n");
	}
	return 0;
}