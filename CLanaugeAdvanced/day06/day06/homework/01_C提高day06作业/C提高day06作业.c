1. 将一个未知大小的文件(如: song.txt )全部读入(不是一行一行读取)内存，并显示在屏幕上，例子参考《01_ReadSong》
	参考：fseek(),  ftell(),  rewind(),  fread(),  malloc()


2. 实现配置文件读写的写功能，key=value格式，可执行程序参考《02_配置文件》
	提示：
	a) 循环读每一行, 如果此行包含key，则把key的value修改
	b) 如果所有行都不包含key，则在文件结尾追加： "key = value"
	c) 文件大小不能超过8k
	c) 参考：fgets(), strstr(), sprintf(), strcat(), fprintf(), fputs(), fseek(),  ftell(),  rewind()
	

3. 文件拷贝程序，例子参考《03_拷贝文件》


4. 动手重新写一下加密解密案例，例子参考《04_加密解密文件》