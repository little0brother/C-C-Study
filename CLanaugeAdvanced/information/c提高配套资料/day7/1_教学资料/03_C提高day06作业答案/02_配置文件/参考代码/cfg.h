//防止头文件重复包含
#pragma once

//为了兼容C++编译器
#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

//函数的声明

//读配置文件
int ReadCfgFile(char *fileName, char *pKey, char *pVal, int *pLen);

//写、修改配置文件
int WriteCfgFile(char *fileName, char *pKey, char *pVal, int len);


#ifdef __cplusplus
}
#endif // __cplusplus
